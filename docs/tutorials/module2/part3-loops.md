---
layout: default
title: Part 3 - Loops
nav_order: 3
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part3-loops/
---

# Part 3: Loops

## Learning Objectives
- Master different types of loops (for, while, do-while)
- Understand loop selection criteria and best practices
- Learn proper loop control and termination
- Implement robust input validation
- Handle loop state and iteration tracking
- Process results effectively
- Create professional user interfaces
- Avoid common loop pitfalls

## Introduction
Loops are fundamental control structures in C++ that enable you to execute code repeatedly based on specific conditions. Think of them like a washing machine cycle:

1. **Why Loops Matter**:
   - **Code Efficiency**: Avoid repetitive code
   - **Data Processing**: Handle multiple items
   - **User Interaction**: Process multiple inputs
   - **Calculations**: Perform iterative computations
   - **Control Flow**: Manage program execution

2. **Real-World Applications**:
   - **Game Loops**: Update game state continuously
   - **Data Processing**: Process large datasets
   - **User Input**: Validate and retry inputs
   - **Animations**: Update screen frames
   - **File Processing**: Read/write data streams

3. **Benefits in Development**:
   - **Reduced Code**: Eliminate repetition
   - **Better Organization**: Structure iterations
   - **Easier Maintenance**: Centralize loop logic
   - **Improved Performance**: Optimize iterations
   - **Better Testing**: Test loop boundaries

4. **Loop Types Overview**:
   - **for**: Known number of iterations
   - **while**: Pre-test condition loop
   - **do-while**: Post-test condition loop
   - **range-based for**: Collection iteration
   - **nested loops**: Complex patterns

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part3/loops_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part3/loops.cpp`.

### Step 1: For Loop Examples
First, let's explore different for loop patterns:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Basic counter loop
    cout << "Counting up:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // Array iteration
    int numbers[] = {10, 20, 30, 40, 50};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    cout << "Sum: " << sum << endl;
    
    // Range-based for loop
    vector<int> scores = {85, 92, 78, 95, 88};
    int total = 0;
    for (int score : scores) {
        total += score;
    }
    cout << "Average: " << total/scores.size() << endl;
    
    // Nested loops for pattern
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    return 0;
}
```

Key Points:
- Initialize counter properly
- Check boundary condition
- Update counter correctly
- Consider loop scope
- Handle array bounds

### Step 2: While Loop Examples
Demonstrate condition-based loops:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Basic while loop
    int count = 1;
    while (count <= 5) {
        cout << count << " ";
        count++;
    }
    cout << endl;
    
    // Input validation
    string password;
    bool valid = false;
    
    while (!valid) {
        cout << "Enter password (min 8 chars): ";
        getline(cin, password);
        
        if (password.length() >= 8) {
            valid = true;
            cout << "Password accepted!" << endl;
        } else {
            cout << "Password too short!" << endl;
        }
    }
    
    // Sentinel-controlled loop
    int sum = 0;
    int number;
    cout << "\nEnter numbers (0 to end):" << endl;
    
    while (true) {
        if (!(cin >> number)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (number == 0) break;
        sum += number;
    }
    
    cout << "Sum: " << sum << endl;
    
    return 0;
}
```

### Step 3: Do-While Loop Examples
Show post-test condition loops:

```cpp
#include <iostream>
using namespace std;

