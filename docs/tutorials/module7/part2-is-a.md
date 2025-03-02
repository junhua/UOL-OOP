---
layout: default
title: Part 2 - "is-a" Relationship
nav_order: 2
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part2-is-a/
---

# Part 2: "is-a" Relationship

## Learning Objectives
- Understand the "is-a" relationship in inheritance
- Master proper inheritance hierarchies
- Learn when to use inheritance vs composition
- Practice designing class hierarchies
- Implement LSP (Liskov Substitution Principle)
- Document inheritance relationships effectively
- Recognize and avoid inheritance pitfalls

## Introduction
The "is-a" relationship is a fundamental concept in inheritance that helps determine whether inheritance is appropriate for your class design. Think of it like biological classification:

1. **Why "is-a" Matters**:
   - **Proper Modeling**: Ensures logical class relationships
   - **Code Organization**: Creates meaningful hierarchies
   - **Maintainability**: Makes code easier to understand and modify
   - **Polymorphism**: Enables proper substitution
   - **Design Clarity**: Makes relationships obvious

2. **Real-World Parallels**:
   - **Animal Kingdom**: Dog "is-a" Animal
   - **Vehicle Types**: Car "is-a" Vehicle
   - **Shapes**: Circle "is-a" Shape
   - **Employees**: Manager "is-a" Employee

3. **Benefits in Development**:
   - **Clear Relationships**: Easy to understand connections
   - **Code Reuse**: Share common functionality
   - **Type Safety**: Compiler can check relationships
   - **Polymorphic Behavior**: Use base class pointers
   - **Extensibility**: Add new derived classes easily

## Understanding "is-a" vs "has-a" Relationships

### "is-a" Relationship (Inheritance)
An "is-a" relationship indicates that one class is a specialized type of another class. This is implemented through inheritance.

```cpp
// "is-a" relationship examples:
class Animal { /* ... */ };
class Dog : public Animal { /* ... */ };  // Dog IS-A Animal

class Vehicle { /* ... */ };
class Car : public Vehicle { /* ... */ };  // Car IS-A Vehicle

class Employee { /* ... */ };
class Manager : public Employee { /* ... */ };  // Manager IS-A Employee
```

Key characteristics:
- Derived class inherits all base class properties and behaviors
- Derived class can be used wherever base class is expected
- Derived class can extend or override base class functionality
- Represents specialization or refinement

### "has-a" Relationship (Composition)
A "has-a" relationship indicates that one class contains an instance of another class as a member. This is implemented through composition.

```cpp
// "has-a" relationship examples:
class Engine { /* ... */ };
class Car {
private:
    Engine engine;  // Car HAS-A Engine
};

class Employee { /* ... */ };
class Department {
private:
    vector<Employee*> employees;  // Department HAS-A collection of Employees
};
```

Key characteristics:
- Container class has member variables of the contained class
- Container class delegates to contained class for functionality
- Represents ownership or containment
- More flexible than inheritance in many cases

### When to Choose Which Relationship

| Criteria | Use "is-a" (Inheritance) | Use "has-a" (Composition) |
|----------|--------------------------|---------------------------|
| Relationship | Specialization/refinement | Containment/delegation |
| Code reuse | Inherit implementation | Delegate to implementation |
| Coupling | Tighter coupling | Looser coupling |
| Flexibility | Less flexible | More flexible |
| Runtime changes | Fixed at compile time | Can change at runtime |
| Example | Dog is an Animal | Car has an Engine |

## The Liskov Substitution Principle (LSP)

The Liskov Substitution Principle is a fundamental principle of object-oriented design, formulated by Barbara Liskov:

> If S is a subtype of T, then objects of type T may be replaced with objects of type S without altering any of the desirable properties of the program.

In simpler terms: **Any derived class should be able to substitute for its base class without changing the correctness of the program.**

### LSP Requirements

For a derived class to satisfy LSP:

1. **Preconditions cannot be strengthened**
   - Derived methods cannot demand more than base methods

