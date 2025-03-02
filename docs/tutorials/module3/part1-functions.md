---
layout: default
title: Part 1 - Function Basics
nav_order: 1
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part1-functions/
---

# Part 1: Function Basics

## Learning Objectives
- Understand function purpose and implementation mechanics
- Master parameter passing methods and return value handling
- Implement proper error handling and validation in functions
- Design reusable functions with clear interfaces
- Document functions effectively with comments
- Debug common function issues systematically
- Apply function design patterns to solve real problems

## Introduction
Functions are the cornerstone of modern programming, serving as the fundamental building blocks that transform complex programs into manageable, organized pieces of code. Think of functions as specialized workers in a factory assembly line - each with a specific job, taking inputs, performing operations, and producing outputs.

1. **Why Functions Matter**:
   - **Code Organization**: Break large programs into smaller, manageable pieces
   - **Reusability**: Write code once, use it many times in different places
   - **Maintainability**: Fix or modify functionality in one place instead of throughout the code
   - **Testing**: Test individual pieces of functionality in isolation
   - **Collaboration**: Enable multiple developers to work on different functions simultaneously
   - **Abstraction**: Hide complex implementation details behind simple interfaces
   - **Modularity**: Create independent, interchangeable components

2. **Real-World Parallels**:
   - **Restaurant Kitchen**: Each chef has a specialized function (prep, grill, sauce)
   - **Assembly Line**: Each station performs a specific task on the product
   - **Hospital**: Different specialists handle specific medical functions
   - **Orchestra**: Each musician plays a specific part that contributes to the whole
   - **Automotive Systems**: Each component (engine, brakes, steering) has a specific function

3. **Industry Applications**:
   - **Financial Software**: Functions calculate interest, validate transactions, generate reports
   - **E-commerce**: Functions process orders, update inventory, calculate shipping
   - **IoT Systems**: Functions collect sensor data, process readings, trigger actions
   - **Game Development**: Functions handle physics, AI decisions, user input, rendering
   - **Data Analysis**: Functions clean data, perform calculations, generate visualizations

This part explores several key concepts:

1. **Function Fundamentals**:
   - Basic syntax and structure
   - Function declarations and definitions
   - Function calls and execution flow
   - Return types and values
   - Parameter passing methods
   - Memory allocation during function execution
   - Stack frame management

2. **Function Design Principles**:
   - Single Responsibility Principle
   - Interface design and parameter selection
   - Error handling strategies
   - Input validation techniques
   - Return value optimization
   - Documentation standards
   - Testing methodologies

3. **Best Practices and Patterns**:
   - Descriptive naming conventions
   - Consistent parameter ordering
   - Default parameter usage
   - Early return pattern
   - Guard clauses for validation
   - Error code vs. exception handling
   - Pure functions vs. functions with side effects
   - Function composition techniques

Understanding these concepts is essential for writing maintainable and efficient code. Through practical examples and guided implementations, you'll learn how to create well-structured functions that can be reused throughout your programs and maintained over time.

## Implementation Guide

The `Tutorials/Module03/Part1/Learning/` directory contains starter files to help you learn about function basics:

1. Start with these files:
   - `functions_starter.cpp`: Basic function examples
   - `calculator_starter.cpp`: Calculator function implementation
   - `array_processor_starter.cpp`: Array processing functions
   - `menu_system_starter.cpp`: Complete menu-driven program

2. Implementation Steps:
   a. Begin with basic functions:
      - Add function declarations
      - Implement function definitions
      - Test with various inputs
   
   b. Move to calculator functions:
      - Implement operation validation
      - Add calculation logic
      - Add error handling
   
   c. Complete array processor:
      - Implement array validation
      - Add processing logic
      - Handle edge cases
   
   d. Finish the menu system:
      - Implement menu display
      - Add input validation
      - Create data processing functions

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o function_demo functions_starter.cpp
   
   # Run and verify output
   ./function_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each function as you implement it
   - Compare with example code in documentation
   - Use debugger to understand function execution flow
   
5. Reference Implementation:
   The completed versions are available in the same directory.
   Use these to:
   - Verify your implementation
   - Study function patterns
   - Understand best practices

### Step 1: Basic Function Structure
First, let's create a simple greeting function with proper documentation and error handling:

