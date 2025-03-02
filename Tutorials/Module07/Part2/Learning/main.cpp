#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"

using namespace std;

int main() {
    cout << "Demonstrating \"is-a\" Relationship" << endl;
    cout << string(50, '=') << endl;
    
    // Create a vector of Shape pointers to demonstrate polymorphism
    vector<Shape*> shapes;
    
    // Add circles with different colors and sizes
    shapes.push_back(new Circle("red", 5));
    shapes.push_back(new Circle("blue", 3));
    shapes.push_back(new Circle("green", 4));
    
    // Demonstrate polymorphic behavior
    cout << "\nShape Information:" << endl;
    cout << string(50, '=') << endl;
    
    for (const auto& shape : shapes) {
        // Use base class pointer to call derived class methods
        shape->draw();
        cout << "Area: " << shape->getArea() << endl;
        cout << string(50, '-') << endl;
    }
    
    // Clean up
    cout << "\nCleaning up..." << endl;
    for (auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();
    
    cout << "\nDemonstrating direct Circle usage:" << endl;
    cout << string(50, '=') << endl;
    
    // Create a Circle directly
    Circle circle("purple", 2);
    
    // Use Circle-specific method
    cout << "Radius: " << circle.getRadius() << endl;
    
    // Use inherited methods
    circle.draw();
    cout << "Area: " << circle.getArea() << endl;
    
    cout << "\nProgram completed successfully" << endl;
    
    return 0;
}
