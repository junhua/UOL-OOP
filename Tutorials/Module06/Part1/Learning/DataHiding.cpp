#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <random>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string accountType;
    vector<string> transactionHistory;
    
    // Helper function to record transactions
    void recordTransaction(const string& type, double amount) {
        time_t now = time(nullptr);
        string timestamp = ctime(&now);
        timestamp = timestamp.substr(0, timestamp.length() - 1);  // Remove newline
        
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << timestamp << " - " << type << ": $" << amount 
           << " (Balance: $" << balance << ")";
        
        transactionHistory.push_back(ss.str());
    }
    
public:
    BankAccount(const string& accNum, const string& type, double initialBalance = 0.0)
        : accountNumber(accNum), accountType(type), balance(initialBalance) {
        if (initialBalance > 0) {
            recordTransaction("Initial deposit", initialBalance);
        }
    }
    
    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Invalid deposit amount" << endl;
            return false;
        }
        
        balance += amount;
        recordTransaction("Deposit", amount);
        return true;
    }
    
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Invalid withdrawal amount" << endl;
            return false;
        }
        
        if (amount > balance) {
            cout << "Error: Insufficient funds" << endl;
            return false;
        }
        
        balance -= amount;
        recordTransaction("Withdrawal", amount);
        return true;
    }
    
    double getBalance() const {
        return balance;
    }
    
    vector<string> getTransactionHistory() const {
        return transactionHistory;
    }
    
    string getAccountInfo() const {
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << "Account: " << accountNumber << endl
           << "Type: " << accountType << endl
           << "Balance: $" << balance;
        return ss.str();
    }
};

class Password {
private:
    string hashedPassword;
    string salt;
    size_t minLength;
    
    // Helper function to generate salt
    string generateSalt() {
        const string chars = 
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> distribution(0, chars.size() - 1);
        
        string result;
        for (int i = 0; i < 16; ++i) {
            result += chars[distribution(generator)];
        }
        return result;
    }
    
    // Helper function to hash password
    string hashPassword(const string& password, const string& salt) const {
        // Simple hash function for demonstration
        string combined = password + salt;
        size_t hash = 0;
        for (char c : combined) {
            hash = ((hash << 5) + hash) + c;
        }
        
        stringstream ss;
        ss << hex << hash;
        return ss.str();
    }
    
public:
    explicit Password(size_t minLen = 8) : minLength(minLen) {
        salt = generateSalt();
    }
    
    bool setPassword(const string& newPassword) {
        if (newPassword.length() < minLength) {
            cout << "Error: Password too short" << endl;
            return false;
        }
        
        bool hasUpper = false, hasLower = false, hasDigit = false;
        for (char c : newPassword) {
            if (isupper(c)) hasUpper = true;
            if (islower(c)) hasLower = true;
            if (isdigit(c)) hasDigit = true;
        }
        
        if (!hasUpper || !hasLower || !hasDigit) {
            cout << "Error: Password must contain uppercase, lowercase, and digits" << endl;
            return false;
        }
        
        hashedPassword = hashPassword(newPassword, salt);
        return true;
    }
    
    bool validatePassword(const string& password) const {
        string hashedInput = hashPassword(password, salt);
        return hashedInput == hashedPassword;
    }
    
    int checkStrength(const string& password) const {
        if (password.length() < minLength) return 0;
        
        int score = 0;
        bool hasUpper = false, hasLower = false, 
             hasDigit = false, hasSpecial = false;
        
        for (char c : password) {
            if (isupper(c)) hasUpper = true;
            else if (islower(c)) hasLower = true;
            else if (isdigit(c)) hasDigit = true;
            else hasSpecial = true;
        }
        
        if (hasUpper) score++;
        if (hasLower) score++;
        if (hasDigit) score++;
        if (hasSpecial) score++;
        if (password.length() >= minLength * 2) score++;
        
        return score;
    }
};

class Logger {
private:
    vector<string> logEntries;
    size_t maxSize;
    
    // Helper function to format timestamp
    string getTimestamp() {
        time_t now = time(nullptr);
        string timestamp = ctime(&now);
        return timestamp.substr(0, timestamp.length() - 1);
    }
    
    // Helper function to format log entry
    string formatEntry(const string& message, const string& level) {
        stringstream ss;
        ss << "[" << getTimestamp() << "] " << level << ": " << message;
        return ss.str();
    }
    
public:
    explicit Logger(size_t maxEntries = 1000) : maxSize(maxEntries) {}
    
    void log(const string& message, const string& level = "INFO") {
        string entry = formatEntry(message, level);
        
        if (logEntries.size() >= maxSize) {
            logEntries.erase(logEntries.begin());
        }
        
        logEntries.push_back(entry);
    }
    
    vector<string> getRecentLogs(size_t count = 10) const {
        if (count > logEntries.size()) {
            count = logEntries.size();
        }
        
        return vector<string>(
            logEntries.end() - count,
            logEntries.end()
        );
    }
    
    vector<string> searchLogs(const string& term) const {
        vector<string> results;
        for (const auto& entry : logEntries) {
            if (entry.find(term) != string::npos) {
                results.push_back(entry);
            }
        }
        return results;
    }
    
    void clearLogs() {
        logEntries.clear();
    }
    
    size_t size() const {
        return logEntries.size();
    }
};

int main() {
    cout << "Data Hiding Demo" << endl;
    cout << "===============" << endl;
    
    // Bank Account Demo
    cout << "\nBank Account Demo:" << endl;
    cout << "=================" << endl;
    
    BankAccount account("1234567890", "Savings", 1000.0);
    cout << account.getAccountInfo() << endl << endl;
    
    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(2000.0);  // Should fail
    
    cout << "\nTransaction History:" << endl;
    for (const auto& transaction : account.getTransactionHistory()) {
        cout << transaction << endl;
    }
    
    // Password Demo
    cout << "\nPassword Demo:" << endl;
    cout << "=============" << endl;
    
    Password pwd(8);
    string password = "Weak";
    cout << "Setting weak password: " 
         << (pwd.setPassword(password) ? "Success" : "Failed") << endl;
    
    password = "StrongPwd123";
    cout << "Setting strong password: " 
         << (pwd.setPassword(password) ? "Success" : "Failed") << endl;
    
    cout << "Password strength (0-5): " << pwd.checkStrength(password) << endl;
    cout << "Validate correct password: " 
         << (pwd.validatePassword(password) ? "Success" : "Failed") << endl;
    cout << "Validate wrong password: " 
         << (pwd.validatePassword("WrongPwd123") ? "Success" : "Failed") << endl;
    
    // Logger Demo
    cout << "\nLogger Demo:" << endl;
    cout << "===========" << endl;
    
    Logger logger(5);  // Small size for demo
    
    logger.log("Application started");
    logger.log("Processing data", "INFO");
    logger.log("File not found", "WARNING");
    logger.log("Database connection failed", "ERROR");
    logger.log("Retrying connection", "INFO");
    logger.log("Connection established", "INFO");
    
    cout << "\nRecent Logs:" << endl;
    for (const auto& entry : logger.getRecentLogs()) {
        cout << entry << endl;
    }
    
    cout << "\nSearching for 'connection':" << endl;
    for (const auto& entry : logger.searchLogs("connection")) {
        cout << entry << endl;
    }
    
    return 0;
}
