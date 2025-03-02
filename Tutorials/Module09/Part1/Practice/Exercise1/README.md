# Exercise 1: Basic Pointer Operations

## Objective
Implement a program that demonstrates basic pointer operations including declaration, initialization, dereferencing, and address-of operations.

## Requirements
1. Create a program that:
   - Declares variables of different data types (int, double, char)
   - Creates pointers to these variables
   - Displays the values and addresses of both the variables and pointers
   - Modifies the values through pointers
   - Shows the updated values

2. Your program should demonstrate:
   - Proper pointer declaration and initialization
   - Dereferencing pointers to access and modify values
   - Proper pointer safety practices
   - Clear output showing the relationship between variables and pointers

## Starter Code
The `pointer_basics_starter.cpp` file contains a skeleton structure for your implementation. Complete the TODOs in the file.

## Expected Output
When run, your program should produce output similar to:
```
===== Integer Pointer =====
Value of num: 42
Address of num: 0x7ffd123456a8
Value of ptr: 0x7ffd123456a8
Value pointed to by ptr: 42
After modification through pointer:
Value of num: 100

===== Double Pointer =====
Value of decimal: 3.14159
Address of decimal: 0x7ffd123456b0
Value of doublePtr: 0x7ffd123456b0
Value pointed to by doublePtr: 3.14159
After modification through pointer:
Value of decimal: 2.71828

===== Character Pointer =====
Value of letter: A
Address of letter: 0x7ffd123456b8
Value of charPtr: 0x7ffd123456b8
Value pointed to by charPtr: A
After modification through pointer:
Value of letter: Z
```

## Hints
- Remember to initialize all pointers before using them
- Use the address-of operator (&) to get the address of a variable
- Use the dereference operator (*) to access the value pointed to by a pointer
- Format your output clearly to show the relationship between variables and pointers

## Testing
Compile and run your program:
```bash
g++ -o pointer_basics pointer_basics_starter.cpp
./pointer_basics
```

## Solution
A completed solution is available in `pointer_basics.cpp` for reference after you've attempted the exercise.
