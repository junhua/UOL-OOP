---
layout: default
title: Part 3 - Dynamic Memory Allocation
nav_order: 3
parent: Module 9 - Pointers and Dynamic Memory
grand_parent: Tutorials
permalink: /tutorials/module9/part3-dynamic-memory/
---

# Part 3: Dynamic Memory Allocation

## Learning Objectives
- Understand the difference between stack and heap memory
- Master dynamic memory allocation with `new` and `delete`
- Implement dynamic arrays with proper memory management
- Learn techniques for resizing dynamic memory
- Avoid common dynamic memory pitfalls
- Introduce smart pointer concepts for safer memory management

## Introduction
Dynamic memory allocation allows programs to request memory during runtime rather than compile time. Think of it like reserving hotel rooms as needed rather than booking all rooms in advance:

1. **Why Dynamic Memory Matters**:
   - **Flexibility**: Allocate exactly what you need when you need it
   - **Efficiency**: Avoid wasting memory on unused space
   - **Scalability**: Handle varying data sizes without fixed limits
   - **Data Structures**: Create complex structures like linked lists and trees
   - **Resource Management**: Control the lifetime of objects

2. **Real-World Parallels**:
   - **Just-in-Time Manufacturing**: Produce items as needed rather than stockpiling
   - **Expandable Buildings**: Add rooms to a structure as requirements grow
   - **Library Book Checkout**: Borrow resources when needed, return when done
   - **Flexible Office Space**: Rent exactly the space required for your team

3. **Benefits in Development**:
   - **Runtime Sizing**: Determine array sizes during execution
   - **Memory Efficiency**: Use only what's necessary
   - **Object Lifetime Control**: Create/destroy objects when needed
   - **Data Structure Implementation**: Build trees, graphs, linked lists
   - **Resource Optimization**: Manage memory for performance-critical applications

## Stack vs. Heap Memory

### Understanding Memory Models

C++ uses two primary regions of memory for storing data:

#### Stack Memory
- **Allocation**: Automatic, managed by the compiler
- **Lifetime**: Follows scope (local variables)
- **Size**: Fixed at compile time, limited
- **Speed**: Very fast allocation/deallocation
- **Management**: Automatic cleanup when variables go out of scope
- **Usage**: Local variables, function parameters, fixed-size objects

```cpp
void function() {
    int number = 42;        // Stack allocation
    double values[10];      // Stack allocation (fixed size array)
    
    // When function ends, all stack variables are automatically deallocated
}
```

#### Heap Memory
- **Allocation**: Manual, using `new`/`delete` (or `malloc`/`free` in C)
- **Lifetime**: Persists until explicitly deallocated
- **Size**: Limited only by available system memory
- **Speed**: Slower than stack allocation
- **Management**: Programmer must handle cleanup
- **Usage**: Large objects, variable-sized data, objects that outlive their scope

```cpp
void function() {
    int* dynamicNumber = new int;       // Heap allocation
    *dynamicNumber = 42;
    
    int* dynamicArray = new int[1000];  // Heap allocation (large array)
    
    // Must manually deallocate or memory will leak
    delete dynamicNumber;
    delete[] dynamicArray;
}
```

### Memory Visualization

```
Memory Layout:

+------------------------+
|       Stack Memory     |
| (grows downward)       |
|                        |
| Local variables        |
| Function parameters    |
| Return addresses       |
+------------------------+
|                        |
|                        |
|    Unused Memory       |
|                        |
|                        |
+------------------------+
|       Heap Memory      |
| (grows upward)         |
|                        |
| Dynamic allocations    |
| (new/delete)           |
+------------------------+
|       Static Data      |
| Global variables       |
| Static variables       |
+------------------------+
|       Code Segment     |
| Program instructions   |
+------------------------+
```

### When to Use Each Type

| Feature | Stack | Heap |
|---------|-------|------|
| Size known at compile time | ✓ | ✗ |
| Large data structures | ✗ | ✓ |
| Speed critical | ✓ | ✗ |
| Variable size | ✗ | ✓ |
| Lifetime beyond scope | ✗ | ✓ |
| Automatic cleanup | ✓ | ✗ |
| Risk of memory leaks | ✗ | ✓ |
| Risk of fragmentation | ✗ | ✓ |

## Dynamic Memory Allocation

### The `new` Operator

The `new` operator allocates memory on the heap and returns a pointer to the allocated memory:

```cpp
// Allocate a single integer
int* ptr = new int;
*ptr = 42;

// Allocate and initialize
int* ptr2 = new int(42);  // Initialized to 42

// Allocate custom types
string* strPtr = new string("Hello");
```

