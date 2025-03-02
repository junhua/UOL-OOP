---
layout: default
title: Part 3 - Abstract Classes and Pure Virtual Functions
nav_order: 3
parent: Module 8 - Core OOP Concepts - Polymorphism
grand_parent: Tutorials
permalink: /tutorials/module8/part3-abstract-classes/
---

# Part 3: Abstract Classes and Pure Virtual Functions

## Learning Objectives
- Understand abstract classes and their purpose in C++
- Master pure virtual functions and their implementation
- Learn how to design effective interfaces using abstract classes
- Practice implementing derived classes from abstract base classes
- Understand when to use abstract classes vs concrete classes
- Implement proper memory management with abstract classes
- Recognize and avoid common abstract class pitfalls

## Introduction
Abstract classes and pure virtual functions are powerful tools in C++ that allow you to define interfaces that derived classes must implement. They provide a way to enforce a contract between base and derived classes, ensuring that derived classes provide implementations for specific functionality.

1. **Why Abstract Classes Matter**:
   - **Interface Definition**: Define what derived classes must implement
   - **Code Organization**: Create clear hierarchies with well-defined responsibilities
   - **Design Clarity**: Separate interface from implementation
   - **Polymorphic Behavior**: Enable runtime polymorphism with guaranteed interfaces
   - **Extensibility**: Create frameworks that can be extended without modification

2. **Real-World Parallels**:
   - **Blueprints**: Define structure but can't be built directly
   - **Job Descriptions**: Define responsibilities without specifying how to fulfill them
   - **Contracts**: Specify obligations without dictating implementation details
   - **Recipes**: List required ingredients but allow for variations in preparation

3. **Benefits in Development**:
   - **Enforced Implementation**: Derived classes must implement required methods
   - **Clear Interfaces**: Define what clients can expect from all derived classes
   - **Reduced Errors**: Compiler ensures required methods are implemented
   - **Better Design**: Encourages thinking about interfaces before implementation
   - **Flexible Architecture**: Adapt to changing requirements with minimal disruption

## Abstract Classes and Pure Virtual Functions

### What Makes a Class Abstract?

A class becomes abstract when it has at least one pure virtual function. An abstract class:

1. **Cannot be instantiated directly**
2. **Can contain a mix of pure virtual and regular methods**
3. **Can have data members and constructors**
4. **Must be subclassed to be useful**
5. **Can have pure virtual destructors (though rare)**

```cpp
class AbstractClass {
public:
    // Pure virtual function (makes the class abstract)
    virtual void pureVirtualMethod() = 0;
    
    // Regular virtual function with implementation
    virtual void regularVirtualMethod() {
        cout << "AbstractClass::regularVirtualMethod" << endl;
    }
    
    // Non-virtual method
    void nonVirtualMethod() {
        cout << "AbstractClass::nonVirtualMethod" << endl;
    }
};

// Error: Cannot instantiate abstract class
// AbstractClass obj;  // Compiler error

// Must derive and implement pure virtual methods
class ConcreteClass : public AbstractClass {
public:
    // Implementation of pure virtual method
    void pureVirtualMethod() override {
        cout << "ConcreteClass::pureVirtualMethod" << endl;
    }
};

// Now we can create objects
ConcreteClass obj;  // OK
```

### Pure Virtual Functions

A pure virtual function is declared by adding `= 0` to the end of the function declaration:

1. **Syntax**: `virtual returnType functionName(parameters) = 0;`
2. **Purpose**: Declares a function that must be implemented by derived classes
3. **Implementation**: No implementation in the abstract class (usually)
4. **Effect**: Makes the class abstract (cannot be instantiated)

```cpp
class Shape {
public:
    // Pure virtual functions
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    
    // Regular virtual function with implementation
    virtual void displayProperties() const {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};
```

### Pure Virtual Functions with Implementation

Interestingly, C++ allows pure virtual functions to have implementations, though this is less common:

```cpp
class Base {
public:
    // Pure virtual function with implementation
    virtual void method() = 0;
};

// Implementation outside the class
void Base::method() {
    cout << "Base::method implementation" << endl;
}

class Derived : public Base {
public:
    void method() override {
        // Call the base implementation if desired
        Base::method();
        cout << "Derived::method implementation" << endl;
    }
};
```

This pattern is useful when:
- You want to provide a default implementation that derived classes can call
- You want to make a class abstract but still provide behavior for a method
- You're implementing the Template Method pattern

