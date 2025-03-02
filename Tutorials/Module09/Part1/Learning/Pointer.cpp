#include "Pointer.h"
#include <iostream>

using namespace std;

void PointerDemo::demonstrateBasicPointers() {
    // Declare an integer variable
    int number = 42;
    
    // Declare a pointer to an integer
    int* ptr;
    
    // Assign the address of the integer to the pointer
    ptr = &number;
    
    // Print the value of the integer
    cout << "Value of number: " << number << endl;
    
    // Print the address of the integer
    cout << "Address of number: " << &number << endl;
    
    // Print the value of the pointer (which is an address)
    cout << "Value of ptr: " << ptr << endl;
    
    // Print the value pointed to by the pointer (dereferencing)
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    // Modify the value through the pointer
    *ptr = 100;
    
    // Print the new value of the integer
    cout << "New value of number: " << number << endl;
    cout << "New value pointed to by ptr: " << *ptr << endl;
}

void PointerDemo::demonstratePointerAssignment() {
    // Declare two integer variables
    int num1 = 10;
    int num2 = 20;
    
    // Declare two pointers to integers
    int* ptr1;
    int* ptr2;
    
    // Assign addresses to pointers
    ptr1 = &num1;
    ptr2 = &num2;
    
    // Print values and addresses
    cout << "num1 = " << num1 << ", address: " << &num1 << endl;
    cout << "num2 = " << num2 << ", address: " << &num2 << endl;
    cout << "ptr1 = " << ptr1 << ", points to: " << *ptr1 << endl;
    cout << "ptr2 = " << ptr2 << ", points to: " << *ptr2 << endl;
    
    // Assign one pointer to another
    ptr1 = ptr2;
    
    // Modify a value through the second pointer
    *ptr1 = 30;
    
    // Print the new values
    cout << "\nAfter assignment and modification:" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "ptr1 = " << ptr1 << ", points to: " << *ptr1 << endl;
    cout << "ptr2 = " << ptr2 << ", points to: " << *ptr2 << endl;
    
    // Compare pointers
    if (ptr1 == ptr2) {
        cout << "\nptr1 and ptr2 point to the same memory location" << endl;
    } else {
        cout << "\nptr1 and ptr2 point to different memory locations" << endl;
    }
}

void PointerDemo::demonstrateNullPointers() {
    // Declare a null pointer
    int* ptr = nullptr;
    
    // Check if pointer is null
    if (ptr == nullptr) {
        cout << "ptr is a null pointer" << endl;
    }
    
    // Safe usage with null check
    cout << "Attempting to use pointer safely:" << endl;
    if (ptr != nullptr) {
        cout << "Value pointed to by ptr: " << *ptr << endl;
    } else {
        cout << "Cannot dereference a null pointer" << endl;
    }
    
    // Initialize pointer with a valid address
    int number = 42;
    ptr = &number;
    
    // Check again if pointer is null
    if (ptr == nullptr) {
        cout << "ptr is a null pointer" << endl;
    } else {
        cout << "ptr is not null, it points to: " << *ptr << endl;
    }
}

void PointerDemo::demonstrateVoidPointers() {
    // Declare variables of different types
    int intValue = 42;
    double doubleValue = 3.14159;
    char charValue = 'A';
    
    // Declare a void pointer
    void* voidPtr;
    
    // Assign address of integer to void pointer
    voidPtr = &intValue;
    
    // Cast void pointer back to integer pointer and dereference
    cout << "Integer value: " << *(static_cast<int*>(voidPtr)) << endl;
    
    // Assign address of double to the same void pointer
    voidPtr = &doubleValue;
    
    // Cast void pointer to double pointer and dereference
    cout << "Double value: " << *(static_cast<double*>(voidPtr)) << endl;
    
    // Assign address of character to void pointer
    voidPtr = &charValue;
    
    // Cast void pointer to character pointer and dereference
    cout << "Character value: " << *(static_cast<char*>(voidPtr)) << endl;
}

void PointerDemo::demonstratePointersAndArrays() {
    // Declare an array
    int numbers[5] = {10, 20, 30, 40, 50};
    
    // Declare a pointer to the array
    int* ptr = numbers;  // No & needed - array name decays to pointer
    
    // Print array elements using array notation
    cout << "Array elements using array notation:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }
    
    // Print array elements using pointer notation
    cout << "\nArray elements using pointer notation:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(ptr + " << i << ") = " << *(ptr + i) << endl;
    }
    
    // Increment pointer to access different elements
    cout << "\nAccessing elements by incrementing pointer:" << endl;
    ptr = numbers;  // Reset pointer to start of array
    cout << "*ptr = " << *ptr << endl;
    
    ptr++;  // Move to next element
    cout << "*ptr after ptr++ = " << *ptr << endl;
    
    ptr += 2;  // Move forward by 2 elements
    cout << "*ptr after ptr += 2 = " << *ptr << endl;
    
    // Print array address and first element address
    cout << "\nArray address: " << numbers << endl;
    cout << "Address of first element: " << &numbers[0] << endl;
    
    // Demonstrate array decay to pointer
    cout << "\nDemonstrating array decay:" << endl;
    cout << "Size of numbers array: " << sizeof(numbers) << " bytes" << endl;
    cout << "Size of ptr: " << sizeof(ptr) << " bytes" << endl;
}
