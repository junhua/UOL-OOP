#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;
    double price;
    
public:
    // Constructor
    Vehicle(std::string make, std::string model, int year, double price);
    
    // Virtual destructor
    virtual ~Vehicle();
    
    // Getters
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    double getPrice() const;
    
    // Virtual methods
    virtual void displayInfo() const;
    virtual double calculateValue() const;
};

#endif // VEHICLE_H
