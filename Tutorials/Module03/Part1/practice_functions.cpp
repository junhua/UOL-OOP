#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

// Temperature Converter Functions
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

bool validateTemperature(double temp, double min, double max) {
    return temp >= min && temp <= max;
}

void displayConversion(double value, char unit) {
    cout << fixed << setprecision(2);
    if (unit == 'C' || unit == 'c') {
        double fahrenheit = celsiusToFahrenheit(value);
        cout << value << "°C = " << fahrenheit << "°F" << endl;
    } else if (unit == 'F' || unit == 'f') {
        double celsius = fahrenheitToCelsius(value);
        cout << value << "°F = " << celsius << "°C" << endl;
    }
}

// String Processor Functions
int countWords(const string& text) {
    if (text.empty()) return 0;
    
    int count = 0;
    bool inWord = false;
    
    for (char c : text) {
        if (isspace(c)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    
    return count;
}

string reverseString(const string& text) {
    return string(text.rbegin(), text.rend());
}

bool isPalindrome(const string& text) {
    string processed;
    for (char c : text) {
        if (isalnum(c)) {
            processed += tolower(c);
        }
    }
    
    string reversed = reverseString(processed);
    return processed == reversed;
}

string changeCase(const string& text, char mode) {
    string result = text;
    if (mode == 'u' || mode == 'U') {
        transform(result.begin(), result.end(), result.begin(), ::toupper);
    } else if (mode == 'l' || mode == 'L') {
        transform(result.begin(), result.end(), result.begin(), ::tolower);
    }
    return result;
}

string removeCharacter(const string& text, char target) {
    string result;
    copy_if(text.begin(), text.end(), back_inserter(result),
            [target](char c) { return c != target; });
    return result;
}

// Calculator Functions
double basicOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            cout << "Error: Division by zero" << endl;
            return 0;
        default:
            cout << "Error: Invalid operator" << endl;
            return 0;
    }
}

double power(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;
    }
    
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double squareRoot(double number) {
    if (number < 0) {
        cout << "Error: Cannot calculate square root of negative number" << endl;
        return 0;
    }
    return sqrt(number);
}

bool validateInput(double number) {
    return !isnan(number) && !isinf(number);
}

string getCalculationHistory() {
    static vector<string> history;
    string result = "Calculation History:\n";
    for (const auto& entry : history) {
        result += entry + "\n";
    }
    return result;
}

void testTemperatureConverter() {
    cout << "\nTemperature Converter Test" << endl;
    cout << "========================" << endl;
    
    // Test valid temperatures
    cout << "Converting 0°C: ";
    displayConversion(0, 'C');
    
    cout << "Converting 100°C: ";
    displayConversion(100, 'C');
    
    cout << "Converting 32°F: ";
    displayConversion(32, 'F');
    
    cout << "Converting 212°F: ";
    displayConversion(212, 'F');
    
    // Test validation
    cout << "\nValidation Tests:" << endl;
    cout << "-273.15°C is valid: " 
         << (validateTemperature(-273.15, -273.15, 1000) ? "Yes" : "No") << endl;
    cout << "1000°C is valid: "
         << (validateTemperature(1000, -273.15, 1000) ? "Yes" : "No") << endl;
    cout << "-274°C is valid: "
         << (validateTemperature(-274, -273.15, 1000) ? "Yes" : "No") << endl;
}

void testStringProcessor() {
    cout << "\nString Processor Test" << endl;
    cout << "====================" << endl;
    
    string text = "Hello, World! This is a test.";
    cout << "Original text: " << text << endl;
    
    cout << "Word count: " << countWords(text) << endl;
    cout << "Reversed: " << reverseString(text) << endl;
    
    string palindrome = "A man, a plan, a canal: Panama";
    cout << "\nTesting palindrome: " << palindrome << endl;
    cout << "Is palindrome? " << (isPalindrome(palindrome) ? "Yes" : "No") << endl;
    
    cout << "\nCase conversion:" << endl;
    cout << "Uppercase: " << changeCase(text, 'U') << endl;
    cout << "Lowercase: " << changeCase(text, 'L') << endl;
    
    cout << "\nRemoving spaces: " << endl;
    cout << removeCharacter(text, ' ') << endl;
}

void testCalculator() {
    cout << "\nCalculator Test" << endl;
    cout << "==============" << endl;
    
    // Test basic operations
    cout << "Basic Operations:" << endl;
    cout << "10 + 5 = " << basicOperation(10, 5, '+') << endl;
    cout << "10 - 5 = " << basicOperation(10, 5, '-') << endl;
    cout << "10 * 5 = " << basicOperation(10, 5, '*') << endl;
    cout << "10 / 5 = " << basicOperation(10, 5, '/') << endl;
    
    // Test power function
    cout << "\nPower Function:" << endl;
    cout << "2^3 = " << power(2, 3) << endl;
    cout << "2^-2 = " << power(2, -2) << endl;
    cout << "5^0 = " << power(5, 0) << endl;
    
    // Test square root
    cout << "\nSquare Root:" << endl;
    cout << "√16 = " << squareRoot(16) << endl;
    cout << "√25 = " << squareRoot(25) << endl;
    cout << "√-4 = "; squareRoot(-4);
    
    // Test validation
    cout << "\nValidation:" << endl;
    cout << "Valid number (123): " << validateInput(123) << endl;
    cout << "Invalid number (inf): " << validateInput(INFINITY) << endl;
}

int main() {
    cout << "Practice Functions Demo" << endl;
    cout << "=====================" << endl;
    
    testTemperatureConverter();
    testStringProcessor();
    testCalculator();
    
    return 0;
}
