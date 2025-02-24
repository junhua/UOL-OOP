---
layout: default
title: Part 5 - Simple Program Examples
nav_order: 5
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part5-examples/
---

# Part 5: Simple Program Examples

## Learning Objectives
- Combine control flow concepts into complete programs
- Master input validation techniques
- Implement robust error handling
- Create user-friendly interfaces
- Practice code organization
- Develop maintainable solutions
- Handle complex program flow

## Introduction
This section demonstrates how to effectively combine various control flow concepts into complete, practical programs. Think of it like building a house:

1. **Why Complete Examples Matter**:
   - **Integration**: Combine multiple concepts
   - **Real-World Usage**: Practical applications
   - **Problem Solving**: Complete solutions
   - **Best Practices**: Professional patterns
   - **Code Organization**: Structure large programs

2. **Real-World Applications**:
   - **Game Development**: Interactive games
   - **Data Processing**: File handlers
   - **User Interfaces**: Menu systems
   - **Business Logic**: Transaction processing
   - **Utility Tools**: Helper applications

3. **Benefits in Development**:
   - **Better Understanding**: See concepts in context
   - **Pattern Recognition**: Learn common patterns
   - **Problem Solving**: Practice complete solutions
   - **Code Organization**: Structure larger programs
   - **Error Handling**: Robust applications

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part5/examples_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part5/examples.cpp`.

### Example 1: Number Guessing Game
A complete game implementation:

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Game configuration
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 100;
    const int MAX_TRIES = 7;
    
    // Game variables
    int secretNumber = MIN_NUMBER + (rand() % (MAX_NUMBER - MIN_NUMBER + 1));
    int tries = 0;
    bool won = false;
    
    // Game introduction
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between " << MIN_NUMBER 
         << " and " << MAX_NUMBER << endl;
    cout << "You have " << MAX_TRIES << " tries to guess it." << endl;
    
    // Main game loop
    while (tries < MAX_TRIES && !won) {
        int guess;
        cout << "\nTry " << (tries + 1) << "/" << MAX_TRIES << endl;
        cout << "Enter your guess: ";
        
        // Input validation
        if (!(cin >> guess)) {
            cout << "Please enter a valid number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        // Range validation
        if (guess < MIN_NUMBER || guess > MAX_NUMBER) {
            cout << "Please guess between " << MIN_NUMBER 
                 << " and " << MAX_NUMBER << endl;
            continue;
        }
        
        tries++;
        
        // Check guess
        if (guess == secretNumber) {
            won = true;
        } else {
            cout << "Too " << (guess < secretNumber ? "low" : "high") << "!" << endl;
        }
    }
    
    // Game result
    if (won) {
        cout << "\nCongratulations! You won in " << tries 
             << " tries!" << endl;
    } else {
        cout << "\nGame Over! The number was " << secretNumber << endl;
    }
    
    return 0;
}
```

### Example 2: Student Grade Manager
A grade management system:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Student record structure
struct Student {
    string name;
    vector<double> grades;
    double average;
};

// Function declarations
void displayMenu();
Student addStudent();
void addGrade(Student& student);
void displayStudent(const Student& student);
void displayAllStudents(const vector<Student>& students);
double calculateAverage(const vector<double>& grades);

