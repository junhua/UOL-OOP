#include "Logger.h"
#include <iostream>
#include <stdexcept>

std::string Logger::getCurrentTime() const {
    time_t now = time(nullptr);
    std::string timestamp = ctime(&now);
    // Remove newline character from ctime output
    return timestamp.substr(0, timestamp.length() - 1);
}

Logger::Logger() 
    : name("default"), enabled(false) {
    std::cout << "Default constructor called" << std::endl;
}

Logger::Logger(const std::string& fileName, bool isEnabled) 
    : name(fileName), enabled(isEnabled) {
    if (enabled) {
        logFile.open(name + ".log", std::ios::app);
        if (!logFile) {
            throw std::runtime_error("Failed to open log file: " + name + ".log");
        }
        log("Log file initialized");
    }
    std::cout << "Parameterized constructor called" << std::endl;
}

Logger::Logger(const Logger& other)
    : name(other.name + "_copy"),
      enabled(other.enabled) {
    if (enabled) {
        logFile.open(name + ".log", std::ios::app);
        if (!logFile) {
            throw std::runtime_error("Failed to open log file: " + name + ".log");
        }
        log("Log file copied");
    }
    std::cout << "Copy constructor called" << std::endl;
}

Logger::~Logger() {
    if (enabled && logFile.is_open()) {
        log("Log file closing");
        logFile.close();
    }
    std::cout << "Destructor called for " << name << std::endl;
}

void Logger::log(const std::string& message) {
    if (enabled && logFile.is_open()) {
        logFile << "[" << getCurrentTime() << "] " 
                << message << std::endl;
    }
}

void Logger::enable() {
    if (!enabled) {
        enabled = true;
        logFile.open(name + ".log", std::ios::app);
        if (!logFile) {
            enabled = false;
            throw std::runtime_error("Failed to open log file: " + name + ".log");
        }
        log("Logging enabled");
    }
}

void Logger::disable() {
    if (enabled) {
        log("Logging disabled");
        enabled = false;
        if (logFile.is_open()) {
            logFile.close();
        }
    }
}
