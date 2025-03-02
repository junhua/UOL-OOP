#ifndef FINANCIAL_ACCOUNT_H
#define FINANCIAL_ACCOUNT_H

#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <mutex>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <random>
#include <numeric>

/**
 * @class Transaction
 * @brief Represents a financial transaction with details and validation
 * 
 * This class demonstrates proper encapsulation with validation
 * and computed properties.
 */
class Transaction {
private:
    std::string id;
    std::string type;  // "deposit", "withdrawal", "transfer", etc.
    double amount;
    std::string description;
    std::string category;
    std::chrono::system_clock::time_point timestamp;
    bool successful;
    std::string failureReason;
    
    // Validation methods
    bool isValidType(const std::string& type) const {
        static const std::vector<std::string> validTypes = {
            "deposit", "withdrawal", "transfer", "interest", "fee", "adjustment"
        };
        
        return std::find(validTypes.begin(), validTypes.end(), type) != validTypes.end();
    }
    
    bool isValidAmount(double amount) const {
        return amount > 0.0;
    }
    
    bool isValidCategory(const std::string& category) const {
        static const std::vector<std::string> validCategories = {
            "income", "expense", "transfer", "interest", "fee", "other"
        };
        
        return std::find(validCategories.begin(), validCategories.end(), category) != validCategories.end();
    }
    
    // Generate a unique ID
    std::string generateId() const {
        static int counter = 0;
        return "TXN_" + std::to_string(++counter);
    }
    
public:
    // Constructor
    Transaction(const std::string& type = "", 
                double amount = 0.0,
                const std::string& description = "",
                const std::string& category = "other")
        : id(generateId()),
          type(type),
          amount(amount),
          description(description),
          category(category),
          timestamp(std::chrono::system_clock::now()),
          successful(true),
          failureReason("") {
        
        // Validate inputs
        if (!isValidType(type)) {
            this->type = "other";
        }
        
        if (!isValidAmount(amount)) {
            this->amount = 0.0;
        }
        
        if (!isValidCategory(category)) {
            this->category = "other";
        }
    }
    
    // Getters
    std::string getId() const { return id; }
    
    std::string getType() const { return type; }
    
    double getAmount() const { return amount; }
    
    std::string getDescription() const { return description; }
    
    std::string getCategory() const { return category; }
    
    std::chrono::system_clock::time_point getTimestamp() const { return timestamp; }
    
    bool isSuccessful() const { return successful; }
    
    std::string getFailureReason() const { return failureReason; }
    
    // Setters with validation
    bool setType(const std::string& newType) {
        if (!isValidType(newType)) {
            return false;
        }
        type = newType;
        return true;
    }
    
    bool setAmount(double newAmount) {
        if (!isValidAmount(newAmount)) {
            return false;
        }
        amount = newAmount;
        return true;
    }
    
    void setDescription(const std::string& newDescription) {
        description = newDescription;
    }
    
    bool setCategory(const std::string& newCategory) {
        if (!isValidCategory(newCategory)) {
            return false;
        }
        category = newCategory;
        return true;
    }
    
    void setSuccessful(bool success) {
        successful = success;
    }
    
    void setFailureReason(const std::string& reason) {
        failureReason = reason;
        if (!reason.empty()) {
            successful = false;
        }
    }
    
    // Formatting methods
    std::string getFormattedAmount() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << amount;
        return ss.str();
    }
    
    std::string getFormattedTimestamp() const {
        auto timeT = std::chrono::system_clock::to_time_t(timestamp);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
    
    std::string getSummary() const {
        std::stringstream ss;
        ss << getFormattedTimestamp() << " - " 
           << type << ": $" << getFormattedAmount();
        
        if (!description.empty()) {
            ss << " (" << description << ")";
        }
        
        return ss.str();
    }
};

/**
 * @class Account
 * @brief Represents a financial account with transaction history and security features
 * 
 * This class demonstrates proper encapsulation with validation,
 * computed properties, and state management.
 */
class Account {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;
    double interestRate;
    bool frozen;
    std::vector<Transaction> transactions;
    std::chrono::system_clock::time_point lastActivity;
    mutable std::mutex mutex;
    mutable std::string lastError;
    
    // Delete copy constructor and assignment operator
    // to prevent copying of mutex
    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;
    
    // Validation methods
    bool isValidAccountNumber(const std::string& number) const {
        if (number.empty()) {
            lastError = "Account number cannot be empty";
            return false;
        }
        
        if (number.length() < 4 || number.length() > 20) {
            lastError = "Account number must be between 4 and 20 characters";
            return false;
        }
        
        return true;
    }
    
