#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// TODO: Implement value parameter examples
// - Modify integer value
// - Process array elements
// - Handle string modification
void modifyValue(int x) {
    // Your code here
}

void processArray(int arr[], int size) {
    // Your code here
}

void handleString(string text) {
    // Your code here
}

// TODO: Implement reference parameter examples
// - Modify integer by reference
// - Swap two values
// - Update string content
void modifyByRef(int& x) {
    // Your code here
}

void swapValues(int& a, int& b) {
    // Your code here
}

void updateString(string& text) {
    // Your code here
}

// TODO: Implement const reference examples
// - Print vector contents
// - Calculate array average
// - Display person information
void printData(const vector<int>& data) {
    // Your code here
}

double calculateAverage(const double values[], int size) {
    // Your code here
    return 0.0;
}

void displayPerson(const string& name, const int& age) {
    // Your code here
}

// TODO: Implement mixed parameter types example
struct Student {
    string name;
    vector<double> grades;
    double average;
};

void addGrade(Student& student, double grade) {
    // Your code here
}

void displayStudent(const Student& student) {
    // Your code here
}

// TODO: Implement multiple return values using references
void getMinMax(const vector<int>& numbers, int& min, int& max) {
    // Your code here
}

// TODO: Complete class with different parameter types
class DataProcessor {
public:
    // Constructor should take name and data by const reference
    DataProcessor(const string& name, const vector<int>& data) {
        // Your code here
    }
    
    void addValue(int value) {
        // Your code here
    }
    
    double getAverage() const {
        // Your code here
        return 0.0;
    }
    
    const string& getName() const {
        // Your code here
        return processorName;
    }
    
    void displayStats() const {
        // Your code here
    }

private:
    string processorName;
    vector<int> values;
    double average;
    
    void processData() {
        // Your code here
    }
};

int main() {
    cout << "Call Types Demo" << endl;
    cout << "=============\n" << endl;
    
    // Test value parameters
    cout << "Value Parameters:" << endl;
    cout << "---------------" << endl;
    
    int number = 42;
    cout << "Before: " << number << endl;
    modifyValue(number);
    cout << "After: " << number << endl;  // Should be unchanged
    
    int data[] = {1, 2, 3};
    cout << "\nBefore array modification: ";
    for (int i = 0; i < 3; i++) cout << data[i] << " ";
    cout << endl;
    
    processArray(data, 3);
    
    cout << "After array modification: ";
    for (int i = 0; i < 3; i++) cout << data[i] << " ";
    cout << endl;
    
    string msg = "Hello";
    cout << "\nBefore: " << msg << endl;
    handleString(msg);
    cout << "After: " << msg << endl;  // Should be unchanged
    
    // Test reference parameters
    cout << "\nReference Parameters:" << endl;
    cout << "-------------------" << endl;
    
    int value = 42;
    cout << "Before: " << value << endl;
    modifyByRef(value);
    cout << "After: " << value << endl;  // Should be modified
    
    int x = 5, y = 10;
    cout << "\nBefore swap: x=" << x << ", y=" << y << endl;
    swapValues(x, y);
    cout << "After swap: x=" << x << ", y=" << y << endl;
    
    string text = "Hello";
    cout << "\nBefore: " << text << endl;
    updateString(text);
    cout << "After: " << text << endl;  // Should be modified
    
    // Test const reference parameters
    cout << "\nConst Reference Parameters:" << endl;
    cout << "------------------------" << endl;
    
    vector<int> numbers = {1, 2, 3, 4, 5};
    cout << "Vector contents: ";
    printData(numbers);
    
    double scores[] = {85.5, 92.0, 77.5, 90.0};
    cout << "Average score: " << calculateAverage(scores, 4) << endl;
    
    string name = "Alice";
    int age = 25;
    displayPerson(name, age);
    
    // Test mixed parameter types
    cout << "\nMixed Parameter Types:" << endl;
    cout << "-------------------" << endl;
    
    Student alice{"Alice", {}, 0.0};
    addGrade(alice, 95.0);
    addGrade(alice, 87.5);
    addGrade(alice, 92.0);
    displayStudent(alice);
    
    // Test multiple return values
    cout << "\nMultiple Return Values:" << endl;
    cout << "--------------------" << endl;
    
    vector<int> values = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int min, max;
    getMinMax(values, min, max);
    cout << "Min: " << min << ", Max: " << max << endl;
    
    // Test class with different parameter types
    cout << "\nClass Parameter Types:" << endl;
    cout << "-------------------" << endl;
    
    DataProcessor processor("Test Processor", {1, 2, 3, 4, 5});
    processor.addValue(6);
    processor.displayStats();
    
    cout << "\nProcessor name: " << processor.getName() << endl;
    cout << "Average: " << processor.getAverage() << endl;
    
    return 0;
}
