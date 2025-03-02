/**
 * @file calculator.cpp
 * @brief An interactive calculator application
 * 
 * This program demonstrates:
 * - Menu-driven interface
 * - Mathematical operations
 * - Input validation
 * - Memory functions
 * - Operation history
 * - Error handling
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>  // For setprecision
#include <cmath>    // For mathematical functions
#include <sstream>  // For string stream

// Function to get a valid menu choice (0-10)
int getValidMenuChoice() {
    int choice;
    bool valid = false;
    
    do {
        std::cout << "Enter your choice (0-10): ";
        
        if (std::cin >> choice) {
            if (choice >= 0 && choice <= 10) {
                valid = true;
            } else {
                std::cout << "Error: Choice must be between 0 and 10. Please try again." << std::endl;
            }
        } else {
            std::cout << "Error: Invalid input. Please enter a number." << std::endl;
            std::cin.clear();  // Clear error flags
        }
        
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (!valid);
    
    return choice;
}

// Function to get a valid number input
double getValidNumber(const std::string& prompt) {
    double number;
    bool valid = false;
    
    do {
        std::cout << prompt;
        
        if (std::cin >> number) {
            valid = true;
        } else {
            std::cout << "Error: Invalid input. Please enter a number." << std::endl;
            std::cin.clear();  // Clear error flags
        }
        
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (!valid);
    
    return number;
}

// Function to get a valid yes/no response
bool getYesNoResponse(const std::string& prompt) {
    char response;
    bool valid = false;
    
    do {
        std::cout << prompt << " (y/n): ";
        
        if (std::cin >> response) {
            response = std::tolower(response);
            if (response == 'y' || response == 'n') {
                valid = true;
            } else {
                std::cout << "Error: Please enter 'y' or 'n'." << std::endl;
            }
        } else {
            std::cout << "Error: Invalid input. Please enter 'y' or 'n'." << std::endl;
            std::cin.clear();  // Clear error flags
        }
        
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (!valid);
    
    return (response == 'y');
}

// Function to display the menu
void displayMenu() {
    std::cout << "\n===== Calculator Menu =====" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Power" << std::endl;
    std::cout << "6. Square Root" << std::endl;
    std::cout << "7. Store to Memory" << std::endl;
    std::cout << "8. Recall from Memory" << std::endl;
    std::cout << "9. Clear Memory" << std::endl;
    std::cout << "10. Show History" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "=========================" << std::endl;
}

// Function to display history
void displayHistory(const std::vector<std::string>& history) {
    if (history.empty()) {
        std::cout << "No operations in history." << std::endl;
        return;
    }
    
    std::cout << "\n===== Operation History =====" << std::endl;
    for (size_t i = 0; i < history.size(); ++i) {
        std::cout << (i + 1) << ". " << history[i] << std::endl;
    }
    std::cout << "============================" << std::endl;
}

int main() {
    // Declare variables
    int choice;
    double operand1, operand2, result = 0.0;
    double memory = 0.0;
    std::vector<std::string> history;
    bool continueProgram = true;
    bool hasResult = false;  // Flag to track if there's a valid result
    
    // Display welcome message and program description
    std::cout << "=======================================" << std::endl;
    std::cout << "      Interactive Calculator           " << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "This program allows you to perform various" << std::endl;
    std::cout << "mathematical operations, store values in" << std::endl;
    std::cout << "memory, and track your calculation history." << std::endl;
    
    // Implement the main program loop
    do {
        // Display the menu
        displayMenu();
        
        // Get user's choice with validation
        choice = getValidMenuChoice();
        
        // Process the user's choice
        switch (choice) {
            case 0:  // Exit
                continueProgram = false;
                break;
                
            case 1:  // Addition
                operand1 = getValidNumber("Enter first number: ");
                operand2 = getValidNumber("Enter second number: ");
                result = operand1 + operand2;
                
                std::cout << std::fixed << std::setprecision(2);
                std::cout << operand1 << " + " << operand2 << " = " << result << std::endl;
                
                // Add to history
                {
                    std::stringstream ss;
                    ss << std::fixed << std::setprecision(2);
                    ss << operand1 << " + " << operand2 << " = " << result;
                    history.push_back(ss.str());
                }
                
                hasResult = true;
                break;
                
            case 2:  // Subtraction
                operand1 = getValidNumber("Enter first number: ");
                operand2 = getValidNumber("Enter second number: ");
                result = operand1 - operand2;
                
                std::cout << std::fixed << std::setprecision(2);
                std::cout << operand1 << " - " << operand2 << " = " << result << std::endl;
                
                // Add to history
                {
                    std::stringstream ss;
                    ss << std::fixed << std::setprecision(2);
                    ss << operand1 << " - " << operand2 << " = " << result;
                    history.push_back(ss.str());
                }
                
                hasResult = true;
                break;
                
            case 3:  // Multiplication
                operand1 = getValidNumber("Enter first number: ");
                operand2 = getValidNumber("Enter second number: ");
                result = operand1 * operand2;
                
                std::cout << std::fixed << std::setprecision(2);
                std::cout << operand1 << " * " << operand2 << " = " << result << std::endl;
                
                // Add to history
                {
                    std::stringstream ss;
                    ss << std::fixed << std::setprecision(2);
                    ss << operand1 << " * " << operand2 << " = " << result;
                    history.push_back(ss.str());
                }
                
                hasResult = true;
                break;
                
            case 4:  // Division
                operand1 = getValidNumber("Enter first number: ");
                operand2 = getValidNumber("Enter second number: ");
                
                if (operand2 == 0) {
                    std::cout << "Error: Division by zero is not allowed." << std::endl;
                    
                    // Add to history
                    {
                        std::stringstream ss;
                        ss << operand1 << " / " << operand2 << " = Error: Division by zero";
                        history.push_back(ss.str());
                    }
                } else {
                    result = operand1 / operand2;
                    
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << operand1 << " / " << operand2 << " = " << result << std::endl;
                    
                    // Add to history
                    {
                        std::stringstream ss;
                        ss << std::fixed << std::setprecision(2);
                        ss << operand1 << " / " << operand2 << " = " << result;
                        history.push_back(ss.str());
                    }
                    
                    hasResult = true;
                }
                break;
                
            case 5:  // Power
                operand1 = getValidNumber("Enter base: ");
                operand2 = getValidNumber("Enter exponent: ");
                result = std::pow(operand1, operand2);
                
                std::cout << std::fixed << std::setprecision(2);
                std::cout << operand1 << " ^ " << operand2 << " = " << result << std::endl;
                
                // Add to history
                {
                    std::stringstream ss;
                    ss << std::fixed << std::setprecision(2);
                    ss << operand1 << " ^ " << operand2 << " = " << result;
                    history.push_back(ss.str());
                }
                
                hasResult = true;
                break;
                
            case 6:  // Square Root
                operand1 = getValidNumber("Enter number: ");
                
                if (operand1 < 0) {
                    std::cout << "Error: Cannot calculate square root of a negative number." << std::endl;
                    
                    // Add to history
                    {
                        std::stringstream ss;
                        ss << "sqrt(" << operand1 << ") = Error: Negative input";
                        history.push_back(ss.str());
                    }
                } else {
                    result = std::sqrt(operand1);
                    
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << "sqrt(" << operand1 << ") = " << result << std::endl;
                    
                    // Add to history
                    {
                        std::stringstream ss;
                        ss << std::fixed << std::setprecision(2);
                        ss << "sqrt(" << operand1 << ") = " << result;
                        history.push_back(ss.str());
                    }
                    
                    hasResult = true;
                }
                break;
                
            case 7:  // Store to Memory
                if (hasResult) {
                    memory = result;
                    std::cout << "Value " << std::fixed << std::setprecision(2) << result << " stored in memory." << std::endl;
                    
                    // Add to history
                    {
                        std::stringstream ss;
                        ss << std::fixed << std::setprecision(2);
                        ss << "Memory Store: " << result;
                        history.push_back(ss.str());
                    }
                } else {
                    std::cout << "No result available to store in memory." << std::endl;
                }
                break;
                
            case 8:  // Recall from Memory
                std::cout << "Memory: " << std::fixed << std::setprecision(2) << memory << std::endl;
                result = memory;
                
                // Add to history
                {
                    std::stringstream ss;
                    ss << std::fixed << std::setprecision(2);
                    ss << "Memory Recall: " << memory;
                    history.push_back(ss.str());
                }
                
                hasResult = true;
                break;
                
            case 9:  // Clear Memory
                memory = 0.0;
                std::cout << "Memory cleared." << std::endl;
                
                // Add to history
                history.push_back("Memory Clear");
                break;
                
            case 10:  // Show History
                displayHistory(history);
                break;
        }
        
        // Ask if the user wants to perform another operation
        if (choice != 0) {
            continueProgram = getYesNoResponse("Do you want to perform another operation?");
        }
        
    } while (continueProgram);
    
    // Display goodbye message
    std::cout << "\nThank you for using the Interactive Calculator!" << std::endl;
    
    return 0;
}
