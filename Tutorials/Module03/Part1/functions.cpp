#include <iostream>
#include <string>
using namespace std;

// Function declarations
void greetUser(string name);
int calculateSum(int a, int b);
bool divideNumbers(double numerator, double denominator, double& result);
double calculateAverage(const int numbers[], int size);
string getValidInput(string prompt);

int main() {
    // Demonstrate basic function
    string name = getValidInput("Enter your name: ");
    greetUser(name);
    
    // Demonstrate function with return value
    int num1 = 5, num2 = 3;
    int sum = calculateSum(num1, num2);
    cout << num1 << " + " << num2 << " = " << sum << endl;
    
    // Demonstrate error handling
    double quotient;
    double numerator = 10.0, denominator = 2.0;
    if (divideNumbers(numerator, denominator, quotient)) {
        cout << numerator << " / " << denominator << " = " << quotient << endl;
    } else {
        cout << "Error: Division by zero!" << endl;
    }
    
    // Test error case
    if (!divideNumbers(5.0, 0.0, quotient)) {
        cout << "Successfully caught division by zero" << endl;
    }
    
    // Demonstrate array processing
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    double average = calculateAverage(numbers, size);
    cout << "Average of array: " << average << endl;
    
    // Test empty array case
    int emptyArray[] = {};
    cout << "Empty array average: " << calculateAverage(emptyArray, 0) << endl;
    
    return 0;
}

// Function definitions
void greetUser(string name) {
    cout << "Hello, " << name << "!" << endl;
}

int calculateSum(int a, int b) {
    return a + b;
}

bool divideNumbers(double numerator, double denominator, double& result) {
    if (denominator == 0) {
        return false;  // Error case
    }
    result = numerator / denominator;
    return true;  // Success case
}

double calculateAverage(const int numbers[], int size) {
    if (size <= 0) {
        return 0.0;  // Handle empty array case
    }
    
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    
    return sum / size;
}

string getValidInput(string prompt) {
    string input;
    do {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        cout << "Invalid input. Please try again." << endl;
    } while (true);
}