int main() {
    vector<Student> students;
    int choice;
    bool running = true;
    
    cout << "Student Grade Manager" << endl;
    
    while (running) {
        displayMenu();
        
        // Input validation
        if (!(cin >> choice)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Process choice
        switch (choice) {
            case 1: {  // Add student
                students.push_back(addStudent());
                cout << "Student added successfully!" << endl;
                break;
            }
            case 2: {  // Add grade
                if (students.empty()) {
                    cout << "No students registered!" << endl;
                    break;
                }
                
                cout << "Enter student number (1-" << students.size() << "): ";
                int index;
                cin >> index;
                
                if (index < 1 || index > static_cast<int>(students.size())) {
                    cout << "Invalid student number!" << endl;
                    break;
                }
                
                addGrade(students[index-1]);
                break;
            }
            case 3: {  // Display all students
                if (students.empty()) {
                    cout << "No students registered!" << endl;
                } else {
                    displayAllStudents(students);
                }
                break;
            }
            case 4: {  // Exit
                running = false;
                cout << "Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }
    
    return 0;
}

void displayMenu() {
    cout << "\nMenu Options:\n"
         << "1. Add Student\n"
         << "2. Add Grade\n"
         << "3. Display All Students\n"
         << "4. Exit\n"
         << "Choice: ";
}

Student addStudent() {
    Student student;
    cout << "Enter student name: ";
    getline(cin, student.name);
    student.average = 0.0;
    return student;
}

void addGrade(Student& student) {
    double grade;
    cout << "Enter grade (0-100): ";
    
    if (cin >> grade && grade >= 0 && grade <= 100) {
        student.grades.push_back(grade);
        student.average = calculateAverage(student.grades);
        cout << "Grade added successfully!" << endl;
    } else {
        cout << "Invalid grade!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void displayStudent(const Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "Grades: ";
    
    if (student.grades.empty()) {
        cout << "No grades yet";
    } else {
        for (double grade : student.grades) {
            cout << grade << " ";
        }
        cout << "\nAverage: " << fixed << setprecision(2) 
             << student.average;
    }
    cout << endl;
}

void displayAllStudents(const vector<Student>& students) {
    cout << "\nStudent Records:\n";
    cout << string(30, '-') << endl;
    
    for (size_t i = 0; i < students.size(); i++) {
        cout << "Student " << (i + 1) << ":\n";
        displayStudent(students[i]);
        cout << string(30, '-') << endl;
    }
}

double calculateAverage(const vector<double>& grades) {
    if (grades.empty()) return 0.0;
    
    double sum = 0.0;
    for (double grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}
```

### Example 3: File Statistics
A text file analyzer:

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    // Statistics variables
    int chars = 0;
    int words = 0;
    int lines = 0;
    int digits = 0;
    int spaces = 0;
    bool inWord = false;
    
    cout << "Enter text (Ctrl+D/Z to end):\n";
    
    // Process input character by character
    char c;
    while (cin.get(c)) {
        chars++;
        
        if (isdigit(c)) {
            digits++;
        }
        
        if (isspace(c)) {
            spaces++;
            if (c == '\n') {
                lines++;
            }
            if (inWord) {
                words++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }
    
    // Count last word if text doesn't end with space
    if (inWord) {
        words++;
    }
    
    // Count last line if text doesn't end with newline
    if (chars > 0 && !isspace(c)) {
        lines++;
    }
    
    // Display statistics
    cout << "\nFile Statistics:\n";
    cout << string(20, '-') << endl;
    cout << "Characters: " << chars << endl;
    cout << "Words: " << words << endl;
    cout << "Lines: " << lines << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    
    return 0;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module02/Part5/practice_examples_starter.cpp`
- Complete solution: `Tutorials/Module02/Part5/practice_examples.cpp`

### Exercise 1: Quiz Game
Create an interactive quiz game:
1. Store questions and answers
2. Track score
3. Provide feedback
4. Show progress
5. Display final results

Requirements:
1. Multiple question types
2. Score tracking
3. Input validation
4. Progress display
5. Final statistics

### Exercise 2: Bank Account
Implement a bank account system:
1. Support operations:
   - Deposit
   - Withdraw
   - Check balance
   - View history
2. Validate transactions
3. Track balance
4. Store history
5. Generate statements

Requirements:
1. Transaction validation
2. Balance management
3. History tracking
4. Error handling
5. Clear interface

### Exercise 3: Inventory System
Create an inventory manager:
1. Track items:
   - Add
   - Remove
   - Update
   - Search
2. Validate quantities
3. Generate reports
4. Handle errors
5. Save/load data

Requirements:
1. Data validation
2. Search functionality
3. Report generation
4. Error recovery
5. Data persistence

## Summary

### Key Concepts
1. **Program Structure**
   ```cpp
   int main() {
       // 1. Initialize
       setup();
       
       // 2. Main loop
       while (running) {
           displayMenu();
           processInput();
           updateState();
           displayOutput();
       }
       
       // 3. Cleanup
       cleanup();
   }
   ```

2. **State Management**
   ```cpp
   class GameState {
       bool running = true;
       int score = 0;
       vector<string> history;
       
   public:
       void update() {
           // Process game logic
       }
       
       void reset() {
           // Reset state
       }
   };
   ```

3. **User Interface**
   ```cpp
   void displayMenu() {
       cout << "Options:\n"
            << "1. Start\n"
            << "2. Settings\n"
            << "3. Exit\n";
            
       processChoice(getValidInput());
   }
   ```

### Common Pitfalls
1. **Poor Input Validation**
   ```cpp
   // Bad: No validation
   cin >> value;
   process(value);

   // Good: Complete validation
   while (!(cin >> value) || !isValid(value)) {
       cout << "Invalid input!\n";
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }
   ```

2. **Unclear Interface**
   ```cpp
   // Bad: Confusing
   cout << "1/2/3/4?";

   // Good: Clear menu
   cout << "1. Add\n"
        << "2. Remove\n"
        << "3. Update\n"
        << "4. Exit\n";
   ```

3. **Missing Error Handling**
   ```cpp
   // Bad: No error handling
   process();

   // Good: Handle errors
   try {
       process();
   } catch (const exception& e) {
       handleError(e);
   }
   ```

### Best Practices
1. **Input Validation**
   ```cpp
   bool getValidInput(int& value, int min, int max) {
       while (!(cin >> value) || 
              value < min || 
              value > max) {
           handleError();
       }
       return true;
   }
   ```

2. **State Management**
   ```cpp
   struct GameState {
       bool running = true;
       int score = 0;
       
       void reset() {
           running = true;
           score = 0;
       }
   };
   ```

3. **User Feedback**
   ```cpp
   void showProgress(int current, int total) {
       cout << "Progress: [";
       for (int i = 0; i < 20; i++) {
           cout << (i < current*20/total ? "=" : " ");
       }
       cout << "] " << current*100/total << "%\n";
   }
   ```

4. **Resource Management**
   ```cpp
   class Resource {
   public:
       Resource() { initialize(); }
       ~Resource() { cleanup(); }
       
   private:
       void initialize() { /* Setup */ }
       void cleanup() { /* Cleanup */ }
   };
   ```

5. **Program Flow**
   ```cpp
   void runProgram() {
       initialize();
       
       try {
           while (isRunning()) {
               processInput();
               updateState();
               render();
           }
       } catch (...) {
           handleError();
       }
       
       cleanup();
   }
   ```

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Add error handling
5. Improve user interface
6. Optimize code
7. Move on to [Module 3: Functions]({{ site.baseurl }}/tutorials/module3)
