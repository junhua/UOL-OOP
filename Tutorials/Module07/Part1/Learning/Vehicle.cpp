#include "Vehicle.h"

Vehicle::Vehicle(std::string make, std::string model, int year, double price)
    : make(make), model(model), year(year), price(price) {
    std::cout << "Creating vehicle: " << year << " " << make << " " << model << std::endl;
}

Vehicle::~Vehicle() {
    std::cout << "Destroying vehicle: " << year << " " << make << " " << model << std::endl;
}

std::string Vehicle::getMake() const { 
    return make; 
}

std::string Vehicle::getModel() const { 
    return model; 
}

int Vehicle::getYear() const { 
    return year; 
}

double Vehicle::getPrice() const { 
    return price; 
}

void Vehicle::displayInfo() const {
    std::cout << "\nVehicle Information:" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Make: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Original Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
    std::cout << "Current Value: $" << calculateValue() << std::endl;
}

double Vehicle::calculateValue() const {
    int age = 2024 - year;
    return price * std::pow(0.85, age);  // 15% depreciation per year
}
