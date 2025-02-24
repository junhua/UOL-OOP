---
layout: default
title: Part 4 - Input and Output
nav_order: 4
parent: Module 1 - Introduction to C++
grand_parent: Tutorials
permalink: /tutorials/module1/part4-io/
---

# Part 4: Input and Output

## Learning Objectives
- Master C++ I/O streams
- Understand input/output operations
- Learn formatting techniques
- Implement file I/O operations
- Practice error handling
- Create user-friendly interfaces
- Handle complex I/O scenarios

## Introduction
Input/Output (I/O) in C++ is like a communication system between your program and the outside world. Think of it as:

1. **Why I/O Matters**:
   - **User Interaction**: Interface with users
   - **Data Persistence**: Save/load data
   - **Error Reporting**: Communicate issues
   - **Debugging**: Monitor program state
   - **Data Processing**: Handle external data

2. **Real-World Applications**:
   - **Configuration Files**: Load settings
   - **Log Files**: Record events
   - **Data Files**: Process data
   - **User Interfaces**: Interactive programs
   - **Network Communication**: Data exchange

3. **Benefits in Development**:
   - **Better User Experience**: Clear interaction
   - **Robust Programs**: Error handling
   - **Data Management**: File operations
   - **Debug Support**: Logging
   - **Clean Code**: Organized I/O

## Implementation Guide

You'll find the starter code in `Tutorials/Module01/Part4/io_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module01/Part4/io.cpp`.

### Console I/O
First, let's explore basic console operations:

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Basic output
    cout << "Welcome to I/O Demo!" << endl;
    
    // Formatted output
    cout << fixed << setprecision(2);
    cout << "Pi: " << 3.14159265359 << endl;
    
    // Width and fill
    cout << setw(10) << setfill('*') << "Hello" << endl;
    
    // Basic input
    string name;
    int age;
    
    cout << "Enter your name: ";
    getline(cin, name);
    
    cout << "Enter your age: ";
    if (cin >> age) {
        cout << name << " is " << age << " years old." << endl;
    } else {
        cout << "Invalid age input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return 0;
}
```

### File I/O
Handle file operations:

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Writing to a file
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File I/O!" << endl;
        outFile << "Numbers: ";
        for (int i = 1; i <= 5; i++) {
            outFile << i << " ";
        }
        outFile << endl;
        outFile.close();
    } else {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }
    
    // Reading from a file
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << "Read: " << line << endl;
        }
        inFile.close();
    } else {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }
    
    return 0;
}
```

