#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

// TODO: Implement the Account base class
class Account {
protected:
    // TODO: Add protected members for:
    // - accountNumber
    // - accountHolder
    // - balance
    // - transactionHistory
    
public:
    // TODO: Implement constructor and virtual destructor
    
    // TODO: Add pure virtual methods for:
    // - deposit()
    // - withdraw()
    // - calculateInterest()
    // - displayInfo()
    
    // TODO: Add common methods for:
    // - getBalance()
    // - getAccountNumber()
    // - addTransaction()
    // - displayTransactions()
};

// TODO: Implement the SavingsAccount class that inherits from Account
class SavingsAccount {
protected:
    // TODO: Add protected members for:
    // - interestRate
    // - minimumBalance
    
public:
    // TODO: Implement constructor and destructor
    
    // TODO: Override base class methods
    
    // TODO: Add SavingsAccount-specific methods:
    // - addInterest()
    // - setMinimumBalance()
};

// TODO: Implement the CheckingAccount class that inherits from Account
class CheckingAccount {
private:
    // TODO: Add members for:
    // - overdraftLimit
    // - monthlyFee
    
public:
    // TODO: Implement constructor and destructor
    
    // TODO: Override base class methods
    
    // TODO: Add CheckingAccount-specific methods:
    // - processCheck()
    // - applyMonthlyFee()
};

// TODO: Implement the MoneyMarket class that inherits from SavingsAccount
class MoneyMarket {
private:
    // TODO: Add members for:
    // - minimumInvestment
    // - tierLevel
    
public:
    // TODO: Implement constructor and destructor
    
    // TODO: Override inherited methods
    
    // TODO: Add MoneyMarket-specific methods:
    // - updateTierLevel()
    // - calculateBonus()
};

// Helper struct for transactions
struct Transaction {
    std::string date;
    std::string type;
    double amount;
    double balanceAfter;
    
    Transaction(std::string d, std::string t, double a, double b)
        : date(d), type(t), amount(a), balanceAfter(b) {}
};

#endif // ACCOUNT_H
