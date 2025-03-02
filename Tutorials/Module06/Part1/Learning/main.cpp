#include <iostream>
#include "DataHiding.h"
using namespace std;

void demonstrateBankAccount() {
    cout << "\n=== Bank Account Demo ===\n";
    
    // Poor encapsulation example
    cout << "\nPoor Encapsulation:\n";
    BankAccountPoor poorAccount;
    poorAccount.balance = 1000;  // Direct access - dangerous!
    poorAccount.withdraw(2000);  // No validation - account overdrawn!
    cout << "Balance after invalid withdrawal: " << poorAccount.balance << endl;
    
    // Good encapsulation example
    cout << "\nGood Encapsulation:\n";
    BankAccountGood goodAccount("ACC123");
    goodAccount.deposit(1000);
    cout << "Balance after deposit: $" << goodAccount.getBalance() << endl;
    
    if (!goodAccount.withdraw(2000)) {
        cout << "Withdrawal failed: " << goodAccount.getLastError() << endl;
    }
    
    goodAccount.freeze();
    if (!goodAccount.deposit(500)) {
        cout << "Deposit failed: " << goodAccount.getLastError() << endl;
    }
    
    cout << "\nTransaction History:\n";
    for (const auto& transaction : goodAccount.getTransactionHistory()) {
        cout << transaction << endl;
    }
}

void demonstratePassword() {
    cout << "\n=== Password Management Demo ===\n";
    
    Password pwd(10);  // Minimum length of 10
    
    // Try weak password
    string weakPass = "password123";
    if (!pwd.setPassword(weakPass)) {
        cout << "Weak password rejected: " << pwd.getLastError() << endl;
    }
    
    // Try strong password
    string strongPass = "SecurePass123!";
    if (pwd.setPassword(strongPass)) {
        cout << "Strong password accepted\n";
        cout << "Password strength score: " << pwd.checkStrength(strongPass) << "/8\n";
    }
    
    // Validate password
    string attempt = "WrongPass123!";
    if (!pwd.validatePassword(attempt)) {
        cout << "Invalid password attempt\n";
    }
    
    attempt = strongPass;
    if (pwd.validatePassword(attempt)) {
        cout << "Valid password attempt\n";
    }
}

void demonstrateLogger() {
    cout << "\n=== Logger Demo ===\n";
    
    Logger log(5);  // Keep only last 5 entries
    
    // Log different types of messages
    log.info("Application started");
    log.warning("High memory usage detected");
    log.error("Failed to connect to database");
    log.info("Retrying connection...");
    log.info("Connection established");
    log.info("New entry - should push out oldest");
    
    cout << "\nLog Entries:\n";
    for (const auto& entry : log.getLogs()) {
        cout << entry << endl;
    }
    
    cout << "\nTotal log entries: " << log.size() << endl;
    
    // Change log level to show only errors
    log.setLevel("ERROR");
    log.info("This won't be logged");
    log.warning("This won't be logged either");
    log.error("But this will be logged");
    
    cout << "\nAfter level change to ERROR:\n";
    for (const auto& entry : log.getLogs()) {
        cout << entry << endl;
    }
}

int main() {
    demonstrateBankAccount();
    demonstratePassword();
    demonstrateLogger();
    return 0;
}
