---
layout: default
title: Part 4 - Memory Leaks and How to Avoid Them
nav_order: 4
parent: Module 9 - Pointers and Dynamic Memory
grand_parent: Tutorials
permalink: /tutorials/module9/part4-memory-leaks/
---

# Part 4: Memory Leaks and How to Avoid Them

## Learning Objectives
- Understand what memory leaks are and why they're problematic
- Identify common causes of memory leaks in C++ programs
- Master debugging techniques for detecting memory issues
- Implement resource management patterns to prevent leaks
- Apply the RAII principle for automatic resource management
- Learn to use memory leak detection tools effectively
- Practice writing leak-free code with proper cleanup

## Introduction
Memory leaks occur when a program allocates memory but fails to release it when no longer needed. Think of it like leaving the water running in your home:

1. **Why Memory Leaks Matter**:
   - **Resource Depletion**: Programs gradually consume more memory
   - **Performance Degradation**: System slows as available memory decreases
   - **Crashes**: Eventually, memory allocation may fail
   - **Reliability Issues**: Long-running applications become unstable
   - **Scalability Problems**: Affects system's ability to handle increased load

2. **Real-World Parallels**:
   - **Water Leaks**: Slow drips that eventually flood a house
   - **Gas Leaks**: Invisible but dangerous accumulation
   - **Inventory Shrinkage**: Items checked out but never returned
   - **Resource Hoarding**: Claiming resources without releasing them

3. **Benefits of Leak-Free Code**:
   - **Stability**: Programs run reliably for extended periods
   - **Performance**: Consistent memory usage over time
   - **Scalability**: Handles varying workloads efficiently
   - **Maintainability**: Easier to understand and modify
   - **Professionalism**: Mark of quality engineering

## Understanding Memory Leaks

### What Is a Memory Leak?

A memory leak occurs when dynamically allocated memory is no longer needed but not properly deallocated, making it unavailable for reuse:

```cpp
void createLeak() {
    int* data = new int[1000];  // Allocate memory
    
    // Use data...
    
    // Missing: delete[] data;
    // Memory remains allocated but inaccessible after function returns
}

int main() {
    while (true) {
        createLeak();  // Repeatedly leaks memory
        // Eventually, the program will run out of memory
    }
}
```

### Memory Leak Visualization

```
Memory Before Leak:
+------------------------+
|       Heap Memory      |
|                        |
| +------------------+   |
| |    Available     |   |
| |                  |   |
| +------------------+   |
|                        |
+------------------------+

Memory After Multiple Leaks:
+------------------------+
|       Heap Memory      |
|                        |
| +------------------+   |
| | Leaked Block 1   |   |
| +------------------+   |
| | Leaked Block 2   |   |
| +------------------+   |
| | Leaked Block 3   |   |
| +------------------+   |
| |    Available     |   |
| |    (shrinking)   |   |
| +------------------+   |
|                        |
+------------------------+
```

### Impact of Memory Leaks

Memory leaks can have several negative effects:

1. **Gradual Memory Consumption**:
   - Program uses more memory over time
   - Available system memory decreases
   - Other applications may be affected

2. **Performance Degradation**:
   - Memory paging increases
   - Cache efficiency decreases
   - System becomes less responsive

3. **Program Failure**:
   - Eventually, memory allocation fails
   - Program crashes when `new` throws `std::bad_alloc`
   - System may become unstable

4. **Difficult to Diagnose**:
   - Problems may only appear after extended runtime
   - Intermittent failures are hard to reproduce
   - Root cause may be far from where symptoms appear

## Common Causes of Memory Leaks

### 1. Forgetting to Delete

The most straightforward cause is simply forgetting to deallocate memory:

```cpp
// Memory leak: allocated but never freed
void forgetfulFunction() {
    int* numbers = new int[100];
    // Use numbers...
    
    // Missing: delete[] numbers;
}
```

### 2. Early Returns and Exceptions

Early function exits can bypass cleanup code:

```cpp
// Memory leak due to early return
bool processData(const char* filename) {
    int* data = new int[1000];
    
    if (!loadFile(filename)) {
        return false;  // Leak: data not deleted on this path
    }
    
    // Process data...
    
    delete[] data;
    return true;
}
```

Similarly, exceptions can cause leaks if not properly handled:

```cpp
// Memory leak due to exception
void riskyFunction() {
    int* data = new int[1000];
    
    // If processData throws an exception, data is never deleted
    processData(data);
    
    delete[] data;
}
```

