---
layout: default
title: Part 1 - Base Classes and Derived Classes
nav_order: 1
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part1-base-derived/
---

# Part 1: Base Classes and Derived Classes

## Learning Objectives
- Understand base and derived class relationships
- Master constructor chaining and initialization
- Learn proper virtual method usage and mechanics
- Practice inheritance implementation
- Implement proper memory management
- Document class hierarchies effectively
- Avoid common inheritance pitfalls like object slicing

## Introduction
Base and derived classes form the foundation of inheritance in C++. Think of it like building a house:

1. **Why Base and Derived Classes Matter**:
   - **Code Organization**: Foundation for class hierarchies
   - **Code Reuse**: Share common functionality
   - **Extensibility**: Easy to add new features
   - **Maintainability**: Centralize common code
   - **Polymorphism**: Enable runtime behavior

2. **Real-World Parallels**:
   - **Building Construction**: Foundation → Floors → Rooms
   - **Vehicle Manufacturing**: Base Frame → Model Specifics
   - **Document Types**: Basic Document → Specific Formats
   - **Employee Roles**: Basic Employee → Specialized Positions

3. **Benefits in Development**:
   - **Reduced Duplication**: Share common code
   - **Consistent Interface**: Common base methods
   - **Easy Extension**: Add new derived classes
   - **Clear Structure**: Logical class organization
   - **Runtime Flexibility**: Polymorphic behavior

## Implementation Guide

The `Tutorials/Module07/Part1/Learning/` directory contains starter files to help you learn about base and derived classes:

1. Start with these files:
   - `Vehicle_starter.h` and `Vehicle_starter.cpp`: Base class skeleton
   - `Car_starter.h` and `Car_starter.cpp`: Derived class skeleton
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Vehicle base class:
      - Add member variables
      - Implement constructor and destructor
      - Define virtual methods
   
   b. Move to Car derived class:
      - Add specific members
      - Chain to base constructor
      - Override virtual methods
   
   c. Complete the main program:
      - Create Vehicle pointers
      - Test inheritance behavior
      - Verify proper cleanup

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o vehicle_demo main_starter.cpp Vehicle_starter.cpp Car_starter.cpp
   
   # Run and verify output
   ./vehicle_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to understand inheritance flow

