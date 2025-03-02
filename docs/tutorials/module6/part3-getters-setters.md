---
layout: default
title: Part 3 - Getters and Setters
nav_order: 3
parent: Module 6 - Core OOP Concepts - Encapsulation
grand_parent: Tutorials
permalink: /tutorials/module6/part3-getters-setters/
---

# Part 3: Getters and Setters

## Learning Objectives
- Understand the purpose and benefits of getter and setter methods
- Implement validation in setter methods to maintain data integrity
- Create computed properties that derive values from internal state
- Design thread-safe property access for concurrent environments
- Apply state management techniques to maintain object consistency
- Implement proper error handling and reporting in property access

## Introduction
Getter and setter methods (accessors and mutators) provide controlled access to class members. They are a fundamental aspect of encapsulation, allowing you to protect your data while providing a clean interface. Think of them through these real-world analogies:

1. **Bank Tellers**
   - **Public Interface**: Deposit/withdraw forms (getters/setters)
   - **Private Data**: Vault contents (member variables)
   - **Validation**: ID verification (input validation)
   - **Security**: Transaction records (state tracking)

2. **Security Checkpoints**
   - **Public Interface**: ID scanners (getters/setters)
   - **Private Area**: Secure facility (member variables)
   - **Validation**: Credentials check (input validation)
   - **Security**: Access logs (state tracking)

3. **Vending Machines**
   - **Public Interface**: Buttons and coin slot (getters/setters)
   - **Private Mechanics**: Dispensing system (member variables)
   - **Validation**: Coin verification (input validation)
   - **State Management**: Inventory tracking (state tracking)

4. **Thermostats**
   - **Public Interface**: Temperature controls (getters/setters)
   - **Private Mechanics**: HVAC system (member variables)
   - **Computed Values**: Current vs. target temperature (computed properties)
   - **State Management**: Heating/cooling cycles (state tracking)

### Why Use Getters and Setters?

1. **Data Protection**
   - Validate inputs before changing state
   - Control modifications to maintain invariants
   - Prevent invalid states
   - Track changes for debugging
   - Implement access control

2. **Implementation Flexibility**
   - Change internal representation without affecting clients
   - Add logging or debugging without modifying interface
   - Implement lazy loading for performance
   - Cache computed values
   - Add thread safety

3. **State Management**
   - Coordinate related changes to multiple properties
   - Maintain consistency between dependent properties
   - Handle derived or computed properties
   - Track modifications for undo/redo
   - Implement notifications for observers

## Implementation Guide

The `Tutorials/Module06/Part3/Learning/` directory contains starter files to help you learn about getters and setters:

1. Start with these files:
   - `PropertyAccess_starter.h` and `PropertyAccess_starter.cpp`: Class skeletons
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Temperature class:
      - Add private member variables
      - Implement validation methods
      - Create basic getters and setters
      - Add computed properties
   
   b. Move to Image class:
      - Add lazy loading implementation
      - Create computed properties
      - Implement state invalidation
      - Add property validation
   
   c. Complete the ThreadSafeCounter class:
      - Add thread safety with mutexes
      - Implement atomic operations
      - Create thread-safe computed properties
      - Add history tracking

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o property_access main_starter.cpp PropertyAccess_starter.cpp -std=c++17 -pthread
   
   # Run and verify output
   ./property_access
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each feature as you implement it
   - Compare with example code in documentation
   - Use debugger to understand property access flow

