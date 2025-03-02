---
layout: default
title: Part 7 - Function Pointers
nav_order: 7
parent: Module 9 - Pointers and Dynamic Memory
grand_parent: Tutorials
permalink: /tutorials/module9/part7-function-pointers/
---

# Part 7: Function Pointers

## Learning Objectives
- Understand the concept and syntax of function pointers
- Master passing functions as arguments to other functions
- Implement callback mechanisms using function pointers
- Create function pointer arrays for strategy selection
- Apply function pointers to implement event-driven programming
- Compare function pointers with modern C++ alternatives

## Introduction
Function pointers allow you to treat functions as data, enabling powerful programming techniques. Think of them like TV remote buttons that can be reprogrammed:

1. **Why Function Pointers Matter**:
   - **Runtime Function Selection**: Choose behavior at runtime
   - **Callback Mechanisms**: Register functions to be called later
   - **Plugin Architecture**: Extend functionality without modifying code
   - **Algorithm Customization**: Parameterize algorithms with behavior
   - **Event-Driven Programming**: Respond to events with appropriate handlers

2. **Real-World Parallels**:
   - **Remote Controls**: Buttons that trigger different actions
   - **Instruction Manuals**: Steps that reference different procedures
   - **Management Delegation**: Assigning tasks to different team members
   - **Switchboards**: Routing calls to different destinations

3. **Benefits in Development**:
   - **Code Flexibility**: Change behavior without changing structure
   - **Decoupling**: Separate what is done from how it's done
   - **Extensibility**: Add new behaviors without modifying existing code
   - **Reusability**: Create generic algorithms that work with different functions
   - **Simplification**: Avoid complex conditional logic

## Function Pointer Basics

### Function Pointer Syntax

The syntax for declaring a function pointer can be complex:

```cpp
// Function declaration
return_type function_name(parameter_types);

// Function pointer declaration
return_type (*pointer_name)(parameter_types);
```

For example:

```cpp
// Function that takes two ints and returns an int
int add(int a, int b) {
    return a + b;
}

// Function pointer declaration
int (*operation)(int, int);

// Assign function address to pointer
operation = add;

// Call function through pointer
int result = operation(5, 3);  // result = 8
```

### Alternative Syntax with typedef

You can use `typedef` to simplify function pointer declarations:

```cpp
// Define a function pointer type
typedef int (*Operation)(int, int);

// Use the type to declare function pointers
Operation operation = add;
```

### Modern C++ Syntax with using

In modern C++, you can use the `using` keyword:

```cpp
// Define a function pointer type
using Operation = int (*)(int, int);

// Use the type to declare function pointers
Operation operation = add;
```

### Initializing Function Pointers

Function pointers can be initialized in several ways:

```cpp
// Direct assignment
int (*operation)(int, int) = add;

// Address-of operator (optional)
int (*operation)(int, int) = &add;

// With typedef
typedef int (*Operation)(int, int);
Operation operation = add;

// With using
using Operation = int (*)(int, int);
Operation operation = add;
```

### Calling Functions Through Pointers

There are two equivalent ways to call a function through a pointer:

```cpp
// Direct call syntax
int result1 = operation(5, 3);

// Dereference syntax
int result2 = (*operation)(5, 3);
```

Both forms are equivalent and produce the same result.

## Passing Functions as Arguments

### Function Pointers as Parameters

Functions can accept function pointers as parameters:

```cpp
// Function that takes a function pointer
int applyOperation(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// With typedef
typedef int (*Operation)(int, int);
int applyOperation(int a, int b, Operation operation) {
    return operation(a, b);
}

// Usage
int result = applyOperation(5, 3, add);  // result = 8
```

### Example: Customizable Sorting

Function pointers allow customizing algorithms like sorting:

