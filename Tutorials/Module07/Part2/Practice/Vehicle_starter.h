#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

// TODO: Implement the Vehicle base class
class Vehicle {
protected:
    // TODO: Add protected members for:
    // - make
    // - model
    // - year
    // - registrationNumber
    
public:
    // TODO: Implement constructor and virtual destructor
    
    // TODO: Add pure virtual methods for:
    // - start()
    // - stop()
    // - displayInfo()
    
    // TODO: Add getters for vehicle properties
};

// TODO: Implement the LandVehicle class that inherits from Vehicle
class LandVehicle {
protected:
    // TODO: Add protected members for:
    // - numWheels
    // - engineType
    
public:
    // TODO: Implement constructor and destructor
    
    // TODO: Override base class methods
    
    // TODO: Add LandVehicle-specific methods:
    // - park()
    // - honk()
};

// TODO: Implement the Car class that inherits from LandVehicle
class Car {
private:
    // TODO: Add members for:
    // - numDoors
    // - transmission
    // - fuelType
    
public:
    // TODO: Implement constructor and destructor
    
    // TODO: Override inherited methods
    
    // TODO: Add Car-specific methods:
    // - openTrunk()
    // - adjustAC()
};

// TODO: Implement the Motorcycle class that inherits from LandVehicle
class Motorcycle {
private:
    // TODO: Add members for:
    // - style (sport, cruiser, etc.)
    // - hasSidecar
    
public:
    // TODO: Implement constructor and destructor
    
    // TODO: Override inherited methods
    
    // TODO: Add Motorcycle-specific methods:
    // - leanIntoTurn()
    // - deployStand()
};

#endif // VEHICLE_H
