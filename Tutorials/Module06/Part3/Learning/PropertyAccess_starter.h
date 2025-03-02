#ifndef PROPERTYACCESS_H
#define PROPERTYACCESS_H

#include <string>
#include <vector>

// TODO: Implement BankAccount class
// - Use getters and setters for properties
// - Validate all data modifications
class BankAccount {
private:
    // TODO: Add private member variables
    // - Account number (read-only)
    // - Balance (read-write with validation)
    // - Account type (read-write with validation)
    // - Transaction history (read-only)
    
public:
    // TODO: Implement constructor
    // - Initialize account with required data
    BankAccount(const std::string& accountNum, const std::string& type);
    
    // TODO: Implement getters
    // - Get account number (const)
    // - Get balance (const)
    // - Get account type (const)
    // - Get transaction history (const)
    const std::string& getAccountNumber() const;
    double getBalance() const;
    const std::string& getAccountType() const;
    std::vector<std::string> getTransactionHistory() const;
    
    // TODO: Implement setters
    // - Set account type (with validation)
    // - Set balance (through deposit/withdraw)
    bool setAccountType(const std::string& type);
    bool deposit(double amount);
    bool withdraw(double amount);
};

// TODO: Implement Employee class
// - Use getters and setters for properties
// - Track property modifications
class Employee {
private:
    // TODO: Add private member variables
    // - Employee ID (read-only)
    // - Name (read-write)
    // - Position (read-write with validation)
    // - Salary (read-write with validation)
    // - Modification history
    
public:
    // TODO: Implement constructor
    // - Initialize employee data
    Employee(const std::string& id, const std::string& name);
    
    // TODO: Implement getters
    // - Get employee ID (const)
    // - Get name (const)
    // - Get position (const)
    // - Get salary (const)
    const std::string& getEmployeeId() const;
    const std::string& getName() const;
    const std::string& getPosition() const;
    double getSalary() const;
    
    // TODO: Implement setters
    // - Set name (with validation)
    // - Set position (with validation)
    // - Set salary (with validation)
    bool setName(const std::string& name);
    bool setPosition(const std::string& position);
    bool setSalary(double salary);
};

// TODO: Implement Product class
// - Use getters and setters for properties
// - Implement computed properties
class Product {
private:
    // TODO: Add private member variables
    // - Product ID (read-only)
    // - Name (read-write)
    // - Price (read-write with validation)
    // - Quantity (read-write with validation)
    // - Discount rate (read-write with validation)
    
public:
    // TODO: Implement constructor
    // - Initialize product data
    Product(const std::string& id, const std::string& name, double price);
    
    // TODO: Implement basic getters
    // - Get product ID (const)
    // - Get name (const)
    // - Get base price (const)
    // - Get quantity (const)
    const std::string& getProductId() const;
    const std::string& getName() const;
    double getBasePrice() const;
    int getQuantity() const;
    
    // TODO: Implement computed getters
    // - Get discount rate (const)
    // - Get discounted price (const)
    // - Get total value (const)
    double getDiscountRate() const;
    double getDiscountedPrice() const;
    double getTotalValue() const;
    
    // TODO: Implement setters
    // - Set name (with validation)
    // - Set price (with validation)
    // - Set quantity (with validation)
    // - Set discount (with validation)
    bool setName(const std::string& name);
    bool setPrice(double price);
    bool setQuantity(int quantity);
    bool setDiscountRate(double rate);
};

#endif // PROPERTYACCESS_H
