---
layout: default
title: Part 4 - Break and Continue Statements
nav_order: 4
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part4-break-continue/
---

# Part 4: Break and Continue Statements

## Learning Objectives
- Master break and continue statement usage
- Understand proper loop control flow
- Learn when to use each control statement
- Implement robust error handling
- Practice nested loop control
- Create efficient loop structures
- Avoid common control flow pitfalls

## Introduction
Break and continue statements provide precise control over loop execution. Think of them like:

1. **Why Control Statements Matter**:
   - **Flow Control**: Direct program execution efficiently
   - **Error Handling**: Handle exceptional cases gracefully
   - **Performance**: Skip unnecessary iterations
   - **Code Structure**: Implement complex logic clearly
   - **Resource Management**: Control resource usage

2. **Real-World Applications**:
   - **Search Operations**: Exit when item found
   - **Input Validation**: Skip invalid data
   - **Data Processing**: Filter unwanted items
   - **Game Logic**: Handle special conditions
   - **Resource Management**: Early termination

3. **Benefits in Development**:
   - **Cleaner Code**: Avoid nested conditions
   - **Better Performance**: Skip unnecessary work
   - **Easier Debugging**: Clear flow control
   - **Resource Efficiency**: Early exit paths
   - **Better Organization**: Structured control flow

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part4/control_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part4/control.cpp`.

### Step 1: Break Statement Examples
First, let's explore break usage:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Early exit example
    vector<int> numbers = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    bool found = false;
    
    for (int num : numbers) {
        if (num == target) {
            found = true;
            cout << "Found " << target << "!" << endl;
            break;  // Exit loop early
        }
        cout << "Checking " << num << "..." << endl;
    }
    
    if (!found) {
        cout << target << " not found." << endl;
    }
    
    // Nested loop break
    const int ROWS = 3;
    const int COLS = 4;
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    target = 6;
    found = false;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == target) {
                cout << "Found at position [" << i << "][" << j << "]" << endl;
                found = true;
                break;  // Exits inner loop only
            }
        }
        if (found) break;  // Exits outer loop
    }
    
    return 0;
}
```

### Step 2: Continue Statement Examples
Demonstrate continue usage:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Skip processing example
    vector<int> numbers = {1, -2, 3, -4, 5, -6, 7, -8};
    int positiveSum = 0;
    
    for (int num : numbers) {
        if (num < 0) {
            cout << "Skipping " << num << endl;
            continue;  // Skip negative numbers
        }
        positiveSum += num;
    }
    
    cout << "Sum of positive numbers: " << positiveSum << endl;
    
    // Input validation with continue
    int sum = 0;
    int count = 0;
    
    cout << "Enter 5 positive numbers:" << endl;
    while (count < 5) {
        int value;
        cout << "Number " << (count + 1) << ": ";
        
        if (!(cin >> value)) {
            cout << "Invalid input! Enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (value <= 0) {
            cout << "Please enter a positive number." << endl;
            continue;
        }
        
        sum += value;
        count++;
    }
    
    cout << "Average: " << static_cast<double>(sum) / count << endl;
    
    return 0;
}
```

### Step 3: Combined Control Flow
Show complex control flow:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;
    bool success = false;
    
    while (attempts < MAX_ATTEMPTS) {
        cout << "Enter password: ";
        getline(cin, password);
        attempts++;
        
        // Skip empty input
        if (password.empty()) {
            cout << "Empty input not allowed!" << endl;
            continue;
        }
        
        // Check password strength
        if (password.length() < 8) {
            cout << "Password too short!" << endl;
            continue;
        }
        
        // Check for required characters
        bool hasUpper = false, hasLower = false, hasDigit = false;
        
        for (char c : password) {
            if (isupper(c)) hasUpper = true;
            if (islower(c)) hasLower = true;
            if (isdigit(c)) hasDigit = true;
            
            if (hasUpper && hasLower && hasDigit) {
                success = true;
                break;  // Found all required characters
            }
        }
        
        if (success) {
            cout << "Password accepted!" << endl;
            break;  // Exit main loop
        } else {
            cout << "Password must contain uppercase, lowercase, and digit" << endl;
        }
    }
    
    if (!success) {
        cout << "Maximum attempts exceeded!" << endl;
    }
    
    return 0;
}
```

Test Cases:
```cpp
// Break Example Test
Input: N/A
Expected Output:
Checking 1...
Checking 3...
Checking 5...
Found 7!

// Continue Example Test
Input: 1, -2, 3, 4, 5
Expected Output:
Skipping -2
Sum of positive numbers: 13

// Combined Flow Test
Input: "pass", "password", "Password123"
Expected Output:
Password too short!
Password must contain uppercase, lowercase, and digit
Password accepted!
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module02/Part4/practice_control_starter.cpp`
- Complete solution: `Tutorials/Module02/Part4/practice_control.cpp`

