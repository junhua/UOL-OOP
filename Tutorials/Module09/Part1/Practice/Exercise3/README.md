# Exercise 3: Void Pointers and Type Casting

## Objective
Implement a program that demonstrates the use of void pointers and type casting to work with different data types using a single pointer.

## Requirements
1. Create a program that:
   - Declares a void pointer
   - Uses the void pointer to point to variables of different data types
   - Demonstrates proper type casting to access and modify values
   - Shows the flexibility and limitations of void pointers

2. Your program should include:
   - A function that demonstrates using a void pointer with integers
   - A function that demonstrates using a void pointer with doubles
   - A function that demonstrates using a void pointer with characters
   - A function that demonstrates a generic print function using void pointers
   - Clear output explaining each operation

## Starter Code
The `void_pointers_starter.cpp` file contains a skeleton structure for your implementation. Complete the TODOs in the file.

## Expected Output
When run, your program should produce output similar to:
```
===== Void Pointer with Integer =====
Integer value: 42
After modification through void pointer:
Integer value: 100

===== Void Pointer with Double =====
Double value: 3.14159
After modification through void pointer:
Double value: 2.71828

===== Void Pointer with Character =====
Character value: A
After modification through void pointer:
Character value: Z

===== Generic Print Function =====
Integer: 100
Double: 2.71828
Character: Z
```

## Hints
- Remember that void pointers cannot be dereferenced directly
- You must cast a void pointer to the appropriate type before dereferencing
- Use static_cast<type*>(voidPtr) for type-safe casting
- Be careful with pointer arithmetic on void pointers (it's not allowed directly)
- Void pointers are useful for creating generic functions that work with multiple types

## Testing
Compile and run your program:
```bash
g++ -o void_pointers void_pointers_starter.cpp
./void_pointers
```

## Solution
A completed solution is available in `void_pointers.cpp` for reference after you've attempted the exercise.
