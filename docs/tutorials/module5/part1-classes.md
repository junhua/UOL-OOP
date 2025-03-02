---
layout: default
title: Part 1 - Defining Classes
nav_order: 1
parent: Module 5 - Classes and Objects
grand_parent: Tutorials
permalink: /tutorials/module5/part1-classes/
---

# Part 1: Defining Classes

## Learning Objectives
- Understand class fundamentals and purpose
- Master class member declaration and access control
- Learn proper method implementation techniques
- Practice effective class design principles
- Implement robust member functions
- Handle class-related errors and exceptions
- Design clear and maintainable interfaces
- Document class relationships effectively
- Apply SOLID principles to class design

## Introduction
Classes are the foundation of object-oriented programming, providing a way to create custom data types that combine data and functionality. Think of them like blueprints for creating objects:

1. **Why Classes Matter**:
   - **Data Encapsulation**: Combine related data and operations
   - **Code Organization**: Group related functionality
   - **Access Control**: Protect data integrity
   - **Code Reuse**: Create reusable components
   - **Abstraction**: Hide implementation details
   - **Type Safety**: Create custom types
   - **Maintenance**: Localize changes
   - **Modeling**: Represent real-world entities

2. **Real-World Parallels**:
   - **Building Blueprints**: Define structure before construction
   - **Manufacturing Templates**: Standardize production
   - **DNA**: Instructions for creating organisms
   - **Recipes**: Instructions with ingredients and methods
   - **Legal Contracts**: Define rights and responsibilities
   - **Organization Charts**: Define roles and relationships
   - **Circuit Diagrams**: Define component connections

3. **Real-World Applications**:
   - **Game Development**: Character classes, item systems
   - **Financial Systems**: Account management, transactions
   - **GUI Applications**: Window components, controls
   - **Database Systems**: Record management, queries
   - **Network Applications**: Connection handling, protocols
   - **File Systems**: File operations, streaming
   - **Graphics Systems**: Shape handling, transformations
   - **Embedded Systems**: Device drivers, sensor interfaces

4. **Benefits in Development**:
   - **Maintainability**: Organized, modular code
   - **Readability**: Clear structure and purpose
   - **Extensibility**: Easy to modify and enhance
   - **Debugging**: Isolated components
   - **Testing**: Unit testable components
   - **Documentation**: Self-documenting code
   - **Collaboration**: Clear interfaces
   - **Scalability**: Manage complexity in large systems

## Implementation Guide

The `Tutorials/Module05/Part1/Learning/` directory contains starter files to help you learn about classes:

1. Start with these files:
   - `Time_starter.h` and `Time_starter.cpp`: Basic class implementation
   - `DynamicString_starter.h` and `DynamicString_starter.cpp`: Class with dynamic memory
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Time class:
      - Add member variables
      - Implement member functions
      - Add validation logic
      - Create utility methods
   
   b. Move to DynamicString class:
      - Implement dynamic memory management
      - Add copy semantics
      - Create string operations
      - Handle resource cleanup
   
   c. Complete the main program:
      - Create class instances
      - Test functionality
      - Verify proper behavior

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o class_demo main_starter.cpp Time_starter.cpp DynamicString_starter.cpp
   
   # Run and verify output
   ./class_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to understand class behavior

