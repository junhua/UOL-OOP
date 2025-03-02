---
layout: default
title: Part 3 - Function Parameters and Return Values
nav_order: 3
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part3-parameters/
---

# Part 3: Function Parameters and Return Values

## Learning Objectives
- Master different parameter passing methods and their performance implications
- Implement value, reference, and const reference parameters with proper usage patterns
- Design functions with optimal parameter types based on data size and modification needs
- Apply multiple return value techniques using reference parameters
- Implement robust error handling through parameter validation and return values
- Design clear function interfaces with appropriate parameter ordering and defaults
- Debug common parameter-related issues and memory problems
- Optimize function performance through appropriate parameter selection

## Introduction
Function parameters and return values are essential mechanisms for making functions flexible, reusable, and efficient. They form the contract between a function and its caller, defining how data flows in and out of the function. Think of them as the communication channels of your code:

1. **Parameters as Input Channels**:
   - Like plugs on a device that accept different types of data
   - Configure function behavior for different scenarios
   - Enable function flexibility and reusability
   - Allow code to be generalized for multiple use cases
   - Control how data is accessed and modified
   - Determine function performance characteristics

2. **Return Values as Output Channels**:
   - Provide computed results back to the caller
   - Indicate success/failure status of operations
   - Enable function composition and chaining
   - Support comprehensive error handling
   - Allow for functional programming patterns
   - Create clear data flow in complex systems

3. **Real-World Parallels**:
   - **Manufacturing Machine**: Parameters are the settings and materials (inputs), return value is the finished product (output)
   - **Kitchen Appliance**: Parameters are ingredients and settings, return value is the prepared food
   - **Medical Test**: Parameters are patient samples and test specifications, return value is the diagnosis
   - **Financial Transaction**: Parameters are account details and amount, return value is the transaction status
   - **GPS Navigation**: Parameters are start/end locations and preferences, return value is the route

4. **Industry Applications**:
   - **Data Processing**: Functions with data source parameters and processing options
   - **Graphics Rendering**: Functions with scene parameters and rendering settings
   - **Financial Calculations**: Functions with monetary values and calculation parameters
   - **Scientific Computing**: Functions with measurement parameters and precision settings
   - **User Authentication**: Functions with credentials and security parameters

## Implementation Guide

The `Tutorials/Module03/Part3/Learning/` directory contains starter files to help you learn about function parameters and return values:

1. Start with these files:
   - `value_parameters_starter.cpp`: Examples of pass-by-value
   - `reference_parameters_starter.cpp`: Examples of pass-by-reference
   - `const_parameters_starter.cpp`: Examples of const parameters
   - `multiple_returns_starter.cpp`: Examples of multiple return techniques
   - `parameter_optimization_starter.cpp`: Examples of performance considerations

2. Implementation Steps:
   a. Begin with value parameters:
      - Implement basic value parameter functions
      - Observe how changes don't affect original values
      - Test with different data types
   
   b. Move to reference parameters:
      - Implement functions with reference parameters
      - Create functions that modify original values
      - Implement output parameters
   
   c. Add const parameters:
      - Convert appropriate parameters to const
      - Implement functions with const reference parameters
      - Test compiler enforcement of const correctness
   
   d. Explore multiple returns:
      - Implement functions with multiple output parameters
      - Create functions that return complex results
      - Compare different return techniques

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o parameter_demo value_parameters_starter.cpp
   
   # Run and verify output
   ./parameter_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each function as you implement it
   - Compare with example code in documentation
   - Use debugger to observe parameter behavior
   
5. Reference Implementation:
   The completed versions are available in the same directory with "_solution" suffix.
   Use these to:
   - Verify your implementation
   - Study parameter patterns
   - Understand best practices

### Step 1: Value Parameters
Value parameters create a copy of the argument, providing safety but potentially impacting performance:

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Demonstrates value parameter behavior with primitive types
 * 
 * @param num A copy of the original integer
 */
void modifyValue(int num) {
    cout << "Inside modifyValue, initial value: " << num << endl;
    num *= 2;  // Only modifies local copy
    cout << "Inside modifyValue, after modification: " << num << endl;
}

/**
 * Demonstrates value parameter behavior with strings
 * 
 * @param text A copy of the original string
 */
