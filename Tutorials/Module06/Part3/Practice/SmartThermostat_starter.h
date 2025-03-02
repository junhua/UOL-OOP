#ifndef SMART_THERMOSTAT_H
#define SMART_THERMOSTAT_H

#include <string>
#include <vector>
#include <chrono>
#include <mutex>

// Temperature reading with timestamp
struct TemperatureReading {
    double temperature;
    double humidity;
    std::chrono::system_clock::time_point timestamp;
    std::string sensorId;
};

// Schedule entry for temperature control
struct ScheduleEntry {
    int hour;
    int minute;
    double targetTemp;
    bool repeat;
    std::vector<bool> activeDays;  // Sunday to Saturday
};

// Base class for temperature control
class TemperatureController {
    // TODO: Add private member variables for
    // - Current temperature
    // - Target temperature
    // - Temperature range (min/max)
    // - Operating mode
    // - Power status
    // - Temperature history
    // - Error state
    
    // TODO: Add private helper methods for
    // - Validating temperatures
    // - Recording temperature changes
    // - Managing state transitions
    // - Error handling
    
protected:
    // TODO: Add protected methods for derived classes
    // - Update temperature
    // - Handle mode changes
    // - Process schedules
    
public:
    // Constructor and destructor
    TemperatureController(double minTemp, double maxTemp);
    virtual ~TemperatureController() = default;
    
    // Basic operations
    bool setPowerState(bool on);
    bool isOn() const;
    
    // Temperature control
    bool setTargetTemperature(double temp);
    double getTargetTemperature() const;
    double getCurrentTemperature() const;
    
    // Operating modes
    enum class Mode { Heat, Cool, Auto, Off };
    bool setMode(Mode mode);
    Mode getMode() const;
    
    // Temperature history
    std::vector<TemperatureReading> getTemperatureHistory() const;
    double getAverageTemperature(int hours) const;
    
    // Status information
    bool isHeating() const;
    bool isCooling() const;
    virtual std::string getStatus() const = 0;
    
    // Error handling
    bool hasError() const;
    std::string getLastError() const;
    void clearError();
};

// Smart thermostat with advanced features
class SmartThermostat : public TemperatureController {
    // TODO: Add private member variables for
    // - Schedule entries
    // - Sensor readings
    // - Energy usage data
    // - Network status
    // - User preferences
    
protected:
    // TODO: Add protected methods for
    // - Schedule processing
    // - Energy optimization
    // - Sensor data handling
    
public:
    SmartThermostat(double minTemp, double maxTemp);
    
    // Schedule management
    bool addSchedule(const ScheduleEntry& entry);
    bool removeSchedule(int hour, int minute);
    std::vector<ScheduleEntry> getSchedule() const;
    
    // Sensor operations
    bool addSensor(const std::string& sensorId, const std::string& location);
    bool removeSensor(const std::string& sensorId);
    bool updateSensorReading(const std::string& sensorId, 
                           double temp, double humidity);
    
    // Energy management
    double getEnergyUsage() const;
    double getEnergyUsage(int days) const;
    void setEcoMode(bool enabled);
    bool isEcoMode() const;
    
    // Remote operations
    bool connect();
    bool disconnect();
    bool isConnected() const;
    
    // Advanced features
    void enableLearning(bool enabled);
    bool isLearningEnabled() const;
    void setAwayMode(bool away);
    bool isAwayMode() const;
    
    // Overridden methods
    std::string getStatus() const override;
};

// Zone controller for multi-room systems
class ZoneController : public SmartThermostat {
    // TODO: Add private member variables for
    // - Zone information
    // - Zone schedules
    // - Zone sensors
    // - Zone status
    
protected:
    // TODO: Add protected methods for
    // - Zone management
    // - Temperature balancing
    // - Air flow control
    
public:
    ZoneController(const std::string& zoneName,
                  double minTemp, double maxTemp);
    
    // Zone management
    std::string getZoneName() const;
    void setZonePriority(int priority);
    int getZonePriority() const;
    
    // Zone control
    void setZoneActive(bool active);
    bool isZoneActive() const;
    double getZoneTemperature() const;
    
    // Air flow control
    void setVentPosition(int position);
    int getVentPosition() const;
    void setFanSpeed(int speed);
    int getFanSpeed() const;
    
    // Zone schedule
    bool setZoneSchedule(const std::vector<ScheduleEntry>& schedule);
    std::vector<ScheduleEntry> getZoneSchedule() const;
    
    // Status reporting
    bool isZoneHeating() const;
    bool isZoneCooling() const;
    std::string getZoneStatus() const;
};

#endif // SMART_THERMOSTAT_H
