---
layout: default
title: Part 2 - Accessing Array Elements
nav_order: 2
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part2-arrays/
---

# Part 2: Accessing Array Elements

## Learning Objectives
- Master array declaration and initialization
- Understand array indexing and bounds
- Learn array parameter passing
- Practice array manipulation techniques
- Implement multi-dimensional arrays
- Handle array-related errors

## Introduction
Arrays are fundamental data structures that provide fixed-size sequential storage. Think of them like:

1. **Why Arrays Matter**:
   - **Direct Memory Access**: Contiguous memory storage
   - **Fixed Size**: Compile-time size allocation
   - **Performance**: O(1) element access
   - **Memory Efficiency**: Minimal overhead
   - **Multi-dimensional**: Support for matrices/tables

2. **Real-World Applications**:
   - **Image Processing**: Pixel matrices
   - **Game Development**: Game boards
   - **Scientific Computing**: Data tables
   - **Signal Processing**: Sample arrays
   - **Database Systems**: Record arrays

3. **Benefits in Development**:
   - **Predictable Performance**: Constant-time access
   - **Memory Layout**: Cache-friendly
   - **Simple Indexing**: Direct element access
   - **Stack Allocation**: Fast memory allocation
   - **Pointer Arithmetic**: Efficient traversal

## Implementation Guide

You'll find the starter code in `Tutorials/Module04/Part2/arrays_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module04/Part2/arrays.cpp`.

### Step 1: Array Declaration and Initialization
```cpp
// Fixed-size array declaration
int numbers[5];                    // Uninitialized
int scores[3] = {95, 88, 78};     // Initialized array
double grades[] = {85.5, 92.0};   // Size from initializer

// Array size
const int SIZE = 5;
int values[SIZE];                  // Size from constant

// Initialize all elements
for (int i = 0; i < SIZE; i++) {
    values[i] = i + 1;            // Sequential values
}
```

Key Points:
- Fixed size at compile time
- Contiguous memory allocation
- No size tracking
- Zero-based indexing
- Automatic storage duration

### Step 2: Array Access and Bounds
```cpp
// Safe array access
void processArray(int arr[], int size) {
    // Check bounds before access
    if (size <= 0) return;
    
    // First and last elements
    cout << "First: " << arr[0] << endl;
    cout << "Last: " << arr[size-1] << endl;
    
    // Iterate with bounds checking
    for (int i = 0; i < size; i++) {
        if (i < size) {  // Extra safety
            cout << arr[i] << " ";
        }
    }
}

// Array bounds example
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Safe access
    processArray(arr, 5);
    
    // Bounds checking
    int index;
    cout << "Enter index: ";
    cin >> index;
    
    if (index >= 0 && index < 5) {
        cout << arr[index] << endl;
    } else {
        cout << "Index out of bounds" << endl;
    }
}
```

Key Points:
- Always check bounds
- Pass size with array
- Validate indices
- Handle edge cases
- Document size requirements

### Step 3: Multi-dimensional Arrays
```cpp
// 2D array declaration
const int ROWS = 3;
const int COLS = 4;
int matrix[ROWS][COLS];

// Initialize 2D array
for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
        matrix[i][j] = i * COLS + j;
    }
}

// Access 2D array elements
void print2DArray(int arr[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Process 2D array
void process2DArray(int arr[][COLS], int rows) {
    // Calculate row sums
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i << " sum: " << sum << endl;
    }
}
```

Key Points:
- Column size required
- Row-major order
- Nested iteration
- Memory layout
- Parameter passing

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module04/Part2/practice_arrays_starter.cpp`
- Complete solution: `Tutorials/Module04/Part2/practice_arrays.cpp`

### Exercise 1: Temperature Tracker
Implement a daily temperature tracking system:
```cpp
class TemperatureTracker {
private:
    double temperatures[24];  // 24 hours
public:
    void recordTemperature(int hour, double temp);
    double getAverageTemperature() const;
    void getHighestTemperature(double& temp, int& hour) const;
    void displayChart() const;
};
```

Requirements:
1. Validate hour (0-23)
2. Validate temperature range
3. Calculate statistics
4. Format output clearly
5. Handle missing data

### Exercise 2: Image Processor
Create a simple image processing system:
```cpp
class ImageProcessor {
private:
    int image[5][5];  // 5x5 grayscale image
public:
    void setPixel(int row, int col, int value);
    void applyThreshold(int threshold);
    void flipHorizontal();
    void displayImage() const;
};
```

Requirements:
1. Validate coordinates
2. Handle pixel values (0-255)
3. Implement transformations
4. Format display neatly
5. Process efficiently

### Exercise 3: Seating System
Build a theater seating system:
```cpp
class SeatingSystem {
private:
    bool seats[10][10];  // 10x10 seating grid
public:
    bool reserveSeat(int row, int col);
    bool cancelReservation(int row, int col);
    bool isSeatAvailable(int row, int col) const;
    void displayChart() const;
};
```

Requirements:
1. Validate seat coordinates
2. Handle reservations
3. Track availability
4. Display seating chart
5. Process efficiently

## Summary

### Key Concepts

1. **Array Basics**
   ```cpp
   int arr[SIZE];           // Fixed-size array
   arr[index]              // Element access
   sizeof(arr)             // Array size in bytes
   &arr[0]                // Array address
   arr                    // Decays to pointer
   ```

2. **Array Parameters**
   ```cpp
   void process(int arr[], int size);     // 1D array
   void process(int arr[][COLS], int rows); // 2D array
   void process(const int arr[], int size); // Read-only
   ```

3. **Array Operations**
   ```cpp
   // Initialization
   int arr[] = {1, 2, 3};
   
   // Iteration
   for (int i = 0; i < size; i++)
   
   // Bounds checking
   if (index >= 0 && index < size)
   ```

### Common Pitfalls

1. **Bounds Errors**
   ```cpp
   // Wrong: No bounds check
   arr[i] = value;
   
   // Right: Check bounds
   if (i < size) arr[i] = value;
   ```

2. **Size Issues**
   ```cpp
   // Wrong: Sizeof on parameter
   void process(int arr[]) {
       int size = sizeof(arr);  // Wrong!
   }
   
   // Right: Pass size explicitly
   void process(int arr[], int size)
   ```

3. **Initialization Problems**
   ```cpp
   // Wrong: Partial initialization
   int arr[5] = {1, 2};  // Others are 0
   
   // Right: Full initialization
   int arr[5] = {1, 2, 3, 4, 5};
   ```

### Best Practices

1. **Array Declaration**
   - Use constants for size
   - Initialize all elements
   - Consider std::array
   - Document size requirements
   - Use meaningful names

2. **Array Access**
   - Always check bounds
   - Use const when read-only
   - Pass size with array
   - Validate indices
   - Handle edge cases

3. **Array Processing**
   - Use appropriate loops
   - Process efficiently
   - Handle empty arrays
   - Document assumptions
   - Consider alternatives

4. **Error Handling**
   - Validate input
   - Check bounds
   - Handle edge cases
   - Document errors
   - Return status

## Next Steps
1. Complete practice exercises
2. Test with various inputs
3. Handle edge cases
4. Review error handling
5. Move on to [Part 3: Strings]({{ site.baseurl }}/tutorials/module4/part3-strings)

Remember: Arrays provide efficient but fixed-size storage. Always validate indices and consider using std::array or std::vector for more safety and flexibility.
