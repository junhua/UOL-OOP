#include "Pointer_starter.h"
#include <iostream>

using namespace std;

int main() {
    // Create a PointerDemo object
    PointerDemo demo;
    
    cout << "===== Basic Pointers =====" << endl;
    demo.demonstrateBasicPointers();
    
    cout << "\n===== Pointer Assignment =====" << endl;
    demo.demonstratePointerAssignment();
    
    cout << "\n===== Null Pointers =====" << endl;
    demo.demonstrateNullPointers();
    
    cout << "\n===== Void Pointers =====" << endl;
    demo.demonstrateVoidPointers();
    
    cout << "\n===== Pointers and Arrays =====" << endl;
    demo.demonstratePointersAndArrays();
    
    return 0;
}