2. **Postconditions cannot be weakened**
   - Derived methods must fulfill at least the same guarantees

3. **Invariants must be preserved**
   - Properties that are true for the base class must remain true

4. **History constraint (no new methods that modify base state)**
   - Derived class shouldn't modify base class state in unexpected ways

### LSP Violation Example: Rectangle and Square

A classic example of LSP violation is the Rectangle-Square problem:

```cpp
class Rectangle {
protected:
    int width;
    int height;
    
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
    int getArea() const { return width * height; }
};

// Square IS-A Rectangle, right? (Mathematically yes, but...)
class Square : public Rectangle {
public:
    Square(int side) : Rectangle(side, side) {}
    
    // Square must maintain equal sides, so override setters
    void setWidth(int w) override {
        width = w;
        height = w;  // Must keep sides equal
    }
    
    void setHeight(int h) override {
        width = h;  // Must keep sides equal
        height = h;
    }
};
```

The LSP violation occurs when client code expects Rectangle behavior:

```cpp
void resizeRectangle(Rectangle& r) {
    r.setWidth(10);
    r.setHeight(5);
    assert(r.getArea() == 50);  // Fails for Square!
}

Rectangle rect(3, 4);
resizeRectangle(rect);  // Works fine

Square square(4);
resizeRectangle(square);  // Assertion fails! Area will be 25, not 50
```

This violates LSP because a Square cannot be substituted for a Rectangle without breaking the program's correctness.

### Fixing LSP Violations

Options to fix LSP violations:

1. **Redesign the hierarchy**
   ```cpp
   class Shape {
       virtual int getArea() const = 0;
   };
   
   class Rectangle : public Shape {
       // Rectangle implementation
   };
   
   class Square : public Shape {  // Not derived from Rectangle
       // Square implementation
   }
   ```

2. **Use composition instead of inheritance**
   ```cpp
   class Square {
   private:
       Rectangle rectangle;  // Composition
   
   public:
       Square(int side) : rectangle(side, side) {}
       
       void setSide(int side) {
           rectangle.setWidth(side);
           rectangle.setHeight(side);
       }
   };
   ```

3. **Make base class immutable**
   ```cpp
   class Rectangle {
   private:  // No setters
       int width;
       int height;
       
   public:
       Rectangle(int w, int h) : width(w), height(h) {}
       int getArea() const { return width * height; }
   };
   ```

## Implementation Guide

The `Tutorials/Module07/Part2/Learning/` directory contains starter files to help you learn about inheritance and "is-a" relationships:

1. Start with these files:
   - `Shape_starter.h` and `Shape_starter.cpp`: Base class skeleton
   - `Circle_starter.h` and `Circle_starter.cpp`: Derived class skeleton
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Shape base class:
      - Add color member variable
      - Implement constructor and destructor
      - Define pure virtual methods
   
   b. Move to Circle derived class:
      - Add radius member
      - Implement constructor and destructor
      - Override virtual methods
   
   c. Complete the main program:
      - Create Shape pointers
      - Test polymorphic behavior
      - Verify proper cleanup

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o shape_demo main_starter.cpp Shape_starter.cpp Circle_starter.cpp
   
   # Run and verify output
   ./shape_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to understand inheritance flow

