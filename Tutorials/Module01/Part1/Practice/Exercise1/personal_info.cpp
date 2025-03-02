/**
 * @file personal_info.cpp
 * @brief A program that collects and displays user information
 * 
 * This program demonstrates:
 * - User input with validation
 * - Multiple data types (string, int)
 * - Formatted output
 * - Error handling
 */

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>  // For setw

// Function to check if a string is empty or contains only whitespace
bool isEmptyOrWhitespace(const std::string& str) {
    for (char c : str) {
        if (!std::isspace(c)) {
            return false;  // Found a non-whitespace character
        }
    }
    return true;  // String is empty or contains only whitespace
}

// Function to get a valid string input (not empty)
std::string get_valid_string(const std::string& prompt) {
    std::string input;
    bool valid = false;
    
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (isEmptyOrWhitespace(input)) {
            std::cout << "Error: Input cannot be empty. Please try again." << std::endl;
        } else {
            valid = true;
        }
    } while (!valid);
    
    return input;
}

// Function to get a valid positive integer
int get_valid_positive_int(const std::string& prompt) {
    int input;
    bool valid = false;
    
    do {
        std::cout << prompt;
        
        if (std::cin >> input) {
            if (input <= 0) {
                std::cout << "Error: Age must be a positive number. Please try again." << std::endl;
            } else {
                valid = true;
            }
        } else {
            std::cout << "Error: Invalid input. Please enter a number." << std::endl;
            std::cin.clear();  // Clear error flags
        }
        
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (!valid);
    
    return input;
}

int main() {
    // Declare variables for user information
    std::string name;
    int age;
    std::string city;
    std::string occupation;
    
    // Display welcome message and program description
    std::cout << "=======================================" << std::endl;
    std::cout << "      Personal Information Form        " << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "This program collects your personal information" << std::endl;
    std::cout << "and displays it in a formatted card." << std::endl;
    std::cout << "Please provide the following information:" << std::endl;
    std::cout << std::endl;
    
    // Get user information with validation
    name = get_valid_string("Enter your name: ");
    age = get_valid_positive_int("Enter your age: ");
    city = get_valid_string("Enter your city: ");
    occupation = get_valid_string("Enter your occupation: ");
    
    // Calculate the width needed for the card
    int max_length = 14;  // "Occupation: " is 12 characters
    max_length = std::max(max_length, static_cast<int>(name.length() + 6));  // "Name: " is 6 characters
    max_length = std::max(max_length, static_cast<int>(city.length() + 6));  // "City: " is 6 characters
    max_length = std::max(max_length, static_cast<int>(occupation.length() + 12));  // "Occupation: " is 12 characters
    
    // Add some padding
    max_length += 4;
    
    // Display collected information in a formatted card
    std::cout << std::endl;
    std::cout << "+" << std::string(max_length, '-') << "+" << std::endl;
    std::cout << "|" << std::setw(max_length / 2 + 8) << "PERSONAL INFO" 
              << std::setw(max_length / 2 - 7) << "|" << std::endl;
    std::cout << "+" << std::string(max_length, '-') << "+" << std::endl;
    std::cout << "| Name: " << name << std::string(max_length - name.length() - 7, ' ') << "|" << std::endl;
    std::cout << "| Age: " << age << std::string(max_length - std::to_string(age).length() - 6, ' ') << "|" << std::endl;
    std::cout << "| City: " << city << std::string(max_length - city.length() - 7, ' ') << "|" << std::endl;
    std::cout << "| Occupation: " << occupation << std::string(max_length - occupation.length() - 13, ' ') << "|" << std::endl;
    std::cout << "+" << std::string(max_length, '-') << "+" << std::endl;
    
    return 0;
}
