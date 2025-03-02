#include <iostream>

using namespace std;

void demonstrateVoidPointerWithInt() {
    cout << "===== Void Pointer with Integer =====" << endl;
    
    // Declare an integer variable with an initial value
    int num = 42;
    
    // Declare a void pointer
    void* voidPtr;
    
    // Assign the address of the integer to the void pointer
    voidPtr = &num;
    
    // Print the value of the integer
    cout << "Integer value: " << num << endl;
    
    // Cast the void pointer to an integer pointer and modify the value
    *static_cast<int*>(voidPtr) = 100;
    
    // Print the new value of the integer
    cout << "After modification through void pointer:" << endl;
    cout << "Integer value: " << num << endl;
}

void demonstrateVoidPointerWithDouble() {
    cout << "\n===== Void Pointer with Double =====" << endl;
    
    // Declare a double variable with an initial value
    double decimal = 3.14159;
    
    // Declare a void pointer
    void* voidPtr;
    
    // Assign the address of the double to the void pointer
    voidPtr = &decimal;
    
    // Print the value of the double
    cout << "Double value: " << decimal << endl;
    
    // Cast the void pointer to a double pointer and modify the value
    *static_cast<double*>(voidPtr) = 2.71828;
    
    // Print the new value of the double
    cout << "After modification through void pointer:" << endl;
    cout << "Double value: " << decimal << endl;
}

void demonstrateVoidPointerWithChar() {
    cout << "\n===== Void Pointer with Character =====" << endl;
    
    // Declare a character variable with an initial value
    char letter = 'A';
    
    // Declare a void pointer
    void* voidPtr;
    
    // Assign the address of the character to the void pointer
    voidPtr = &letter;
    
    // Print the value of the character
    cout << "Character value: " << letter << endl;
    
    // Cast the void pointer to a character pointer and modify the value
    *static_cast<char*>(voidPtr) = 'Z';
    
    // Print the new value of the character
    cout << "After modification through void pointer:" << endl;
    cout << "Character value: " << letter << endl;
}

// Create a generic print function that takes a void pointer and a type indicator
// The type indicator is 'i' for int, 'd' for double, 'c' for char
void genericPrint(void* ptr, char type) {
    // Based on the type, cast the void pointer appropriately and print the value
    switch (type) {
        case 'i':
            cout << "Integer: " << *static_cast<int*>(ptr) << endl;
            break;
        case 'd':
            cout << "Double: " << *static_cast<double*>(ptr) << endl;
            break;
        case 'c':
            cout << "Character: " << *static_cast<char*>(ptr) << endl;
            break;
        default:
            cout << "Unknown type" << endl;
    }
}

void demonstrateGenericPrintFunction() {
    cout << "\n===== Generic Print Function =====" << endl;
    
    // Declare variables of different types
    int intValue = 100;
    double doubleValue = 2.71828;
    char charValue = 'Z';
    
    // Call the generic print function for each variable
    genericPrint(&intValue, 'i');
    genericPrint(&doubleValue, 'd');
    genericPrint(&charValue, 'c');
}

int main() {
    demonstrateVoidPointerWithInt();
    demonstrateVoidPointerWithDouble();
    demonstrateVoidPointerWithChar();
    demonstrateGenericPrintFunction();
    
    return 0;
}
