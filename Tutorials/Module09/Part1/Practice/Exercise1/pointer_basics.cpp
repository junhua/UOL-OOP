#include <iostream>

using namespace std;

void demonstrateIntPointer() {
    cout << "===== Integer Pointer =====" << endl;
    
    // Declare an integer variable with an initial value
    int num = 42;
    
    // Declare a pointer to an integer
    int* ptr;
    
    // Assign the address of the integer to the pointer
    ptr = &num;
    
    // Print the value of the integer
    cout << "Value of num: " << num << endl;
    
    // Print the address of the integer
    cout << "Address of num: " << &num << endl;
    
    // Print the value of the pointer (which is an address)
    cout << "Value of ptr: " << ptr << endl;
    
    // Print the value pointed to by the pointer (dereferencing)
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    // Modify the value through the pointer
    *ptr = 100;
    
    // Print the new value of the integer
    cout << "After modification through pointer:" << endl;
    cout << "Value of num: " << num << endl;
}

void demonstrateDoublePointer() {
    cout << "\n===== Double Pointer =====" << endl;
    
    // Declare a double variable with an initial value
    double decimal = 3.14159;
    
    // Declare a pointer to a double
    double* doublePtr;
    
    // Assign the address of the double to the pointer
    doublePtr = &decimal;
    
    // Print the value of the double
    cout << "Value of decimal: " << decimal << endl;
    
    // Print the address of the double
    cout << "Address of decimal: " << &decimal << endl;
    
    // Print the value of the pointer
    cout << "Value of doublePtr: " << doublePtr << endl;
    
    // Print the value pointed to by the pointer
    cout << "Value pointed to by doublePtr: " << *doublePtr << endl;
    
    // Modify the value through the pointer
    *doublePtr = 2.71828;
    
    // Print the new value of the double
    cout << "After modification through pointer:" << endl;
    cout << "Value of decimal: " << decimal << endl;
}

void demonstrateCharPointer() {
    cout << "\n===== Character Pointer =====" << endl;
    
    // Declare a character variable with an initial value
    char letter = 'A';
    
    // Declare a pointer to a character
    char* charPtr;
    
    // Assign the address of the character to the pointer
    charPtr = &letter;
    
    // Print the value of the character
    cout << "Value of letter: " << letter << endl;
    
    // Print the address of the character
    cout << "Address of letter: " << static_cast<void*>(&letter) << endl;
    
    // Print the value of the pointer
    cout << "Value of charPtr: " << static_cast<void*>(charPtr) << endl;
    
    // Print the value pointed to by the pointer
    cout << "Value pointed to by charPtr: " << *charPtr << endl;
    
    // Modify the value through the pointer
    *charPtr = 'Z';
    
    // Print the new value of the character
    cout << "After modification through pointer:" << endl;
    cout << "Value of letter: " << letter << endl;
}

int main() {
    demonstrateIntPointer();
    demonstrateDoublePointer();
    demonstrateCharPointer();
    
    return 0;
}
