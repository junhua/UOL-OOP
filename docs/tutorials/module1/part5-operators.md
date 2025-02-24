---
layout: default
title: Part 5 - Operators
nav_order: 5
parent: Module 1 - Introduction to C++
grand_parent: Tutorials
permalink: /tutorials/module1/part5-operators/
---

# Part 5: Operators

## Learning Objectives
- Master C++ operators and their usage
- Understand operator precedence
- Learn type conversion rules
- Implement operator overloading
- Practice safe operator usage
- Handle operation errors
- Create custom operators

## Introduction
Operators in C++ are like the tools in a toolbox, each designed for specific operations. Think of them as:

1. **Why Operators Matter**:
   - **Computation**: Perform calculations
   - **Comparison**: Make decisions
   - **Logic**: Control program flow
   - **Manipulation**: Transform data
   - **Assignment**: Modify values

2. **Real-World Applications**:
   - **Calculator**: Mathematical operations
   - **Game Logic**: Collision detection
   - **Data Processing**: Value comparisons
   - **Graphics**: Coordinate manipulation
   - **Finance**: Currency calculations

3. **Benefits in Development**:
   - **Clear Code**: Expressive operations
   - **Efficient Logic**: Compact expressions
   - **Type Safety**: Controlled conversions
   - **Custom Types**: Extended operations
   - **Clean Syntax**: Readable code

## Implementation Guide

You'll find the starter code in `Tutorials/Module01/Part5/operators_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module01/Part5/operators.cpp`.

### Arithmetic Operators
Basic mathematical operations:

```cpp
#include <iostream>
using namespace std;

int main() {
    // Basic arithmetic
    int a = 10, b = 3;
    
    cout << "Arithmetic Operations:" << endl;
    cout << "Addition: " << a + b << endl;        // 13
    cout << "Subtraction: " << a - b << endl;     // 7
    cout << "Multiplication: " << a * b << endl;  // 30
    cout << "Division: " << a / b << endl;        // 3
    cout << "Modulus: " << a % b << endl;         // 1
    
    // Increment/Decrement
    int x = 5;
    cout << "\nIncrement/Decrement:" << endl;
    cout << "Pre-increment: " << ++x << endl;  // 6
    cout << "Post-increment: " << x++ << endl; // 6 (then 7)
    cout << "Pre-decrement: " << --x << endl;  // 6
    cout << "Post-decrement: " << x-- << endl; // 6 (then 5)
    
    // Compound assignment
    x = 5;
    cout << "\nCompound Assignment:" << endl;
    cout << "Initial value: " << x << endl;    // 5
    x += 3;  // x = x + 3
    cout << "After += 3: " << x << endl;       // 8
    x *= 2;  // x = x * 2
    cout << "After *= 2: " << x << endl;       // 16
    
    return 0;
}
```

### Relational and Logical Operators
Compare values and combine conditions:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;
    bool flag1 = true, flag2 = false;
    
    // Relational operators
    cout << "Relational Operations:" << endl;
    cout << "Equal to: " << (a == b) << endl;         // 0
    cout << "Not equal to: " << (a != b) << endl;     // 1
    cout << "Greater than: " << (a > b) << endl;      // 0
    cout << "Less than: " << (a < b) << endl;         // 1
    cout << "Greater/equal: " << (a >= b) << endl;    // 0
    cout << "Less/equal: " << (a <= b) << endl;       // 1
    
    // Logical operators
    cout << "\nLogical Operations:" << endl;
    cout << "AND: " << (flag1 && flag2) << endl;      // 0
    cout << "OR: " << (flag1 || flag2) << endl;       // 1
    cout << "NOT: " << (!flag1) << endl;              // 0
    
    // Short-circuit evaluation
    int x = 5;
    cout << "\nShort-circuit evaluation:" << endl;
    
    // Second part not evaluated if first is false
    if (x > 10 && ++x > 6) {
        cout << "Not reached" << endl;
    }
    cout << "x after &&: " << x << endl;  // Still 5
    
    // Second part not evaluated if first is true
    if (x < 10 || ++x > 6) {
        cout << "Reached" << endl;
    }
    cout << "x after ||: " << x << endl;  // Still 5
    
    return 0;
}
```

### Bitwise Operators
Manipulate individual bits:

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    unsigned char a = 0b00001111;  // 15
    unsigned char b = 0b00110011;  // 51
    
    cout << "Bitwise Operations:" << endl;
    cout << "a = " << bitset<8>(a) << endl;
    cout << "b = " << bitset<8>(b) << endl;
    
    // Bitwise AND
    cout << "AND: " << bitset<8>(a & b) << endl;
    
    // Bitwise OR
    cout << "OR:  " << bitset<8>(a | b) << endl;
    
    // Bitwise XOR
    cout << "XOR: " << bitset<8>(a ^ b) << endl;
    
    // Bitwise NOT
    cout << "NOT a: " << bitset<8>(~a) << endl;
    
    // Left shift
    cout << "Left shift a << 2: " 
         << bitset<8>(a << 2) << endl;
    
    // Right shift
    cout << "Right shift b >> 1: " 
         << bitset<8>(b >> 1) << endl;
    
    // Bit manipulation
    unsigned char flags = 0;
    
    // Set bit
    flags |= (1 << 3);  // Set bit 3
    cout << "\nAfter setting bit 3: " 
         << bitset<8>(flags) << endl;
    
    // Clear bit
    flags &= ~(1 << 3);  // Clear bit 3
    cout << "After clearing bit 3: " 
         << bitset<8>(flags) << endl;
    
    // Toggle bit
    flags ^= (1 << 4);  // Toggle bit 4
    cout << "After toggling bit 4: " 
         << bitset<8>(flags) << endl;
    
    // Check bit
    bool isBitSet = (flags & (1 << 4)) != 0;
    cout << "Is bit 4 set? " << isBitSet << endl;
    
    return 0;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module01/Part5/practice_operators_starter.cpp`
