/**
 * @file temp_converter.cpp
 * @brief A temperature conversion utility
 * 
 * This program demonstrates:
 * - Menu-driven interface
 * - Temperature conversions between different units
 * - Input validation
 * - Formatted output
 * - Multiple conversions in one session
 */

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>  // For setprecision

// Function to get a valid menu choice (0-6)
int getValidMenuChoice() {
    int choice;
    bool valid = false;
    
    do {
        std::cout << "Enter your choice (0-6): ";
        
        if (std::cin >> choice) {
            if (choice >= 0 && choice <= 6) {
                valid = true;
            } else {
                std::cout << "Error: Choice must be between 0 and 6. Please try again." << std::endl;
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

// Function to get a valid temperature input
double getValidTemperature(const std::string& unit) {
    double temp;
    bool valid = false;
    
    do {
        std::cout << "Enter temperature in " << unit << ": ";
        
        if (std::cin >> temp) {
            valid = true;
        } else {
            std::cout << "Error: Invalid input. Please enter a number." << std::endl;
            std::cin.clear();  // Clear error flags
        }
        
        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (!valid);
    
    return temp;
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
    std::cout << "\n===== Temperature Converter Menu =====" << std::endl;
    std::cout << "1. Celsius to Fahrenheit" << std::endl;
    std::cout << "2. Fahrenheit to Celsius" << std::endl;
    std::cout << "3. Celsius to Kelvin" << std::endl;
    std::cout << "4. Kelvin to Celsius" << std::endl;
    std::cout << "5. Fahrenheit to Kelvin" << std::endl;
    std::cout << "6. Kelvin to Fahrenheit" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "===================================" << std::endl;
}

int main() {
    // Declare variables
    int choice;
    double temperature, result;
    bool continueProgram = true;
    
    // Display welcome message and program description
    std::cout << "=======================================" << std::endl;
    std::cout << "      Temperature Converter Utility    " << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "This program allows you to convert temperatures" << std::endl;
    std::cout << "between Celsius, Fahrenheit, and Kelvin." << std::endl;
    
    // Implement the main program loop
    do {
        // Display the menu
        displayMenu();
        
        // Get user's choice with validation
        choice = getValidMenuChoice();
        
        // Process the user's choice
        if (choice == 0) {
            continueProgram = false;
        } else {
            // Get temperature input with validation
            std::string inputUnit;
            
            switch (choice) {
                case 1:
                case 3:
                    inputUnit = "Celsius (°C)";
                    break;
                case 2:
                case 5:
                    inputUnit = "Fahrenheit (°F)";
                    break;
                case 4:
                case 6:
                    inputUnit = "Kelvin (K)";
                    break;
            }
            
            temperature = getValidTemperature(inputUnit);
            
            // Perform the conversion based on the user's choice
            switch (choice) {
                case 1:  // Celsius to Fahrenheit
                    result = (temperature * 9.0 / 5.0) + 32.0;
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << temperature << "°C = " << result << "°F" << std::endl;
                    break;
                    
                case 2:  // Fahrenheit to Celsius
                    result = (temperature - 32.0) * 5.0 / 9.0;
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << temperature << "°F = " << result << "°C" << std::endl;
                    break;
                    
                case 3:  // Celsius to Kelvin
                    result = temperature + 273.15;
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << temperature << "°C = " << result << "K" << std::endl;
                    break;
                    
                case 4:  // Kelvin to Celsius
                    result = temperature - 273.15;
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << temperature << "K = " << result << "°C" << std::endl;
                    break;
                    
                case 5:  // Fahrenheit to Kelvin
                    result = (temperature - 32.0) * 5.0 / 9.0 + 273.15;
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << temperature << "°F = " << result << "K" << std::endl;
                    break;
                    
                case 6:  // Kelvin to Fahrenheit
                    result = (temperature - 273.15) * 9.0 / 5.0 + 32.0;
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << temperature << "K = " << result << "°F" << std::endl;
                    break;
            }
            
            // Ask if the user wants to perform another conversion
            continueProgram = getYesNoResponse("Do you want to perform another conversion?");
        }
        
    } while (continueProgram);
    
    // Display goodbye message
    std::cout << "\nThank you for using the Temperature Converter Utility!" << std::endl;
    
    return 0;
}
