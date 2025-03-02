#include "Car_starter.h"

// TODO: Implement constructor
// Remember to:
// 1. Initialize base class using Vehicle constructor
// 2. Initialize Car-specific members
// 3. Print creation message
Car::Car(std::string make, std::string model, int year, double price,
         int doors, std::string fuel)
    : Vehicle(make, model, year, price)  // Initialize base class
{
    // Your code here:
    // 1. Initialize numDoors and fuelType
    // 2. Print creation message
}

// TODO: Implement destructor
// Print destruction message
Car::~Car() {
    // Your code here
}

// TODO: Implement getters
int Car::getNumDoors() const {
    // Your code here
    return 0;  // Placeholder return
}

std::string Car::getFuelType() const {
    // Your code here
    return "";  // Placeholder return
}

// TODO: Implement displayInfo
// Remember to:
// 1. Call base class displayInfo first
// 2. Add Car-specific information:
//    - Type (Car)
//    - Number of doors
//    - Fuel type
void Car::displayInfo() const {
    // Your code here
}

// TODO: Implement calculateValue
// Remember to:
// 1. Get base value from Vehicle::calculateValue()
// 2. Apply fuel type adjustments:
//    - Electric: +10% to base value
//    - Hybrid: +5% to base value
double Car::calculateValue() const {
    // Your code here
    return 0.0;  // Placeholder return
}
