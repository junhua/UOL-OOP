#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
using namespace std;

// Forward declarations for Shape Calculator
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);
void displayArea(string shape, double area);

// Forward declarations for Text Analyzer
int countVowels(const string& text);
int countConsonants(const string& text);
double calculateLetterRatio(int vowels, int consonants);
void displayTextStats(const string& text);

// Forward declarations for Grade Calculator
struct Grade {
    string subject;
    double score;
    char letterGrade;
};

Grade createGrade(string subject, double score);
char calculateLetterGrade(double score);
double calculateGPA(const vector<Grade>& grades);
void displayGradeReport(const vector<Grade>& grades);

// Shape Calculator Implementations
double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

void displayArea(string shape, double area) {
    cout << shape << " Area: " << fixed << setprecision(2) << area << endl;
}

// Text Analyzer Implementations
int countVowels(const string& text) {
    int count = 0;
    string vowels = "aeiouAEIOU";
    for (char c : text) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

int countConsonants(const string& text) {
    int count = 0;
    for (char c : text) {
        if (isalpha(c) && string("aeiouAEIOU").find(c) == string::npos) {
            count++;
        }
    }
    return count;
}

double calculateLetterRatio(int vowels, int consonants) {
    if (consonants == 0) return 0.0;
    return static_cast<double>(vowels) / consonants;
}

void displayTextStats(const string& text) {
    int vowels = countVowels(text);
    int consonants = countConsonants(text);
    double ratio = calculateLetterRatio(vowels, consonants);
    
    cout << "Text Analysis:" << endl;
    cout << "-------------" << endl;
    cout << "Text: " << text << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Vowel/Consonant Ratio: " << fixed << setprecision(2) << ratio << endl;
}

// Grade Calculator Implementations
Grade createGrade(string subject, double score) {
    Grade grade;
    grade.subject = subject;
    grade.score = score;
    grade.letterGrade = calculateLetterGrade(score);
    return grade;
}

char calculateLetterGrade(double score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}

double calculateGPA(const vector<Grade>& grades) {
    if (grades.empty()) return 0.0;
    
    double total = 0.0;
    for (const Grade& grade : grades) {
        switch (grade.letterGrade) {
            case 'A': total += 4.0; break;
            case 'B': total += 3.0; break;
            case 'C': total += 2.0; break;
            case 'D': total += 1.0; break;
            default: total += 0.0;
        }
    }
    
    return total / grades.size();
}

void displayGradeReport(const vector<Grade>& grades) {
    cout << "\nGrade Report" << endl;
    cout << "============" << endl;
    cout << setw(15) << left << "Subject" 
         << setw(10) << "Score" 
         << "Letter Grade" << endl;
    cout << string(35, '-') << endl;
    
    for (const Grade& grade : grades) {
        cout << setw(15) << left << grade.subject 
             << setw(10) << grade.score 
             << grade.letterGrade << endl;
    }
    
    cout << "\nGPA: " << fixed << setprecision(2) 
         << calculateGPA(grades) << endl;
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
