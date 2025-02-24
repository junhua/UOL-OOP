#include <iostream>
#include <string>
using namespace std;

// Global variables
int globalCounter = 0;
const double PI = 3.14159;

// Global function to demonstrate global variable access
void incrementGlobalCounter() {
    globalCounter++;
    cout << "Global counter is now: " << globalCounter << endl;
}

// Function demonstrating local scope
void demonstrateLocalScope() {
    int x = 10;  // Local to this function
    cout << "Inside function: x = " << x << endl;
    
    {  // New block scope
        int y = 20;  // Local to this block
        cout << "Inside block: x = " << x << ", y = " << y << endl;
        
        {  // Nested block
            int z = 30;  // Local to this nested block
            cout << "Inside nested block: x = " << x << ", y = " << y 
                 << ", z = " << z << endl;
        }
        // z is not accessible here
    }
    // y is not accessible here
}

// Function with static variable
void countFunctionCalls() {
    static int calls = 0;  // Initialized only once
    calls++;
    cout << "Function has been called " << calls << " times" << endl;
}

// Class demonstrating different scope types
class ScopeDemo {
private:
    int instanceVar;           // Instance scope
    static int instanceCount;  // Class scope
    
public:
    ScopeDemo(int value = 0) : instanceVar(value) {
        instanceCount++;
        cout << "Created instance " << instanceCount 
             << " with value " << instanceVar << endl;
    }
    
    ~ScopeDemo() {
        instanceCount--;
        cout << "Destroyed instance. " << instanceCount 
             << " instances remaining" << endl;
    }
    
    static int getInstanceCount() {
        return instanceCount;
    }
    
    void demonstrateScope() {
        int localVar = 100;  // Local to method
        cout << "Instance variable: " << instanceVar << endl;
        cout << "Local variable: " << localVar << endl;
        cout << "Total instances: " << instanceCount << endl;
    }
};

// Initialize static member
int ScopeDemo::instanceCount = 0;

// Function demonstrating name hiding
void demonstrateNameHiding() {
    int value = 100;
    cout << "Outer value: " << value << endl;
    
    {
        int value = 200;  // Hides outer value
        cout << "Inner value: " << value << endl;
    }
    
    cout << "Outer value again: " << value << endl;
}

int main() {
    cout << "=== Global Variable Demo ===" << endl;
    cout << "Initial global counter: " << globalCounter << endl;
    incrementGlobalCounter();
    incrementGlobalCounter();
    
    cout << "\n=== Local Scope Demo ===" << endl;
    demonstrateLocalScope();
    
    cout << "\n=== Static Variable Demo ===" << endl;
    for (int i = 0; i < 3; i++) {
        countFunctionCalls();
    }
    
    cout << "\n=== Class Scope Demo ===" << endl;
    cout << "Initial instances: " << ScopeDemo::getInstanceCount() << endl;
    
    {
        ScopeDemo demo1(10);
        demo1.demonstrateScope();
        
        {
            ScopeDemo demo2(20);
            demo2.demonstrateScope();
        }
        
        cout << "After inner block: " << ScopeDemo::getInstanceCount() 
             << " instances" << endl;
    }
    
    cout << "Final instances: " << ScopeDemo::getInstanceCount() << endl;
    
    cout << "\n=== Name Hiding Demo ===" << endl;
    demonstrateNameHiding();
    
    return 0;
}
