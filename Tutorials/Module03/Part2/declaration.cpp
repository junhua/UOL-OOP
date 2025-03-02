#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Forward declarations
void processData(int value);
void processB(int x);  // Forward declaration needed for mutual recursion
double calculateArea(double radius);
string formatText(const string& text);
void displayArray(const int arr[], int size);
int findMax(const vector<int>& numbers);

// Function definitions with documentation
/**
 * Process a numeric value and display the result
 * @param value The number to process
 */
void processData(int value) {
    cout << "Processing: " << value << endl;
}

/**
 * Calculate the area of a circle
 * @param radius The radius of the circle
 * @return The calculated area
 */
double calculateArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

/**
 * Format text by adding decorative elements
 * @param text The text to format
 * @return The formatted text
 */
string formatText(const string& text) {
    return "=== " + text + " ===";
}

/**
 * Display array elements with proper formatting
 * @param arr The array to display
 * @param size The size of the array
 */
void displayArray(const int arr[], int size) {
    cout << "Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Find the maximum value in a vector
 * @param numbers Vector of integers
 * @return The maximum value
 */
int findMax(const vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    
    int max = numbers[0];
    for (int num : numbers) {
        if (num > max) max = num;
    }
    return max;
}

// Mutual recursion example
void processA(int x) {
    if (x > 0) {
        cout << "A" << x << " ";
        processB(x - 1);
    }
}

void processB(int x) {
    if (x > 0) {
        cout << "B" << x << " ";
        processA(x - 1);
    }
}

// Class with member function declarations
class Calculator {
public:
    Calculator();
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    void displayResult(double result);
private:
    int operationCount;
};

// Class member function definitions
Calculator::Calculator() : operationCount(0) {}

double Calculator::add(double a, double b) {
    operationCount++;
    return a + b;
}

double Calculator::subtract(double a, double b) {
    operationCount++;
    return a - b;
}

double Calculator::multiply(double a, double b) {
    operationCount++;
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b != 0) {
        operationCount++;
        return a / b;
    }
    cout << "Error: Division by zero" << endl;
    return 0;
}

void Calculator::displayResult(double result) {
    cout << "Result: " << result << endl;
    cout << "Operations performed: " << operationCount << endl;
}

int main() {
    cout << "Function Declaration Demo" << endl;
    cout << "======================\n" << endl;
    
    // Test basic functions
    processData(42);
    cout << "Circle area: " << calculateArea(5.0) << endl;
    cout << formatText("Hello") << endl;
    
    // Test array functions
    int numbers[] = {1, 2, 3, 4, 5};
    displayArray(numbers, 5);
    
    // Test vector functions
    vector<int> vec = {5, 2, 8, 1, 9};
    cout << "Maximum value: " << findMax(vec) << endl;
    
    // Test mutual recursion
    cout << "\nMutual Recursion Test:" << endl;
    processA(3);
    cout << endl;
    
    // Test calculator class
    Calculator calc;
    double result;
    
    result = calc.add(10, 5);
    calc.displayResult(result);
    
    result = calc.multiply(result, 2);
    calc.displayResult(result);
    
    result = calc.divide(result, 5);
    calc.displayResult(result);
    
    return 0;
}