5. Reference Implementation:
   The completed versions (Vehicle.h, Vehicle.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study inheritance patterns
   - Understand best practices

### Step 1: Base Class Implementation

```cpp
class Vehicle {
protected:
    string make;
    string model;
    int year;
    double price;
    
public:
    // Constructor with initialization list
    Vehicle(string make, string model, int year, double price)
        : make(make), model(model), year(year), price(price) {
        cout << "Creating vehicle: " << year << " " << make << " " << model << endl;
    }
    
    // Virtual destructor ensures proper cleanup of derived objects
    virtual ~Vehicle() {
        cout << "Destroying vehicle: " << year << " " << make << " " << model << endl;
    }
    
    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    
    // Virtual methods
    virtual void displayInfo() const {
        cout << year << " " << make << " " << model << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
    }
    
    virtual double calculateValue() const {
        int age = 2024 - year;
        return price * pow(0.85, age);  // 15% depreciation per year
    }
};
```

Test Cases:
```cpp
// Create a Vehicle object dynamically
Vehicle* vehicle = new Vehicle("Toyota", "Camry", 2020, 25000);

// Test virtual methods
vehicle->displayInfo();
cout << "Value: $" << vehicle->calculateValue() << endl;

// Clean up memory
delete vehicle;  // Calls virtual destructor

Expected Output:
Creating vehicle: 2020 Toyota Camry
2020 Toyota Camry
Price: $25000.00
Value: $15312.50
Destroying vehicle: 2020 Toyota Camry
```

### Step 2: Derived Class Implementation

```cpp
class Car : public Vehicle {
private:
    int numDoors;
    string fuelType;
    
public:
    // Constructor chains to base class constructor
    Car(string make, string model, int year, double price,
        int doors, string fuel)
        : Vehicle(make, model, year, price),  // Base class initialization
          numDoors(doors), fuelType(fuel) {   // Member initialization
        cout << "Creating car with " << doors << " doors" << endl;
    }
    
    // Destructor (override keyword is optional for destructors but good practice)
    ~Car() override {
        cout << "Destroying car: " << getMake() << " " << getModel() << endl;
    }
    
    // Getters for Car-specific members
    int getNumDoors() const { return numDoors; }
    string getFuelType() const { return fuelType; }
    
    // Override base class methods with 'override' keyword
    void displayInfo() const override {
        Vehicle::displayInfo();  // Call base class method
        cout << "Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
    
    double calculateValue() const override {
        double baseValue = Vehicle::calculateValue();  // Get base calculation
        if (fuelType == "Electric") {
            baseValue *= 1.1;  // 10% premium for electric
        }
        return baseValue;
    }
};
```

Test Cases:
```cpp
// Create a Car object dynamically
Car* car = new Car("Tesla", "Model 3", 2022, 45000, 4, "Electric");

// Test overridden methods
car->displayInfo();
cout << "Value: $" << car->calculateValue() << endl;

// Clean up memory
delete car;  // Calls Car's destructor, then Vehicle's destructor

Expected Output:
Creating vehicle: 2022 Tesla Model 3
Creating car with 4 doors
2022 Tesla Model 3
Price: $45000.00
Doors: 4
Fuel Type: Electric
Value: $41287.50
Destroying car: Tesla Model 3
Destroying vehicle: 2022 Tesla Model 3
```

### Step 3: Constructor Chaining in Detail

Constructor chaining is a critical concept in inheritance. When you create a derived class object, the following sequence occurs:

1. Memory is allocated for the entire object (base + derived parts)
2. The base class constructor is called first
3. The derived class's member initializers run
4. The derived class constructor body executes

```cpp
class Truck : public Vehicle {
private:
    double cargoCapacity;
    bool hasTrailer;
    
public:
    // Constructor chains to base class
    Truck(string make, string model, int year, double price,
          double capacity, bool trailer)
        : Vehicle(make, model, year, price),  // Base initialization (runs first)
          cargoCapacity(capacity),            // Member initialization (runs second)
          hasTrailer(trailer) {
        cout << "Creating truck with " << capacity << " ton capacity" << endl;
        // Constructor body (runs last)
    }
    
    ~Truck() override {
        cout << "Destroying truck: " << getMake() << " " << getModel() << endl;
        // Base class destructor runs automatically after this
    }
};
```

Execution Order Example:
```cpp
Truck* truck = new Truck("Ford", "F-150", 2021, 35000, 2.5, true);
delete truck;

Output:
Creating vehicle: 2021 Ford F-150     // Base constructor
Creating truck with 2.5 ton capacity  // Derived constructor
Destroying truck: Ford F-150          // Derived destructor
Destroying vehicle: 2021 Ford F-150   // Base destructor
```

### Step 4: Understanding Virtual Functions

Virtual functions enable polymorphism - the ability to call different implementations based on the actual object type at runtime.

#### How Virtual Functions Work

When a class contains virtual functions, the compiler creates a virtual function table (vtable) for that class:

1. Each class with virtual functions has its own vtable
2. Each object has a hidden pointer (vptr) to its class's vtable
3. When you call a virtual function through a pointer/reference, the program:
   - Follows the vptr to the vtable
   - Looks up the correct function implementation
   - Calls that implementation

```
Memory Layout:
+----------------+        +----------------+
| Vehicle Object |        | Vehicle vtable |
|----------------|        |----------------|
| vptr  ---------|------->| ~Vehicle()     |
| make           |        | displayInfo()  |
| model          |        | calculateValue()|
| year           |        +----------------+
| price          |
+----------------+

+----------------+        +----------------+
| Car Object     |        | Car vtable     |
|----------------|        |----------------|
| vptr  ---------|------->| ~Car()         |
| make           |        | displayInfo()  |
| model          |        | calculateValue()|
| year           |        +----------------+
| price          |
| numDoors       |
| fuelType       |
+----------------+
```

#### Why Virtual Destructors Matter

Without a virtual destructor, deleting a derived object through a base pointer would only call the base destructor:

```cpp
// Without virtual destructor
Vehicle* v = new Car("Honda", "Civic", 2019, 20000, 4, "Gasoline");
delete v;  // Only Vehicle's destructor runs, Car's destructor never called!

// With virtual destructor
Vehicle* v = new Car("Honda", "Civic", 2019, 20000, 4, "Gasoline");
delete v;  // Car's destructor runs, then Vehicle's destructor
```

### Step 5: Avoiding Object Slicing

Object slicing occurs when a derived class object is assigned to a base class object (not a pointer or reference), causing derived class data to be "sliced off":

```cpp
// Object slicing example
Car myCar("Toyota", "Camry", 2020, 25000, 4, "Hybrid");
Vehicle myVehicle = myCar;  // SLICING OCCURS HERE!

// Now myVehicle only has Vehicle parts, Car-specific data is lost
myVehicle.displayInfo();  // Calls Vehicle::displayInfo(), not Car::displayInfo()
```

To avoid slicing:
1. Use pointers or references when working with polymorphic objects
2. Pass objects by reference in functions
3. Store pointers in containers, not objects

```cpp
// Correct approach - no slicing
Car myCar("Toyota", "Camry", 2020, 25000, 4, "Hybrid");
Vehicle& vehicleRef = myCar;  // Reference - no slicing
Vehicle* vehiclePtr = &myCar;  // Pointer - no slicing

vehicleRef.displayInfo();  // Calls Car::displayInfo()
vehiclePtr->displayInfo();  // Calls Car::displayInfo()
```

## Practice Exercises

The `Tutorials/Module07/Part1/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., Vehicle_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your class hierarchy
      - Define member variables
   
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
   g++ -o exercise1 main_starter.cpp Vehicle_starter.cpp Car_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand flow
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Vehicle Fleet
Create a vehicle management system:

```cpp
// TODO: Implement these classes
class Vehicle;     // Base vehicle class
class Car;        // Basic passenger car
class Truck;      // Cargo truck
class Motorcycle; // Two-wheeler
```

### Exercise 2: Document System
Implement a document processing system:

```cpp
// TODO: Implement these classes
class Document;     // Base document class
class TextDoc;      // Text document
class Spreadsheet;  // Spreadsheet document
class Presentation; // Presentation document
```

### Exercise 3: Employee Hierarchy
Create an employee management system:

```cpp
// TODO: Implement these classes
class Employee;    // Base employee class
class Manager;     // Department manager
class Engineer;    // Technical staff
class Salesperson; // Sales staff
```

## Summary

### Key Concepts

1. **Base Class Design**
   - Virtual destructors for proper cleanup
   - Protected members for derived access
   - Virtual methods for polymorphism
   - Constructor design with initialization lists
   - Memory management considerations

2. **Derived Class Design**
   - Constructor chaining to initialize base
   - Member initialization in derived class
   - Method overriding with 'override' keyword
   - Base class access with scope resolution
   - Resource management in inheritance

3. **Common Patterns**
   - Virtual methods for polymorphic behavior
   - Protected access for inheritance
   - Constructor chains for proper initialization
   - Memory cleanup with virtual destructors
   - Polymorphic behavior through base pointers

### Common Pitfalls

1. **Memory Leaks**
   ```cpp
   // Wrong! No virtual destructor
   class Base {
       ~Base() { }  // Should be virtual
   };
   
   // Correct
   class Base {
       virtual ~Base() { }  // Ensures proper cleanup
   };
   ```

2. **Constructor Issues**
   ```cpp
   // Wrong! Missing base initialization
   class Derived : public Base {
       Derived(int x) { }  // Should initialize Base
   };
   
   // Correct
   class Derived : public Base {
       Derived(int x) : Base() { }  // Explicitly calls Base constructor
   };
   ```

3. **Access Problems**
   ```cpp
   // Wrong! Private inheritance
   class Derived : private Base { };  // Usually want public
   
   // Correct for "is-a" relationship
   class Derived : public Base { };
   ```

4. **Object Slicing**
   ```cpp
   // Wrong! Causes slicing
   void processVehicle(Vehicle vehicle) {  // Passed by value
       vehicle.displayInfo();  // Only Vehicle version called
   }
   
   // Correct
   void processVehicle(Vehicle& vehicle) {  // Passed by reference
       vehicle.displayInfo();  // Polymorphic behavior preserved
   }
   ```

5. **Missing Override Keyword**
   ```cpp
   // Wrong! No override keyword
   class Derived : public Base {
       void display() { }  // No compile error if Base::display signature changes
   };
   
   // Correct
   class Derived : public Base {
       void display() override { }  // Compiler checks signature match
   };
   ```

### Best Practices
1. Always use virtual destructors in base classes
2. Initialize base class properly in derived constructors
3. Use protected for members needed by derived classes
4. Document class relationships with clear comments
5. Test memory management with valgrind or similar tools
6. Use override keyword for all overridden methods
7. Keep inheritance hierarchies shallow (avoid deep nesting)
8. Consider composition as an alternative to inheritance
9. Use pointers or references for polymorphic behavior
10. Avoid object slicing by not passing/returning objects by value

## Next Steps
1. Complete all practice exercises
2. Test with various scenarios
3. Review memory management
4. Study inheritance patterns
5. Move on to [Part 2: "is-a" Relationship]({{ site.baseurl }}/tutorials/module7/part2-is-a)

Remember: Base and derived classes are fundamental to inheritance. Take time to understand their relationship and proper implementation.
