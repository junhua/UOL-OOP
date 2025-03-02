#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "SmartThermostat_starter.h"
using namespace std;

// Helper function to display temperature information
void displayTemperature(const string& title, const TemperatureController& controller) {
    cout << "\n" << title << ":" << endl;
    cout << string(title.length() + 1, '=') << endl;
    cout << "Current: " << fixed << setprecision(1) 
         << controller.getCurrentTemperature() << "°C" << endl;
    cout << "Target: " << controller.getTargetTemperature() << "°C" << endl;
    cout << "Mode: ";
    switch (controller.getMode()) {
        case TemperatureController::Mode::Heat: cout << "Heat"; break;
        case TemperatureController::Mode::Cool: cout << "Cool"; break;
        case TemperatureController::Mode::Auto: cout << "Auto"; break;
        case TemperatureController::Mode::Off: cout << "Off"; break;
    }
    cout << endl;
    cout << "Status: " << controller.getStatus() << endl;
}

void testBasicOperations() {
    cout << "\nTesting Basic Operations" << endl;
    cout << "======================" << endl;
    
    SmartThermostat thermostat(10.0, 30.0);  // Min 10°C, Max 30°C
    
    cout << "1. Initial state:" << endl;
    displayTemperature("Thermostat", thermostat);
    
    // Test power control
    cout << "\n2. Power control:" << endl;
    if (thermostat.setPowerState(true)) {
        cout << "Power on successful" << endl;
    }
    cout << "Power state: " << (thermostat.isOn() ? "On" : "Off") << endl;
    
    // Test temperature setting
    cout << "\n3. Temperature control:" << endl;
    if (thermostat.setTargetTemperature(22.5)) {
        cout << "Target temperature set to 22.5°C" << endl;
    }
    if (!thermostat.setTargetTemperature(5.0)) {
        cout << "Prevented setting temperature below minimum" << endl;
    }
    
    // Test mode setting
    cout << "\n4. Mode control:" << endl;
    if (thermostat.setMode(TemperatureController::Mode::Heat)) {
        cout << "Heat mode activated" << endl;
    }
    
    displayTemperature("Updated State", thermostat);
}

void testSmartFeatures() {
    cout << "\nTesting Smart Features" << endl;
    cout << "====================" << endl;
    
    SmartThermostat thermostat(15.0, 28.0);
    thermostat.setPowerState(true);
    
    // Test schedule
    cout << "1. Schedule management:" << endl;
    ScheduleEntry morning{7, 0, 22.0, true, {1,1,1,1,1,0,0}};  // Weekdays
    if (thermostat.addSchedule(morning)) {
        cout << "Morning schedule added" << endl;
    }
    
    auto schedule = thermostat.getSchedule();
    cout << "Schedule entries: " << schedule.size() << endl;
    
    // Test sensors
    cout << "\n2. Sensor management:" << endl;
    if (thermostat.addSensor("LIVING_ROOM", "Living Room")) {
        cout << "Living room sensor added" << endl;
    }
    if (thermostat.updateSensorReading("LIVING_ROOM", 23.5, 45.0)) {
        cout << "Sensor reading updated" << endl;
    }
    
    // Test energy management
    cout << "\n3. Energy management:" << endl;
    thermostat.setEcoMode(true);
    cout << "Eco mode: " << (thermostat.isEcoMode() ? "On" : "Off") << endl;
    cout << "Energy usage: " << thermostat.getEnergyUsage() << " kWh" << endl;
    
    // Test network features
    cout << "\n4. Network features:" << endl;
    if (thermostat.connect()) {
        cout << "Network connected" << endl;
    }
    cout << "Connection status: " 
         << (thermostat.isConnected() ? "Online" : "Offline") << endl;
    
    // Test learning and away modes
    cout << "\n5. Advanced features:" << endl;
    thermostat.enableLearning(true);
    cout << "Learning mode: " 
         << (thermostat.isLearningEnabled() ? "Enabled" : "Disabled") << endl;
    
    thermostat.setAwayMode(true);
    cout << "Away mode: " 
         << (thermostat.isAwayMode() ? "Active" : "Inactive") << endl;
    
    displayTemperature("Smart Features State", thermostat);
}

void testZoneControl() {
    cout << "\nTesting Zone Control" << endl;
    cout << "===================" << endl;
    
    ZoneController zone("Master Bedroom", 18.0, 26.0);
    zone.setPowerState(true);
    
    cout << "1. Zone setup:" << endl;
    cout << "Zone: " << zone.getZoneName() << endl;
    
    zone.setZonePriority(1);  // High priority
    cout << "Priority: " << zone.getZonePriority() << endl;
    
    // Test zone activation
    cout << "\n2. Zone activation:" << endl;
    zone.setZoneActive(true);
    cout << "Zone active: " << (zone.isZoneActive() ? "Yes" : "No") << endl;
    
    // Test air flow control
    cout << "\n3. Air flow control:" << endl;
    zone.setVentPosition(75);  // 75% open
    cout << "Vent position: " << zone.getVentPosition() << "%" << endl;
    
    zone.setFanSpeed(2);  // Medium speed
    cout << "Fan speed: " << zone.getFanSpeed() << endl;
    
    // Test zone schedule
    cout << "\n4. Zone scheduling:" << endl;
    ScheduleEntry night{22, 0, 20.0, true, {1,1,1,1,1,1,1}};  // Every night
    vector<ScheduleEntry> zoneSchedule{night};
    
    if (zone.setZoneSchedule(zoneSchedule)) {
        cout << "Night schedule set" << endl;
    }
    
    auto schedule = zone.getZoneSchedule();
    cout << "Schedule entries: " << schedule.size() << endl;
    
    // Test zone status
    cout << "\n5. Zone status:" << endl;
    cout << "Heating: " << (zone.isZoneHeating() ? "Yes" : "No") << endl;
    cout << "Cooling: " << (zone.isZoneCooling() ? "Yes" : "No") << endl;
    cout << "\nDetailed status:" << endl;
    cout << zone.getZoneStatus() << endl;
}

void testErrorHandling() {
    cout << "\nTesting Error Handling" << endl;
    cout << "====================" << endl;
    
    SmartThermostat thermostat(15.0, 30.0);
    
    cout << "1. Invalid operations:" << endl;
    
    // Test invalid temperature
    if (!thermostat.setTargetTemperature(35.0)) {
        cout << "Prevented setting temperature above maximum" << endl;
    }
    
    // Test invalid mode transition
    if (!thermostat.setMode(TemperatureController::Mode::Cool)) {
        cout << "Prevented invalid mode transition" << endl;
    }
    
    // Test invalid sensor
    if (!thermostat.updateSensorReading("INVALID", 22.0, 50.0)) {
        cout << "Prevented update to non-existent sensor" << endl;
    }
    
    // Test error state
    cout << "\n2. Error handling:" << endl;
    if (thermostat.hasError()) {
        cout << "Error detected: " << thermostat.getLastError() << endl;
        thermostat.clearError();
        cout << "Error cleared" << endl;
    }
}

int main() {
    cout << "Smart Thermostat System Tests" << endl;
    cout << "===========================" << endl;
    
    try {
        testBasicOperations();
        testSmartFeatures();
        testZoneControl();
        testErrorHandling();
        
        cout << "\nAll tests completed successfully!" << endl;
        
    } catch (const exception& e) {
        cerr << "Test failed with error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
