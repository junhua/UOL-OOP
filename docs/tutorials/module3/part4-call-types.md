---
layout: default
title: Part 4 - Call by Value and Call by Reference
nav_order: 4
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part4-call-types/
---

# Part 4: Call by Value and Call by Reference

## Learning Objectives
- Master the mechanics and memory implications of value vs. reference parameter passing
- Implement proper error handling for different parameter passing methods
- Analyze and optimize function performance through appropriate parameter selection
- Apply const references to balance efficiency and safety in function design
- Debug common memory and reference-related issues in function calls
- Measure and compare performance impacts of different parameter passing methods
- Design functions with appropriate parameter types based on data size and usage patterns
- Implement move semantics for modern C++ performance optimization

## Introduction
C++ provides multiple ways to pass arguments to functions, each with distinct performance characteristics and safety implications. Understanding these parameter passing methods is crucial for writing efficient, maintainable, and correct code.

1. **Call by Value**:
   - Creates a complete copy of the argument
   - Safe but potentially inefficient for large objects
   - Original data remains protected from modification
   - Good for small data types (int, double, char, bool)
   - Provides natural isolation between function and caller
   - Eliminates side effects and unexpected modifications
   - Creates memory overhead for large objects

2. **Call by Reference**:
   - Passes a reference (alias) to the original data
   - More efficient for large objects (no copying)
   - Can modify the original data directly
   - Must be initialized (cannot be null)
   - Requires careful handling to prevent unintended modifications
   - Enables functions to return multiple values through parameters
   - Creates potential for side effects if not documented

3. **Call by Const Reference**:
   - Combines efficiency of references with safety of values
   - Prevents modification of the original data
   - Compiler enforces const correctness
   - Ideal for large read-only parameters
   - Communicates clear intent to not modify
   - Enables compiler optimizations
   - Best practice for most input parameters

4. **Real-World Parallels**:
   - **Document Handling**: Value is like giving someone a photocopy (safe but wasteful), reference is like sharing the original document (efficient but risky), const reference is like letting someone read the original but not write on it
   - **Library Books**: Value is like making a personal copy of a book, reference is like lending the actual book, const reference is like allowing in-library reading only
   - **Blueprints**: Value is like creating duplicate blueprints, reference is like sharing the master blueprint, const reference is like viewing the blueprint behind glass
   - **Financial Records**: Value is like working with a copy of financial data, reference is like editing the actual ledger, const reference is like viewing statements without editing rights

5. **Industry Applications**:
   - **Game Development**: Const references for large game state objects, values for small position coordinates
   - **Financial Software**: Const references for market data, references for account modifications
   - **Image Processing**: Const references for input images, references for output images
   - **Database Systems**: References for transaction objects, const references for query parameters
   - **Scientific Computing**: Const references for large datasets, values for calculation parameters

## Implementation Guide

The `Tutorials/Module03/Part4/Learning/` directory contains starter files to help you learn about different parameter passing methods:

1. Start with these files:
   - `value_parameters_starter.cpp`: Examples of call by value
   - `reference_parameters_starter.cpp`: Examples of call by reference
   - `const_reference_starter.cpp`: Examples of call by const reference
   - `performance_comparison_starter.cpp`: Benchmark different parameter types
   - `move_semantics_starter.cpp`: Modern C++ move semantics examples

2. Implementation Steps:
   a. Begin with value parameters:
      - Implement functions with value parameters
      - Test with different data types
      - Observe copy behavior
   
   b. Move to reference parameters:
      - Implement functions with reference parameters
      - Create functions that modify original values
      - Compare behavior with value parameters
   
   c. Add const reference parameters:
      - Convert appropriate parameters to const references
      - Test compiler enforcement of const correctness
      - Compare memory usage with value parameters
   
   d. Benchmark performance:
      - Measure execution time for different parameter types
      - Test with various data sizes
      - Analyze performance implications

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -std=c++17 -o call_types value_parameters_starter.cpp
   
   # Run and verify output
   ./call_types
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each function as you implement it
   - Compare with example code in documentation
   - Use debugger to observe memory behavior
   