5. Reference Implementation:
   The completed versions (PropertyAccess.h, PropertyAccess.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study property access patterns
   - Understand best practices

### Step 1: Basic Getters and Setters

Start with a simple example showing proper implementation:

```cpp
class Temperature {
private:
    double celsius;
    mutable std::string lastError;
    
    bool isValidTemperature(double temp) const {
        return temp >= -273.15;  // Absolute zero
    }
    
    void setError(const std::string& error) const {
        lastError = error;
    }
    
public:
    Temperature() : celsius(0) {}
    
    // Basic getter
    double getCelsius() const {
        return celsius;
    }
    
    // Validated setter
    bool setCelsius(double temp) {
        if (!isValidTemperature(temp)) {
            setError("Temperature below absolute zero");
            return false;
        }
        celsius = temp;
        return true;
    }
    
    // Computed properties
    double getFahrenheit() const {
        return celsius * 9.0/5.0 + 32.0;
    }
    
    bool setFahrenheit(double temp) {
        // Convert to Celsius for validation
        double cel = (temp - 32.0) * 5.0/9.0;
        return setCelsius(cel);
    }
    
    double getKelvin() const {
        return celsius + 273.15;
    }
    
    bool setKelvin(double temp) {
        return setCelsius(temp - 273.15);
    }
    
    // Error handling
    std::string getLastError() const {
        return lastError;
    }
};
```

Test Cases:
```cpp
Temperature temp;
temp.setCelsius(25.0);
cout << "Celsius: " << temp.getCelsius() << "°C" << endl;
cout << "Fahrenheit: " << temp.getFahrenheit() << "°F" << endl;
cout << "Kelvin: " << temp.getKelvin() << "K" << endl;

if (!temp.setCelsius(-300.0)) {
    cout << "Error: " << temp.getLastError() << endl;
}

Expected Output:
Celsius: 25°C
Fahrenheit: 77°F
Kelvin: 298.15K
Error: Temperature below absolute zero
```

Key Points:
- Private member variables
- Validation in setters
- Error reporting
- Computed properties
- Const correctness

### Step 2: Advanced Property Patterns

Implement more complex property patterns:

```cpp
class Image {
private:
    std::string filename;
    mutable std::vector<uint8_t> imageData;
    mutable bool dataLoaded;
    int width;
    int height;
    std::string format;
    mutable std::string lastError;
    
    void loadImageData() const {
        if (!dataLoaded) {
            // Simulate loading image from file
            std::cout << "Loading image data from " << filename << std::endl;
            imageData.resize(width * height);
            // Fill with dummy data
            std::fill(imageData.begin(), imageData.end(), 0);
            dataLoaded = true;
        }
    }
    
    bool isValidDimension(int dimension) const {
        if (dimension <= 0) {
            lastError = "Dimension must be positive";
            return false;
        }
        return true;
    }
    
public:
    Image(const std::string& file, int w, int h, const std::string& fmt)
        : filename(file), dataLoaded(false), width(w), height(h), format(fmt) {
        if (!isValidDimension(w) || !isValidDimension(h)) {
            throw std::invalid_argument(lastError);
        }
    }
    
    // Lazy loading getter
    const std::vector<uint8_t>& getData() const {
        loadImageData();
        return imageData;
    }
    
    // Computed property
    size_t getSize() const {
        return width * height;
    }
    
    // Property with side effect
    bool setDimensions(int w, int h) {
        if (!isValidDimension(w) || !isValidDimension(h)) {
            return false;
        }
        width = w;
        height = h;
        // Invalidate cached data
        imageData.clear();
        dataLoaded = false;
        return true;
    }
    
    // Read-only properties
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::string getFormat() const { return format; }
    std::string getLastError() const { return lastError; }
    
    // Property with validation
    bool setFormat(const std::string& fmt) {
        static const std::vector<std::string> validFormats = {
            "PNG", "JPEG", "GIF", "BMP"
        };
        
        auto it = std::find(validFormats.begin(), validFormats.end(), fmt);
        if (it == validFormats.end()) {
            lastError = "Invalid format: " + fmt;
            return false;
        }
        
        format = fmt;
        return true;
    }
};
```

Test Cases:
```cpp
Image img("photo.jpg", 800, 600, "JPEG");
cout << "Image dimensions: " << img.getWidth() << "x" << img.getHeight() << endl;
cout << "Image size: " << img.getSize() << " pixels" << endl;

// First access loads the data
const auto& data = img.getData();
cout << "Data size: " << data.size() << " bytes" << endl;

// Change dimensions invalidates the data
img.setDimensions(1024, 768);
cout << "New dimensions: " << img.getWidth() << "x" << img.getHeight() << endl;
cout << "New size: " << img.getSize() << " pixels" << endl;

// Data will be reloaded
const auto& newData = img.getData();
cout << "New data size: " << newData.size() << " bytes" << endl;

// Test format validation
if (!img.setFormat("TIFF")) {
    cout << "Error: " << img.getLastError() << endl;
}

Expected Output:
Image dimensions: 800x600
Image size: 480000 pixels
Loading image data from photo.jpg
Data size: 480000 bytes
New dimensions: 1024x768
New size: 786432 pixels
Loading image data from photo.jpg
New data size: 786432 bytes
Error: Invalid format: TIFF
```

Key Points:
- Lazy loading
- Cached properties
- State invalidation
- Property validation
- Side effects

### Step 3: Thread-Safe Properties

Implement thread-safe property access:

```cpp
class ThreadSafeCounter {
private:
    mutable std::mutex mutex;
    int value;
    std::vector<int> history;
    mutable std::string lastError;
    
    bool isValidValue(int val) const {
        if (val < 0) {
            lastError = "Value cannot be negative";
            return false;
        }
        return true;
    }
    
public:
    ThreadSafeCounter() : value(0) {}
    
    // Thread-safe getter
    int getValue() const {
        std::lock_guard<std::mutex> lock(mutex);
        return value;
    }
    
    // Thread-safe setter with validation
    bool setValue(int newValue) {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isValidValue(newValue)) {
            return false;
        }
        value = newValue;
        history.push_back(newValue);
        return true;
    }
    
    // Thread-safe increment
    int increment() {
        std::lock_guard<std::mutex> lock(mutex);
        value++;
        history.push_back(value);
        return value;
    }
    
    // Thread-safe history access
    std::vector<int> getHistory() const {
        std::lock_guard<std::mutex> lock(mutex);
        return history;
    }
    
    // Thread-safe computed property
    double getAverage() const {
        std::lock_guard<std::mutex> lock(mutex);
        if (history.empty()) {
            return 0.0;
        }
        double sum = std::accumulate(history.begin(), history.end(), 0.0);
        return sum / history.size();
    }
    
    // Thread-safe error access
    std::string getLastError() const {
        std::lock_guard<std::mutex> lock(mutex);
        return lastError;
    }
};
```

Test Cases:
```cpp
ThreadSafeCounter counter;
counter.setValue(10);
cout << "Value: " << counter.getValue() << endl;

for (int i = 0; i < 5; i++) {
    cout << "Increment: " << counter.increment() << endl;
}

cout << "Final value: " << counter.getValue() << endl;

if (!counter.setValue(-5)) {
    cout << "Error: " << counter.getLastError() << endl;
}

cout << "History size: " << counter.getHistory().size() << endl;
cout << "Average: " << counter.getAverage() << endl;

Expected Output:
Value: 10
Increment: 11
Increment: 12
Increment: 13
Increment: 14
Increment: 15
Final value: 15
Error: Value cannot be negative
History size: 6
Average: 12.5
```

Key Points:
- Thread safety with mutexes
- Atomic operations
- Consistent locking
- Thread-safe computed properties
- History tracking

## Practice Exercises

The `Tutorials/Module06/Part3/Practice/` directory contains starter files for three exercises:

### Exercise 1: Smart Thermostat

Implement a smart thermostat with proper property management:

Requirements:
- Temperature control with validation
- Mode management (heat, cool, auto, off)
- History tracking
- Statistics calculation
- State consistency

Files:
- `SmartThermostat_starter.h` and `SmartThermostat_starter.cpp`: Class skeletons
- `thermostat_test.cpp`: Test program
- `README.md`: Detailed instructions

### Exercise 2: Media Library

Create a media library with property management:

Requirements:
- Content management (songs, videos, podcasts)
- User preferences (volume, playback speed)
- Playback history
- Rating system
- Search functionality

Files:
- `MediaLibrary_starter.h` and `MediaLibrary_starter.cpp`: Class skeletons
- `media_library_test.cpp`: Test program
- `README.md`: Detailed instructions

### Exercise 3: Financial Account

Build a financial account system with property management:

Requirements:
- Balance management with validation
- Transaction history
- Interest calculation
- Statement generation
- Security features

Files:
- `FinancialAccount_starter.h` and `FinancialAccount_starter.cpp`: Class skeletons
- `account_test.cpp`: Test program
- `README.md`: Detailed instructions

## Best Practices

### 1. Validation in Setters
```cpp
class Person {
private:
    std::string name;
    int age;
    mutable std::string lastError;
    
    bool isValidAge(int a) const {
        if (a < 0 || a > 150) {
            lastError = "Age must be between 0 and 150";
            return false;
        }
        return true;
    }
    
    bool isValidName(const std::string& n) const {
        if (n.empty()) {
            lastError = "Name cannot be empty";
            return false;
        }
        if (n.length() > 100) {
            lastError = "Name too long (max 100 characters)";
            return false;
        }
        return true;
    }
    
public:
    Person(const std::string& n = "", int a = 0) {
        setName(n);
        setAge(a);
    }
    
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getLastError() const { return lastError; }
    
    bool setAge(int a) {
        if (!isValidAge(a)) {
            return false;
        }
        age = a;
        return true;
    }
    
    bool setName(const std::string& n) {
        if (!isValidName(n)) {
            return false;
        }
        name = n;
        return true;
    }
};
```

### 2. Computed Properties
```cpp
class Rectangle {
private:
    double width;
    double height;
    mutable double area;
    mutable bool areaValid;
    
    void invalidateArea() {
        areaValid = false;
    }
    
public:
    Rectangle(double w = 0, double h = 0) 
        : width(w), height(h), area(0), areaValid(false) {}
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    void setWidth(double w) {
        width = w;
        invalidateArea();
    }
    
    void setHeight(double h) {
        height = h;
        invalidateArea();
    }
    
    double getArea() const {
        if (!areaValid) {
            area = width * height;
            areaValid = true;
        }
        return area;
    }
    
    // Combined setter maintains consistency
    bool setDimensions(double w, double h) {
        if (w < 0 || h < 0) {
            return false;
        }
        width = w;
        height = h;
        invalidateArea();
        return true;
    }
};
```

### 3. State Management
```cpp
class Account {
private:
    double balance;
    bool frozen;
    std::vector<std::string> transactions;
    mutable std::string lastError;
    
    void recordTransaction(const std::string& type, double amount) {
        auto now = std::chrono::system_clock::now();
        auto timeT = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        ss << " - " << type << ": $" << std::fixed 
           << std::setprecision(2) << amount;
        transactions.push_back(ss.str());
    }
    
    bool isValidAmount(double amount) const {
        if (amount <= 0) {
            lastError = "Amount must be positive";
            return false;
        }
        return true;
    }
    
public:
    Account() : balance(0), frozen(false) {}
    
    double getBalance() const { return balance; }
    bool isFrozen() const { return frozen; }
    std::vector<std::string> getTransactions() const { return transactions; }
    std::string getLastError() const { return lastError; }
    
    bool deposit(double amount) {
        if (frozen) {
            lastError = "Account is frozen";
            return false;
        }
        if (!isValidAmount(amount)) {
            return false;
        }
        balance += amount;
        recordTransaction("Deposit", amount);
        return true;
    }
    
    bool withdraw(double amount) {
        if (frozen) {
            lastError = "Account is frozen";
            return false;
        }
        if (!isValidAmount(amount)) {
            return false;
        }
        if (amount > balance) {
            lastError = "Insufficient funds";
            return false;
        }
        balance -= amount;
        recordTransaction("Withdrawal", amount);
        return true;
    }
    
    bool freeze() {
        frozen = true;
        recordTransaction("Account frozen", 0);
        return true;
    }
    
    bool unfreeze() {
        frozen = false;
        recordTransaction("Account unfrozen", 0);
        return true;
    }
};
```

## Common Pitfalls

### 1. Unnecessary Getters/Setters
```cpp
// Bad: Exposing implementation details
class Point {
private:
    int x, y;
public:
    int getX() { return x; }
    void setX(int x) { this->x = x; }
    int getY() { return y; }
    void setY(int y) { this->y = y; }
};

// Better: Meaningful operations
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Meaningful operations instead of raw getters/setters
    void moveTo(int newX, int newY) {
        x = newX;
        y = newY;
    }
    
    void moveBy(int dx, int dy) {
        x += dx;
        y += dy;
    }
    
    double distanceTo(const Point& other) const {
        int dx = x - other.x;
        int dy = y - other.y;
        return std::sqrt(dx*dx + dy*dy);
    }
    
    // Only expose coordinates when needed
    std::pair<int, int> getCoordinates() const {
        return {x, y};
    }
};
```

### 2. Inconsistent State
```cpp
// Bad: State can become invalid
class Rectangle {
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    
    // Computed property depends on valid state
    int getArea() { return width * height; }
private:
    int width, height;
};

// Better: Maintain consistency
class Rectangle {
public:
    Rectangle(int w = 0, int h = 0) : width(w), height(h) {
        if (w < 0) width = 0;
        if (h < 0) height = 0;
    }
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
    bool setDimensions(int w, int h) {
        if (w < 0 || h < 0) return false;
        width = w;
        height = h;
        return true;
    }
    
    int getArea() const { return width * height; }
private:
    int width, height;
};
```

### 3. Performance Issues
```cpp
// Bad: Copying large objects
class DataManager {
private:
    std::vector<int> data;
    
public:
    // Returns a copy - inefficient for large vectors
    std::vector<int> getData() {
        return data;
    }
    
    void addData(int value) {
        data.push_back(value);
    }
};

// Better: Return reference
class DataManager {
private:
    std::vector<int> data;
    
public:
    // Returns a const reference - efficient for any size
    const std::vector<int>& getData() const {
        return data;
    }
    
    void addData(int value) {
        data.push_back(value);
    }
    
    // Provide specific operations instead of raw access
    int getSum() const {
        return std::accumulate(data.begin(), data.end(), 0);
    }
    
    double getAverage() const {
        if (data.empty()) return 0.0;
        return static_cast<double>(getSum()) / data.size();
    }
};
```

## Summary

### Key Concepts
1. **Getter and Setter Basics**
   - Private member variables
   - Public access methods
   - Validation in setters
   - Error reporting
   - Const correctness

2. **Advanced Property Patterns**
   - Computed properties
   - Lazy loading
   - Caching
   - State invalidation
   - Side effects

3. **Thread Safety**
   - Mutex protection
   - Atomic operations
   - Consistent locking
   - Thread-safe computed properties
   - Concurrent access

4. **Best Practices**
   - Validate all inputs
   - Maintain state consistency
   - Use meaningful operations
   - Consider performance
   - Provide error reporting

### Next Steps
1. Complete all practice exercises
2. Review your existing classes for proper encapsulation
3. Apply getter and setter patterns to your projects
4. Move on to [Module 7: Inheritance]({{ site.baseurl }}/tutorials/module7)

Remember: Getters and setters are not just about accessing data - they're about providing a controlled interface that maintains class invariants and encapsulates implementation details. Always think about what operations your class should expose rather than simply providing raw access to internal data.
