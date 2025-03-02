---
layout: default
title: Part 6 - Pointers to Objects
nav_order: 6
parent: Module 9 - Pointers and Dynamic Memory
grand_parent: Tutorials
permalink: /tutorials/module9/part6-pointers-objects/
---

# Part 6: Pointers to Objects

## Learning Objectives
- Master object creation and management on the heap
- Implement polymorphism using pointers to objects
- Understand object ownership and lifetime management
- Create container classes that manage object pointers
- Apply smart pointers to object management
- Implement proper memory management for object hierarchies

## Introduction
Pointers to objects are essential for dynamic object creation, polymorphism, and complex data structures. Think of them like remote controls for objects:

1. **Why Pointers to Objects Matter**:
   - **Dynamic Lifetime**: Create objects when needed, destroy when done
   - **Polymorphism**: Enable runtime type selection and behavior
   - **Memory Efficiency**: Share objects without duplication
   - **Complex Structures**: Build trees, graphs, and linked structures
   - **Flexibility**: Change object relationships at runtime

2. **Real-World Parallels**:
   - **Remote Controls**: Operate devices from a distance
   - **Business Cards**: Reference to a person without being the person
   - **Organizational Charts**: References to people in different roles
   - **Inventory Systems**: References to physical items in storage

3. **Benefits in Development**:
   - **Runtime Object Creation**: Create objects based on program state
   - **Polymorphic Behavior**: Select object types at runtime
   - **Memory Management**: Control object lifetime precisely
   - **Data Structure Implementation**: Build complex object relationships
   - **Dependency Management**: Implement various ownership models

## Object Creation on the Heap

### Basic Object Allocation

Creating objects on the heap gives you control over their lifetime:

```cpp
// Stack-allocated object (automatic lifetime)
Person stackPerson("Alice", 30);  // Destroyed when out of scope

// Heap-allocated object (manual lifetime)
Person* heapPerson = new Person("Bob", 25);  // Lives until explicitly deleted
// Use heapPerson...
delete heapPerson;  // Manual destruction
```

### Constructor and Destructor Calls

When creating and destroying heap objects, constructors and destructors are called:

```cpp
class Person {
private:
    string name;
    int age;
    
public:
    Person(string n, int a) : name(n), age(a) {
        cout << "Constructor called for " << name << endl;
    }
    
    ~Person() {
        cout << "Destructor called for " << name << endl;
    }
    
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Usage
Person* person = new Person("Charlie", 35);
person->display();
delete person;

// Output:
// Constructor called for Charlie
// Name: Charlie, Age: 35
// Destructor called for Charlie
```

### Member Access with Pointers

To access members of an object through a pointer, use the arrow operator (`->`):

```cpp
Person* person = new Person("David", 28);

// Member access with arrow operator
person->display();  // Equivalent to (*person).display()

// Changing member values
person->setAge(29);

delete person;
```

### Arrays of Objects on the Heap

You can create arrays of objects on the heap:

```cpp
// Array of 3 Person objects on the heap
Person* people = new Person[3]{
    Person("Eve", 22),
    Person("Frank", 45),
    Person("Grace", 33)
};

// Access array elements
people[0].display();
people[1].display();
people[2].display();

// Clean up
delete[] people;
```

## Polymorphism with Pointers

### Base and Derived Class Pointers

Polymorphism allows a base class pointer to point to derived class objects:

```cpp
class Shape {
public:
    virtual void draw() const {
        cout << "Drawing a shape" << endl;
    }
    
    virtual ~Shape() {
        cout << "Destroying shape" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    void draw() const override {
        cout << "Drawing a circle with radius " << radius << endl;
    }
    
    ~Circle() override {
        cout << "Destroying circle" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    void draw() const override {
        cout << "Drawing a rectangle " << width << "x" << height << endl;
    }
    
    ~Rectangle() override {
        cout << "Destroying rectangle" << endl;
    }
};
```

### Polymorphic Behavior

Base class pointers can be used to achieve polymorphic behavior:

```cpp
// Create objects on the heap
Shape* shape1 = new Circle(5.0);
Shape* shape2 = new Rectangle(4.0, 3.0);

// Polymorphic function calls
shape1->draw();  // Calls Circle::draw()
shape2->draw();  // Calls Rectangle::draw()

// Clean up
delete shape1;  // Calls Circle destructor, then Shape destructor
delete shape2;  // Calls Rectangle destructor, then Shape destructor

// Output:
// Drawing a circle with radius 5
// Drawing a rectangle 4x3
// Destroying circle
// Destroying shape
// Destroying rectangle
// Destroying shape
```

### Virtual Destructors

Virtual destructors are essential for proper cleanup of derived objects:

```cpp
// Without virtual destructor (problematic)
class Base {
public:
    ~Base() {  // Non-virtual
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int* data;
    
public:
    Derived() {
        data = new int[100];
        cout << "Derived constructor" << endl;
    }
    
    ~Derived() {
        delete[] data;
        cout << "Derived destructor" << endl;
    }
};

// Problem demonstration
Base* ptr = new Derived();
delete ptr;  // Only calls Base destructor, causing memory leak!

// Output:
// Derived constructor
// Base destructor
```

With virtual destructors:

```cpp
// With virtual destructor (correct)
class Base {
public:
    virtual ~Base() {  // Virtual
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int* data;
    
public:
    Derived() {
        data = new int[100];
        cout << "Derived constructor" << endl;
    }
    
    ~Derived() override {
        delete[] data;
        cout << "Derived destructor" << endl;
    }
};

// Correct behavior
Base* ptr = new Derived();
delete ptr;  // Calls Derived destructor, then Base destructor

// Output:
// Derived constructor
// Derived destructor
// Base destructor
```

### Runtime Type Identification

C++ provides runtime type information (RTTI) for polymorphic objects:

```cpp
Shape* shape = new Circle(5.0);

// dynamic_cast returns nullptr if the cast is invalid
Circle* circle = dynamic_cast<Circle*>(shape);
if (circle != nullptr) {
    cout << "Shape is a Circle" << endl;
}

Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);
if (rectangle == nullptr) {
    cout << "Shape is not a Rectangle" << endl;
}

// typeid operator returns type information
cout << "Type: " << typeid(*shape).name() << endl;

delete shape;
```

## Object Ownership and Lifetime

### Ownership Models

Different ownership models determine who is responsible for deleting objects:

1. **Exclusive Ownership**: One owner is responsible for deletion
2. **Shared Ownership**: Multiple owners share responsibility
3. **Temporary Access**: No ownership, just temporary use
4. **Transfer Ownership**: Ownership changes during program execution

### Exclusive Ownership Example

```cpp
class ResourceManager {
private:
    Resource* resource;  // Exclusively owned
    
public:
    ResourceManager() : resource(new Resource()) {}
    
    ~ResourceManager() {
        delete resource;  // Owner is responsible for cleanup
    }
    
    // Prevent copying to maintain exclusive ownership
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
};
```

### Shared Ownership Example

```cpp
class SharedResource {
private:
    Resource* resource;
    int* refCount;  // Shared reference count
    
public:
    SharedResource(Resource* res) : resource(res) {
        refCount = new int(1);
    }
    
    // Copy constructor increases reference count
    SharedResource(const SharedResource& other) 
        : resource(other.resource), refCount(other.refCount) {
        (*refCount)++;
    }
    
    // Assignment operator
    SharedResource& operator=(const SharedResource& other) {
        if (this != &other) {
            // Decrease current reference count
            release();
            
            // Share the other resource
            resource = other.resource;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }
    
    ~SharedResource() {
        release();
    }
    
private:
    void release() {
        if (--(*refCount) == 0) {
            delete resource;
            delete refCount;
        }
    }
};
```

### Transfer Ownership Example

```cpp
class UniqueResource {
private:
    Resource* resource;
    
public:
    UniqueResource(Resource* res) : resource(res) {}
    
    // Move constructor transfers ownership
    UniqueResource(UniqueResource&& other) noexcept 
        : resource(other.resource) {
        other.resource = nullptr;  // Previous owner gives up ownership
    }
    
    // Move assignment transfers ownership
    UniqueResource& operator=(UniqueResource&& other) noexcept {
        if (this != &other) {
            delete resource;  // Clean up current resource
            
            resource = other.resource;  // Take ownership
            other.resource = nullptr;   // Previous owner gives up ownership
        }
        return *this;
    }
    
    ~UniqueResource() {
        delete resource;
    }
    
    // Prevent copying
    UniqueResource(const UniqueResource&) = delete;
    UniqueResource& operator=(const UniqueResource&) = delete;
};
```