void modifyString(string text) {
    cout << "Inside modifyString, initial value: " << text << endl;
    text += " World";  // Only modifies local copy
    cout << "Inside modifyString, after modification: " << text << endl;
}

/**
 * Demonstrates array parameter behavior
 * Arrays are passed as pointers, not by value
 * 
 * @param arr Pointer to the original array
 * @param size Size of the array
 */
void modifyArray(int arr[], int size) {
    cout << "Inside modifyArray, initial values: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Arrays are passed by reference by default
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
    
    cout << "Inside modifyArray, after modification: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Demonstrates vector value parameter behavior
 * 
 * @param numbers A copy of the original vector
 */
void modifyVector(vector<int> numbers) {
    cout << "Inside modifyVector, initial values: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Modify the local copy
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] *= 2;
    }
    
    cout << "Inside modifyVector, after modification: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Test with primitive type
    int number = 5;
    cout << "Before calling modifyValue: " << number << endl;
    modifyValue(number);
    cout << "After calling modifyValue: " << number << endl;  // Still 5
    cout << endl;
    
    // Test with string
    string text = "Hello";
    cout << "Before calling modifyString: " << text << endl;
    modifyString(text);
    cout << "After calling modifyString: " << text << endl;  // Still "Hello"
    cout << endl;
    
    // Test with array
    int array[] = {1, 2, 3};
    cout << "Before calling modifyArray: ";
    for (int i = 0; i < 3; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    modifyArray(array, 3);
    
    cout << "After calling modifyArray: ";
    for (int i = 0; i < 3; i++) {
        cout << array[i] << " ";
    }
    cout << endl;  // Changed to {2, 4, 6}
    cout << endl;
    
    // Test with vector
    vector<int> numbers = {10, 20, 30};
    cout << "Before calling modifyVector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    modifyVector(numbers);
    
    cout << "After calling modifyVector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;  // Still {10, 20, 30}
    
    return 0;
}
```

Parameter Passing Visualization:
```
Value Parameter (Copy):
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Parameter     │
│ Variable      │      │ Copy          │
├───────────────┤      ├───────────────┤
│ int number = 5│─────►│ int num = 5   │
└───────────────┘      └───────────────┘
       │                      │
       │                      │
       │                      ▼
       │               ┌───────────────┐
       │               │ num *= 2      │
       │               │ num becomes 10│
       │               └───────────────┘
       │                      │
       ▼                      │
┌───────────────┐             │
│ number        │◄────────────┘
│ remains 5     │    (No effect on original)
└───────────────┘

Array Parameter (Pointer):
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Parameter     │
│ Array         │      │ (Pointer)     │
├───────────────┤      ├───────────────┤
│ int array[]   │─────►│ int arr[]     │
│ {1,2,3}       │      │ (points to    │
└───────────────┘      │  original)    │
       ▲               └───────────────┘
       │                      │
       │                      │
       │                      ▼
       │               ┌───────────────┐
       │               │ arr[0] *= 2   │
       │               │ arr[1] *= 2   │
       └───────────────│ arr[2] *= 2   │
         (Modifies     └───────────────┘
          original)
