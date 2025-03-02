#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

// Basic overloading with different types
void print(int value) {
    cout << "Integer: " << value << endl;
}

void print(double value) {
    cout << fixed << setprecision(2);
    cout << "Double: " << value << endl;
}

void print(const string& text) {
    cout << "String: " << text << endl;
}

void print(const vector<int>& values) {
    cout << "Vector: ";
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;
}

// Overloading with different number of parameters
void display(int x) {
    cout << x << endl;
}

void display(int x, int y) {
    cout << x << ", " << y << endl;
}

void display(int x, int y, int z) {
    cout << x << ", " << y << ", " << z << endl;
}

// Overloading with different parameter types
string format(int value) {
    return "Number: " + to_string(value);
}

string format(double value, int precision) {
    ostringstream ss;
    ss << fixed << setprecision(precision) << value;
    return "Float: " + ss.str();
}

string format(const string& text, bool uppercase) {
    string result = text;
    if (uppercase) {
        transform(result.begin(), result.end(), 
                 result.begin(), ::toupper);
    }
    return "Text: " + result;
}

// Overloading with const and non-const versions
class DataContainer {
public:
    DataContainer(const vector<int>& data) : values(data) {}
    
    // Non-const version - can modify data
    vector<int>& getData() {
        cout << "Called non-const getData()" << endl;
        return values;
    }
    
    // Const version - read-only access
    const vector<int>& getData() const {
        cout << "Called const getData()" << endl;
        return values;
    }
    
private:
    vector<int> values;
};

// Overloaded operators
class Point {
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Overload + operator
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    // Overload - operator
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    
    // Overload * operator for scaling
    Point operator*(int scale) const {
        return Point(x * scale, y * scale);
    }
    
    // Overload == operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    // Friend function to overload << operator
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
private:
    int x, y;
};

// Template function overloading
template<typename T>
T add(T a, T b) {
    return a + b;
}

template<typename T>
T add(T a, T b, T c) {
    return a + b + c;
}

template<typename T>
T add(const vector<T>& values) {
    T sum = T();
    for (const T& value : values) {
        sum += value;
    }
    return sum;
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
    
    data.getData().push_back(6);      // Calls non-const version
    cout << "First value: " << constData.getData()[0] << endl;  // Calls const version
    
    // Test operator overloading
    cout << "\nOperator Overloading:" << endl;
    cout << "-------------------" << endl;
    Point p1(1, 2), p2(3, 4);
    
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 - p1 = " << p2 - p1 << endl;
    cout << "p1 * 3 = " << p1 * 3 << endl;
    cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << endl;
    
    // Test template overloading
    cout << "\nTemplate Overloading:" << endl;
    cout << "-------------------" << endl;
    cout << "add(1, 2) = " << add(1, 2) << endl;
    cout << "add(1.5, 2.7) = " << add(1.5, 2.7) << endl;
    cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;
    cout << "add(vector) = " << add(vector<int>{1, 2, 3, 4, 5}) << endl;
    
    return 0;
}
