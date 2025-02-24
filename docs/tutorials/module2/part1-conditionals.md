---
layout: default
title: Part 1 - Conditional Statements
nav_order: 1
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part1-conditionals/
---

# Part 1: Conditional Statements

## Learning Objectives
- Master conditional statement syntax and usage
- Understand different types of control structures
- Learn condition evaluation and boolean logic
- Practice implementing decision-making logic
- Master input validation techniques
- Implement robust error handling
- Create user-friendly interfaces

## Introduction
Conditional statements are fundamental building blocks that enable programs to make decisions and execute different code paths based on specific conditions. Think of them like traffic signals controlling the flow of vehicles:

1. **Why Conditionals Matter**:
   - **Program Flow**: Direct program execution based on conditions
   - **Decision Making**: Enable programs to respond to different situations
   - **Data Validation**: Verify input correctness
   - **Error Handling**: Manage exceptional cases
   - **User Interaction**: Respond to user choices

2. **Real-World Applications**:
   - **Banking Systems**: Verify account balances for transactions
   - **Games**: Check collision detection and game rules
   - **Web Forms**: Validate user input
   - **Security Systems**: Authenticate users
   - **Control Systems**: Monitor and respond to sensor data

3. **Benefits in Development**:
   - **Reduced Complexity**: Break complex logic into manageable pieces
   - **Better Organization**: Structure code based on conditions
   - **Easier Debugging**: Isolate and fix logical errors
   - **Code Reuse**: Share common validation logic
   - **Better Testing**: Test different execution paths

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part1/conditionals_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part1/conditionals.cpp`.

### Step 1: Basic Conditional Structure
First, let's understand basic if statements:

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    // Simple if statement
    if (number > 0) {
        cout << "Number is positive" << endl;
    }
    
    // if-else statement
    if (number % 2 == 0) {
        cout << "Number is even" << endl;
    } else {
        cout << "Number is odd" << endl;
    }
    
    // if-else if-else chain
    if (number < 0) {
        cout << "Number is negative" << endl;
    } else if (number == 0) {
        cout << "Number is zero" << endl;
    } else {
        cout << "Number is positive" << endl;
    }
    
    return 0;
}
```

Key Points:
- Condition must be boolean expression
- Braces required for multiple statements
- Each branch executes exclusively
- Order matters in else-if chains
- Always consider all cases

### Step 2: Complex Conditions
Implement more sophisticated logic:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;
    bool hasID;
    
    // Get user information
    cout << "Enter name: ";
    getline(cin, name);
    
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Has ID? (1 for yes, 0 for no): ";
    cin >> hasID;
    
    // Complex condition with logical operators
    if (age >= 18 && hasID) {
        cout << name << " can enter the venue" << endl;
        
        // Nested if statement
        if (age >= 21) {
            cout << "Can purchase alcohol" << endl;
        } else {
            cout << "Cannot purchase alcohol" << endl;
        }
    } else {
        cout << name << " cannot enter the venue" << endl;
        
        // Multiple conditions
        if (age < 18) {
            cout << "Must be 18 or older" << endl;
        }
        if (!hasID) {
            cout << "Must have ID" << endl;
        }
    }
    
    return 0;
}
```

### Step 3: Input Validation
Create robust input handling:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int age;
    bool validInput = false;
    
    // Input validation loop
    do {
        cout << "Enter age (0-120): ";
        
        // Check for valid numeric input
        if (cin >> age) {
            // Check range
            if (age >= 0 && age <= 120) {
                validInput = true;
            } else {
                cout << "Age must be between 0 and 120" << endl;
            }
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Process valid input
    if (age >= 18) {
        cout << "Adult" << endl;
    } else if (age >= 13) {
        cout << "Teen" << endl;
    } else {
        cout << "Child" << endl;
    }
    
    return 0;
}
```

Test Cases:
```cpp
Input: 25
Expected: "Adult"

Input: 15
Expected: "Teen"

Input: abc
Expected: "Invalid input. Please enter a number."

Input: -5
Expected: "Age must be between 0 and 120"
```

### Understanding Conditional Logic

#### Basic If Statement
Core Structure:
```cpp
if (condition) {
    // Code executed if condition is true
}

if (condition) {
    // Code for true case
} else {
    // Code for false case
}
```

Key Points:
- Condition must evaluate to boolean
- Braces required for multiple statements
- Single statement can omit braces (not recommended)
- Each branch is mutually exclusive

#### Multiple Conditions
```cpp
if (condition1) {
    // First case
} else if (condition2) {
    // Second case
} else if (condition3) {
    // Third case
} else {
    // Default case
}
```

Important Concepts:
- Conditions checked in order
- First true condition executes
- Default case handles remaining scenarios
- Consider condition overlap

