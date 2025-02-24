---
layout: default
title: Part 5 - Function Overloading
nav_order: 5
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part5-overloading/
---

# Part 5: Function Overloading

## Learning Objectives
- Understand function overloading concepts
- Master overload resolution rules
- Learn when to use overloading
- Practice creating overloaded functions
- Implement type-safe interfaces
- Avoid common overloading pitfalls

## Introduction
Function overloading allows multiple functions with the same name but different parameter lists to coexist. Think of it like:

1. **Real-World Analogies**:
   - Different phone numbers for one contact (home, work, mobile)
   - Multiple entrances to a building (main, side, emergency)
   - Various payment methods (cash, card, digital)
   - Different tools with same purpose (screwdrivers for different screws)
   - Multiple routes to same destination (highway, local roads)

2. **Benefits in Programming**:
   - Intuitive interface design
   - Type-safe operations
   - Simplified code usage
   - Consistent naming
   - Better code organization

3. **Common Applications**:
   - Constructors with different parameters
   - Print functions for various types
   - Math operations on different number types
   - String processing with different inputs
   - Data conversion functions

## Implementation Guide

You'll find the starter code in `Tutorials/Module03/Part5/overloading_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module03/Part5/overloading.cpp`.

### Step 1: Basic Function Overloading

```cpp
// Function declarations
int add(int a, int b);
double add(double a, double b);
string add(const string& a, const string& b);

int main() {
    // Integer addition
    cout << "5 + 3 = " << add(5, 3) << endl;
    
    // Double addition
    cout << "3.14 + 2.86 = " << add(3.14, 2.86) << endl;
    
    // String concatenation
    cout << add("Hello, ", "World!") << endl;
    
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

string add(const string& a, const string& b) {
    return a + b;
}
```

Key Points:
- Same function name
- Different parameter types
- Compiler chooses correct version
- Type-safe operations
- Clear function intent

### Step 2: Overloading with Different Parameters

```cpp
// Function declarations
void print(int value);
void print(int value, int width);
void print(int value, int width, char fill);
void print(const string& text, bool uppercase = false);

int main() {
    print(42);                  // Basic integer
    print(42, 5);              // Width-formatted integer
    print(42, 5, '0');         // Zero-padded integer
    print("Hello");            // Basic string
    print("Hello", true);      // Uppercase string
    
    return 0;
}

// Function definitions
void print(int value) {
    cout << value << endl;
}

void print(int value, int width) {
    cout << setw(width) << value << endl;
}

void print(int value, int width, char fill) {
    cout << setfill(fill) << setw(width) << value << endl;
}

void print(const string& text, bool uppercase) {
    string output = text;
    if (uppercase) {
        transform(output.begin(), output.end(), 
                 output.begin(), ::toupper);
    }
    cout << output << endl;
}
```

### Step 3: Advanced Overloading Examples

```cpp
class Point {
public:
    int x, y;
    
    // Constructor overloading
    Point() : x(0), y(0) {}
    Point(int x) : x(x), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    
    // Method overloading
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    
    void move(const Point& other) {
        x += other.x;
        y += other.y;
    }
    
    void move(int distance) {
        x += distance;
        y += distance;
    }
};

// Function overloading with const
void updateValue(int& value) {
    value *= 2;
}

void updateValue(const int& value, int& result) {
    result = value * 2;
}

int main() {
    // Test Point class
    Point p1;          // Default constructor
    Point p2(5);       // Single parameter
    Point p3(3, 4);    // Two parameters
    
    p1.move(2, 3);    // Move by dx, dy
    p2.move(p3);      // Move by another point
    p3.move(5);       // Move by single value
    
    // Test const overloading
    int x = 10, result;
    updateValue(x);              // Modifies x
    updateValue(42, result);     // Stores in result
    
    return 0;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part5/practice_overloading_starter.cpp`
- Complete solution: `Tutorials/Module03/Part5/practice_overloading.cpp`

