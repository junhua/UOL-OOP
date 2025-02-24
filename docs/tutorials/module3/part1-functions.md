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
- Understand the purpose and syntax of functions
- Master function declaration and definition
- Learn proper function naming and organization
- Practice implementing reusable functions
- Understand function scope and lifetime
- Master function documentation
- Implement error handling in functions

## Introduction
Functions are the cornerstone of modern programming, serving as the fundamental building blocks that transform complex programs into manageable, organized pieces of code. Imagine building a house - instead of constructing everything as one massive structure, you create individual rooms, each serving a specific purpose. Functions work the same way in programming:

1. **Why Functions Matter**:
   - **Code Organization**: Break large programs into smaller, manageable pieces
   - **Reusability**: Write code once, use it many times in different places
   - **Maintainability**: Fix or modify functionality in one place instead of throughout the code
   - **Testing**: Test individual pieces of functionality in isolation
   - **Collaboration**: Enable multiple developers to work on different functions simultaneously

2. **Real-World Applications**:
   - **Mobile Apps**: Each button press triggers a specific function
   - **Web Browsers**: Functions handle everything from URL parsing to page rendering
   - **Games**: Different functions manage physics, graphics, and user input
   - **Business Software**: Functions process transactions, generate reports, and manage data

3. **Benefits in Development**:
   - **Reduced Complexity**: Break down complex problems into simpler steps
   - **Better Organization**: Group related code together logically
   - **Easier Debugging**: Isolate and fix issues in specific functions
   - **Code Reuse**: Share functionality across different parts of your program
   - **Better Testing**: Unit test individual functions independently

This part explores several key concepts:

1. **Function Fundamentals**:
   - Basic syntax and structure
   - Function declarations
   - Function definitions
   - Function calls
   - Return types
   - Code organization

2. **Function Design**:
   - Naming conventions
   - Documentation standards
   - Error handling
   - Code reusability
   - Function scope

3. **Best Practices**:
   - Single responsibility
   - Clear documentation
   - Error prevention
   - Code readability
   - Function organization

Understanding these concepts is essential for writing maintainable and efficient code. Through practical examples, you'll learn how to create well-structured functions that can be reused throughout your programs.

## Implementation Guide

You'll find the starter code in `Tutorials/Module03/Part1/functions_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module03/Part1/functions.cpp`.

### Step 1: Basic Function Structure
First, let's create a simple greeting function:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Function declaration
void greetUser(string name);

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    
    // Function call
    greetUser(name);
    return 0;
}

// Function definition
void greetUser(string name) {
    cout << "Hello, " << name << "!" << endl;
}
```

Key Points:
- Function declaration before main()
- Function definition after main()
- void means no return value
- Parameters pass data to function

Test Cases:
```cpp
Input: "Alice"
Expected: "Hello, Alice!"

Input: "Bob Smith"
Expected: "Hello, Bob Smith!"
```

### Step 2: Functions with Return Values
Implement a calculator function:

```cpp
// Function declarations
double calculate(double num1, double num2, char operation);
bool isValidOperation(char op);

int main() {
    double num1, num2;
    char operation;
    
    // Get input with validation
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    // Validate operation
    if (!isValidOperation(operation)) {
        cout << "Invalid operation!" << endl;
        return 1;
    }
    
    // Calculate and display result
    double result = calculate(num1, num2, operation);
    cout << num1 << " " << operation << " " << num2 
         << " = " << result << endl;
    
    return 0;
}

// Function definitions
double calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num2 != 0 ? num1 / num2 : 0;
        default: return 0;
    }
}

bool isValidOperation(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}
```

Test Cases:
```cpp
Input: 5.0, '+', 3.0
Expected: "5.0 + 3.0 = 8.0"

Input: 10.0, '/', 2.0
Expected: "10.0 / 2.0 = 5.0"

Input: 4.0, '$', 2.0
Expected: "Invalid operation!"
```

### Step 3: Functions with Error Handling
Create a robust array processing function:

```cpp
// Function declarations
bool processArray(const int arr[], int size, double& average, int& max);
void displayResults(bool success, double average, int max);

int main() {
    const int MAX_SIZE = 5;
    int numbers[MAX_SIZE];
    double average;
    int max;
    
    // Get array input
    cout << "Enter " << MAX_SIZE << " numbers:" << endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    // Process array and display results
    bool success = processArray(numbers, MAX_SIZE, average, max);
    displayResults(success, average, max);
    
    return 0;
}

// Function definitions
bool processArray(const int arr[], int size, double& average, int& max) {
    if (size <= 0) {
        return false;
    }
    
    int sum = 0;
    max = arr[0];
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    average = static_cast<double>(sum) / size;
    return true;
}

void displayResults(bool success, double average, int max) {
    if (success) {
        cout << "Average: " << average << endl;
        cout << "Maximum: " << max << endl;
    } else {
        cout << "Error: Invalid array size" << endl;
    }
}
```

Test Cases:
```cpp
Input: [1, 2, 3, 4, 5]
Expected:
Average: 3.0
Maximum: 5

Input: Empty array
Expected: "Error: Invalid array size"
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
