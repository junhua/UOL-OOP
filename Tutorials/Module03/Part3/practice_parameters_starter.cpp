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

// TODO: Declare these student grade calculator functions:
// 1. void addGrade(Student& student, double grade)
//    - Adds a grade to student's grade vector if valid (0-100)

// 2. double calculateAverage(const Student& student)
//    - Calculates average of all grades

// 3. char getLetterGrade(double average)
//    - Returns letter grade based on average:
//      90+ = 'A', 80+ = 'B', 70+ = 'C', 60+ = 'D', below 60 = 'F'

// 4. void printStudentReport(const Student& student)
//    - Prints student name, grades, average, and letter grade


// ===== Exercise 2: Array Operations =====
// TODO: Declare these array operation functions:
// 1. void fillArray(int arr[], int size)
//    - Fills array with sequential numbers (1, 2, 3, ...)

// 2. void modifyArray(int arr[], int size, int multiplier)
//    - Multiplies each element by the multiplier

// 3. int findMax(const int arr[], int size)
//    - Returns maximum value in array

// 4. void printArray(const int arr[], int size)
//    - Prints array elements


// ===== Exercise 3: String Manipulator =====
// TODO: Declare these string manipulation functions:
// 1. void appendText(string& text, const string& suffix)
//    - Appends suffix to text

// 2. string wrapInTags(const string& text, const string& tag)
//    - Wraps text in HTML-style tags

// 3. int countOccurrences(const string& text, char target)
//    - Counts occurrences of target character

// 4. void convertCase(string& text, char mode)
//    - Converts text to upper ('u') or lower ('l') case


int main() {
    // Test Exercise 1: Student Grade Calculator
    cout << "===== Student Grade Calculator =====" << endl;
    // TODO: Create a student and add some grades
    // TODO: Print student report
    cout << endl;
    
    // Test Exercise 2: Array Operations
    cout << "===== Array Operations =====" << endl;
    // TODO: Create and fill an array
    // TODO: Print original array
    // TODO: Modify array and print again
    // TODO: Find and print maximum value
    cout << endl;
    
    // Test Exercise 3: String Manipulator
    cout << "===== String Manipulator =====" << endl;
    // TODO: Create and manipulate strings
    // TODO: Test all string operations
    
    return 0;
}

// ===== Exercise 1: Student Grade Calculator Implementation =====
// TODO: Implement addGrade
// Function: addGrade
// Purpose: Adds a valid grade to student's grades
// Parameters: student - reference to Student object
//            grade - grade to add (must be 0-100)
// Returns: void

// TODO: Implement calculateAverage
// Function: calculateAverage
// Purpose: Calculates average of all grades
// Parameters: student - const reference to Student object
// Returns: double - average grade (0.0 if no grades)

// TODO: Implement getLetterGrade
// Function: getLetterGrade
// Purpose: Converts numeric average to letter grade
// Parameters: average - numeric grade average
// Returns: char - letter grade

// TODO: Implement printStudentReport
// Function: printStudentReport
// Purpose: Displays complete student grade report
// Parameters: student - const reference to Student object
// Returns: void

// ===== Exercise 2: Array Operations Implementation =====
// TODO: Implement fillArray
// Function: fillArray
// Purpose: Fills array with sequential numbers
// Parameters: arr - array to fill
//            size - size of array
// Returns: void

// TODO: Implement modifyArray
// Function: modifyArray
// Purpose: Multiplies each array element
// Parameters: arr - array to modify
//            size - size of array
//            multiplier - value to multiply by
// Returns: void

// TODO: Implement findMax
// Function: findMax
// Purpose: Finds maximum value in array
// Parameters: arr - const array to search
//            size - size of array
// Returns: int - maximum value (0 if empty)

// TODO: Implement printArray
// Function: printArray
// Purpose: Displays array elements
// Parameters: arr - const array to print
//            size - size of array
// Returns: void

// ===== Exercise 3: String Manipulator Implementation =====
// TODO: Implement appendText
// Function: appendText
// Purpose: Adds suffix to end of text
// Parameters: text - reference to string to modify
//            suffix - const reference to string to append
// Returns: void

// TODO: Implement wrapInTags
// Function: wrapInTags
// Purpose: Wraps text in HTML-style tags
// Parameters: text - const reference to text to wrap
//            tag - const reference to tag name
// Returns: string - wrapped text

// TODO: Implement countOccurrences
// Function: countOccurrences
// Purpose: Counts character occurrences
// Parameters: text - const reference to text to search
//            target - character to count
// Returns: int - number of occurrences

// TODO: Implement convertCase
// Function: convertCase
// Purpose: Changes text case
// Parameters: text - reference to string to modify
//            mode - 'u' for upper, 'l' for lower
// Returns: void
