#include "Car.h"

Car::Car(std::string make, std::string model, int year, double price,
         int doors, std::string fuel)
    : Vehicle(make, model, year, price),
      numDoors(doors), fuelType(fuel) {
    std::cout << "Creating car with " << doors << " doors" << std::endl;
}

Car::~Car() {
    std::cout << "Destroying car: " << getMake() << " " << getModel() << std::endl;
}

int Car::getNumDoors() const {
    return numDoors;
}

std::string Car::getFuelType() const {
    return fuelType;
}

void Car::displayInfo() const {
    Vehicle::displayInfo();  // Call base class method
    std::cout << "Type: Car" << std::endl;
    std::cout << "Number of Doors: " << numDoors << std::endl;
    std::cout << "Fuel Type: " << fuelType << std::endl;
}

double Car::calculateValue() const {
    double baseValue = Vehicle::calculateValue();  // Get base calculation
    
    // Adjust value based on fuel type
    if (fuelType == "Electric") {
        baseValue *= 1.1;  // 10% premium for electric
    } else if (fuelType == "Hybrid") {
        baseValue *= 1.05;  // 5% premium for hybrid
    }
    
    return baseValue;
}
