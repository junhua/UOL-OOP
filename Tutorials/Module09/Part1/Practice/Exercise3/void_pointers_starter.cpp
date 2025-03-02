#include <iostream>

using namespace std;

void demonstrateVoidPointerWithInt() {
    cout << "===== Void Pointer with Integer =====" << endl;
    
    // TODO: Declare an integer variable with an initial value
    
    // TODO: Declare a void pointer
    
    // TODO: Assign the address of the integer to the void pointer
    
    // TODO: Print the value of the integer
    
    // TODO: Cast the void pointer to an integer pointer and modify the value
    
    // TODO: Print the new value of the integer
}

void demonstrateVoidPointerWithDouble() {
    cout << "\n===== Void Pointer with Double =====" << endl;
    
    // TODO: Declare a double variable with an initial value
    
    // TODO: Declare a void pointer
    
    // TODO: Assign the address of the double to the void pointer
    
    // TODO: Print the value of the double
    
    // TODO: Cast the void pointer to a double pointer and modify the value
    
    // TODO: Print the new value of the double
}

void demonstrateVoidPointerWithChar() {
    cout << "\n===== Void Pointer with Character =====" << endl;
    
    // TODO: Declare a character variable with an initial value
    
    // TODO: Declare a void pointer
    
    // TODO: Assign the address of the character to the void pointer
    
    // TODO: Print the value of the character
    
    // TODO: Cast the void pointer to a character pointer and modify the value
    
    // TODO: Print the new value of the character
}

// TODO: Create a generic print function that takes a void pointer and a type indicator
// The type indicator should be 'i' for int, 'd' for double, 'c' for char
void genericPrint(void* ptr, char type) {
    // TODO: Based on the type, cast the void pointer appropriately and print the value
}

void demonstrateGenericPrintFunction() {
    cout << "\n===== Generic Print Function =====" << endl;
    
    // TODO: Declare variables of different types
    
    // TODO: Call the generic print function for each variable
}

int main() {
    demonstrateVoidPointerWithInt();
    demonstrateVoidPointerWithDouble();
    demonstrateVoidPointerWithChar();
    demonstrateGenericPrintFunction();
    
    return 0;
}
