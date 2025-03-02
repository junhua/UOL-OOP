#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

// TODO: Implement basic overloading with different types
// - Print integer values
// - Print double values
// - Print string values
// - Print vector contents
void print(int value) {
    // Your code here
}

void print(double value) {
    // Your code here
}

void print(const string& text) {
    // Your code here
}

void print(const vector<int>& values) {
    // Your code here
}

// TODO: Implement overloading with different number of parameters
// - Display single value
// - Display two values
// - Display three values
void display(int x) {
    // Your code here
}

void display(int x, int y) {
    // Your code here
}

void display(int x, int y, int z) {
    // Your code here
}

// TODO: Implement overloading with different parameter types
// - Format integer values
// - Format floating point values with precision
// - Format text with case conversion
string format(int value) {
    // Your code here
    return "";
}

string format(double value, int precision) {
    // Your code here
    return "";
}

string format(const string& text, bool uppercase) {
    // Your code here
    return "";
}

// TODO: Implement overloading with const and non-const versions
class DataContainer {
public:
    DataContainer(const vector<int>& data) : values(data) {}
    
    // TODO: Add non-const getData() that allows modification
    
    // TODO: Add const getData() that provides read-only access
    
private:
    vector<int> values;
};

// TODO: Implement operator overloading
class Point {
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // TODO: Overload + operator
    
    // TODO: Overload - operator
    
    // TODO: Overload * operator for scaling
    
    // TODO: Overload == operator
    
    // TODO: Overload << operator as friend function
    
private:
    int x, y;
};

// TODO: Implement template function overloading
// - Add two values
// - Add three values
// - Add all values in a vector
template<typename T>
T add(T a, T b) {
    // Your code here
    return T();
}

template<typename T>
T add(T a, T b, T c) {
    // Your code here
    return T();
}

template<typename T>
T add(const vector<T>& values) {
    // Your code here
    return T();
}

int main() {
    cout << "Function Overloading Demo" << endl;
    cout << "======================\n" << endl;
    
    // Test basic overloading
    cout << "Basic Overloading:" << endl;
    cout << "-----------------" << endl;
    print(42);
    print(3.14159);
    print("Hello, World!");
    print(vector<int>{1, 2, 3, 4, 5});
    
    // Test parameter count overloading
    cout << "\nParameter Count Overloading:" << endl;
    cout << "--------------------------" << endl;
    display(1);
    display(1, 2);
    display(1, 2, 3);
    
    // Test parameter type overloading
    cout << "\nParameter Type Overloading:" << endl;
    cout << "-------------------------" << endl;
    cout << format(42) << endl;
    cout << format(3.14159, 2) << endl;
    cout << format("hello", true) << endl;
    
    // Test const overloading
    cout << "\nConst Overloading:" << endl;
    cout << "-----------------" << endl;
    DataContainer data({1, 2, 3, 4, 5});
    const DataContainer constData({6, 7, 8, 9, 10});
    
    // TODO: Test getData() with both const and non-const objects
    
    // Test operator overloading
    cout << "\nOperator Overloading:" << endl;
    cout << "-------------------" << endl;
    Point p1(1, 2), p2(3, 4);
    
    // TODO: Test overloaded operators
    
    // Test template overloading
    cout << "\nTemplate Overloading:" << endl;
    cout << "-------------------" << endl;
    cout << "add(1, 2) = " << add(1, 2) << endl;
    cout << "add(1.5, 2.7) = " << add(1.5, 2.7) << endl;
    cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;
    cout << "add(vector) = " << add(vector<int>{1, 2, 3, 4, 5}) << endl;
    
    return 0;
}