### Exercise 1: Data Filter
Create a data filtering system:
1. Process array of values
2. Filter based on criteria:
   - Range validation
   - Type checking
   - Pattern matching
3. Skip invalid items
4. Collect valid data
5. Report statistics

Requirements:
1. Use continue for filtering
2. Track processed items
3. Handle invalid data
4. Generate summary
5. Optimize performance

### Exercise 2: Search System
Implement a search algorithm:
1. Search multiple arrays
2. Support criteria:
   - Exact match
   - Range match
   - Pattern match
3. Exit early on find
4. Handle not found
5. Report results

Requirements:
1. Use break efficiently
2. Handle nested searches
3. Track search path
4. Provide feedback
5. Optimize search

### Exercise 3: Input Processor
Create an input processing system:
1. Accept multiple inputs
2. Validate each input:
   - Format check
   - Range check
   - Type check
3. Process valid data
4. Skip invalid data
5. Generate report

Requirements:
1. Robust validation
2. Clear feedback
3. Error recovery
4. Progress tracking
5. Final summary

## Summary

### Key Concepts
1. **Break Statement**
   ```cpp
   // Early exit from loop
   for (int i = 0; i < size; i++) {
       if (found) break;  // Exit loop
       process(data[i]);
   }
   
   // Nested loop control
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           if (found) {
               found = true;
               break;  // Exit inner loop
           }
       }
       if (found) break;  // Exit outer loop
   }
   ```

2. **Continue Statement**
   ```cpp
   // Skip current iteration
   for (const auto& item : items) {
       if (!valid(item)) {
           continue;  // Skip to next item
       }
       process(item);
   }
   
   // Input validation
   while (true) {
       if (!validInput()) {
           continue;  // Retry input
       }
       processInput();
   }
   ```

3. **Control Flow Patterns**
   ```cpp
   // Combined control
   while (processData()) {
       if (shouldSkip()) {
           continue;  // Skip processing
       }
       if (isDone()) {
           break;    // Exit processing
       }
       // Normal processing
   }
   ```

### Common Pitfalls
1. **Breaking Wrong Loop**
   ```cpp
   // Bad: Only breaks inner loop
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           if (found) break;  // Wrong!
       }
   }

   // Good: Control both loops
   bool found = false;
   for (int i = 0; i < rows && !found; i++) {
       for (int j = 0; j < cols; j++) {
           if (match) {
               found = true;
               break;
           }
       }
   }
   ```

2. **Infinite Loops**
   ```cpp
   // Bad: Continue skips increment
   while (count < max) {
       if (error) continue;  // Infinite!
       count++;
   }

   // Good: Proper control
   while (count < max) {
       if (error) {
           handleError();
           continue;
       }
       process();
       count++;
   }
   ```

3. **Resource Management**
   ```cpp
   // Bad: Resource leak
   while (processData()) {
       if (error) break;  // Leak!
   }

   // Good: Cleanup
   while (processData()) {
       if (error) {
           cleanup();
           break;
       }
   }
   ```

### Best Practices
1. **Clear Intent**
   ```cpp
   for (const auto& item : items) {
       // Skip invalid items
       if (!valid(item)) continue;
       
       // Exit on match
       if (matches(item)) break;
       
       process(item);
   }
   ```

2. **Resource Safety**
   ```cpp
   while (processData()) {
       try {
           if (error) {
               cleanup();
               break;
           }
       } catch (...) {
           cleanup();
           throw;
       }
   }
   ```

3. **Loop Control**
   ```cpp
   bool found = false;
   for (int i = 0; i < size && !found; i++) {
       if (match(data[i])) {
           found = true;
           break;
       }
   }
   ```

4. **Error Handling**
   ```cpp
   while (true) {
       try {
           if (!valid()) continue;
           if (done()) break;
           process();
       } catch (const Error& e) {
           handleError();
       }
   }
   ```

5. **Progress Tracking**
   ```cpp
   int processed = 0;
   for (const auto& item : items) {
       if (skip(item)) {
           logSkip(item);
           continue;
       }
       process(item);
       showProgress(++processed);
   }
   ```

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Study control flow patterns
5. Practice nested loops
6. Implement complex algorithms
7. Move on to [Part 5: Simple Program Examples]({{ site.baseurl }}/tutorials/module2/part5-examples)
