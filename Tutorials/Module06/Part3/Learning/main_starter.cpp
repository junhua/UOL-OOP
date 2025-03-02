#include <iostream>
#include <iomanip>
#include "PropertyAccess_starter.h"
using namespace std;

// TODO: Implement bank account demo
// - Create account
// - Test property access
// - Validate modifications
void bankAccountDemo() {
    cout << "\nBank Account Demo" << endl;
    cout << "=================" << endl;
    
    // TODO: Create bank account
    // - Initialize with account number and type
    
    // TODO: Test read-only properties
    // - Try accessing account number
    // - Verify immutability
    
    // TODO: Test validated setters
    // - Deposit valid amount
    // - Try negative deposit
    // - Withdraw valid amount
    // - Try excessive withdrawal
    
    // TODO: Test type modification
    // - Change to valid type
    // - Try invalid type
    // - Verify changes
}

// TODO: Implement employee demo
// - Create employee
// - Modify properties
// - Track changes
void employeeDemo() {
    cout << "\nEmployee Demo" << endl;
    cout << "=============" << endl;
    
    // TODO: Create employee
    // - Set initial values
    
    // TODO: Test property modifications
    // - Update name
    // - Change position
    // - Adjust salary
    
    // TODO: Test validation
    // - Try invalid values
    // - Verify constraints
    
    // TODO: Display changes
    // - Show modification history
    // - Verify tracking
}

// TODO: Implement product demo
// - Create product
// - Test computed properties
// - Validate updates
void productDemo() {
    cout << "\nProduct Demo" << endl;
    cout << "============" << endl;
    
    // TODO: Create product
    // - Set initial values
    
    // TODO: Test basic properties
    // - Get/set name
    // - Update price
    // - Modify quantity
    
    // TODO: Test computed properties
    // - Set discount rate
    // - Get discounted price
    // - Calculate total value
    
    // TODO: Test validation
    // - Try invalid price
    // - Try invalid quantity
    // - Try invalid discount
}

// TODO: Implement property patterns demo
// - Show different patterns
// - Compare approaches
void patternsDemo() {
    cout << "\nProperty Patterns Demo" << endl;
    cout << "====================" << endl;
    
    // TODO: Demonstrate read-only
    // - Show immutable properties
    // - Explain use cases
    
    // TODO: Demonstrate computed
    // - Show derived values
    // - Explain caching
    
    // TODO: Demonstrate validation
    // - Show different approaches
    // - Compare strategies
}

int main() {
    cout << "Property Access Demo" << endl;
    cout << "===================" << endl;
    
    bankAccountDemo();
    employeeDemo();
    productDemo();
    patternsDemo();
    
    return 0;
}
