---
layout: default
title: Part 1 - Function Overriding (Runtime Polymorphism)
nav_order: 1
parent: Module 8 - Core OOP Concepts - Polymorphism
grand_parent: Tutorials
permalink: /tutorials/module8/part1-polymorphism/
---

# Part 1: Function Overriding (Runtime Polymorphism)

## Learning Objectives
- Understand the concept of polymorphism in object-oriented programming
- Master function overriding for runtime polymorphism
- Learn how to use base class pointers with derived objects
- Practice implementing polymorphic behavior
- Understand dynamic binding and virtual function tables
- Implement proper memory management with polymorphic objects
- Recognize and avoid common polymorphism pitfalls

## Introduction
Polymorphism is one of the fundamental concepts in object-oriented programming that allows objects of different classes to be treated as objects of a common base class. The term "polymorphism" comes from Greek words meaning "many forms," and it allows a single interface to represent different underlying forms (data types).

1. **Why Polymorphism Matters**:
   - **Flexibility**: Write code that works with base class and automatically works with all derived classes
   - **Extensibility**: Add new derived classes without changing existing code
   - **Abstraction**: Focus on what operations are performed rather than how they are performed
   - **Code Reuse**: Share common functionality while allowing specialized behavior
   - **Maintainability**: Changes to one class don't affect others

2. **Real-World Parallels**:
   - **Remote Control**: Same buttons control different devices
   - **Power Outlets**: Same interface powers different appliances
   - **Steering Wheel**: Same interface controls different vehicles
   - **Payment Processing**: Same payment interface handles different payment methods

3. **Benefits in Development**:
   - **Simplified Interfaces**: Interact with objects through common interfaces
   - **Reduced Complexity**: Eliminate type-specific code and conditionals
   - **Easier Maintenance**: Add new types without changing existing code
   - **Better Organization**: Group related classes in hierarchies
   - **Runtime Flexibility**: Determine behavior at runtime

## Understanding Polymorphism

### Types of Polymorphism

C++ supports two main types of polymorphism:

1. **Compile-time Polymorphism (Static Binding)**:
   - Function overloading
   - Operator overloading
   - Template functions
   - Resolved at compile time

2. **Runtime Polymorphism (Dynamic Binding)**:
   - Function overriding with virtual functions
   - Resolved at runtime
   - The focus of this tutorial

### Runtime Polymorphism Mechanism

Runtime polymorphism in C++ is achieved through:

1. **Inheritance**: Derived classes inherit from base classes
2. **Virtual Functions**: Base class declares functions that can be overridden
3. **Function Overriding**: Derived classes provide their own implementations
4. **Base Class Pointers/References**: Used to refer to derived class objects

```cpp
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

// Polymorphic usage
Shape* shape = new Circle();
shape->draw();  // Calls Circle::draw(), not Shape::draw()
```

### How It Works: Virtual Function Tables

When a class contains virtual functions, the compiler creates a virtual function table (vtable) for that class:

1. Each class with virtual functions has its own vtable
2. Each object of that class contains a hidden pointer (vptr) to the class's vtable
3. When a virtual function is called through a pointer/reference, the program:
   - Follows the vptr to find the vtable
   - Looks up the function in the vtable
   - Calls the correct implementation

```
Memory Layout:

+----------------+        +----------------+
| Shape Object   |        | Shape vtable   |
|----------------|        |----------------|
| vptr  ---------|------->| draw()         |
+----------------+        +----------------+

+----------------+        +----------------+
| Circle Object  |        | Circle vtable  |
|----------------|        |----------------|
| vptr  ---------|------->| draw()         |
| radius         |        +----------------+
+----------------+
```

## Implementation Guide

The `Tutorials/Module08/Part1/Learning/` directory contains starter files to help you learn about function overriding and polymorphism:

1. Start with these files:
   - `Shape_starter.h` and `Shape_starter.cpp`: Base class skeleton
   - `Circle_starter.h` and `Circle_starter.cpp`: Derived class skeleton
   - `Rectangle_starter.h` and `Rectangle_starter.cpp`: Another derived class skeleton
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Shape base class:
      - Add member variables
      - Define virtual methods
      - Implement constructor and destructor
   
   b. Move to Circle derived class:
      - Add specific members
      - Override virtual methods
      - Implement constructor and destructor
   
   c. Implement Rectangle derived class:
      - Add specific members
      - Override virtual methods
      - Implement constructor and destructor
   
   d. Complete the main program:
      - Create Shape pointers
      - Test polymorphic behavior
      - Verify proper cleanup

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o shape_demo main_starter.cpp Shape_starter.cpp Circle_starter.cpp Rectangle_starter.cpp
   
   # Run and verify output
   ./shape_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to understand polymorphic behavior

