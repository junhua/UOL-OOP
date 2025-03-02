#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// TODO: Implement Student Management System
class Student {
public:
    Student(string id, string name) : id(id), name(name) {}
    
    // TODO: Implement grade management
    void addGrade(double grade) {
        // Your code here
    }
    
    // TODO: Implement average calculation
    double getAverage() const {
        // Your code here
        return 0.0;
    }
    
    string getId() const { return id; }
    string getName() const { return name; }
    const vector<double>& getGrades() const { return grades; }

private:
    string id;
    string name;
    vector<double> grades;
};

class StudentManager {
public:
    // TODO: Implement student management
    void addStudent(const Student& student) {
        // Your code here
    }
    
    void addGrade(const string& id, double grade) {
        // Your code here
    }
    
    void displayStudent(const string& id) {
        // Your code here
    }
    
    void displayAllStudents() {
        // Your code here
    }

private:
    map<string, Student> students;
};

// TODO: Implement Inventory System
class Product {
public:
    Product(string id, string name, double price, int quantity)
        : id(id), name(name), price(price), quantity(quantity) {}
    
    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }

private:
    string id;
    string name;
    double price;
    int quantity;
};

class InventoryManager {
public:
    // TODO: Implement inventory management
    void addProduct(const Product& product) {
        // Your code here
    }
    
    void updateQuantity(const string& id, int quantity) {
        // Your code here
    }
    
    void displayProduct(const string& id) {
        // Your code here
    }
    
    void displayLowStock(int threshold) {
        // Your code here
    }

private:
    map<string, Product> inventory;
};

// TODO: Implement Data Analysis System
class DataAnalyzer {
public:
    // TODO: Implement data collection
    void addValue(double value) {
        // Your code here
    }
    
    // TODO: Implement statistical calculations
    double getAverage() const {
        // Your code here
        return 0.0;
    }
    
    double getMedian() {
        // Your code here
        return 0.0;
    }
    
    void displayStats() {
        // Your code here
    }

private:
    vector<double> values;
    set<double> uniqueValues;
};

void testStudentManager() {
    cout << "Student Management System Test" << endl;
    cout << "===========================" << endl;
    
    StudentManager manager;
    
    // Add students
    manager.addStudent(Student("S001", "Alice Smith"));
    manager.addStudent(Student("S002", "Bob Johnson"));
    
    // Add grades
    manager.addGrade("S001", 95.5);
    manager.addGrade("S001", 87.0);
    manager.addGrade("S001", 92.5);
    
    manager.addGrade("S002", 88.0);
    manager.addGrade("S002", 91.5);
    
    // Display all students
    manager.displayAllStudents();
}

void testInventoryManager() {
    cout << "\nInventory Management System Test" << endl;
    cout << "=============================" << endl;
    
    InventoryManager manager;
    
    // Add products
    manager.addProduct(Product("P001", "Laptop", 999.99, 5));
    manager.addProduct(Product("P002", "Mouse", 29.99, 15));
    manager.addProduct(Product("P003", "Keyboard", 59.99, 3));
    
    // Update quantity
    manager.updateQuantity("P001", 4);
    
    // Display low stock
    manager.displayLowStock(5);
}

void testDataAnalyzer() {
    cout << "\nData Analysis System Test" << endl;
    cout << "======================" << endl;
    
    DataAnalyzer analyzer;
    
    // Add values
    vector<double> testData = {
        23.5, 27.0, 23.5, 25.5, 30.0, 
        28.5, 23.5, 25.0, 28.0, 27.5
    };
    
    for (double value : testData) {
        analyzer.addValue(value);
    }
    
    // Display statistics
    analyzer.displayStats();
}

int main() {
    cout << "Collections Practice Demo" << endl;
    cout << "=====================\n" << endl;
    
    testStudentManager();
    testInventoryManager();
    testDataAnalyzer();
    
    return 0;
}
