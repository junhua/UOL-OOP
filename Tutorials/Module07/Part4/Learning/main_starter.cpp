#include <iostream>
#include <string>
#include "Base_starter.h"

using namespace std;

/**
 * This program demonstrates different types of inheritance
 * and their effects on member access.
 * 
 * Complete the Base_starter files, then use this program
 * to test your implementation.
 * 
 * Tasks:
 * 1. Implement Base class:
 *    - Add members with different access levels
 *    - Create public interface
 *    - Define protected helpers
 *    - Hide private implementation
 * 
 * 2. Implement derived classes:
 *    - Test public inheritance
 *    - Test protected inheritance
 *    - Test private inheritance
 */

int main() {
    cout << "Testing Inheritance Types" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Test public inheritance
    cout << "\nPublic Inheritance:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create PublicDerived object
    // PublicDerived pub;
    
    // TODO: Test access levels
    // - Call public methods (should work)
    // - Try protected methods (should fail)
    // - Try private methods (should fail)
    // - Test inheritance behavior
    
    // TODO: Test protected inheritance
    cout << "\nProtected Inheritance:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create ProtectedDerived object
    // ProtectedDerived prot;
    
    // TODO: Test access levels
    // - Try public methods (should fail)
    // - Use accessBaseMethod() to test protected access
    // - Verify inheritance behavior
    
    // TODO: Test private inheritance
    cout << "\nPrivate Inheritance:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create PrivateDerived object
    // PrivateDerived priv;
    
    // TODO: Test access levels
    // - Try public methods (should fail)
    // - Use accessBaseMethod() to test private access
    // - Verify inheritance restrictions
    
    // TODO: Test inheritance chains
    cout << "\nInheritance Chains:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Demonstrate further inheritance
    // - Inherit from PublicDerived (should work)
    // - Try to inherit from PrivateDerived (should fail)
    // - Show access level propagation
    
    cout << "\nProgram completed successfully" << endl;
    
    return 0;
}
