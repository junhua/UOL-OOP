#include <iostream>
#include <vector>
#include <iomanip>
#include "Shape_starter.h"

using namespace std;

/**
 * Practice Exercise: Shape Hierarchy
 * 
 * This program demonstrates proper "is-a" relationships in a shape hierarchy.
 * Complete the Shape_starter.h file, then use this main file to test your implementation.
 * 
 * Tasks:
 * 1. Implement the Shape base class with:
 *    - Protected color member
 *    - Pure virtual methods for area, perimeter, and drawing
 * 
 * 2. Implement the Circle class that inherits from Shape:
 *    - Add radius member
 *    - Override all virtual methods
 *    - Add circle-specific functionality
 * 
 * 3. Implement the Rectangle class that inherits from Shape:
 *    - Add width and height members
 *    - Override all virtual methods
 *    - Add rectangle-specific functionality
 * 
 * 4. Implement the Square class that inherits from Rectangle:
 *    - Ensure proper "is-a" relationship
 *    - Override necessary methods
 *    - Maintain LSP compliance
 */

int main() {
    cout << "Shape Hierarchy Demonstration" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Create a vector of Shape pointers
    
    // TODO: Add various shapes:
    // - Circle with radius 5
    // - Rectangle 4x6
    // - Square with side 3
    
    // TODO: Demonstrate polymorphism:
    // - Display each shape
    // - Calculate and show areas
    // - Calculate and show perimeters
    
    // TODO: Test specific shape features:
    // - Circle radius
    // - Rectangle dimensions
    // - Square side length
    
    // TODO: Clean up allocated memory
    
    return 0;
}