5. Reference Implementation:
   The completed versions (Shape.h, Shape.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study polymorphism patterns
   - Understand best practices

### Step 1: Base Class Implementation

```cpp
// Shape.h
class Shape {
protected:
    string color;
    int x, y;  // Position
    
public:
    // Constructor
    Shape(string color, int x, int y)
        : color(color), x(x), y(y) {
        cout << "Creating shape at (" << x << "," << y << ")" << endl;
    }
    
    // Virtual destructor - critical for polymorphic classes
    virtual ~Shape() {
        cout << "Destroying shape" << endl;
    }
    
    // Getters
    string getColor() const { return color; }
    int getX() const { return x; }
    int getY() const { return y; }
    
    // Virtual methods that can be overridden
    virtual void draw() const {
        cout << "Drawing a " << color << " shape at (" << x << "," << y << ")" << endl;
    }
    
    virtual double area() const {
        cout << "Shape area calculation not implemented" << endl;
        return 0.0;
    }
    
    virtual double perimeter() const {
        cout << "Shape perimeter calculation not implemented" << endl;
        return 0.0;
    }
    
    // Non-virtual method - cannot be overridden
    void move(int newX, int newY) {
        x = newX;
        y = newY;
        cout << "Moving shape to (" << x << "," << y << ")" << endl;
    }
};
```

Test Cases:
```cpp
// Create a Shape object
Shape* shape = new Shape("red", 0, 0);
shape->draw();
cout << "Area: " << shape->area() << endl;
cout << "Perimeter: " << shape->perimeter() << endl;
delete shape;

Expected Output:
Creating shape at (0,0)
Drawing a red shape at (0,0)
Shape area calculation not implemented
Area: 0
Shape perimeter calculation not implemented
Perimeter: 0
Destroying shape
```

### Step 2: Derived Class Implementation

```cpp
// Circle.h
class Circle : public Shape {
private:
    double radius;
    
public:
    // Constructor
    Circle(string color, int x, int y, double radius)
        : Shape(color, x, y), radius(radius) {
        cout << "Creating circle with radius " << radius << endl;
    }
    
    // Destructor
    ~Circle() override {
        cout << "Destroying circle" << endl;
    }
    
    // Getter
    double getRadius() const { return radius; }
    
    // Override base class virtual methods
    void draw() const override {
        cout << "Drawing a " << getColor() << " circle at (" 
             << getX() << "," << getY() << ") with radius " << radius << endl;
    }
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    // Circle-specific method
    void scale(double factor) {
        radius *= factor;
        cout << "Scaling circle to radius " << radius << endl;
    }
};

// Rectangle.h
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    // Constructor
    Rectangle(string color, int x, int y, double width, double height)
        : Shape(color, x, y), width(width), height(height) {
        cout << "Creating rectangle with width " << width 
             << " and height " << height << endl;
    }
    
    // Destructor
    ~Rectangle() override {
        cout << "Destroying rectangle" << endl;
    }
    
    // Getters
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    // Override base class virtual methods
    void draw() const override {
        cout << "Drawing a " << getColor() << " rectangle at (" 
             << getX() << "," << getY() << ") with width " << width 
             << " and height " << height << endl;
    }
    
    double area() const override {
        return width * height;
    }
    
    double perimeter() const override {
        return 2 * (width + height);
    }
    
    // Rectangle-specific method
    void resize(double newWidth, double newHeight) {
        width = newWidth;
        height = newHeight;
        cout << "Resizing rectangle to width " << width 
             << " and height " << height << endl;
    }
};
```

Test Cases:
```cpp
// Create a Circle object
Circle* circle = new Circle("blue", 5, 5, 10);
circle->draw();
cout << "Area: " << circle->area() << endl;
cout << "Perimeter: " << circle->perimeter() << endl;
circle->scale(2);
delete circle;

// Create a Rectangle object
Rectangle* rectangle = new Rectangle("green", 10, 10, 5, 3);
rectangle->draw();
cout << "Area: " << rectangle->area() << endl;
cout << "Perimeter: " << rectangle->perimeter() << endl;
rectangle->resize(10, 6);
delete rectangle;

Expected Output:
Creating shape at (5,5)
Creating circle with radius 10
Drawing a blue circle at (5,5) with radius 10
Area: 314.159
Perimeter: 62.8318
Scaling circle to radius 20
Destroying circle
Destroying shape

Creating shape at (10,10)
Creating rectangle with width 5 and height 3
Drawing a green rectangle at (10,10) with width 5 and height 3
Area: 15
Perimeter: 16
Resizing rectangle to width 10 and height 6
Destroying rectangle
Destroying shape
```

### Step 3: Polymorphic Behavior

```cpp
// main.cpp
int main() {
    // Create an array of Shape pointers
    const int NUM_SHAPES = 4;
    Shape* shapes[NUM_SHAPES];
    
    // Initialize with different shapes
    shapes[0] = new Shape("yellow", 0, 0);
    shapes[1] = new Circle("red", 10, 10, 5);
    shapes[2] = new Rectangle("blue", 20, 20, 7, 3);
    shapes[3] = new Circle("green", 15, 15, 10);
    
    // Polymorphic behavior - same code works for all shapes
    cout << "\nDrawing all shapes:" << endl;
    for (int i = 0; i < NUM_SHAPES; i++) {
        shapes[i]->draw();
    }
    
    cout << "\nCalculating areas:" << endl;
    for (int i = 0; i < NUM_SHAPES; i++) {
        cout << "Shape " << i << " area: " << shapes[i]->area() << endl;
    }
    
    cout << "\nMoving all shapes:" << endl;
    for (int i = 0; i < NUM_SHAPES; i++) {
        shapes[i]->move(i * 10, i * 10);
    }
    
    // Type-specific operations require downcasting
    cout << "\nPerforming type-specific operations:" << endl;
    for (int i = 0; i < NUM_SHAPES; i++) {
        // Try to downcast to Circle
        Circle* circle = dynamic_cast<Circle*>(shapes[i]);
        if (circle) {
            cout << "Found a circle. Scaling it by 2..." << endl;
            circle->scale(2);
        }
        
        // Try to downcast to Rectangle
        Rectangle* rectangle = dynamic_cast<Rectangle*>(shapes[i]);
        if (rectangle) {
            cout << "Found a rectangle. Resizing it..." << endl;
            rectangle->resize(rectangle->getWidth() * 1.5, rectangle->getHeight() * 1.5);
        }
    }
    
    // Clean up
    cout << "\nCleaning up:" << endl;
    for (int i = 0; i < NUM_SHAPES; i++) {
        delete shapes[i];  // Calls the appropriate destructor
    }
    
    return 0;
}
```

Expected Output:
```
Creating shape at (0,0)
Creating shape at (10,10)
Creating circle with radius 5
Creating shape at (20,20)
Creating rectangle with width 7 and height 3
Creating shape at (15,15)
Creating circle with radius 10

Drawing all shapes:
Drawing a yellow shape at (0,0)
Drawing a red circle at (10,10) with radius 5
Drawing a blue rectangle at (20,20) with width 7 and height 3
Drawing a green circle at (15,15) with radius 10

Calculating areas:
Shape 0 area: 0
Shape 1 area: 78.5398
Shape 2 area: 21
Shape 3 area: 314.159

Moving all shapes:
Moving shape to (0,0)
Moving shape to (10,10)
Moving shape to (20,20)
Moving shape to (30,30)

Performing type-specific operations:
Found a circle. Scaling it by 2...
Scaling circle to radius 10
Found a rectangle. Resizing it...
Resizing rectangle to width 10.5 and height 4.5
Found a circle. Scaling it by 2...
Scaling circle to radius 20

Cleaning up:
Destroying shape
Destroying circle
Destroying shape
Destroying rectangle
Destroying shape
Destroying circle
Destroying shape
```

### Step 4: Dynamic Casting and Type Identification

C++ provides mechanisms to safely work with polymorphic objects:

1. **dynamic_cast**: Safely converts pointers/references within an inheritance hierarchy
   ```cpp
   Shape* shape = new Circle("red", 0, 0, 5);
   
   // Safe downcasting
   Circle* circle = dynamic_cast<Circle*>(shape);
   if (circle) {
       // This is indeed a Circle
       circle->scale(2);
   }
   ```

2. **typeid**: Identifies the actual type of an object at runtime
   ```cpp
   Shape* shape = new Circle("red", 0, 0, 5);
   
   if (typeid(*shape) == typeid(Circle)) {
       cout << "This is a Circle" << endl;
   }
   
   cout << "Type name: " << typeid(*shape).name() << endl;
   ```

3. **When to use**:
   - Use dynamic_cast when you need to access derived class functionality
   - Use typeid when you need to identify the exact type
   - Both require the base class to have at least one virtual function

### Step 5: Virtual Destructors

Virtual destructors are crucial for polymorphic classes:

```cpp
// Without virtual destructor
class Base {
public:
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor" << endl; }
};

Base* obj = new Derived();
delete obj;  // Only calls Base destructor, memory leak!

// Output:
// Base destructor

// With virtual destructor
class Base {
public:
    virtual ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    ~Derived() override { cout << "Derived destructor" << endl; }
};

Base* obj = new Derived();
delete obj;  // Calls both destructors in correct order

// Output:
// Derived destructor
// Base destructor
```

## Practice Exercises

The `Tutorials/Module08/Part1/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., Character_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your class hierarchy
      - Define virtual methods
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement all required methods
      - Add proper constructors/destructors
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -o exercise1 main_starter.cpp Character_starter.cpp Warrior_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand polymorphic behavior
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Game Character System

Create a game character system with the following classes:
- `Character` (base class)
- `Warrior` (derived from Character)
- `Mage` (derived from Character)
- `Archer` (derived from Character)

### Exercise 2: Vehicle Hierarchy

Implement a vehicle classification system:
- `Vehicle` (base class)
- `Car` (derived from Vehicle)
- `Motorcycle` (derived from Vehicle)
- `Truck` (derived from Vehicle)

### Exercise 3: Shape Drawing System

Create a shape drawing system:
- `Shape` (base class)
- `Circle` (derived from Shape)
- `Rectangle` (derived from Shape)
- `Triangle` (derived from Shape)

## Summary

### Key Concepts

1. **Runtime Polymorphism**
   - Achieved through virtual functions
   - Allows different behaviors through same interface
   - Determined at runtime
   - Requires inheritance hierarchy
   - Uses base class pointers/references

2. **Virtual Functions**
   - Declared with 'virtual' keyword
   - Can be overridden in derived classes
   - Enable polymorphic behavior
   - Implemented using vtables
   - Slight performance overhead

3. **Dynamic Binding**
   - Function call resolved at runtime
   - Based on actual object type
   - Allows for extensible code
   - Supports "open-closed principle"
   - Core mechanism of polymorphism

4. **Type Safety**
   - dynamic_cast for safe downcasting
   - typeid for runtime type identification
   - Requires RTTI (Runtime Type Information)
   - Helps prevent type-related errors
   - Enables type-specific operations

5. **Memory Management**
   - Virtual destructors essential
   - Proper cleanup of derived objects
   - Prevents memory leaks
   - Ensures complete object destruction
   - Required for polymorphic classes

### Common Pitfalls

1. **Missing Virtual Destructors**
   ```cpp
   // Wrong! No virtual destructor
   class Base {
       ~Base() { }  // Should be virtual
   };
   
   // Correct
   class Base {
       virtual ~Base() { }
   };
   ```

2. **Forgetting Override Keyword**
   ```cpp
   // Wrong! No override keyword
   class Derived : public Base {
       void draw() { }  // No compile error if signature changes
   };
   
   // Correct
   class Derived : public Base {
       void draw() override { }  // Compiler checks signature
   };
   ```

3. **Slicing Problem**
   ```cpp
   // Wrong! Object slicing
   void processShape(Shape shape) {  // Passed by value
       shape.draw();  // Always calls Shape::draw()
   }
   
   // Correct
   void processShape(Shape& shape) {  // Passed by reference
       shape.draw();  // Calls appropriate override
   }
   ```

4. **Incorrect Downcasting**
   ```cpp
   // Wrong! Unsafe cast
   Shape* shape = new Circle();
   Circle* circle = (Circle*)shape;  // C-style cast, dangerous
   
   // Correct
   Circle* circle = dynamic_cast<Circle*>(shape);
   if (circle) {  // Check if cast succeeded
       // Use circle
   }
   ```

5. **Calling Virtual Functions in Constructors/Destructors**
   ```cpp
   // Wrong! Virtual call in constructor
   class Base {
   public:
       Base() {
           draw();  // Calls Base::draw(), not Derived::draw()
       }
       virtual void draw() { }
   };
   ```

### Best Practices
1. Always use virtual destructors in base classes
2. Use override keyword for all overridden methods
3. Pass polymorphic objects by reference or pointer
4. Use dynamic_cast for type-safe downcasting
5. Check dynamic_cast results before using
6. Avoid calling virtual functions in constructors/destructors
7. Keep inheritance hierarchies shallow
8. Use const-correctness for methods
9. Consider alternatives to deep hierarchies
10. Document polymorphic behavior clearly

## Next Steps
1. Complete all practice exercises
2. Test with various scenarios
3. Review virtual function mechanics
4. Study polymorphic design patterns
5. Move on to [Part 2: Virtual Functions]({{ site.baseurl }}/tutorials/module8/part2-virtual-functions)

Remember: Polymorphism is a powerful tool for creating flexible, extensible code. Take time to understand its mechanics and proper implementation.
