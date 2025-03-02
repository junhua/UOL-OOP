---
layout: default
title: Part 1 - Data Hiding
nav_order: 1
parent: Module 6 - Core OOP Concepts - Encapsulation
grand_parent: Tutorials
permalink: /tutorials/module6/part1-data-hiding/
---

# Part 1: Data Hiding

## Learning Objectives
- Understand data hiding and encapsulation principles
- Master validation and error handling
- Learn state management techniques
- Practice secure data handling
- Implement logging and monitoring
- Create maintainable code

## Introduction
Encapsulation is one of the fundamental principles of object-oriented programming. It combines data hiding and abstraction to create secure, maintainable code. Think of it through these real-world analogies:

1. **Bank Account**
   - Public interface: Deposit/withdraw money (like ATM buttons)
   - Private data: Account balance (hidden from view)
   - Validation: Check sufficient funds (prevent overdraft)
   - State tracking: Transaction history (record all changes)

2. **Password Manager**
   - Public interface: Set/validate password
   - Private data: Hashed password (never stored in plain text)
   - Validation: Check password strength
   - Security: Salt and hash for storage

3. **Car Dashboard**
   - Public interface: Simple controls and displays
   - Private mechanics: Complex engine operations
   - State management: Warning lights and indicators
   - Error handling: Diagnostic messages

### Why Use Encapsulation?

1. **Data Protection**
   - Prevent unauthorized access
   - Control data modification
   - Maintain object state integrity
   - Validate all inputs
   - Track changes

2. **Code Organization**
   - Clear separation of concerns
   - Better maintainability
   - Reduced complexity
   - Improved testing
   - Easier debugging

3. **Implementation Flexibility**
   - Change internals without affecting users
   - Version control friendly
   - Better evolution
   - Simplified updates
   - Enhanced security

## Implementation Guide

You'll find the starter code in `Tutorials/Module06/Part1/Learning/DataHiding_starter.h` and `Tutorials/Module06/Part1/Learning/main_starter.cpp`. 

You can compare your implementation with the completed versions in `Tutorials/Module06/Part1/Learning/DataHiding.h` and `Tutorials/Module06/Part1/Learning/main.cpp`.

### Step 1: Basic Data Hiding
Start with a bank account example showing poor vs. good encapsulation:

```cpp
// Poor encapsulation - DON'T DO THIS
class BankAccountPoor {
public:
    double balance;  // Directly accessible
    std::string accountNumber;  // No protection
    bool frozen;  // Anyone can modify
    
    void deposit(double amount) {
        balance += amount;  // No validation
    }
    
    void withdraw(double amount) {
        balance -= amount;  // No checks
    }
};

// Good encapsulation
class BankAccountGood {
private:
    double balance;
    std::string accountNumber;
    bool frozen;
    std::vector<std::string> transactionHistory;
    mutable std::string lastError;
    
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
        ss << " - " << type << ": $" << std::fixed 
           << std::setprecision(2) << amount;
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
    
    // Controlled access to data
    double getBalance() const { return balance; }
    std::string getAccountNumber() const { return accountNumber; }
    bool isFrozen() const { return frozen; }
    std::vector<std::string> getTransactionHistory() const {
        return transactionHistory;
    }
    std::string getLastError() const { return lastError; }
    
    // Account management
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
};
```

Key Points:
- Private data members
- Validation methods
- Error tracking
- Transaction history
- State management

### Step 2: Secure Data Management
Implement a password management system:

```cpp
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
    
    // Simple hash function (for demonstration)
    std::string hashPassword(const std::string& password, 
                           const std::string& salt) const {
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
        
        // Length checks
        if (password.length() >= minLength) score++;
        if (password.length() >= minLength + 4) score++;
        
        // Character type checks
        bool hasUpper = false, hasLower = false;
        bool hasDigit = false, hasSpecial = false;
        
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
    
    std::string getLastError() const { return lastError; }
};
```

Key Points:
- Secure storage
- Password validation
- Strength checking
- Salt generation
- Error reporting

