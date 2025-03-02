#ifndef DATA_HIDING_H
#define DATA_HIDING_H

#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <random>
#include <iomanip>

// Example of poor encapsulation
class BankAccountPoor {
public:
    double balance;  // Directly accessible
    std::string accountNumber;
    bool frozen;
    
    void deposit(double amount) {
        balance += amount;  // No validation
    }
    
    void withdraw(double amount) {
        balance -= amount;  // No validation
    }
};

// Example of good encapsulation
class BankAccountGood {
private:
    double balance;
    std::string accountNumber;
    bool frozen;
    std::vector<std::string> transactionHistory;
    mutable std::string lastError;  // Can be modified in const methods
    
    bool isValidAmount(double amount) const {
        if (amount <= 0) {
            lastError = "Invalid amount: must be positive";
            return false;
        }
        return true;
    }
    
    void recordTransaction(const std::string& type, double amount) {
        auto now = std::chrono::system_clock::now();
        auto timeT = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        ss << " - " << type << ": $" << std::fixed << std::setprecision(2) << amount;
        transactionHistory.push_back(ss.str());
    }
    
public:
    BankAccountGood(const std::string& accNum)
        : balance(0), accountNumber(accNum), frozen(false) {
        recordTransaction("Account created", 0);
    }
    
    bool deposit(double amount) {
        if (frozen) {
            lastError = "Account is frozen";
            return false;
        }
        if (!isValidAmount(amount)) {
            return false;
        }
        balance += amount;
        recordTransaction("Deposit", amount);
        return true;
    }
    
    bool withdraw(double amount) {
        if (frozen) {
            lastError = "Account is frozen";
            return false;
        }
        if (!isValidAmount(amount)) {
            return false;
        }
        if (amount > balance) {
            lastError = "Insufficient funds";
            return false;
        }
        balance -= amount;
        recordTransaction("Withdrawal", amount);
        return true;
    }
    
    double getBalance() const {
        return balance;
    }
    
    std::string getAccountNumber() const {
        return accountNumber;
    }
    
    bool isFrozen() const {
        return frozen;
    }
    
    bool freeze() {
        frozen = true;
        recordTransaction("Account frozen", 0);
        return true;
    }
    
    bool unfreeze() {
        frozen = false;
        recordTransaction("Account unfrozen", 0);
        return true;
    }
    
    std::vector<std::string> getTransactionHistory() const {
        return transactionHistory;
    }
    
    std::string getLastError() const {
        return lastError;
    }
};

// Example of secure password management
class Password {
private:
    std::string hashedPassword;
    std::string salt;
    size_t minLength;
    mutable std::string lastError;
    
    // Generate random salt
    std::string generateSalt() const {
        const std::string chars = 
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<> distribution(0, chars.size() - 1);
        
        std::string result;
        for (int i = 0; i < 16; ++i) {
            result += chars[distribution(generator)];
        }
        return result;
    }
    
    // Simple hash function (for demonstration - use proper crypto in production)
    std::string hashPassword(const std::string& password, const std::string& salt) const {
        std::string combined = password + salt;
        std::hash<std::string> hasher;
        return std::to_string(hasher(combined));
    }
    
public:
    explicit Password(size_t minLen = 8) : minLength(minLen) {
        salt = generateSalt();
    }
    
    bool setPassword(const std::string& newPassword) {
        if (!meetsRequirements(newPassword)) {
            return false;
        }
        hashedPassword = hashPassword(newPassword, salt);
        return true;
    }
    
    bool validatePassword(const std::string& password) const {
        return hashPassword(password, salt) == hashedPassword;
    }
    
    int checkStrength(const std::string& password) const {
        int score = 0;
        
        // Length check
        if (password.length() >= minLength) score++;
        if (password.length() >= minLength + 4) score++;
        
        // Character type checks
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        for (char c : password) {
            if (std::isupper(c)) hasUpper = true;
            else if (std::islower(c)) hasLower = true;
            else if (std::isdigit(c)) hasDigit = true;
            else hasSpecial = true;
        }
        
        if (hasUpper) score++;
        if (hasLower) score++;
        if (hasDigit) score++;
        if (hasSpecial) score++;
        
        return score;
    }
    
    bool meetsRequirements(const std::string& password) const {
        if (password.length() < minLength) {
            lastError = "Password too short";
            return false;
        }
        
        bool hasUpper = false, hasLower = false, hasDigit = false;
        for (char c : password) {
            if (std::isupper(c)) hasUpper = true;
            else if (std::islower(c)) hasLower = true;
            else if (std::isdigit(c)) hasDigit = true;
        }
        
        if (!hasUpper || !hasLower || !hasDigit) {
            lastError = "Password must contain uppercase, lowercase, and digits";
            return false;
        }
        
        return true;
    }
    
    std::string getLastError() const {
        return lastError;
    }
};

// Example of controlled logging system
class Logger {
private:
    std::vector<std::string> entries;
    size_t maxSize;
    enum class Level { INFO, WARNING, ERROR };
    Level currentLevel;
    mutable std::string lastError;
    
    std::string levelToString(Level level) const {
        switch (level) {
            case Level::INFO: return "INFO";
            case Level::WARNING: return "WARNING";
            case Level::ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }
    
    std::string formatMessage(Level level, const std::string& message) const {
        auto now = std::chrono::system_clock::now();
        auto timeT = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        ss << " [" << levelToString(level) << "] " << message;
        return ss.str();
    }
    
    void maintainSize() {
        while (entries.size() > maxSize) {
            entries.erase(entries.begin());
        }
    }
    
public:
    explicit Logger(size_t maxEntries = 1000) 
        : maxSize(maxEntries), currentLevel(Level::INFO) {}
    
    void setLevel(const std::string& level) {
        if (level == "INFO") currentLevel = Level::INFO;
        else if (level == "WARNING") currentLevel = Level::WARNING;
        else if (level == "ERROR") currentLevel = Level::ERROR;
        else {
            lastError = "Invalid log level";
        }
    }
    
    void info(const std::string& message) {
        if (currentLevel <= Level::INFO) {
            entries.push_back(formatMessage(Level::INFO, message));
            maintainSize();
        }
    }
    
    void warning(const std::string& message) {
        if (currentLevel <= Level::WARNING) {
            entries.push_back(formatMessage(Level::WARNING, message));
            maintainSize();
        }
    }
    
    void error(const std::string& message) {
        if (currentLevel <= Level::ERROR) {
            entries.push_back(formatMessage(Level::ERROR, message));
            maintainSize();
        }
    }
    
    std::vector<std::string> getLogs() const {
        return entries;
    }
    
    void clearLogs() {
        entries.clear();
    }
    
    size_t size() const {
        return entries.size();
    }
    
    std::string getLastError() const {
        return lastError;
    }
};

#endif // DATA_HIDING_H