```cpp
#include <iostream>
#include <string>
#include <cctype>  // For character checking functions
using namespace std;

/**
 * Validates if a name contains only letters and spaces
 * 
 * @param name The name to validate
 * @return true if valid, false otherwise
 */
bool isValidName(const string& name) {
    if (name.empty()) {
        return false;
    }
    
    for (char c : name) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    
    return true;
}

/**
 * Greets a user with a personalized message
 * 
 * @param name The user's name
 * @return true if greeting was successful, false otherwise
 */
bool greetUser(const string& name) {
    // Validate input
    if (!isValidName(name)) {
        cout << "Error: Invalid name format." << endl;
        return false;
    }
    
    // Process valid input
    cout << "Hello, " << name << "!" << endl;
    return true;
}

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    
    // Function call with error handling
    if (!greetUser(name)) {
        cout << "Could not process the greeting. Please try again." << endl;
    }
    
    return 0;
}
```

Key Points:
- Function declaration with clear documentation
- Input validation in separate function
- Error handling with return values
- Const reference parameter for efficiency
- Clear function responsibilities
- Descriptive variable and function names

Memory Layout During Execution:
```
Stack Frame Visualization:

+----------------+
| main()         |
|----------------|
| name           | <-- Local variable in main
| Return address |
+----------------+
         |
         v
+----------------+
| greetUser()    |
|----------------|
| name (ref)     | <-- Reference to main's name
| Return address |
+----------------+
         |
         v
+----------------+
| isValidName()  |
|----------------|
| name (ref)     | <-- Reference to main's name
| c              | <-- Loop variable
| Return address |
+----------------+
```

Test Cases:
```cpp
Input: "Alice"
Expected: "Hello, Alice!"

Input: "Bob Smith"
Expected: "Hello, Bob Smith!"

Input: "John123"
Expected: "Error: Invalid name format."

Input: ""
Expected: "Error: Invalid name format."
```

### Step 2: Functions with Return Values and Error Handling
Implement a robust calculator function with comprehensive error handling:

```cpp
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
using namespace std;

/**
 * Validates if an operation is supported
 * 
 * @param op The operation character to validate
 * @return true if valid, false otherwise
 */
bool isValidOperation(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

/**
 * Performs a calculation between two numbers
 * 
 * @param num1 First operand
 * @param num2 Second operand
 * @param operation Mathematical operation to perform
 * @param result Reference to store the result
 * @return Error code: 0=success, 1=invalid operation, 2=division by zero, 3=overflow
 */
int calculate(double num1, double num2, char operation, double& result) {
    // Validate operation
    if (!isValidOperation(operation)) {
        return 1; // Invalid operation
    }
    
    // Perform calculation with error handling
    try {
        switch (operation) {
            case '+': 
                result = num1 + num2;
                break;
            case '-': 
                result = num1 - num2;
                break;
            case '*': 
                result = num1 * num2;
                break;
            case '/': 
                if (num2 == 0) {
                    return 2; // Division by zero
                }
                result = num1 / num2;
                break;
        }
        
        // Check for overflow/underflow
        if (result == std::numeric_limits<double>::infinity() || 
            result == -std::numeric_limits<double>::infinity()) {
            return 3; // Overflow
        }
        
        return 0; // Success
    }
    catch (...) {
        return 3; // Unexpected error (overflow or other)
    }
}

/**
 * Gets a valid number from user input
 * 
 * @param prompt Message to display to the user
 * @param value Reference to store the input value
 * @return true if input was valid, false otherwise
 */
bool getNumberInput(const string& prompt, double& value) {
    cout << prompt;
    
    if (!(cin >> value)) {
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input
        return false;
    }
    
    return true;
}

/**
 * Displays error message based on error code
 * 
 * @param errorCode The error code to process
 */
void displayError(int errorCode) {
    switch (errorCode) {
        case 1:
            cout << "Error: Invalid operation!" << endl;
            break;
        case 2:
            cout << "Error: Division by zero!" << endl;
            break;
        case 3:
            cout << "Error: Calculation resulted in overflow!" << endl;
            break;
        default:
            cout << "Unknown error occurred!" << endl;
    }
}

int main() {
    double num1, num2, result;
    char operation;
    
    // Get first number with validation
    if (!getNumberInput("Enter first number: ", num1)) {
        cout << "Invalid number input!" << endl;
        return 1;
    }
    
    // Get operation
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    // Get second number with validation
    if (!getNumberInput("Enter second number: ", num2)) {
        cout << "Invalid number input!" << endl;
        return 1;
    }
    
    // Calculate with error handling
    int errorCode = calculate(num1, num2, operation, result);
    
    if (errorCode != 0) {
        displayError(errorCode);
        return errorCode;
    }
    
    // Display result with proper formatting
    cout << fixed << setprecision(2);
    cout << num1 << " " << operation << " " << num2 
         << " = " << result << endl;
    
    return 0;
}
```

