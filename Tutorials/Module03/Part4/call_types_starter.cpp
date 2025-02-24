#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===== Step 1: Call by Value Examples =====
// TODO: Declare these value parameter functions:
// 1. void modifyValue(int num)
//    - Attempts to modify a value parameter

// 2. void processArray(int arr[], int size)
//    - Shows array parameter behavior

// 3. void modifyString(string text)
//    - Demonstrates string parameter behavior


// ===== Step 2: Call by Reference Examples =====
// TODO: Declare these reference parameter functions:
// 1. void modifyReference(int& num)
//    - Modifies a value through reference

// 2. void getMinMax(const vector<int>& numbers, int& min, int& max)
//    - Finds minimum and maximum values

// 3. void swapValues(int& a, int& b)
//    - Swaps two values using references


// ===== Step 3: Const Reference Examples =====
// TODO: Declare these const reference functions:
// 1. double calculateAverage(const vector<int>& numbers)
//    - Calculates average without modifying vector

// 2. void printDetails(const string& name, const int& age)
//    - Prints details without modifying parameters

// 3. bool searchValue(const int arr[], int size, int target)
//    - Searches array without modifying it


int main() {
    // Test Step 1: Call by Value
    cout << "===== Testing Call by Value =====" << endl;
    // TODO: Test modifyValue with a number
    
    // TODO: Test processArray with an array
    
    // TODO: Test modifyString with a string
    cout << endl;
    
    // Test Step 2: Call by Reference
    cout << "===== Testing Call by Reference =====" << endl;
    // TODO: Test modifyReference with a number
    
    // TODO: Test getMinMax with a vector
    
    // TODO: Test swapValues with two numbers
    cout << endl;
    
    // Test Step 3: Const Reference
    cout << "===== Testing Const Reference =====" << endl;
    // TODO: Test calculateAverage with a vector
    
    // TODO: Test printDetails with name and age
    
    // TODO: Test searchValue with an array
    
    return 0;
}

// ===== Step 1: Call by Value Implementations =====
// TODO: Implement modifyValue
// Function: modifyValue
// Purpose: Shows that value parameters create copies
// Parameters: num - integer to modify
// Returns: void

// TODO: Implement processArray
// Function: processArray
// Purpose: Shows array parameter behavior
// Parameters: arr - array to modify
//            size - size of array
// Returns: void

// TODO: Implement modifyString
// Function: modifyString
// Purpose: Shows string parameter behavior
// Parameters: text - string to modify
// Returns: void

// ===== Step 2: Call by Reference Implementations =====
// TODO: Implement modifyReference
// Function: modifyReference
// Purpose: Shows reference parameter modification
// Parameters: num - reference to integer
// Returns: void

// TODO: Implement getMinMax
// Function: getMinMax
// Purpose: Finds minimum and maximum values
// Parameters: numbers - vector to search
//            min - reference to store minimum
//            max - reference to store maximum
// Returns: void

// TODO: Implement swapValues
// Function: swapValues
// Purpose: Swaps two values using references
// Parameters: a, b - references to values to swap
// Returns: void

// ===== Step 3: Const Reference Implementations =====
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
