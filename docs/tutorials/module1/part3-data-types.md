---
layout: default
title: Part 3 - Data Types
nav_order: 3
parent: Module 1 - Introduction to C++
grand_parent: Tutorials
permalink: /tutorials/module1/part3-data-types/
---

# Part 3: Data Types

## Learning Objectives
- Master C++ fundamental data types
- Understand type conversion rules
- Learn about user-defined types
- Implement type-safe code
- Practice proper type usage
- Handle type-related errors
- Create custom data types

## Introduction
Data types in C++ are like different kinds of containers, each designed to hold specific types of data. Think of them as:

1. **Why Data Types Matter**:
   - **Memory Efficiency**: Optimal storage use
   - **Type Safety**: Prevent errors
   - **Performance**: Efficient operations
   - **Clarity**: Clear code intent
   - **Reliability**: Prevent data corruption

2. **Real-World Applications**:
   - **Financial Software**: Precise calculations
   - **Graphics**: Coordinate systems
   - **Scientific Computing**: Accurate measurements
   - **Database Systems**: Data storage
   - **Game Development**: Entity properties

3. **Benefits in Development**:
   - **Better Memory Management**: Right-sized storage
   - **Fewer Bugs**: Type checking
   - **Clear Interfaces**: Type-based contracts
   - **Efficient Code**: Optimized operations
   - **Safe Conversions**: Controlled type changes

## Implementation Guide

You'll find the starter code in `Tutorials/Module01/Part3/types_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module01/Part3/types.cpp`.

### Overview
In this implementation, we'll explore and work with C++'s rich type system. We'll build programs that:
- Demonstrate all fundamental data types
- Create and use custom types
- Handle type conversions safely
- Show type limits and properties
- Implement type-safe operations

Through these examples, you'll learn:
- How to **choose appropriate types**
- *Work with type conversions* safely
- ***Critical type safety*** considerations
- Memory usage optimization
- Professional type handling

### Fundamental Types
First, let's explore the basic building blocks of C++ types. We'll cover:
- **Integer types** for whole numbers
- *Floating-point types* for decimals
- ***Character types*** for text
- Boolean type for logical values
- Size and range information

Let's examine each type in detail:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // Integer types
    int integer = 42;
    short smallInteger = 32767;
    long largeInteger = 2147483647L;
    long long veryLargeInteger = 9223372036854775807LL;
    
    // Floating-point types
    float decimal = 3.14159f;
    double preciseDecimal = 3.14159265359;
    long double veryPreciseDecimal = 3.14159265359L;
    
    // Character types
    char character = 'A';
    wchar_t wideChar = L'Ω';
    char16_t unicode16 = u'Ω';
    char32_t unicode32 = U'Ω';
    
    // Boolean type
    bool flag = true;
    
    // Size information
    cout << "Type Sizes:\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";
    cout << "char: " << sizeof(char) << " bytes\n";
    cout << "bool: " << sizeof(bool) << " bytes\n";
    
    // Range information
    cout << "\nType Ranges:\n";
    cout << "int: " << numeric_limits<int>::min() 
         << " to " << numeric_limits<int>::max() << "\n";
    cout << "float precision: " 
         << numeric_limits<float>::digits10 << " digits\n";
    
    return 0;
}
```

### User-Defined Types
Now we'll learn to create our own custom types. We'll explore:
- **Enumeration** for named constants
- *Structures* for data grouping
- ***Classes*** for encapsulation
- Unions for memory sharing
- Type safety patterns

Let's create some custom types:

```cpp
// Enumeration
enum class Color {
    Red,
    Green,
    Blue,
    Yellow
};

// Structure
struct Point {
    double x;
    double y;
    
    // Constructor
    Point(double x_val = 0, double y_val = 0) 
        : x(x_val), y(y_val) {}
        
    // Method
    double distanceFromOrigin() const {
        return sqrt(x*x + y*y);
    }
};

// Union
union DataValue {
    int i;
    float f;
    char c;
};

// Class
class Rectangle {
public:
    Rectangle(double w, double h) 
        : width(w), height(h) {}
    
    double getArea() const {
        return width * height;
    }
    
    double getPerimeter() const {
        return 2 * (width + height);
    }
    
private:
    double width;
    double height;
};
```

### Type Conversions
Type conversions require careful handling to prevent data loss. We'll learn:
- **Implicit vs explicit** conversions
- *Safe conversion* patterns
- ***Critical safety checks***
- Numeric type conversions
- Pointer type handling

Let's implement safe type conversions:

```cpp
#include <iostream>
using namespace std;