### 3. Losing the Pointer

Overwriting or losing the only pointer to allocated memory creates a leak:

```cpp
// Memory leak due to pointer reassignment
void losingPointer() {
    int* ptr = new int[100];  // First allocation
    
    // Overwrite pointer without freeing original memory
    ptr = new int[200];  // Second allocation, first block now leaked
    
    delete[] ptr;  // Only frees the second allocation
}
```

### 4. Circular References

With manual memory management, circular references can cause leaks:

```cpp
class Node {
public:
    Node* next;
    
    Node() : next(nullptr) {}
    
    ~Node() {
        // Does not delete next
    }
};

// Memory leak due to circular reference
void createCircularLeak() {
    Node* a = new Node();
    Node* b = new Node();
    
    a->next = b;
    b->next = a;  // Circular reference
    
    delete a;  // Only deletes a, not b
    // b is now leaked
}
```

### 5. Improper Custom Destructors

Classes with dynamic memory need proper destructors:

```cpp
// Memory leak in class with improper destructor
class StringHolder {
private:
    char* data;
    
public:
    StringHolder(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    
    // Missing or improper destructor
    // ~StringHolder() { delete[] data; }
};

void useStringHolder() {
    StringHolder* holder = new StringHolder("Hello");
    delete holder;  // Deletes the holder but not the char array inside
}
```

## Debugging Memory Leaks

### Manual Tracking

For small programs, you can manually track allocations and deallocations:

```cpp
// Simple memory tracking
class MemoryTracker {
private:
    static int allocations;
    
public:
    static void allocate() {
        allocations++;
        std::cout << "Allocation: " << allocations << " active" << std::endl;
    }
    
    static void deallocate() {
        allocations--;
        std::cout << "Deallocation: " << allocations << " active" << std::endl;
    }
    
    static void report() {
        std::cout << "Memory report: " << allocations << " active allocations" << std::endl;
        if (allocations > 0) {
            std::cout << "WARNING: Memory leak detected!" << std::endl;
        }
    }
};

int MemoryTracker::allocations = 0;

// Usage
int* ptr = new int[10];
MemoryTracker::allocate();

// Later
delete[] ptr;
MemoryTracker::deallocate();

// At program end
MemoryTracker::report();
```

### Using Debugging Tools

#### Valgrind

Valgrind is a powerful tool for detecting memory leaks on Linux and macOS:

```bash
# Compile with debugging information
g++ -g -o myprogram myprogram.cpp

# Run with Valgrind
valgrind --leak-check=full ./myprogram
```

Sample Valgrind output:

```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 1,024 bytes in 1 blocks
==12345==   total heap usage: 2 allocs, 1 frees, 2,048 bytes allocated
==12345== 
==12345== 1,024 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x4C2B0E0: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12345==    by 0x400781: main (myprogram.cpp:15)
```

#### Address Sanitizer (ASan)

Modern compilers include Address Sanitizer for detecting memory issues:

```bash
# Compile with Address Sanitizer
g++ -fsanitize=address -g -o myprogram myprogram.cpp

# Run normally
./myprogram
```

Sample ASan output:

```
==12345==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 1024 byte(s) in 1 object(s) allocated from:
    #0 0x7f7f7f7f7f7f in operator new[](unsigned long) (/lib/x86_64-linux-gnu/libasan.so.4+0x7f7f7)
    #1 0x400781 in main myprogram.cpp:15

SUMMARY: AddressSanitizer: 1024 byte(s) leaked in 1 allocation(s).
```

#### Visual Studio Memory Leak Detection

In Visual Studio, you can use the built-in memory leak detection:

```cpp
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    // Your code with potential leaks
    int* leak = new int[10];
    
    return 0;  // Memory leak report generated at exit
}
```

Output in Visual Studio Output window:

```
Detected memory leaks!
Dumping objects ->
{18} normal block at 0x00000000023D5D50, 40 bytes long.
 Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
```

## Resource Management Patterns

### RAII Principle

RAII (Resource Acquisition Is Initialization) is a C++ programming principle where:
- Resources are acquired during object initialization
- Resources are released during object destruction
- Ensures proper cleanup even with exceptions

```cpp
// RAII wrapper for dynamic arrays
template <typename T>
class ArrayWrapper {
private:
    T* data;
    
public:
    ArrayWrapper(size_t size) {
        data = new T[size];
    }
    
    ~ArrayWrapper() {
        delete[] data;  // Automatic cleanup
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index];
    }
};

// Usage - no explicit cleanup needed
void useArray() {
    ArrayWrapper<int> numbers(100);
    
    // Use numbers...
    numbers[0] = 42;
    
    // ArrayWrapper destructor automatically called when numbers goes out of scope
}
```

