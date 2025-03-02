#include "Time_starter.h"
#include <iomanip>
#include <sstream>

// TODO: Add member variables in the class definition in Time_starter.h
// int hours;
// int minutes;
// int seconds;

// TODO: Implement validation helper method
bool Time::isValidTime(int h, int m, int s) const {
    // Check if hours is between 0 and 23
    // Check if minutes is between 0 and 59
    // Check if seconds is between 0 and 59
    return false;  // Replace with your implementation
}

// TODO: Implement default constructor
Time::Time() {
    // Initialize hours, minutes, and seconds to 0
}

// TODO: Implement parameterized constructor
Time::Time(int h, int m, int s) {
    // Validate input using isValidTime
    // If valid, set member variables
    // If invalid, throw std::invalid_argument
}

// TODO: Implement setter method
void Time::setTime(int h, int m, int s) {
    // Validate input using isValidTime
    // If valid, set member variables
    // If invalid, throw std::invalid_argument
}

// TODO: Implement getter methods
int Time::getHours() const {
    return 0;  // Replace with your implementation
}

int Time::getMinutes() const {
    return 0;  // Replace with your implementation
}

int Time::getSeconds() const {
    return 0;  // Replace with your implementation
}

// TODO: Implement time manipulation methods
void Time::addSeconds(int s) {
    // Validate that s is not negative
    // Add seconds and handle overflow to minutes
    // Handle overflow of minutes to hours
    // Handle 24-hour wraparound
}

void Time::addMinutes(int m) {
    // Validate that m is not negative
    // Add minutes and handle overflow to hours
    // Handle 24-hour wraparound
}

void Time::addHours(int h) {
    // Validate that h is not negative
    // Add hours and handle 24-hour wraparound
}

// TODO: Implement utility methods
std::string Time::toString() const {
    // Create a string representation of time in format "HH:MM:SS"
    // Use setfill and setw for proper formatting
    return "";  // Replace with your implementation
}

void Time::display() const {
    // Display the time using toString()
}

// TODO: Implement comparison methods
bool Time::equals(const Time& other) const {
    // Compare hours, minutes, and seconds
    return false;  // Replace with your implementation
}

bool Time::isBefore(const Time& other) const {
    // Compare times to check if this time is before other
    // Consider hours first, then minutes, then seconds
    return false;  // Replace with your implementation
}

bool Time::isAfter(const Time& other) const {
    // Use equals and isBefore to determine if this time is after other
    return false;  // Replace with your implementation
}