### Advanced Formatting
Demonstrate complex formatting:

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Table formatting
    cout << left << setw(15) << "Name"
         << right << setw(10) << "Age"
         << right << setw(10) << "Score" << endl;
    cout << string(35, '-') << endl;
    
    // Data rows
    cout << left << setw(15) << "John Doe"
         << right << setw(10) << 25
         << right << setw(10) << 95.5 << endl;
    
    cout << left << setw(15) << "Jane Smith"
         << right << setw(10) << 22
         << right << setw(10) << 97.8 << endl;
    
    // Number formatting
    double value = 123456.789;
    
    cout << "\nNumber Formatting:" << endl;
    cout << "Default: " << value << endl;
    cout << "Fixed: " << fixed << value << endl;
    cout << "Scientific: " << scientific << value << endl;
    cout << "Precision(2): " << fixed 
         << setprecision(2) << value << endl;
    
    // Boolean formatting
    cout << "\nBoolean values:" << endl;
    cout << "Default: " << true << " " << false << endl;
    cout << boolalpha << "Alpha: " << true << " " 
         << false << endl;
    
    return 0;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module01/Part4/practice_io_starter.cpp`
- Complete solution: `Tutorials/Module01/Part4/practice_io.cpp`

### Exercise 1: Data Logger
Create a logging system:
1. Support operations:
   - Write log entries
   - Read log history
   - Format timestamps
   - Filter entries
   - Search logs
2. Handle errors
3. Format output
4. Validate input
5. Manage files

Requirements:
1. File operations
2. Time formatting
3. Error handling
4. Search functionality
5. Clean output

### Exercise 2: Configuration Manager
Build a config file manager:
1. Handle operations:
   - Read settings
   - Write settings
   - Update values
   - Validate format
   - Parse data
2. Check syntax
3. Handle errors
4. Format output
5. Validate input

Requirements:
1. File I/O
2. Format checking
3. Error handling
4. Data validation
5. Clean interface

### Exercise 3: Report Generator
Create a report system:
1. Generate reports:
   - Tables
   - Statistics
   - Charts
   - Summaries
2. Format output
3. Handle data
4. Save reports
5. Load templates

Requirements:
1. Table formatting
2. Data processing
3. File operations
4. Error handling
5. Clean layout

## Summary

### Key Concepts
1. **Console I/O**
   ```cpp
   // Basic input/output
   cout << "Enter value: ";
   cin >> value;
   
   // Formatted output
   cout << fixed << setprecision(2)
        << setw(10) << value << endl;
   
   // String input
   string line;
   getline(cin, line);
   ```

2. **File I/O**
   ```cpp
   // Write to file
   ofstream outFile("data.txt");
   if (outFile) {
       outFile << "Data" << endl;
   }
   
   // Read from file
   ifstream inFile("data.txt");
   if (inFile) {
       string line;
       getline(inFile, line);
   }
   ```

3. **Stream Formatting**
   ```cpp
   // Format flags
   cout << boolalpha      // true/false
        << showpoint      // show decimal point
        << fixed         // fixed precision
        << scientific;   // scientific notation
   
   // Manipulators
   cout << setw(10)      // field width
        << setfill('*')  // fill character
        << left;         // alignment
   ```

### Common Pitfalls
1. **Unchecked Input**
   ```cpp
   // Bad: No validation
   int number;
   cin >> number;  // What if input fails?

   // Good: Validate input
   while (!(cin >> number)) {
       cout << "Invalid input. Try again: ";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   ```

2. **Unclosed Files**
   ```cpp
   // Bad: File might not close
   ofstream file("data.txt");
   file << "Data";  // What if program crashes?

   // Good: RAII approach
   {
       ofstream file("data.txt");
       if (file) file << "Data";
   }  // File closes automatically
   ```

3. **Format State**
   ```cpp
   // Bad: Format state persists
   cout << fixed << setprecision(2);

   // Good: Scope format changes
   {
       auto flags = cout.flags();
       cout << fixed << setprecision(2);
       cout.flags(flags);  // Restore
   }
   ```

### Best Practices
1. **Input Validation**
   ```cpp
   template<typename T>
   T getValidInput(const string& prompt) {
       T value;
       while (true) {
           cout << prompt;
           if (cin >> value) return value;
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           cout << "Invalid input!" << endl;
       }
   }
   ```

2. **File Operations**
   ```cpp
   class FileHandler {
       ofstream file;
   public:
       FileHandler(const string& name) : file(name) {
           if (!file) throw runtime_error("Cannot open file");
       }
       ~FileHandler() {
           if (file) file.close();
       }
   };
   ```

3. **Format Control**
   ```cpp
   class FormatGuard {
       ios_base::fmtflags flags;
       ostream& stream;
   public:
       FormatGuard(ostream& s) : stream(s) {
           flags = stream.flags();
       }
       ~FormatGuard() {
           stream.flags(flags);
       }
   };
   ```

4. **Error Handling**
   ```cpp
   void processFile(const string& filename) {
       ifstream file(filename);
       if (!file) {
           throw runtime_error("Cannot open file");
       }
       // Process with RAII
   }
   ```

5. **Stream State**
   ```cpp
   void writeData(ostream& out, const string& data) {
       if (!out || !(out << data)) {
           throw runtime_error("Write failed");
       }
   }
   ```

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Study formatting options
5. Practice file operations
6. Implement error handling
7. Move on to [Part 5: Operators]({{ site.baseurl }}/tutorials/module1/part5-operators)