### Smart Pointers

Modern C++ provides smart pointers that implement RAII for dynamic memory:

#### std::unique_ptr

For exclusive ownership:

```cpp
#include <memory>

void useUniquePtr() {
    // Create a unique_ptr to an integer
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    
    // Use ptr like a regular pointer
    *ptr = 100;
    
    // No need to delete - automatically cleaned up
}

// For arrays
void useUniqueArray() {
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(100);
    
    // Use like a regular array
    arr[0] = 42;
    
    // Automatically deleted when arr goes out of scope
}
```

#### std::shared_ptr

For shared ownership:

```cpp
#include <memory>

void useSharedPtr() {
    // Create a shared_ptr
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    
    {
        // Create another shared_ptr pointing to the same object
        std::shared_ptr<int> ptr2 = ptr1;
        
        // Both pointers share ownership
        *ptr2 = 100;
        
        // ptr2 goes out of scope here, but memory isn't freed yet
    }
    
    // Memory is still accessible through ptr1
    std::cout << *ptr1 << std::endl;  // 100
    
    // Memory freed when ptr1 goes out of scope
}
```

#### std::weak_ptr

For breaking circular references:

```cpp
#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // Weak reference to avoid circular dependency
    
    void setData(int val) {
        data = val;
    }
    
private:
    int data;
};

void useWeakPtr() {
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();
    
    node1->next = node2;  // Strong reference
    node2->prev = node1;  // Weak reference
    
    // No memory leak when nodes go out of scope
}
```

### Custom Deleters

Smart pointers can use custom deleters for special cleanup:

```cpp
#include <memory>
#include <fstream>

void useCustomDeleter() {
    // Custom deleter for file handles
    auto fileDeleter = [](std::FILE* file) {
        std::fclose(file);
        std::cout << "File closed" << std::endl;
    };
    
    // Open file and create smart pointer with custom deleter
    std::shared_ptr<std::FILE> file(std::fopen("data.txt", "r"), fileDeleter);
    
    // Use file...
    
    // File automatically closed when pointer goes out of scope
}
```

## Implementation Guide

The `Tutorials/Module09/Part4/Learning/` directory contains starter files to help you learn about memory leak prevention:

1. Start with these files:
   - `MemoryLeak_starter.h` and `MemoryLeak_starter.cpp`: Memory leak examples and fixes
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with leak identification:
      - Identify common leak patterns
      - Implement leak detection
      - Practice fixing simple leaks
   
   b. Move to advanced techniques:
      - Implement RAII wrappers
      - Use smart pointers
      - Handle circular references
   
   c. Complete the main program:
      - Test leak detection
      - Verify leak fixes
      - Implement memory safety patterns

3. Build and Test:
   ```bash
   # Compile with leak detection
   g++ -fsanitize=address -g -o memory_leak_demo main_starter.cpp MemoryLeak_starter.cpp
   
   # Run and check for leaks
   ./memory_leak_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each leak fix
   - Compare with example code in documentation
   - Use debugging tools to verify fixes

5. Reference Implementation:
   The completed versions (MemoryLeak.h, MemoryLeak.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study leak prevention patterns
   - Understand best practices

### Step 1: Identifying and Fixing Basic Leaks

```cpp
// Demonstrate and fix a basic memory leak
void demonstrateBasicLeak() {
    cout << "Demonstrating basic memory leak..." << endl;
    
    // Leak: memory allocated but never freed
    int* numbers = new int[100];
    for (int i = 0; i < 100; i++) {
        numbers[i] = i;
    }
    
    cout << "First few numbers: " << numbers[0] << ", " << numbers[1] << endl;
    
    // Fix: add proper deallocation
    delete[] numbers;
    
    cout << "Basic leak fixed" << endl;
}

// Expected Output:
// Demonstrating basic memory leak...
// First few numbers: 0, 1
// Basic leak fixed
```

### Step 2: Handling Early Returns

```cpp
// Demonstrate and fix a leak caused by early return
bool demonstrateEarlyReturnLeak(bool shouldReturn) {
    cout << "Demonstrating early return leak..." << endl;
    
    // Allocate memory
    int* data = new int[100];
    
    // Initialize data
    for (int i = 0; i < 100; i++) {
        data[i] = i * 10;
    }
    
    // Early return condition
    if (shouldReturn) {
        // Leak: returning without freeing memory
        
        // Fix: add deallocation before return
        delete[] data;
        return false;
    }
    
    // Process data
    cout << "Processing data: " << data[5] << endl;
    
    // Clean up
    delete[] data;
    
    return true;
}