5. Reference Implementation:
   The completed versions are available in the same directory with "_solution" suffix.
   Use these to:
   - Verify your implementation
   - Study parameter passing patterns
   - Understand performance implications

### Step 1: Call by Value Examples

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

/**
 * Demonstrates call by value with primitive types
 * Creates a copy of the original value
 * 
 * @param x A copy of the original integer
 */
void modifyValue(int x) {
    cout << "Inside modifyValue, initial value: " << x << endl;
    cout << "Address of parameter x: " << &x << endl;  // Different address
    
    x *= 2;  // Only modifies local copy
    
    cout << "Inside modifyValue, after modification: " << x << endl;
}

/**
 * Demonstrates call by value with strings
 * Creates a copy of the original string
 * 
 * @param text A copy of the original string
 */
void handleString(string text) {
    cout << "Inside handleString, initial value: " << text << endl;
    cout << "Address of parameter text: " << &text << endl;  // Different address
    
    text += " World";  // Only modifies local copy
    
    cout << "Inside handleString, after modification: " << text << endl;
}

/**
 * Demonstrates array parameter behavior
 * Arrays are passed as pointers, not by value
 * 
 * @param arr Pointer to the original array
 * @param size Size of the array
 */
void processArray(int arr[], int size) {
    cout << "Inside processArray, initial values: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Address of parameter arr: " << arr << endl;  // Same address as original
    
    // Arrays are passed by reference by default
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original array
    }
    
    cout << "Inside processArray, after modification: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Demonstrates call by value with vectors
 * Creates a copy of the original vector
 * 
 * @param numbers A copy of the original vector
 */
void processVector(vector<int> numbers) {
    cout << "Inside processVector, initial values: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Address of parameter numbers: " << &numbers << endl;  // Different address
    
    // Modify the local copy
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] *= 2;
    }
    
    cout << "Inside processVector, after modification: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * Measures the performance impact of call by value
 * for different data sizes
 */
void measureValuePerformance() {
    cout << "\n=== Performance Measurement for Call by Value ===" << endl;
    
    // Test with different vector sizes
    vector<int> sizes = {1000, 10000, 100000};
    
    for (int size : sizes) {
        // Create test vector
        vector<int> testData(size, 1);  // Vector of specified size filled with 1s
        
        // Measure time to pass by value
        auto start = chrono::high_resolution_clock::now();
        
        // Call function 100 times to get measurable time
        for (int i = 0; i < 100; i++) {
            processVector(testData);  // Pass by value (creates copy)
        }
        
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        
        cout << "Time to process vector of size " << size 
             << " by value (100 calls): " << duration.count() << " ms" << endl;
    }
}

