#include <iostream>

using namespace std;

void demonstrateNullPointerSafety() {
    cout << "===== Null Pointer Safety =====" << endl;
    
    // TODO: Declare a pointer and initialize it to nullptr
    
    // TODO: Try to safely use the pointer (check if it's null before dereferencing)
    
    // TODO: Initialize the pointer with a valid address
    
    // TODO: Now safely use the pointer again
}

void demonstratePointerValidation() {
    cout << "\n===== Pointer Validation =====" << endl;
    
    // TODO: Declare an integer variable
    
    // TODO: Declare a pointer and initialize it with the address of the integer
    
    // TODO: Validate the pointer before using it
    
    // TODO: Set the pointer to null
    
    // TODO: Validate the pointer again before trying to use it
}

void demonstrateAvoidingDanglingPointers() {
    cout << "\n===== Avoiding Dangling Pointers =====" << endl;
    
    // TODO: Create a pointer to a dynamically allocated integer
    
    // TODO: Use the pointer
    
    // TODO: Delete the pointer (free the memory)
    
    // TODO: Set the pointer to nullptr to avoid a dangling pointer
    
    // TODO: Check if the pointer is null before trying to use it again
}

int main() {
    demonstrateNullPointerSafety();
    demonstratePointerValidation();
    demonstrateAvoidingDanglingPointers();
    
    return 0;
}
