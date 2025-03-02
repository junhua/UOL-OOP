#include "Time.h"
#include <sstream>

void Time::addSeconds(int s) {
    if (s < 0) {
        throw std::invalid_argument("Cannot add negative seconds");
    }
    
    seconds += s;
    minutes += seconds / 60;
    seconds %= 60;
    
    hours += minutes / 60;
    minutes %= 60;
    hours %= 24;
}

void Time::addMinutes(int m) {
    if (m < 0) {
        throw std::invalid_argument("Cannot add negative minutes");
    }
    
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
    hours %= 24;
}

void Time::addHours(int h) {
    if (h < 0) {
        throw std::invalid_argument("Cannot add negative hours");
    }
    
    hours = (hours + h) % 24;
}

std::string Time::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;
    return oss.str();
}

void Time::display() const {
    std::cout << toString() << std::endl;
}

bool Time::equals(const Time& other) const {
    return hours == other.hours &&
           minutes == other.minutes &&
           seconds == other.seconds;
}

bool Time::isBefore(const Time& other) const {
    if (hours < other.hours) return true;
    if (hours > other.hours) return false;
    
    if (minutes < other.minutes) return true;
    if (minutes > other.minutes) return false;
    
    return seconds < other.seconds;
}

bool Time::isAfter(const Time& other) const {
    return !equals(other) && !isBefore(other);
}