### Step 3: State Management
Create a logging system with proper state management:

```cpp
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
    
    std::vector<std::string> getLogs() const { return entries; }
    void clearLogs() { entries.clear(); }
    size_t size() const { return entries.size(); }
    std::string getLastError() const { return lastError; }
};
```

Key Points:
- Log level management
- Message formatting
- Size control
- Error handling
- State tracking

## Practice Exercise

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module06/Part1/Practice/SecureMessage_starter.h` and `Tutorials/Module06/Part1/Practice/secure_message_test.cpp`
- Complete solution: `Tutorials/Module06/Part1/Practice/SecureMessage.h` and `Tutorials/Module06/Part1/Practice/secure_message_test.cpp`

Create a secure messaging system that combines all three concepts:
1. Data protection (like BankAccount)
2. Security (like Password)
3. State management (like Logger)

Requirements:
1. Message content must be protected
2. Sender/recipient validation
3. Optional encryption
4. Access control
5. Activity logging
6. Error handling

## Best Practices

### 1. Data Protection
```cpp
class User {
private:
    std::string password;  // Never expose sensitive data
    std::vector<std::string> accessLog;  // Track all access
    
    bool validatePassword(const std::string& input) const {
        return password == hashPassword(input);
    }
    
    void logAccess(const std::string& action) {
        accessLog.push_back(getTimestamp() + ": " + action);
    }
    
public:
    bool authenticate(const std::string& input) {
        bool result = validatePassword(input);
        logAccess(result ? "Login success" : "Login failed");
        return result;
    }
};
```

### 2. State Management
```cpp
class Connection {
private:
    enum class State { Disconnected, Connecting, Connected, Error };
    State state;
    std::string errorMessage;
    std::vector<std::string> stateHistory;
    
    void setState(State newState, const std::string& error = "") {
        stateHistory.push_back(
            getTimestamp() + ": " + 
            std::to_string(static_cast<int>(state)) + " -> " +
            std::to_string(static_cast<int>(newState))
        );
        state = newState;
        errorMessage = error;
    }
    
public:
    bool connect() {
        if (state == State::Connected) return true;
        setState(State::Connecting);
        // Connection logic
        setState(State::Connected);
        return true;
    }
};
```

### 3. Error Handling
```cpp
class Transaction {
private:
    double amount;
    std::string type;
    mutable std::string lastError;
    
    bool validate() const {
        if (amount <= 0) {
            lastError = "Invalid amount";
            return false;
        }
        if (type.empty()) {
            lastError = "Missing type";
            return false;
        }
        return true;
    }
    
public:
    bool process() {
        if (!validate()) return false;
        // Processing logic
        return true;
    }
    
    std::string getError() const { return lastError; }
};
```

## Common Pitfalls

### 1. Insufficient Protection
```cpp
// Bad: Public data
class UserData {
public:
    string password;  // NEVER expose passwords
};

// Good: Protected data
class UserData {
private:
    string hashedPassword;
public:
    bool validatePassword(const string& input);
};
```

### 2. Poor Error Handling
```cpp
// Bad: Silent failures
void process(int value) {
    if (value < 0) return;  // Error lost
}

// Good: Error reporting
bool process(int value) {
    if (value < 0) {
        lastError = "Invalid value";
        return false;
    }
    return true;
}
```

### 3. Inconsistent State
```cpp
// Bad: State can become invalid
class Account {
public:
    void setBalance(double b) { balance = b; }
    void setLimit(double l) { limit = l; }
};

// Good: State consistency
class Account {
public:
    bool setLimits(double balance, double limit) {
        if (balance > limit) return false;
        this->balance = balance;
        this->limit = limit;
        return true;
    }
};
```

## Next Steps
1. Complete the practice exercise
2. Review your code for encapsulation issues
3. Apply these patterns to your projects
4. Move on to [Part 2: Access Specifiers]({{ site.baseurl }}/tutorials/module6/part2-access-specifiers)

Remember: Good encapsulation is about protecting data integrity while providing a clean, usable interface. Always think about what should be hidden and what should be exposed.
