#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    
    // Helper method for validation
    bool isValidTime(int h, int m, int s) const {
        return h >= 0 && h < 24 &&
               m >= 0 && m < 60 &&
               s >= 0 && s < 60;
    }
    
public:
    // Constructors
    Time() : hours(0), minutes(0), seconds(0) {}
    
    Time(int h, int m, int s) {
        if (!isValidTime(h, m, s)) {
            throw std::invalid_argument("Invalid time values");
        }
        hours = h;
        minutes = m;
        seconds = s;
    }
    
    // Setter methods
    void setTime(int h, int m, int s) {
        if (!isValidTime(h, m, s)) {
            throw std::invalid_argument("Invalid time values");
        }
        hours = h;
        minutes = m;
        seconds = s;
    }
    
    // Getter methods
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    
    // Time manipulation methods
    void addSeconds(int s);
    void addMinutes(int m);
    void addHours(int h);
    
    // Utility methods
    std::string toString() const;
    void display() const;
    
    // Time comparison methods
    bool equals(const Time& other) const;
    bool isBefore(const Time& other) const;
    bool isAfter(const Time& other) const;
};

#endif // TIME_H