```

Key Points:
- Value parameters create copies of the original data
- Changes to the parameter don't affect the original variable
- Value parameters are safe but can be inefficient for large data
- Arrays are a special case - they're passed as pointers, not by value
- Value parameters provide natural protection against unintended modification
- Useful for small data types (int, double, char, bool)
- Creates memory overhead for large objects like vectors or strings

### Step 2: Reference Parameters
Reference parameters provide direct access to the original argument, enabling modification and improved performance:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * Modifies a value through reference parameter
 * 
 * @param num Reference to the original integer
 */
void modifyByReference(int& num) {
    cout << "Inside modifyByReference, initial value: " << num << endl;
    num *= 2;  // Modifies original value
    cout << "Inside modifyByReference, after modification: " << num << endl;
}

/**
 * Finds minimum and maximum values in a vector
 * Uses reference parameters for output values
 * 
 * @param numbers Vector to analyze (const reference for efficiency)
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
 * Swaps two values using references
 * 
 * @param a First value to swap
 * @param b Second value to swap
 */
void swapValues(int& a, int& b) {
    cout << "Inside swapValues, initial values: a=" << a << ", b=" << b << endl;
    
    int temp = a;
    a = b;
    b = temp;
    
    cout << "Inside swapValues, after swap: a=" << a << ", b=" << b << endl;
}

/**
 * Modifies a string through reference parameter
 * 
 * @param text Reference to the original string
 * @param prefix Text to prepend
 * @param suffix Text to append
 */
void modifyString(string& text, const string& prefix, const string& suffix) {
    cout << "Inside modifyString, initial value: " << text << endl;
    
    // Input validation
    if (text.empty()) {
        throw invalid_argument("Empty string provided");
    }
    
    // Modify the original string
    text = prefix + text + suffix;
    
    cout << "Inside modifyString, after modification: " << text << endl;
}

int main() {
    // Test modifying a value by reference
    int number = 10;
    cout << "Before calling modifyByReference: " << number << endl;
    modifyByReference(number);
    cout << "After calling modifyByReference: " << number << endl;  // Now 20
    cout << endl;
    
    // Test finding min and max values
    vector<int> nums = {3, 7, 1, 9, 4};
    int min, max;
    
    cout << "Vector contents: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    if (getMinMax(nums, min, max)) {
        cout << "Minimum value: " << min << endl;  // 1
        cout << "Maximum value: " << max << endl;  // 9
    } else {
        cout << "Error: Empty vector" << endl;
    }
    cout << endl;
    
    // Test swapping values
    int x = 5, y = 10;
    cout << "Before swapping: x=" << x << ", y=" << y << endl;
    swapValues(x, y);
    cout << "After swapping: x=" << x << ", y=" << y << endl;  // x=10, y=5
    cout << endl;
    
    // Test modifying a string
    string message = "Hello";
    cout << "Before modifying string: " << message << endl;
    
    try {
        modifyString(message, "** ", " **");
        cout << "After modifying string: " << message << endl;  // "** Hello **"
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

Reference Parameter Visualization:
```
Reference Parameter:
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Reference     │
│ Variable      │      │ Parameter     │
├───────────────┤      ├───────────────┤
│ int number=10 │◄────►│ int& num      │
└───────────────┘      └───────────────┘
       ▲                      │
       │                      │
       │                      ▼
       │               ┌───────────────┐
       │               │ num *= 2      │
       └───────────────│ num becomes 20│
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

Key Points:
- Reference parameters provide direct access to the original variable
- Changes to the parameter directly modify the original
- More efficient for large objects (no copying)
- Can be used to return multiple values from a function
- References must be initialized and can't be null
- Const references provide efficiency without allowing modification
- References create clearer code than pointers
- Useful for output parameters and modifying existing values
- Can improve performance significantly for large data structures

### Step 3: Const Parameters and Return Value Optimization
Const parameters prevent modification of arguments and enable compiler optimizations:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

/**
 * Calculates the average of a vector of numbers
 * Uses const reference for efficiency without modification
 * 
 * @param numbers Vector to analyze (const reference)
 * @return The average value or 0.0 if empty
 */
double calculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) {
        return 0.0;  // Handle empty vector case
    }
    
    double sum = 0.0;
    for (int num : numbers) {
        sum += num;
    }
    
    return sum / numbers.size();
}

/**
 * Prints person details with const parameters
 * 
 * @param name Person's name (const reference for efficiency)
 * @param age Person's age (const reference for demonstration)
 * @param height Person's height (const reference)
 */
void printPersonDetails(const string& name, const int& age, const double& height) {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << " years" << endl;
    cout << "Height: " << fixed << setprecision(2) << height << " meters" << endl;
    
    // The following would cause compiler errors:
    // name += " Smith";  // Error: name is const
    // age++;             // Error: age is const
    // height += 0.1;     // Error: height is const
}

/**
 * Searches for a value in an array
 * 
 * @param arr Array to search (const to prevent modification)
 * @param size Size of the array
 * @param target Value to find
 * @return true if found, false otherwise
 */
bool searchValue(const int arr[], int size, int target) {
    // Input validation
    if (arr == nullptr || size <= 0) {
        return false;
    }
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;  // Found
        }
    }
    
    return false;  // Not found
}

