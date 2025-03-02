#include "Time.h"
#include <iostream>
using namespace std;

void demonstrateTimeOperations() {
    cout << "Time Class Demonstration" << endl;
    cout << "======================" << endl;
    
    // Creating time objects
    cout << "\n1. Creating Time Objects:" << endl;
    cout << "------------------------" << endl;
    
    Time t1;  // Default constructor (00:00:00)
    cout << "t1 (default): ";
    t1.display();
    
    Time t2(14, 30, 45);  // Parameterized constructor
    cout << "t2 (14:30:45): ";
    t2.display();
    
    // Time validation
    cout << "\n2. Time Validation:" << endl;
    cout << "-------------------" << endl;
    try {
        Time invalid(25, 0, 0);  // Invalid hours
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    try {
        Time invalid(12, 60, 0);  // Invalid minutes
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Time manipulation
    cout << "\n3. Time Manipulation:" << endl;
    cout << "--------------------" << endl;
    
    Time t3(23, 45, 30);
    cout << "Original time: ";
    t3.display();
    
    t3.addSeconds(40);
    cout << "After adding 40 seconds: ";
    t3.display();
    
    t3.addMinutes(20);
    cout << "After adding 20 minutes: ";
    t3.display();
    
    t3.addHours(3);
    cout << "After adding 3 hours: ";
    t3.display();
    
    // Time comparison
    cout << "\n4. Time Comparison:" << endl;
    cout << "------------------" << endl;
    
    Time t4(10, 20, 30);
    Time t5(10, 20, 30);
    Time t6(14, 30, 0);
    
    cout << "t4: ";
    t4.display();
    cout << "t5: ";
    t5.display();
    cout << "t6: ";
    t6.display();
    
    cout << "t4 equals t5: " << (t4.equals(t5) ? "Yes" : "No") << endl;
    cout << "t4 before t6: " << (t4.isBefore(t6) ? "Yes" : "No") << endl;
    cout << "t6 after t4: " << (t6.isAfter(t4) ? "Yes" : "No") << endl;
    
    // Error handling
    cout << "\n5. Error Handling:" << endl;
    cout << "-----------------" << endl;
    
    try {
        t4.addSeconds(-10);  // Negative seconds
    } catch (const invalid_argument& e) {
        cout << "Error adding negative seconds: " << e.what() << endl;
    }
    
    try {
        t4.setTime(12, 70, 30);  // Invalid minutes
    } catch (const invalid_argument& e) {
        cout << "Error setting invalid time: " << e.what() << endl;
    }
}

int main() {
    try {
        demonstrateTimeOperations();
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