### The `delete` Operator

The `delete` operator deallocates memory that was previously allocated with `new`:

```cpp
int* ptr = new int(42);
// Use ptr...
delete ptr;  // Deallocate memory
ptr = nullptr;  // Good practice: set to nullptr after deletion
```

### Memory Allocation Failure

Memory allocation can fail if there isn't enough memory available:

```cpp
try {
    // Try to allocate a large amount of memory
    int* largeArray = new int[1000000000];  // Might fail
    // Use largeArray...
    delete[] largeArray;
} catch (const std::bad_alloc& e) {
    cerr << "Memory allocation failed: " << e.what() << endl;
}
```

Alternatively, you can use the nothrow version:

```cpp
int* largeArray = new (nothrow) int[1000000000];
if (largeArray == nullptr) {
    cerr << "Memory allocation failed" << endl;
} else {
    // Use largeArray...
    delete[] largeArray;
}
```

## Dynamic Arrays

### Allocating Arrays

To allocate an array dynamically, use the array form of `new`:

```cpp
// Allocate an array of 10 integers
int* numbers = new int[10];

// Initialize all elements to zero
for (int i = 0; i < 10; i++) {
    numbers[i] = 0;
}

// Use the array
numbers[0] = 42;
numbers[1] = 73;
```

### Deallocating Arrays

To deallocate an array, use the array form of `delete`:

```cpp
int* numbers = new int[10];
// Use numbers...
delete[] numbers;  // Note the square brackets
```

**Important**: Always use `delete[]` for arrays and `delete` for single objects. Using the wrong form leads to undefined behavior.

### Initializing Dynamic Arrays

C++11 and later allow initializing dynamic arrays:

```cpp
// C++11 and later
int* numbers = new int[5]{10, 20, 30, 40, 50};

// For objects
string* names = new string[3]{"Alice", "Bob", "Charlie"};
```

### Multi-dimensional Dynamic Arrays

Creating multi-dimensional arrays requires multiple allocations:

```cpp
// Create a 3x4 matrix
int rows = 3;
int cols = 4;

// Allocate array of pointers
int** matrix = new int*[rows];

// Allocate each row
for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
    
    // Initialize row
    for (int j = 0; j < cols; j++) {
        matrix[i][j] = 0;
    }
}

// Access elements
matrix[1][2] = 42;

// Deallocate (in reverse order)
for (int i = 0; i < rows; i++) {
    delete[] matrix[i];  // Delete each row
}
delete[] matrix;  // Delete array of pointers
```

A more efficient approach for contiguous memory:

```cpp
// Create a 3x4 matrix in contiguous memory
int rows = 3;
int cols = 4;

// Allocate all data in one block
int* data = new int[rows * cols];

// Access using calculated offsets
// Element at (i,j) is at data[i*cols + j]
data[1*cols + 2] = 42;  // Set element at row 1, column 2

// Deallocate in one step
delete[] data;
```

## Resizing Dynamic Memory

### Manual Resizing Technique

To resize a dynamic array, you need to:
1. Allocate a new array with the desired size
2. Copy data from the old array to the new one
3. Delete the old array
4. Update the pointer

```cpp
// Resize an array from oldSize to newSize
void resizeArray(int*& arr, int oldSize, int newSize) {
    // Allocate new array
    int* newArr = new int[newSize];
    
    // Determine how many elements to copy
    int copySize = (oldSize < newSize) ? oldSize : newSize;
    
    // Copy elements
    for (int i = 0; i < copySize; i++) {
        newArr[i] = arr[i];
    }
    
    // Initialize new elements if expanding
    for (int i = oldSize; i < newSize; i++) {
        newArr[i] = 0;  // Default initialization
    }
    
    // Delete old array
    delete[] arr;
    
    // Update pointer
    arr = newArr;
}

// Usage
int* numbers = new int[5]{10, 20, 30, 40, 50};
resizeArray(numbers, 5, 10);  // Resize to 10 elements
// numbers now points to a new array of size 10
```

### Preserving Data During Resize

When resizing, be careful to preserve the data:

```cpp
// Expand a dynamic string array
void expandStringArray(string*& arr, int& size) {
    int newSize = size * 2;  // Double the size
    
    // Allocate new array
    string* newArr = new string[newSize];
    
    // Copy existing strings
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];  // String copy
    }
    
    // Delete old array
    delete[] arr;
    
    // Update pointer and size
    arr = newArr;
    size = newSize;
}
```

### Efficiency Considerations

