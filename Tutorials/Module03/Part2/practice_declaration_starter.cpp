#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
using namespace std;

// TODO: Add forward declarations for Shape Calculator
// - Circle area calculator
// - Rectangle area calculator
// - Triangle area calculator
// - Area display function

// TODO: Add forward declarations for Text Analyzer
// - Vowel counter
// - Consonant counter
// - Letter ratio calculator
// - Stats display function

// TODO: Add forward declarations for Grade Calculator
struct Grade {
    string subject;
    double score;
    char letterGrade;
};

// TODO: Add Grade Calculator forward declarations
// - Grade creation
// - Letter grade calculation
// - GPA calculation
// - Report display

// TODO: Implement Shape Calculator Functions
double calculateCircleArea(double radius) {
    // Your code here
    return 0;
}

double calculateRectangleArea(double length, double width) {
    // Your code here
    return 0;
}

double calculateTriangleArea(double base, double height) {
    // Your code here
    return 0;
}

void displayArea(string shape, double area) {
    // Your code here
}

// TODO: Implement Text Analyzer Functions
int countVowels(const string& text) {
    // Your code here
    return 0;
}

int countConsonants(const string& text) {
    // Your code here
    return 0;
}

double calculateLetterRatio(int vowels, int consonants) {
    // Your code here
    return 0;
}

void displayTextStats(const string& text) {
    // Your code here
}

// TODO: Implement Grade Calculator Functions
Grade createGrade(string subject, double score) {
    // Your code here
    Grade grade;
    grade.letterGrade = 'F';
    return grade;
}

char calculateLetterGrade(double score) {
    // Your code here
    return 'F';
}

double calculateGPA(const vector<Grade>& grades) {
    // Your code here
    return 0.0;
}

void displayGradeReport(const vector<Grade>& grades) {
    // Your code here
}

void testShapeCalculator() {
    cout << "Shape Calculator Test" << endl;
    cout << "====================" << endl;
    
    double radius = 5.0;
    double length = 4.0;
    double width = 6.0;
    double base = 3.0;
    double height = 8.0;
    
    displayArea("Circle", calculateCircleArea(radius));
    displayArea("Rectangle", calculateRectangleArea(length, width));
    displayArea("Triangle", calculateTriangleArea(base, height));
}

void testTextAnalyzer() {
    cout << "\nText Analyzer Test" << endl;
    cout << "=================" << endl;
    
    string text1 = "Hello World";
    string text2 = "AEIOU";
    string text3 = "BCDFG";
    
    displayTextStats(text1);
    cout << endl;
    displayTextStats(text2);
    cout << endl;
    displayTextStats(text3);
}

void testGradeCalculator() {
    cout << "\nGrade Calculator Test" << endl;
    cout << "====================" << endl;
    
    vector<Grade> grades;
    grades.push_back(createGrade("Math", 95.0));
    grades.push_back(createGrade("English", 87.5));
    grades.push_back(createGrade("History", 76.8));
    grades.push_back(createGrade("Science", 92.3));
    
    displayGradeReport(grades);
}

int main() {
    cout << "Practice Declaration Demo" << endl;
    cout << "=======================" << endl;
    
    testShapeCalculator();
    testTextAnalyzer();
    testGradeCalculator();
    
    return 0;
}