// Expected Output (with shouldReturn = true):
// Demonstrating early return leak...
// Early return leak fixed
```

### Step 3: Exception Safety

```cpp
// Function that might throw
void riskyOperation(int value) {
    if (value < 0) {
        throw std::runtime_error("Negative value not allowed");
    }
    cout << "Processed value: " << value << endl;
}

// Demonstrate and fix a leak caused by exception
void demonstrateExceptionLeak(int value) {
    cout << "Demonstrating exception leak..." << endl;
    
    // Allocate memory
    int* data = nullptr;
    
    try {
        data = new int[100];
        
        // This might throw
        riskyOperation(value);
        
        // Clean up (only reached if no exception)
        delete[] data;
    }
    catch (const std::exception& e) {
        // Fix: add cleanup in catch block
        delete[] data;
        cout << "Caught exception: " << e.what() << endl;
        cout << "Exception leak fixed" << endl;
    }
}

// Expected Output (with value = -1):
// Demonstrating exception leak...
// Caught exception: Negative value not allowed
// Exception leak fixed
```

### Step 4: RAII Implementation

```cpp
// RAII wrapper for dynamic arrays
template <typename T>
class ArrayRAII {
private:
    T* data;
    
public:
    ArrayRAII(size_t size) {
        data = new T[size];
        cout << "ArrayRAII: Allocated memory" << endl;
    }
    
    ~ArrayRAII() {
        delete[] data;
        cout << "ArrayRAII: Freed memory" << endl;
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index];
    }
    
    T* get() {
        return data;
    }
};

// Demonstrate RAII for leak prevention
void demonstrateRAII(int value) {
    cout << "Demonstrating RAII..." << endl;
    
    try {
        // Use RAII wrapper instead of raw pointer
        ArrayRAII<int> safeArray(100);
        
        // Initialize
        for (int i = 0; i < 100; i++) {
            safeArray[i] = i;
        }
        
        // This might throw
        riskyOperation(value);
        
        cout << "RAII demonstration completed normally" << endl;
    }
    catch (const std::exception& e) {
        cout << "Caught exception: " << e.what() << endl;
        cout << "RAII still ensures cleanup" << endl;
    }
    
    // ArrayRAII destructor automatically called, no leak
}

// Expected Output (with value = -1):
// Demonstrating RAII...
// ArrayRAII: Allocated memory
// Caught exception: Negative value not allowed
// RAII still ensures cleanup
// ArrayRAII: Freed memory
```

### Step 5: Smart Pointers

```cpp
#include <memory>

// Demonstrate smart pointers for leak prevention
void demonstrateSmartPointers() {
    cout << "Demonstrating smart pointers..." << endl;
    
    // unique_ptr for exclusive ownership
    {
        cout << "Using unique_ptr:" << endl;
        std::unique_ptr<int[]> numbers = std::make_unique<int[]>(100);
        
        // Use like regular array
        for (int i = 0; i < 100; i++) {
            numbers[i] = i;
        }
        
        cout << "First few numbers: " << numbers[0] << ", " << numbers[1] << endl;
        
        // No need for explicit delete
    }
    cout << "unique_ptr automatically freed memory" << endl;
    
    // shared_ptr for shared ownership
    {
        cout << "\nUsing shared_ptr:" << endl;
        auto numbers = std::make_shared<int>(42);
        
        {
            auto numbers2 = numbers;  // Share ownership
            *numbers2 = 100;
            cout << "Modified through numbers2: " << *numbers2 << endl;
            cout << "Reference count: " << numbers.use_count() << endl;
        }
        
        cout << "After inner scope, value: " << *numbers << endl;
        cout << "Reference count: " << numbers.use_count() << endl;
        
        // No need for explicit delete
    }
    cout << "shared_ptr automatically freed memory" << endl;
}

