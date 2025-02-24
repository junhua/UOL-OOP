#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Exercise 1 - Temperature Converter
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0/9.0;
}

bool validateTemperature(double temp, double minTemp, double maxTemp) {
    return temp >= minTemp && temp <= maxTemp;
}

// Exercise 2 - String Processor
int countWords(const string& text) {
    stringstream ss(text);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

string reverseString(const string& text) {
    return string(text.rbegin(), text.rend());
}

bool isPalindrome(const string& text) {
    string processed;
    // Remove non-alphanumeric characters and convert to lowercase
    for (char c : text) {
        if (isalnum(c)) {
            processed += tolower(c);
        }
    }
    return processed == string(processed.rbegin(), processed.rend());
}

string changeCase(const string& text, char mode) {
    string result = text;
    if (mode == 'u') {
        for (char& c : result) {
            c = toupper(c);
        }
    } else if (mode == 'l') {
        for (char& c : result) {
            c = tolower(c);
        }
    }
    return result;
}

string removeCharacter(const string& text, char charToRemove) {
    string result = text;
    result.erase(remove(result.begin(), result.end(), charToRemove), result.end());
    return result;
}

// Exercise 3 - Calculator Functions
vector<string> calculationHistory;

double calculate(double a, double b, char operation) {
    switch (operation) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        default: return 0;
    }
}

bool validateOperation(char operation) {
    return operation == '+' || operation == '-' || 
           operation == '*' || operation == '/';
}

void displayResult(double result, bool isValid) {
    if (isValid) {
        cout << "Result: " << result << endl;
        // Add to history
        ostringstream oss;
        oss << "Result: " << result;
        calculationHistory.push_back(oss.str());
    } else {
        cout << "Error: Invalid operation" << endl;
    }
}

string getCalculationHistory() {
    if (calculationHistory.empty()) {
        return "No calculations performed";
    }
    
    string history = "Calculation History:\n";
    for (const string& calc : calculationHistory) {
        history += calc + "\n";
    }
    return history;
}

int main() {
    // Temperature Converter Examples
    cout << "=== Temperature Converter ===" << endl;
    double celsius = 25.0;
    cout << celsius << "°C = " << celsiusToFahrenheit(celsius) << "°F" << endl;
    
    double fahrenheit = 98.6;
    cout << fahrenheit << "°F = " << fahrenheitToCelsius(fahrenheit) << "°C" << endl;
    
    // Validate temperatures
    double temp = -50.0;
    if (validateTemperature(temp, -273.15, 100.0)) {
        cout << temp << "°C is a valid temperature" << endl;
    } else {
        cout << temp << "°C is not a valid temperature" << endl;
    }
    
    // String Processor Examples
    cout << "\n=== String Processor ===" << endl;
    string text = "Hello World! How are you?";
    cout << "Text: " << text << endl;
    cout << "Word count: " << countWords(text) << endl;
    cout << "Reversed: " << reverseString(text) << endl;
    
    string palindrome = "A man, a plan, a canal: Panama";
    cout << "\"" << palindrome << "\" is " 
         << (isPalindrome(palindrome) ? "" : "not ") 
         << "a palindrome" << endl;
    
    cout << "Uppercase: " << changeCase(text, 'u') << endl;
    cout << "Lowercase: " << changeCase(text, 'l') << endl;
    
    cout << "Remove spaces: " << removeCharacter(text, ' ') << endl;
    
    // Calculator Examples
    cout << "\n=== Calculator ===" << endl;
    double a = 10.0, b = 5.0;
    char operations[] = {'+', '-', '*', '/'};
    
    for (char op : operations) {
        if (validateOperation(op)) {
            double result = calculate(a, b, op);
            cout << a << " " << op << " " << b << " = " << result << endl;
            displayResult(result, true);
        }
    }
    
    // Test invalid operation
    char invalidOp = '%';
    if (!validateOperation(invalidOp)) {
        cout << "Invalid operation: " << invalidOp << endl;
    }
    
    // Display calculation history
    cout << "\n" << getCalculationHistory() << endl;
    
    return 0;
}
