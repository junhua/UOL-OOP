#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

class Time {
private:
    // TODO: Add member variables for hours, minutes, and seconds
    
    // TODO: Implement validation helper method
    bool isValidTime(int h, int m, int s) const;
    
public:
    // TODO: Implement constructors
    Time();  // Default constructor
    Time(int h, int m, int s);  // Parameterized constructor
    
    // TODO: Implement setter method
    void setTime(int h, int m, int s);
    
    // TODO: Implement getter methods
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    
    // TODO: Implement time manipulation methods
    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    
    // TODO: Implement utility methods
    std::string toString() const;
    void display() const;
    
    // TODO: Implement comparison methods
    bool equals(const Time& other) const;
    bool isBefore(const Time& other) const;
    bool isAfter(const Time& other) const;
};

#endif // TIME_H
