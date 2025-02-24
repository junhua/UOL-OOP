---
layout: default
title: Part 2 - Function Declaration and Definition
nav_order: 2
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part2-declaration/
---

# Part 2: Function Declaration and Definition

## Learning Objectives
- Understand function declaration and definition separation
- Master function prototypes and implementations
- Learn proper function organization
- Practice writing well-structured code
- Implement proper error handling
- Document functions effectively

## Introduction
Function declarations and definitions are fundamental concepts in C++ that enable better code organization and maintainability. Think of them like a restaurant menu and kitchen:

1. **Why Separate Declaration and Definition**:
   - **Code Organization**: Keep interface separate from implementation
   - **Compilation Efficiency**: Compiler can work with just declarations
   - **Team Collaboration**: Different team members can work on different parts
   - **Code Reuse**: Share declarations across multiple files
   - **Maintenance**: Change implementation without affecting other code

2. **Real-World Parallels**:
   - **Restaurant Menu**: Declaration is like the menu (what's available)
   - **Kitchen**: Definition is like the kitchen (how it's made)
   - **Car Dashboard**: Declaration is the controls (what you can do)
   - **Engine**: Definition is the engine (how it works)

3. **Benefits in Development**:
   - **Better Organization**: Clear separation of interface and implementation
   - **Easier Testing**: Test against declarations before implementation
   - **Simpler Debugging**: Focus on either interface or implementation
   - **Code Protection**: Hide implementation details
   - **Flexible Updates**: Change implementation without affecting users

## Implementation Guide

You'll find the starter code in `Tutorials/Module03/Part2/declaration_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module03/Part2/declaration.cpp`.

### Step 1: Basic Function Declaration
First, let's understand basic function declarations:

```cpp
// Function declarations (prototypes)
void printMessage();
int getNumber();
void displayNumber(int num);

int main() {
    printMessage();
    int num = getNumber();
    displayNumber(num);
    return 0;
}

// Function definitions
void printMessage() {
    cout << "Hello from a basic function!" << endl;
}

int getNumber() {
    return 42;
}

void displayNumber(int num) {
    cout << "The number is: " << num << endl;
}
```

Test Cases:

```cpp
Expected Output:
Hello from a basic function!
The number is: 42
```

### Step 2: Functions with Parameters
Add parameters to your declarations:

```cpp
// Function declarations
double calculateArea(double radius);
string formatName(string first, string last);
bool isEven(int number);

int main() {
    cout << "Area: " << calculateArea(5.0) << endl;
    cout << "Name: " << formatName("John", "Doe") << endl;
    cout << "Is 42 even? " << (isEven(42) ? "Yes" : "No") << endl;
    return 0;
}

// Function definitions
double calculateArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

string formatName(string first, string last) {
    return last + ", " + first;
}

bool isEven(int number) {
    return number % 2 == 0;
}
```

Test Cases:

```cpp
Input: calculateArea(5.0)
Expected: Area: 78.53975

Input: formatName("John", "Doe")
Expected: Name: Doe, John

Input: isEven(42)
Expected: Is 42 even? Yes
```

### Step 3: Advanced Function Organization
Organize related functions together:

```cpp
// Struct declaration
struct Student {
    string name;
    double gpa;
};

// Function declarations
Student createStudent(string name, double gpa);
void displayStudent(const Student& student);
bool isHonorsStudent(const Student& student);

int main() {
    Student student = createStudent("Alice Smith", 3.8);
    displayStudent(student);
    cout << "Honors: " << (isHonorsStudent(student) ? "Yes" : "No") << endl;
    return 0;
}

// Function definitions
Student createStudent(string name, double gpa) {
    Student student;
    student.name = name;
    student.gpa = gpa;
    return student;
}

void displayStudent(const Student& student) {
    cout << "Student: " << student.name << endl;
    cout << "GPA: " << student.gpa << endl;
}

bool isHonorsStudent(const Student& student) {
    return student.gpa >= 3.5;
}
```

Test Cases:

```cpp
Input: Student("Alice Smith", 3.8)
Expected Output:
Student: Alice Smith
GPA: 3.8
Honors: Yes
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part2/practice_declaration_starter.cpp`
- Complete solution: `Tutorials/Module03/Part2/practice_declaration.cpp`

Follow these steps:
1. Open the starter template
2. Implement each exercise following the requirements
3. Test your implementation with the provided test cases
4. Compare your solution with the complete version if needed

### Exercise 1: Shape Calculator
Create a shape calculation system:

```cpp
// TODO: Declare these functions
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);
void displayArea(string shape, double area);
```

### Exercise 2: Text Analyzer
Implement text analysis functions:

```cpp
// TODO: Declare these functions
int countVowels(const string& text);
int countConsonants(const string& text);
double calculateLetterRatio(int vowels, int consonants);
void displayTextStats(const string& text);
```

### Exercise 3: Grade Calculator
Create a grading system:

```cpp
struct Grade {
    string subject;
    double score;
    char letterGrade;
};

// TODO: Declare these functions
Grade createGrade(string subject, double score);
char calculateLetterGrade(double score);
double calculateGPA(const vector<Grade>& grades);
void displayGradeReport(const vector<Grade>& grades);
```

## Summary

### Key Concepts

1. **Function Declaration**
   - Tells compiler about function existence
   - Also called function prototype
   - Must match definition exactly

   ```cpp
   // Declaration only
   void processData(int value);
   double calculateArea(double radius);
   string formatText(const string& text);
   ```

2. **Function Definition**
   - Contains actual implementation
   - Can be in different file from declaration
   - Must match declaration exactly

   ```cpp
   // Definition matches declaration
   void processData(int value) {
       cout << "Processing: " << value << endl;
   }

   double calculateArea(double radius) {
       const double PI = 3.14159;
       return PI * radius * radius;
   }
   ```

3. **Separation Benefits**
   - **Header Files**: Declarations in .h files

     ```cpp
     // mathFunctions.h
     double add(double a, double b);
     double subtract(double a, double b);
     ```

   - **Source Files**: Definitions in .cpp files

     ```cpp
     // mathFunctions.cpp
     double add(double a, double b) {
         return a + b;
     }
     ```

4. **Forward Declaration**
   - Declare functions before use
   - Enable function ordering flexibility
   - Support mutual recursion

   ```cpp
   void processB(int x);  // Forward declaration

   void processA(int x) {
       if (x > 0) processB(x - 1);
   }

   void processB(int x) {  // Definition
       if (x > 0) processA(x - 1);
   }
   ```

### Common Pitfalls

1. **Declaration/Definition Mismatch**

   ```cpp
   // Declaration
   void process(int x);

   // Error: Return type doesn't match
   int process(int x) {  // Wrong!
       return x;
   }
   ```

2. **Missing Declaration**

   ```cpp
   int main() {
       display(5);  // Error: No declaration for display
       return 0;
   }

   void display(int x) {  // Too late!
       cout << x << endl;
   }
   ```

3. **Parameter Type Mismatch**

   ```cpp
   // Declaration
   void calculate(double x);

   // Error: Parameter type doesn't match
   void calculate(int x) {  // Wrong!
       cout << x << endl;
   }
   ```

### Best Practices
1. Declare functions before using them
2. Match declarations and definitions exactly
3. Group related functions together
4. Use clear, descriptive names
5. Document function behavior
6. Handle errors appropriately
7. Test thoroughly
8. Keep functions focused

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Review error handling
5. Move on to [Part 3: Function Parameters]({{ site.baseurl }}/tutorials/module3/part3-parameters)

Remember: Good function organization starts with proper declarations and definitions. Take time to plan your functions before implementing them.
