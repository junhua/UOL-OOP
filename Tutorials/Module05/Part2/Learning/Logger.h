#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <ctime>

class Logger {
private:
    std::string name;
    std::ofstream logFile;
    bool enabled;
    
    // Helper method to get current timestamp
    std::string getCurrentTime() const;
    
public:
    // Default constructor
    Logger();
    
    // Parameterized constructor
    Logger(const std::string& fileName, bool isEnabled = true);
    
    // Copy constructor
    Logger(const Logger& other);
    
    // Destructor
    ~Logger();
    
    // Logging operations
    void log(const std::string& message);
    void enable();
    void disable();
    
    // Status check
    bool isEnabled() const { return enabled; }
    std::string getName() const { return name; }
};

#endif // LOGGER_H