### Abstract Classes vs Interfaces

In C++, there's no formal "interface" keyword as in some other languages, but abstract classes can be used to create interface-like constructs:

1. **Pure Interface** (all methods are pure virtual):
   ```cpp
   class Drawable {
   public:
       virtual ~Drawable() = default;
       virtual void draw() const = 0;
       virtual void resize(double factor) = 0;
   };
   ```

2. **Abstract Class** (mix of pure virtual and implemented methods):
   ```cpp
   class Shape {
   protected:
       string color;
       
   public:
       Shape(string c) : color(c) {}
       virtual ~Shape() = default;
       
       // Pure virtual methods
       virtual double area() const = 0;
       virtual double perimeter() const = 0;
       
       // Implemented methods
       virtual void setColor(string c) { color = c; }
       string getColor() const { return color; }
   };
   ```

### When to Use Abstract Classes

Abstract classes are ideal in these scenarios:

1. **Defining Interfaces**: When you want to define what derived classes must implement
2. **Partial Implementation**: When some behavior is common but some must be specialized
3. **Framework Design**: When creating extensible frameworks
4. **Polymorphic Behavior**: When you need runtime polymorphism with guaranteed interfaces
5. **Template Method Pattern**: When you want to define an algorithm's structure but let subclasses implement specific steps

## Implementation Guide

The `Tutorials/Module08/Part3/Learning/` directory contains starter files to help you learn about abstract classes:

1. Start with these files:
   - `Device_starter.h` and `Device_starter.cpp`: Abstract base class skeleton
   - `Smartphone_starter.h` and `Smartphone_starter.cpp`: Derived class skeleton
   - `Laptop_starter.h` and `Laptop_starter.cpp`: Another derived class skeleton
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Device abstract class:
      - Add member variables
      - Define pure virtual methods
      - Implement regular virtual methods
      - Implement constructor and virtual destructor
   
   b. Move to Smartphone derived class:
      - Add specific members
      - Implement pure virtual methods
      - Override regular virtual methods
      - Implement constructor and destructor
   
   c. Implement Laptop derived class:
      - Add specific members
      - Implement pure virtual methods
      - Override regular virtual methods
      - Implement constructor and destructor
   
   d. Complete the main program:
      - Create Device pointers to derived objects
      - Test polymorphic behavior
      - Verify proper cleanup

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o device_demo main_starter.cpp Device_starter.cpp Smartphone_starter.cpp Laptop_starter.cpp
   
   # Run and verify output
   ./device_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to understand abstract class behavior

