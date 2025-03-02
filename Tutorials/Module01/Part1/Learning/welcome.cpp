/**
 * @file welcome.cpp
 * @brief A simple C++ program demonstrating basic input/output operations
 * 
 * This program shows the fundamental structure of a C++ program including:
 * - Header inclusion
 * - The main function
 * - Basic console output
 * - User input handling
 * - String processing
 * - Input validation
 */

#include <iostream>  // For input/output operations
#include <string>    // For string handling
#include <limits>    // For input validation

int main() {
    // Initialize variables
    std::string name;
    bool validInput = false;
    
    // Display welcome message
    std::cout << "====================================" << std::endl;
    std::cout << "  Welcome to C++ Programming!" << std::endl;
    std::cout << "====================================" << std::endl;
    
    // Get user's name with input validation
    do {
        std::cout << "What's your name? ";
        std::getline(std::cin, name);
        
        // Check if name is empty or only whitespace
        bool isEmpty = true;
        for (char c : name) {
            if (!std::isspace(c)) {
                isEmpty = false;
                break;
            }
        }
        
        if (isEmpty) {
            std::cout << "Name cannot be empty. Please try again." << std::endl;
        } else {
            validInput = true;
        }
    } while (!validInput);
    
    // Personalized greeting
    std::cout << "\nHello, " << name << "!" << std::endl;
    std::cout << "Ready to start your C++ journey?" << std::endl;
    
    // Program information
    std::cout << "\nThis program demonstrates:" << std::endl;
    std::cout << "- Basic console output using std::cout" << std::endl;
    std::cout << "- User input with std::getline" << std::endl;
    std::cout << "- Simple input validation" << std::endl;
    std::cout << "- String manipulation" << std::endl;
    
    return 0;  // Indicate successful program completion
}
