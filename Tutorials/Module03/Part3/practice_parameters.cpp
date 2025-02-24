#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ===== Exercise 1: Student Grade Calculator =====
struct Student {
    string name;
    vector<double> grades;
};

// Function declarations
void addGrade(Student& student, double grade);
double calculateAverage(const Student& student);
char getLetterGrade(double average);
void printStudentReport(const Student& student);

// ===== Exercise 2: Array Operations =====
// Function declarations
void fillArray(int arr[], int size);
void modifyArray(int arr[], int size, int multiplier);
int findMax(const int arr[], int size);
void printArray(const int arr[], int size);

// ===== Exercise 3: String Manipulator =====
// Function declarations
void appendText(string& text, const string& suffix);
string wrapInTags(const string& text, const string& tag);
int countOccurrences(const string& text, char target);
void convertCase(string& text, char mode);

int main() {
    // Test Exercise 1: Student Grade Calculator
    cout << "===== Student Grade Calculator =====" << endl;
    Student student{"Alice Smith", {}};
    addGrade(student, 85.5);
    addGrade(student, 92.0);
    addGrade(student, 88.5);
    printStudentReport(student);
    cout << endl;
    
    // Test Exercise 2: Array Operations
    cout << "===== Array Operations =====" << endl;
    const int SIZE = 5;
    int numbers[SIZE];
    
    fillArray(numbers, SIZE);
    cout << "Original array: ";
    printArray(numbers, SIZE);
    
    modifyArray(numbers, SIZE, 2);
    cout << "After multiplication by 2: ";
    printArray(numbers, SIZE);
    
    int max = findMax(numbers, SIZE);
    cout << "Maximum value: " << max << endl;
    cout << endl;
    
    // Test Exercise 3: String Manipulator
    cout << "===== String Manipulator =====" << endl;
    string text = "Hello";
    cout << "Original text: " << text << endl;
    
    appendText(text, " World!");
    cout << "After append: " << text << endl;
    
    string htmlText = wrapInTags(text, "p");
    cout << "HTML wrapped: " << htmlText << endl;
    
    int count = countOccurrences(text, 'l');
    cout << "Occurrences of 'l': " << count << endl;
    
    convertCase(text, 'u');
    cout << "Uppercase: " << text << endl;
    
    return 0;
}

// ===== Exercise 1: Student Grade Calculator Implementation =====
void addGrade(Student& student, double grade) {
    if (grade >= 0 && grade <= 100) {
        student.grades.push_back(grade);
    }
}

double calculateAverage(const Student& student) {
    if (student.grades.empty()) return 0.0;
    
    double sum = 0.0;
    for (double grade : student.grades) {
        sum += grade;
    }
    return sum / student.grades.size();
}

char getLetterGrade(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}

void printStudentReport(const Student& student) {
    cout << "Student: " << student.name << endl;
    cout << "Grades: ";
    for (double grade : student.grades) {
        cout << fixed << setprecision(1) << grade << " ";
    }
    cout << endl;
    
    double average = calculateAverage(student);
    char letterGrade = getLetterGrade(average);
    
    cout << "Average: " << average << endl;
    cout << "Letter Grade: " << letterGrade << endl;
}

// ===== Exercise 2: Array Operations Implementation =====
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;  // Fill with 1, 2, 3, ...
    }
}

void modifyArray(int arr[], int size, int multiplier) {
    for (int i = 0; i < size; i++) {
        arr[i] *= multiplier;
    }
}

int findMax(const int arr[], int size) {
    if (size <= 0) return 0;
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ===== Exercise 3: String Manipulator Implementation =====
void appendText(string& text, const string& suffix) {
    text += suffix;
}

string wrapInTags(const string& text, const string& tag) {
    return "<" + tag + ">" + text + "</" + tag + ">";
}

int countOccurrences(const string& text, char target) {
    int count = 0;
    for (char c : text) {
        if (c == target) count++;
    }
    return count;
}

void convertCase(string& text, char mode) {
    for (char& c : text) {
        if (mode == 'u') {
            c = toupper(c);
        } else if (mode == 'l') {
            c = tolower(c);
        }
    }
}
