#include <iostream>
#include <vector>
#include <iomanip>
#include "Vehicle_starter.h"
#include "Car_starter.h"

using namespace std;

/**
 * This program demonstrates base and derived class relationships
 * using Vehicle and Car classes.
 * 
 * Complete the Vehicle_starter and Car_starter files, then use
 * this program to test your implementation.
 * 
 * Tasks:
 * 1. Implement Vehicle base class:
 *    - Add member variables
 *    - Create constructor and destructor
 *    - Implement virtual methods
 * 
 * 2. Implement Car derived class:
 *    - Add car-specific members
 *    - Chain to base constructor
 *    - Override virtual methods
 */

int main() {
    cout << "Vehicle Management System" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Test Vehicle base class
    cout << "\nTesting Vehicle Base Class:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create a Vehicle
    // Vehicle* vehicle = new Vehicle("Toyota", "Camry", 2020, 25000);
    
    // TODO: Test Vehicle methods
    // - Display vehicle info
    // - Calculate and show value
    // - Clean up
    
    // TODO: Test Car derived class
    cout << "\nTesting Car Derived Class:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create different types of Cars
    // - Regular gasoline car
    // - Electric car (should have higher value)
    // - Hybrid car
    
    // TODO: Test Car methods
    // - Display car info
    // - Show fuel types
    // - Calculate values
    // - Clean up
    
    // TODO: Test polymorphic behavior
    cout << "\nTesting Polymorphism:" << endl;
    cout << string(30, '-') << endl;
    
    // TODO: Create a vector of Vehicle pointers
    // vector<Vehicle*> vehicles;
    
    // TODO: Add different vehicles to vector
    
    // TODO: Process all vehicles polymorphically
    // - Display info for each
    // - Calculate values
    // - Clean up properly
    
    cout << "\nProgram completed successfully" << endl;
    
    return 0;
}
