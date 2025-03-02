#include <iostream>
#include <vector>
#include <memory>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

// For C++11 compatibility (if make_unique is not available)
template<typename T, typename... Args>
std::unique_ptr<T> make_unique_ptr(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

/**
 * This program demonstrates polymorphism using a Shape hierarchy.
 * It creates a collection of different shapes and processes them
 * uniformly through their common base class interface.
 */
int main() {
    try {
        cout << "Polymorphism Demo" << endl;
        cout << string(50, '=') << endl;
        
        // Create a vector of unique_ptr<Shape> to store different shapes
        vector<unique_ptr<Shape>> shapes;
        
        // Add a Circle to the vector
        shapes.push_back(std::unique_ptr<Circle>(new Circle("Red", 3.0)));
        
        // Add a Rectangle to the vector
        shapes.push_back(std::unique_ptr<Rectangle>(new Rectangle("Blue", 4.0, 2.0)));
        
        // Process all shapes polymorphically
        cout << "\nProcessing shapes polymorphically:" << endl;
        cout << string(50, '-') << endl;
        
        for (const auto& shape : shapes) {
            // Display shape information
            shape->displayInfo();
            
            // Draw the shape
            shape->draw();
            
            // Print the area
            cout << "Area: " << shape->getArea() << endl;
            cout << string(30, '-') << endl;
        }
        
        cout << "\nDemonstrating object references:" << endl;
        cout << string(50, '-') << endl;
        
        // Create a Circle object
        Circle circle("Green", 2.0);
        
        // Create a Shape reference to the Circle
        Shape& shapeRef = circle;
        
        // Call displayInfo() on the reference (calls Circle's version)
        cout << "Calling displayInfo() through Shape reference:" << endl;
        shapeRef.displayInfo();
        
        // Note: We can't demonstrate object slicing with Shape because it's abstract
        // But we can explain the concept
        cout << "\nObject slicing would occur if we did:" << endl;
        cout << "Shape shape = circle;  // Error: Shape is abstract" << endl;
        cout << "But if Shape weren't abstract, the Circle part would be sliced off" << endl;
        
        cout << "\nDemonstrating virtual destructors:" << endl;
        cout << string(50, '-') << endl;
        
        // Create a Shape pointer to a new Circle
        Shape* shapePtr = new Circle("Yellow", 1.5);
        
        // Delete the pointer (calls both destructors)
        cout << "Deleting Shape pointer to Circle:" << endl;
        delete shapePtr;
        
        cout << "\nProgram completed successfully" << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