Frequent resizing can be inefficient. Consider:
- Allocating more than immediately needed
- Growing geometrically (e.g., doubling size) rather than incrementally
- Using data structures like `std::vector` that handle resizing automatically

## Introduction to Smart Pointers

### The Problem with Raw Pointers

Raw pointers have several issues:
- No automatic cleanup
- Easy to forget `delete`
- Unclear ownership
- Exception safety problems
- Potential double deletion

### RAII Principle

RAII (Resource Acquisition Is Initialization) is a C++ programming principle:
- Resources are acquired during object initialization
- Resources are released during object destruction
- Ensures proper cleanup even with exceptions

### std::unique_ptr

`std::unique_ptr` is a smart pointer that owns and manages a dynamically allocated object:

```cpp
#include <memory>

// Create a unique_ptr to an integer
std::unique_ptr<int> ptr = std::make_unique<int>(42);  // C++14

// Access the value
cout << *ptr << endl;  // 42

// No need to delete - automatically cleaned up when ptr goes out of scope
```

For arrays:

```cpp
// Create a unique_ptr to an array
std::unique_ptr<int[]> arr = std::make_unique<int[]>(10);

// Use like a normal array
arr[0] = 42;
arr[1] = 73;

// Automatically deleted when arr goes out of scope
```

### std::shared_ptr

`std::shared_ptr` allows multiple pointers to share ownership:

```cpp
#include <memory>

// Create a shared_ptr
std::shared_ptr<int> ptr1 = std::make_shared<int>(42);

// Create another shared_ptr pointing to the same object
std::shared_ptr<int> ptr2 = ptr1;

// Both pointers share ownership
cout << *ptr1 << " " << *ptr2 << endl;  // 42 42

// Object is deleted when the last shared_ptr goes out of scope
```

## Implementation Guide

The `Tutorials/Module09/Part3/Learning/` directory contains starter files to help you learn about dynamic memory:

1. Start with these files:
   - `DynamicMemory_starter.h` and `DynamicMemory_starter.cpp`: Dynamic memory operations
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with basic dynamic allocation:
      - Implement single object allocation/deallocation
      - Practice dynamic array creation
      - Implement proper cleanup
   
   b. Move to advanced operations:
      - Implement array resizing
      - Create multi-dimensional arrays
      - Practice exception handling
   
   c. Complete the main program:
      - Test dynamic memory operations
      - Verify proper behavior
      - Implement memory safety checks

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o dynamic_memory_demo main_starter.cpp DynamicMemory_starter.cpp
   
   # Run and verify output
   ./dynamic_memory_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to track memory allocations

