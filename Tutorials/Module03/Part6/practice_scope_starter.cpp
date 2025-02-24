#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Exercise 1: Function Counter System
namespace CounterSystem {
    // TODO: Create static counter variable
    
    // TODO: Implement resetCounter function
    
    // TODO: Implement incrementCounter function
    
    // TODO: Implement getCurrentCount function
    
    // TODO: Implement displayCount function
}

// Exercise 2: Temperature Tracker
class TemperatureTracker {
private:
    // TODO: Declare static member variables
    // - Vector for temperatures
    // - Highest temperature
    // - Lowest temperature
    // - Total temperature
    // - Reading count
    
public:
    // TODO: Implement addReading function
    // - Update highest/lowest
    // - Add to vector
    // - Update total and count
    
    // TODO: Implement reset function
    // - Clear all data
    // - Reset statistics
    
    // TODO: Implement getter functions
    // - Highest temperature
    // - Lowest temperature
    // - Average temperature
    // - Reading count
    
    // TODO: Implement displayStats function
    // - Show all statistics
    // - Handle empty case
};

// TODO: Initialize static members

// Exercise 3: Resource Manager
namespace ResourceManager {
    // TODO: Define maximum resources constant
    // TODO: Create static resource counter
    
    // TODO: Implement isResourceAvailable function
    
    // TODO: Implement allocateResource function
    // - Check availability
    // - Increment counter
    // - Handle errors
    
    // TODO: Implement releaseResource function
    // - Check if resources exist
    // - Decrement counter
    // - Handle errors
    
    // TODO: Implement getActiveResources function
}

int main() {
    try {
        // Test Function Counter System
        cout << "=== Function Counter System ===" << endl;
        // TODO: Test counter functions
        // - Display initial count
        // - Increment counter
        // - Display updated count
        // - Reset counter
        // - Verify reset
        
        // Test Temperature Tracker
        cout << "\n=== Temperature Tracker ===" << endl;
        // TODO: Test temperature tracking
        // - Add several readings
        // - Display statistics
        // - Reset tracker
        // - Verify reset
        
        // Test Resource Manager
        cout << "\n=== Resource Manager ===" << endl;
        // TODO: Test resource management
        // - Check initial state
        // - Allocate resources
        // - Test maximum allocation
        // - Release resources
        // - Test empty state
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
    
    return 0;
}
