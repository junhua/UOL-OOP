#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Exercise 1: Function Counter System
namespace CounterSystem {
    static int counter = 0;  // Private to this namespace
    
    void resetCounter() {
        counter = 0;
        cout << "Counter reset to 0" << endl;
    }
    
    void incrementCounter() {
        counter++;
        cout << "Counter incremented to " << counter << endl;
    }
    
    int getCurrentCount() {
        return counter;
    }
    
    void displayCount() {
        cout << "Current count: " << counter << endl;
    }
}

// Exercise 2: Temperature Tracker
class TemperatureTracker {
private:
    static vector<double> temperatures;
    static double highestTemp;
    static double lowestTemp;
    static double totalTemp;
    static int readingCount;
    
public:
    static void addReading(double temp) {
        if (temperatures.empty()) {
            highestTemp = lowestTemp = temp;
        } else {
            highestTemp = max(highestTemp, temp);
            lowestTemp = min(lowestTemp, temp);
        }
        
        temperatures.push_back(temp);
        totalTemp += temp;
        readingCount++;
        
        cout << "Added temperature: " << temp << "°C" << endl;
    }
    
    static void reset() {
        temperatures.clear();
        highestTemp = lowestTemp = totalTemp = 0;
        readingCount = 0;
        cout << "Temperature tracker reset" << endl;
    }
    
    static double getHighest() { return readingCount > 0 ? highestTemp : 0; }
    static double getLowest() { return readingCount > 0 ? lowestTemp : 0; }
    static double getAverage() { return readingCount > 0 ? totalTemp / readingCount : 0; }
    static int getCount() { return readingCount; }
    
    static void displayStats() {
        if (readingCount == 0) {
            cout << "No temperature readings available" << endl;
            return;
        }
        
        cout << fixed << setprecision(2);
        cout << "Temperature Statistics:" << endl;
        cout << "  Readings: " << readingCount << endl;
        cout << "  Highest:  " << highestTemp << "°C" << endl;
        cout << "  Lowest:   " << lowestTemp << "°C" << endl;
        cout << "  Average:  " << getAverage() << "°C" << endl;
    }
};

// Initialize static members
vector<double> TemperatureTracker::temperatures;
double TemperatureTracker::highestTemp = 0;
double TemperatureTracker::lowestTemp = 0;
double TemperatureTracker::totalTemp = 0;
int TemperatureTracker::readingCount = 0;

// Exercise 3: Resource Manager
namespace ResourceManager {
    const int MAX_RESOURCES = 5;
    static int activeResources = 0;
    
    bool isResourceAvailable() {
        return activeResources < MAX_RESOURCES;
    }
    
    void allocateResource() {
        if (!isResourceAvailable()) {
            throw runtime_error("No resources available");
        }
        activeResources++;
        cout << "Resource allocated. Active resources: " << activeResources << endl;
    }
    
    void releaseResource() {
        if (activeResources <= 0) {
            throw runtime_error("No resources to release");
        }
        activeResources--;
        cout << "Resource released. Active resources: " << activeResources << endl;
    }
    
    int getActiveResources() {
        return activeResources;
    }
}

int main() {
    try {
        // Test Function Counter System
        cout << "=== Function Counter System ===" << endl;
        CounterSystem::displayCount();
        CounterSystem::incrementCounter();
        CounterSystem::incrementCounter();
        CounterSystem::displayCount();
        CounterSystem::resetCounter();
        CounterSystem::displayCount();
        
        // Test Temperature Tracker
        cout << "\n=== Temperature Tracker ===" << endl;
        TemperatureTracker::addReading(25.5);
        TemperatureTracker::addReading(30.2);
        TemperatureTracker::addReading(22.8);
        TemperatureTracker::displayStats();
        TemperatureTracker::reset();
        TemperatureTracker::displayStats();
        
        // Test Resource Manager
        cout << "\n=== Resource Manager ===" << endl;
        cout << "Initial resources: " << ResourceManager::getActiveResources() << endl;
        
        // Allocate maximum resources
        for (int i = 0; i < ResourceManager::MAX_RESOURCES; i++) {
            ResourceManager::allocateResource();
        }
        
        // Try to allocate when full
        try {
            ResourceManager::allocateResource();
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        
        // Release all resources
        while (ResourceManager::getActiveResources() > 0) {
            ResourceManager::releaseResource();
        }
        
        // Try to release when empty
        try {
            ResourceManager::releaseResource();
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
    
    return 0;
}