5. Reference Implementation:
   The completed versions (Shape.h, Shape.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study proper inheritance patterns
   - Understand best practices

### Step 1: Basic "is-a" Relationship

```cpp
// Base class representing a general shape
class Shape {
protected:
    string color;
    
public:
    Shape(string c) : color(c) {
        cout << "Creating shape with color: " << color << endl;
    }
    
    virtual ~Shape() {
        cout << "Destroying shape" << endl;
    }
    
    string getColor() const { return color; }
    
    // Pure virtual methods - must be implemented by derived classes
    virtual double getArea() const = 0;
    virtual void draw() const = 0;
};

// Circle "is-a" Shape - valid inheritance relationship
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string color, double r) : Shape(color), radius(r) {
        cout << "Creating circle with radius: " << radius << endl;
    }
    
    ~Circle() override {
        cout << "Destroying circle" << endl;
    }
    
    double getRadius() const { return radius; }
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " circle with radius " << radius << endl;
    }
};
```

Test Cases:
```cpp
// Direct object usage
Circle circle("red", 5);
cout << "Area: " << circle.getArea() << endl;
circle.draw();

// Polymorphic usage through base pointer
Shape* shape = new Circle("blue", 3);
shape->draw();
cout << "Area: " << shape->getArea() << endl;
delete shape;

Expected Output:
Creating shape with color: red
Creating circle with radius: 5
Area: 78.53975
Drawing red circle with radius 5
Creating shape with color: blue
Creating circle with radius: 3
Drawing blue circle with radius 3
Area: 28.27431
Destroying circle
Destroying shape
```

### Step 2: Multiple Level Inheritance

```cpp
// Animal hierarchy demonstrating multi-level "is-a"
class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {
        cout << "Creating animal: " << name << endl;
    }
    
    virtual ~Animal() {
        cout << "Destroying animal: " << name << endl;
    }
    
    string getName() const { return name; }
    int getAge() const { return age; }
    
    // Pure virtual methods
    virtual void makeSound() const = 0;
    virtual void move() const = 0;
};

// Mammal "is-a" Animal
class Mammal : public Animal {
protected:
    bool hasFur;
    
public:
    Mammal(string n, int a, bool f) 
        : Animal(n, a), hasFur(f) {
        cout << "Creating mammal" << endl;
    }
    
    ~Mammal() override {
        cout << "Destroying mammal" << endl;
    }
    
    bool getHasFur() const { return hasFur; }
    
    // Additional method specific to mammals
    virtual void nurse() const {
        cout << name << " is nursing young" << endl;
    }
    
    // Note: makeSound() and move() are still abstract
    // Mammal doesn't implement them, so it's still an abstract class
};

// Dog "is-a" Mammal
class Dog : public Mammal {
private:
    string breed;
    
public:
    Dog(string n, int a, string b) 
        : Mammal(n, a, true), breed(b) {
        cout << "Creating dog of breed: " << breed << endl;
    }
    
    ~Dog() override {
        cout << "Destroying dog" << endl;
    }
    
    string getBreed() const { return breed; }
    
    // Implement required abstract methods
    void makeSound() const override {
        cout << name << " barks!" << endl;
    }
    
    void move() const override {
        cout << name << " runs on four legs" << endl;
    }
    
    // Override Mammal's method with more specific behavior
    void nurse() const override {
        cout << name << " the " << breed << " is nursing puppies" << endl;
    }
};
```

Test Cases:
```cpp
// Create a Dog object
Dog dog("Rex", 3, "German Shepherd");

// Test methods from all levels of the hierarchy
cout << "Name: " << dog.getName() << endl;
cout << "Age: " << dog.getAge() << endl;
cout << "Has fur: " << (dog.getHasFur() ? "Yes" : "No") << endl;
cout << "Breed: " << dog.getBreed() << endl;

// Test behaviors
dog.makeSound();
dog.move();
dog.nurse();

// Polymorphic usage
Animal* animal = &dog;
animal->makeSound();
animal->move();

// Note: animal->nurse() won't compile - not part of Animal interface

Expected Output:
Creating animal: Rex
Creating mammal
Creating dog of breed: German Shepherd
Name: Rex
Age: 3
Has fur: Yes
Breed: German Shepherd
Rex barks!
Rex runs on four legs
Rex the German Shepherd is nursing puppies
Rex barks!
Rex runs on four legs
```

### Step 3: Testing "is-a" Relationships

To determine if an "is-a" relationship is valid, ask these questions:

1. **Substitution Test**: Can the derived class be used anywhere the base class is expected?
2. **Behavior Test**: Does the derived class maintain the expected behavior of the base class?
3. **Logical Test**: Does the relationship make sense in the real world?
4. **LSP Test**: Does the derived class satisfy the Liskov Substitution Principle?

```cpp
// Valid "is-a" relationship example
class Employee {
protected:
    string name;
    double salary;
    
public:
    Employee(string n, double s) : name(n), salary(s) {}
    virtual ~Employee() {}
    
    string getName() const { return name; }
    double getSalary() const { return salary; }
    
    virtual void work() const = 0;
    virtual double calculatePay() const = 0;
};

// Manager "is-a" Employee - Valid
class Manager : public Employee {
private:
    vector<Employee*> team;
    double bonus;
    
public:
    Manager(string n, double s, double b) 
        : Employee(n, s), bonus(b) {}
    
    void addTeamMember(Employee* emp) {
        team.push_back(emp);
    }
    
    void work() const override {
        cout << name << " is managing the team of " << team.size() << " employees" << endl;
    }
    
    double calculatePay() const override {
        return salary + bonus;
    }
};

// Invalid "is-a" relationship example
class Company : public Employee {  // Wrong! Company is not an Employee
    // This violates "is-a" relationship
    // A company doesn't have a name and salary in the same sense as an employee
    // A company doesn't "work" like an employee
};

// Better approach: Composition
class Company {
private:
    string name;
    vector<Employee*> employees;  // Company HAS-A collection of employees
    
public:
    Company(string n) : name(n) {}
    
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }
    
    void listEmployees() const {
        cout << "Employees at " << name << ":" << endl;
        for (const auto& emp : employees) {
            cout << "- " << emp->getName() << endl;
        }
    }
};
```

## Alternatives to Inheritance

When "is-a" doesn't quite fit, consider these alternatives:

### 1. Composition (has-a)

```cpp
// Instead of inheritance
class Logger {
    // Logging functionality
};

// Don't do this:
class FileProcessor : public Logger { }; // FileProcessor is not a Logger

// Do this instead:
class FileProcessor {
private:
    Logger logger;  // FileProcessor has-a Logger
    
public:
    void process(const string& filename) {
        logger.log("Processing file: " + filename);
        // Processing logic
    }
};
```

### 2. Delegation

```cpp
class TextFormatter {
public:
    string formatBold(const string& text) { return "**" + text + "**"; }
    string formatItalic(const string& text) { return "*" + text + "*"; }
    // More formatting methods
};

class Document {
private:
    TextFormatter formatter;  // Delegation target
    
public:
    // Delegate formatting to the TextFormatter
    string formatBold(const string& text) {
        return formatter.formatBold(text);
    }
    
    string formatItalic(const string& text) {
        return formatter.formatItalic(text);
    }
};
```

### 3. Interface Implementation

```cpp
// Define interface using abstract class
class Drawable {
public:
    virtual ~Drawable() {}
    virtual void draw() const = 0;
};

class Movable {
public:
    virtual ~Movable() {}
    virtual void move(double x, double y) = 0;
};

// Implement interfaces without inheritance hierarchy
class Circle : public Drawable, public Movable {
private:
    double x, y, radius;
    
public:
    Circle(double x, double y, double r) : x(x), y(y), radius(r) {}
    
    void draw() const override {
        cout << "Drawing circle at (" << x << "," << y << ") with radius " << radius << endl;
    }
    
    void move(double newX, double newY) override {
        x = newX;
        y = newY;
    }
};
```

### 4. Strategy Pattern

```cpp
// Define strategy interface
class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sort(vector<int>& data) = 0;
};

// Concrete strategies
class QuickSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "Sorting using QuickSort" << endl;
        // QuickSort implementation
    }
};

class MergeSort : public SortStrategy {
public:
    void sort(vector<int>& data) override {
        cout << "Sorting using MergeSort" << endl;
        // MergeSort implementation
    }
};

// Context class uses strategy
class Sorter {
private:
    SortStrategy* strategy;
    
public:
    Sorter(SortStrategy* s) : strategy(s) {}
    
    void setStrategy(SortStrategy* s) {
        strategy = s;
    }
    
    void performSort(vector<int>& data) {
        strategy->sort(data);
    }
};
```

## Practice Exercises

After completing the Learning implementation, move on to the exercises in `Tutorials/Module07/Part2/Practice/`:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., Shape_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your class hierarchy
      - Define class relationships
   
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
   # Exercise 1: Shape Hierarchy
   g++ -o shape_test Shape.cpp main.cpp
   ./shape_test
   
   # Exercise 2: Vehicle System
   g++ -o vehicle_test Vehicle.cpp main.cpp
   ./vehicle_test
   
   # Exercise 3: Banking System
   g++ -o banking_test Account.cpp main.cpp
   ./banking_test
   ```

4. Learning Path:
   - Complete exercises in order (Shape → Vehicle → Banking)
   - Each exercise builds on previous concepts
   - Use debugger to understand inheritance flow
   - Compare your solution with provided implementations
   - Test thoroughly before moving to next exercise

### Exercise 1: Shape Hierarchy
Create a shape hierarchy with proper "is-a" relationships:

```cpp
// TODO: Implement these classes with proper "is-a" relationships
class Shape;        // Base class
class Circle;       // Circle is-a Shape
class Rectangle;    // Rectangle is-a Shape
class Square;       // Square is-a Rectangle (not Shape directly)
```

### Exercise 2: Vehicle System
Implement a vehicle classification system:

```cpp
// TODO: Implement these classes
class Vehicle;      // Base class
class LandVehicle;  // LandVehicle is-a Vehicle
class Car;          // Car is-a LandVehicle
class Motorcycle;   // Motorcycle is-a LandVehicle
```

### Exercise 3: Banking System
Create a banking system with proper inheritance:

```cpp
// TODO: Implement these classes
class Account;          // Base class
class SavingsAccount;   // SavingsAccount is-a Account
class CheckingAccount;  // CheckingAccount is-a Account
class MoneyMarket;      // MoneyMarket is-a SavingsAccount
```

## Real-World Inheritance Example: GUI Framework

Here's a more complex example showing inheritance in a GUI framework:

```cpp
// Component hierarchy in a GUI framework
class Widget {
protected:
    int x, y, width, height;
    bool visible;
    
public:
    Widget(int x, int y, int w, int h) 
        : x(x), y(y), width(w), height(h), visible(true) {}
    
    virtual ~Widget() {}
    
    virtual void draw() const = 0;
    virtual void resize(int w, int h) {
        width = w;
        height = h;
    }
    
    virtual void move(int newX, int newY) {
        x = newX;
        y = newY;
    }
    
    virtual bool contains(int pointX, int pointY) const {
        return pointX >= x && pointX < x + width &&
               pointY >= y && pointY < y + height;
    }
    
    void show() { visible = true; }
    void hide() { visible = false; }
    bool isVisible() const { return visible; }
};

class Control : public Widget {
protected:
    bool enabled;
    string text;
    
public:
    Control(int x, int y, int w, int h, const string& t)
        : Widget(x, y, w, h), enabled(true), text(t) {}
    
    virtual void setEnabled(bool e) { enabled = e; }
    bool isEnabled() const { return enabled; }
    
    virtual void setText(const string& t) { text = t; }
    string getText() const { return text; }
    
    // Still abstract
};

class Button : public Control {
private:
    function<void()> clickHandler;
    
public:
    Button(int x, int y, int w, int h, const string& label)
        : Control(x, y, w, h, label), clickHandler(nullptr) {}
    
    void setClickHandler(function<void()> handler) {
        clickHandler = handler;
    }
    
    void click() {
        if (enabled && clickHandler) {
            clickHandler();
        }
    }
    
    void draw() const override {
        if (!visible) return;
        
        cout << "Drawing button at (" << x << "," << y << ") size " 
             << width << "x" << height << " with text: " << text;
        
        if (!enabled) {
            cout << " (disabled)";
        }
        cout << endl;
    }
};

class TextBox : public Control {
private:
    bool multiline;
    int maxLength;
    
public:
    TextBox(int x, int y, int w, int h, bool multi = false)
        : Control(x, y, w, h, ""), multiline(multi), maxLength(100) {}
    
    void setText(const string& t) override {
        // Enforce maxLength constraint
        text = t.substr(0, maxLength);
    }
    
    void setMaxLength(int max) { maxLength = max; }
    
    void draw() const override {
        if (!visible) return;
        
        cout << "Drawing " << (multiline ? "multiline " : "") 
             << "textbox at (" << x << "," << y << ") size " 
             << width << "x" << height;
        
        if (!text.empty()) {
            cout << " with text: " << text;
        }
        
        if (!enabled) {
            cout << " (disabled)";
        }
        cout << endl;
    }
};
```

## Summary

### Key Concepts

1. **"is-a" Relationship**
   - Must be logically valid
   - Should be obvious and natural
   - Must support substitution
   - Should enable code reuse
   - Must maintain LSP

2. **Liskov Substitution Principle**
   - Derived classes must be substitutable for base classes
   - Preconditions cannot be strengthened
   - Postconditions cannot be weakened
   - Invariants must be preserved
   - Behavior must be consistent with base class expectations

3. **Testing "is-a"**
   - Use sentence formation ("X is a Y")
   - Check substitutability
   - Verify behavior inheritance
   - Test with polymorphism
   - Validate LSP compliance

4. **Inheritance Alternatives**
   - Composition (has-a)
   - Delegation
   - Interface implementation
   - Strategy pattern

5. **Common Patterns**
   - Single inheritance chains
   - Multiple inheritance (careful!)
   - Interface inheritance
   - Abstract base classes
   - Template method pattern

### Common Pitfalls

1. **Forced Relationships**
   ```cpp
   // Wrong! House is not a Room
   class House : public Room { };
   
   // Better: House has Rooms
   class House {
       vector<Room> rooms;
   };
   ```

2. **LSP Violations**
   ```cpp
   // Wrong! Square can't substitute for Rectangle
   class Square : public Rectangle { };
   
   // Better: Both inherit from Shape
   class Shape { };
   class Rectangle : public Shape { };
   class Square : public Shape { };
   ```

3. **Deep Hierarchies**
   ```cpp
   // Too deep, hard to maintain
   class A : public B : public C : public D { };
   
   // Better: Flatter hierarchy with composition
   class A : public B {
       C c;  // Composition
       D d;  // Composition
   };
   ```

4. **Inheritance for Code Reuse Only**
   ```cpp
   // Wrong! Just for code reuse
   class StringUtils { /* utility methods */ };
   class TextProcessor : public StringUtils { };
   
   // Better: Use composition or static methods
   class TextProcessor {
       StringUtils utils;  // Composition
   };
   ```

5. **Fragile Base Class Problem**
   ```cpp
   // Base class changes can break derived classes
   class Base {
       void methodA() { /* implementation */ }
   };
   
   class Derived : public Base {
       void methodB() { methodA(); /* depends on Base implementation */ }
   };
   
   // If Base::methodA() changes, Derived::methodB() might break
   ```

### Best Practices
1. Use "is-a" test before inheritance
2. Keep hierarchies shallow (2-3 levels max)
3. Prefer composition to inheritance when in doubt
4. Document relationships clearly
5. Follow LSP principles
6. Test substitutability
7. Consider interfaces for behavior contracts
8. Use abstract classes for partial implementations
9. Design for extension, not modification
10. Validate inheritance relationships with domain experts

## Next Steps
1. Complete all practice exercises
2. Test with various scenarios
3. Review inheritance alternatives
4. Study composition patterns
5. Move on to [Part 3: Overriding Methods]({{ site.baseurl }}/tutorials/module7/part3-overriding)

Remember: The "is-a" relationship is fundamental to proper inheritance design. Take time to validate your relationships before implementing them.
