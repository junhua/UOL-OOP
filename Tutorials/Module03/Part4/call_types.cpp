#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Value parameter examples
void modifyValue(int x) {
    x *= 2;  // Only modifies local copy
    cout << "Inside function: " << x << endl;
}

void processArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original array
    }
}

void handleString(string text) {
    text += " World";  // Only modifies local copy
    cout << "Inside function: " << text << endl;
}

// Reference parameter examples
void modifyByRef(int& x) {
    x *= 2;  // Modifies original value
}

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void updateString(string& text) {
    text += " World";  // Modifies original string
}

// Const reference examples
void printData(const vector<int>& data) {
    for (int value : data) {
        cout << value << " ";
    }
    cout << endl;
}

double calculateAverage(const double values[], int size) {
    if (size == 0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum / size;
}

void displayPerson(const string& name, const int& age) {
    cout << name << " is " << age << " years old" << endl;
}

// Mixed parameter types example
struct Student {
    string name;
    vector<double> grades;
    double average;
};

void addGrade(Student& student, double grade) {
    student.grades.push_back(grade);
    
    // Recalculate average
    double sum = 0;
    for (double g : student.grades) {
        sum += g;
    }
    student.average = sum / student.grades.size();
}

void displayStudent(const Student& student) {
    cout << "Student: " << student.name << endl;
    cout << "Grades: ";
    for (double grade : student.grades) {
        cout << grade << " ";
    }
    cout << "\nAverage: " << fixed << setprecision(2) 
         << student.average << endl;
}

// Multiple return values using references
void getMinMax(const vector<int>& numbers, int& min, int& max) {
    if (numbers.empty()) {
        min = max = 0;
        return;
    }
    
    min = max = numbers[0];
    for (int num : numbers) {
        if (num < min) min = num;
        if (num > max) max = num;
    }
}

// Class with different parameter types
class DataProcessor {
public:
    // Constructor takes values by const reference
    DataProcessor(const string& name, const vector<int>& data)
        : processorName(name), values(data) {}
    
    // Modifies internal state
    void addValue(int value) {
        values.push_back(value);
        processData();
    }
    
    // Returns data by value
    double getAverage() const {
        return average;
    }
    
    // Returns data by const reference
    const string& getName() const {
        return processorName;
    }
    
    // Takes const reference parameter
    void displayStats() const {
        cout << "Processor: " << processorName << endl;
        cout << "Values: ";
        for (int value : values) {
            cout << value << " ";
        }
        cout << "\nAverage: " << average << endl;
    }

private:
    string processorName;
    vector<int> values;
    double average;
    
    void processData() {
        if (values.empty()) {
            average = 0;
            return;
        }
        
        int sum = 0;
        for (int value : values) {
            sum += value;
        }
        average = static_cast<double>(sum) / values.size();
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
    cout << "After: " << number << endl;  // Unchanged
    
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
    cout << "After: " << msg << endl;  // Unchanged
    
    // Test reference parameters
    cout << "\nReference Parameters:" << endl;
    cout << "-------------------" << endl;
    
    int value = 42;
    cout << "Before: " << value << endl;
    modifyByRef(value);
    cout << "After: " << value << endl;  // Modified
    
    int x = 5, y = 10;
    cout << "\nBefore swap: x=" << x << ", y=" << y << endl;
    swapValues(x, y);
    cout << "After swap: x=" << x << ", y=" << y << endl;
    
    string text = "Hello";
    cout << "\nBefore: " << text << endl;
    updateString(text);
    cout << "After: " << text << endl;  // Modified
    
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
