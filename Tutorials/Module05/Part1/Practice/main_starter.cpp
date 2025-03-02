#include "Time_starter.h"
#include <iostream>
#include <cassert>
using namespace std;

// Test function declarations
void testConstructors();
void testSettersAndGetters();
void testTimeManipulation();
void testComparisons();
void testErrorHandling();

int main() {
    cout << "Testing Time Class Implementation" << endl;
    cout << "===============================" << endl;
    
    try {
        testConstructors();
        cout << "\nConstructor tests passed!" << endl;
        
        testSettersAndGetters();
        cout << "Setter and getter tests passed!" << endl;
        
        testTimeManipulation();
        cout << "Time manipulation tests passed!" << endl;
        
        testComparisons();
        cout << "Comparison tests passed!" << endl;
        
        testErrorHandling();
        cout << "Error handling tests passed!" << endl;
        
        cout << "\nAll tests passed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

void testConstructors() {
    // Test default constructor
    Time t1;
    assert(t1.getHours() == 0 && t1.getMinutes() == 0 && t1.getSeconds() == 0);
    cout << "Default constructor: ";
    t1.display();
    
    // Test parameterized constructor
    Time t2(14, 30, 45);
    assert(t2.getHours() == 14 && t2.getMinutes() == 30 && t2.getSeconds() == 45);
    cout << "Parameterized constructor: ";
    t2.display();
}

void testSettersAndGetters() {
    Time t;
    t.setTime(12, 30, 45);
    
    assert(t.getHours() == 12);
    assert(t.getMinutes() == 30);
    assert(t.getSeconds() == 45);
    
    cout << "Time after setTime: ";
    t.display();
}

void testTimeManipulation() {
    Time t(23, 59, 45);
    cout << "Original time: ";
    t.display();
    
    t.addSeconds(20);
    assert(t.getSeconds() == 5);
    assert(t.getMinutes() == 0);
    assert(t.getHours() == 0);
    cout << "After adding 20 seconds: ";
    t.display();
    
    t.addMinutes(65);
    assert(t.getHours() == 1);
    assert(t.getMinutes() == 5);
    cout << "After adding 65 minutes: ";
    t.display();
    
    t.addHours(23);
    assert(t.getHours() == 0);
    cout << "After adding 23 hours: ";
    t.display();
}

void testComparisons() {
    Time t1(10, 20, 30);
    Time t2(10, 20, 30);
    Time t3(15, 30, 0);
    
    assert(t1.equals(t2));
    assert(!t1.equals(t3));
    assert(t1.isBefore(t3));
    assert(t3.isAfter(t1));
    
    cout << "t1: ";
    t1.display();
    cout << "t2: ";
    t2.display();
    cout << "t3: ";
    t3.display();
}

void testErrorHandling() {
    // Test invalid hours
    try {
        Time t(24, 0, 0);
        assert(false);  // Should not reach here
    } catch (const invalid_argument&) {
        cout << "Successfully caught invalid hours" << endl;
    }
    
    // Test invalid minutes
    try {
        Time t(12, 60, 0);
        assert(false);  // Should not reach here
    } catch (const invalid_argument&) {
        cout << "Successfully caught invalid minutes" << endl;
    }
    
    // Test invalid seconds
    try {
        Time t(12, 30, 60);
        assert(false);  // Should not reach here
    } catch (const invalid_argument&) {
        cout << "Successfully caught invalid seconds" << endl;
    }
    
    // Test negative time values
    try {
        Time t(12, 30, 45);
        t.addSeconds(-1);
        assert(false);  // Should not reach here
    } catch (const invalid_argument&) {
        cout << "Successfully caught negative seconds" << endl;
    }
}