int main() {
    // Test with primitive type
    int number = 42;
    cout << "Original number: " << number << endl;
    cout << "Address of number: " << &number << endl;
    
    modifyValue(number);
    
    cout << "After calling modifyValue: " << number << endl;  // Still 42
    cout << endl;
    
    // Test with string
    string message = "Hello";
    cout << "Original message: " << message << endl;
    cout << "Address of message: " << &message << endl;
    
    handleString(message);
    
    cout << "After calling handleString: " << message << endl;  // Still "Hello"
    cout << endl;
    
    // Test with array
    int data[] = {1, 2, 3};
    cout << "Original array: ";
    for (int i = 0; i < 3; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    cout << "Address of data: " << data << endl;
    
    processArray(data, 3);
    
    cout << "After calling processArray: ";
    for (int i = 0; i < 3; i++) {
        cout << data[i] << " ";
    }
    cout << endl;  // Changed to {2, 4, 6}
    cout << endl;
    
    // Test with vector
    vector<int> numbers = {10, 20, 30};
    cout << "Original vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Address of numbers: " << &numbers << endl;
    
    processVector(numbers);
    
    cout << "After calling processVector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;  // Still {10, 20, 30}
    cout << endl;
    
    // Measure performance
    measureValuePerformance();
    
    return 0;
}
```

Memory Visualization for Call by Value:
```
Call by Value (Primitive Type):
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Parameter     │
│ Variable      │      │ Copy          │
├───────────────┤      ├───────────────┤
│ int number=42 │─────►│ int x=42      │
│ &number=0x1000│      │ &x=0x2000     │
└───────────────┘      └───────────────┘
       │                      │
       │                      │
       │                      ▼
       │               ┌───────────────┐
       │               │ x *= 2        │
       │               │ x becomes 84  │
       │               └───────────────┘
       │                      │
       ▼                      │
┌───────────────┐             │
│ number        │◄────────────┘
│ remains 42    │    (No effect on original)
└───────────────┘

Call by Value (Vector):
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Parameter     │
│ Vector        │      │ Copy          │
├───────────────┤      ├───────────────┤
│ vector<int>   │─────►│ vector<int>   │
│ {10,20,30}    │      │ {10,20,30}    │
│ &numbers=0x1000│      │ &numbers=0x3000│
└───────────────┘      └───────────────┘
       │                      │
       │                      │
       │                      ▼
       │               ┌───────────────┐
       │               │ Modify copy   │
       │               │ {20,40,60}    │
       │               └───────────────┘
       │                      │
       ▼                      │
┌───────────────┐             │
│ Original      │◄────────────┘
│ remains       │    (No effect on original)
│ {10,20,30}    │
└───────────────┘

Array Parameter (Special Case):
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Parameter     │
│ Array         │      │ (Pointer)     │
├───────────────┤      ├───────────────┤
│ int data[]    │─────►│ int arr[]     │
│ {1,2,3}       │      │ (points to    │
│ &data=0x1000  │      │  original)    │
└───────────────┘      │ arr=0x1000    │
       ▲               └───────────────┘
       │                      │
       │                      │
       │                      ▼
       │               ┌───────────────┐
       │               │ Modify array  │
       └───────────────│ {2,4,6}       │
         (Modifies     └───────────────┘
          original)
```

### Step 2: Call by Reference Examples

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;

/**
 * Modifies a value through reference parameter
 * Directly accesses and changes the original value
 * 
 * @param x Reference to the original integer
 */
void modifyByRef(int& x) {
    cout << "Inside modifyByRef, initial value: " << x << endl;
    cout << "Address of parameter x: " << &x << endl;  // Same address as original
    
    x *= 2;  // Modifies original value
    
    cout << "Inside modifyByRef, after modification: " << x << endl;
}

/**
 * Swaps two values using references
 * Directly modifies the original variables
 * 
 * @param a Reference to first value
 * @param b Reference to second value
 */
void swapValues(int& a, int& b) {
    cout << "Inside swapValues, initial values: a=" << a << ", b=" << b << endl;
    cout << "Address of parameter a: " << &a << endl;  // Same as original
    cout << "Address of parameter b: " << &b << endl;  // Same as original
    
    int temp = a;
    a = b;
    b = temp;
    
    cout << "Inside swapValues, after swap: a=" << a << ", b=" << b << endl;
}

/**
 * Updates a string through reference parameter
 * Directly modifies the original string
 * 
 * @param text Reference to the original string
 * @param suffix Text to append
 * @return Length of the resulting string
 */
int updateString(string& text, const string& suffix) {
    cout << "Inside updateString, initial value: " << text << endl;
    cout << "Address of parameter text: " << &text << endl;  // Same as original
    
    // Input validation
    if (text.empty()) {
        cout << "Warning: Empty string provided" << endl;
        text = suffix;
        return text.length();
    }
    
    // Modify the original string
    text += suffix;
    
    cout << "Inside updateString, after modification: " << text << endl;
    return text.length();
}

/**
 * Processes a vector through reference parameter
 * Directly modifies the original vector
 * 
 * @param numbers Reference to the original vector
 * @param multiplier Value to multiply each element by
 */
void processVectorByRef(vector<int>& numbers, int multiplier) {
    cout << "Inside processVectorByRef, initial values: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Address of parameter numbers: " << &numbers << endl;  // Same as original
    
    // Modify the original vector
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] *= multiplier;
    }
    
    cout << "Inside processVectorByRef, after modification: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * Finds minimum and maximum values in a vector
 * Uses reference parameters for output values
 * 
 * @param numbers Vector to analyze
 * @param min Reference parameter to store minimum value
 * @param max Reference parameter to store maximum value
 * @return true if successful, false if vector is empty
 */
bool getMinMax(const vector<int>& numbers, int& min, int& max) {
    if (numbers.empty()) {
        return false;  // Error case: empty vector
    }
    
    min = max = numbers[0];
    for (int num : numbers) {
        if (num < min) min = num;
        if (num > max) max = num;
    }
    
    return true;  // Success
}

/**
 * Measures the performance impact of call by reference
 * for different data sizes
 */
void measureReferencePerformance() {
    cout << "\n=== Performance Measurement for Call by Reference ===" << endl;
    
    // Test with different vector sizes
    vector<int> sizes = {1000, 10000, 100000};
    
    for (int size : sizes) {
        // Create test vector
        vector<int> testData(size, 1);  // Vector of specified size filled with 1s
        
        // Measure time to pass by reference
        auto start = chrono::high_resolution_clock::now();
        
        // Call function 100 times to get measurable time
        for (int i = 0; i < 100; i++) {
            processVectorByRef(testData, 2);  // Pass by reference (no copy)
        }
        
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        
        cout << "Time to process vector of size " << size 
             << " by reference (100 calls): " << duration.count() << " ms" << endl;
    }
}

int main() {
    // Test modifying a value by reference
    int number = 42;
    cout << "Original number: " << number << endl;
    cout << "Address of number: " << &number << endl;
    
    modifyByRef(number);
    
    cout << "After calling modifyByRef: " << number << endl;  // Now 84
    cout << endl;
    
    // Test swapping values
    int x = 5, y = 10;
    cout << "Original values: x=" << x << ", y=" << y << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Address of y: " << &y << endl;
    
    swapValues(x, y);
    
    cout << "After calling swapValues: x=" << x << ", y=" << y << endl;  // x=10, y=5
    cout << endl;
    
    // Test updating a string
    string message = "Hello";
    cout << "Original message: " << message << endl;
    cout << "Address of message: " << &message << endl;
    
    int length = updateString(message, " World!");
    
    cout << "After calling updateString: " << message << endl;  // "Hello World!"
    cout << "Resulting length: " << length << endl;
    cout << endl;
    
    // Test processing a vector by reference
    vector<int> numbers = {10, 20, 30};
    cout << "Original vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Address of numbers: " << &numbers << endl;
    
    processVectorByRef(numbers, 2);
    
    cout << "After calling processVectorByRef: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;  // Now {20, 40, 60}
    cout << endl;
    
    // Test finding min and max
    vector<int> data = {3, 7, 1, 9, 4};
    int min, max;
    
    cout << "Data vector: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
    
    if (getMinMax(data, min, max)) {
        cout << "Minimum value: " << min << endl;  // 1
        cout << "Maximum value: " << max << endl;  // 9
    } else {
        cout << "Error: Empty vector" << endl;
    }
    cout << endl;
    
    // Measure performance
    measureReferencePerformance();
    
    return 0;
}
```

Memory Visualization for Call by Reference:
```
Call by Reference:
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Reference     │
│ Variable      │      │ Parameter     │
├───────────────┤      ├───────────────┤
│ int number=42 │◄────►│ int& x        │
│ &number=0x1000│      │ &x=0x1000     │
└───────────────┘      └───────────────┘
       ▲                      │
       │                      │
       │                      ▼
       │               ┌───────────────┐
       │               │ x *= 2        │
       └───────────────│ x becomes 84  │
         (Modifies     └───────────────┘
          original)

Multiple Return Values:
┌───────────────┐      ┌───────────────┐
│ Function      │      │ Caller        │
│ getMinMax()   │      │               │
├───────────────┤      ├───────────────┤
│ const vector& │◄────►│ vector<int>   │
│ int& min      │◄────►│ int min       │
│ int& max      │◄────►│ int max       │
└───────────────┘      └───────────────┘
       │                      ▲
       ▼                      │
┌───────────────┐             │
│ min = 1       │             │
│ max = 9       │─────────────┘
└───────────────┘
```

### Step 3: Const Reference Examples

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>
using namespace std;

/**
 * Prints vector data using const reference
 * Efficient access without copying, prevents modification
 * 
 * @param data Vector to print (const reference)
 */
void printData(const vector<int>& data) {
    cout << "Inside printData, address of parameter data: " << &data << endl;  // Same as original
    
    cout << "Data values: ";
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
    
    // The following would cause compiler errors:
    // data.push_back(100);  // Error: data is const
    // data[0] = 999;        // Error: data is const
}

/**
 * Calculates average of array values using const array
 * Prevents modification of original data
 * 
 * @param values Array of values (const)
 * @param size Size of the array
 * @return Average value or 0.0 if empty
 */
double calculateAverage(const double values[], int size) {
    // Input validation
    if (values == nullptr || size <= 0) {
        return 0.0;  // Handle invalid input
    }
    
    cout << "Inside calculateAverage, values address: " << values << endl;
    
    // The following would cause compiler errors:
    // values[0] = 100.0;  // Error: values is const
    
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    
    return sum / size;
}

/**
 * Displays person details with const parameters
 * Efficient access without copying, prevents modification
 * 
 * @param name Person's name (const reference)
 * @param age Person's age (const reference)
 * @param height Person's height (const reference)
 */
void displayPerson(const string& name, const int& age, const double& height) {
    cout << "Inside displayPerson:" << endl;
    cout << "  name address: " << &name << endl;  // Same as original
    cout << "  age address: " << &age << endl;    // Same as original
    
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Height: " << fixed << setprecision(2) << height << " meters" << endl;
    
    // The following would cause compiler errors:
    // name += " Smith";  // Error: name is const
    // age++;             // Error: age is const
    // height += 0.1;     // Error: height is const
}

/**
 * Searches for values in a range using const reference
 * Efficient access without copying, prevents modification
 * 
 * @param numbers Vector to search (const reference)
 * @param min Minimum value
 * @param max Maximum value
 * @return Vector of values in range
 */
vector<int> fin

### Step 3: Const Reference Examples

```cpp
// Function declarations
void printData(const vector<int>& data);
double calculateAverage(const double values[], int size);
void displayPerson(const string& name, const int& age);

int main() {
    // Test const vector reference
    vector<int> numbers = {1, 2, 3, 4, 5};
    printData(numbers);
    
    // Test const array reference
    double scores[] = {85.5, 92.0, 77.5, 90.0};
    cout << "Average: " << calculateAverage(scores, 4) << endl;
    
    // Test const primitive references
    string name = "Alice";
    int age = 25;
    displayPerson(name, age);
    
    return 0;
}

// Function definitions
void printData(const vector<int>& data) {
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
}

double calculateAverage(const double values[], int size) {
    if (size == 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum / size;
}

void displayPerson(const string& name, const int& age) {
    cout << name << " is " << age << " years old" << endl;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part4/practice_call_types_starter.cpp`
- Complete solution: `Tutorials/Module03/Part4/practice_call_types.cpp`

### Exercise 1: Bank Account System

```cpp
struct BankAccount {
    string accountNumber;
    double balance;
    vector<string> transactions;
};

// TODO: Implement these functions
void deposit(BankAccount& account, double amount);
bool withdraw(BankAccount& account, double amount);
void displayBalance(const BankAccount& account);
void addTransaction(BankAccount& account, const string& description);
```

Requirements:
1. Use reference for account modifications
2. Use const reference for display
3. Validate all operations
4. Maintain transaction history
5. Format currency properly

### Exercise 2: Text Processing System

```cpp
// TODO: Implement these functions
void processText(const string& input, string& output);
int countWords(const string& text);
void convertCase(string& text, char mode);
void findAndReplace(string& text, const string& find, const string& replace);
```

Requirements:
1. Use const for input text
2. Modify output through reference
3. Handle empty strings
4. Process special characters
5. Validate all inputs

### Exercise 3: Data Analysis System

```cpp
struct DataSet {
    vector<double> values;
    double mean;
    double median;
    double standardDev;
};

// TODO: Implement these functions
void calculateStats(DataSet& data);
void addValue(DataSet& data, double value);
void removeValue(DataSet& data, int index);
void displayStats(const DataSet& data);
```

Requirements:
1. Update stats efficiently
2. Validate all operations
3. Handle empty datasets
4. Format output clearly
5. Use appropriate call types

## Summary

### Key Concepts

1. **Call by Value**
   - Creates copy of argument
   - Protects original data
   - Good for small types

   ```cpp
   void increment(int x) {
       x++;  // Only changes copy
   }
   
   int num = 5;
   increment(num);  // num still 5
   ```

2. **Call by Reference**
   - Uses original data
   - More efficient
   - Can modify argument

   ```cpp
   void increment(int& x) {
       x++;  // Changes original
   }
   
   int num = 5;
   increment(num);  // num now 6
   ```

3. **Const Reference**
   - Efficient access
   - Prevents modification
   - Best for large read-only

   ```cpp
   void print(const string& text) {
       cout << text << endl;
       // text += "!";  // Error
   }
   ```

4. **Performance Considerations**
   - Value copies data
   - Reference shares data
   - Const prevents changes

   ```cpp
   // Efficient parameter passing
   void process(const vector<int>& data) {
       // Access without copying
   }
   ```

### Common Pitfalls

1. **Unnecessary Copying**

   ```cpp
   // Inefficient: Copies large object
   void processData(vector<int> data) {
       // Works with copy
   }

   // Better: Uses reference
   void processData(const vector<int>& data) {
       // Works with original
   }
   ```

2. **Missing Const**

   ```cpp
   // Risky: Could modify input
   void displayData(vector<int>& data) {
       data.clear();  // Accidental modification
   }

   // Safe: Prevents modification
   void displayData(const vector<int>& data) {
       // data.clear();  // Error
   }
   ```

3. **Reference to Temporary**

   ```cpp
   // Dangerous: Reference to temporary
   int& getNumber() {
       int x = 42;
       return x;  // Returns dangling reference
   }

   // Safe: Return by value
   int getNumber() {
       int x = 42;
       return x;
   }
   ```

### Best Practices
1. **Parameter Selection**
   - Use value for small types
   - Use const reference for large types
   - Use reference for modification
   - Consider performance impact

2. **Safety Guidelines**
   - Validate references
   - Use const when possible
   - Avoid dangling references
   - Document modifications

3. **Performance Tips**
   - Minimize copying
   - Use references for large objects
   - Consider memory usage
   - Profile critical code

4. **Documentation**
   - Note parameter types
   - Document modifications
   - Explain performance choices
   - Specify requirements

## Next Steps
1. Complete practice exercises
2. Test with various data types
3. Profile performance
4. Review error handling
5. Move on to [Part 5: Function Overloading]({{ site.baseurl }}/tutorials/module3/part5-overloading)

Remember: Choosing the right parameter passing method is crucial for both correctness and performance. Consider the size of data and intended usage when making your choice.