// Expected Output:
// Demonstrating smart pointers...
// Using unique_ptr:
// First few numbers: 0, 1
// unique_ptr automatically freed memory
//
// Using shared_ptr:
// Modified through numbers2: 100
// Reference count: 2
// After inner scope, value: 100
// Reference count: 1
// shared_ptr automatically freed memory
```

## Practice Exercises

The `Tutorials/Module09/Part4/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., MemoryLeak_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Identify memory leaks
      - Plan your fixes
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement leak prevention
      - Add proper resource management
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -fsanitize=address -g -o exercise1 main_starter.cpp MemoryLeak_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugging tools to verify
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Fix the Leaks
Identify and fix memory leaks in the provided code:

```cpp
// TODO: Fix memory leaks in these functions
void function1();  // Basic leak
void function2(bool condition);  // Early return leak
void function3(int value);  // Exception leak
void function4();  // Pointer reassignment leak
void function5();  // Circular reference leak
```

### Exercise 2: Resource Management
Implement RAII wrappers for different resources:

```cpp
// TODO: Implement these RAII wrappers
class FileWrapper {
    // RAII wrapper for file handles
};

class LockWrapper {
    // RAII wrapper for mutex locks
};

class MemoryBlockWrapper {
    // RAII wrapper for dynamic memory
};
```

### Exercise 3: Smart Pointer Usage
Convert raw pointer code to use smart pointers:

```cpp
// TODO: Convert these functions to use smart pointers
void processData(int* data, int size);  // Use unique_ptr
void shareResource();  // Use shared_ptr
void handleCircularReferences();  // Use weak_ptr
```

## Advanced Memory Management Topics

### Custom Memory Management

For performance-critical applications, custom memory management can reduce allocation overhead:

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
    
    void reset() {
        used = 0;  // Simple reset without individual deallocation
    }
};

// Usage
void useMemoryPool() {
    MemoryPool pool(1024);  // 1KB pool
    
    // Allocate from pool
    int* numbers = static_cast<int*>(pool.allocate(10 * sizeof(int)));
    for (int i = 0; i < 10; i++) {
        numbers[i] = i;
    }
    
    // No individual delete needed
    pool.reset();  // Reset entire pool
}
```

### Leak Detection in Production Code

For production code, you can implement a simple leak detector:

```cpp
#ifdef DEBUG_MEMORY

class MemoryLeakDetector {
private:
    static std::map<void*, std::string> allocations;
    
public:
    static void recordAllocation(void* ptr, const std::string& file, int line) {
        std::stringstream ss;
        ss << file << ":" << line;
        allocations[ptr] = ss.str();
    }
    
    static void recordDeallocation(void* ptr) {
        allocations.erase(ptr);
    }
    
    static void reportLeaks() {
        if (allocations.empty()) {
            std::cout << "No memory leaks detected" << std::endl;
            return;
        }
        
        std::cout << "MEMORY LEAKS DETECTED:" << std::endl;
        for (const auto& pair : allocations) {
            std::cout << "Address: " << pair.first << ", allocated at: " << pair.second << std::endl;
        }
    }
};

std::map<void*, std::string> MemoryLeakDetector::allocations;

// Override new and delete
void* operator new(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    MemoryLeakDetector::recordAllocation(ptr, file, line);
    return ptr;
}

void operator delete(void* ptr) noexcept {
    MemoryLeakDetector::recordDeallocation(ptr);
    free(ptr);
}

#define new new(__FILE__, __LINE__)

#endif // DEBUG_MEMORY

