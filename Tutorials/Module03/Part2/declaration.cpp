#include <iostream>
#include <string>
using namespace std;

// ===== Step 1: Basic Function Declaration =====
// Function declarations
void printMessage();
int getNumber();
void displayNumber(int num);

// ===== Step 2: Functions with Parameters =====
// Function declarations with parameters
double calculateArea(double radius);
string formatName(string first, string last);
bool isEven(int number);

// ===== Step 3: Advanced Function Organization =====
// Related function declarations for student management
struct Student {
    string name;
    double gpa;
};

Student createStudent(string name, double gpa);
void displayStudent(const Student& student);
bool isHonorsStudent(const Student& student);

int main() {
    // Test Step 1: Basic functions
    cout << "===== Testing Step 1 =====" << endl;
    printMessage();
    
    int num = getNumber();
    displayNumber(num);
    cout << endl;
    
    // Test Step 2: Functions with parameters
    cout << "===== Testing Step 2 =====" << endl;
    double radius = 5.0;
    cout << "Area of circle with radius " << radius << ": " 
         << calculateArea(radius) << endl;
    
    string formattedName = formatName("John", "Doe");
    cout << "Formatted name: " << formattedName << endl;
    
    int testNum = 42;
    cout << testNum << " is " << (isEven(testNum) ? "even" : "odd") << endl;
    cout << endl;
    
    // Test Step 3: Student management
    cout << "===== Testing Step 3 =====" << endl;
    Student student = createStudent("Alice Smith", 3.8);
    displayStudent(student);
    cout << student.name << " is " 
         << (isHonorsStudent(student) ? "" : "not ") 
         << "an honors student" << endl;
    
    return 0;
}

// ===== Function Definitions =====

// Step 1: Basic function definitions
void printMessage() {
    cout << "Hello from a basic function!" << endl;
}

int getNumber() {
    return 42;  // Returns a fixed number for demonstration
}

void displayNumber(int num) {
    cout << "The number is: " << num << endl;
}

// Step 2: Functions with parameters
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

// Step 3: Student management functions
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