int main() {
    // Menu system
    int choice;
    do {
        // Display menu
        cout << "\nMenu Options:\n";
        cout << "1. New Game\n";
        cout << "2. Load Game\n";
        cout << "3. Settings\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        
        // Get valid input
        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;  // Force loop to continue
            continue;
        }
        
        // Process choice
        switch (choice) {
            case 1:
                cout << "Starting new game...\n";
                break;
            case 2:
                cout << "Loading saved game...\n";
                break;
            case 3:
                cout << "Opening settings...\n";
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    
    return 0;
}
```

Test Cases:
```cpp
// For Loop Test
Input: N/A
Expected Output:
Counting up:
1 2 3 4 5
Sum: 150
Average: 87
* 
* * 
* * *

// While Loop Test
Input: "short" then "password123"
Expected Output:
Password too short!
Enter password (min 8 chars): 
Password accepted!

// Do-While Loop Test
Input: 1, then 4
Expected Output:
Starting new game...
Goodbye!
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module02/Part3/practice_loops_starter.cpp`
- Complete solution: `Tutorials/Module02/Part3/practice_loops.cpp`

### Exercise 1: Number Analyzer
Create a program that:
1. Accepts numbers until sentinel value
2. Calculates:
   - Minimum
   - Maximum
   - Average
   - Sum
3. Validates all input
4. Handles errors
5. Shows statistics

Requirements:
1. Input validation
2. Error messages
3. Running totals
4. Final summary
5. Clean exit

### Exercise 2: Pattern Generator
Implement a pattern generator:
1. Accept dimensions
2. Support patterns:
   - Rectangle
   - Triangle
   - Diamond
3. Validate inputs
4. Use nested loops
5. Format output

Requirements:
1. Size validation
2. Pattern selection
3. Clear display
4. Error handling
5. Multiple patterns

### Exercise 3: Data Processor
Create a data processing system:
1. Read series of values
2. Process data:
   - Filter
   - Transform
   - Aggregate
3. Validate input
4. Show progress
5. Generate report

Requirements:
1. Data validation
2. Progress tracking
3. Error handling
4. Status updates
5. Final report

## Summary

### Key Concepts
1. **For Loop**
   ```cpp
   // Counter-based iteration
   for (int i = 0; i < size; i++) {
       // Known number of iterations
   }
   
   // Range-based for
   for (const auto& item : collection) {
       // Collection iteration
   }
   
   // Nested loops
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           // Grid processing
       }
   }
   ```

2. **While Loop**
   ```cpp
   // Pre-test condition
   while (condition) {
       // Execute while true
   }
   
   // Sentinel-controlled
   while (cin >> value && value != sentinel) {
       // Process until sentinel
   }
   ```

3. **Do-While Loop**
   ```cpp
   // Post-test condition
   do {
       // Always executes once
   } while (condition);
   
   // Menu system
   do {
       displayMenu();
       getChoice();
   } while (choice != exit);
   ```

### Common Pitfalls
1. **Infinite Loops**
   ```cpp
   // Bad: No exit condition
   while (true) {
       // Never ends
   }

   // Good: Clear exit
   while (condition) {
       if (exitCase) break;
       // Update condition
   }
   ```

2. **Off-by-One Errors**
   ```cpp
   // Bad: Array overflow
   for (int i = 1; i <= size; i++) {
       array[i];  // Wrong!
   }

   // Good: Correct bounds
   for (int i = 0; i < size; i++) {
       array[i];  // Safe
   }
   ```

3. **Missing Updates**
   ```cpp
   // Bad: Counter static
   while (count < 10) {
       // count never changes
   }

   // Good: Counter updates
   while (count < 10) {
       process();
       count++;
   }
   ```

### Best Practices
1. **Loop Selection**
   ```cpp
   // For: Known iterations
   for (int i = 0; i < n; i++) {
       // Count-based
   }

   // While: Unknown iterations
   while (!done) {
       // Condition-based
   }
   ```

2. **Input Validation**
   ```cpp
   while (true) {
       if (cin >> value) {
           if (isValid(value)) break;
       }
       handleError();
   }
   ```

3. **Loop Control**
   ```cpp
   bool running = true;
   while (running) {
       if (shouldExit()) {
           running = false;
           continue;
       }
       process();
   }
   ```

4. **Progress Tracking**
   ```cpp
   for (int i = 0; i < total; i++) {
       process(items[i]);
       showProgress(i, total);
   }
   ```

5. **Resource Management**
   ```cpp
   while (processData()) {
       try {
           useResource();
       } catch (...) {
           cleanup();
           break;
       }
   }
   ```

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Study loop optimization
5. Practice nested loops
6. Implement complex patterns
7. Move on to [Part 4: Break and Continue]({{ site.baseurl }}/tutorials/module2/part4-break-continue)