// Usage
int main() {
    int* leak = new int;  // Tracked allocation
    
    // No delete, will be reported as leak
    
    MemoryLeakDetector::reportLeaks();
    return 0;
}
```

### Memory Profiling

For complex applications, memory profiling tools can help identify patterns:

- **Valgrind Massif**: Heap profiler that measures memory usage
- **Visual Studio Memory Usage Tool**: Tracks allocations over time
- **Intel VTune Profiler**: Advanced memory usage analysis

## Summary

### Key Concepts

1. **Memory Leak Fundamentals**
   - Allocated memory not deallocated
   - Resources gradually depleted
   - Performance and stability affected
   - Often difficult to diagnose
   - Critical in long-running applications

2. **Common Leak Causes**
   - Forgetting to delete
   - Early returns and exceptions
   - Pointer reassignment
   - Circular references
   - Improper destructors

3. **Debugging Techniques**
   - Manual tracking
   - Memory debugging tools
   - Static analysis
   - Runtime leak detection
   - Memory profiling

4. **Resource Management**
   - RAII principle
   - Smart pointers
   - Custom deleters
   - Exception safety
   - Ownership semantics

5. **Prevention Patterns**
   - Consistent allocation/deallocation
   - Smart pointers by default
   - Clear ownership rules
   - Exception-safe code
   - Automated testing

### Common Pitfalls

1. **Inconsistent Cleanup**
   ```cpp
   // Wrong! Inconsistent cleanup paths
   void function(bool condition) {
       Resource* res = new Resource();
       
       if (condition) {
           // Process...
           return;  // Leak: no cleanup on this path
       }
       
       // Process...
       delete res;
   }
   
   // Correct
   void function(bool condition) {
       Resource* res = new Resource();
       
       if (condition) {
           // Process...
           delete res;
           return;
       }
       
       // Process...
       delete res;
   }
   
   // Even better
   void function(bool condition) {
       std::unique_ptr<Resource> res = std::make_unique<Resource>();
       
       if (condition) {
           // Process...
           return;  // No leak: unique_ptr handles cleanup
       }
       
       // Process...
   }
   ```

2. **Mismatched new/delete**
   ```cpp
   // Wrong! Mismatched new/delete
   void function() {
       int* array = new int[10];
       // ...
       delete array;  // Should be delete[] array
   }
   
   // Correct
   void function() {
       int* array = new int[10];
       // ...
       delete[] array;
   }
   
   // Even better
   void function() {
       std::unique_ptr<int[]> array = std::make_unique<int[]>(10);
       // ...
   }
   ```

3. **Manual Exception Handling**
   ```cpp
   // Wrong! Exception can cause leak
   void function() {
       Resource* res = new Resource();
       
       // This might throw
       processData();
       
       delete res;
   }
   
   // Correct but cumbersome
   void function() {
       Resource* res = new Resource();
       
       try {
           // This might throw
           processData();
           
           delete res;
       }
       catch (...) {
           delete res;
           throw;  // Re-throw
       }
   }
   
   // Better
   void function() {
       std::unique_ptr<Resource> res = std::make_unique<Resource>();
       
       // This might throw, but no leak
       processData();
   }
   ```

4. **Circular References with shared_ptr**
   ```cpp
   // Wrong! Circular reference with shared_ptr
   struct Node {
       std::shared_ptr<Node> next;
       std::shared_ptr<Node> prev;
   };
   
   void createNodes() {
       auto node1 = std::make_shared<Node>();
       auto node2 = std::make_shared<Node>();
       
       node1->next = node2;  // node1 references node2
       node2->prev = node1;  // node2 references node1
       
   // Leak: circular reference prevents cleanup
   }
   
   // Correct
   struct Node {
       std::shared_ptr<Node> next;
       std::weak_ptr<Node> prev;  // Use weak_ptr to break circular reference
   };
   
   void createNodes() {
       auto node1 = std::make_shared<Node>();
       auto node2 = std::make_shared<Node>();
       
       node1->next = node2;  // Strong reference
       node2->prev = node1;  // Weak reference
       
       // No leak: weak_ptr doesn't prevent cleanup
   }
   ```

5. **Forgetting Custom Destructors**
   ```cpp
   // Wrong! Missing destructor in class with resources
   class ResourceOwner {
   private:
       Resource* resource;
       
   public:
       ResourceOwner() {
           resource = new Resource();
       }
       
       // Missing destructor
       // ~ResourceOwner() { delete resource; }
   };
   
   // Correct
   class ResourceOwner {
   private:
       Resource* resource;
       
   public:
       ResourceOwner() {
           resource = new Resource();
       }
       
       ~ResourceOwner() {
           delete resource;
       }
   };
   
   // Even better
   class ResourceOwner {
   private:
       std::unique_ptr<Resource> resource;
       
   public:
       ResourceOwner() {
           resource = std::make_unique<Resource>();
       }
       
       // No explicit destructor needed
   };
   ```

### Best Practices
1. Use smart pointers by default
2. Follow RAII for all resources
3. Implement proper destructors for classes with resources
4. Be consistent with memory management patterns
5. Use tools to detect leaks during development
6. Test exception paths
7. Document ownership semantics
8. Prefer stack allocation when possible
9. Use containers for collections
10. Avoid manual memory management in modern C++

## Next Steps
1. Complete all practice exercises
2. Test with memory debugging tools
3. Review resource management patterns
4. Study smart pointer usage in depth
5. Move on to [Part 5: Pointers and Arrays]({{ site.baseurl }}/tutorials/module9/part5-pointers-arrays)

Remember: Memory leaks can be subtle and difficult to detect. Consistent use of RAII and smart pointers is the best defense against leaks in modern C++ code.