## Container Classes with Object Pointers

### Simple Object Container

A container class can manage a collection of object pointers:

```cpp
class ShapeContainer {
private:
    Shape** shapes;
    int capacity;
    int count;
    
public:
    ShapeContainer(int cap = 10) : capacity(cap), count(0) {
        shapes = new Shape*[capacity];
    }
    
    ~ShapeContainer() {
        // Delete all shapes
        for (int i = 0; i < count; i++) {
            delete shapes[i];
        }
        
        // Delete the array of pointers
        delete[] shapes;
    }
    
    void add(Shape* shape) {
        if (count < capacity) {
            shapes[count++] = shape;
        }
    }
    
    void drawAll() const {
        for (int i = 0; i < count; i++) {
            shapes[i]->draw();
        }
    }
    
    // Prevent copying (or implement deep copy)
    ShapeContainer(const ShapeContainer&) = delete;
    ShapeContainer& operator=(const ShapeContainer&) = delete;
};

// Usage
ShapeContainer container;
container.add(new Circle(5.0));
container.add(new Rectangle(4.0, 3.0));
container.drawAll();
```

### Heterogeneous Object Collection

Containers can hold different types of objects through polymorphism:

```cpp
// Create a container
ShapeContainer container;

// Add different types of shapes
container.add(new Circle(2.5));
container.add(new Rectangle(3.0, 4.0));
container.add(new Circle(1.0));
container.add(new Rectangle(5.0, 2.0));

// Draw all shapes polymorphically
container.drawAll();

// Container destructor will delete all shapes
```

### Ownership Transfer to Container

Containers often take ownership of the objects added to them:

```cpp
// Create objects
Circle* circle = new Circle(3.0);
Rectangle* rectangle = new Rectangle(2.0, 5.0);

// Transfer ownership to container
ShapeContainer container;
container.add(circle);     // Container now owns circle
container.add(rectangle);  // Container now owns rectangle

// Don't delete these objects directly!
// circle and rectangle will be deleted by container's destructor
```

## Smart Pointers for Objects

### std::unique_ptr for Exclusive Ownership

`std::unique_ptr` provides exclusive ownership semantics:

```cpp
#include <memory>

// Create a unique_ptr to a Circle
std::unique_ptr<Circle> circle = std::make_unique<Circle>(5.0);

// Access members
circle->draw();

// Cannot copy unique_ptr
// std::unique_ptr<Circle> circleCopy = circle;  // Error!

// Can transfer ownership via move
std::unique_ptr<Circle> circleMoved = std::move(circle);

// Original pointer is now null
if (circle == nullptr) {
    cout << "Original pointer is null after move" << endl;
}

// No need for explicit delete
```

### std::shared_ptr for Shared Ownership

`std::shared_ptr` provides shared ownership semantics:

```cpp
#include <memory>

// Create a shared_ptr to a Rectangle
std::shared_ptr<Rectangle> rect1 = std::make_shared<Rectangle>(4.0, 3.0);

// Create another shared_ptr pointing to the same Rectangle
std::shared_ptr<Rectangle> rect2 = rect1;

// Both pointers share ownership
rect1->draw();
rect2->draw();

cout << "Reference count: " << rect1.use_count() << endl;  // 2

// When all shared_ptrs go out of scope, the Rectangle is deleted
```

### Smart Pointer Container

Containers can use smart pointers for automatic memory management:

```cpp
class SmartShapeContainer {
private:
    std::vector<std::unique_ptr<Shape>> shapes;
    
public:
    void add(std::unique_ptr<Shape> shape) {
        shapes.push_back(std::move(shape));
    }
    
    void drawAll() const {
        for (const auto& shape : shapes) {
            shape->draw();
        }
    }
    
    // No need for custom destructor - unique_ptr handles cleanup
};

// Usage
SmartShapeContainer container;
container.add(std::make_unique<Circle>(5.0));
container.add(std::make_unique<Rectangle>(4.0, 3.0));
container.drawAll();
```

