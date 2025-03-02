# Exercise 3: Interactive Calculator

## Overview
In this exercise, you will create a full-featured calculator application that supports basic and advanced operations, memory functions, and operation history. This exercise will help you practice creating a complex menu-driven interface, implementing mathematical operations, validating input, and managing program state.

## Learning Objectives
- Implement a comprehensive menu-driven interface
- Perform various mathematical operations
- Implement memory storage and recall functions
- Create and manage an operation history
- Validate numeric input and handle errors
- Format output for readability
- Implement proper error handling for edge cases

## Requirements

### 1. Menu Interface
The program should display a menu with the following options:
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Power
6. Square Root
7. Store to Memory
8. Recall from Memory
9. Clear Memory
10. Show History
0. Exit

### 2. Input Validation
The program should validate all inputs:
- Menu choice must be a number between 0 and 10
- Operands must be valid numbers
- The program should handle invalid input (e.g., non-numeric input)
- The program should provide clear error messages for invalid input
- The program should continue asking for input until valid input is provided

### 3. Mathematical Operations
The program should implement the following operations:
- Addition: Calculate the sum of two numbers
- Subtraction: Calculate the difference between two numbers
- Multiplication: Calculate the product of two numbers
- Division: Calculate the quotient of two numbers
- Power: Calculate one number raised to the power of another
- Square Root: Calculate the square root of a number

### 4. Memory Functions
The program should implement the following memory functions:
- Store to Memory: Store the current result in memory
- Recall from Memory: Retrieve the value stored in memory
- Clear Memory: Reset the memory to zero

### 5. Operation History
The program should:
- Keep track of all operations performed
- Display the operation history when requested
- Show each operation with its operands and result

### 6. Error Handling
The program should handle the following error conditions:
- Division by zero
- Invalid input (non-numeric)
- Square root of negative numbers
- Other mathematical errors

### 7. Multiple Operations
The program should:
- Allow the user to perform multiple operations in one session
- Ask if the user wants to perform another operation after each result
- Exit only when the user chooses to exit (option 0 or answering 'n' to continue)

## Implementation Steps

1. **Set Up Variables**
   - Declare variables for menu choice, operands, result
   - Initialize memory to zero
   - Create a vector to store operation history
   - Initialize a boolean flag to control the main program loop

2. **Display Welcome Message**
   - Show a welcome message
   - Explain the purpose of the program

3. **Implement Main Program Loop**
   - Continue until the user chooses to exit
   - Display the menu options
   - Get and validate the user's choice
   - Process the choice accordingly

4. **Implement Menu Choice Validation**
   - Prompt for menu choice
   - Read input using `cin`
   - Validate that choice is between 0 and 10
   - Handle non-numeric input
   - Display error message if invalid
   - Repeat until valid input is provided

5. **Implement Operand Input Validation**
   - Prompt for operand(s) based on the selected operation
   - Read input using `cin`
   - Handle non-numeric input
   - Display error message if invalid
   - Repeat until valid input is provided

6. **Implement Operation Logic**
   - Use a switch statement to handle different operation options
   - Implement each mathematical operation
   - Handle special cases (e.g., division by zero)
   - Store the result
   - Add the operation to history

7. **Implement Memory Functions**
   - Store the current result in memory
   - Recall the value from memory
   - Clear the memory

8. **Implement History Function**
   - Add each operation to the history vector
   - Display the history when requested
   - Format the history for readability

9. **Display Formatted Result**
   - Use `std::fixed` and `std::setprecision` for consistent decimal places
   - Format the output for readability

10. **Implement Continue Prompt**
    - Ask if the user wants to perform another operation
    - Validate the input (y/n)
    - Update the loop control variable based on the input

11. **Display Goodbye Message**
    - Show a goodbye message when the user exits

## Testing

Test your program with the following inputs:

### Test Case 1: Basic Operations
```
Menu Choice: 1 (Addition)
Operand 1: 5
Operand 2: 3
Expected Result: 8.00

Menu Choice: 2 (Subtraction)
Operand 1: 10
Operand 2: 4
Expected Result: 6.00

Menu Choice: 3 (Multiplication)
Operand 1: 6
Operand 2: 7
Expected Result: 42.00

Menu Choice: 4 (Division)
Operand 1: 20
Operand 2: 5
Expected Result: 4.00
```

### Test Case 2: Advanced Operations
```
Menu Choice: 5 (Power)
Operand 1: 2
Operand 2: 3
Expected Result: 8.00

Menu Choice: 6 (Square Root)
Operand: 16
Expected Result: 4.00
```

### Test Case 3: Error Handling
```
Menu Choice: 4 (Division)
Operand 1: 10
Operand 2: 0
Expected Result: Error message about division by zero

Menu Choice: 6 (Square Root)
Operand: -4
Expected Result: Error message about square root of negative number
```

### Test Case 4: Memory Functions
```
Menu Choice: 1 (Addition)
Operand 1: 5
Operand 2: 3
Result: 8.00

Menu Choice: 7 (Store to Memory)
Expected Result: Value 8.00 stored in memory

Menu Choice: 9 (Clear Memory)
Expected Result: Memory cleared

Menu Choice: 8 (Recall from Memory)
Expected Result: 0.00 (or message indicating memory is empty)
```

### Test Case 5: History Function
```
Perform several operations, then:
Menu Choice: 10 (Show History)
Expected Result: List of all operations performed with their results
```

## Hints
- Use a `do-while` loop for the main program loop
- Use a `switch` statement to handle different menu options
- Remember to clear the input buffer after handling invalid input
- Use `std::fixed` and `std::setprecision(2)` for formatting output to two decimal places
- Consider creating helper functions for input validation and operations
- Use a `std::vector<std::string>` to store the operation history
- Use `std::stringstream` to format history entries
- Check for special cases before performing operations (e.g., division by zero)

## Compilation and Execution
```bash
# Compile
g++ -Wall -Wextra -o calculator calculator_starter.cpp

# Run
./calculator
```

## Solution
A complete solution is available in `calculator.cpp`. Try to implement the program yourself before looking at the solution.
