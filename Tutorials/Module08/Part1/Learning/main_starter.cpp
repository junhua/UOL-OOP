#include <iostream>
#include <vector>
#include <memory>
#include "Shape_starter.h"
#include "Circle_starter.h"
#include "Rectangle_starter.h"

using namespace std;

/**
 * This program demonstrates polymorphism using a Shape hierarchy.
 * It creates a collection of different shapes and processes them
 * uniformly through their common base class interface.
 */
int main() {
    try {
        cout << "Polymorphism Demo" << endl;
        cout << string(50, '=') << endl;
        
        // TODO: Create a vector of unique_ptr<Shape> to store different shapes
        
        // TODO: Add a Circle to the vector (use make_unique)
        
        // TODO: Add a Rectangle to the vector (use make_unique)
        
        // TODO: Process all shapes polymorphically
        // For each shape in the vector:
        //   - Display its information
        //   - Draw it
        //   - Print its area
        
        cout << "\nDemonstrating object slicing:" << endl;
        cout << string(50, '-') << endl;
        
        // TODO: Create a Circle object
        
        // TODO: Create a Shape reference to the Circle
        
        // TODO: Call displayInfo() on the reference (should call Circle's version)
        
        // TODO: Attempt to slice the object (assign Circle to a Shape variable)
        // Note: This won't compile because Shape is abstract, but if it weren't,
        // it would demonstrate object slicing
        
        cout << "\nDemonstrating virtual destructors:" << endl;
        cout << string(50, '-') << endl;
        
        // TODO: Create a Shape pointer to a new Circle
        
        // TODO: Delete the pointer (should call both destructors)
        
        cout << "\nProgram completed successfully" << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