int main() {
    // Implicit conversions
    int i = 42;
    double d = i;    // int to double (safe)
    float f = d;     // double to float (possible precision loss)
    
    // Explicit conversions
    double pi = 3.14159;
    int rounded = static_cast<int>(pi);  // double to int
    
    // Numeric conversions
    long bigNum = 1234567890L;
    int normalNum = static_cast<int>(bigNum);  // Check range
    
    if (bigNum > numeric_limits<int>::max()) {
        cout << "Warning: Possible data loss in conversion\n";
    }
    
    // Character conversions
    char c = 'A';
    int ascii = static_cast<int>(c);  // char to int
    
    // Boolean conversions
    int zero = 0;
    bool isZero = (zero == 0);  // Comparison to bool
    
    // Pointer conversions
    int* ptr = nullptr;
    void* vptr = ptr;  // OK: implicit conversion
    int* back = static_cast<int*>(vptr);  // void* to int*
    
    return 0;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module01/Part3/practice_types_starter.cpp`
- Complete solution: `Tutorials/Module01/Part3/practice_types.cpp`

### Exercise 1: Type Calculator
Create a type information calculator:
1. Show information for:
   - Integer types
   - Floating types
   - Character types
   - Boolean type
2. Display ranges
3. Show memory sizes
4. Calculate limits
5. Demonstrate precision

Requirements:
1. All basic types
2. Range information
3. Size information
4. Precision details
5. Example values

### Exercise 2: Geometry System
Build a geometry calculation system:
1. Define types:
   - Point
   - Line
   - Circle
   - Rectangle
2. Implement calculations
3. Handle conversions
4. Validate input
5. Format output

Requirements:
1. Custom types
2. Safe conversions
3. Input validation
4. Error handling
5. Clear output

### Exercise 3: Data Converter
Create a data type converter:
1. Support conversions:
   - Numeric types
   - Character types
   - Custom types
2. Validate conversions
3. Handle errors
4. Show conversion info
5. Format output

Requirements:
1. Safe conversions
2. Error checking
3. Information display
4. Clean interface
5. Example usage

## Summary

### Key Concepts
1. **Fundamental Types**
   ```cpp
   // Integer types
   int i = 42;             // Basic integer
   short s = 100;          // Small integer
   long l = 1000L;         // Large integer
   long long ll = 1000LL;  // Very large integer
   
   // Floating-point types
   float f = 3.14f;        // Single precision
   double d = 3.14159;     // Double precision
   
   // Character types
   char c = 'A';           // Single character
   wchar_t w = L'Ω';       // Wide character
   
   // Boolean type
   bool flag = true;       // Logical value
   ```

2. **User-Defined Types**
   ```cpp
   // Enumeration
   enum class Color { Red, Green, Blue };
   
   // Structure
   struct Point {
       double x, y;
   };
   
   // Class
   class Circle {
       double radius;
   public:
       double getArea() const;
   };
   ```

3. **Type Conversions**
   ```cpp
   // Safe conversions
   int i = 42;
   double d = i;  // Implicit widening
   
   // Explicit conversions
   double pi = 3.14159;
   int rounded = static_cast<int>(pi);
   ```

### Common Pitfalls
1. **Implicit Conversions**
   ```cpp
   // Bad: Implicit narrowing
   double pi = 3.14159;
   int iPi = pi;  // Loss of precision

   // Good: Explicit conversion
   int iPi = static_cast<int>(pi);
   ```

2. **Type Overflow**
   ```cpp
   // Bad: No overflow check
   short s = 32767;
   s++;  // Undefined behavior

   // Good: Check limits
   if (s < numeric_limits<short>::max()) {
       s++;
   }
   ```

3. **Sign Issues**
   ```cpp
   // Bad: Sign mismatch
   unsigned int u = 10;
   int i = -5;
   if (u > i) {  // i converted to unsigned!

   // Good: Explicit comparison
   if (u > 0 && static_cast<int>(u) > i) {
   ```

### Best Practices
1. **Type Selection**
   ```cpp
   // Choose appropriate types
   int count = 0;         // Counting
   double price = 99.99;  // Money
   char grade = 'A';      // Single character
   bool isValid = true;   // Flags
   ```

2. **Type Safety**
   ```cpp
   // Use type-safe constructs
   enum class Status {
       Success,
       Failure,
       Pending
   };
   Status result = Status::Success;
   ```

3. **Conversions**
   ```cpp
   // Safe type conversions
   template<typename T>
   T safeCast(auto value) {
       if (value > numeric_limits<T>::max()) {
           throw overflow_error("Value too large");
       }
       return static_cast<T>(value);
   }
   ```

4. **Custom Types**
   ```cpp
   // Clear type definitions
   class Temperature {
       double value;
       string unit;
   public:
       Temperature(double v, string u);
   };
   ```

5. **Type Traits**
   ```cpp
   // Use type traits
   template<typename T>
   void processNumber(T value) {
       static_assert(is_arithmetic<T>::value,
                    "Arithmetic type required");
   }
   ```

## Next Steps
1. Complete all practice exercises
2. Test with various types
3. Study type conversions
4. Practice type safety
5. Implement custom types
6. Review type limits
7. Move on to [Part 4: Input and Output]({{ site.baseurl }}/tutorials/module1/part4-io)
