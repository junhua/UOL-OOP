---
layout: default
title: "Topic 1: Text I/O and functions: the main menu"
parent: Labs
nav_order: 1
---

# Topic 1: Text I/O and functions: the main menu

## Overview

Topic 1 introduces the basic structure of the MerkelRex application by implementing a console-based menu system. This topic focuses on:

- Setting up the C++ edit-compile-run cycle
- Implementing text I/O using the standard library
- Creating and calling functions
- Building a modular program structure

## Implementation Details

### Menu System Implementation

The menu system is implemented using a series of functions that handle different aspects of the user interaction:

1. **Menu Display**: A function to display the available options to the user
2. **User Input**: A function to get and validate user input
3. **Option Processing**: A function to process the selected option
4. **Action Functions**: Individual functions for each menu option

The implementation follows a modular approach, where each function has a specific responsibility, making the code more maintainable and easier to understand.

### Code Structure

The initial implementation starts with a simple menu display and gradually evolves to a more structured approach:

#### Initial Implementation

```cpp
#include <iostream>

int main() {
    // 1. print help
    std::cout << "1: Print help" << std::endl;
    // 2. print exchange stats
    std::cout << "2: Print exchange stats." << std::endl;
    // 3. make an offer
    std::cout << "3: Make an offer." << std::endl;
    // 4. make a bid
    std::cout << "4: Make a bid." << std::endl;
    // 5. print wallet
    std::cout << "5: Print wallet." << std::endl;
    // 6. continue
    std::cout << "6: Continue." << std::endl;
    
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    
    return 0;
}
```

#### Adding Conditional Logic

The next step adds conditional logic to handle different user options and a while loop to keep the program running:

```cpp
#include <iostream>

int main() {
    while (true) {
        // Display menu options
        std::cout << "1: Print help" << std::endl;
        std::cout << "2: Print exchange stats." << std::endl;
        std::cout << "3: Make an offer." << std::endl;
        std::cout << "4: Make a bid." << std::endl;
        std::cout << "5: Print wallet." << std::endl;
        std::cout << "6: Continue." << std::endl;
        
        // Get user input
        int userOption;
        std::cin >> userOption;
        std::cout << "You chose: " << userOption << std::endl;
        
        // Process user option
        if (userOption == 1) {
            std::cout << "Help" << std::endl;
        } else if (userOption == 2) {
            std::cout << "Exchange stats" << std::endl;
        } else if (userOption == 3) {
            std::cout << "Make an offer" << std::endl;
        } else if (userOption == 4) {
            std::cout << "Make a bid" << std::endl;
        } else if (userOption == 5) {
            std::cout << "Print wallet" << std::endl;
        } else if (userOption == 6) {
            std::cout << "Continue" << std::endl;
        } else {
            std::cout << "Invalid option" << std::endl;
        }
    }
    
    return 0;
}
```

#### Refactoring into Functions

The final step refactors the code into separate functions for better modularity:

```cpp
#include <iostream>

// Function declarations
void printMenu();
int getUserOption();
void processUserOption(int userOption);
void printHelp();
void printExchangeStats();
void printOffer();
void printBid();
void printWallet();
void continueProgram();

int main() {
    while (true) {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
    return 0;
}

// Function implementations
void printMenu() {
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats." << std::endl;
    std::cout << "3: Make an offer." << std::endl;
    std::cout << "4: Make a bid." << std::endl;
    std::cout << "5: Print wallet." << std::endl;
    std::cout << "6: Continue." << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "Type in 1-6" << std::endl;
}

int getUserOption() {
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption) {
    switch (userOption) {
    case 1:
        printHelp();
        break;
    case 2:
        printExchangeStats();
        break;
    case 3:
        printOffer();
        break;
    case 4:
        printBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        continueProgram();
        break;
    default:
        std::cout << "Invalid option" << std::endl;
    }
}

void printHelp() {
    std::cout << "Help" << std::endl;
}

void printExchangeStats() {
    std::cout << "Exchange stats" << std::endl;
}

void printOffer() {
    std::cout << "Make an offer" << std::endl;
}

void printBid() {
    std::cout << "Make a bid" << std::endl;
}

void printWallet() {
    std::cout << "Print wallet" << std::endl;
}

void continueProgram() {
    std::cout << "Continue" << std::endl;
}
```

## OOP Concepts Demonstrated

While Topic 1 focuses on procedural programming rather than object-oriented programming, it introduces several important concepts that form the foundation for OOP:

### Function Declarations and Definitions

The code demonstrates the separation of function declarations (prototypes) and definitions, which is a key concept in C++ programming:

```cpp
// Declaration
void printMenu();

// Definition
void printMenu() {
    // Implementation
}
```

This separation allows for better code organization and is a precursor to the class declaration/definition separation used in OOP.

### Modularity

The refactored code demonstrates modularity by breaking down the program into smaller, focused functions. Each function has a single responsibility, which is a fundamental principle of good software design and a precursor to the Single Responsibility Principle in OOP.

### Control Flow

The implementation demonstrates various control flow mechanisms:
- Conditional statements (if/else and switch)
- Loops (while)
- Function calls

### Function Parameters and Return Values

The code demonstrates how to pass parameters to functions and return values from functions:

```cpp
int getUserOption() {
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption) {
    // Implementation
}
```

## Key Takeaways

1. **Modular Design**: Breaking down a program into smaller, focused functions improves code organization and maintainability.

2. **Function Structure**: Proper use of function declarations, definitions, parameters, and return values is essential for building well-structured programs.

3. **User Interaction**: Using standard input/output (iostream) for user interaction provides a simple way to create interactive console applications.

4. **Control Flow**: Effective use of conditional statements and loops is crucial for controlling program execution based on user input.

5. **Incremental Development**: The implementation demonstrates an incremental approach to development, starting with a simple implementation and gradually refining it.

## Next Steps

The next topic will build upon this foundation by introducing classes and objects to model data in the MerkelRex application, specifically the OrderBookEntry class for representing trading data.
