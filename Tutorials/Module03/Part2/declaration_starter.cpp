#include <iostream>
#include <string>
using namespace std;

// ===== Step 1: Basic Function Declaration =====
// TODO: Declare these basic functions:
// 1. void printMessage()
//    - Prints "Hello from a basic function!"

// 2. int getNumber()
//    - Returns a fixed number (42)

// 3. void displayNumber(int num)
//    - Displays "The number is: [num]"


// ===== Step 2: Functions with Parameters =====
// TODO: Declare these functions with parameters:
// 1. double calculateArea(double radius)
//    - Calculates circle area using PI * radius * radius

// 2. string formatName(string first, string last)
//    - Returns "last, first" format

// 3. bool isEven(int number)
//    - Returns true if number is even


// ===== Step 3: Advanced Function Organization =====
// TODO: Declare the Student struct and related functions:
struct Student {
    string name;
    double gpa;
};

// 1. Student createStudent(string name, double gpa)
//    - Creates and returns a Student object

// 2. void displayStudent(const Student& student)
//    - Displays student name and GPA

// 3. bool isHonorsStudent(const Student& student)
//    - Returns true if GPA >= 3.5


int main() {
    // Test Step 1: Basic functions
    cout << "===== Testing Step 1 =====" << endl;
    // TODO: Call printMessage
    
    // TODO: Get and display a number using getNumber and displayNumber
    cout << endl;
    
    // Test Step 2: Functions with parameters
    cout << "===== Testing Step 2 =====" << endl;
    double radius = 5.0;
    // TODO: Calculate and display circle area
    
    // TODO: Format and display "John" "Doe"
    
    // TODO: Test if 42 is even
    cout << endl;
    
    // Test Step 3: Student management
    cout << "===== Testing Step 3 =====" << endl;
    // TODO: Create a student with name "Alice Smith" and GPA 3.8
    // TODO: Display student information
    // TODO: Check and display if student is honors
    
    return 0;
}

// ===== Function Definitions =====
// TODO: Implement all the functions you declared above

// Step 1: Basic function definitions
// TODO: Implement printMessage
// TODO: Implement getNumber
// TODO: Implement displayNumber

// Step 2: Functions with parameters
// TODO: Implement calculateArea
// TODO: Implement formatName
// TODO: Implement isEven

// Step 3: Student management functions
// TODO: Implement createStudent
// TODO: Implement displayStudent
// TODO: Implement isHonorsStudent
