#include "Car_starter.h"

// TODO: Implement Car constructor
// Remember:
// 1. Use initialization list to:
//    - Call Vehicle constructor with base class parameters
//    - Initialize Car's members (numDoors, fuelType)
// 2. Print creation message in constructor body
// Example:
// Car::Car(string make, string model, int year, double price,
//          int doors, string fuel)
//     : Vehicle(make, model, year, price),
//       numDoors(doors), fuelType(fuel) {
//     cout << "Creating car with " << doors << " doors" << endl;
// }

// TODO: Implement Car destructor
// Remember:
// 1. Mark as override
// 2. Print destruction message
// 3. Base class destructor will be called automatically

// TODO: Implement getter methods
// - Return corresponding member variables
// - Keep const correctness
// Example:
// int Car::getNumDoors() const {
//     return numDoors;
// }

// TODO: Implement displayInfo()
// Remember:
// 1. Mark as override
// 2. Call base class displayInfo() first
// 3. Add Car-specific information
// Example:
// void Car::displayInfo() const override {
//     Vehicle::displayInfo();
//     cout << "Type: Car" << endl;
//     // Add more Car details...
// }

// TODO: Implement calculateValue()
// Remember:
// 1. Mark as override
// 2. Get base value from Vehicle's calculateValue()
// 3. Apply fuel type adjustments
// Example:
// double Car::calculateValue() const override {
//     double baseValue = Vehicle::calculateValue();
//     // Apply adjustments based on fuelType...
//     return adjustedValue;
// }
