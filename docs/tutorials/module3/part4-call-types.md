---
layout: default
title: Part 4 - Call by Value and Call by Reference
nav_order: 4
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part4-call-types/
---

# Part 4: Call by Value and Call by Reference

## Learning Objectives
- Master different parameter passing methods
- Understand memory implications
- Learn when to use each call type
- Practice efficient parameter passing
- Implement proper error handling
- Optimize function performance

## Introduction
C++ provides two ways to pass arguments to functions: by value and by reference. Understanding the differences between these methods is crucial for writing efficient and effective code.

1. **Call by Value**:
   - Creates a copy of the argument
   - Safe but can be inefficient
   - Original data protected
   - Good for small data types
   - Common default choice

2. **Call by Reference**:
   - Passes memory address
   - More efficient for large objects
   - Can modify original data
   - Must be initialized
   - Requires careful handling

3. **Real-World Analogies**:
   - Value: Like giving someone a photocopy
   - Reference: Like sharing the original document
   - Const Reference: Like a read-only view
   - Multiple References: Like shared access

## Implementation Guide

You'll find the starter code in `Tutorials/Module03/Part4/call_types_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module03/Part4/call_types.cpp`.

### Step 1: Call by Value Examples

```cpp
// Function declarations
void modifyValue(int x);
void processArray(int arr[], int size);
void handleString(string text);

int main() {
    // Test value parameters
    int number = 42;
    cout << "Before: " << number << endl;
    modifyValue(number);
    cout << "After: " << number << endl;  // Unchanged
    
    // Test array (special case)
    int data[] = {1, 2, 3};
    processArray(data, 3);  // Array modified
    
    // Test string
    string msg = "Hello";
    handleString(msg);  // String unchanged
    
    return 0;
}

// Function definitions
void modifyValue(int x) {
    x *= 2;  // Only modifies local copy
    cout << "Inside function: " << x << endl;
}

void processArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original array
    }
}

void handleString(string text) {
    text += " World";  // Only modifies local copy
    cout << "Inside function: " << text << endl;
}
```

### Step 2: Call by Reference Examples

```cpp
// Function declarations
void modifyByRef(int& x);
void swapValues(int& a, int& b);
void updateString(string& text);

int main() {
    // Test reference parameter
    int value = 42;
    cout << "Before: " << value << endl;
    modifyByRef(value);
    cout << "After: " << value << endl;  // Modified
    
    // Test value swapping
    int x = 5, y = 10;
    cout << "Before swap: x=" << x << ", y=" << y << endl;
    swapValues(x, y);
    cout << "After swap: x=" << x << ", y=" << y << endl;
    
    // Test string reference
    string message = "Hello";
    updateString(message);
    cout << "Updated: " << message << endl;  // Modified
    
    return 0;
}

// Function definitions
void modifyByRef(int& x) {
    x *= 2;  // Modifies original value
}

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void updateString(string& text) {
    text += " World";  // Modifies original string
}
```

### Step 3: Const Reference Examples

```cpp
// Function declarations
void printData(const vector<int>& data);
double calculateAverage(const double values[], int size);
void displayPerson(const string& name, const int& age);

int main() {
    // Test const vector reference
    vector<int> numbers = {1, 2, 3, 4, 5};
    printData(numbers);
    
    // Test const array reference
    double scores[] = {85.5, 92.0, 77.5, 90.0};
    cout << "Average: " << calculateAverage(scores, 4) << endl;
    
    // Test const primitive references
    string name = "Alice";
    int age = 25;
    displayPerson(name, age);
    
    return 0;
}

// Function definitions
void printData(const vector<int>& data) {
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
}

double calculateAverage(const double values[], int size) {
    if (size == 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum / size;
}

void displayPerson(const string& name, const int& age) {
    cout << name << " is " << age << " years old" << endl;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part4/practice_call_types_starter.cpp`
- Complete solution: `Tutorials/Module03/Part4/practice_call_types.cpp`

### Exercise 1: Bank Account System

