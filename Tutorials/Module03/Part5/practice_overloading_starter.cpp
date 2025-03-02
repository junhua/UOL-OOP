#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

// TODO: Implement Calculator with operator overloading
class Calculator {
public:
    // Constructor
    Calculator() : result(0), memory(0) {}
    
    // TODO: Implement basic arithmetic operators
    Calculator& operator+(double value) {
        // Your code here
        return *this;
    }
    
    Calculator& operator-(double value) {
        // Your code here
        return *this;
    }
    
    Calculator& operator*(double value) {
        // Your code here
        return *this;
    }
    
    Calculator& operator/(double value) {
        // Your code here
        return *this;
    }
    
    // TODO: Implement memory operations
    void memoryStore() {
        // Your code here
    }
    
    void memoryRecall() {
        // Your code here
    }
    
    void memoryClear() {
        // Your code here
    }
    
    double getResult() const { return result; }
    void clear() { result = 0; }
    
    // TODO: Implement output operator
    friend ostream& operator<<(ostream& os, const Calculator& calc) {
        // Your code here
        return os;
    }

private:
    double result;
    double memory;
};

// TODO: Implement String Formatter with function overloading
class StringFormatter {
public:
    // TODO: Implement format with default settings
    string format(const string& text) {
        // Your code here
        return "";
    }
    
    // TODO: Implement format with case conversion
    string format(const string& text, bool uppercase) {
        // Your code here
        return "";
    }
    
    // TODO: Implement format with padding
    string format(const string& text, size_t width, char fill) {
        // Your code here
        return "";
    }
    
    // TODO: Implement format with prefix and suffix
    string format(const string& text, 
                 const string& prefix, 
                 const string& suffix) {
        // Your code here
        return "";
    }
};

// TODO: Implement Shape hierarchy with method overloading
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string toString() const = 0;
    virtual ~Shape() {}
};

// TODO: Implement Circle class
class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}
    
    // TODO: Implement area calculation
    double area() const override {
        // Your code here
        return 0;
    }
    
    // TODO: Implement perimeter calculation
    double perimeter() const override {
        // Your code here
        return 0;
    }
    
    // TODO: Implement string representation
    string toString() const override {
        // Your code here
        return "";
    }
    
private:
    double radius;
};

// TODO: Implement Rectangle class
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    // TODO: Implement area calculation
    double area() const override {
        // Your code here
        return 0;
    }
    
    // TODO: Implement perimeter calculation
    double perimeter() const override {
        // Your code here
        return 0;
    }
    
    // TODO: Implement string representation
    string toString() const override {
        // Your code here
        return "";
    }
    
private:
    double width, height;
};

// TODO: Implement Triangle class
class Triangle : public Shape {
public:
    Triangle(double a, double b, double c) 
        : side1(a), side2(b), side3(c) {}
    
    // TODO: Implement area calculation using Heron's formula
    double area() const override {
        // Your code here
        return 0;
    }
    
    // TODO: Implement perimeter calculation
    double perimeter() const override {
        // Your code here
        return 0;
    }
    
    // TODO: Implement string representation
    string toString() const override {
        // Your code here
        return "";
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
