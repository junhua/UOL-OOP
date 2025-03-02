# Financial Account Practice Exercise

This practice exercise will help you apply getter and setter patterns by implementing a comprehensive financial account system.

## Files Overview

- `FinancialAccount_starter.h` - Class declaration file
- `FinancialAccount_starter.cpp` - Implementation file
- `account_test.cpp` - Test program demonstrating functionality

## Learning Objectives

- Implement property validation for financial data
- Create computed properties for account statistics
- Design state management for transaction history
- Develop secure access control for sensitive data
- Implement interest calculation and statement generation
- Apply thread safety for concurrent transactions

## Requirements

### 1. Account Management

Implement the `Account` class with:
- Private data members for account details
- Validation for transactions
- Balance management
- Transaction history
- Security features

```cpp
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
```

### 2. Transaction System

Implement the `Transaction` class with:
- Transaction details
- Validation
- Categorization
- Timestamp tracking

```cpp
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
```

### 3. Banking System

Implement the `Bank` class to manage multiple accounts:
- Account collection management
- Inter-account transfers
- Interest processing
- Statement generation

```cpp
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
```

## Implementation Steps

### Step 1: Transaction Class

1. Implement the `Transaction` class:
   - Add private member variables
   - Create validation methods
   - Implement getters and setters
   - Add formatting methods

2. Key methods to implement:
   ```cpp
   bool setAmount(double amount);
   bool setType(const std::string& type);
   bool setCategory(const std::string& category);
   std::string getFormattedAmount() const;
   std::string getFormattedTimestamp() const;
   bool isSuccessful() const;
   std::string getFailureReason() const;
   ```

### Step 2: Account Class

1. Implement the `Account` class:
   - Add private member variables
   - Create validation methods
   - Implement transaction methods
   - Add security features
   - Implement interest calculation

2. Key methods to implement:
   ```cpp
   bool deposit(double amount, const std::string& description = "");
   bool withdraw(double amount, const std::string& description = "");
   double getBalance() const;
   bool setInterestRate(double rate);
   double calculateInterest(int days) const;
   bool freeze();
   bool unfreeze();
   std::vector<Transaction> getTransactionHistory() const;
   std::string generateStatement(int days = 30) const;
   ```

### Step 3: Bank Class

1. Implement the `Bank` class:
   - Add account management
   - Create transfer functionality
   - Implement interest processing
   - Add statement generation

2. Key methods to implement:
   ```cpp
   bool createAccount(const std::string& accountNumber, const std::string& accountHolder);
   bool closeAccount(const std::string& accountNumber);
   bool transfer(const std::string& fromAccount, const std::string& toAccount, double amount);
   void processInterest();
   std::string generateAccountStatement(const std::string& accountNumber, int days = 30) const;
   std::vector<std::string> getAccountNumbers() const;
   ```

### Step 4: Thread Safety

1. Implement thread-safe access:
   - Add mutex protection for shared resources
   - Create thread-safe getters and setters
   - Implement atomic operations
   - Ensure consistent locking

2. Key methods to implement:
   ```cpp
   // Thread-safe account access
   const Account* getAccount(const std::string& accountNumber) const;
   
   // Thread-safe transaction processing
   bool processTransaction(const std::string& accountNumber, const Transaction& transaction);
   
   // Thread-safe batch operations
   void processDailyOperations();
   ```

### Step 5: Complete the Test Program

1. In `account_test.cpp`:
   - Create a banking system
   - Add various accounts
   - Process deposits and withdrawals
   - Perform transfers between accounts
   - Generate account statements
   - Process interest
   - Test security features

## Testing

1. Compile your program:
   ```bash
   g++ -o banking_system account_test.cpp FinancialAccount_starter.cpp -std=c++17 -pthread
   ```

2. Run the program:
   ```bash
   ./banking_system
   ```

3. Verify the output:
   - Check account creation and management
   - Verify transaction processing
   - Test transfer functionality
   - Confirm interest calculation
   - Validate statement generation
   - Check security features

## Expected Output

```
Banking System
==================================================

Creating accounts...
Created account: 1001 (John Doe)
Created account: 1002 (Jane Smith)
Created account: 1003 (Bob Johnson)

Processing deposits...
Deposited $1000.00 to account 1001
Deposited $2500.00 to account 1002
Deposited $750.00 to account 1003

Processing withdrawals...
Withdrew $250.00 from account 1001
Withdrew $500.00 from account 1002
Withdrawal failed: Insufficient funds (Attempted to withdraw $1000.00 from account 1003)

Processing transfers...
Transferred $300.00 from account 1002 to account 1003
Transfer failed: Insufficient funds (Attempted to transfer $2000.00 from account 1001 to account 1003)

Account balances:
Account 1001: $750.00
Account 1002: $1700.00
Account 1003: $1050.00

Testing security features...
Account 1001 frozen
Deposit failed: Account is frozen
Account 1001 unfrozen
Deposited $100.00 to account 1001

Processing interest (3% annual rate)...
Interest added to account 1001: $6.99
Interest added to account 1002: $14.18
Interest added to account 1003: $8.75

Account statement for 1001:
==================================================
ACCOUNT STATEMENT
Account: 1001
Account Holder: John Doe
Date Range: 2024-01-26 to 2024-02-25
--------------------------------------------------
2024-02-25 10:15:00 - Deposit: $1000.00 (Initial deposit)
2024-02-25 10:16:30 - Withdrawal: $250.00 (ATM withdrawal)
2024-02-25 10:20:45 - Account frozen
2024-02-25 10:21:15 - Account unfrozen
2024-02-25 10:21:30 - Deposit: $100.00
2024-02-25 10:25:00 - Interest: $6.99
--------------------------------------------------
Opening Balance: $0.00
Closing Balance: $856.99
Total Deposits: $1100.00
Total Withdrawals: $250.00
Total Interest: $6.99
==================================================

Program completed successfully
```

## Tips

1. Use validation in all setters to maintain data integrity
2. Implement computed properties for derived values
3. Use thread safety for concurrent transactions
4. Add proper error handling and reporting
5. Maintain transaction history for auditing
6. Use meaningful operations instead of raw getters/setters

## Common Issues to Watch For

1. Insufficient validation
2. Missing error handling
3. Race conditions in concurrent transactions
4. Inconsistent state after failed operations
5. Security vulnerabilities
6. Incorrect interest calculations

## Extension Challenges

If you complete the basic requirements, try these extensions:

1. Add different account types (checking, savings, etc.)
2. Implement recurring transactions
3. Add user authentication and authorization
4. Create a persistent storage system
5. Implement a simple command-line interface

Good luck with your implementation!
