#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ===== Exercise 1: Shape Calculator =====
// TODO: Declare these shape calculation functions:
// 1. double calculateCircleArea(double radius)
//    - Calculates area of circle using PI * radius * radius

// 2. double calculateRectangleArea(double length, double width)
//    - Calculates area of rectangle using length * width

// 3. double calculateTriangleArea(double base, double height)
//    - Calculates area of triangle using 0.5 * base * height

// 4. void displayArea(string shape, double area)
//    - Displays shape name and area with 2 decimal places


// ===== Exercise 2: Text Analyzer =====
// TODO: Declare these text analysis functions:
// 1. int countVowels(const string& text)
//    - Counts number of vowels in text

// 2. int countConsonants(const string& text)
//    - Counts number of consonants in text

// 3. double calculateLetterRatio(int vowels, int consonants)
//    - Calculates vowel to consonant ratio

// 4. void displayTextStats(const string& text)
//    - Displays text analysis results


// ===== Exercise 3: Grade Calculator =====
struct Grade {
    string subject;
    double score;
    char letterGrade;
};

// TODO: Declare these grade calculation functions:
// 1. Grade createGrade(string subject, double score)
//    - Creates and returns a Grade object with calculated letter grade

// 2. char calculateLetterGrade(double score)
//    - Returns letter grade based on score:
//      90+ = 'A', 80+ = 'B', 70+ = 'C', 60+ = 'D', below 60 = 'F'

// 3. double calculateGPA(const vector<Grade>& grades)
//    - Calculates GPA from letter grades:
//      A=4.0, B=3.0, C=2.0, D=1.0, F=0.0

// 4. void displayGradeReport(const vector<Grade>& grades)
//    - Displays formatted grade report with GPA


int main() {
    // Test Exercise 1: Shape Calculator
    cout << "===== Shape Calculator =====" << endl;
    double radius = 5.0;
    double length = 4.0, width = 6.0;
    double base = 3.0, height = 8.0;
    
    // TODO: Calculate and display areas for circle, rectangle, and triangle
    cout << endl;
    
    // Test Exercise 2: Text Analyzer
    cout << "===== Text Analyzer =====" << endl;
    string text = "Hello World! How are you today?";
    // TODO: Analyze and display text statistics
    cout << endl;
    
    // Test Exercise 3: Grade Calculator
    cout << "===== Grade Calculator =====" << endl;
    vector<Grade> grades;
    // TODO: Create and add grades for Math(95.5), English(88.0), and History(92.5)
    // TODO: Display grade report
    
    return 0;
}

// ===== Exercise 1: Shape Calculator Implementation =====
// TODO: Implement shape calculator functions


// ===== Exercise 2: Text Analyzer Implementation =====
// TODO: Implement text analyzer functions


// ===== Exercise 3: Grade Calculator Implementation =====
// TODO: Implement grade calculator functions
