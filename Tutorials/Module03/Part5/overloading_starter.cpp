#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <algorithm>
using namespace std;

// TODO: Implement basic function overloading
// Add functions for int, double, and string

// TODO: Implement print function overloading
// Print functions for different parameter combinations

// TODO: Create Point class with overloaded methods
class Point {
public:
    int x, y;
    
    // TODO: Implement constructor overloading
    // Default constructor
    // Single parameter constructor
    // Two parameter constructor
    
    // TODO: Implement method overloading
    // move with dx, dy
    // move with another Point
    // move with single distance
    
    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

// TODO: Implement function overloading with const
// updateValue for modifying the original
// updateValue for storing in a result variable

int main() {
    // Test basic overloading
    cout << "=== Basic Function Overloading ===" << endl;
    // TODO: Test add functions with different types
    
    cout << "\n=== Print Function Overloading ===" << endl;
    // TODO: Test print functions with different parameters
    
    cout << "\n=== Point Class Overloading ===" << endl;
    // TODO: Test Point constructors and move methods
    
    cout << "\n=== Const Overloading ===" << endl;
    // TODO: Test updateValue functions
    
    return 0;
}