### Custom Deleters

Smart pointers can use custom deleters for special cleanup:

```cpp
// Custom deleter function
void customShapeDelete(Shape* shape) {
    cout << "Custom deleter called" << endl;
    delete shape;
}

// Using custom deleter with unique_ptr
std::unique_ptr<Shape, decltype(&customShapeDelete)> 
    shape(new Circle(3.0), customShapeDelete);

// Using custom deleter with shared_ptr
auto customDeleter = [](Shape* shape) {
    cout << "Custom lambda deleter called" << endl;
    delete shape;
};

std::shared_ptr<Shape> sharedShape(new Rectangle(2.0, 4.0), customDeleter);
```

## Implementation Guide

The `Tutorials/Module09/Part6/Learning/` directory contains starter files to help you learn about pointers to objects:

1. Start with these files:
   - `ObjectPointers_starter.h` and `ObjectPointers_starter.cpp`: Object pointer operations
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with basic object pointers:
      - Create objects on the heap
      - Access object members through pointers
      - Implement proper cleanup
   
   b. Move to polymorphism:
      - Create class hierarchies
      - Use base class pointers
      - Implement virtual functions
   
   c. Complete the main program:
      - Test object creation and deletion
      - Verify polymorphic behavior
      - Implement container classes

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o object_pointers_demo main_starter.cpp ObjectPointers_starter.cpp
   
   # Run and verify output
   ./object_pointers_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to track object creation and destruction

