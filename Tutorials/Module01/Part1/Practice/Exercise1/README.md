# Exercise 1: Personal Information

## Overview
In this exercise, you will create a program that collects personal information from the user, validates the input, and displays it in a formatted card. This exercise will help you practice basic input/output operations, input validation, and formatted output.

## Learning Objectives
- Implement user input with proper validation
- Handle different data types (string, int)
- Process and validate user input
- Create formatted output
- Implement error handling for invalid input

## Requirements

### 1. Input Collection
The program should collect the following information from the user:
- Name (string)
- Age (integer)
- City (string)
- Occupation (string)

### 2. Input Validation
The program should validate all inputs:
- Name, city, and occupation cannot be empty or contain only whitespace
- Age must be a positive number (greater than 0)
- The program should handle invalid input (e.g., non-numeric input for age)
- The program should provide clear error messages for invalid input
- The program should continue asking for input until valid input is provided

### 3. Output Formatting
The program should display the collected information in a formatted card:
```
+-----------------------+
|     PERSONAL INFO     |
+-----------------------+
| Name: John Doe        |
| Age: 25               |
| City: New York        |
| Occupation: Developer |
+-----------------------+
```

## Implementation Steps

1. **Set Up Variables**
   - Declare variables for name, age, city, and occupation
   - Initialize validation flags

2. **Display Welcome Message**
   - Show a welcome message
   - Explain the purpose of the program

3. **Collect and Validate Name**
   - Prompt for name
   - Read input using `getline`
   - Validate that name is not empty
   - Display error message if invalid
   - Repeat until valid input is provided

4. **Collect and Validate Age**
   - Prompt for age
   - Read input using `cin`
   - Validate that age is a positive number
   - Handle non-numeric input
   - Clear input buffer after reading
   - Display error message if invalid
   - Repeat until valid input is provided

5. **Collect and Validate City**
   - Prompt for city
   - Read input using `getline`
   - Validate that city is not empty
   - Display error message if invalid
   - Repeat until valid input is provided

6. **Collect and Validate Occupation**
   - Prompt for occupation
   - Read input using `getline`
   - Validate that occupation is not empty
   - Display error message if invalid
   - Repeat until valid input is provided

7. **Display Formatted Output**
   - Create a formatted card with borders
   - Display all collected information
   - Ensure proper alignment

## Testing

Test your program with the following inputs:

### Test Case 1: Valid Input
```
Name: John Doe
Age: 25
City: New York
Occupation: Developer
```

### Test Case 2: Invalid Age (Non-numeric)
```
Name: Jane Smith
Age: twenty (invalid, should prompt again)
Age: 30
City: Boston
Occupation: Teacher
```

### Test Case 3: Invalid Age (Negative)
```
Name: Bob Johnson
Age: -5 (invalid, should prompt again)
Age: 40
City: Chicago
Occupation: Engineer
```

### Test Case 4: Empty Input
```
Name: (empty, should prompt again)
Name: Alice Brown
Age: 35
City: (empty, should prompt again)
City: Los Angeles
Occupation: (empty, should prompt again)
Occupation: Doctor
```

## Hints
- Use `std::getline()` for reading string input to handle spaces
- Use `std::cin >>` for reading numeric input
- Remember to clear the input buffer after using `std::cin >>` before using `std::getline()`
- Use a loop to continue asking for input until valid input is provided
- Check for empty strings by testing if the length is 0
- For better validation, check if a string contains only whitespace

## Compilation and Execution
```bash
# Compile
g++ -Wall -Wextra -o personal_info personal_info_starter.cpp

# Run
./personal_info
```

## Solution
A complete solution is available in `personal_info.cpp`. Try to implement the program yourself before looking at the solution.
