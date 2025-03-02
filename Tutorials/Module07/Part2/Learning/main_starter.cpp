#include <iostream>
#include <vector>
#include "Shape_starter.h"
#include "Circle_starter.h"

using namespace std;

/**
 * This program demonstrates the "is-a" relationship between Shape and Circle.
 * Complete the Shape_starter and Circle_starter files, then use this program to test.
 * 
 * Tasks:
 * 1. Implement Shape base class:
 *    - Add color member
 *    - Create constructor and destructor
 *    - Define pure virtual methods
 * 
 * 2. Implement Circle derived class:
 *    - Add radius member
 *    - Create constructor and destructor
 *    - Override virtual methods
 *    - Add circle-specific methods
 */

int main() {
    cout << "Demonstrating \"is-a\" Relationship" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Create a vector of Shape pointers
    
    // TODO: Add circles with different colors and sizes:
    // - Red circle with radius 5
    // - Blue circle with radius 3
    // - Green circle with radius 4
    
    // TODO: Demonstrate polymorphic behavior:
    // - Draw each shape
    // - Calculate and display areas
    
    // TODO: Clean up allocated memory
    
    cout << "\nDemonstrating direct Circle usage:" << endl;
    cout << string(50, '=') << endl;
    
    // TODO: Create a Circle directly
    // - Use purple color and radius 2
    
    // TODO: Test Circle methods:
    // - Get and display radius
    // - Draw the circle
    // - Calculate and display area
    
    cout << "\nProgram completed successfully" << endl;
    
    return 0;
}