#### Nested Conditions
```cpp
if (outerCondition) {
    if (innerCondition) {
        // Both conditions true
    } else {
        // Only outer condition true
    }
} else {
    // Outer condition false
}
```

Guidelines:
- Limit nesting depth
- Consider extracting complex logic
- Maintain clear indentation
- Document complex cases

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module02/Part1/practice_conditionals_starter.cpp`
- Complete solution: `Tutorials/Module02/Part1/practice_conditionals.cpp`

### Exercise 1: Grade Calculator
Create a program that:
1. Accepts numeric grades (0-100)
2. Validates input
3. Converts to letter grades:
   - A: 90-100
   - B: 80-89
   - C: 70-79
   - D: 60-69
   - F: 0-59
4. Handles invalid input
5. Provides feedback

Requirements:
1. Input validation
2. Clear error messages
3. Proper grade ranges
4. Multiple calculations
5. Exit option

### Exercise 2: Login System
Implement a simple login system:
1. Accept username and password
2. Validate credentials
3. Track login attempts
4. Lock account after failures
5. Provide feedback

Requirements:
1. Store valid credentials
2. Count attempts
3. Clear error messages
4. Account lockout
5. Reset option

### Exercise 3: Number Analyzer
Create a number analysis program:
1. Accept integer input
2. Check properties:
   - Positive/Negative
   - Even/Odd
   - Prime/Composite
3. Validate input
4. Display results
5. Allow multiple checks

Requirements:
1. Input validation
2. Multiple checks
3. Clear output
4. Error handling
5. Exit option

## Summary

### Key Concepts
1. **Basic Conditionals**
   ```cpp
   // Simple if statement
   if (condition) {
       // Execute if true
   }
   
   // if-else statement
   if (condition) {
       // Execute if true
   } else {
       // Execute if false
   }
   
   // if-else chain
   if (condition1) {
       // First case
   } else if (condition2) {
       // Second case
   } else {
       // Default case
   }
   ```

2. **Complex Conditions**
   ```cpp
   // Logical operators
   if (age >= 18 && hasID) {
       // Adult with ID
   }
   
   // Nested conditions
   if (isLoggedIn) {
       if (isAdmin) {
           // Admin access
       } else {
           // User access
       }
   }
   ```

3. **Input Validation**
   ```cpp
   // Validate numeric input
   while (!(cin >> value)) {
       cout << "Invalid input\n";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   
   // Range validation
   if (value >= min && value <= max) {
       // Valid range
   }
   ```

### Common Pitfalls
1. **Missing Input Validation**
   ```cpp
   // Bad: No validation
   int age;
   cin >> age;  // Could fail

   // Good: Validate input
   while (!(cin >> age) || age < 0) {
       cout << "Invalid age\n";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   ```

2. **Complex Nesting**
   ```cpp
   // Bad: Deep nesting
   if (a) {
       if (b) {
           if (c) { /* Too deep */ }
       }
   }

   // Good: Flatten logic
   if (!a) return;
   if (!b) return;
   if (!c) return;
   // Main logic here
   ```

3. **Condition Overlap**
   ```cpp
   // Bad: Overlapping conditions
   if (score >= 90) grade = 'A';
   if (score >= 80) grade = 'B';  // Bug!

   // Good: Mutually exclusive
   if (score >= 90) grade = 'A';
   else if (score >= 80) grade = 'B';
   ```

### Best Practices
1. **Clear Conditions**
   ```cpp
   // Use meaningful names
   bool isEligible(int age, bool hasID) {
       return age >= 18 && hasID;
   }
   
   if (isEligible(userAge, userHasID)) {
       // Process eligible user
   }
   ```

2. **Input Validation**
   ```cpp
   bool getValidAge(int& age) {
       while (!(cin >> age) || age < 0) {
           cout << "Invalid age\n";
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
       return true;
   }
   ```

3. **Error Handling**
   ```cpp
   if (!isValid(input)) {
       cerr << "Error: ";
       if (input < min) cerr << "Too small";
       if (input > max) cerr << "Too large";
       cerr << endl;
       return false;
   }
   ```

4. **Documentation**
   ```cpp
   // Check purchase eligibility:
   // 1. Must be adult (18+)
   // 2. Must have valid ID
   // 3. Must have funds
   if (age >= 18 && hasID && balance >= price) {
       processPurchase();
   }
   ```

5. **Consistent Style**
   ```cpp
   // Always use braces
   if (condition) {
       doSomething();
       doAnotherThing();
   } else {
       handleAlternative();
   }
   ```

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Review error handling strategies
5. Study logical operators and complex conditions
6. Practice nested conditions
7. Move on to [Part 2: Switch Statements]({{ site.baseurl }}/tutorials/module2/part2-switch)

[Continue to Part 2: Switch Statements]({{ site.baseurl }}/tutorials/module2/part2-switch)
