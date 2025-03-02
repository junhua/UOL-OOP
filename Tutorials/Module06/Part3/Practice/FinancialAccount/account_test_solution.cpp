#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include "FinancialAccount.h"

using namespace std;

/**
 * Test program for the Financial Account implementation
 * 
 * This program demonstrates:
 * 1. Creating and managing accounts
 * 2. Processing deposits and withdrawals
 * 3. Performing transfers between accounts
 * 4. Testing security features
 * 5. Processing interest
 * 6. Generating account statements
 */
int main() {
    cout << "Banking System" << endl;
    cout << "==================================================" << endl << endl;

    // Create a banking system
    Bank bank(0.03);  // 3% annual interest rate
    
    // Create accounts
    cout << "Creating accounts..." << endl;
    
    bank.createAccount("1001", "John Doe");
    bank.createAccount("1002", "Jane Smith");
    bank.createAccount("1003", "Bob Johnson");
    
    cout << "Created account: 1001 (John Doe)" << endl;
    cout << "Created account: 1002 (Jane Smith)" << endl;
    cout << "Created account: 1003 (Bob Johnson)" << endl;
    cout << endl;

    // Process deposits
    cout << "Processing deposits..." << endl;
    
    const Account* account1 = bank.getAccount("1001");
    const Account* account2 = bank.getAccount("1002");
    const Account* account3 = bank.getAccount("1003");
    
    // We need to cast away const to modify the accounts
    // In a real application, we would use a non-const getter or a deposit method on the Bank class
    Account* acc1 = const_cast<Account*>(account1);
    Account* acc2 = const_cast<Account*>(account2);
    Account* acc3 = const_cast<Account*>(account3);
    
    acc1->deposit(1000.0, "Initial deposit");
    acc2->deposit(2500.0, "Initial deposit");
    acc3->deposit(750.0, "Initial deposit");
    
    cout << "Deposited $1000.00 to account 1001" << endl;
    cout << "Deposited $2500.00 to account 1002" << endl;
    cout << "Deposited $750.00 to account 1003" << endl;
    cout << endl;

    // Process withdrawals
    cout << "Processing withdrawals..." << endl;
    
    acc1->withdraw(250.0, "ATM withdrawal");
    acc2->withdraw(500.0, "Online payment");
    bool result = acc3->withdraw(1000.0, "Cash withdrawal");
    
    cout << "Withdrew $250.00 from account 1001" << endl;
    cout << "Withdrew $500.00 from account 1002" << endl;
    
    if (!result) {
        cout << "Withdrawal failed: " << acc3->getLastError() 
             << " (Attempted to withdraw $1000.00 from account 1003)" << endl;
    }
    cout << endl;

    // Process transfers
    cout << "Processing transfers..." << endl;
    
    bank.transfer("1002", "1003", 300.0);
    result = bank.transfer("1001", "1003", 2000.0);
    
    cout << "Transferred $300.00 from account 1002 to account 1003" << endl;
    
    if (!result) {
        cout << "Transfer failed: " << bank.getLastError() 
             << " (Attempted to transfer $2000.00 from account 1001 to account 1003)" << endl;
    }
    cout << endl;

    // Display account balances
    cout << "Account balances:" << endl;
    cout << "Account 1001: $" << fixed << setprecision(2) << acc1->getBalance() << endl;
    cout << "Account 1002: $" << fixed << setprecision(2) << acc2->getBalance() << endl;
    cout << "Account 1003: $" << fixed << setprecision(2) << acc3->getBalance() << endl;
    cout << endl;

    // Test security features
    cout << "Testing security features..." << endl;
    
    acc1->freeze();
    cout << "Account 1001 frozen" << endl;
    
    result = acc1->deposit(100.0, "Test deposit");
    if (!result) {
        cout << "Deposit failed: " << acc1->getLastError() << endl;
    }
    
    acc1->unfreeze();
    cout << "Account 1001 unfrozen" << endl;
    
    acc1->deposit(100.0);
    cout << "Deposited $100.00 to account 1001" << endl;
    cout << endl;

    // Process interest
    cout << "Processing interest (3% annual rate)..." << endl;
    
    // Calculate interest for 30 days
    double interest1 = acc1->calculateInterest(30);
    double interest2 = acc2->calculateInterest(30);
    double interest3 = acc3->calculateInterest(30);
    
    acc1->addInterest(30);
    acc2->addInterest(30);
    acc3->addInterest(30);
    
    cout << "Interest added to account 1001: $" << fixed << setprecision(2) << interest1 << endl;
    cout << "Interest added to account 1002: $" << fixed << setprecision(2) << interest2 << endl;
    cout << "Interest added to account 1003: $" << fixed << setprecision(2) << interest3 << endl;
    cout << endl;

    // Generate account statement
    cout << "Account statement for 1001:" << endl;
    string statement = acc1->generateStatement();
    cout << statement << endl;

    cout << "Program completed successfully" << endl;
    return 0;
}
