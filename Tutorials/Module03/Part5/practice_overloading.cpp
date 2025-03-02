#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

// Calculator with operator overloading
class Calculator {
public:
    // Constructor
    Calculator() : result(0), memory(0) {}
    
    // Basic arithmetic operators
    Calculator& operator+(double value) {
        result += value;
        return *this;
    }
    
    Calculator& operator-(double value) {
        result -= value;
        return *this;
    }
    
    Calculator& operator*(double value) {
        result *= value;
        return *this;
    }
    
    Calculator& operator/(double value) {
        if (value != 0) {
            result /= value;
        } else {
            cout << "Error: Division by zero" << endl;
        }
        return *this;
    }
    
    // Memory operations
    void memoryStore() { memory = result; }
    void memoryRecall() { result = memory; }
    void memoryClear() { memory = 0; }
    
    // Get current result
    double getResult() const { return result; }
    
    // Clear result
    void clear() { result = 0; }
    
    // Friend function for output
    friend ostream& operator<<(ostream& os, const Calculator& calc) {
        os << "Result: " << calc.result;
        return os;
    }

private:
    double result;
    double memory;
};

// String formatter with function overloading
class StringFormatter {
public:
    // Format with default settings
    string format(const string& text) {
        return text;
    }
    
    // Format with case conversion
    string format(const string& text, bool uppercase) {
        string result = text;
        if (uppercase) {
            transform(result.begin(), result.end(), 
                     result.begin(), ::toupper);
        } else {
            transform(result.begin(), result.end(), 
                     result.begin(), ::tolower);
        }
        return result;
    }
    
    // Format with padding
    string format(const string& text, size_t width, char fill) {
        ostringstream ss;
        ss << setw(width) << setfill(fill) << text;
        return ss.str();
    }
    
    // Format with prefix and suffix
    string format(const string& text, 
                 const string& prefix, 
                 const string& suffix) {
        return prefix + text + suffix;
    }
};

// Shape hierarchy with method overloading
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string toString() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return M_PI * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
    
    string toString() const override {
        ostringstream ss;
        ss << "Circle(radius=" << radius << ")";
        return ss.str();
    }
    
private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    double perimeter() const override {
        return 2 * (width + height);
    }
    
    string toString() const override {
        ostringstream ss;
        ss << "Rectangle(width=" << width 
           << ", height=" << height << ")";
        return ss.str();
    }
    
private:
    double width, height;
};

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c) 
        : side1(a), side2(b), side3(c) {}
    
    double area() const override {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    double perimeter() const override {
        return side1 + side2 + side3;
    }
    
    string toString() const override {
        ostringstream ss;
        ss << "Triangle(sides=" << side1 << "," 
           << side2 << "," << side3 << ")";
        return ss.str();
    }
    
private:
    double side1, side2, side3;
};

void testCalculator() {
    cout << "Calculator Test" << endl;
    cout << "==============" << endl;
    
    Calculator calc;
    
    // Test basic operations
    calc + 10;
    cout << calc << endl;
    
    calc * 2;
    cout << calc << endl;
    
    calc - 5;
    cout << calc << endl;
    
    calc / 3;
    cout << calc << endl;
    
    // Test memory operations
    calc.memoryStore();
    calc.clear();
    cout << "After clear: " << calc << endl;
    
    calc.memoryRecall();
    cout << "After recall: " << calc << endl;
}

void testStringFormatter() {
    cout << "\nString Formatter Test" << endl;
    cout << "===================" << endl;
    
    StringFormatter formatter;
    string text = "Hello World";
    
    cout << "Default: " << formatter.format(text) << endl;
    cout << "Uppercase: " << formatter.format(text, true) << endl;
    cout << "Padded: " << formatter.format(text, 20, '*') << endl;
    cout << "With affixes: " 
         << formatter.format(text, "<<", ">>") << endl;
}

void testShapes() {
    cout << "\nShape Test" << endl;
    cout << "==========" << endl;
    
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4, 5));
    
    for (const Shape* shape : shapes) {
        cout << shape->toString() << endl;
        cout << "Area: " << fixed << setprecision(2) 
             << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << endl;
        cout << endl;
    }
    
    // Cleanup
    for (Shape* shape : shapes) {
        delete shape;
    }
}

int main() {
    cout << "Practice Overloading Demo" << endl;
    cout << "======================\n" << endl;
    
    testCalculator();
    testStringFormatter();
    testShapes();
    
    return 0;
}
