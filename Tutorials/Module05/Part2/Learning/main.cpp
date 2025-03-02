#include "Logger.h"
#include <iostream>
using namespace std;

void demonstrateConstructors() {
    cout << "\n1. Constructor Demonstration" << endl;
    cout << "==========================" << endl;
    
    // Default constructor
    Logger defaultLogger;
    cout << "Default logger name: " << defaultLogger.getName() << endl;
    cout << "Default logger enabled: " << (defaultLogger.isEnabled() ? "Yes" : "No") << endl;
    
    // Parameterized constructor
    Logger appLogger("application", true);
    appLogger.log("Application started");
    
    // Copy constructor
    Logger backupLogger(appLogger);
    backupLogger.log("Backup logger initialized");
}

void demonstrateResourceManagement() {
    cout << "\n2. Resource Management" << endl;
    cout << "=====================" << endl;
    
    {
        cout << "\nEntering nested scope" << endl;
        Logger scopedLogger("scoped", true);
        scopedLogger.log("Inside scoped block");
        cout << "Leaving nested scope" << endl;
    }  // Destructor called here
    cout << "Scope ended" << endl;
    
    // Enable/disable demonstration
    Logger controlLogger("control");
    cout << "\nInitially enabled: " << (controlLogger.isEnabled() ? "Yes" : "No") << endl;
    
    controlLogger.enable();
    controlLogger.log("Logger enabled message");
    cout << "Now enabled: " << (controlLogger.isEnabled() ? "Yes" : "No") << endl;
    
    controlLogger.disable();
    controlLogger.log("This message won't be logged");
    cout << "Finally enabled: " << (controlLogger.isEnabled() ? "Yes" : "No") << endl;
}

void demonstrateErrorHandling() {
    cout << "\n3. Error Handling" << endl;
    cout << "=================" << endl;
    
    try {
        // Try to create logger with invalid file location
        Logger invalidLogger("/invalid/path/logger", true);
    } catch (const runtime_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
    
    Logger validLogger("valid");
    try {
        // Try to enable logger with invalid path
        validLogger.enable();
        cout << "Logger enabled successfully" << endl;
        
        validLogger.log("Test message");
        cout << "Message logged successfully" << endl;
        
        validLogger.disable();
        cout << "Logger disabled successfully" << endl;
    } catch (const runtime_error& e) {
        cout << "Caught unexpected error: " << e.what() << endl;
    }
}

int main() {
    cout << "Logger Class Demonstration" << endl;
    cout << "=========================" << endl;
    
    try {
        demonstrateConstructors();
        demonstrateResourceManagement();
        demonstrateErrorHandling();
        
        cout << "\nAll demonstrations completed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    cout << "\nProgram ending - watch for destructor calls" << endl;
    return 0;
}
