#include "Vehicle_starter.h"

// TODO: Implement constructor
// Initialize member variables using initialization list
// Print creation message
Vehicle::Vehicle(std::string make, std::string model, int year, double price) {
    // Your code here
}

// TODO: Implement destructor
// Print destruction message
Vehicle::~Vehicle() {
    // Your code here
}

// TODO: Implement getters
std::string Vehicle::getMake() const {
    // Your code here
    return "";  // Placeholder return
}

std::string Vehicle::getModel() const {
    // Your code here
    return "";  // Placeholder return
}

int Vehicle::getYear() const {
    // Your code here
    return 0;  // Placeholder return
}

double Vehicle::getPrice() const {
    // Your code here
    return 0.0;  // Placeholder return
}

// TODO: Implement displayInfo
// Display vehicle information including:
// - Make, model, year
// - Original price
// - Current value (from calculateValue)
void Vehicle::displayInfo() const {
    // Your code here
    // Hint: Use cout with appropriate formatting
}

// TODO: Implement calculateValue
// Calculate current value based on:
// - Original price
// - Age (current year - manufacturing year)
// - 15% depreciation per year
double Vehicle::calculateValue() const {
    // Your code here
    // Hint: Use std::pow for depreciation calculation
    return 0.0;  // Placeholder return
}
