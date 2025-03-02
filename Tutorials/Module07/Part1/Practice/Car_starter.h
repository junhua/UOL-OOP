#ifndef CAR_H
#define CAR_H

#include "Vehicle_starter.h"

// TODO: Create Car class that inherits from Vehicle
class Car : public Vehicle {
private:
    // TODO: Add private member variables for:
    // - numDoors (int)
    // - fuelType (string)
    
public:
    // TODO: Implement constructor that initializes:
    // - All base class members (using Vehicle constructor)
    // - All Car specific members
    Car(std::string make, std::string model, int year, double price,
        int doors, std::string fuel);
    
    // TODO: Implement destructor
    ~Car() override;
    
    // TODO: Implement getters
    int getNumDoors() const;
    std::string getFuelType() const;
    
    // TODO: Override base class virtual methods
    // Remember to use 'override' keyword
    void displayInfo() const override;
    double calculateValue() const override;
    
    // Hints:
    // 1. Call base class displayInfo() before adding Car-specific info
    // 2. For calculateValue, apply fuel type adjustments:
    //    - Electric: +10% to base value
    //    - Hybrid: +5% to base value
};

#endif // CAR_H