- Complete solution: `Tutorials/Module01/Part5/practice_operators.cpp`

### Exercise 1: Calculator
Create a scientific calculator:
1. Support operations:
   - Basic arithmetic
   - Power functions
   - Root calculations
   - Trigonometry
   - Logarithms
2. Handle errors
3. Format output
4. Validate input
5. Show steps

Requirements:
1. All operations
2. Error handling
3. Precision control
4. Input validation
5. Clear output

### Exercise 2: Bit Manipulator
Build a bit manipulation tool:
1. Support operations:
   - Set bits
   - Clear bits
   - Toggle bits
   - Check bits
   - Shift operations
2. Show binary
3. Handle errors
4. Format output
5. Validate input

Requirements:
1. All bit operations
2. Binary display
3. Error checking
4. Clear interface
5. Input validation

### Exercise 3: Vector Calculator
Create a vector mathematics system:
1. Support operations:
   - Addition
   - Subtraction
   - Dot product
   - Cross product
   - Scaling
2. Handle vectors
3. Show results
4. Validate operations
5. Format output

Requirements:
1. Vector operations
2. Error handling
3. Result display
4. Input validation
5. Clear interface

## Common Pitfalls

1. **Division by Zero**
```cpp
// Bad: No check for zero
int result = a / b;  // Crash if b is 0

// Good: Check denominator
if (b != 0) {
    result = a / b;
} else {
    cerr << "Error: Division by zero" << endl;
}
```

2. **Integer Division**
```cpp
// Bad: Integer division truncates
int result = 5 / 2;  // Result is 2

// Good: Use appropriate types
double result = 5.0 / 2.0;  // Result is 2.5
```

3. **Operator Precedence**
```cpp
// Bad: Unclear precedence
int result = a + b * c;

// Good: Use parentheses for clarity
int result = a + (b * c);
```

## Best Practices

1. **Type Safety**
```cpp
// Use appropriate types
template<typename T>
T safeAdd(T a, T b) {
    if (numeric_limits<T>::max() - a < b) {
        throw overflow_error("Addition would overflow");
    }
    return a + b;
}
```

2. **Clear Operations**
```cpp
// Make operations explicit
int calculateTotal(int quantity, int price) {
    return quantity * price;  // Clear intent
}

// Use compound assignments when appropriate
total += item.price;  // Instead of total = total + item.price
```

3. **Bitwise Operations**
```cpp
// Use named constants for bits
enum Flags {
    READ   = 1 << 0,  // 0b00000001
    WRITE  = 1 << 1,  // 0b00000010
    EXECUTE = 1 << 2  // 0b00000100
};

// Use clear bit manipulation
permissions |= READ;    // Set read permission
permissions &= ~WRITE;  // Clear write permission
```

4. **Comparison Safety**
```cpp
// Safe floating-point comparison
bool almostEqual(double a, double b, double epsilon = 0.0001) {
    return abs(a - b) < epsilon;
}

// Safe pointer comparison
if (ptr != nullptr && *ptr > 0) {
    // Safe to dereference
}
```

5. **Operator Overloading**
```cpp
class Vector {
    double x, y;
public:
    // Clear operator overloading
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }
    
    Vector& operator+=(const Vector& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
};
```

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Study operator precedence
5. Practice bit manipulation
6. Implement custom operators
7. Move on to [Part 6: Comments and Documentation]({{ site.baseurl }}/tutorials/module1/part6-comments)
