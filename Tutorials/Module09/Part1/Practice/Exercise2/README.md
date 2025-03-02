# Exercise 2: Pointer Safety and Null Pointers

## Objective
Implement a program that demonstrates safe pointer usage, including null pointer handling, pointer validation, and common pointer safety practices.

## Requirements
1. Create a program that:
   - Demonstrates proper initialization of pointers
   - Shows how to check for null pointers before dereferencing
   - Illustrates common pointer safety issues and how to avoid them
   - Demonstrates reassigning pointers and proper cleanup

2. Your program should include:
   - A function that safely uses a potentially null pointer
   - A function that demonstrates pointer reassignment
   - A function that shows how to avoid dangling pointers
   - Clear output explaining each safety practice

## Starter Code
The `pointer_safety_starter.cpp` file contains a skeleton structure for your implementation. Complete the TODOs in the file.

## Expected Output
When run, your program should produce output similar to:
```
===== Null Pointer Safety =====
Pointer is null, cannot dereference
After initialization:
Value pointed to by ptr: 42

===== Pointer Validation =====
Checking pointer before use...
Pointer is valid, value: 100
Setting pointer to null
Checking pointer before use...
Pointer is null, cannot access value

===== Avoiding Dangling Pointers =====
Created dynamic integer with value: 25
Using the pointer: 25
Deleting the pointer
Setting pointer to null after deletion
Checking if pointer is null: Yes
```

## Hints
- Always initialize pointers to either a valid address or nullptr
- Check if a pointer is null before dereferencing it
- Set pointers to nullptr after deleting what they point to
- Be careful when reassigning pointers to avoid memory leaks
- Use clear and consistent null checking patterns

## Testing
Compile and run your program:
```bash
g++ -o pointer_safety pointer_safety_starter.cpp
./pointer_safety
```

## Solution
A completed solution is available in `pointer_safety.cpp` for reference after you've attempted the exercise.