```cpp
struct BankAccount {
    string accountNumber;
    double balance;
    vector<string> transactions;
};

// TODO: Implement these functions
void deposit(BankAccount& account, double amount);
bool withdraw(BankAccount& account, double amount);
void displayBalance(const BankAccount& account);
void addTransaction(BankAccount& account, const string& description);
```

Requirements:
1. Use reference for account modifications
2. Use const reference for display
3. Validate all operations
4. Maintain transaction history
5. Format currency properly

### Exercise 2: Text Processing System

```cpp
// TODO: Implement these functions
void processText(const string& input, string& output);
int countWords(const string& text);
void convertCase(string& text, char mode);
void findAndReplace(string& text, const string& find, const string& replace);
```

Requirements:
1. Use const for input text
2. Modify output through reference
3. Handle empty strings
4. Process special characters
5. Validate all inputs

### Exercise 3: Data Analysis System

```cpp
struct DataSet {
    vector<double> values;
    double mean;
    double median;
    double standardDev;
};

// TODO: Implement these functions
void calculateStats(DataSet& data);
void addValue(DataSet& data, double value);
void removeValue(DataSet& data, int index);
void displayStats(const DataSet& data);
```

Requirements:
1. Update stats efficiently
2. Validate all operations
3. Handle empty datasets
4. Format output clearly
5. Use appropriate call types

## Summary

### Key Concepts

1. **Call by Value**
   - Creates copy of argument
   - Protects original data
   - Good for small types

   ```cpp
   void increment(int x) {
       x++;  // Only changes copy
   }
   
   int num = 5;
   increment(num);  // num still 5
   ```

2. **Call by Reference**
   - Uses original data
   - More efficient
   - Can modify argument

   ```cpp
   void increment(int& x) {
       x++;  // Changes original
   }
   
   int num = 5;
   increment(num);  // num now 6
   ```

3. **Const Reference**
   - Efficient access
   - Prevents modification
   - Best for large read-only

   ```cpp
   void print(const string& text) {
       cout << text << endl;
       // text += "!";  // Error
   }
   ```

4. **Performance Considerations**
   - Value copies data
   - Reference shares data
   - Const prevents changes

   ```cpp
   // Efficient parameter passing
   void process(const vector<int>& data) {
       // Access without copying
   }
   ```

### Common Pitfalls

1. **Unnecessary Copying**

   ```cpp
   // Inefficient: Copies large object
   void processData(vector<int> data) {
       // Works with copy
   }

   // Better: Uses reference
   void processData(const vector<int>& data) {
       // Works with original
   }
   ```

2. **Missing Const**

   ```cpp
   // Risky: Could modify input
   void displayData(vector<int>& data) {
       data.clear();  // Accidental modification
   }

   // Safe: Prevents modification
   void displayData(const vector<int>& data) {
       // data.clear();  // Error
   }
   ```

3. **Reference to Temporary**

   ```cpp
   // Dangerous: Reference to temporary
   int& getNumber() {
       int x = 42;
       return x;  // Returns dangling reference
   }

   // Safe: Return by value
   int getNumber() {
       int x = 42;
       return x;
   }
   ```

### Best Practices
1. **Parameter Selection**
   - Use value for small types
   - Use const reference for large types
   - Use reference for modification
   - Consider performance impact

2. **Safety Guidelines**
   - Validate references
   - Use const when possible
   - Avoid dangling references
   - Document modifications

3. **Performance Tips**
   - Minimize copying
   - Use references for large objects
   - Consider memory usage
   - Profile critical code

4. **Documentation**
   - Note parameter types
   - Document modifications
   - Explain performance choices
   - Specify requirements

## Next Steps
1. Complete practice exercises
2. Test with various data types
3. Profile performance
4. Review error handling
5. Move on to [Part 5: Function Overloading]({{ site.baseurl }}/tutorials/module3/part5-overloading)

Remember: Choosing the right parameter passing method is crucial for both correctness and performance. Consider the size of data and intended usage when making your choice.
