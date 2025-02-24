#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===== Step 1: Value Parameters =====
// TODO: Declare these value parameter functions:
// 1. void modifyValue(int num)
//    - Attempts to modify a value parameter

// 2. void modifyArray(int arr[], int size)
//    - Modifies elements in an array

// 3. void modifyString(string text)
//    - Attempts to modify a string parameter


// ===== Step 2: Reference Parameters =====
// TODO: Declare these reference parameter functions:
// 1. void modifyByReference(int& num)
//    - Modifies a value through reference

// 2. void getMinMax(const vector<int>& numbers, int& min, int& max)
//    - Finds minimum and maximum values in a vector

// 3. void swapValues(int& a, int& b)
//    - Swaps two values using references


// ===== Step 3: Const Parameters =====
// TODO: Declare these const parameter functions:
// 1. double calculateAverage(const vector<int>& numbers)
//    - Calculates average of numbers without modifying them

// 2. void printDetails(const string& name, const int& age)
//    - Prints name and age without modifying them

// 3. bool searchValue(const int arr[], int size, int target)
//    - Searches for a value in an array without modifying it


int main() {
    // Test Step 1: Value Parameters
    cout << "===== Testing Value Parameters =====" << endl;
    // TODO: Test modifyValue with a number
    
    // TODO: Test modifyArray with an array
    
    // TODO: Test modifyString with a string
    cout << endl;
    
    // Test Step 2: Reference Parameters
    cout << "===== Testing Reference Parameters =====" << endl;
    // TODO: Test modifyByReference with a number
    
    // TODO: Test getMinMax with a vector of numbers
    
    // TODO: Test swapValues with two numbers
    cout << endl;
    
    // Test Step 3: Const Parameters
    cout << "===== Testing Const Parameters =====" << endl;
    // TODO: Test calculateAverage with a vector
    
    // TODO: Test printDetails with name and age
    
    // TODO: Test searchValue with an array and target
    
    return 0;
}

// ===== Step 1: Value Parameters Implementation =====
// TODO: Implement modifyValue
// Function: modifyValue
// Purpose: Demonstrates that value parameters create a copy
// Parameters: num - integer to modify
// Returns: void

// TODO: Implement modifyArray
// Function: modifyArray
// Purpose: Shows that arrays are passed by reference
// Parameters: arr - array to modify
//            size - size of array
// Returns: void

// TODO: Implement modifyString
// Function: modifyString
// Purpose: Shows that strings are passed by value
// Parameters: text - string to modify
// Returns: void

// ===== Step 2: Reference Parameters Implementation =====
// TODO: Implement modifyByReference
// Function: modifyByReference
// Purpose: Demonstrates reference parameter modification
// Parameters: num - reference to integer to modify
// Returns: void

// TODO: Implement getMinMax
// Function: getMinMax
// Purpose: Finds minimum and maximum values in vector
// Parameters: numbers - vector to search
//            min - reference to store minimum
//            max - reference to store maximum
// Returns: void

// TODO: Implement swapValues
// Function: swapValues
// Purpose: Swaps two values using references
// Parameters: a, b - references to values to swap
// Returns: void

// ===== Step 3: Const Parameters Implementation =====
// TODO: Implement calculateAverage
// Function: calculateAverage
// Purpose: Calculates average of vector values
// Parameters: numbers - const reference to vector
// Returns: double - the calculated average

// TODO: Implement printDetails
// Function: printDetails
// Purpose: Prints name and age details
// Parameters: name - const reference to name string
//            age - const reference to age
// Returns: void

// TODO: Implement searchValue
// Function: searchValue
// Purpose: Searches for value in array
// Parameters: arr - const array to search
//            size - size of array
//            target - value to find
// Returns: bool - true if found, false otherwise