Function Call Flow Diagram:
```
main()
  │
  ├─> getNumberInput() ─> User provides num1
  │
  ├─> User provides operation
  │
  ├─> getNumberInput() ─> User provides num2
  │
  ├─> calculate()
  │     │
  │     └─> isValidOperation()
  │
  └─> displayError() (if needed)
```

Test Cases:
```cpp
Input: 5.0, '+', 3.0
Expected: "5.0 + 3.0 = 8.00"

Input: 10.0, '/', 2.0
Expected: "10.0 / 2.0 = 5.00"

Input: 4.0, '$', 2.0
Expected: "Error: Invalid operation!"

Input: 5.0, '/', 0.0
Expected: "Error: Division by zero!"

Input: 1e308, '*', 10.0
Expected: "Error: Calculation resulted in overflow!"

Input: abc, '+', 3.0
Expected: "Invalid number input!"
```

### Step 3: Functions with Comprehensive Error Handling
Create a robust array processing function with detailed validation and error reporting:

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

/**
 * Error codes for array processing
 */
enum ArrayProcessError {
    SUCCESS = 0,
    EMPTY_ARRAY = 1,
    INVALID_SIZE = 2,
    OVERFLOW_ERROR = 3,
    NULL_POINTER = 4
};

/**
 * Statistics structure to hold multiple results
 */
struct ArrayStats {
    double average;
    int max;
    int min;
    int sum;
    double median;
    bool hasOutliers;
};

/**
 * Process array to calculate statistics
 * 
 * @param arr Pointer to the array
 * @param size Size of the array
 * @param stats Reference to statistics structure
 * @return Error code indicating success or specific failure
 */
ArrayProcessError processArray(const int arr[], int size, ArrayStats& stats) {
    // Validate inputs
    if (arr == nullptr) {
        return NULL_POINTER;
    }
    
    if (size <= 0) {
        return EMPTY_ARRAY;
    }
    
    if (size > 10000) {  // Arbitrary limit for demonstration
        return INVALID_SIZE;
    }
    
    // Copy array to vector for additional processing
    vector<int> values(arr, arr + size);
    
    // Calculate statistics
    try {
        // Sum and extremes
        long long sum = 0;  // Use larger type to prevent overflow
        stats.max = values[0];
        stats.min = values[0];
        
        for (int i = 0; i < size; i++) {
            sum += values[i];
            stats.max = max(stats.max, values[i]);
            stats.min = min(stats.min, values[i]);
        }
        
        // Check for overflow
        if (sum > numeric_limits<int>::max()) {
            return OVERFLOW_ERROR;
        }
        
        stats.sum = static_cast<int>(sum);
        stats.average = static_cast<double>(sum) / size;
        
        // Calculate median
        sort(values.begin(), values.end());
        if (size % 2 == 0) {
            stats.median = (values[size/2 - 1] + values[size/2]) / 2.0;
        } else {
            stats.median = values[size/2];
        }
        
        // Check for outliers (simple method: values > 2 std deviations)
        double sumSquaredDiff = 0;
        for (int value : values) {
            double diff = value - stats.average;
            sumSquaredDiff += diff * diff;
        }
        double stdDev = sqrt(sumSquaredDiff / size);
        double threshold = 2 * stdDev;
        
        stats.hasOutliers = false;
        for (int value : values) {
            if (abs(value - stats.average) > threshold) {
                stats.hasOutliers = true;
                break;
            }
        }
        
        return SUCCESS;
    }
    catch (...) {
        return OVERFLOW_ERROR;
    }
}

/**
 * Display array statistics with formatting
 * 
 * @param error Error code from processing
 * @param stats Statistics structure with results
 */
void displayResults(ArrayProcessError error, const ArrayStats& stats) {
    switch (error) {
        case SUCCESS:
            cout << fixed << setprecision(2);
            cout << "Array Statistics:" << endl;
            cout << "----------------" << endl;
            cout << "Count: " << stats.sum / stats.average << endl;
            cout << "Sum: " << stats.sum << endl;
            cout << "Average: " << stats.average << endl;
            cout << "Median: " << stats.median << endl;
            cout << "Maximum: " << stats.max << endl;
            cout << "Minimum: " << stats.min << endl;
            cout << "Range: " << (stats.max - stats.min) << endl;
            
            if (stats.hasOutliers) {
                cout << "Warning: Outliers detected in the data" << endl;
            }
            break;
            
        case EMPTY_ARRAY:
            cout << "Error: Empty array provided" << endl;
            break;
            
        case INVALID_SIZE:
            cout << "Error: Invalid array size" << endl;
            break;
            
        case OVERFLOW_ERROR:
            cout << "Error: Calculation overflow occurred" << endl;
            break;
            
        case NULL_POINTER:
            cout << "Error: Null pointer provided" << endl;
            break;
            
        default:
            cout << "Unknown error occurred" << endl;
    }
}

