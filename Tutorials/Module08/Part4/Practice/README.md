# "has-a" vs "is-a" Relationship Practice Exercises

This directory contains practice exercises for understanding and implementing "has-a" (composition/aggregation) and "is-a" (inheritance) relationships in C++.

## Exercise 1: Library System

Create a library system with the following classes:
- `Book` (base class)
- `Library` (container class)
- `FictionBook` (derived from Book)
- `NonFictionBook` (derived from Book)

### Requirements:
1. The `Book` class should have:
   - Members for title, author, and ISBN
   - Methods for displaying book information

2. The `Library` class should demonstrate "has-a" relationship:
   - Contains a collection of Book objects (composition)
   - Methods for adding, removing, and finding books
   - Method for displaying all books

3. The `FictionBook` and `NonFictionBook` classes should demonstrate "is-a" relationship:
   - Inherit from Book
   - Add genre-specific attributes
   - Override display methods as needed

4. In your main program:
   - Create a Library
   - Add various types of books
   - Demonstrate both relationships in action

## Exercise 2: Vehicle System

Create a vehicle system with the following classes:
- `Vehicle` (base class)
- `Engine` (component class)
- `Car` (derived from Vehicle)
- `Motorcycle` (derived from Vehicle)

### Requirements:
1. The `Engine` class should have:
   - Members for type, horsepower, and cylinders
   - Methods for starting, stopping, and displaying info

2. The `Vehicle` class should demonstrate "has-a" relationship:
   - Contains an Engine object (composition)
   - Members for make, model, and year
   - Methods for basic vehicle operations

3. The `Car` and `Motorcycle` classes should demonstrate "is-a" relationship:
   - Inherit from Vehicle
   - Add vehicle-specific attributes and methods
   - Override methods as needed

4. In your main program:
   - Create different types of vehicles
   - Show how the Engine is composed within Vehicle
   - Demonstrate polymorphism with Vehicle pointers

## Exercise 3: Computer System

Create a computer system with the following classes:
- `Computer` (base class)
- `CPU` and `Memory` (component classes)
- `Laptop` (derived from Computer)
- `Desktop` (derived from Computer)

### Requirements:
1. The `CPU` and `Memory` classes should have:
   - Appropriate attributes and methods
   - Display methods for component information

2. The `Computer` class should demonstrate "has-a" relationship:
   - Contains CPU and Memory objects (composition)
   - Methods for powering on/off and running programs

3. The `Laptop` and `Desktop` classes should demonstrate "is-a" relationship:
   - Inherit from Computer
   - Add form-factor specific attributes and methods
   - Override methods as needed

4. In your main program:
   - Create different types of computers
   - Show how components are composed within computers
   - Demonstrate when to use each relationship type

## Submission

Complete the starter files provided for each exercise:
- `Book_starter.h/cpp`, `Library_starter.h/cpp`, etc.
- `Vehicle_starter.h/cpp`, `Engine_starter.h/cpp`, etc.
- `Computer_starter.h/cpp`, `CPU_starter.h/cpp`, etc.

Test your implementation using the provided `main_starter.cpp` files.