    bool isValidAccountHolder(const std::string& holder) const {
        if (holder.empty()) {
            lastError = "Account holder cannot be empty";
            return false;
        }
        
        if (holder.length() > 100) {
            lastError = "Account holder name too long (max 100 characters)";
            return false;
        }
        
        return true;
    }
    
    bool isValidAmount(double amount) const {
        if (amount <= 0.0) {
            lastError = "Amount must be positive";
            return false;
        }
        
        return true;
    }
    
    bool isValidInterestRate(double rate) const {
        if (rate < 0.0) {
            lastError = "Interest rate cannot be negative";
            return false;
        }
        
        if (rate > 0.2) {  // 20% max
            lastError = "Interest rate too high (max 20%)";
            return false;
        }
        
        return true;
    }
    
    // Helper methods
    void recordTransaction(const Transaction& transaction) {
        transactions.push_back(transaction);
        lastActivity = std::chrono::system_clock::now();
    }
    
public:
    // Constructor
    Account(const std::string& number = "",
            const std::string& holder = "",
            double initialBalance = 0.0,
            double rate = 0.0)
        : accountNumber(number),
          accountHolder(holder),
          balance(initialBalance),
          interestRate(rate),
          frozen(false) {
        
        // Validate inputs
        if (!isValidAccountNumber(number)) {
            this->accountNumber = "INVALID";
        }
        
        if (!isValidAccountHolder(holder)) {
            this->accountHolder = "INVALID";
        }
        
        if (initialBalance < 0.0) {
            this->balance = 0.0;
        }
        
        if (!isValidInterestRate(rate)) {
            this->interestRate = 0.0;
        }
        
        lastActivity = std::chrono::system_clock::now();
        
        // Record initial deposit if balance > 0
        if (initialBalance > 0.0) {
            Transaction initialDeposit("deposit", initialBalance, "Initial deposit");
            recordTransaction(initialDeposit);
        }
    }
    
    // Getters
    std::string getAccountNumber() const {
        std::lock_guard<std::mutex> lock(mutex);
        return accountNumber;
    }
    
    std::string getAccountHolder() const {
        std::lock_guard<std::mutex> lock(mutex);
        return accountHolder;
    }
    
    double getBalance() const {
        std::lock_guard<std::mutex> lock(mutex);
        return balance;
    }
    
    double getInterestRate() const {
        std::lock_guard<std::mutex> lock(mutex);
        return interestRate;
    }
    
    bool isFrozen() const {
        std::lock_guard<std::mutex> lock(mutex);
        return frozen;
    }
    
    std::chrono::system_clock::time_point getLastActivity() const {
        std::lock_guard<std::mutex> lock(mutex);
        return lastActivity;
    }
    
    std::string getLastError() const {
        std::lock_guard<std::mutex> lock(mutex);
        return lastError;
    }
    