5. Reference Implementation:
   The completed versions (ObjectPointers.h, ObjectPointers.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study object pointer patterns
   - Understand best practices

### Step 1: Basic Object Creation

```cpp
// Demonstrate basic object creation on the heap
void demonstrateObjectCreation() {
    cout << "Creating objects on the heap:" << endl;
    
    // Create a Person object on the heap
    Person* person = new Person("Alice", 30);
    
    // Access members
    cout << "Person details: ";
    person->display();
    
    // Modify object through pointer
    person->setAge(31);
    cout << "After modification: ";
    person->display();
    
    // Clean up
    delete person;
    cout << endl;
    
    // Array of objects
    cout << "Creating an array of objects:" << endl;
    Person* people = new Person[3]{
        Person("Bob", 25),
        Person("Charlie", 40),
        Person("David", 35)
    };
    
    // Access array elements
    for (int i = 0; i < 3; i++) {
        cout << "Person " << i + 1 << ": ";
        people[i].display();
    }
    
    // Clean up array
    delete[] people;
}

// Expected Output:
// Creating objects on the heap:
// Constructor called for Alice
// Person details: Name: Alice, Age: 30
// After modification: Name: Alice, Age: 31
// Destructor called for Alice
//
// Creating an array of objects:
// Constructor called for Bob
// Constructor called for Charlie
// Constructor called for David
// Person 1: Name: Bob, Age: 25
// Person 2: Name: Charlie, Age: 40
// Person 3: Name: David, Age: 35
// Destructor called for David
// Destructor called for Charlie
// Destructor called for Bob
```

### Step 2: Polymorphism

```cpp
// Demonstrate polymorphism with object pointers
void demonstratePolymorphism() {
    cout << "Demonstrating polymorphism:" << endl;
    
    // Create derived objects with base pointers
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 3.0);
    
    // Polymorphic function calls
    cout << "Drawing shapes:" << endl;
    circle->draw();     // Calls Circle::draw()
    rectangle->draw();  // Calls Rectangle::draw()
    
    // Runtime type identification
    if (dynamic_cast<Circle*>(circle) != nullptr) {
        cout << "First shape is a Circle" << endl;
    }
    
    if (dynamic_cast<Rectangle*>(rectangle) != nullptr) {
        cout << "Second shape is a Rectangle" << endl;
    }
    
    // Clean up
    delete circle;
    delete rectangle;
    cout << endl;
}

// Expected Output:
// Demonstrating polymorphism:
// Drawing shapes:
// Drawing a circle with radius 5
// Drawing a rectangle 4x3
// First shape is a Circle
// Second shape is a Rectangle
// Destroying circle
// Destroying shape
// Destroying rectangle
// Destroying shape
```

### Step 3: Object Container

```cpp
// Demonstrate object container
void demonstrateObjectContainer() {
    cout << "Demonstrating object container:" << endl;
    
    // Create a container
    ShapeContainer container;
    
    // Add shapes to container
    container.add(new Circle(2.5));
    container.add(new Rectangle(3.0, 4.0));
    container.add(new Circle(1.0));
    
    // Draw all shapes
    cout << "Drawing all shapes in container:" << endl;
    container.drawAll();
    
    // Container destructor will delete all shapes
    cout << endl;
}

// Expected Output:
// Demonstrating object container:
// Drawing all shapes in container:
// Drawing a circle with radius 2.5
// Drawing a rectangle 3x4
// Drawing a circle with radius 1
// Destroying circle
// Destroying shape
// Destroying rectangle
// Destroying shape
// Destroying circle
// Destroying shape
```

### Step 4: Smart Pointers

```cpp
#include <memory>

// Demonstrate smart pointers
void demonstrateSmartPointers() {
    cout << "Demonstrating smart pointers:" << endl;
    
    // unique_ptr
    cout << "Using unique_ptr:" << endl;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(3.0);
    circle->draw();
    
    // Transfer ownership
    std::unique_ptr<Circle> movedCircle = std::move(circle);
    if (circle == nullptr) {
        cout << "Original pointer is null after move" << endl;
    }
    movedCircle->draw();
    
    // shared_ptr
    cout << "\nUsing shared_ptr:" << endl;
    std::shared_ptr<Rectangle> rect1 = std::make_shared<Rectangle>(2.0, 5.0);
    {
        std::shared_ptr<Rectangle> rect2 = rect1;
        cout << "Reference count: " << rect1.use_count() << endl;  // 2
        rect2->draw();
    }
    cout << "After inner scope, reference count: " << rect1.use_count() << endl;  // 1
    rect1->draw();
    
    // Smart pointer container
    cout << "\nUsing smart pointer container:" << endl;
    SmartShapeContainer smartContainer;
    smartContainer.add(std::make_unique<Circle>(1.5));
    smartContainer.add(std::make_unique<Rectangle>(3.0, 2.0));
    smartContainer.drawAll();
    
    // No explicit cleanup needed
    cout << endl;
}

// Expected Output:
// Demonstrating smart pointers:
// Using unique_ptr:
// Drawing a circle with radius 3
// Original pointer is null after move
// Drawing a circle with radius 3
//
// Using shared_ptr:
// Reference count: 2
// Drawing a rectangle 2x5
// After inner scope, reference count: 1
// Drawing a rectangle 2x5
//
// Using smart pointer container:
// Drawing a circle with radius 1.5
// Drawing a rectangle 3x2
```

### Step 5: Custom Memory Management

```cpp
// Class with custom memory management
class ResourceOwner {
private:
    int* resource;
    
public:
    ResourceOwner() {
        resource = new int[1000];
        cout << "ResourceOwner: Allocated memory" << endl;
    }
    
    ~ResourceOwner() {
        delete[] resource;
        cout << "ResourceOwner: Freed memory" << endl;
    }
    
    // Copy constructor with deep copy
    ResourceOwner(const ResourceOwner& other) {
        resource = new int[1000];
        // Copy data from other.resource
        for (int i = 0; i < 1000; i++) {
            resource[i] = other.resource[i];
        }
        cout << "ResourceOwner: Copy constructor" << endl;
    }
    
    // Assignment operator with deep copy
    ResourceOwner& operator=(const ResourceOwner& other) {
        if (this != &other) {
            // Copy data from other.resource
            for (int i = 0; i < 1000; i++) {
                resource[i] = other.resource[i];
            }
            cout << "ResourceOwner: Assignment operator" << endl;
        }
        return *this;
    }
};

// Demonstrate custom memory management
void demonstrateCustomMemoryManagement() {
    cout << "Demonstrating custom memory management:" << endl;
    
    // Create object
    ResourceOwner* owner = new ResourceOwner();
    
    // Create another object
    ResourceOwner* owner2 = new ResourceOwner(*owner);  // Copy constructor
    
    // Assignment
    *owner = *owner2;  // Assignment operator
    
    // Clean up
    delete owner;
    delete owner2;
}

// Expected Output:
// Demonstrating custom memory management:
// ResourceOwner: Allocated memory
// ResourceOwner: Allocated memory
// ResourceOwner: Copy constructor
// ResourceOwner: Assignment operator
// ResourceOwner: Freed memory
// ResourceOwner: Freed memory
```

## Practice Exercises

The `Tutorials/Module09/Part6/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., ObjectPointers_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your object pointer operations
      - Define required classes and functions
   
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
   g++ -o exercise1 main_starter.cpp ObjectPointers_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to track object lifetime
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Animal Hierarchy
Implement a polymorphic animal hierarchy:

```cpp
// TODO: Implement these classes
class Animal {
    // Base class with virtual methods
};

class Dog : public Animal {
    // Derived class with specific behavior
};

class Cat : public Animal {
    // Derived class with specific behavior
};

class AnimalShelter {
    // Container for Animal pointers
};
```

### Exercise 2: Vehicle Fleet Management
Create a vehicle fleet management system:

```cpp
// TODO: Implement these classes
class Vehicle {
    // Base class with virtual methods
};

class Car : public Vehicle {
    // Derived class for cars
};

class Truck : public Vehicle {
    // Derived class for trucks
};

class Fleet {
    // Container using smart pointers
};
```

### Exercise 3: Document Management System
Implement a document management system:

```cpp
// TODO: Implement these classes
class Document {
    // Base class with virtual methods
};

class TextDocument : public Document {
    // Derived class for text documents
};

class SpreadsheetDocument : public Document {
    // Derived class for spreadsheets
};

class DocumentManager {
    // Container with ownership management
};
```

## Advanced Object Pointer Techniques

### Factory Pattern

The Factory pattern uses pointers to create objects of different types:

```cpp
class ShapeFactory {
public:
    static Shape* createShape(const string& type) {
        if (type == "circle") {
            return new Circle(1.0);
        } else if (type == "rectangle") {
            return new Rectangle(2.0, 1.0);
        } else {
            return nullptr;
        }
    }
};

// Usage
Shape* shape = ShapeFactory::createShape("circle");
if (shape != nullptr) {
    shape->draw();
    delete shape;
}
```

### Composite Pattern

The Composite pattern uses pointers to build tree structures:

```cpp
class Component {
public:
    virtual void operation() = 0;
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual ~Component() {}
};

class Leaf : public Component {
public:
    void operation() override {
        cout << "Leaf operation" << endl;
    }
};

class Composite : public Component {
private:
    vector<Component*> children;
    
public:
    void operation() override {
        cout << "Composite operation" << endl;
        for (auto child : children) {
            child->operation();
        }
    }
    
    void add(Component* component) override {
        children.push_back(component);
    }
    
    void remove(Component* component) override {
        // Remove component from children
    }
    
    ~Composite() override {
        for (auto child : children) {
            delete child;
        }
    }
};

// Usage
Composite* root = new Composite();
root->add(new Leaf());
root->add(new Leaf());

Composite* branch = new Composite();
branch->add(new Leaf());
root->add(branch);

root->operation();
delete root;  // Deletes entire tree
```

### Observer Pattern

The Observer pattern uses pointers to implement event notification:

```cpp
class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() {}
};