### Exercise 1: Calculator Functions

```cpp
// TODO: Implement these overloaded functions
double calculate(double a, double b, char op);
int calculate(int a, int b, char op);
complex<double> calculate(complex<double> a, complex<double> b, char op);
```

Requirements:
1. Support basic arithmetic operations
2. Handle integer and floating-point math
3. Implement complex number operations
4. Validate operators
5. Handle division by zero

### Exercise 2: Shape Area Calculator

```cpp
// TODO: Implement area calculations for different shapes
double calculateArea(double radius);                    // Circle
double calculateArea(double length, double width);      // Rectangle
double calculateArea(double base, double height, char shape); // Triangle/Parallelogram
```

Requirements:
1. Calculate accurate areas
2. Validate input values
3. Handle different shape types
4. Return precise results
5. Document calculations

### Exercise 3: String Formatter

```cpp
// TODO: Implement string formatting functions
string format(const string& text);                     // Basic formatting
string format(const string& text, bool uppercase);     // Case formatting
string format(const string& text, int width, char fill); // Width formatting
string format(const string& text, const string& prefix, const string& suffix); // With affixes
```

Requirements:
1. Handle empty strings
2. Process special characters
3. Support padding options
4. Implement case conversion
5. Add prefix/suffix support

## Summary

### Key Concepts

1. **Function Overloading Basics**
   ```cpp
   // Same name, different parameters
   void display(int x);
   void display(double x);
   void display(string x);
   ```

2. **Overload Resolution**
   ```cpp
   // Compiler chooses best match
   display(42);        // Calls int version
   display(3.14);     // Calls double version
   display("Hello");  // Calls string version
   ```

3. **Parameter Differences**
   ```cpp
   // Different number of parameters
   void setup();
   void setup(int value);
   void setup(int value, string name);
   
   // Different parameter types
   void process(int x, int y);
   void process(double x, double y);
   void process(string x, string y);
   ```

4. **Return Type Considerations**
   ```cpp
   // Return type alone doesn't allow overloading
   int getValue();
   double getValue();    // Error: Same parameters
   
   // Valid with different parameters
   int getValue(int index);
   double getValue(string key);
   ```

### Common Pitfalls

1. **Ambiguous Overloads**
   ```cpp
   void print(int value);
   void print(double value);
   
   print(42);        // OK: Calls int version
   print(3.14);      // OK: Calls double version
   print(42.0f);     // Error: Ambiguous
   ```

2. **Return Type Only**
   ```cpp
   int calculate(int x, int y);
   double calculate(int x, int y);  // Error: Same parameters
   ```

3. **Default Arguments**
   ```cpp
   void show(int x, int y = 0);
   void show(int x);  // Error: Ambiguous with default
   ```

### Best Practices

1. **Clear Parameter Differences**
   ```cpp
   // Good: Clear differences
   void process(int value);
   void process(const string& text);
   
   // Bad: Subtle differences
   void process(int* ptr);
   void process(int& ref);
   ```

2. **Consistent Behavior**
   ```cpp
   // Good: Consistent behavior
   int add(int a, int b);      // Addition
   double add(double a, double b);  // Addition
   
   // Bad: Inconsistent behavior
   int combine(int a, int b);     // Addition
   int combine(double a, double b);  // Multiplication
   ```

3. **Documentation**
   ```cpp
   // Document differences clearly
   // Processes integer values
   void process(int value);
   
   // Processes text with optional case sensitivity
   void process(const string& text, bool caseSensitive = false);
   ```

## Next Steps
1. Complete practice exercises
2. Test with various types
3. Handle edge cases
4. Review error handling
5. Move on to [Part 6: Function Templates]({{ site.baseurl }}/tutorials/module3/part6-templates)

Remember: Function overloading is a powerful feature that can make your code more intuitive and easier to use. Choose overloads that make sense semantically and maintain consistent behavior across different versions.
