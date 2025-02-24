---
layout: default
title: Part 2 - Switch Statements
nav_order: 2
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part2-switch/
---

# Part 2: Switch Statements

## Learning Objectives
- Master the **switch statement** syntax and usage
- Understand when to *use* **switch** vs **if-else**
- Learn proper **case organization** and **fall-through**
- *Implement* robust **input validation**
- *Handle* error conditions effectively
- *Practice* **switch patterns** in applications

## Introduction
Switch statements provide an efficient and readable way to handle multiple discrete cases in your code. Think of them like a multi-way junction in a road:

1. **Why Switch Statements Matter**:
   - **Code Organization**: Group related cases together
   - **Performance**: More efficient than long if-else chains
   - **Readability**: Clear structure for multiple choices
   - **Maintainability**: Easy to add or modify cases
   - **Error Prevention**: Compiler checks for duplicate cases

2. **Real-World Applications**:
   - **Menu Systems**: Process user selections
   - **State Machines**: Manage program states
   - **Command Processing**: Handle different commands
   - **Event Handling**: Respond to various events
   - **Data Processing**: Sort items by category

3. **Benefits in Development**:
   - **Cleaner Code**: Better organization than if-else chains
   - **Better Performance**: Optimized by compiler
   - **Easier Debugging**: Clear case structure
   - **Simpler Maintenance**: Easy to modify cases
   - **Reduced Errors**: Compiler catches duplicates

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part2/switch_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part2/switch.cpp`.

### Step 1: Basic Switch Structure
First, let's understand the basic switch statement:

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Enter a number (1-3): ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "You selected One" << endl;
            break;  // Prevents fall-through
            
        case 2:
            cout << "You selected Two" << endl;
            break;
            
        case 3:
            cout << "You selected Three" << endl;
            break;
            
        default:  // Handles all other values
            cout << "Invalid selection" << endl;
            break;
    }
    
    return 0;
}
```

Key Points:
- Expression must be integral type
- Cases must be constant expressions
- Break prevents fall-through
- Default handles unmatched values
- Cases must be unique

### Step 2: Menu System Example
Create a more complex menu:

```cpp
#include <iostream>
#include <string>
using namespace std;

enum class Operation {
    Add = 1,
    Subtract,
    Multiply,
    Divide,
    Exit
};

int main() {
    double num1, num2;
    int choice;
    bool running = true;
    
    while (running) {
        // Display menu
        cout << "\nCalculator Menu\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        
        // Get valid input
        if (!(cin >> choice)) {
            cout << "Invalid input\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        // Exit check
        if (choice == static_cast<int>(Operation::Exit)) {
            running = false;
            continue;
        }
        
        // Get numbers for calculation
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        
        // Process choice
        switch (static_cast<Operation>(choice)) {
            case Operation::Add:
                cout << num1 << " + " << num2 << " = " 
                     << num1 + num2 << endl;
                break;
                
            case Operation::Subtract:
                cout << num1 << " - " << num2 << " = " 
                     << num1 - num2 << endl;
                break;
                
            case Operation::Multiply:
                cout << num1 << " * " << num2 << " = " 
                     << num1 * num2 << endl;
                break;
                
            case Operation::Divide:
                if (num2 != 0) {
                    cout << num1 << " / " << num2 << " = " 
                         << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero" << endl;
                }
                break;
                
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
    
    return 0;
}
```

### Step 3: Fall-Through Example
Demonstrate intentional fall-through:

```cpp
#include <iostream>
using namespace std;

int main() {
    char grade;
    cout << "Enter grade (A-F): ";
    cin >> grade;
    
    switch (toupper(grade)) {
        case 'A':
            cout << "Excellent! ";
            // Fall through intentional
        case 'B':
            cout << "Good! ";
            // Fall through intentional
        case 'C':
            cout << "Passing. ";
            break;
            
        case 'D':
        case 'F':  // Grouped cases
            cout << "Need improvement. ";
            break;
            
        default:
            cout << "Invalid grade. ";
            break;
    }
    
    return 0;
}
```

