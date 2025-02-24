#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <algorithm>
using namespace std;

// Basic function overloading
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

string add(const string& a, const string& b) {
    return a + b;
}

// Print function overloading
void print(int value) {
    cout << value << endl;
}

void print(int value, int width) {
    cout << setw(width) << value << endl;
}

void print(int value, int width, char fill) {
    cout << setfill(fill) << setw(width) << value << endl;
}

void print(const string& text, bool uppercase = false) {
    string output = text;
    if (uppercase) {
        transform(output.begin(), output.end(), output.begin(), ::toupper);
    }
    cout << output << endl;
}

// Class with overloaded methods
class Point {
public:
    int x, y;
    
    // Constructor overloading
    Point() : x(0), y(0) {}
    Point(int x) : x(x), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    
    // Method overloading
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    
    void move(const Point& other) {
        x += other.x;
        y += other.y;
    }
    
    void move(int distance) {
        x += distance;
        y += distance;
    }
    
    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }
};

// Function overloading with const
void updateValue(int& value) {
    value *= 2;
}

void updateValue(const int& value, int& result) {
    result = value * 2;
}

int main() {
    // Test basic overloading
    cout << "=== Basic Function Overloading ===" << endl;
    cout << "add(5, 3) = " << add(5, 3) << endl;
    cout << "add(3.14, 2.86) = " << add(3.14, 2.86) << endl;
    cout << "add(\"Hello, \", \"World!\") = " << add("Hello, ", "World!") << endl;
    
    cout << "\n=== Print Function Overloading ===" << endl;
    print(42);                  // Basic integer
    print(42, 5);              // Width-formatted integer
    print(42, 5, '0');         // Zero-padded integer
    print("Hello");            // Basic string
    print("Hello", true);      // Uppercase string
    
    cout << "\n=== Point Class Overloading ===" << endl;
    Point p1;                  // Default constructor
    Point p2(5);              // Single parameter
    Point p3(3, 4);           // Two parameters
    
    cout << "p1: " << p1.toString() << endl;
    cout << "p2: " << p2.toString() << endl;
    cout << "p3: " << p3.toString() << endl;
    
    p1.move(2, 3);            // Move by dx, dy
    cout << "p1 after move(2, 3): " << p1.toString() << endl;
    
    p2.move(p3);              // Move by another point
    cout << "p2 after move(p3): " << p2.toString() << endl;
    
    p3.move(5);               // Move by single value
    cout << "p3 after move(5): " << p3.toString() << endl;
    
    cout << "\n=== Const Overloading ===" << endl;
    int x = 10, result;
    updateValue(x);           // Modifies x
    cout << "x after updateValue: " << x << endl;
    
    updateValue(42, result);  // Stores in result
    cout << "result after updateValue(42): " << result << endl;
    
    return 0;
}