5. Reference Implementation:
   The completed versions (Time.h, Time.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study class design patterns
   - Understand best practices

### Step 1: Basic Class Structure

The Time class demonstrates fundamental class design principles including encapsulation, validation, and separation of interface from implementation.

```cpp
// Header file (Time.h)
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    // Data members (attributes)
    int hours;    // 0-23
    int minutes;  // 0-59
    int seconds;  // 0-59
    
public:
    // Constructor with default values
    Time(int h = 0, int m = 0, int s = 0) {
        setTime(h, m, s);
    }
    
    // Member functions (methods)
    void setTime(int h, int m, int s) {
        if (isValidTime(h, m, s)) {
            hours = h;
            minutes = m;
            seconds = s;
        } else {
            // Default to midnight if invalid
            hours = 0;
            minutes = 0;
            seconds = 0;
            cerr << "Invalid time values. Time set to 00:00:00" << endl;
        }
    }
    
    // Getter methods - const indicates they don't modify the object
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    
    // Utility methods - declared in header, defined in implementation file
    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    
    // Display method
    void display() const;
    
    // Convert to total seconds
    int toTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
    
private:
    // Helper method - validates time values
    bool isValidTime(int h, int m, int s) const {
        return h >= 0 && h < 24 &&
               m >= 0 && m < 60 &&
               s >= 0 && s < 60;
    }
};

#endif // TIME_H

// Implementation file (Time.cpp)
#include "Time.h"

void Time::addSeconds(int s) {
    if (s < 0) {
        cerr << "Cannot add negative seconds" << endl;
        return;
    }
    
    // Convert current time to seconds, add new seconds, then convert back
    int totalSeconds = toTotalSeconds() + s;
    
    // Extract hours, minutes, seconds
    hours = (totalSeconds / 3600) % 24;
    totalSeconds %= 3600;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
}

void Time::addMinutes(int m) {
    if (m < 0) {
        cerr << "Cannot add negative minutes" << endl;
        return;
    }
    
    addSeconds(m * 60);
}

void Time::addHours(int h) {
    if (h < 0) {
        cerr << "Cannot add negative hours" << endl;
        return;
    }
    
    hours = (hours + h) % 24;
}

void Time::display() const {
    cout << setfill('0') << setw(2) << hours << ":"
         << setfill('0') << setw(2) << minutes << ":"
         << setfill('0') << setw(2) << seconds << endl;
}
```

Test Cases:
```cpp
// Create a Time object
Time time1(10, 30, 45);

// Test getters
cout << "Hours: " << time1.getHours() << endl;
cout << "Minutes: " << time1.getMinutes() << endl;
cout << "Seconds: " << time1.getSeconds() << endl;

// Test display
cout << "Time: ";
time1.display();

// Test time manipulation
time1.addHours(2);
cout << "After adding 2 hours: ";
time1.display();

time1.addMinutes(75);
cout << "After adding 75 minutes: ";
time1.display();

time1.addSeconds(100);
cout << "After adding 100 seconds: ";
time1.display();

// Test validation
Time time2(25, 70, 80);  // Invalid values
cout << "Time2: ";
time2.display();

Expected Output:
Hours: 10
Minutes: 30
Seconds: 45
Time: 10:30:45
After adding 2 hours: 12:30:45
After adding 75 minutes: 13:45:45
After adding 100 seconds: 13:47:25
Invalid time values. Time set to 00:00:00
Time2: 00:00:00
```

Key Design Principles:
1. **Encapsulation**:
   - Private data members (hours, minutes, seconds)
   - Public interface methods (getters, setters, utility functions)
   - Implementation details hidden from users

2. **Validation**:
   - Input checking in setTime method
   - Helper method isValidTime for reusable validation
   - Error handling for invalid inputs

3. **Const Correctness**:
   - Non-modifying methods marked as const
   - Ensures methods don't change object state when they shouldn't
   - Enables use with const objects and references

4. **Separation of Interface and Implementation**:
   - Header file (.h) contains class declaration
   - Implementation file (.cpp) contains method definitions
   - Improves compilation efficiency and organization

5. **Helper Methods**:
   - Private utility method for validation
   - Public utility method for time conversion
   - Promotes code reuse and maintainability

### Step 2: Class with Dynamic Memory

The DynamicString class demonstrates resource management principles including dynamic memory allocation, the Rule of Three, and exception safety.

```cpp
// Header file (DynamicString.h)
#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class DynamicString {
private:
    char* data;      // Dynamically allocated character array
    size_t length;   // Length of string (excluding null terminator)
    
    // Helper method for allocation - centralizes memory management
    void allocateAndCopy(const char* str) {
        if (str == nullptr) {
            throw invalid_argument("Null string pointer");
        }
        
        length = strlen(str);
        
        try {
            data = new char[length + 1];  // +1 for null terminator
        } catch (const bad_alloc& e) {
            throw runtime_error("Memory allocation failed");
        }
        
        strcpy(data, str);  // Copy string including null terminator
    }
    
public:
    // Constructor with default empty string
    DynamicString(const char* str = "") {
        allocateAndCopy(str);
        cout << "Constructor called for: " << (str[0] ? str : "empty string") << endl;
    }
    
    // Destructor - frees allocated memory
    ~DynamicString() {
        cout << "Destructor called for: " << (data[0] ? data : "empty string") << endl;
        delete[] data;  // Safe even if data is nullptr
    }
    
    // Copy constructor - creates deep copy
    DynamicString(const DynamicString& other) {
        allocateAndCopy(other.data);
        cout << "Copy constructor called" << endl;
    }
    
    // Assignment operator - handles self-assignment and creates deep copy
    DynamicString& operator=(const DynamicString& other) {
        cout << "Assignment operator called" << endl;
        
        // Check for self-assignment
        if (this != &other) {
            // Free existing resources before allocation
            delete[] data;
            
            // Allocate new resources
            allocateAndCopy(other.data);
        }
        
        return *this;  // Return reference to this object
    }
    
    // Member functions
    size_t getLength() const { return length; }
    
    const char* getString() const { return data; }
    
    // Append string - reallocates memory to fit combined string
    void append(const char* str) {
        if (str == nullptr) {
            throw invalid_argument("Null string pointer");
        }
        
        size_t appendLength = strlen(str);
        size_t newLength = length + appendLength;
        
        // Allocate new buffer for combined string
        char* newData = nullptr;
        try {
            newData = new char[newLength + 1];  // +1 for null terminator
        } catch (const bad_alloc& e) {
            throw runtime_error("Memory allocation failed during append");
        }
        
        // Copy existing string and append new content
        strcpy(newData, data);
        strcat(newData, str);
        
        // Free old buffer and update pointers
        delete[] data;
        data = newData;
        length = newLength;
    }
    
    // Check if string is empty
    bool isEmpty() const {
        return length == 0;
    }
    
    // Clear string content
    void clear() {
        delete[] data;
        data = new char[1];
        data[0] = '\0';
        length = 0;
    }
    
    // Find substring - returns position or -1 if not found
    int find(const char* substr) const {
        if (substr == nullptr) {
            throw invalid_argument("Null substring pointer");
        }
        
        const char* pos = strstr(data, substr);
        if (pos == nullptr) {
            return -1;  // Not found
        }
        
        return static_cast<int>(pos - data);  // Calculate position
    }
};

#endif // DYNAMIC_STRING_H
```

Test Cases:
```cpp
// Basic construction and methods
DynamicString str1("Hello");
cout << "String: " << str1.getString() << endl;
cout << "Length: " << str1.getLength() << endl;

// Append operation
str1.append(" World!");
cout << "After append: " << str1.getString() << endl;
cout << "New length: " << str1.getLength() << endl;

// Copy constructor
DynamicString str2 = str1;  // Copy constructor
cout << "Copied string: " << str2.getString() << endl;

// Assignment operator
DynamicString str3("Test");
str3 = str1;  // Assignment operator
cout << "Assigned string: " << str3.getString() << endl;

// Self-assignment test
str1 = str1;  // Self-assignment
cout << "After self-assignment: " << str1.getString() << endl;

// Empty string and clear
DynamicString empty;
cout << "Empty string length: " << empty.getLength() << endl;
cout << "Is empty? " << (empty.isEmpty() ? "Yes" : "No") << endl;

str2.clear();
cout << "After clear: '" << str2.getString() << "'" << endl;
cout << "Is empty? " << (str2.isEmpty() ? "Yes" : "No") << endl;

// Find substring
DynamicString text("The quick brown fox jumps over the lazy dog");
int position = text.find("fox");
cout << "Found 'fox' at position: " << position << endl;
position = text.find("cat");
cout << "Found 'cat' at position: " << position << endl;

Expected Output:
Constructor called for: Hello
String: Hello
Length: 5
After append: Hello World!
New length: 12
Copy constructor called
Copied string: Hello World!
Constructor called for: Test
Assignment operator called
Assigned string: Hello World!
Assignment operator called
After self-assignment: Hello World!
Constructor called for: empty string
Empty string length: 0
Is empty? Yes
After clear: ''
Is empty? Yes
Constructor called for: The quick brown fox jumps over the lazy dog
Found 'fox' at position: 16
Found 'cat' at position: -1
Destructor called for: The quick brown fox jumps over the lazy dog
Destructor called for: empty string
Destructor called for: Hello World!
Destructor called for: Hello World!
```

Key Resource Management Principles:
1. **Rule of Three**:
   - Custom destructor to free allocated memory
   - Custom copy constructor for deep copying
   - Custom assignment operator for safe copying and self-assignment

2. **RAII (Resource Acquisition Is Initialization)**:
   - Resources acquired during construction
   - Resources released during destruction
   - Ensures proper cleanup even with exceptions

3. **Exception Safety**:
   - Strong guarantee for most operations
   - No resource leaks if exceptions occur
   - Proper error handling and reporting

4. **Memory Management**:
   - Proper allocation with new[]
   - Proper deallocation with delete[]
   - Handling of null pointers and empty strings
   - Prevention of memory leaks during reallocation

5. **Helper Methods**:
   - Centralized allocation logic
   - Consistent error handling
   - Code reuse across constructor, copy constructor, and assignment operator

### Step 3: Class Relationships

The Employee and Department classes demonstrate various types of class relationships including associations, composition, and bidirectional relationships.

```cpp
// Header files (Employee.h and Department.h)
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Forward declaration to resolve circular dependency
class Department;

class Employee {
private:
    string name;
    int id;
    Department* department;  // Association (Employee works in a Department)
    vector<string> skills;   // Composition (Employee owns skills)
    double salary;
    
public:
    // Constructor with initialization list
    Employee(const string& n, int i, double s = 0.0)
        : name(n), id(i), department(nullptr), salary(s) {
        cout << "Employee created: " << name << " (ID: " << id << ")" << endl;
    }
    
    // Destructor
    ~Employee() {
        cout << "Employee destroyed: " << name << endl;
    }
    
    // Department relationship management
    void setDepartment(Department* dept) {
        department = dept;
    }
    
    Department* getDepartment() const {
        return department;
    }
    
    // Skills management (composition)
    void addSkill(const string& skill) {
        skills.push_back(skill);
    }
    
    bool hasSkill(const string& skill) const {
        for (const auto& s : skills) {
            if (s == skill) return true;
        }
        return false;
    }
    
    const vector<string>& getSkills() const {
        return skills;
    }
    
    // Getters
    string getName() const { return name; }
    int getId() const { return id; }
    double getSalary() const { return salary; }
    
    // Setters
    void setSalary(double s) {
        if (s >= 0) {
            salary = s;
        } else {
            cerr << "Invalid salary value" << endl;
        }
    }
    
    // Display employee information
    void display() const;
};

#endif // EMPLOYEE_H

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Employee.h"
using namespace std;

class Department {
private:
    string name;
    string location;
    vector<Employee*> employees;  // Association (Department has Employees)
    
public:
    // Constructor
    Department(const string& n, const string& loc = "Main Office")
        : name(n), location(loc) {
        cout << "Department created: " << name << " at " << location << endl;
    }
    
    // Destructor - note: doesn't delete Employee objects
    ~Department() {
        cout << "Department destroyed: " << name << endl;
    }
    
    // Employee relationship management
    void addEmployee(Employee* emp) {
        // Check if employee already in department
        if (hasEmployee(emp)) {
            cout << "Employee already in department" << endl;
            return;
        }
        
        // Add employee to department
        employees.push_back(emp);
        
        // Update employee's department reference (bidirectional)
        emp->setDepartment(this);
        
        cout << "Added " << emp->getName() << " to " << name << " department" << endl;
    }
    
    void removeEmployee(Employee* emp) {
        auto it = find(employees.begin(), employees.end(), emp);
        if (it != employees.end()) {
            // Remove department reference from employee (bidirectional)
            (*it)->setDepartment(nullptr);
            
            // Remove employee from department
            employees.erase(it);
            
            cout << "Removed " << emp->getName() << " from " << name << " department" << endl;
        } else {
            cout << "Employee not found in department" << endl;
        }
    }
    
    bool hasEmployee(Employee* emp) const {
        return find(employees.begin(), employees.end(), emp) != employees.end();
    }
    
    // Getters
    string getName() const { return name; }
    string getLocation() const { return location; }
    size_t getEmployeeCount() const { return employees.size(); }
    
    // Display department information
    void displayEmployees() const;
};

// Implementation file (Employee.cpp)
#include "Employee.h"
#include "Department.h"

void Employee::display() const {
    cout << "Employee: " << name << " (ID: " << id << ")" << endl;
    cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    
    if (department) {
        cout << "Department: " << department->getName() << endl;
    } else {
        cout << "Department: None" << endl;
    }
    
    cout << "Skills: ";
    if (skills.empty()) {
        cout << "None";
    } else {
        for (size_t i = 0; i < skills.size(); ++i) {
            cout << skills[i];
            if (i < skills.size() - 1) {
                cout << ", ";
            }
        }
    }
    cout << endl;
}

// Implementation file (Department.cpp)
#include "Department.h"

void Department::displayEmployees() const {
    cout << "Department: " << name << " (" << location << ")" << endl;
    cout << "Employee Count: " << employees.size() << endl;
    
    if (employees.empty()) {
        cout << "No employees in this department" << endl;
    } else {
        cout << "Employees:" << endl;
        for (const auto& emp : employees) {
            cout << "- " << emp->getName() << " (ID: " << emp->getId() << ")" << endl;
        }
    }
}
```

Test Cases:
```cpp
// Create departments
Department engineering("Engineering", "Building A");
Department marketing("Marketing", "Building B");

// Create employees
Employee* alice = new Employee("Alice Smith", 1001, 75000);
Employee* bob = new Employee("Bob Johnson", 1002, 65000);
Employee* charlie = new Employee("Charlie Brown", 1003, 70000);
Employee* diana = new Employee("Diana Miller", 1004, 68000);

// Add skills to employees
alice->addSkill("C++");
alice->addSkill("Python");
bob->addSkill("Java");
bob->addSkill("SQL");
charlie->addSkill("JavaScript");
charlie->addSkill("HTML/CSS");
diana->addSkill("Python");
diana->addSkill("Data Analysis");

// Add employees to departments
engineering.addEmployee(alice);
engineering.addEmployee(bob);
marketing.addEmployee(charlie);
marketing.addEmployee(diana);

// Display department information
cout << "\nDepartment Information:" << endl;
engineering.displayEmployees();
cout << endl;
marketing.displayEmployees();

// Display employee information
cout << "\nEmployee Information:" << endl;
alice->display();
cout << endl;
charlie->display();

// Test relationship management
cout << "\nMoving Bob from Engineering to Marketing:" << endl;
engineering.removeEmployee(bob);
marketing.addEmployee(bob);

// Display updated departments
cout << "\nUpdated Department Information:" << endl;
engineering.displayEmployees();
cout << endl;
marketing.displayEmployees();

// Test skill checking
cout << "\nSkill Check:" << endl;
cout << "Alice knows Python: " << (alice->hasSkill("Python") ? "Yes" : "No") << endl;
cout << "Bob knows Python: " << (bob->hasSkill("Python") ? "Yes" : "No") << endl;

// Clean up
delete alice;
delete bob;
delete charlie;
delete diana;

Expected Output:
Department created: Engineering at Building A
Department created: Marketing at Building B
Employee created: Alice Smith (ID: 1001)
Employee created: Bob Johnson (ID: 1002)
Employee created: Charlie Brown (ID: 1003)
Employee created: Diana Miller (ID: 1004)
Added Alice Smith to Engineering department
Added Bob Johnson to Engineering department
Added Charlie Brown to Marketing department
Added Diana Miller to Marketing department

Department Information:
Department: Engineering (Building A)
Employee Count: 2
Employees:
- Alice Smith (ID: 1001)
- Bob Johnson (ID: 1002)

Department: Marketing (Building B)
Employee Count: 2
Employees:
- Charlie Brown (ID: 1003)
- Diana Miller (ID: 1004)

Employee Information:
Employee: Alice Smith (ID: 1001)
Salary: $75000.00
Department: Engineering
Skills: C++, Python

Employee: Charlie Brown (ID: 1003)
Salary: $70000.00
Department: Marketing
Skills: JavaScript, HTML/CSS

Moving Bob from Engineering to Marketing:
Removed Bob Johnson from Engineering department
Added Bob Johnson to Marketing department

Updated Department Information:
Department: Engineering (Building A)
Employee Count: 1
Employees:
- Alice Smith (ID: 1001)

Department: Marketing (Building B)
Employee Count: 3
Employees:
- Charlie Brown (ID: 1003)
- Diana Miller (ID: 1004)
- Bob Johnson (ID: 1002)

Skill Check:
Alice knows Python: Yes
Bob knows Python: No
Employee destroyed: Alice Smith
Employee destroyed: Bob Johnson
Employee destroyed: Charlie Brown
Employee destroyed: Diana Miller
Department destroyed: Engineering
Department destroyed: Marketing
```

Key Relationship Concepts:
1. **Association**:
   - Department has references to Employee objects (employees vector)
   - Employee has a reference to Department object (department pointer)
   - Objects exist independently of each other
   - Relationship is navigable in both directions (bidirectional)

2. **Composition**:
   - Employee owns skills (vector<string> skills)
   - Skills are created and destroyed with the Employee
   - Skills have no independent existence

3. **Forward Declaration**:
   - Resolves circular dependency between Employee and Department
   - Allows each class to reference the other
   - Full definition not needed for pointer declarations

4. **Relationship Management**:
   - Bidirectional relationship maintenance
   - Consistent state between related objects
   - Proper addition and removal operations
   - Validation to prevent duplicates

5. **Memory Management**:
   - Proper ownership semantics
   - Clear responsibility for object lifecycle
   - Prevention of dangling pointers
   - Clean destruction sequence

## Practice Exercises

The `Tutorials/Module05/Part1/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., `Complex_starter.h`)
   - Main program template (e.g., `main_complex_starter.cpp`)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your class design
      - Define member variables
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement all required methods
      - Add proper validation
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -o complex_test main_complex_starter.cpp Complex_starter.cpp
   ./complex_test
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand behavior
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Complex Number Class

Create a class to represent complex numbers and perform operations on them:

```cpp
class Complex {
private:
    double real;
    double imag;
    
public:
    // Constructors
    Complex();                          // Default constructor (0+0i)
    Complex(double r);                  // Real-only constructor (r+0i)
    Complex(double r, double i);        // Full constructor (r+i*i)
    
    // Basic operations
    void setReal(double r);
    void setImag(double i);
    double getReal() const;
    double getImag() const;
    
    // Mathematical operations
    Complex add(const Complex& other) const;
    Complex subtract(const Complex& other) const;
    Complex multiply(const Complex& other) const;
    Complex divide(const Complex& other) const;
    Complex conjugate() const;          // Returns complex conjugate
    
    // Utility methods
    double magnitude() const;           // Returns |z| = sqrt(a^2 + b^2)
    double argument() const;            // Returns angle in radians
    void display() const;               // Prints in a+bi format
    string toString() const;            // Returns string representation
};
```

Requirements:
1. **Constructors**:
   - Default constructor should initialize to 0+0i
   - Real-only constructor should set imaginary part to 0
   - Full constructor should initialize both parts

2. **Mathematical Operations**:
   - Addition: (a+bi) + (c+di) = (a+c) + (b+d)i
   - Subtraction: (a+bi) - (c+di) = (a-c) + (b-d)i
   - Multiplication: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
   - Division: (a+bi) / (c+di) = ((ac+bd)/(c²+d²)) + ((bc-ad)/(c²+d²))i
   - Conjugate: (a+bi)* = a-bi

3. **Utility Methods**:
   - Magnitude: |a+bi| = √(a² + b²)
   - Argument: θ = atan2(b, a)
   - Display: Format as "a+bi" or "a-bi" (handle special cases)
   - ToString: Return string representation

4. **Error Handling**:
   - Division by zero (when denominator is zero)
   - Invalid operations
   - Proper validation

Example Usage:
```cpp
// Create complex numbers
Complex a(3, 4);     // 3+4i
Complex b(1, -2);    // 1-2i
Complex c;           // 0+0i

// Test operations
Complex sum = a.add(b);
Complex product = a.multiply(b);
Complex quotient = a.divide(b);

// Display results
cout << "a = ";
a.display();
cout << "b = ";
b.display();
cout << "a + b = ";
sum.display();
cout << "a * b = ";
product.display();
cout << "a / b = ";
quotient.display();
cout << "Magnitude of a = " << a.magnitude() << endl;
cout << "Conjugate of a = " << a.conjugate().toString() << endl;

Expected Output:
a = 3+4i
b = 1-2i
a + b = 4+2i
a * b = 11+0i
a / b = -0.2+1.6i
Magnitude of a = 5
Conjugate of a = 3-4i
```

### Exercise 2: Matrix Class

Implement a 2D matrix class with basic matrix operations:

```cpp
class Matrix {
private:
    vector<vector<double>> data;
    size_t rows;
    size_t cols;
    
    // Helper methods
    bool isValidIndex(size_t i, size_t j) const;
    bool canMultiply(const Matrix& other) const;
    bool canAdd(const Matrix& other) const;
    
public:
    // Constructors
    Matrix(size_t r, size_t c);                         // Zero matrix of size r×c
    Matrix(const vector<vector<double>>& values);       // Initialize with values
    
    // Element access
    double get(size_t i, size_t j) const;
    void set(size_t i, size_t j, double value);
    
    // Matrix properties
    size_t getRows() const;
    size_t getCols() const;
    bool isSquare() const;
    
    // Matrix operations
    Matrix add(const Matrix& other) const;
    Matrix subtract(const Matrix& other) const;
    Matrix multiply(const Matrix& other) const;
    Matrix transpose() const;
    Matrix scalarMultiply(double scalar) const;
    
    // Special matrices
    static Matrix identity(size_t n);                   // Create n×n identity matrix
    
    // Utility methods
    void display() const;
    double determinant() const;                         // For 2×2 matrices
    bool isSymmetric() const;                           // Check if A = A^T
};
```

Requirements:
1. **Constructors**:
   - Size constructor should create a zero matrix (all elements 0)
   - Values constructor should validate dimensions and initialize

2. **Element Access**:
   - Validate indices before access
   - Throw exceptions for invalid indices
   - Provide clear error messages

3. **Matrix Operations**:
   - Addition/Subtraction: Matrices must have same dimensions
   - Multiplication: Number of columns in first matrix must equal number of rows in second
   - Transpose: Swap rows and columns
   - Scalar multiplication: Multiply each element by scalar

4. **Special Methods**:
   - Identity matrix: Create n×n matrix with 1s on diagonal, 0s elsewhere
   - Determinant: Implement for 2×2 matrices
   - Symmetric check: Verify if matrix equals its transpose

5. **Error Handling**:
   - Dimension validation
   - Index bounds checking
   - Operation compatibility checking
   - Exception throwing with descriptive messages

Example Usage:
```cpp
// Create matrices
Matrix A(2, 2);
A.set(0, 0, 1); A.set(0, 1, 2);
A.set(1, 0, 3); A.set(1, 1, 4);

Matrix B(2, 2);
B.set(0, 0, 5); B.set(0, 1, 6);
B.set(1, 0, 7); B.set(1, 1, 8);

// Test operations
Matrix C = A.add(B);
Matrix D = A.multiply(B);
Matrix E = A.transpose();

// Display results
cout << "Matrix A:" << endl;
A.display();
cout << "Matrix B:" << endl;
B.display();
cout << "A + B:" << endl;
C.display();
cout << "A * B:" << endl;
D.display();
cout << "A^T:" << endl;
E.display();
cout << "det(A) = " << A.determinant() << endl;
cout << "Is A symmetric? " << (A.isSymmetric() ? "Yes" : "No") << endl;

// Create identity matrix
Matrix I = Matrix::identity(2);
cout << "2x2 Identity Matrix:" << endl;
I.display();

Expected Output:
Matrix A:
1 2
3 4
Matrix B:
5 6
7 8
A + B:
6 8
10 12
A * B:
19 22
43 50
A^T:
1 3
2 4
det(A) = -2
Is A symmetric? No
2x2 Identity Matrix:
1 0
0 1
```

### Exercise 3: Fraction Class

Create a class to represent and manipulate fractions:

```cpp
class Fraction {
private:
    int numerator;
    int denominator;
    
    // Helper methods
    void reduce();                                  // Simplify fraction
    int gcd(int a, int b) const;                    // Greatest common divisor
    int lcm(int a, int b) const;                    // Least common multiple
    void normalize();                               // Handle signs and zero
    
public:
    // Constructors
    Fraction(int num = 0, int den = 1);             // Default and parameterized
    
    // Getters and setters
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int num);
    void setDenominator(int den);                   // Should handle zero
    
    // Basic operations
    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;
    Fraction reciprocal() const;                    // Returns 1/fraction
    
    // Comparison
    bool equals(const Fraction& other) const;
    bool lessThan(const Fraction& other) const;
    bool greaterThan(const Fraction& other) const;
    
    // Conversion
    double toDouble() const;                        // Convert to decimal
    string toString() const;                        // Format as "num/den"
    
    // Display
    void display() const;                           // Print fraction
};
```

Requirements:
1. **Fraction Representation**:
   - Store numerator and denominator as integers
   - Always keep fractions in reduced form
   - Denominator should never be zero
   - Denominator should always be positive (negative sign in numerator)
   - Handle special cases (zero, negative fractions)

2. **Mathematical Operations**:
   - Addition: a/b + c/d = (ad + bc)/bd
   - Subtraction: a/b - c/d = (ad - bc)/bd
   - Multiplication: (a/b) * (c/d) = (ac)/(bd)
   - Division: (a/b) / (c/d) = (a/b) * (d/c) = (ad)/(bc)
   - Always reduce results to lowest terms

3. **Helper Methods**:
   - GCD: Greatest common divisor for reduction
   - LCM: Least common multiple for addition/subtraction
   - Normalize: Handle signs and special cases
   - Reduce: Simplify fraction to lowest terms

4. **Error Handling**:
   - Prevent division by zero
   - Handle invalid inputs
   - Throw exceptions with clear messages

Example Usage:
```cpp
// Create fractions
Fraction a(3, 4);      // 3/4
Fraction b(1, 2);      // 1/2
Fraction c(-5, 10);    // -5/10 should be reduced to -1/2
Fraction d(6, -8);     // 6/-8 should be normalized to -3/4