5. Reference Implementation:
   The completed versions (Device.h, Device.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study abstract class patterns
   - Understand best practices

### Step 1: Abstract Base Class Implementation

```cpp
// Device.h
class Device {
protected:
    string brand;
    string model;
    bool powerStatus;
    
public:
    // Constructor
    Device(string brand, string model)
        : brand(brand), model(model), powerStatus(false) {
        cout << "Creating device: " << brand << " " << model << endl;
    }
    
    // Virtual destructor
    virtual ~Device() {
        cout << "Destroying device: " << brand << " " << model << endl;
    }
    
    // Getters
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    bool isPoweredOn() const { return powerStatus; }
    
    // Pure virtual methods (must be implemented by derived classes)
    virtual void connect() = 0;
    virtual void transferData(const string& data) = 0;
    
    // Virtual methods with implementation
    virtual void powerOn() {
        if (!powerStatus) {
            powerStatus = true;
            cout << brand << " " << model << " is powering on" << endl;
        }
    }
    
    virtual void powerOff() {
        if (powerStatus) {
            powerStatus = false;
            cout << brand << " " << model << " is powering off" << endl;
        }
    }
    
    // Non-virtual method
    void displayInfo() const {
        cout << "Device: " << brand << " " << model << endl;
        cout << "Power: " << (powerStatus ? "On" : "Off") << endl;
    }
};
```

Test Cases:
```cpp
// Cannot create Device object directly (abstract class)
// Device device("Generic", "Model");  // Compiler error

// Must use derived class
Device* device = new Smartphone("Apple", "iPhone 15", "iOS", 6.1);
device->powerOn();
device->connect();
device->transferData("Hello, world!");
device->displayInfo();
device->powerOff();
delete device;

Expected Output:
Creating device: Apple iPhone 15
Creating smartphone with OS: iOS
Apple iPhone 15 is powering on
iPhone 15 connecting to cellular network...
iPhone 15 transferring data: Hello, world!
Device: Apple iPhone 15
Power: On
Apple iPhone 15 is powering off
Destroying smartphone: iPhone 15
Destroying device: Apple iPhone 15
```

### Step 2: Derived Class Implementation

```cpp
// Smartphone.h
class Smartphone : public Device {
private:
    string operatingSystem;
    double screenSize;
    
public:
    // Constructor
    Smartphone(string brand, string model, string os, double screen)
        : Device(brand, model), operatingSystem(os), screenSize(screen) {
        cout << "Creating smartphone with OS: " << os << endl;
    }
    
    // Destructor
    ~Smartphone() override {
        cout << "Destroying smartphone: " << getModel() << endl;
    }
    
    // Getters
    string getOS() const { return operatingSystem; }
    double getScreenSize() const { return screenSize; }
    
    // Implement pure virtual methods
    void connect() override {
        cout << getModel() << " connecting to cellular network..." << endl;
    }
    
    void transferData(const string& data) override {
        cout << getModel() << " transferring data: " << data << endl;
    }
    
    // Override virtual methods
    void powerOn() override {
        Device::powerOn();  // Call base class method
        cout << "Smartphone display lights up" << endl;
    }
    
    void powerOff() override {
        cout << "Smartphone display turns off" << endl;
        Device::powerOff();  // Call base class method
    }
    
    // Smartphone-specific methods
    void makeCall(const string& number) {
        if (isPoweredOn()) {
            cout << getModel() << " calling " << number << "..." << endl;
        } else {
            cout << "Cannot make call. Device is powered off." << endl;
        }
    }
    
    void sendMessage(const string& recipient, const string& message) {
        if (isPoweredOn()) {
            cout << getModel() << " sending message to " << recipient << ": " << message << endl;
        } else {
            cout << "Cannot send message. Device is powered off." << endl;
        }
    }
};

// Laptop.h
class Laptop : public Device {
private:
    string processorType;
    int ramSize;
    bool hasWebcam;
    
public:
    // Constructor
    Laptop(string brand, string model, string processor, int ram, bool webcam)
        : Device(brand, model), processorType(processor), ramSize(ram), hasWebcam(webcam) {
        cout << "Creating laptop with " << processor << " processor and " << ram << "GB RAM" << endl;
    }
    
    // Destructor
    ~Laptop() override {
        cout << "Destroying laptop: " << getModel() << endl;
    }
    
    // Getters
    string getProcessor() const { return processorType; }
    int getRamSize() const { return ramSize; }
    bool getHasWebcam() const { return hasWebcam; }
    
    // Implement pure virtual methods
    void connect() override {
        cout << getModel() << " connecting to Wi-Fi network..." << endl;
    }
    
    void transferData(const string& data) override {
        cout << getModel() << " transferring data via USB: " << data << endl;
    }
    
    // Override virtual methods
    void powerOn() override {
        Device::powerOn();  // Call base class method
        cout << "Laptop fans start spinning" << endl;
    }
    
    void powerOff() override {
        cout << "Laptop saving state before shutdown" << endl;
        Device::powerOff();  // Call base class method
    }
    
    // Laptop-specific methods
    void openApplication(const string& appName) {
        if (isPoweredOn()) {
            cout << getModel() << " opening application: " << appName << endl;
        } else {
            cout << "Cannot open application. Device is powered off." << endl;
        }
    }
    
    void runDiagnostics() {
        if (isPoweredOn()) {
            cout << getModel() << " running system diagnostics..." << endl;
            cout << "Processor: " << processorType << " - OK" << endl;
            cout << "Memory: " << ramSize << "GB - OK" << endl;
            cout << "Webcam: " << (hasWebcam ? "Present" : "Not present") << " - OK" << endl;
        } else {
            cout << "Cannot run diagnostics. Device is powered off." << endl;
        }
    }
};
```

Test Cases:
```cpp
// Create a Smartphone object
Smartphone* phone = new Smartphone("Samsung", "Galaxy S23", "Android", 6.2);
phone->powerOn();
phone->connect();
phone->makeCall("555-1234");
phone->sendMessage("John", "Hello from my new phone!");
phone->powerOff();
delete phone;

// Create a Laptop object
Laptop* laptop = new Laptop("Dell", "XPS 15", "Intel i7", 16, true);
laptop->powerOn();
laptop->connect();
laptop->openApplication("Visual Studio Code");
laptop->runDiagnostics();
laptop->powerOff();
delete laptop;

Expected Output:
Creating device: Samsung Galaxy S23
Creating smartphone with OS: Android
Samsung Galaxy S23 is powering on
Smartphone display lights up
Galaxy S23 connecting to cellular network...
Galaxy S23 calling 555-1234...
Galaxy S23 sending message to John: Hello from my new phone!
Smartphone display turns off
Samsung Galaxy S23 is powering off
Destroying smartphone: Galaxy S23
Destroying device: Samsung Galaxy S23

Creating device: Dell XPS 15
Creating laptop with Intel i7 processor and 16GB RAM
Dell XPS 15 is powering on
Laptop fans start spinning
XPS 15 connecting to Wi-Fi network...
XPS 15 opening application: Visual Studio Code
XPS 15 running system diagnostics...
Processor: Intel i7 - OK
Memory: 16GB - OK
Webcam: Present - OK
Laptop saving state before shutdown
Dell XPS 15 is powering off
Destroying laptop: XPS 15
Destroying device: Dell XPS 15
```

### Step 3: Polymorphic Behavior with Abstract Classes

```cpp
// main.cpp
int main() {
    // Create an array of Device pointers
    const int NUM_DEVICES = 4;
    Device* devices[NUM_DEVICES];
    
    // Initialize with different devices
    devices[0] = new Smartphone("Apple", "iPhone 15", "iOS", 6.1);
    devices[1] = new Laptop("Dell", "XPS 13", "Intel i5", 8, true);
    devices[2] = new Smartphone("Google", "Pixel 7", "Android", 6.3);
    devices[3] = new Laptop("Lenovo", "ThinkPad X1", "Intel i7", 16, true);
    
    // Power on all devices
    cout << "\nPowering on devices:" << endl;
    for (int i = 0; i < NUM_DEVICES; i++) {
        devices[i]->powerOn();
        cout << endl;
    }
    
    // Connect all devices
    cout << "Connecting devices:" << endl;
    for (int i = 0; i < NUM_DEVICES; i++) {
        devices[i]->connect();
    }
    cout << endl;
    
    // Transfer data with all devices
    cout << "Transferring data:" << endl;
    for (int i = 0; i < NUM_DEVICES; i++) {
        devices[i]->transferData("Test data " + to_string(i + 1));
    }
    cout << endl;
    
    // Display info for all devices
    cout << "Device information:" << endl;
    for (int i = 0; i < NUM_DEVICES; i++) {
        devices[i]->displayInfo();
        cout << endl;
    }
    
    // Type-specific operations require downcasting
    cout << "Performing type-specific operations:" << endl;
    for (int i = 0; i < NUM_DEVICES; i++) {
        // Try to downcast to Smartphone
        Smartphone* phone = dynamic_cast<Smartphone*>(devices[i]);
        if (phone) {
            cout << "Found a smartphone. Making a call..." << endl;
            phone->makeCall("555-1234");
        }
        
        // Try to downcast to Laptop
        Laptop* laptop = dynamic_cast<Laptop*>(devices[i]);
        if (laptop) {
            cout << "Found a laptop. Running diagnostics..." << endl;
            laptop->runDiagnostics();
        }
        
        cout << endl;
    }
    
    // Power off all devices
    cout << "Powering off devices:" << endl;
    for (int i = 0; i < NUM_DEVICES; i++) {
        devices[i]->powerOff();
        cout << endl;
    }
    
    // Clean up
    cout << "Cleaning up:" << endl;
    for (int i = 0; i < NUM_DEVICES; i++) {
        delete devices[i];
        cout << endl;
    }
    
    return 0;
}
```

Expected Output:
```
Creating device: Apple iPhone 15
Creating smartphone with OS: iOS
Creating device: Dell XPS 13
Creating laptop with Intel i5 processor and 8GB RAM
Creating device: Google Pixel 7
Creating smartphone with OS: Android
Creating device: Lenovo ThinkPad X1
Creating laptop with Intel i7 processor and 16GB RAM

Powering on devices:
Apple iPhone 15 is powering on
Smartphone display lights up

Dell XPS 13 is powering on
Laptop fans start spinning

Google Pixel 7 is powering on
Smartphone display lights up

Lenovo ThinkPad X1 is powering on
Laptop fans start spinning

Connecting devices:
iPhone 15 connecting to cellular network...
XPS 13 connecting to Wi-Fi network...
Pixel 7 connecting to cellular network...
ThinkPad X1 connecting to Wi-Fi network...

Transferring data:
iPhone 15 transferring data: Test data 1
XPS 13 transferring data via USB: Test data 2
Pixel 7 transferring data: Test data 3
ThinkPad X1 transferring data via USB: Test data 4

Device information:
Device: Apple iPhone 15
Power: On

Device: Dell XPS 13
Power: On

Device: Google Pixel 7
Power: On

Device: Lenovo ThinkPad X1
Power: On

Performing type-specific operations:
Found a smartphone. Making a call...
iPhone 15 calling 555-1234...

Found a laptop. Running diagnostics...
XPS 13 running system diagnostics...
Processor: Intel i5 - OK
Memory: 8GB - OK
Webcam: Present - OK

Found a smartphone. Making a call...
Pixel 7 calling 555-1234...

Found a laptop. Running diagnostics...
ThinkPad X1 running system diagnostics...
Processor: Intel i7 - OK
Memory: 16GB - OK
Webcam: Present - OK

Powering off devices:
Smartphone display turns off
Apple iPhone 15 is powering off

Laptop saving state before shutdown
Dell XPS 13 is powering off

Smartphone display turns off
Google Pixel 7 is powering off

Laptop saving state before shutdown
Lenovo ThinkPad X1 is powering off

Cleaning up:
Destroying smartphone: iPhone 15
Destroying device: Apple iPhone 15

Destroying laptop: XPS 13
Destroying device: Dell XPS 13

Destroying smartphone: Pixel 7
Destroying device: Google Pixel 7

Destroying laptop: ThinkPad X1
Destroying device: Lenovo ThinkPad X1
```

### Step 4: Abstract Class Design Patterns

Abstract classes are often used in design patterns:

1. **Template Method Pattern**:
   - Define algorithm structure in base class
   - Let derived classes implement specific steps
   
   ```cpp
   class DataProcessor {
   public:
       // Template method defines algorithm structure
       void processData() {
           openFile();
           readData();
           transformData();
           writeResults();
           closeFile();
       }
       
   protected:
       // Some steps are common
       void openFile() { cout << "Opening file" << endl; }
       void closeFile() { cout << "Closing file" << endl; }
       
       // These steps must be implemented by derived classes
       virtual void readData() = 0;
       virtual void transformData() = 0;
       virtual void writeResults() = 0;
   };
   ```

2. **Strategy Pattern**:
   - Define family of algorithms
   - Make them interchangeable
   
   ```cpp
   class SortStrategy {
   public:
       virtual ~SortStrategy() = default;
       virtual void sort(vector<int>& data) = 0;
   };
   
   class QuickSort : public SortStrategy {
   public:
       void sort(vector<int>& data) override {
           cout << "Sorting using QuickSort" << endl;
           // Implementation
       }
   };
   
   class MergeSort : public SortStrategy {
   public:
       void sort(vector<int>& data) override {
           cout << "Sorting using MergeSort" << endl;
           // Implementation
       }
   };
   
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

3. **Factory Method Pattern**:
   - Create objects without specifying exact class
   - Defer instantiation to subclasses
   
   ```cpp
   class Document {
   public:
       virtual ~Document() = default;
       virtual void open() = 0;
       virtual void save() = 0;
       virtual void close() = 0;
   };
   
   class Application {
   public:
       void newDocument() {
           Document* doc = createDocument();
           doc->open();
           // Work with document
       }
       
   protected:
       // Factory method - implemented by derived classes
       virtual Document* createDocument() = 0;
   };
   
   class TextDocument : public Document {
   public:
       void open() override { cout << "Opening text document" << endl; }
       void save() override { cout << "Saving text document" << endl; }
       void close() override { cout << "Closing text document" << endl; }
   };
   
   class TextEditor : public Application {
   protected:
       Document* createDocument() override {
           return new TextDocument();
       }
   };
   ```

## Practice Exercises

The `Tutorials/Module08/Part3/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., MediaItem_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your class hierarchy
      - Define pure virtual methods
   
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
   g++ -o exercise1 main_starter.cpp MediaItem_starter.cpp Song_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand abstract class behavior
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Media Player System

Create a media player system with the following classes:
- `MediaItem` (abstract base class)
- `Song` (derived from MediaItem)
- `Video` (derived from MediaItem)
- `Podcast` (derived from MediaItem)

### Exercise 2: Banking System

Create a banking system with the following classes:
- `Account` (abstract base class)
- `SavingsAccount` (derived from Account)
- `CheckingAccount` (derived from Account)
- `CreditAccount` (derived from Account)

### Exercise 3: Game Character System

Create a game character system with the following classes:
- `Character` (abstract base class)
- `Warrior` (derived from Character)
- `Mage` (derived from Character)
- `Archer` (derived from Character)

## Summary

### Key Concepts

1. **Abstract Classes**
   - Cannot be instantiated directly
   - Contain at least one pure virtual function
   - Define interfaces for derived classes
   - Can contain a mix of pure virtual and regular methods
   - Can have data members and constructors

2. **Pure Virtual Functions**
   - Declared with `= 0` syntax
   - Must be implemented by derived classes
   - Define the interface contract
   - Can have implementations (though uncommon)
   - Make a class abstract

3. **Interface Design**
   - Define what derived classes must implement
   - Separate interface from implementation
   - Create clear contracts
   - Enable polymorphic behavior
   - Support extensibility

4. **Design Patterns**
   - Template Method: Define algorithm structure
   - Strategy: Interchangeable algorithms
   - Factory Method: Defer object creation
   - Observer: Event notification
   - Command: Encapsulate requests

5. **Memory Management**
   - Virtual destructors essential
   - Proper cleanup of derived objects
   - Prevent memory leaks
   - Called in correct order (derived → base)
   - Required when deleting through base pointers

### Common Pitfalls

1. **Forgetting to Implement Pure Virtual Functions**
   ```cpp
   // Wrong! Missing implementation for pure virtual function
   class Derived : public Abstract {
       // Forgot to implement pureVirtualMethod()
   };
   
   // Correct
   class Derived : public Abstract {
       void pureVirtualMethod() override {
           // Implementation
       }
   };
   ```

2. **Trying to Instantiate Abstract Classes**
   ```cpp
   // Wrong! Cannot instantiate abstract class
   Abstract obj;  // Compiler error
   
   // Correct
   Derived obj;  // OK
   Abstract* ptr = new Derived();  // OK
   ```

3. **Missing Virtual Destructors**
   ```cpp
   // Wrong! No virtual destructor
   class Abstract {
   public:
       virtual void method() = 0;
       ~Abstract() { }  // Should be virtual
   };
   
   // Correct
   class Abstract {
   public:
       virtual void method() = 0;
       virtual ~Abstract() { }
   };
   ```

4. **Confusing Interface with Implementation**
   ```cpp
   // Wrong! Too much implementation in interface
   class Shape {
   public:
       virtual double area() = 0;
       virtual double perimeter() = 0;
       
       // Too much implementation for an interface
       void draw() {
           // Complex drawing logic
       }
   };
   
   // Better
   class Shape {
   public:
       virtual double area() = 0;
       virtual double perimeter() = 0;
       virtual void draw() = 0;  // Part of interface
   };
   ```

5. **Overdesigning Hierarchies**
   ```cpp
   // Wrong! Too many levels, too specific
   class Animal { };
   class Mammal : public Animal { };
   class Canine : public Mammal { };
   class Dog : public Canine { };
   class GermanShepherd : public Dog { };
   
   // Better
   class Animal { };
   class Dog : public Animal { };
   ```

### Best Practices
1. Use abstract classes to define interfaces
2. Keep interfaces focused and cohesive
3. Use pure virtual functions for required behavior
4. Provide default implementations when appropriate
5. Always use virtual destructors
6. Use override keyword for all overridden methods
7. Keep inheritance hierarchies shallow
8. Consider design patterns for common problems
9. Document interface contracts clearly
10. Test derived classes thoroughly

## Next Steps
1. Complete all practice exercises
2. Test with various scenarios
3. Review abstract class mechanics
4. Study design patterns using abstract classes
5. Move on to [Part 4: "has-a" Relationship vs "is-a" Relationship]({{ site.baseurl }}/tutorials/module8/part4-has-a-vs-is-a)

Remember: Abstract classes are powerful tools for defining interfaces and creating extensible frameworks. Understanding their proper use is essential for effective object-oriented design.
