#include <iostream>
#include <string>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

// Exercise 1: Calculator Functions
double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : throw runtime_error("Division by zero");
        default: throw runtime_error("Invalid operator");
    }
}

int calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : throw runtime_error("Division by zero");
        case '%': return b != 0 ? a % b : throw runtime_error("Division by zero");
        default: throw runtime_error("Invalid operator");
    }
}

complex<double> calculate(complex<double> a, complex<double> b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != complex<double>(0,0) ? a / b : 
                 throw runtime_error("Division by zero");
        default: throw runtime_error("Invalid operator");
    }
}

// Exercise 2: Shape Area Calculator
const double PI = 3.14159265359;

double calculateArea(double radius) {  // Circle
    if (radius < 0) throw runtime_error("Negative radius");
    return PI * radius * radius;
}

double calculateArea(double length, double width) {  // Rectangle
    if (length < 0 || width < 0) throw runtime_error("Negative dimensions");
    return length * width;
}

double calculateArea(double base, double height, char shape) {  // Triangle/Parallelogram
    if (base < 0 || height < 0) throw runtime_error("Negative dimensions");
    switch (toupper(shape)) {
        case 'T': return 0.5 * base * height;  // Triangle
        case 'P': return base * height;        // Parallelogram
        default: throw runtime_error("Invalid shape");
    }
}

// Exercise 3: String Formatter
string format(const string& text) {
    if (text.empty()) return "";
    string result = text;
    // Remove leading/trailing whitespace
    result = result.substr(result.find_first_not_of(" \t"));
    result = result.substr(0, result.find_last_not_of(" \t") + 1);
    return result;
}

string format(const string& text, bool uppercase) {
    string result = format(text);  // Use basic formatting first
    if (uppercase) {
        transform(result.begin(), result.end(), result.begin(), ::toupper);
    }
    return result;
}

string format(const string& text, int width, char fill) {
    string result = format(text);  // Use basic formatting first
    if (result.length() < width) {
        result = string(width - result.length(), fill) + result;
    }
    return result;
}

string format(const string& text, const string& prefix, const string& suffix) {
    string result = format(text);  // Use basic formatting first
    return prefix + result + suffix;
}

int main() {
    try {
        // Test Calculator Functions
        cout << "=== Calculator Functions ===" << endl;
        cout << "Integer: 15 / 3 = " << calculate(15, 3, '/') << endl;
        cout << "Double: 3.14 * 2.0 = " << calculate(3.14, 2.0, '*') << endl;
        complex<double> c1(1, 2), c2(3, 4);
        cout << "Complex: (1+2i) + (3+4i) = " << calculate(c1, c2, '+') << endl;

        // Test Shape Area Calculator
        cout << "\n=== Shape Area Calculator ===" << endl;
        cout << "Circle (r=5): " << fixed << setprecision(2) 
             << calculateArea(5.0) << endl;
        cout << "Rectangle (4x6): " << calculateArea(4.0, 6.0) << endl;
        cout << "Triangle (b=3,h=4): " << calculateArea(3.0, 4.0, 'T') << endl;
        cout << "Parallelogram (b=5,h=3): " << calculateArea(5.0, 3.0, 'P') << endl;

        // Test String Formatter
        cout << "\n=== String Formatter ===" << endl;
        string text = "  Hello, World!  ";
        cout << "Basic: \"" << format(text) << "\"" << endl;
        cout << "Uppercase: \"" << format(text, true) << "\"" << endl;
        cout << "Width(20,'*'): \"" << format(text, 20, '*') << "\"" << endl;
        cout << "With affixes: \"" << format(text, "[", "]") << "\"" << endl;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