/**
 * Creates a formatted string (demonstrates return value)
 * 
 * @param items Vector of items (const reference)
 * @return Formatted string with items
 */
string createItemList(const vector<string>& items) {
    if (items.empty()) {
        return "No items";
    }
    
    string result = "Items: ";
    for (size_t i = 0; i < items.size(); i++) {
        result += items[i];
        if (i < items.size() - 1) {
            result += ", ";
        }
    }
    
    return result;  // Return by value (compiler may optimize with RVO)
}

/**
 * Finds values within a range (demonstrates multiple return techniques)
 * 
 * @param numbers Vector to analyze
 * @param min Minimum threshold
 * @param max Maximum threshold
 * @return Vector of values within range
 */
vector<int> findValuesInRange(const vector<int>& numbers, int min, int max) {
    vector<int> result;
    
    // Input validation
    if (min > max) {
        swap(min, max);  // Fix invalid range
    }
    
    // Find values in range
    for (int num : numbers) {
        if (num >= min && num <= max) {
            result.push_back(num);
        }
    }
    
    return result;  // Return by value (compiler may optimize with RVO)
}

int main() {
    // Test average calculation
    vector<int> nums = {10, 20, 30, 40, 50};
    cout << "Numbers: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    double avg = calculateAverage(nums);
    cout << "Average: " << avg << endl << endl;
    
    // Test person details
    string name = "Alice Johnson";
    int age = 28;
    double height = 1.75;
    
    printPersonDetails(name, age, height);
    cout << endl;
    
    // Test array search
    int arr[] = {10, 20, 30, 40, 50};
    int target = 30;
    
    cout << "Searching for " << target << " in array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    bool found = searchValue(arr, 5, target);
    cout << "Found " << target << ": " << (found ? "Yes" : "No") << endl << endl;
    
    // Test item list creation
    vector<string> items = {"Apple", "Banana", "Cherry"};
    string itemList = createItemList(items);
    cout << itemList << endl << endl;
    
    // Test range finder
    vector<int> values = {5, 12, 8, 25, 3, 17};
    cout << "Values: ";
    for (int val : values) {
        cout << val << " ";
    }
    cout << endl;
    
    int minThreshold = 10;
    int maxThreshold = 20;
    vector<int> inRange = findValuesInRange(values, minThreshold, maxThreshold);
    
    cout << "Values between " << minThreshold << " and " << maxThreshold << ": ";
    for (int val : inRange) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
```

Const Parameter and Return Value Visualization:
```
Const Reference Parameter:
┌───────────────┐      ┌───────────────┐
│ Original      │      │ Const         │
│ Vector        │      │ Reference     │
├───────────────┤      ├───────────────┤
│ vector<int>   │─────►│ const vector& │
│ nums          │      │ numbers       │
└───────────────┘      └───────────────┘
                              │
                              │
                              ▼
                       ┌───────────────┐
                       │ Read-only     │
                       │ access        │
                       │ (No changes   │
                       │  allowed)     │
                       └───────────────┘

Return Value Optimization (RVO):
┌───────────────┐      ┌───────────────┐
│ Function      │      │ Caller        │
│ findValues()  │      │               │
├───────────────┤      ├───────────────┤
│ vector<int>   │      │ vector<int>   │
│ result        │─────►│ inRange       │
└───────────────┘      └───────────────┘
       │                      
       │                      
       ▼                      
┌───────────────┐             
│ Compiler      │             
│ optimizes to  │             
│ construct     │             
│ directly in   │             
│ caller's space│             
└───────────────┘             
```

Key Points:
- Const parameters prevent accidental modification of arguments
- Compiler enforces const correctness with errors for modification attempts
- Const references combine efficiency (no copying) with safety (no modification)
- Use const references for all large input parameters you don't need to modify
- Const correctness makes code intent clearer and prevents bugs
- Return value optimization (RVO) allows efficient return of large objects
- Const parameters enable more aggressive compiler optimizations
- Const correctness is especially important in large codebases
- Modern C++ compilers can optimize away unnecessary copies with RVO/NRVO

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part3/practice_parameters_starter.cpp`
- Complete solution: `Tutorials/Module03/Part3/practice_parameters.cpp`

### Exercise 1: Student Grade Calculator
Create a grade management system:

```cpp
struct Student {
    string name;
    vector<double> grades;
};

void addGrade(Student& student, double grade);
double calculateAverage(const Student& student);
char getLetterGrade(double average);
void printStudentReport(const Student& student);
```

Requirements:
1. Validate grades (0-100)
2. Calculate accurate average
3. Convert to letter grades
4. Format output clearly
5. Handle empty grade lists

### Exercise 2: Array Operations
Implement array manipulation functions:

```cpp
void fillArray(int arr[], int size);
void modifyArray(int arr[], int size, int multiplier);
int findMax(const int arr[], int size);
void printArray(const int arr[], int size);
```

Requirements:
1. Fill array sequentially
2. Modify all elements
3. Find maximum safely
4. Format output neatly
5. Handle empty arrays

### Exercise 3: String Manipulator
Create string processing functions:

```cpp
void appendText(string& text, const string& suffix);
string wrapInTags(const string& text, const string& tag);
int countOccurrences(const string& text, char target);
void convertCase(string& text, char mode);
```

Requirements:
1. Append text efficiently
2. Create HTML tags
3. Count characters accurately
4. Handle case conversion
5. Process empty strings

## Summary

### Key Concepts

1. **Value Parameters**
   - Creates copy of argument
   - Changes don't affect original
   - Good for small data types

   ```cpp
   void modifyValue(int x) {
       x = x * 2;  // Only changes local copy
   }

   int num = 10;
   modifyValue(num);  // num still equals 10
   ```

2. **Reference Parameters**
   - Direct access to original data
   - Changes affect original value
   - More efficient for large objects

   ```cpp
   void modifyReference(string& text) {
       text += " modified";  // Changes original
   }

   string msg = "Hello";
   modifyReference(msg);  // msg is now "Hello modified"
   ```

3. **Const Parameters**
   - Prevents modification of arguments
   - Compiler enforces protection
   - Best for large read-only data

   ```cpp
   void printData(const vector<int>& data) {
       // data.push_back(42);  // Error: can't modify
       for (int value : data) {
           cout << value << " ";
       }
   }
   ```

4. **Multiple Return Values**
   - Use reference parameters
   - Pass by reference for output
   - Document output parameters

   ```cpp
   void getMinMax(const vector<int>& data, 
                 int& min, int& max) {
       if (data.empty()) return;
       min = max = data[0];
       for (int value : data) {
           min = std::min(min, value);
           max = std::max(max, value);
       }
   }
   ```

### Common Pitfalls

1. **Value vs. Reference Confusion**

   ```cpp
   // Wrong: Trying to modify through value
   void increment(int x) {
       x++;  // Doesn't affect original
   }

   // Right: Using reference
   void increment(int& x) {
       x++;  // Modifies original
   }
   ```

2. **Missing Const**

   ```cpp
   // Wrong: Could accidentally modify input
   void printArray(vector<int>& nums) {
       nums[0] = 0;  // Accidental modification
   }

   // Right: Protect with const
   void printArray(const vector<int>& nums) {
       // nums[0] = 0;  // Compiler error
   }
   ```

3. **Array Decay**

   ```cpp
   // Wrong: Size lost in parameter
   void process(int arr[]) {
       int size = sizeof(arr);  // Wrong!
   }

   // Right: Pass size explicitly
   void process(int arr[], int size) {
       // Use size parameter
   }
   ```

### Best Practices

1. **Parameter Selection**
   - Use value for small types
   - Use const reference for large types
   - Use non-const reference to modify
   - Pass arrays with size
   - Use const when possible

2. **Return Values**
   - Return by value for small types
   - Return by const reference for large types
   - Use references for multiple returns
   - Return status for error handling
   - Document return values

3. **Error Handling**
   - Validate all inputs
   - Handle edge cases
   - Return error status
   - Use references for errors
   - Document error conditions

4. **Documentation**
   - Document parameters
   - Specify return values
   - Note modifications
   - List requirements
   - Explain errors

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Review error handling
5. Move on to [Part 4: Call Types]({{ site.baseurl }}/tutorials/module3/part4-call-types)

Remember: Proper parameter and return value management is crucial for creating reliable and maintainable functions. Always consider the most appropriate parameter types and validate all inputs thoroughly.
