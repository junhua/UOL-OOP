#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

int main() {
    cout << "Demonstrating Base and Derived Classes" << endl;
    cout << string(50, '=') << endl;
    
    // Create a vector to store vehicles
    vector<Vehicle*> vehicles;
    
    // Add different types of vehicles
    vehicles.push_back(new Car("Toyota", "Camry", 2020, 25000, 4, "Hybrid"));
    vehicles.push_back(new Car("Tesla", "Model 3", 2022, 45000, 4, "Electric"));
    vehicles.push_back(new Car("Honda", "Civic", 2019, 20000, 4, "Gasoline"));
    
    // Display information for all vehicles
    cout << "\nVehicle Information:" << endl;
    cout << string(50, '=') << endl;
    
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
        cout << string(50, '-') << endl;
    }
    
    // Demonstrate polymorphic behavior
    cout << "\nDemonstrating Polymorphism:" << endl;
    cout << string(50, '=') << endl;
    
    for (const auto& vehicle : vehicles) {
        cout << vehicle->getYear() << " " << vehicle->getMake() 
             << " " << vehicle->getModel() << endl;
        cout << "Current value: $" << fixed << setprecision(2) 
             << vehicle->calculateValue() << endl;
        cout << string(30, '-') << endl;
    }
    
    // Clean up
    cout << "\nCleaning up..." << endl;
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }
    vehicles.clear();
    
    cout << "\nProgram completed successfully" << endl;
    
    return 0;
}