```cpp
// Comparison functions
bool ascending(int a, int b) {
    return a < b;
}

bool descending(int a, int b) {
    return a > b;
}

// Sort function that takes a comparison function
void sortArray(int arr[], int size, bool (*compare)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j+1], arr[j])) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Usage
int numbers[] = {5, 2, 8, 1, 9};
sortArray(numbers, 5, ascending);   // Sort in ascending order
sortArray(numbers, 5, descending);  // Sort in descending order
```

### Example: Generic Algorithm

Function pointers enable generic algorithms that work with different data types:

```cpp
// Generic map function that applies a function to each element
template <typename T>
void map(T arr[], int size, T (*func)(T)) {
    for (int i = 0; i < size; i++) {
        arr[i] = func(arr[i]);
    }
}

// Functions to apply
int square(int x) {
    return x * x;
}

double half(double x) {
    return x / 2.0;
}

// Usage
int intArray[] = {1, 2, 3, 4, 5};
map(intArray, 5, square);  // [1, 4, 9, 16, 25]

double doubleArray[] = {2.0, 4.0, 6.0, 8.0};
map(doubleArray, 4, half);  // [1.0, 2.0, 3.0, 4.0]
```

## Callback Mechanisms

### Basic Callback Pattern

Callbacks allow registering functions to be called when specific events occur:

```cpp
// Callback function type
typedef void (*Callback)(const std::string&);

// Function that accepts a callback
void processFile(const std::string& filename, Callback onLineRead) {
    std::ifstream file(filename);
    std::string line;
    
    while (std::getline(file, line)) {
        // Call the callback for each line
        onLineRead(line);
    }
}

// Callback implementation
void printLine(const std::string& line) {
    std::cout << "Line: " << line << std::endl;
}

void countChars(const std::string& line) {
    std::cout << "Characters: " << line.length() << std::endl;
}

// Usage
processFile("data.txt", printLine);   // Print each line
processFile("data.txt", countChars);  // Count characters in each line
```

### Callbacks with Context

Sometimes callbacks need additional context. You can use a context pointer:

```cpp
// Callback with context
typedef void (*CallbackWithContext)(const std::string&, void*);

// Function that accepts a callback with context
void processFile(const std::string& filename, 
                CallbackWithContext callback, void* context) {
    std::ifstream file(filename);
    std::string line;
    
    while (std::getline(file, line)) {
        // Call the callback with context
        callback(line, context);
    }
}

// Callback implementation
void collectLines(const std::string& line, void* context) {
    // Cast context to appropriate type
    std::vector<std::string>* lines = 
        static_cast<std::vector<std::string>*>(context);
    
    // Use context
    lines->push_back(line);
}

// Usage
std::vector<std::string> allLines;
processFile("data.txt", collectLines, &allLines);
```

### Event-Driven Programming

Function pointers are essential for event-driven programming:

```cpp
// Event types
enum EventType {
    MOUSE_CLICK,
    KEY_PRESS,
    WINDOW_RESIZE,
    MAX_EVENT_TYPES
};

// Event handler type
typedef void (*EventHandler)(const void* eventData);

// Event system
class EventSystem {
private:
    EventHandler handlers[MAX_EVENT_TYPES];
    
public:
    EventSystem() {
        // Initialize all handlers to nullptr
        for (int i = 0; i < MAX_EVENT_TYPES; i++) {
            handlers[i] = nullptr;
        }
    }
    
    // Register handler for event type
    void registerHandler(EventType type, EventHandler handler) {
        handlers[type] = handler;
    }
    
    // Trigger event
    void triggerEvent(EventType type, const void* eventData) {
        if (handlers[type] != nullptr) {
            handlers[type](eventData);
        }
    }
};

// Event handlers
void handleMouseClick(const void* data) {
    const int* coords = static_cast<const int*>(data);
    std::cout << "Mouse clicked at: " << coords[0] << ", " << coords[1] << std::endl;
}

void handleKeyPress(const void* data) {
    const char* key = static_cast<const char*>(data);
    std::cout << "Key pressed: " << *key << std::endl;
}

// Usage
EventSystem events;
events.registerHandler(MOUSE_CLICK, handleMouseClick);
events.registerHandler(KEY_PRESS, handleKeyPress);

// Trigger events
int coords[] = {10, 20};
events.triggerEvent(MOUSE_CLICK, coords);

char key = 'A';
events.triggerEvent(KEY_PRESS, &key);
```

