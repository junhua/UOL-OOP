#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// Student Management System
class Student {
public:
    Student(string id, string name) : id(id), name(name) {}
    
    void addGrade(double grade) {
        grades.push_back(grade);
    }
    
    double getAverage() const {
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
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
    void addStudent(const Student& student) {
        students[student.getId()] = student;
    }
    
    void addGrade(const string& id, double grade) {
        if (students.find(id) != students.end()) {
            students[id].addGrade(grade);
        }
    }
    
    void displayStudent(const string& id) {
        if (students.find(id) != students.end()) {
            const Student& student = students[id];
            cout << "ID: " << student.getId() << endl;
            cout << "Name: " << student.getName() << endl;
            cout << "Grades: ";
            for (double grade : student.getGrades()) {
                cout << grade << " ";
            }
            cout << endl;
            cout << "Average: " << fixed << setprecision(2) 
                 << student.getAverage() << endl;
        }
    }
    
    void displayAllStudents() {
        for (const auto& pair : students) {
            cout << "\nStudent Information:" << endl;
            cout << "----------------" << endl;
            displayStudent(pair.first);
        }
    }

private:
    map<string, Student> students;
};

// Inventory System
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
    void addProduct(const Product& product) {
        inventory[product.getId()] = product;
    }
    
    void updateQuantity(const string& id, int quantity) {
        if (inventory.find(id) != inventory.end()) {
            inventory[id].setQuantity(quantity);
        }
    }
    
    void displayProduct(const string& id) {
        if (inventory.find(id) != inventory.end()) {
            const Product& product = inventory[id];
            cout << "ID: " << product.getId() << endl;
            cout << "Name: " << product.getName() << endl;
            cout << "Price: $" << fixed << setprecision(2) 
                 << product.getPrice() << endl;
            cout << "Quantity: " << product.getQuantity() << endl;
        }
    }
    
    void displayLowStock(int threshold) {
        cout << "Low Stock Products (below " << threshold << "):" << endl;
        for (const auto& pair : inventory) {
            if (pair.second.getQuantity() < threshold) {
                displayProduct(pair.first);
                cout << endl;
            }
        }
    }

private:
    map<string, Product> inventory;
};

// Data Analysis System
class DataAnalyzer {
public:
    void addValue(double value) {
        values.push_back(value);
        uniqueValues.insert(value);
    }
    
    double getAverage() const {
        if (values.empty()) return 0.0;
        double sum = 0;
        for (double value : values) {
            sum += value;
        }
        return sum / values.size();
    }
    
    double getMedian() {
        if (values.empty()) return 0.0;
        
        vector<double> sorted = values;
        sort(sorted.begin(), sorted.end());
        
        size_t size = sorted.size();
        if (size % 2 == 0) {
            return (sorted[size/2 - 1] + sorted[size/2]) / 2;
        } else {
            return sorted[size/2];
        }
    }
    
    void displayStats() {
        cout << "\nData Analysis:" << endl;
        cout << "-------------" << endl;
        cout << "Number of values: " << values.size() << endl;
        cout << "Unique values: " << uniqueValues.size() << endl;
        cout << "Average: " << fixed << setprecision(2) 
             << getAverage() << endl;
        cout << "Median: " << getMedian() << endl;
        
        if (!values.empty()) {
            auto minmax = minmax_element(values.begin(), values.end());
            cout << "Min: " << *minmax.first << endl;
            cout << "Max: " << *minmax.second << endl;
        }
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
