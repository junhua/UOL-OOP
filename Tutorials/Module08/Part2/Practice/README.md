# Virtual Functions Practice Exercises

This directory contains practice exercises for working with virtual functions and polymorphism in C++.

## Exercise 1: Vehicle Hierarchy

Create a polymorphic vehicle hierarchy with the following classes:
- `Vehicle` (base class)
- `Car` (derived from Vehicle)
- `Motorcycle` (derived from Vehicle)
- `Truck` (derived from Vehicle)

### Requirements:
1. The `Vehicle` class should have:
   - Protected members for make, model, and year
   - Pure virtual methods for `calculateFuelEfficiency()` and `displayInfo()`
   - A virtual method for `startEngine()`

2. Each derived class should:
   - Override the pure virtual methods
   - Add class-specific attributes and methods
   - Implement proper constructors and destructors

3. In your main program:
   - Create an array of Vehicle pointers
   - Store different vehicle types in the array
   - Demonstrate polymorphism by calling methods through base pointers

## Exercise 2: Shape Hierarchy

Create a shape hierarchy with the following classes:
- `Shape` (base class)
- `Circle` (derived from Shape)
- `Rectangle` (derived from Shape)
- `Triangle` (derived from Shape)

### Requirements:
1. The `Shape` class should have:
   - A color attribute
   - Pure virtual methods for `calculateArea()` and `calculatePerimeter()`
   - A virtual method for `displayInfo()`

2. Each derived class should:
   - Override the pure virtual methods with appropriate formulas
   - Add class-specific attributes (radius for Circle, width/height for Rectangle, etc.)
   - Implement proper constructors and destructors

3. In your main program:
   - Create a vector of Shape pointers
   - Add various shapes to the vector
   - Calculate and display the total area of all shapes

## Exercise 3: Employee Management System

Create an employee management system with the following classes:
- `Employee` (base class)
- `Manager` (derived from Employee)
- `Engineer` (derived from Employee)
- `Salesperson` (derived from Employee)

### Requirements:
1. The `Employee` class should have:
   - Protected members for name, ID, and base salary
   - Pure virtual method for `calculateSalary()`
   - Virtual methods for `displayInfo()` and `performDuties()`

2. Each derived class should:
   - Override the pure virtual method with appropriate salary calculations
   - Override the virtual methods with class-specific implementations
   - Add class-specific attributes and methods
   - Implement proper constructors and destructors

3. In your main program:
   - Create an array of Employee pointers
   - Store different employee types in the array
   - Calculate and display the total payroll
   - Demonstrate polymorphism by calling methods through base pointers

## Submission

Complete the starter files provided for each exercise:
- `Vehicle_starter.h/cpp`, `Car_starter.h/cpp`, etc.
- `Shape_starter.h/cpp`, `Circle_starter.h/cpp`, etc.
- `Employee_starter.h/cpp`, `Manager_starter.h/cpp`, etc.

Test your implementation using the provided `main_starter.cpp` files.