## Function Pointer Arrays

### Strategy Selection

Arrays of function pointers enable runtime strategy selection:

```cpp
// Mathematical operations
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

// Array of function pointers
typedef int (*Operation)(int, int);
Operation operations[] = {add, subtract, multiply, divide};

// Operation codes
enum OperationCode {
    ADD = 0,
    SUBTRACT = 1,
    MULTIPLY = 2,
    DIVIDE = 3
};

// Usage
int calculate(int a, int b, OperationCode opCode) {
    return operations[opCode](a, b);
}

// Example
int result = calculate(10, 5, MULTIPLY);  // result = 50
```

### Command Pattern

Function pointer arrays can implement the Command pattern:

```cpp
// Command functions
void newFile() { std::cout << "Creating new file" << std::endl; }
void openFile() { std::cout << "Opening file" << std::endl; }
void saveFile() { std::cout << "Saving file" << std::endl; }
void printFile() { std::cout << "Printing file" << std::endl; }

// Command type
typedef void (*Command)();

// Menu system
class Menu {
private:
    std::string labels[10];
    Command commands[10];
    int count;
    
public:
    Menu() : count(0) {}
    
    // Add menu item
    void addItem(const std::string& label, Command command) {
        if (count < 10) {
            labels[count] = label;
            commands[count] = command;
            count++;
        }
    }
    
    // Execute command by index
    void executeCommand(int index) {
        if (index >= 0 && index < count) {
            commands[index]();
        }
    }
    
    // Display menu
    void display() {
        for (int i = 0; i < count; i++) {
            std::cout << i << ": " << labels[i] << std::endl;
        }
    }
};

// Usage
Menu fileMenu;
fileMenu.addItem("New", newFile);
fileMenu.addItem("Open", openFile);
fileMenu.addItem("Save", saveFile);
fileMenu.addItem("Print", printFile);

fileMenu.display();
fileMenu.executeCommand(2);  // Execute "Save" command
```

### State Machine

Function pointer arrays can implement state machines:

```cpp
// State handler type
typedef void (*StateHandler)();

// State handlers
void idleState() {
    std::cout << "System idle" << std::endl;
    // Logic to determine next state...
}

void activeState() {
    std::cout << "System active" << std::endl;
    // Logic to determine next state...
}

void pausedState() {
    std::cout << "System paused" << std::endl;
    // Logic to determine next state...
}

void errorState() {
    std::cout << "System error" << std::endl;
    // Logic to determine next state...
}

// State codes
enum State {
    IDLE = 0,
    ACTIVE = 1,
    PAUSED = 2,
    ERROR = 3,
    MAX_STATES
};

// State machine
class StateMachine {
private:
    StateHandler states[MAX_STATES];
    State currentState;
    
public:
    StateMachine() : currentState(IDLE) {
        // Initialize state handlers
        states[IDLE] = idleState;
        states[ACTIVE] = activeState;
        states[PAUSED] = pausedState;
        states[ERROR] = errorState;
    }
    
    // Update state machine
    void update() {
        // Execute current state handler
        states[currentState]();
    }
    
    // Transition to new state
    void transitionTo(State newState) {
        if (newState < MAX_STATES) {
            currentState = newState;
        }
    }
};

// Usage
StateMachine machine;
machine.update();           // Execute idle state
machine.transitionTo(ACTIVE);
machine.update();           // Execute active state
```

## Member Function Pointers

### Pointer to Member Function Syntax

Pointers to member functions have a different syntax:

```cpp
// Class with member functions
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }
    int divide(int a, int b) { return b != 0 ? a / b : 0; }
};

// Pointer to member function declaration
int (Calculator::*operation)(int, int);

// Assign member function address
operation = &Calculator::add;

// Call member function through pointer
Calculator calc;
int result = (calc.*operation)(5, 3);  // result = 8
```

### Using typedef with Member Function Pointers

You can use `typedef` to simplify member function pointer declarations:

```cpp
// Define a member function pointer type
typedef int (Calculator::*Operation)(int, int);

// Use the type to declare member function pointers
Operation operation = &Calculator::multiply;

// Call member function through pointer
Calculator calc;
int result = (calc.*operation)(5, 3);  // result = 15
```

### Calling Member Functions Through Pointers

There are two ways to call a member function through a pointer:

```cpp
// For objects
Calculator calc;
int result1 = (calc.*operation)(5, 3);

// For pointers to objects
Calculator* calcPtr = new Calculator();
int result2 = (calcPtr->*operation)(5, 3);
delete calcPtr;
```

### Arrays of Member Function Pointers

You can create arrays of member function pointers:

```cpp
// Define a member function pointer type
typedef int (Calculator::*Operation)(int, int);

// Array of member function pointers
Operation operations[] = {
    &Calculator::add,
    &Calculator::subtract,
    &Calculator::multiply,
    &Calculator::divide
};

// Usage
Calculator calc;
int result = (calc.*operations[2])(5, 3);  // result = 15 (multiply)
```

## Modern C++ Alternatives

### Function Objects (Functors)

Function objects provide an object-oriented alternative to function pointers:

```cpp
// Function object
class Multiplier {
private:
    int factor;
    
public:
    Multiplier(int f) : factor(f) {}
    
    int operator()(int value) const {
        return value * factor;
    }
};

// Usage
Multiplier doubler(2);
int result = doubler(5);  // result = 10

// With algorithms
std::vector<int> numbers = {1, 2, 3, 4, 5};
std::transform(numbers.begin(), numbers.end(), 
               numbers.begin(), Multiplier(3));
// numbers = {3, 6, 9, 12, 15}
```

### Lambda Expressions

Lambda expressions provide a concise way to define anonymous functions:

```cpp
// Lambda expression
auto add = [](int a, int b) { return a + b; };

// Usage
int result = add(5, 3);  // result = 8

// With algorithms
std::vector<int> numbers = {1, 2, 3, 4, 5};
std::transform(numbers.begin(), numbers.end(), 
               numbers.begin(), 
               [](int x) { return x * x; });
// numbers = {1, 4, 9, 16, 25}
```

### std::function

`std::function` provides a type-erased function wrapper:

```cpp
#include <functional>

// std::function declaration
std::function<int(int, int)> operation;

// Assign different callable objects
operation = [](int a, int b) { return a + b; };  // Lambda
int result1 = operation(5, 3);  // result1 = 8

operation = std::minus<int>();  // Function object
int result2 = operation(5, 3);  // result2 = 2

// Regular function
int multiply(int a, int b) { return a * b; }
operation = multiply;
int result3 = operation(5, 3);  // result3 = 15
```

### Comparison of Approaches

| Feature | Function Pointers | Function Objects | Lambdas | std::function |
|---------|-------------------|------------------|---------|---------------|
| Syntax complexity | High | Medium | Low | Low |
| Type safety | Medium | High | High | High |
| State storage | No | Yes | Yes | Yes |
| Performance | High | High | High | Medium |
| Flexibility | Low | Medium | Medium | High |
| C++ version | Any | Any | C++11+ | C++11+ |

## Implementation Guide

The `Tutorials/Module09/Part7/Learning/` directory contains starter files to help you learn about function pointers:

1. Start with these files:
   - `FunctionPointers_starter.h` and `FunctionPointers_starter.cpp`: Function pointer operations
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with basic function pointers:
      - Declare function pointers
      - Assign functions to pointers
      - Call functions through pointers
   
   b. Move to advanced techniques:
      - Create function pointer arrays
      - Implement callbacks
      - Use member function pointers
   
   c. Complete the main program:
      - Test function pointer operations
      - Verify callback behavior
      - Compare with modern alternatives

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o function_pointers_demo main_starter.cpp FunctionPointers_starter.cpp
   
   # Run and verify output
   ./function_pointers_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to understand function pointer behavior

5. Reference Implementation:
   The completed versions (FunctionPointers.h, FunctionPointers.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study function pointer patterns
   - Understand best practices

### Step 1: Basic Function Pointers

```cpp
// Mathematical functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

// Demonstrate basic function pointers
void demonstrateBasicFunctionPointers() {
    cout << "Demonstrating basic function pointers:" << endl;
    
    // Declare function pointer
    int (*operation)(int, int);
    
    // Assign function to pointer
    operation = add;
    cout << "Result of add: " << operation(5, 3) << endl;
    
    // Assign different function
    operation = multiply;
    cout << "Result of multiply: " << operation(5, 3) << endl;
    
    // Using address-of operator (optional)
    operation = &subtract;
    cout << "Result of subtract: " << operation(5, 3) << endl;
    
    // Using dereference syntax
    operation = divide;
    cout << "Result of divide: " << (*operation)(10, 2) << endl;
    
    cout << endl;
}

// Expected Output:
// Demonstrating basic function pointers:
// Result of add: 8
// Result of multiply: 15
// Result of subtract: 2
// Result of divide: 5
```

### Step 2: Function Pointers as Parameters

```cpp
// Function that takes a function pointer
int applyOperation(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// Demonstrate function pointers as parameters
void demonstrateFunctionPointersAsParameters() {
    cout << "Demonstrating function pointers as parameters:" << endl;
    
    // Pass different functions
    cout << "Apply add: " << applyOperation(10, 5, add) << endl;
    cout << "Apply subtract: " << applyOperation(10, 5, subtract) << endl;
    cout << "Apply multiply: " << applyOperation(10, 5, multiply) << endl;
    cout << "Apply divide: " << applyOperation(10, 5, divide) << endl;
    
    cout << endl;
}

// Expected Output:
// Demonstrating function pointers as parameters:
// Apply add: 15
// Apply subtract: 5
// Apply multiply: 50
// Apply divide: 2
```

### Step 3: Function Pointer Arrays

```cpp
// Demonstrate function pointer arrays
void demonstrateFunctionPointerArrays() {
    cout << "Demonstrating function pointer arrays:" << endl;
    
    // Array of function pointers
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};
    
    // Operation names for display
    const char* opNames[] = {"add", "subtract", "multiply", "divide"};
    
    // Use array of function pointers
    int a = 10, b = 5;
    for (int i = 0; i < 4; i++) {
        cout << "Result of " << opNames[i] << ": " 
             << operations[i](a, b) << endl;
    }
    
    cout << endl;
}

// Expected Output:
// Demonstrating function pointer arrays:
// Result of add: 15
// Result of subtract: 5
// Result of multiply: 50
// Result of divide: 2
```

### Step 4: Callbacks

```cpp
// Callback function type
typedef void (*Callback)(int);

// Function that processes an array with a callback
void processArray(int arr[], int size, Callback callback) {
    for (int i = 0; i < size; i++) {
        callback(arr[i]);
    }
}

// Callback implementations
void printElement(int value) {
    cout << "Element: " << value << endl;
}

void squareElement(int value) {
    cout << "Square: " << (value * value) << endl;
}

// Demonstrate callbacks
void demonstrateCallbacks() {
    cout << "Demonstrating callbacks:" << endl;
    
    // Array to process
    int numbers[] = {1, 2, 3, 4, 5};
    
    // Process with different callbacks
    cout << "Processing with printElement:" << endl;
    processArray(numbers, 5, printElement);
    
    cout << "Processing with squareElement:" << endl;
    processArray(numbers, 5, squareElement);
    
    cout << endl;
}

// Expected Output:
// Demonstrating callbacks:
// Processing with printElement:
// Element: 1
// Element: 2
// Element: 3
// Element: 4
// Element: 5
// Processing with squareElement:
// Square: 1
// Square: 4
// Square: 9
// Square: 16
// Square: 25
```

### Step 5: Member Function Pointers

```cpp
// Class with member functions
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }
    int divide(int a, int b) { return b != 0 ? a / b : 0; }
};

// Demonstrate member function pointers
void demonstrateMemberFunctionPointers() {
    cout << "Demonstrating member function pointers:" << endl;
    
    // Declare member function pointer
    int (Calculator::*operation)(int, int);
    
    // Create calculator object
    Calculator calc;
    
    // Assign and call member functions
    operation = &Calculator::add;
    cout << "Result of add: " << (calc.*operation)(10, 5) << endl;
    
    operation = &Calculator::multiply;
    cout << "Result of multiply: " << (calc.*operation)(10, 5) << endl;
    
    // With calculator pointer
    Calculator* calcPtr = new Calculator();
    
    operation = &Calculator::subtract;
    cout << "Result of subtract: " << (calcPtr->*operation)(10, 5) << endl;
    
    delete calcPtr;
    
    cout << endl;
}

// Expected Output:
// Demonstrating member function pointers:
// Result of add: 15
// Result of multiply: 50
// Result of subtract: 5
```

### Step 6: Modern Alternatives

```cpp
#include <functional>
#include <vector>
#include <algorithm>

// Demonstrate modern alternatives
void demonstrateModernAlternatives() {
    cout << "Demonstrating modern alternatives:" << endl;
    
    // Lambda expressions
    cout << "Lambda expressions:" << endl;
    auto add = [](int a, int b) { return a + b; };
    auto multiply = [](int a, int b) { return a * b; };
    
    cout << "Lambda add: " << add(10, 5) << endl;
    cout << "Lambda multiply: " << multiply(10, 5) << endl;
    
    // std::function
    cout << "\nstd::function:" << endl;
    std::function<int(int, int)> operation;
    
    operation = add;  // Assign lambda
    cout << "std::function with lambda: " << operation(10, 5) << endl;
    
    operation = ::multiply;  // Assign regular function
    cout << "std::function with regular function: " << operation(10, 5) << endl;
    
    // Function objects
    cout << "\nFunction objects:" << endl;
    class Multiplier {
    private:
        int factor;
    public:
        Multiplier(int f) : factor(f) {}
        int operator()(int value) const { return value * factor; }
    };
    
    Multiplier doubler(2);
    Multiplier tripler(3);
    
    cout << "Doubler: " << doubler(10) << endl;
    cout << "Tripler: " << tripler(10) << endl;
    
    // With algorithms
    cout << "\nWith algorithms:" << endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    std::transform(numbers.begin(), numbers.end(), 
                  numbers.begin(), doubler);
    
    cout << "After doubling: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << endl;
}

// Expected Output:
// Demonstrating modern alternatives:
// Lambda expressions:
// Lambda add: 15
// Lambda multiply: 50
//
// std::function:
// std::function with lambda: 15
// std::function with regular function: 50
//
// Function objects:
// Doubler: 20
// Tripler: 30
//
// With algorithms:
// After doubling: 2 4 6 8 10
```

## Practice Exercises

The `Tutorials/Module09/Part7/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., FunctionPointers_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your function pointer operations
      - Define required functions and types
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement all required methods
      - Add proper error handling
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -o exercise1 main_starter.cpp FunctionPointers_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand function calls
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Custom Algorithm Library
Implement a library of generic algorithms using function pointers:

```cpp
// TODO: Implement these functions
template <typename T>
void forEach(T arr[], int size, void (*func)(T&));

template <typename T>
void transform(T arr[], int size, T (*func)(T));

template <typename T>
int countIf(T arr[], int size, bool (*predicate)(T));

template <typename T>
T reduce(T arr[], int size, T (*func)(T, T), T initialValue);
```

### Exercise 2: Event System
Create an event system using function pointers:

```cpp
// TODO: Implement this class
class EventSystem {
public:
    // Event handler type
    typedef void (*EventHandler)(const void* eventData);
    
    // Register handler for event type
    void registerHandler(int eventType, EventHandler handler);
    
    // Unregister handler for event type
    void unregisterHandler(int eventType);
    
    // Trigger event
    void triggerEvent(int eventType, const void* eventData);
};
```

### Exercise 3: Strategy Pattern
Implement the Strategy pattern using function pointers:

```cpp
// TODO: Implement these classes
class TextProcessor {
public:
    // Text transformation function type
    typedef std::string (*TextTransform)(const std::string&);
    
    // Set transformation strategy
    void setTransformStrategy(TextTransform transform);
    
    // Process text using current strategy
    std::string processText(const std::string& text);
};

// Transformation strategies
std::string toUpperCase(const std::string& text);
std::string toLowerCase(const std::string& text);
std::string capitalizeWords(const std::string& text);
```

## Advanced Function Pointer Techniques

### Function Pointer Type Erasure

Type erasure allows creating generic interfaces for different function types:

```cpp
// Generic callback wrapper
class Callback {
private:
    void* object;
    void* function;
    void (*invoker)(void* object, void* function, void* data);
    
public:
    // Constructor for free functions
    template <typename Func>
    Callback(Func f) {
        object = nullptr;
        function = reinterpret_cast<void*>(f);
        invoker = [](void* obj, void* func, void* data) {
            Func* f = reinterpret_cast<Func*>(func);
            (*f)(data);
        };
    }
    
    // Constructor for member functions
    template <typename T, typename Func>
    Callback(T* obj, Func f) {
        object = obj;
        function = reinterpret_cast<void*>(f);
        invoker = [](void* obj, void* func, void* data) {
            T* o = reinterpret_cast<T*>(obj);
            Func* f = reinterpret_cast<Func*>(func);
            (o->*f)(data);
        };
    }
    
    // Invoke the callback
    void operator()(void* data) {
        invoker(object, function, data);
    }
};
```

### Function Pointer Metaprogramming

Template metaprogramming can create powerful function pointer utilities:

```cpp
// Function traits to extract return type and parameter types
template <typename T>
struct FunctionTraits;

// Specialization for regular functions
template <typename R, typename... Args>
struct FunctionTraits<R(*)(Args...)> {
    using ReturnType = R;
    using ParameterTypes = std::tuple<Args...>;
    static constexpr size_t ParameterCount = sizeof...(Args);
};

// Specialization for member functions
template <typename C, typename R, typename... Args>
struct FunctionTraits<R(C::*)(Args...)> {
    using ClassType = C;
    using ReturnType = R;
    using ParameterTypes = std::tuple<Args...>;
    static constexpr size_t ParameterCount = sizeof...(Args);
};

// Usage
void func(int, double, const char*) {}

using Traits = FunctionTraits<decltype(&func)>;
static_assert(std::is_same<Traits::ReturnType, void>::value, "Return type should be void");
static_assert(Traits::ParameterCount == 3, "Should have 3 parameters");
```

### Function Pointer Serialization

Function pointers can be serialized for plugin systems:

```cpp
// Function registry
class FunctionRegistry {
private:
    std::unordered_map<std::string, void*> functions;
    
public:
    // Register a function
    template <typename Func>
    void registerFunction(const std::string& name, Func func) {
        functions[name] = reinterpret_cast<void*>(func);
    }
    
    // Get a function by name
    template <typename Func>
    Func getFunction(const std::string& name) {
        if (functions.find(name) != functions.end()) {
            return reinterpret_cast<Func>(functions[name]);
        }
        return nullptr;
    }
};

// Usage
FunctionRegistry registry;
registry.registerFunction("add", add);
registry.registerFunction("multiply", multiply);

// Get function by name
auto func = registry.getFunction<int(*)(int, int)>("add");
if (func) {
    int result = func(5, 3);  // result = 8
}
```

## Summary

### Key Concepts

1. **Function Pointer Basics**
   - Function pointer declaration syntax
   - Assigning functions to pointers
   - Calling functions through pointers
   - Using typedef and using for clarity
   - Equivalent call syntaxes

2. **Functions as Parameters**
   - Passing functions to other functions
   - Customizing algorithm behavior
   - Generic algorithm implementation
   - Type-safe function parameters
   - Runtime behavior selection

3. **Callback Mechanisms**
   - Basic callback patterns
   - Callbacks with context
   - Event-driven programming
   - Asynchronous processing
   - Observer pattern implementation

4. **Function Pointer Arrays**
   - Strategy selection at runtime
   - Command pattern implementation
   - State machine design
   - Menu systems
   - Dispatch tables

5. **Member Function Pointers**
   - Member function pointer syntax
   - Calling member functions through pointers
   - Arrays of member function pointers
   - Object-specific behavior
   - Class method delegation

### Common Pitfalls

1. **Complex Syntax**
   ```cpp
   // Wrong! Incorrect function pointer syntax
   int* operation(int, int);  // This is a function declaration, not a pointer
   
   // Correct
   int (*operation)(int, int);  // Function pointer
   ```

2. **Missing typedef**
   ```cpp
   // Wrong! Repeating complex syntax
   void processArray(int arr[], int size, void (*process)(int));
   void transformArray(int arr[], int size, int (*transform)(int));
   
   // Correct
   typedef void (*Processor)(int);
   typedef int (*Transformer)(int);
   
   void processArray(int arr[], int size, Processor process);
   void transformArray(int arr[], int size, Transformer transform);
   ```

3. **Function Signature Mismatch**
   ```cpp
   // Wrong! Signature mismatch
   int (*operation)(int, int) = someFunction;  // someFunction has wrong signature
   
   // Correct
   int someFunction(int a, int b) { return a + b; }
   int (*operation)(int, int) = someFunction;  // Matching signature
   ```

4. **Member Function Pointer Confusion**
   ```cpp
   // Wrong! Using regular function pointer syntax
   int (*operation)(int, int) = &MyClass::add;  // Error
   
   // Correct
   int (MyClass::*operation)(int, int) = &MyClass::add;
   ```

5. **Context-less Callbacks**
   ```cpp
   // Wrong! No way to pass context
   void processWithCallback(Callback callback) {
       // How to pass additional data to callback?
       callback();
   }
   
   // Correct
   void processWithCallback(Callback callback, void* context) {
       callback(context);
   }
   ```

### Best Practices
1. Use typedef or using to simplify function pointer syntax
2. Prefer modern alternatives (lambdas, std::function) when available
3. Document function pointer parameters clearly
4. Consider context requirements for callbacks
5. Use member function pointers for object-specific behavior
6. Implement proper error handling in callback systems
7. Consider type safety when designing function pointer interfaces
8. Use arrays of function pointers for strategy selection
9. Leverage function traits for metaprogramming
10. Test function pointer code thoroughly with different functions

## Next Steps
1. Complete all practice exercises
2. Test with various function types
3. Review modern C++ alternatives
4. Study design patterns using function pointers
5. Explore the C++ Standard Library's use of function pointers and callable objects

Remember: Function pointers are a powerful tool for creating flexible, extensible code. Understanding them provides insight into many advanced C++ patterns and techniques.
