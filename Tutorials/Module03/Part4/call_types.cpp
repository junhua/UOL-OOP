#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===== Step 1: Call by Value Examples =====
// Function declarations
void modifyValue(int num);
void processArray(int arr[], int size);  // Arrays are special case
void modifyString(string text);

// ===== Step 2: Call by Reference Examples =====
// Function declarations
void modifyReference(int& num);
void getMinMax(const vector<int>& numbers, int& min, int& max);
void swapValues(int& a, int& b);

// ===== Step 3: Const Reference Examples =====
// Function declarations
double calculateAverage(const vector<int>& numbers);
void printDetails(const string& name, const int& age);
bool searchValue(const int arr[], int size, int target);

int main() {
    // Test Step 1: Call by Value
    cout << "===== Testing Call by Value =====" << endl;
    int number = 5;
    cout << "Before modifyValue: " << number << endl;
    modifyValue(number);
    cout << "After modifyValue: " << number << endl;
    
    int array[] = {1, 2, 3, 4, 5};
    cout << "\nBefore processArray: ";
    for (int i = 0; i < 5; i++) cout << array[i] << " ";
    cout << endl;
    processArray(array, 5);
    cout << "After processArray: ";
    for (int i = 0; i < 5; i++) cout << array[i] << " ";
    cout << endl;
    
    string text = "Hello";
    cout << "\nBefore modifyString: " << text << endl;
    modifyString(text);
    cout << "After modifyString: " << text << endl;
    cout << endl;
    
    // Test Step 2: Call by Reference
    cout << "===== Testing Call by Reference =====" << endl;
    number = 10;
    cout << "Before modifyReference: " << number << endl;
    modifyReference(number);
    cout << "After modifyReference: " << number << endl;
    
    vector<int> numbers = {3, 7, 1, 9, 4, 6};
    int min, max;
    getMinMax(numbers, min, max);
    cout << "\nMin: " << min << ", Max: " << max << endl;
    
    int x = 5, y = 10;
    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;
    cout << endl;
    
    // Test Step 3: Const Reference
    cout << "===== Testing Const Reference =====" << endl;
    double avg = calculateAverage(numbers);
    cout << "Average: " << avg << endl;
    
    printDetails("Alice", 25);
    
    int searchArray[] = {2, 4, 6, 8, 10};
    int target = 6;
    bool found = searchValue(searchArray, 5, target);
    cout << "\nValue " << target << " was " 
         << (found ? "found" : "not found") << endl;
    
    return 0;
}

// ===== Step 1: Call by Value Implementations =====
void modifyValue(int num) {
    num *= 2;  // This change won't affect the original value
    cout << "Inside modifyValue: " << num << endl;
}

void processArray(int arr[], int size) {
    // Arrays are passed by reference by default
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

void modifyString(string text) {
    text += " World";  // This change won't affect the original string
    cout << "Inside modifyString: " << text << endl;
}

// ===== Step 2: Call by Reference Implementations =====
void modifyReference(int& num) {
    num *= 2;  // This change will affect the original value
    cout << "Inside modifyReference: " << num << endl;
}

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

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// ===== Step 3: Const Reference Implementations =====
double calculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) return 0.0;
    
    double sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

void printDetails(const string& name, const int& age) {
    cout << "Name: " << name << ", Age: " << age << endl;
}

bool searchValue(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}