/**
 * Get array input from user with validation
 * 
 * @param arr Array to fill
 * @param maxSize Maximum array size
 * @return Actual number of elements entered
 */
int getArrayInput(int arr[], int maxSize) {
    int size;
    
    // Get array size with validation
    do {
        cout << "Enter number of elements (1-" << maxSize << "): ";
        if (!(cin >> size) || size < 1 || size > maxSize) {
            cout << "Invalid size. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            size = 0;
        }
    } while (size == 0);
    
    // Get array elements
    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        while (true) {
            cout << "Number " << (i + 1) << ": ";
            if (cin >> arr[i]) {
                break;
            } else {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    
    return size;
}

int main() {
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    ArrayStats stats;
    
    // Get array input with validation
    int size = getArrayInput(numbers, MAX_SIZE);
    
    // Process array and display results
    ArrayProcessError error = processArray(numbers, size, stats);
    displayResults(error, stats);
    
    return 0;
}
```

Function Dependency Diagram:
```
                  +-------------+
                  |    main()   |
                  +------+------+
                         |
          +--------------|---------------+
          |              |               |
+---------v----------+ +-v--------------+ +----------------+
| getArrayInput()    | | processArray() | | displayResults()|
+-------------------+ +--------+--------+ +----------------+
                               |
                     +---------+---------+
                     | vector operations |
                     | (sort, min, max)  |
                     +-------------------+
```

Test Cases:
```cpp
Input: [1, 2, 3, 4, 5]
Expected:
Array Statistics:
----------------
Count: 5
Sum: 15
Average: 3.00
Median: 3.00
Maximum: 5
Minimum: 1
Range: 4

Input: [10, 20, 30, 100]
Expected:
Array Statistics:
----------------
Count: 4
Sum: 160
Average: 40.00
Median: 25.00
Maximum: 100
Minimum: 10
Range: 90
Warning: Outliers detected in the data

Input: Empty array
Expected: "Error: Empty array provided"

Input: Null pointer
Expected: "Error: Null pointer provided"

Input: Very large values causing overflow
Expected: "Error: Calculation overflow occurred"
```

### Step 4: Complete Implementation
Here's a complete program that demonstrates all concepts:

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function declarations
void displayMenu();
int getMenuChoice();
void processChoice(int choice);
bool processNumbers(vector<int>& numbers);
void displayStats(const vector<int>& numbers);
void clearScreen();

int main() {
    int choice;
    do {
        displayMenu();
        choice = getMenuChoice();
        processChoice(choice);
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    clearScreen();
    cout << "=== Number Processor ===" << endl;
    cout << "1. Enter numbers" << endl;
    cout << "2. Display statistics" << endl;
    cout << "3. Clear data" << endl;
    cout << "4. Exit" << endl;
    cout << "Choice: ";
}

int getMenuChoice() {
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid choice. Enter 1-4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void processChoice(int choice) {
    static vector<int> numbers;  // Persists between function calls
    
    switch (choice) {
        case 1:
            if (processNumbers(numbers)) {
                cout << "Numbers added successfully!" << endl;
            }
            break;
        case 2:
            displayStats(numbers);
            break;
        case 3:
            numbers.clear();
            cout << "Data cleared!" << endl;
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
    }
    
    if (choice != 4) {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}

bool processNumbers(vector<int>& numbers) {
    int num;
    cout << "Enter numbers (0 to finish):" << endl;
    
    while (true) {
        if (!(cin >> num)) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (num == 0) {
            break;
        }
        
        numbers.push_back(num);
    }
    
    return true;
}

void displayStats(const vector<int>& numbers) {
    if (numbers.empty()) {
        cout << "No data available!" << endl;
        return;
    }
    
    int sum = 0;
    int max = numbers[0];
    int min = numbers[0];
    
    for (int num : numbers) {
        sum += num;
        max = (num > max) ? num : max;
        min = (num < min) ? num : min;
    }
    
    double avg = static_cast<double>(sum) / numbers.size();
    
    cout << "\nStatistics:" << endl;
    cout << "Count: " << numbers.size() << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
```

Test Cases:
```cpp
Test Case 1: Basic Operation
Input:
1       // Choose enter numbers
5 10 15 0  // Enter numbers, 0 to finish
2       // Display statistics
4       // Exit

Expected Output:
Statistics:
Count: 3
Sum: 30
Average: 10
Maximum: 15
Minimum: 5

Test Case 2: Invalid Input Recovery
Input:
abc    // Invalid menu choice
1      // Valid choice
abc    // Invalid number
10     // Valid number
0      // Finish entering
4      // Exit

Expected:
Invalid choice. Enter 1-4:
Invalid input. Enter a number:
Numbers added successfully!

Test Case 3: Empty Statistics
Input:
2      // Display statistics before entering numbers
4      // Exit

Expected:
No data available!
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part1/practice_functions_starter.cpp`
- Complete solution: `Tutorials/Module03/Part1/practice_functions.cpp`

Follow these steps:
1. Open the starter template
2. Implement each exercise following the requirements
3. Test your implementation with the provided test cases
4. Compare your solution with the complete version if needed

### Exercise 1: Temperature Converter
Create a temperature conversion system with these functions:

```cpp
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
bool validateTemperature(double temp, double min, double max);
void displayConversion(double value, char unit);
```

Requirements:
1. Handle both C to F and F to C conversions
2. Validate temperatures within realistic ranges
3. Format output to 2 decimal places
4. Provide clear error messages
5. Allow multiple conversions

### Exercise 2: String Processor
Implement string manipulation functions:

```cpp
int countWords(const string& text);
string reverseString(const string& text);
bool isPalindrome(const string& text);
string changeCase(const string& text, char mode);
string removeCharacter(const string& text, char target);
```

Requirements:
1. Handle empty strings properly
2. Process multi-word input correctly
3. Ignore case for palindrome check
4. Support upper/lower case conversion
5. Handle special characters

### Exercise 3: Calculator
Create a scientific calculator with these functions:

```cpp
double basicOperation(double a, double b, char op);
double power(double base, int exponent);
double squareRoot(double number);
bool validateInput(double number);
string getCalculationHistory();
```

Requirements:
1. Support basic arithmetic operations
2. Include power and square root functions
3. Maintain calculation history
4. Validate all inputs
5. Format results professionally

### Working with the Practice Code

1. Navigate to the practice directory:
```bash
cd Tutorials/Module03/Part1
```

2. Compile the starter code:
```bash
g++ practice_functions_starter.cpp -o practice_starter
```

3. Run your implementation:
```bash
./practice_starter
```

4. Compare with the solution:
```bash
g++ practice_functions.cpp -o practice_solution
./practice_solution
```

## Summary

### Key Concepts
1. **Function Structure**
   - **Declaration**: Function prototype that tells compiler about function
     ```cpp
     void greetUser(string name);  // Declaration
     ```
   - **Definition**: Actual implementation of function
     ```cpp
     void greetUser(string name) {  // Definition
         cout << "Hello, " << name << "!" << endl;
     }
     ```
   - **Call**: Using the function
     ```cpp
     greetUser("Alice");  // Function call
     ```

2. **Return Values**
   - Functions can return data using `return` statement
   - Return type specified in declaration
   - Multiple return points possible
   ```cpp
   int add(int a, int b) {
       return a + b;  // Returns sum
   }

   bool isValid(int value) {
       if (value < 0) return false;
       if (value > 100) return false;
       return true;
   }
   ```

3. **Parameters**
   - Pass data into functions
   - Multiple parameters allowed
   - Different types possible
   ```cpp
   void displayInfo(string name, int age, double height) {
       cout << name << " is " << age << " years old";
       cout << " and " << height << "m tall" << endl;
   }
   ```

4. **Function Organization**
   - Group related functions together
   - Use meaningful names
   - Keep functions focused  
   
   ```cpp
   // Related functions grouped together
   double calculateArea(double radius) {
       return PI * radius * radius;
   }

   double calculateCircumference(double radius) {
       return 2 * PI * radius;
   }
   ```

### Common Pitfalls
1. Missing function declarations
2. Incorrect return types
3. Parameter type mismatches
4. Scope issues
5. Missing error handling
6. Poor documentation
7. Function name conflicts
8. Memory management issues

### Best Practices
1. Use clear, descriptive names
2. Document all functions
3. Handle all error cases
4. Keep functions focused
5. Validate all inputs
6. Use consistent formatting
7. Follow naming conventions
8. Maintain proper scope

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Review error handling
5. Move on to [Part 2: Function Declarations]({{ site.baseurl }}/tutorials/module3/part2-declaration)
6. Continue to [Part 3: Function Parameters]({{ site.baseurl }}/tutorials/module3/part3-parameters)
7. Finish with [Part 4: Call Types]({{ site.baseurl }}/tutorials/module3/part4-call-types)

Remember that well-structured functions are key to writing maintainable code. Always validate inputs, handle errors appropriately, and document your functions clearly.