// Test operations
Fraction sum = a.add(b);
Fraction diff = a.subtract(b);
Fraction product = a.multiply(b);
Fraction quotient = a.divide(b);

// Display results
cout << "a = " << a.toString() << endl;
cout << "b = " << b.toString() << endl;
cout << "c = " << c.toString() << endl;
cout << "d = " << d.toString() << endl;
cout << "a + b = " << sum.toString() << endl;
cout << "a - b = " << diff.toString() << endl;
cout << "a * b = " << product.toString() << endl;
cout << "a / b = " << quotient.toString() << endl;
cout << "a as decimal = " << a.toDouble() << endl;
cout << "a == b? " << (a.equals(b) ? "Yes" : "No") << endl;
cout << "a < b? " << (a.lessThan(b) ? "Yes" : "No") << endl;

// Test error handling
try {
    Fraction bad(1, 0);  // Should throw exception
} catch (const exception& e) {
    cout << "Error: " << e.what() << endl;
}

Expected Output:
a = 3/4
b = 1/2
c = -1/2
d = -3/4
a + b = 5/4
a - b = 1/4
a * b = 3/8
a / b = 3/2
a as decimal = 0.75
a == b? No
a < b? No
Error: Denominator cannot be zero
```

## Summary

### Key Concepts

1. **Class Structure**
   ```cpp
   class ClassName {
   private:
       // Data members
       // Helper methods
   
   public:
       // Interface methods
       // Public operations
   };
   ```

2. **Member Access**
   ```cpp
   private:   // Class only
   protected: // Class and derived
   public:    // Everyone
   ```

3. **Method Types**
   ```cpp
   void modify();          // Modifying method
   int getData() const;    // Non-modifying method
   static void utility();  // Class method
   ```

### Common Pitfalls

1. **Access Control**
   ```cpp
   // Wrong: Public data
   public:
       int data;  // Exposed implementation
   
   // Right: Encapsulation
   private:
       int data;
   public:
       int getData() const;
   ```

2. **Const Correctness**
   ```cpp
   // Wrong: Missing const
   string getName() { return name; }
   
   // Right: Const method
   string getName() const { return name; }
   ```

3. **Resource Management**
   ```cpp
   // Wrong: Raw pointers
   class Unsafe {
       int* data;  // Raw pointer
   };
   
   // Right: Smart pointers
   class Safe {
       unique_ptr<int> data;  // Managed resource
   };
   ```

### Best Practices

1. **Class Design**
   - Keep data private
   - Provide clear interface
   - Use const correctly
   - Handle resources properly
   - Document behavior
   - Validate input
   - Follow naming conventions

2. **Method Implementation**
   - Single responsibility
   - Clear parameters
   - Proper validation
   - Error handling
   - Consistent behavior
   - Efficient operations
   - Clear documentation

3. **Resource Management**
   - RAII principles
   - Smart pointers
   - Copy semantics
   - Move semantics
   - Exception safety
   - Memory management
   - Resource cleanup

4. **Documentation**
   - Class purpose
   - Method behavior
   - Parameters
   - Return values
   - Error conditions
   - Examples
   - Dependencies

## Next Steps
1. Complete practice exercises
2. Test with various inputs
3. Handle edge cases
4. Review error handling
5. Move on to [Part 2: Constructors and Destructors]({{ site.baseurl }}/tutorials/module5/part2-constructors)

Remember: Classes are the foundation of object-oriented programming. Design them carefully with clear responsibilities, well-defined interfaces, and proper resource management.
