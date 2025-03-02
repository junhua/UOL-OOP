#include <iostream>
#include "DataHiding.h"
using namespace std;

// TODO: Implement bank account demonstration
void demonstrateBankAccount() {
    cout << "\n=== Bank Account Demo ===\n";
    
    // TODO: Demonstrate poor encapsulation
    // - Create account
    // - Show problems with direct access
    // - Show problems with no validation
    cout << "\nPoor Encapsulation:\n";
    
    // TODO: Demonstrate good encapsulation
    // - Create account
    // - Test deposit with validation
    // - Test withdrawal with validation
    // - Test account freezing
    // - Show transaction history
    cout << "\nGood Encapsulation:\n";
}

// TODO: Implement password management demonstration
void demonstratePassword() {
    cout << "\n=== Password Management Demo ===\n";
    
    // TODO: Create password manager
    // - Set minimum length requirement
    
    // TODO: Test weak password
    // - Try password that doesn't meet requirements
    // - Show rejection
    
    // TODO: Test strong password
    // - Try password that meets requirements
    // - Show acceptance
    // - Show strength score
    
    // TODO: Test password validation
    // - Try incorrect password
    // - Try correct password
}

// TODO: Implement logger demonstration
void demonstrateLogger() {
    cout << "\n=== Logger Demo ===\n";
    
    // TODO: Create logger
    // - Set maximum size limit
    
    // TODO: Test different log levels
    // - Log info messages
    // - Log warning messages
    // - Log error messages
    
    // TODO: Show log entries
    // - Display all entries
    // - Show total count
    
    // TODO: Test log level filtering
    // - Change log level
    // - Show filtered messages
}

int main() {
    // TODO: Run all demonstrations
    demonstrateBankAccount();
    demonstratePassword();
    demonstrateLogger();
    return 0;
}
