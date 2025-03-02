#include "Buffer.h"
#include <iostream>
#include <vector>
using namespace std;

void demonstrateConstructors() {
    cout << "\n1. Constructor Demonstration" << endl;
    cout << "==========================" << endl;
    
    // Size constructor
    Buffer b1(5);
    cout << "b1: " << b1 << endl;
    
    // Data constructor
    int data[] = {1, 2, 3, 4};
    Buffer b2(data, 4);
    cout << "b2: " << b2 << endl;
    
    // Copy constructor
    Buffer b3(b2);
    cout << "b3 (copy of b2): " << b3 << endl;
    
    // Move constructor
    Buffer b4(std::move(b3));
    cout << "b4 (moved from b3): " << b4 << endl;
    cout << "b3 (after move): " << b3 << endl;
}

void demonstrateAssignment() {
    cout << "\n2. Assignment Demonstration" << endl;
    cout << "=========================" << endl;
    
    Buffer b1(3);
    b1.fill(1);
    cout << "b1: " << b1 << endl;
    
    Buffer b2(2);
    b2.fill(2);
    cout << "b2: " << b2 << endl;
    
    // Copy assignment
    b2 = b1;
    cout << "b2 after copy from b1: " << b2 << endl;
    
    // Move assignment
    Buffer b3(5);
    b3.fill(3);
    cout << "b3 before move: " << b3 << endl;
    
    b1 = std::move(b3);
    cout << "b1 after move from b3: " << b1 << endl;
    cout << "b3 after move: " << b3 << endl;
}

void demonstrateOperations() {
    cout << "\n3. Buffer Operations" << endl;
    cout << "===================" << endl;
    
    Buffer buf(4);
    
    // Set values
    for (size_t i = 0; i < buf.getSize(); ++i) {
        buf.set(i, i * 2);
    }
    cout << "After setting values: " << buf << endl;
    
    // Get values
    cout << "Values: ";
    for (size_t i = 0; i < buf.getSize(); ++i) {
        cout << buf.get(i) << " ";
    }
    cout << endl;
    
    // Fill
    buf.fill(42);
    cout << "After fill(42): " << buf << endl;
    
    // Resize
    buf.resize(6);
    cout << "After resize(6): " << buf << endl;
    
    buf.resize(2);
    cout << "After resize(2): " << buf << endl;
}

void demonstrateErrorHandling() {
    cout << "\n4. Error Handling" << endl;
    cout << "=================" << endl;
    
    Buffer buf(3);
    
    try {
        cout << "Attempting out-of-bounds access..." << endl;
        buf.get(5);
    } catch (const out_of_range& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    try {
        cout << "Attempting invalid set..." << endl;
        buf.set(10, 42);
    } catch (const out_of_range& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    try {
        cout << "Attempting very large allocation..." << endl;
        Buffer large(size_t(-1));  // Try to allocate maximum size_t
    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

void demonstrateRAII() {
    cout << "\n5. RAII Demonstration" << endl;
    cout << "====================" << endl;
    
    try {
        cout << "Entering nested scope" << endl;
        {
            Buffer b1(3);
            b1.fill(1);
            cout << "Created b1: " << b1 << endl;
            
            throw runtime_error("Simulated error");
            
            // This code won't execute
            Buffer b2(2);
            b2.fill(2);
        }
    } catch (const runtime_error& e) {
        cout << "Caught error: " << e.what() << endl;
        cout << "Buffer was automatically cleaned up" << endl;
    }
}

int main() {
    cout << "Buffer Class Demonstration" << endl;
    cout << "========================" << endl;
    
    try {
        demonstrateConstructors();
        demonstrateAssignment();
        demonstrateOperations();
        demonstrateErrorHandling();
        demonstrateRAII();
        
        cout << "\nAll demonstrations completed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    cout << "\nProgram ending - watch for destructor calls" << endl;
    return 0;
}