Test Cases:
```cpp
Input: 'A'
Expected: "Excellent! Good! Passing."

Input: 'B'
Expected: "Good! Passing."

Input: 'D'
Expected: "Need improvement."

Input: 'X'
Expected: "Invalid grade."
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module02/Part2/practice_switch_starter.cpp`
- Complete solution: `Tutorials/Module02/Part2/practice_switch.cpp`

### Exercise 1: Command Processor
Create a command processing system:
1. Accept single-character commands
2. Process different actions:
   - 'H': Help
   - 'L': List
   - 'A': Add
   - 'D': Delete
   - 'Q': Quit
3. Validate input
4. Provide feedback
5. Support multiple commands

Requirements:
1. Input validation
2. Clear messages
3. Case insensitive
4. Error handling
5. Exit option

### Exercise 2: State Machine
Implement a simple state machine:
1. Define states:
   - IDLE
   - RUNNING
   - PAUSED
   - ERROR
   - COMPLETE
2. Process state transitions
3. Handle invalid transitions
4. Track current state
5. Display state changes

Requirements:
1. Valid transitions
2. State validation
3. Error handling
4. Status display
5. Clean exit

### Exercise 3: Calculator
Create a scientific calculator:
1. Basic operations (+,-,*,/)
2. Advanced functions:
   - Square root
   - Power
   - Absolute value
3. Memory operations
4. Input validation
5. Error handling

Requirements:
1. Number validation
2. Operation checks
3. Error messages
4. Memory management
5. Multiple calculations

## Summary

### Key Concepts
1. **Basic Switch Structure**
   ```cpp
   switch (expression) {
       case constant1:
           // Code for case 1
           break;
       case constant2:
           // Code for case 2
           break;
       default:
           // Default handler
           break;
   }
   ```

2. **Fall-Through Behavior**
   ```cpp
   switch (grade) {
       case 'A':
           cout << "Excellent! ";
           // Intentional fall-through
       case 'B':
           cout << "Good! ";
           break;
   }
   ```

3. **Grouped Cases**
   ```cpp
   switch (response) {
       case 'y':
       case 'Y':
           // Handle yes
           break;
       case 'n':
       case 'N':
           // Handle no
           break;
   }
   ```

### Common Pitfalls
1. **Missing Break**
   ```cpp
   // Bad: Accidental fall-through
   switch (value) {
       case 1:
           cout << "One";  // Falls through!
       case 2:
           cout << "Two";
   }

   // Good: Explicit breaks
   switch (value) {
       case 1:
           cout << "One";
           break;
       case 2:
           cout << "Two";
           break;
   }
   ```

2. **Non-Constant Cases**
   ```cpp
   // Bad: Variable in case
   int x = 1;
   switch (value) {
       case x:  // Error: Must be constant
           break;
   }

   // Good: Constant cases
   switch (value) {
       case 1:  // Literal
       case MAX:  // Constant
           break;
   }
   ```

3. **Wrong Types**
   ```cpp
   // Bad: Non-integral type
   double d = 1.0;
   switch (d) {  // Error!

   // Good: Integral type
   int i = 1;
   switch (i) {  // OK
   ```

### Best Practices
1. **Use Enums**
   ```cpp
   enum class Option {
       Add = 1,
       Remove,
       Update
   };

   switch (static_cast<Option>(choice)) {
       case Option::Add:
           // Handle add
           break;
   }
   ```

2. **Input Validation**
   ```cpp
   if (value < 1 || value > 5) {
       cout << "Invalid input\n";
       return;
   }
   switch (value) {
       // Process valid input
   }
   ```

3. **Default Case**
   ```cpp
   switch (value) {
       case 1:
           process();
           break;
       default:
           handleUnknown();
           break;
   }
   ```

4. **Document Fall-Through**
   ```cpp
   switch (value) {
       case 1:
           // Fall through intentional
       case 2:
           // Shared handling
           break;
   }
   ```

5. **Group Cases**
   ```cpp
   switch (value) {
       case 'y':
       case 'Y':
           handleYes();
           break;
       case 'n':
       case 'N':
           handleNo();
           break;
   }
   ```

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Study fall-through behavior
5. Practice input validation
6. Implement complex switches
7. Move on to [Part 3: Loops]({{ site.baseurl }}/tutorials/module2/part3-loops)
