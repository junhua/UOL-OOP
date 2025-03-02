#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int numDoors;
    std::string fuelType;
    
public:
    // Constructor
    Car(std::string make, std::string model, int year, double price,
        int doors, std::string fuel);
    
    // Destructor
    ~Car() override;
    
    // Additional getters
    int getNumDoors() const;
    std::string getFuelType() const;
    
    // Override base class methods
    void displayInfo() const override;
    double calculateValue() const override;
};

#endif // CAR_H
