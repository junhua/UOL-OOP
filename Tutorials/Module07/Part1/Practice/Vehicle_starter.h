#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class Vehicle {
protected:
    // TODO: Add protected member variables for:
    // - make (string)
    // - model (string)
    // - year (int)
    // - price (double)
    
public:
    // TODO: Implement constructor
    Vehicle(std::string make, std::string model, int year, double price);
    
    // TODO: Implement virtual destructor
    virtual ~Vehicle();
    
    // TODO: Implement getters
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    double getPrice() const;
    
    // TODO: Implement virtual methods
    virtual void displayInfo() const;
    virtual double calculateValue() const;
};

#endif // VEHICLE_H
