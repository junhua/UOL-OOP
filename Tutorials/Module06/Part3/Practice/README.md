# Smart Thermostat System Practice Exercise

This exercise focuses on implementing a smart thermostat system that demonstrates proper use of getters, setters, and property access patterns in C++. The system consists of three classes in a hierarchy that model different levels of temperature control functionality.

## Class Hierarchy

{% mermaid %}
classDiagram
    TemperatureController <|-- SmartThermostat
    SmartThermostat <|-- ZoneController
    
    class TemperatureController {
        -temperature: double
        -targetTemp: double
        -mode: Mode
        #validateTemp(temp)
        +getTemp() const
        +setTargetTemp(temp)
    }
    
    class SmartThermostat {
        -schedule: vector
        -sensors: map
        #processSensors()
        +addSchedule()
        +updateSensor()
    }
    
    class ZoneController {
        -zoneName: string
        -priority: int
        #balanceAirFlow()
        +setZonePriority()
        +getZoneStatus()
    }
{% endmermaid %}

## Files

1. **SmartThermostat_starter.h**
   - Class declarations with access specifiers
   - Property declarations and method prototypes
   - Documentation comments

2. **SmartThermostat_starter.cpp**
   - Implementation stubs with TODO comments
   - Helper function suggestions
   - Error handling patterns

3. **thermostat_test.cpp**
   - Comprehensive test cases
   - Usage examples
   - Error handling tests

## Implementation Requirements

### 1. TemperatureController Class
- Basic temperature control
- Mode management (Heat/Cool/Auto/Off)
- Temperature validation
- Error handling
- Status reporting

### 2. SmartThermostat Class
- Schedule management
- Sensor integration
- Energy usage tracking
- Network connectivity
- Learning capabilities
- Away mode support

### 3. ZoneController Class
- Zone-specific settings
- Air flow control
- Priority management
- Zone scheduling
- Status monitoring

## Property Access Patterns

1. **Basic Properties**
   ```cpp
   // Simple getter
   double getCurrentTemperature() const {
       return temperature;
   }
   
   // Validated setter
   bool setTargetTemperature(double temp) {
       if (!isValidTemperature(temp)) return false;
       targetTemperature = temp;
       return true;
   }
   ```

2. **Computed Properties**
   ```cpp
   // Derived from other properties
   bool isHeating() const {
       return isOn() && mode == Mode::Heat && 
              currentTemp < targetTemp;
   }
   ```

3. **Collection Properties**
   ```cpp
   // Safe access to collections
   std::vector<ScheduleEntry> getSchedule() const {
       return schedule;  // Returns copy
   }
   ```

4. **State-Dependent Properties**
   ```cpp
   // Property depends on system state
   bool canSetMode(Mode newMode) const {
       if (!isOn()) return false;
       if (hasError()) return false;
       return isValidModeTransition(currentMode, newMode);
   }
   ```

## Error Handling

1. **Validation**
   ```cpp
   bool isValidTemperature(double temp) const {
       return temp >= minTemp && temp <= maxTemp;
   }
   ```

2. **Error State**
   ```cpp
   void recordError(const std::string& message) {
       lastError = message;
       errorState = true;
   }
   ```

3. **Operation Results**
   ```cpp
   bool updateSensor(const std::string& id, double value) {
       if (!sensorExists(id)) {
           recordError("Invalid sensor ID");
           return false;
       }
       // Update logic
       return true;
   }
   ```

## Thread Safety

1. **Mutex Protection**
   ```cpp
   double getTemperature() const {
       std::lock_guard<std::mutex> lock(mutex);
       return temperature;
   }
   ```

2. **State Consistency**
   ```cpp
   bool updateState(const State& newState) {
       std::lock_guard<std::mutex> lock(mutex);
       if (!isValidTransition(currentState, newState)) {
           return false;
       }
       currentState = newState;
       return true;
   }
   ```

## Implementation Steps

1. **Basic Setup**
   - Implement constructors
   - Add private member variables
   - Define helper methods

2. **Core Functionality**
   - Temperature control
   - Mode management
   - Status reporting

3. **Smart Features**
   - Schedule management
   - Sensor integration
   - Network operations

4. **Zone Control**
   - Zone-specific logic
   - Air flow management
   - Priority handling

5. **Error Handling**
   - Input validation
   - State verification
   - Error reporting

## Testing

1. **Build the Test Program**
   ```bash
   g++ -std=c++17 thermostat_test.cpp SmartThermostat_starter.cpp -o thermostat_test
   ```

2. **Run the Tests**
   ```bash
   ./thermostat_test
   ```

3. **Test Categories**
   - Basic operations
   - Smart features
   - Zone control
   - Error handling

## Learning Objectives

After completing this exercise, you should understand:
1. Proper getter/setter implementation
2. Property access patterns
3. Thread-safe property access
4. Error handling in property operations
5. Collection property management
6. State-dependent properties
7. Computed properties
8. Property inheritance patterns

## Extension Ideas

1. **Additional Features**
   - Weather integration
   - Mobile app connectivity
   - Voice control support
   - Energy usage analytics

2. **Enhanced Scheduling**
   - Holiday schedules
   - Temporary overrides
   - Schedule templates
   - Calendar integration

3. **Advanced Zones**
   - Zone grouping
   - Zone dependencies
   - Occupancy detection
   - Dynamic balancing

## Common Pitfalls

1. **Property Access**
   ```cpp
   // Bad: Direct access
   public:
       double temperature;
   
   // Good: Controlled access
   private:
       double temperature;
   public:
       double getTemperature() const;
   ```

2. **Validation**
   ```cpp
   // Bad: No validation
   void setTemperature(double t) {
       temperature = t;
   }
   
   // Good: Validated
   bool setTemperature(double t) {
       if (!isValidTemperature(t)) return false;
       temperature = t;
       return true;
   }
   ```

3. **Thread Safety**
   ```cpp
   // Bad: Race condition
   void updateTemperature(double t) {
       if (isValidTemperature(t))
           temperature = t;
   }
   
   // Good: Thread-safe
   bool updateTemperature(double t) {
       std::lock_guard<std::mutex> lock(mutex);
       if (!isValidTemperature(t)) return false;
       temperature = t;
       return true;
   }
   ```

Remember: Focus on implementing proper property access patterns while maintaining thread safety and proper error handling.
