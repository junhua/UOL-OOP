---
layout: default
title: Part 2 - Access Specifiers
nav_order: 2
parent: Module 6 - Core OOP Concepts - Encapsulation
grand_parent: Tutorials
permalink: /tutorials/module6/part2-access-specifiers/
---

# Part 2: Access Specifiers

## Introduction
Access specifiers are the mechanisms C++ provides to control visibility and accessibility of class members. Think of them like security clearance levels:
- Public members (Level 1): Anyone can access
- Protected members (Level 2): Only family members (derived classes) can access
- Private members (Level 3): Only the class itself can access

### Why Use Access Specifiers?
1. **Data Protection**
   - Control access to sensitive data
   - Prevent unauthorized modifications
   - Maintain class invariants
   - Enforce validation

2. **Interface Design**
   - Create clean public interfaces
   - Hide implementation details
   - Support inheritance properly
   - Enable future changes

3. **Code Organization**
   - Group related functionality
   - Separate interface from implementation
   - Control inheritance relationships
   - Manage dependencies

## Implementation Guide

You'll find the starter code in `Tutorials/Module06/Part2/Learning/AccessControl_starter.h` and `Tutorials/Module06/Part2/Learning/main_starter.cpp`. 

You can compare your implementation with the completed versions in `Tutorials/Module06/Part2/Learning/AccessControl.h`, `Tutorials/Module06/Part2/Learning/AccessControl.cpp`, and `Tutorials/Module06/Part2/Learning/main.cpp`.

### Step 1: Basic Access Control
Start with a simple example showing different access levels:

```cpp
class BankAccount {
private:  // Only accessible within this class
    double balance;
    std::string accountNumber;
    std::vector<std::string> transactionHistory;
    
    bool isValidAmount(double amount) const {
        return amount > 0;
    }
    
protected:  // Accessible in this class and derived classes
    void addTransaction(const std::string& description) {
        transactionHistory.push_back(description);
    }
    
    double getBalance() const {
        return balance;
    }
    
public:  // Accessible by anyone
    BankAccount(const std::string& accNum)
        : balance(0), accountNumber(accNum) {}
    
    bool deposit(double amount) {
        if (!isValidAmount(amount)) {
            return false;
        }
        balance += amount;
        addTransaction("Deposit: " + std::to_string(amount));
        return true;
    }
    
    bool withdraw(double amount) {
        if (!isValidAmount(amount) || amount > balance) {
            return false;
        }
        balance -= amount;
        addTransaction("Withdrawal: " + std::to_string(amount));
        return true;
    }
    
    std::string getAccountNumber() const {
        return accountNumber;
    }
    
    std::vector<std::string> getTransactions() const {
        return transactionHistory;
    }
};
```

### Step 2: Inheritance and Access Control
Demonstrate how access specifiers work with inheritance:

```cpp
class SavingsAccount : public BankAccount {
private:
    double interestRate;
    double minimumBalance;
    
    bool isBelowMinimum() const {
        return getBalance() < minimumBalance;  // Can access protected member
    }
    
public:
    SavingsAccount(const std::string& accNum, double rate, double minBal)
        : BankAccount(accNum), interestRate(rate), minimumBalance(minBal) {}
    
    bool withdraw(double amount) {
        if (isBelowMinimum()) {
            return false;
        }
        return BankAccount::withdraw(amount);  // Call base class method
    }
    
    void applyInterest() {
        double interest = getBalance() * interestRate;
        deposit(interest);
        addTransaction("Interest: " + std::to_string(interest));
    }
};

class CheckingAccount : public BankAccount {
private:
    int transactionLimit;
    int monthlyTransactions;
    
protected:
    void resetTransactionCount() {
        monthlyTransactions = 0;
    }
    
public:
    CheckingAccount(const std::string& accNum, int limit)
        : BankAccount(accNum), transactionLimit(limit), monthlyTransactions(0) {}
    
    bool withdraw(double amount) {
        if (monthlyTransactions >= transactionLimit) {
            return false;
        }
        if (BankAccount::withdraw(amount)) {
            monthlyTransactions++;
            return true;
        }
        return false;
    }
};
```

### Step 3: Friend Declarations
Show how to use friend declarations for controlled access:

```cpp
class AccountManager;  // Forward declaration

class Account {
private:
    double balance;
    std::string accountNumber;
    
    friend class AccountManager;  // Give AccountManager access to private members
    friend void auditAccount(const Account& acc);  // Friend function
    
public:
    Account(const std::string& accNum) : balance(0), accountNumber(accNum) {}
    
    // Public interface methods...
};

class AccountManager {
public:
    void transferFunds(Account& from, Account& to, double amount) {
        // Can access private members of Account
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
        }
    }
    
    void adjustBalance(Account& acc, double amount) {
        // Direct access to private members
        acc.balance += amount;
    }
};

void auditAccount(const Account& acc) {
    // Friend function can access private members
    cout << "Account " << acc.accountNumber 
         << " Balance: " << acc.balance << endl;
}
```

## Practice Exercise

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module06/Part2/Practice/LibraryItem_starter.h`, `Tutorials/Module06/Part2/Practice/LibraryItem_starter.cpp`, and `Tutorials/Module06/Part2/Practice/library_test.cpp`
- Complete solution: `Tutorials/Module06/Part2/Practice/LibraryItem.h`, `Tutorials/Module06/Part2/Practice/LibraryItem.cpp`, and `Tutorials/Module06/Part2/Practice/library_test.cpp`

Create a library management system with proper access control:

```cpp
class LibraryItem {
private:
    std::string id;
    std::string title;
    bool checkedOut;
    std::string currentBorrower;
    std::chrono::system_clock::time_point dueDate;
    std::vector<std::string> history;
    
protected:
    void addToHistory(const std::string& event) {
        history.push_back(event + " - " + 
            std::to_string(std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now())));
    }
    
    bool isOverdue() const {
        return checkedOut && 
               std::chrono::system_clock::now() > dueDate;
    }
    
public:
    LibraryItem(const std::string& itemId, const std::string& itemTitle)
        : id(itemId), title(itemTitle), checkedOut(false) {}
    
    virtual bool checkOut(const std::string& borrower) {
        if (checkedOut) return false;
        
        checkedOut = true;
        currentBorrower = borrower;
        dueDate = std::chrono::system_clock::now() + 
                  std::chrono::hours(24 * 14);  // 2 weeks
        
        addToHistory("Checked out to " + borrower);
        return true;
    }
    
    virtual bool checkIn() {
        if (!checkedOut) return false;
        
        checkedOut = false;
        addToHistory("Checked in from " + currentBorrower);
        currentBorrower.clear();
        return true;
    }
    
    virtual std::string getStatus() const {
        std::stringstream ss;
        ss << "Item: " << title << " (ID: " << id << ")\n"
           << "Status: " << (checkedOut ? "Checked Out" : "Available") << "\n";
        if (checkedOut) {
            ss << "Borrower: " << currentBorrower << "\n"
               << "Due: " << std::chrono::system_clock::to_time_t(dueDate) << "\n"
               << "Overdue: " << (isOverdue() ? "Yes" : "No") << "\n";
        }
        return ss.str();
    }
    
    std::vector<std::string> getHistory() const {
        return history;
    }
};

class Book : public LibraryItem {
private:
    std::string author;
    std::string isbn;
    bool isReference;
    
public:
    Book(const std::string& id, const std::string& title,
         const std::string& author, const std::string& isbn,
         bool reference = false)
        : LibraryItem(id, title), author(author), isbn(isbn),
          isReference(reference) {}
    
    bool checkOut(const std::string& borrower) override {
        if (isReference) {
            addToHistory("Checkout denied - Reference book");
            return false;
        }
        return LibraryItem::checkOut(borrower);
    }
    
    std::string getStatus() const override {
        std::string status = LibraryItem::getStatus();
        status += "Type: Book\n"
                 "Author: " + author + "\n"
                 "ISBN: " + isbn + "\n"
                 "Reference: " + std::string(isReference ? "Yes" : "No") + "\n";
        return status;
    }
};

class DVD : public LibraryItem {
private:
    int duration;  // minutes
    bool isRestricted;
    std::vector<std::string> authorizedBorrowers;
    
protected:
    bool isBorrowerAuthorized(const std::string& borrower) const {
        return !isRestricted || 
               std::find(authorizedBorrowers.begin(),
                        authorizedBorrowers.end(),
                        borrower) != authorizedBorrowers.end();
    }
    
public:
    DVD(const std::string& id, const std::string& title,
        int duration, bool restricted = false)
        : LibraryItem(id, title), duration(duration),
          isRestricted(restricted) {}
    