    // Setters with validation
    bool setAccountHolder(const std::string& holder) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!isValidAccountHolder(holder)) {
            return false;
        }
        
        accountHolder = holder;
        return true;
    }
    
    bool setInterestRate(double rate) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!isValidInterestRate(rate)) {
            return false;
        }
        
        interestRate = rate;
        return true;
    }
    
    // Transaction methods
    bool deposit(double amount, const std::string& description = "") {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (frozen) {
            lastError = "Account is frozen";
            return false;
        }
        
        if (!isValidAmount(amount)) {
            return false;
        }
        
        Transaction transaction("deposit", amount, description);
        balance += amount;
        recordTransaction(transaction);
        
        return true;
    }
    
    bool withdraw(double amount, const std::string& description = "") {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (frozen) {
            lastError = "Account is frozen";
            return false;
        }
        
        if (!isValidAmount(amount)) {
            return false;
        }
        
        if (amount > balance) {
            lastError = "Insufficient funds";
            
            Transaction failedTransaction("withdrawal", amount, description);
            failedTransaction.setSuccessful(false);
            failedTransaction.setFailureReason("Insufficient funds");
            recordTransaction(failedTransaction);
            
            return false;
        }
        
        Transaction transaction("withdrawal", amount, description);
        balance -= amount;
        recordTransaction(transaction);
        
        return true;
    }
    
    // Security features
    bool freeze() {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (frozen) {
            lastError = "Account is already frozen";
            return false;
        }
        
        frozen = true;
        Transaction transaction("adjustment", 0.0, "Account frozen");
        recordTransaction(transaction);
        
        return true;
    }
    
    bool unfreeze() {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!frozen) {
            lastError = "Account is not frozen";
            return false;
        }
        
        frozen = false;
        Transaction transaction("adjustment", 0.0, "Account unfrozen");
        recordTransaction(transaction);
        
        return true;
    }
    
    // Interest calculation
    double calculateInterest(int days) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (balance <= 0.0 || interestRate <= 0.0) {
            return 0.0;
        }
        
        // Simple interest calculation
        double dailyRate = interestRate / 365.0;
        return balance * dailyRate * days;
    }
    
    bool addInterest(int days) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (frozen) {
            lastError = "Account is frozen";
            return false;
        }
        
        double interest = calculateInterest(days);
        if (interest <= 0.0) {
            return false;
        }
        
        balance += interest;
        
        std::stringstream ss;
        ss << days << " days interest at " << (interestRate * 100.0) << "%";
        Transaction transaction("interest", interest, ss.str());
        recordTransaction(transaction);
        
        return true;
    }
    
    // Transaction history
    std::vector<Transaction> getTransactionHistory() const {
        std::lock_guard<std::mutex> lock(mutex);
        return transactions;
    }
    
    std::vector<Transaction> getTransactionHistory(int days) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        auto now = std::chrono::system_clock::now();
        auto cutoff = now - std::chrono::hours(24 * days);
        
        std::vector<Transaction> recentTransactions;
        for (const auto& transaction : transactions) {
            if (transaction.getTimestamp() >= cutoff) {
                recentTransactions.push_back(transaction);
            }
        }
        
        return recentTransactions;
    }
    
    // Statement generation
    std::string generateStatement(int days = 30) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        auto recentTransactions = getTransactionHistory(days);
        
        auto now = std::chrono::system_clock::now();
        auto startDate = now - std::chrono::hours(24 * days);
        
        auto nowT = std::chrono::system_clock::to_time_t(now);
        auto startT = std::chrono::system_clock::to_time_t(startDate);
        
        std::stringstream ss;
        ss << "==================================================" << std::endl;
        ss << "ACCOUNT STATEMENT" << std::endl;
        ss << "Account: " << accountNumber << std::endl;
        ss << "Account Holder: " << accountHolder << std::endl;
        ss << "Date Range: " << std::put_time(std::localtime(&startT), "%Y-%m-%d") 
           << " to " << std::put_time(std::localtime(&nowT), "%Y-%m-%d") << std::endl;
        ss << "--------------------------------------------------" << std::endl;
        
        double totalDeposits = 0.0;
        double totalWithdrawals = 0.0;
        double totalInterest = 0.0;
        
        for (const auto& transaction : recentTransactions) {
            ss << transaction.getSummary() << std::endl;
            
            if (transaction.getType() == "deposit") {
                totalDeposits += transaction.getAmount();
            } else if (transaction.getType() == "withdrawal") {
                totalWithdrawals += transaction.getAmount();
            } else if (transaction.getType() == "interest") {
                totalInterest += transaction.getAmount();
            }
        }
        
        // Calculate opening balance
        double openingBalance = balance;
        for (const auto& transaction : recentTransactions) {
            if (transaction.isSuccessful()) {
                if (transaction.getType() == "deposit" || transaction.getType() == "interest") {
                    openingBalance -= transaction.getAmount();
                } else if (transaction.getType() == "withdrawal") {
                    openingBalance += transaction.getAmount();
                }
            }
        }
        
        ss << "--------------------------------------------------" << std::endl;
        ss << "Opening Balance: $" << std::fixed << std::setprecision(2) << openingBalance << std::endl;
        ss << "Closing Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        ss << "Total Deposits: $" << std::fixed << std::setprecision(2) << totalDeposits << std::endl;
        ss << "Total Withdrawals: $" << std::fixed << std::setprecision(2) << totalWithdrawals << std::endl;
        ss << "Total Interest: $" << std::fixed << std::setprecision(2) << totalInterest << std::endl;
        ss << "==================================================" << std::endl;
        
        return ss.str();
    }
};

/**
 * @class Bank
 * @brief Manages a collection of accounts with transfer and interest functionality
 * 
 * This class demonstrates thread-safe property access, collection management,
 * and state tracking.
 */
class Bank {
private:
    std::map<std::string, std::unique_ptr<Account>> accounts;
    double baseInterestRate;
    mutable std::mutex mutex;
    mutable std::string lastError;
    
    // Validation methods
    bool isValidAccountNumber(const std::string& number) const {
        if (number.empty()) {
            lastError = "Account number cannot be empty";
            return false;
        }
        
        if (number.length() < 4 || number.length() > 20) {
            lastError = "Account number must be between 4 and 20 characters";
            return false;
        }
        
        return true;
    }
    
