# Exercise 2: Temperature Converter

## Overview
In this exercise, you will create a temperature conversion utility that allows users to convert temperatures between Celsius, Fahrenheit, and Kelvin. This exercise will help you practice creating a menu-driven interface, implementing mathematical formulas, validating input, and formatting output.

## Learning Objectives
- Implement a menu-driven interface
- Perform temperature conversions using mathematical formulas
- Validate numeric input
- Format output with precision
- Handle multiple conversions in one session
- Implement proper error handling

## Requirements

### 1. Menu Interface
The program should display a menu with the following options:
1. Celsius to Fahrenheit
2. Fahrenheit to Celsius
3. Celsius to Kelvin
4. Kelvin to Celsius
5. Fahrenheit to Kelvin
6. Kelvin to Fahrenheit
0. Exit

### 2. Input Validation
The program should validate all inputs:
- Menu choice must be a number between 0 and 6
- Temperature input must be a valid number
- The program should handle invalid input (e.g., non-numeric input)
- The program should provide clear error messages for invalid input
- The program should continue asking for input until valid input is provided

### 3. Temperature Conversions
The program should implement the following conversion formulas:
- Celsius to Fahrenheit: (C × 9/5) + 32
- Fahrenheit to Celsius: (F - 32) × 5/9
- Celsius to Kelvin: C + 273.15
- Kelvin to Celsius: K - 273.15
- Fahrenheit to Kelvin: (F - 32) × 5/9 + 273.15
- Kelvin to Fahrenheit: (K - 273.15) × 9/5 + 32

### 4. Output Formatting
The program should display the conversion result with:
- Two decimal places of precision
- Appropriate temperature units (°C, °F, K)
- Clear and readable format

### 5. Multiple Conversions
The program should:
- Allow the user to perform multiple conversions in one session
- Ask if the user wants to perform another conversion after each result
- Exit only when the user chooses to exit (option 0 or answering 'n' to continue)

## Implementation Steps

1. **Set Up Variables**
   - Declare variables for menu choice, temperature input, conversion result
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
   - Validate that choice is between 0 and 6
   - Handle non-numeric input
   - Display error message if invalid
   - Repeat until valid input is provided

5. **Implement Temperature Input Validation**
   - Prompt for temperature based on the selected conversion
   - Read input using `cin`
   - Handle non-numeric input
   - Display error message if invalid
   - Repeat until valid input is provided

6. **Implement Conversion Logic**
   - Use a switch statement or if-else chain to handle different conversion options
   - Implement each conversion formula
   - Store the result in a variable

7. **Display Formatted Result**
   - Use `std::fixed` and `std::setprecision` for consistent decimal places
   - Include appropriate units in the output
   - Format the output for readability

8. **Implement Continue Prompt**
   - Ask if the user wants to perform another conversion
   - Validate the input (y/n)
   - Update the loop control variable based on the input

9. **Display Goodbye Message**
   - Show a goodbye message when the user exits

## Testing

Test your program with the following inputs:

### Test Case 1: Celsius to Fahrenheit
```
Menu Choice: 1
Temperature: 25°C
Expected Result: 77.00°F
```

### Test Case 2: Fahrenheit to Celsius
```
Menu Choice: 2
Temperature: 98.6°F
Expected Result: 37.00°C
```

### Test Case 3: Invalid Menu Choice
```
Menu Choice: 9 (invalid, should prompt again)
Menu Choice: a (invalid, should prompt again)
Menu Choice: 3
Temperature: 30°C
Expected Result: 303.15K
```

### Test Case 4: Invalid Temperature Input
```
Menu Choice: 4
Temperature: abc (invalid, should prompt again)
Temperature: 300K
Expected Result: 26.85°C
```

### Test Case 5: Multiple Conversions
```
Menu Choice: 5
Temperature: 32°F
Expected Result: 273.15K
Continue? y
Menu Choice: 6
Temperature: 0K
Expected Result: -459.67°F
Continue? n
```

## Hints
- Use a `do-while` loop for the main program loop
- Use a `switch` statement to handle different menu options
- Remember to clear the input buffer after handling invalid input
- Use `std::fixed` and `std::setprecision(2)` for formatting output to two decimal places
- Consider creating helper functions for input validation and conversions
- Test each conversion formula with known values to ensure accuracy

## Compilation and Execution
```bash
# Compile
g++ -Wall -Wextra -o temp_converter temp_converter_starter.cpp

# Run
./temp_converter
```

## Solution
A complete solution is available in `temp_converter.cpp`. Try to implement the program yourself before looking at the solution.