    bool addAuthorizedBorrower(const std::string& borrower) {
        if (!isRestricted) return false;
        authorizedBorrowers.push_back(borrower);
        return true;
    }
    
    bool checkOut(const std::string& borrower) override {
        if (isRestricted && !isBorrowerAuthorized(borrower)) {
            addToHistory("Checkout denied - Unauthorized borrower: " + borrower);
            return false;
        }
        return LibraryItem::checkOut(borrower);
    }
    
    std::string getStatus() const override {
        std::string status = LibraryItem::getStatus();
        status += "Type: DVD\n"
                 "Duration: " + std::to_string(duration) + " minutes\n"
                 "Restricted: " + std::string(isRestricted ? "Yes" : "No") + "\n";
        return status;
    }
};

int main() {
    // Create library items
    Book book1("B001", "C++ Programming", "John Doe", "123-456-789");
    Book book2("B002", "C++ Reference", "Jane Smith", "987-654-321", true);
    DVD dvd1("D001", "C++ Tutorial", 120);
    DVD dvd2("D002", "Advanced C++", 180, true);
    
    // Test book checkout
    if (book1.checkOut("Alice")) {
        cout << "Book checked out successfully" << endl;
        cout << book1.getStatus() << endl;
    }
    
    if (!book2.checkOut("Bob")) {
        cout << "Cannot check out reference book" << endl;
        cout << book2.getStatus() << endl;
    }
    
    // Test DVD checkout
    dvd2.addAuthorizedBorrower("Charlie");
    
    if (!dvd2.checkOut("Alice")) {
        cout << "Unauthorized access prevented" << endl;
    }
    
    if (dvd2.checkOut("Charlie")) {
        cout << "Authorized access granted" << endl;
        cout << dvd2.getStatus() << endl;
    }
    
    // Display history
    cout << "\nBook History:" << endl;
    for (const auto& event : book1.getHistory()) {
        cout << event << endl;
    }
    
    cout << "\nDVD History:" << endl;
    for (const auto& event : dvd2.getHistory()) {
        cout << event << endl;
    }
    
    return 0;
}
```

## Best Practices

### 1. Access Level Selection
```cpp
class DataManager {
private:
    // Implementation details
    std::vector<int> data;
    void sortData();
    
protected:
    // Derived class helpers
    void validateData();
    void preprocessData();
    
public:
    // Public interface
    bool addData(int value);
    std::vector<int> getData() const;
};
```

### 2. Inheritance Design
```cpp
class Shape {
protected:
    // Shared with derived classes
    double x, y;
    void moveTo(double newX, double newY);
    
public:
    // Public interface
    virtual double area() const = 0;
    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    // Circle-specific data
    double radius;
    
public:
    // Implement interface
    double area() const override;
    void draw() override;
};
```

### 3. Friend Usage
```cpp
class Engine;  // Forward declaration

class Car {
private:
    Engine* engine;
    
    friend class Mechanic;  // Give access to Mechanic
    friend void emergencyRepair(Car& car);  // Friend function
};

class Mechanic {
public:
    void repair(Car& car) {
        // Can access car's private members
    }
};
```

## Common Pitfalls

### 1. Over-using Friends
```cpp
// Bad: Too many friends
class Data {
    friend class A;  // Unnecessary
    friend class B;  // Unnecessary
    friend class C;  // Unnecessary
};

// Good: Minimal friends
class Data {
    friend class DataManager;  // Only necessary friend
};
```

### 2. Wrong Access Level
```cpp
// Bad: Protected when private would suffice
class Base {
protected:
    void helper();  // Not needed by derived classes
};

// Good: Appropriate access
class Base {
private:
    void helper();  // Internal use only
protected:
    void derivedHelper();  // Actually needed by derived classes
};
```

### 3. Public Data Members
```cpp
// Bad: Public data
class Point {
public:
    int x, y;  // No control over access
};

// Good: Controlled access
class Point {
private:
    int x, y;
public:
    void setPosition(int newX, int newY);
    std::pair<int, int> getPosition() const;
};
```

## Next Steps
1. Complete the practice exercise
2. Review your class hierarchies
3. Apply proper access control
4. Move on to [Part 3: Getter and Setter Methods]({{ site.baseurl }}/tutorials/module6/part3-getters-setters)

Remember: Choose the most restrictive access level that still allows your code to function. This helps maintain encapsulation and makes your code more maintainable.
