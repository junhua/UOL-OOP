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

// Forward declaration
class Transaction;

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
    
    // TODO: Add validation methods
    
public:
    // TODO: Implement constructor
    
    // TODO: Implement getters and setters with validation
    
    // TODO: Implement transaction methods
    
    // TODO: Implement security features
};

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
    
    // TODO: Add validation methods
    
public:
    // TODO: Implement constructor
    
    // TODO: Implement getters and setters with validation
    
    // TODO: Implement formatting methods
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
    std::map<std::string, Account> accounts;
    double baseInterestRate;
    mutable std::mutex mutex;
    mutable std::string lastError;
    
    // TODO: Add helper methods for validation and management
    
public:
    // TODO: Implement constructor
    
    // TODO: Implement account management methods
    
    // TODO: Implement transfer methods
    
    // TODO: Implement interest processing
    
    // TODO: Implement statement generation
};

#endif // FINANCIAL_ACCOUNT_H
