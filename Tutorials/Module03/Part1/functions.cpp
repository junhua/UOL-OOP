#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Basic greeting function
void greetUser(string name) {
    cout << "Hello, " << name << "!" << endl;
}

// Calculator function with validation
double calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 != 0) return num1 / num2;
            cout << "Error: Division by zero" << endl;
            return 0;
        default:
            cout << "Error: Invalid operation" << endl;
            return 0;
    }
}

bool isValidOperation(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

// Array processing with error handling
bool processArray(const int arr[], int size, double& average, int& max) {
    if (size <= 0) {
        cout << "Error: Invalid array size" << endl;
        return false;
    }
    
    int sum = 0;
    max = arr[0];
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    average = static_cast<double>(sum) / size;
    return true;
}

void displayResults(bool success, double average, int max) {
    if (success) {
        cout << "Average: " << average << endl;
        cout << "Maximum: " << max << endl;
    }
}

// Menu-driven number processor
void displayMenu() {
    cout << "\n=== Number Processor ===" << endl;
    cout << "1. Enter numbers" << endl;
    cout << "2. Display statistics" << endl;
    cout << "3. Clear data" << endl;
    cout << "4. Exit" << endl;
    cout << "Choice: ";
}

int getMenuChoice() {
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid choice. Enter 1-4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

bool processNumbers(vector<int>& numbers) {
    cout << "Enter numbers (0 to finish):" << endl;
    int num;
    
    while (true) {
        if (!(cin >> num)) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (num == 0) break;
        numbers.push_back(num);
    }
    
    return true;
}

void displayStats(const vector<int>& numbers) {
    if (numbers.empty()) {
        cout << "No data available!" << endl;
        return;
    }
    
    int sum = 0, max = numbers[0], min = numbers[0];
    for (int num : numbers) {
        sum += num;
        if (num > max) max = num;
        if (num < min) min = num;
    }
    
    double avg = static_cast<double>(sum) / numbers.size();
    
    cout << "\nStatistics:" << endl;
    cout << "Count: " << numbers.size() << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
}

void processChoice(int choice) {
    static vector<int> numbers;
    
    switch (choice) {
        case 1:
            if (processNumbers(numbers)) {
                cout << "Numbers added successfully!" << endl;
            }
            break;
        case 2:
            displayStats(numbers);
            break;
        case 3:
            numbers.clear();
            cout << "Data cleared!" << endl;
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
    }
    
    if (choice != 4) {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}

int main() {
    cout << "Function Examples" << endl;
    cout << "================\n" << endl;
    
    // Test basic function
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    greetUser(name);
    
    // Test calculator
    double num1, num2;
    char operation;
    
    cout << "\nCalculator" << endl;
    cout << "==========" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    if (isValidOperation(operation)) {
        double result = calculate(num1, num2, operation);
        cout << num1 << " " << operation << " " << num2 
             << " = " << result << endl;
    } else {
        cout << "Invalid operation!" << endl;
    }
    
    // Test array processing
    const int SIZE = 5;
    int numbers[SIZE];
    double average;
    int max;
    
    cout << "\nArray Processing" << endl;
    cout << "===============" << endl;
    cout << "Enter " << SIZE << " numbers:" << endl;
    
    for (int i = 0; i < SIZE; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    if (processArray(numbers, SIZE, average, max)) {
        displayResults(true, average, max);
    }
    
    // Test menu-driven program
    cout << "\nMenu-Driven Program" << endl;
    cout << "==================" << endl;
    
    int choice;
    do {
        displayMenu();
        choice = getMenuChoice();
        processChoice(choice);
    } while (choice != 4);
    
    return 0;
}