    bool isValidInterestRate(double rate) const {
        if (rate < 0.0) {
            lastError = "Interest rate cannot be negative";
            return false;
        }
        
        if (rate > 0.2) {  // 20% max
            lastError = "Interest rate too high (max 20%)";
            return false;
        }
        
        return true;
    }
    
    // Helper methods
    bool accountExists(const std::string& accountNumber) const {
        return accounts.find(accountNumber) != accounts.end();
    }
    
    // Generate a unique account number
    std::string generateAccountNumber() const {
        static int counter = 1000;
        return std::to_string(++counter);
    }
    
public:
    // Constructor
    Bank(double baseRate = 0.03)  // 3% default
        : baseInterestRate(baseRate) {
        
        if (!isValidInterestRate(baseRate)) {
            this->baseInterestRate = 0.03;  // Default to 3%
        }
    }
    
    // Getters
    double getBaseInterestRate() const {
        std::lock_guard<std::mutex> lock(mutex);
        return baseInterestRate;
    }
    
    std::string getLastError() const {
        std::lock_guard<std::mutex> lock(mutex);
        return lastError;
    }
    
    // Setters with validation
    bool setBaseInterestRate(double rate) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!isValidInterestRate(rate)) {
            return false;
        }
        
        baseInterestRate = rate;
        return true;
    }
    
    // Account management methods
    bool createAccount(const std::string& accountNumber, const std::string& accountHolder) {
        std::lock_guard<std::mutex> lock(mutex);
        
        std::string number = accountNumber;
        if (number.empty()) {
            number = generateAccountNumber();
        } else if (!isValidAccountNumber(number)) {
            return false;
        }
        
        if (accountExists(number)) {
            lastError = "Account with number " + number + " already exists";
            return false;
        }
        
        accounts[number] = std::unique_ptr<Account>(new Account(number, accountHolder, 0.0, baseInterestRate));
        return true;
    }
    
    bool closeAccount(const std::string& accountNumber) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!accountExists(accountNumber)) {
            lastError = "Account with number " + accountNumber + " not found";
            return false;
        }
        
        if (accounts[accountNumber]->getBalance() > 0.0) {
            lastError = "Cannot close account with positive balance";
            return false;
        }
        
        accounts.erase(accountNumber);
        return true;
    }
    
    // Transfer methods
    bool transfer(const std::string& fromAccount, const std::string& toAccount, double amount) {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!accountExists(fromAccount)) {
            lastError = "Source account " + fromAccount + " not found";
            return false;
        }
        
        if (!accountExists(toAccount)) {
            lastError = "Destination account " + toAccount + " not found";
            return false;
        }
        
        Account* source = accounts[fromAccount].get();
        Account* destination = accounts[toAccount].get();
        
        if (source->isFrozen()) {
            lastError = "Source account is frozen";
            return false;
        }
        
        if (destination->isFrozen()) {
            lastError = "Destination account is frozen";
            return false;
        }
        
        if (amount <= 0.0) {
            lastError = "Transfer amount must be positive";
            return false;
        }
        
        if (source->getBalance() < amount) {
            lastError = "Insufficient funds in source account";
            return false;
        }
        
        // Perform the transfer
        source->withdraw(amount, "Transfer to " + toAccount);
        destination->deposit(amount, "Transfer from " + fromAccount);
        
        return true;
    }
    
    // Interest processing
    void processInterest() {
        std::lock_guard<std::mutex> lock(mutex);
        
        for (auto& pair : accounts) {
            pair.second->addInterest(1);  // 1 day of interest
        }
    }
    
    // Statement generation
    std::string generateAccountStatement(const std::string& accountNumber, int days = 30) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!accountExists(accountNumber)) {
            lastError = "Account with number " + accountNumber + " not found";
            return "";
        }
        
        return accounts.at(accountNumber)->generateStatement(days);
    }
    
    // Access methods
    const Account* getAccount(const std::string& accountNumber) const {
        std::lock_guard<std::mutex> lock(mutex);
        
        if (!accountExists(accountNumber)) {
            lastError = "Account with number " + accountNumber + " not found";
            return nullptr;
        }
        
        return accounts.at(accountNumber).get();
    }
    
    std::vector<std::string> getAccountNumbers() const {
        std::lock_guard<std::mutex> lock(mutex);
        
        std::vector<std::string> numbers;
        for (const auto& pair : accounts) {
            numbers.push_back(pair.first);
        }
        
        return numbers;
    }
    
    // Batch operations
    void processDailyOperations() {
        std::lock_guard<std::mutex> lock(mutex);
        
        // Process interest for all accounts
        processInterest();
        
        // Additional daily operations could be added here
    }
};

#endif // FINANCIAL_ACCOUNT_H
