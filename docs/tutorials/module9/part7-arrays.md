---
layout: default
title: Part 7 - Arrays and Pointers
nav_order: 7
parent: Module 9 - Pointers and Dynamic Memory
grand_parent: Tutorials
permalink: /tutorials/module9/part7-arrays/
---

# Part 7: Arrays and Pointers

## Overview
Arrays and pointers are closely related in C++. Understanding their relationship is crucial for effective memory management and array manipulation.

## Array-Pointer Relationship

### Array Decay
```cpp
int numbers[] = {1, 2, 3, 4, 5};
int* ptr = numbers;  // Array decays to pointer to first element

cout << numbers[0] << endl;  // Array notation
cout << *ptr << endl;        // Pointer notation
cout << ptr[0] << endl;      // Pointer array notation
```

### Pointer Arithmetic
```cpp
int* ptr = numbers;
cout << *ptr;       // First element
cout << *(ptr + 1); // Second element
cout << ptr[2];     // Third element
```

### Array Size
```cpp
int numbers[] = {1, 2, 3, 4, 5};
size_t size = sizeof(numbers) / sizeof(numbers[0]);
```

## Practice Exercise

Create a program demonstrating array and pointer relationships:
1. Array manipulation
2. Pointer arithmetic
3. Multi-dimensional arrays
4. Dynamic arrays

Solution:
```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void demonstrateBasicArrays() {
    cout << "\nBasic Array Operations:" << endl;
    cout << string(30, '-') << endl;
    
    // Array declaration and initialization
    int numbers[] = {1, 2, 3, 4, 5};
    int* ptr = numbers;
    
    // Array size calculation
    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Array size: " << size << endl;
    
    // Different access methods
    cout << "\nAccessing elements:" << endl;
    cout << "Array notation: ";
    for (size_t i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "Pointer notation: ";
    for (size_t i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    
    cout << "Pointer array notation: ";
    for (size_t i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

void demonstratePointerArithmetic() {
    cout << "\nPointer Arithmetic:" << endl;
    cout << string(30, '-') << endl;
    
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;
    
    cout << "Moving through array:" << endl;
    cout << "Initial position: " << *ptr << endl;
    
    ptr++;  // Move to next element
    cout << "After ptr++: " << *ptr << endl;
    
    ptr += 2;  // Skip two elements
    cout << "After ptr += 2: " << *ptr << endl;
    
    ptr--;  // Move back one element
    cout << "After ptr--: " << *ptr << endl;
    
    // Distance between pointers
    int* start = numbers;
    int* end = numbers + 4;
    cout << "\nDistance between pointers: " << end - start << " elements" << endl;
}

void demonstrateMultiDimensional() {
    cout << "\nMulti-dimensional Arrays:" << endl;
    cout << string(30, '-') << endl;
    
    // 2D array
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Using array notation
    cout << "Using array notation:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Using pointer arithmetic
    cout << "\nUsing pointer arithmetic:" << endl;
    int* ptr = &matrix[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(3) << *(ptr + i * 4 + j) << " ";
        }
        cout << endl;
    }
}

class DynamicArray {
private:
    int* data;
    size_t size;
    
public:
    DynamicArray(size_t s) : size(s) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    
    ~DynamicArray() {
        delete[] data;
    }
    
    void set(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
    }
    
    int get(size_t index) const {
        return (index < size) ? data[index] : 0;
    }
    
    void display() const {
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
    size_t getSize() const { return size; }
};

void demonstrateDynamicArrays() {
    cout << "\nDynamic Arrays:" << endl;
    cout << string(30, '-') << endl;
    
    // Single dynamic array
    cout << "Single dynamic array:" << endl;
    int* numbers = new int[5]{1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    delete[] numbers;
    
    // Dynamic 2D array
    cout << "\nDynamic 2D array:" << endl;
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
    
    // Display matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Cleanup
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    // Using DynamicArray class
    cout << "\nDynamic array class:" << endl;
    DynamicArray arr(5);
    
    for (size_t i = 0; i < arr.getSize(); i++) {
        arr.set(i, i * 10);
    }
    
    arr.display();
}

int main() {
    try {
        cout << "Array and Pointer Relationship Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        demonstrateBasicArrays();
        demonstratePointerArithmetic();
        demonstrateMultiDimensional();
        demonstrateDynamicArrays();
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Memory Layout

### Array in Memory
{% mermaid %}
graph LR
    A[Array Base] --> B[Element 0]
    B --> C[Element 1]
    C --> D[Element 2]
    D --> E[...]
{% endmermaid %}

### 2D Array Layout
{% mermaid %}
graph TD
    A[Matrix] --> B[Row 0]
    A --> C[Row 1]
    A --> D[Row 2]
    B --> E[Elements 0,0 to 0,n]
    C --> F[Elements 1,0 to 1,n]
    D --> G[Elements 2,0 to 2,n]
{% endmermaid %}

## Best Practices

### Array Management
1. Size tracking
2. Bounds checking
3. Memory alignment
4. Cleanup handling
5. Error checking

### Pointer Safety
1. Null checks
2. Bounds validation
3. Memory leaks
4. Type safety
5. Ownership clarity

### Performance Tips
1. Cache alignment
2. Memory access
3. Array traversal
4. Dynamic allocation
5. Memory reuse

## Common Mistakes to Avoid
1. Array bounds
2. Memory leaks
3. Dangling pointers
4. Type confusion
5. Size miscalculation

## Next Steps
- Try the practice exercise
- Experiment with arrays
- Complete Module 9
