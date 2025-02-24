#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ===== Exercise 1: Shape Calculator =====
// Function declarations
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);
void displayArea(string shape, double area);

// ===== Exercise 2: Text Analyzer =====
// Function declarations
int countVowels(const string& text);
int countConsonants(const string& text);
double calculateLetterRatio(int vowels, int consonants);
void displayTextStats(const string& text);

// ===== Exercise 3: Grade Calculator =====
struct Grade {
    string subject;
    double score;
    char letterGrade;
};

// Function declarations
Grade createGrade(string subject, double score);
char calculateLetterGrade(double score);
double calculateGPA(const vector<Grade>& grades);
void displayGradeReport(const vector<Grade>& grades);

int main() {
    // Test Exercise 1: Shape Calculator
    cout << "===== Shape Calculator =====" << endl;
    double radius = 5.0;
    double length = 4.0, width = 6.0;
    double base = 3.0, height = 8.0;
    
    displayArea("Circle", calculateCircleArea(radius));
    displayArea("Rectangle", calculateRectangleArea(length, width));
    displayArea("Triangle", calculateTriangleArea(base, height));
    cout << endl;
    
    // Test Exercise 2: Text Analyzer
    cout << "===== Text Analyzer =====" << endl;
    string text = "Hello World! How are you today?";
    displayTextStats(text);
    cout << endl;
    
    // Test Exercise 3: Grade Calculator
    cout << "===== Grade Calculator =====" << endl;
    vector<Grade> grades;
    grades.push_back(createGrade("Math", 95.5));
    grades.push_back(createGrade("English", 88.0));
    grades.push_back(createGrade("History", 92.5));
    displayGradeReport(grades);
    
    return 0;
}

// ===== Exercise 1: Shape Calculator Implementation =====
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

// ===== Exercise 2: Text Analyzer Implementation =====
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
    return consonants != 0 ? static_cast<double>(vowels) / consonants : 0;
}

void displayTextStats(const string& text) {
    int vowels = countVowels(text);
    int consonants = countConsonants(text);
    double ratio = calculateLetterRatio(vowels, consonants);
    
    cout << "Text: \"" << text << "\"" << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Vowel/Consonant Ratio: " << fixed << setprecision(2) << ratio << endl;
}

// ===== Exercise 3: Grade Calculator Implementation =====
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
            default: break;
        }
    }
    return total / grades.size();
}

void displayGradeReport(const vector<Grade>& grades) {
    cout << "Grade Report:" << endl;
    cout << setw(10) << "Subject" << setw(10) << "Score" 
         << setw(10) << "Grade" << endl;
    cout << string(30, '-') << endl;
    
    for (const Grade& grade : grades) {
        cout << setw(10) << grade.subject 
             << setw(10) << fixed << setprecision(1) << grade.score
             << setw(10) << grade.letterGrade << endl;
    }
    
    cout << "\nGPA: " << fixed << setprecision(2) << calculateGPA(grades) << endl;
}
