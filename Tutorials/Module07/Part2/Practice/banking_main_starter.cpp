#include <iostream>
#include <vector>
#include <iomanip>
#include "Account_starter.h"

using namespace std;

/**
 * Practice Exercise: Banking System
 * 
 * This program demonstrates inheritance in a banking system context.
 * Complete the Account_starter.h file, then use this main file to test your implementation.
 * 
 * Tasks:
 * 1. Implement the Account base class with:
 *    - Basic account properties
 *    - Transaction tracking
 *    - Pure virtual methods for operations
 * 
 * 2. Implement the SavingsAccount class that inherits from Account:
 *    - Interest rate handling
 *    - Minimum balance requirements
 *    - Override base class methods
 * 
 * 3. Implement the CheckingAccount class that inherits from Account:
 *    - Overdraft protection
 *    - Monthly fees
 *    - Check processing
 * 
 * 4. Implement the MoneyMarket class that inherits from SavingsAccount:
 *    - Tiered interest rates
 *    - Minimum investment requirements
 *    - Investment bonuses
 */

int main() {
    cout << fixed << setprecision(2);
    cout << "Banking System Demonstration" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Create a vector of Account pointers
    
    // TODO: Create various accounts:
    // - Savings Account (5% interest, $1000 minimum)
    // - Checking Account ($500 overdraft, $5 monthly fee)
    // - Money Market Account (6% interest, $10000 minimum)
    
    // TODO: Demonstrate account operations:
    // - Deposit funds
    // - Withdraw funds
    // - Calculate interest
    // - Display account info
    
    // TODO: Test specific account features:
    // Savings:
    // - Add interest
    // - Check minimum balance
    
    // Checking:
    // - Process checks
    // - Apply monthly fee
    // - Test overdraft
    
    // Money Market:
    // - Update tier level
    // - Calculate bonus
    // - Apply tiered interest
    
    // TODO: Display transaction history for each account
    
    // TODO: Test polymorphic behavior:
    // - Use base class pointers
    // - Call virtual methods
    // - Verify proper overriding
    
    // TODO: Clean up allocated memory
    
    return 0;
}
