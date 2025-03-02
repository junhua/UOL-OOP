#include <iostream>
#include <vector>
#include <iomanip>
#include "Vehicle_starter.h"

using namespace std;

/**
 * Practice Exercise: Vehicle System
 * 
 * This program demonstrates multi-level inheritance in a vehicle classification system.
 * Complete the Vehicle_starter.h file, then use this main file to test your implementation.
 * 
 * Tasks:
 * 1. Implement the Vehicle base class with:
 *    - Basic vehicle properties (make, model, year, registration)
 *    - Pure virtual methods for core operations
 * 
 * 2. Implement the LandVehicle class that inherits from Vehicle:
 *    - Add land-specific properties (wheels, engine type)
 *    - Override base class methods
 *    - Add land vehicle operations
 * 
 * 3. Implement the Car class that inherits from LandVehicle:
 *    - Add car-specific features
 *    - Override inherited methods
 *    - Implement car operations
 * 
 * 4. Implement the Motorcycle class that inherits from LandVehicle:
 *    - Add motorcycle-specific features
 *    - Override inherited methods
 *    - Implement motorcycle operations
 */

int main() {
    cout << "Vehicle Classification System" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Create a vector of Vehicle pointers
    
    // TODO: Add various vehicles:
    // - Car: Toyota Camry (2022, Hybrid)
    // - Car: Tesla Model 3 (2023, Electric)
    // - Motorcycle: Harley Davidson (2021, Cruiser)
    // - Motorcycle: Ducati (2023, Sport)
    
    // TODO: Demonstrate inheritance hierarchy:
    // - Show vehicle info
    // - Start and stop vehicles
    // - Use land vehicle methods
    // - Test specific features:
    //   * Car: AC and trunk
    //   * Motorcycle: lean and stand
    
    // TODO: Test polymorphic behavior:
    // - Use base class pointers
    // - Call virtual methods
    // - Verify proper overriding
    
    // TODO: Clean up allocated memory
    
    return 0;
}