class Subject {
private:
    vector<Observer*> observers;
    
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    
    void detach(Observer* observer) {
        // Remove observer from vector
    }
    
    void notify(const string& message) {
        for (auto observer : observers) {
            observer->update(message);
        }
    }
};

class ConcreteObserver : public Observer {
private:
    string name;
    
public:
    ConcreteObserver(const string& n) : name(n) {}
    
    void update(const string& message) override {
        cout << name << " received: " << message << endl;
    }
};

// Usage
Subject subject;
ConcreteObserver observer1("Observer 1");
ConcreteObserver observer2("Observer 2");

subject.attach(&observer1);
subject.attach(&observer2);
subject.notify("Hello, observers!");
```

## Summary

### Key Concepts

1. **Object Creation on the Heap**
   - Dynamic object allocation with `new`
   - Constructor and destructor calls
   - Member access with arrow operator
   - Arrays of objects on the heap
   - Proper cleanup with `delete`

2. **Polymorphism with Pointers**
   - Base and derived class pointers
   - Virtual functions for polymorphic behavior
   - Virtual destructors for proper cleanup
   - Runtime type identification
   - Dynamic casting

3. **Object Ownership**
   - Exclusive ownership model
   - Shared ownership model
   - Temporary access model
   - Ownership transfer
   - Resource management patterns

4. **Container Classes**
   - Object pointer collections
   - Heterogeneous object containers
   - Ownership management
   - Polymorphic operations
   - Memory management responsibilities

5. **Smart Pointers**
   - `unique_ptr` for exclusive ownership
   - `shared_ptr` for shared ownership
   - `weak_ptr` for breaking cycles
   - Custom deleters
   - Smart pointer containers

### Common Pitfalls

1. **Missing Virtual Destructors**
   ```cpp
   // Wrong! Non-virtual destructor
   class Base {
   public:
       ~Base() { }  // Should be virtual
   };
   
   // Correct
   class Base {
   public:
       virtual ~Base() { }
   };
   ```

2. **Memory Leaks in Containers**
   ```cpp
   // Wrong! Missing cleanup in destructor
   class Container {
   private:
       Object** objects;
       int count;
       
   public:
       ~Container() {
           delete[] objects;  // Deletes array but not objects
       }
   };
   
   // Correct
   class Container {
   private:
       Object** objects;
       int count;
       
   public:
       ~Container() {
           // Delete each object first
           for (int i = 0; i < count; i++) {
               delete objects[i];
           }
           
           // Then delete the array
           delete[] objects;
       }
   };
   ```

3. **Dangling Pointers**
   ```cpp
   // Wrong! Using pointer after deletion
   Shape* shape = new Circle(5.0);
   delete shape;
   shape->draw();  // Undefined behavior - accessing deleted memory
   
   // Correct
   Shape* shape = new Circle(5.0);
   delete shape;
   shape = nullptr;  // Set to nullptr after deletion
   
   if (shape != nullptr) {  // Check before use
       shape->draw();
   }
   ```

4. **Slicing Problem**
   ```cpp
   // Wrong! Object slicing
   Circle circle(5.0);
   Shape shape = circle;  // Slices off Circle-specific members
   shape.draw();  // Calls Shape::draw(), not Circle::draw()
   
   // Correct
   Circle circle(5.0);
   Shape& shapeRef = circle;  // Reference - no slicing
   shapeRef.draw();  // Calls Circle::draw()
   
   // Or use pointers
   Shape* shapePtr = &circle;  // Pointer - no slicing
   shapePtr->draw();  // Calls Circle::draw()
   ```

5. **Ownership Confusion**
   ```cpp
   // Wrong! Unclear ownership
   Shape* createShape() {
       return new Circle(5.0);  // Who deletes this?
   }
   
   void processShape(Shape* shape) {
       // Does this function own the shape?
       // Should it delete the shape?
   }
   
   // Correct - explicit ownership transfer
   std::unique_ptr<Shape> createShape() {
       return std::make_unique<Circle>(5.0);  // Ownership clear
   }
   
   void processShape(std::unique_ptr<Shape> shape) {
       // Function clearly takes ownership
   }
   ```

### Best Practices
1. Always use virtual destructors in base classes
2. Prefer smart pointers to raw pointers
3. Be explicit about ownership responsibilities
4. Use containers that manage object lifetime
5. Implement proper copy/move semantics
6. Set pointers to nullptr after deletion
7. Check for nullptr before dereferencing
8. Use dynamic_cast for type-safe downcasting
9. Avoid object slicing with polymorphic objects
10. Consider factory patterns for object creation

## Next Steps
1. Complete all practice exercises
2. Test with various object hierarchies
3. Review polymorphic behavior
4. Study design patterns using object pointers
5. Move on to [Part 7: Function Pointers]({{ site.baseurl }}/tutorials/module9/part7-function-pointers)

Remember: Pointers to objects are essential for polymorphism and dynamic object creation. Understanding proper memory management and ownership semantics is crucial for writing robust C++ code.
