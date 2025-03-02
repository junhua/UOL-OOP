#ifndef CAR_H
#define CAR_H

#include "Vehicle_starter.h"

// TODO: Implement the Car class that inherits from Vehicle
class Car {
private:
    // TODO: Add private members for:
    // - numDoors (int)
    // - fuelType (string)
    
public:
    // TODO: Implement constructor
    // Parameters:
    // - All Vehicle parameters (make, model, year, price)
    // - doors: Number of doors
    // - fuel: Type of fuel (e.g., "Gasoline", "Electric", "Hybrid")
    // Expected behavior:
    // 1. Initialize Vehicle base class
    // 2. Initialize Car members
    // 3. Print creation message:
    //    "Creating car with [doors] doors"
    
    // TODO: Implement destructor
    // Expected behavior:
    // 1. Print destruction message:
    //    "Destroying car: [make] [model]"
    
    // TODO: Implement getters for:
    // - getNumDoors()
    // - getFuelType()
    
    // TODO: Override displayInfo()
    // Expected behavior:
    // 1. Call Vehicle's displayInfo()
    // 2. Add Car-specific info:
    //    Type: Car
    //    Number of Doors: [doors]
    //    Fuel Type: [fuelType]
    
    // TODO: Override calculateValue()
    // Algorithm:
    // 1. Get base value from Vehicle's calculateValue()
    // 2. Apply fuel type adjustments:
    //    - Electric: +10% (multiply by 1.1)
    //    - Hybrid: +5% (multiply by 1.05)
    //    - Others: no adjustment
    // 3. Return adjusted value
};

#endif // CAR_H