5. Reference Implementation:
   The completed versions (DynamicMemory.h, DynamicMemory.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study dynamic memory patterns
   - Understand best practices

### Step 1: Basic Dynamic Allocation

```cpp
// Demonstrate basic dynamic allocation
void basicDynamicAllocation() {
    // Allocate a single integer
    int* number = new int;
    *number = 42;
    
    cout << "Dynamically allocated number: " << *number << endl;
    
    // Allocate and initialize
    int* initializedNumber = new int(100);
    cout << "Initialized number: " << *initializedNumber << endl;
    
    // Cleanup
    delete number;
    delete initializedNumber;
}

// Expected Output:
// Dynamically allocated number: 42
// Initialized number: 100
```

### Step 2: Dynamic Arrays

```cpp
// Demonstrate dynamic arrays
void dynamicArrays() {
    // Allocate array of 5 integers
    int* numbers = new int[5];
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }
    
    // Display array
    cout << "Dynamic array contents: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Cleanup
    delete[] numbers;
}

// Expected Output:
// Dynamic array contents: 0 10 20 30 40
```

### Step 3: Array Resizing

```cpp
// Resize an array
int* resizeArray(int* oldArray, int oldSize, int newSize) {
    // Allocate new array
    int* newArray = new int[newSize];
    
    // Determine how many elements to copy
    int copySize = (oldSize < newSize) ? oldSize : newSize;
    
    // Copy elements
    for (int i = 0; i < copySize; i++) {
        newArray[i] = oldArray[i];
    }
    
    // Initialize new elements if expanding
    for (int i = oldSize; i < newSize; i++) {
        newArray[i] = 0;
    }
    
    // Delete old array
    delete[] oldArray;
    
    // Return new array
    return newArray;
}

// Usage
void demonstrateResizing() {
    // Create initial array
    int* numbers = new int[5];
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }
    
    cout << "Original array: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Resize to larger array
    numbers = resizeArray(numbers, 5, 8);
    
    cout << "Expanded array: ";
    for (int i = 0; i < 8; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Resize to smaller array
    numbers = resizeArray(numbers, 8, 3);
    
    cout << "Shrunk array: ";
    for (int i = 0; i < 3; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Cleanup
    delete[] numbers;
}

// Expected Output:
// Original array: 0 10 20 30 40
// Expanded array: 0 10 20 30 40 0 0 0
// Shrunk array: 0 10 20
```

### Step 4: Multi-dimensional Arrays

```cpp
// Create and use a 2D matrix
void twoDimensionalArray() {
    int rows = 3;
    int cols = 4;
    
    // Allocate rows
    int** matrix = new int*[rows];
    
    // Allocate columns for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        
        // Initialize row
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;  // Fill with sequential values
        }
    }
    
    // Display matrix
    cout << "2D Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Cleanup (in reverse order)
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Expected Output:
// 2D Matrix:
// 0    1    2    3
// 4    5    6    7
// 8    9    10   11
```

### Step 5: Smart Pointers

```cpp
#include <memory>

// Demonstrate unique_ptr
void demonstrateUniquePtr() {
    // Create a unique_ptr to an integer
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    
    cout << "unique_ptr value: " << *ptr << endl;
    
    // Modify the value
    *ptr = 100;
    cout << "Modified value: " << *ptr << endl;
    
    // Create a unique_ptr to an array
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    
    // Display array
    cout << "unique_ptr array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // No need for explicit cleanup - automatically handled
}

// Demonstrate shared_ptr
void demonstrateSharedPtr() {
    // Create a shared_ptr
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    
    // Create another shared_ptr pointing to the same object
    std::shared_ptr<int> ptr2 = ptr1;
    
    cout << "shared_ptr values: " << *ptr1 << " " << *ptr2 << endl;
    
    // Modify through one pointer
    *ptr1 = 100;
    cout << "After modification: " << *ptr1 << " " << *ptr2 << endl;
    
    // Check reference count
    cout << "Reference count: " << ptr1.use_count() << endl;
    
    // No need for explicit cleanup - automatically handled
}

// Expected Output:
// unique_ptr value: 42
// Modified value: 100
// unique_ptr array: 0 10 20 30 40
// shared_ptr values: 42 42
// After modification: 100 100
// Reference count: 2
```

## Practice Exercises

The `Tutorials/Module09/Part3/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., DynamicMemory_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your dynamic memory operations
      - Define required functions
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement all required methods
      - Add proper memory management
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -o exercise1 main_starter.cpp DynamicMemory_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to track memory
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Dynamic String Manager
Implement a dynamic string manager:

```cpp
// TODO: Implement these functions
char* createString(const char* str);  // Allocate and copy a string
void appendString(char*& str, const char* suffix);  // Append to a string
void truncateString(char*& str, int newLength);  // Truncate a string
void deleteString(char* str);  // Free string memory
```

### Exercise 2: Dynamic Matrix Operations
Create a matrix class with dynamic memory:

```cpp
// TODO: Implement this class
class Matrix {
private:
    int** data;
    int rows;
    int cols;
    
public:
    Matrix(int r, int c);  // Constructor
    ~Matrix();  // Destructor
    
    void setValue(int row, int col, int value);
    int getValue(int row, int col) const;
    void display() const;
    
    // Matrix operations
    Matrix add(const Matrix& other) const;
    Matrix multiply(const Matrix& other) const;
    Matrix transpose() const;
};
```

### Exercise 3: Dynamic Object Array
Implement a dynamic array of objects:

```cpp
// TODO: Implement this class
class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
    
public:
    DynamicArray(int initialCapacity = 10);
    ~DynamicArray();
    
    void add(int value);  // Add element, resize if needed
    void remove(int index);  // Remove element at index
    int get(int index) const;  // Get element at index
    int getSize() const;  // Get current size
    void clear();  // Remove all elements
    
    // Prevent copying (or implement deep copy)
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;
};
```

## Advanced Dynamic Memory Topics

### Placement new

Placement new allows constructing an object at a specific memory location:

```cpp
#include <new>  // For placement new

// Allocate raw memory
char* buffer = new char[sizeof(string)];

// Construct a string in the buffer
string* str = new (buffer) string("Hello, World!");

// Use the string
cout << *str << endl;

// Explicitly call destructor
str->~string();

// Free the raw memory
delete[] buffer;
```

### Custom Memory Allocators

You can create custom allocators for specialized memory management:

```cpp
// Simple memory pool
class MemoryPool {
private:
    char* memory;
    size_t size;
    size_t used;
    
public:
    MemoryPool(size_t poolSize) : size(poolSize), used(0) {
        memory = new char[size];
    }
    
