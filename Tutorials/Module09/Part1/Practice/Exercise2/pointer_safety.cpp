#include <iostream>

using namespace std;

void demonstrateNullPointerSafety() {
    cout << "===== Null Pointer Safety =====" << endl;
    
    // Declare a pointer and initialize it to nullptr
    int* ptr = nullptr;
    
    // Try to safely use the pointer (check if it's null before dereferencing)
    if (ptr != nullptr) {
        cout << "Value pointed to by ptr: " << *ptr << endl;
    } else {
        cout << "Pointer is null, cannot dereference" << endl;
    }
    
    // Initialize the pointer with a valid address
    int value = 42;
    ptr = &value;
    
    // Now safely use the pointer again
    cout << "After initialization:" << endl;
    if (ptr != nullptr) {
        cout << "Value pointed to by ptr: " << *ptr << endl;
    } else {
        cout << "Pointer is still null, cannot dereference" << endl;
    }
}

void demonstratePointerValidation() {
    cout << "\n===== Pointer Validation =====" << endl;
    
    // Declare an integer variable
    int number = 100;
    
    // Declare a pointer and initialize it with the address of the integer
    int* ptr = &number;
    
    // Validate the pointer before using it
    cout << "Checking pointer before use..." << endl;
    if (ptr != nullptr) {
        cout << "Pointer is valid, value: " << *ptr << endl;
    } else {
        cout << "Pointer is null, cannot access value" << endl;
    }
    
    // Set the pointer to null
    cout << "Setting pointer to null" << endl;
    ptr = nullptr;
    
    // Validate the pointer again before trying to use it
    cout << "Checking pointer before use..." << endl;
    if (ptr != nullptr) {
        cout << "Pointer is valid, value: " << *ptr << endl;
    } else {
        cout << "Pointer is null, cannot access value" << endl;
    }
}

void demonstrateAvoidingDanglingPointers() {
    cout << "\n===== Avoiding Dangling Pointers =====" << endl;
    
    // Create a pointer to a dynamically allocated integer
    int* ptr = new int(25);
    
    // Use the pointer
    cout << "Created dynamic integer with value: " << *ptr << endl;
    cout << "Using the pointer: " << *ptr << endl;
    
    // Delete the pointer (free the memory)
    cout << "Deleting the pointer" << endl;
    delete ptr;
    
    // Set the pointer to nullptr to avoid a dangling pointer
    cout << "Setting pointer to null after deletion" << endl;
    ptr = nullptr;
    
    // Check if the pointer is null before trying to use it again
    cout << "Checking if pointer is null: " << (ptr == nullptr ? "Yes" : "No") << endl;
    
    // Safe usage after deletion
    if (ptr != nullptr) {
        cout << "Using the pointer again: " << *ptr << endl;
    } else {
        // This code will execute since ptr is null
        // We avoid accessing deleted memory
    }
}

int main() {
    demonstrateNullPointerSafety();
    demonstratePointerValidation();
    demonstrateAvoidingDanglingPointers();
    
    return 0;
}