    ~MemoryPool() {
        delete[] memory;
    }
    
    void* allocate(size_t bytes) {
        if (used + bytes > size) {
            return nullptr;  // Out of memory
        }
        
        void* result = memory + used;
        used += bytes;
        return result;
    }
    
    // Simple pool doesn't support individual deallocation
    void reset() {
        used = 0;
    }
};

// Usage
MemoryPool pool(1024);  // 1KB pool

// Allocate from pool
int* numbers = static_cast<int*>(pool.allocate(5 * sizeof(int)));
for (int i = 0; i < 5; i++) {
    numbers[i] = i;
}

// Reset pool when done
pool.reset();
```

### Memory Alignment

Memory alignment is important for performance and correctness:

```cpp
// Aligned allocation (C++17)
void* aligned_ptr = aligned_alloc(64, 1024);  // 1KB aligned to 64 bytes
// Use memory...
free(aligned_ptr);

// C++17 aligned new
struct alignas(64) AlignedData {
    char data[1024];
};

AlignedData* aligned = new AlignedData;
// Use aligned...
delete aligned;
```

## Summary

### Key Concepts

1. **Stack vs. Heap Memory**
   - Stack: automatic, fast, limited size
   - Heap: manual, flexible, unlimited size
   - Stack for local variables
   - Heap for dynamic allocation
   - Each has specific use cases

2. **Dynamic Allocation**
   - `new` for allocation
   - `delete` for deallocation
   - `new[]` for arrays
   - `delete[]` for array deallocation
   - Handle allocation failures

3. **Dynamic Arrays**
   - Flexible size at runtime
   - Multi-dimensional arrays
   - Proper initialization
   - Correct deallocation
   - Resizing techniques

4. **Memory Management**
   - Manual resizing
   - Data preservation
   - Efficiency considerations
   - Exception safety
   - Smart pointers

5. **Smart Pointers**
   - RAII principle
   - `unique_ptr` for exclusive ownership
   - `shared_ptr` for shared ownership
   - Automatic cleanup
   - Memory safety

### Common Pitfalls

1. **Memory Leaks**
   ```cpp
   // Wrong! Missing delete
   void function() {
       int* ptr = new int(42);
       // No delete before function returns
   }
   
   // Correct
   void function() {
       int* ptr = new int(42);
       // Use ptr...
       delete ptr;
   }
   ```

2. **Double Deletion**
   ```cpp
   // Wrong! Double delete
   int* ptr = new int(42);
   delete ptr;
   delete ptr;  // Undefined behavior
   
   // Correct
   int* ptr = new int(42);
   delete ptr;
   ptr = nullptr;  // Set to nullptr after deletion
   ```

3. **Wrong Delete Form**
   ```cpp
   // Wrong! Using delete instead of delete[]
   int* arr = new int[10];
   delete arr;  // Should be delete[] arr
   
   // Correct
   int* arr = new int[10];
   delete[] arr;
   ```

4. **Dangling Pointers**
   ```cpp
   // Wrong! Using pointer after deletion
   int* ptr = new int(42);
   delete ptr;
   *ptr = 100;  // Undefined behavior
   
   // Correct
   int* ptr = new int(42);
   delete ptr;
   ptr = nullptr;  // Set to nullptr after deletion
   ```

5. **Memory Fragmentation**
   ```cpp
   // Wrong! Frequent small allocations/deallocations
   for (int i = 0; i < 1000; i++) {
       int* small = new int[10];
       // Use small...
       delete[] small;
   }
   
   // Better
   int* large = new int[10000];
   for (int i = 0; i < 1000; i++) {
       // Use large[i*10] through large[i*10+9]
   }
   delete[] large;
   ```

### Best Practices
1. Always pair `new` with `delete` and `new[]` with `delete[]`
2. Set pointers to `nullptr` after deletion
3. Use smart pointers when possible
4. Check for allocation failures
5. Be careful with ownership semantics
6. Avoid frequent allocations/deallocations
7. Consider RAII for resource management
8. Use containers like `vector` for dynamic arrays
9. Implement proper copy/move semantics for classes with dynamic memory
10. Use memory debugging tools to detect leaks

## Next Steps
1. Complete all practice exercises
2. Test with various allocation scenarios
3. Review memory management
4. Study smart pointers in depth
5. Move on to [Part 4: Memory Leaks and How to Avoid Them]({{ site.baseurl }}/tutorials/module9/part4-memory-leaks)

Remember: Dynamic memory is powerful but requires careful management. Always ensure proper allocation and deallocation to avoid memory leaks and other issues.
