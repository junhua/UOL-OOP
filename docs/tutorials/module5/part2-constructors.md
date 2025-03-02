---
layout: default
title: Part 2 - Constructors and Destructors
nav_order: 2
parent: Module 5 - Classes and Objects
grand_parent: Tutorials
permalink: /tutorials/module5/part2-constructors/
---

# Part 2: Constructors and Destructors

## Learning Objectives
- Master constructor types and usage patterns
- Understand destructor behavior and necessity
- Learn initialization list techniques
- Practice resource management strategies
- Implement copy and move semantics
- Handle construction errors properly
- Design exception-safe constructors

## Introduction
Constructors and destructors are special member functions that control object lifecycle. Think of them like:

1. **Why Constructors Matter**:
   - **Object Initialization**: Proper setup
   - **Resource Allocation**: Memory management
   - **State Setup**: Initial conditions
   - **Validation**: Input checking
   - **Consistency**: Guaranteed state
   - **Exception Safety**: Safe construction
   - **Resource Management**: RAII pattern

2. **Real-World Applications**:
   - **File Handlers**: Open/close files
   - **Database Connections**: Connect/disconnect
   - **Network Sockets**: Initialize/cleanup
   - **GUI Windows**: Create/destroy
   - **Memory Buffers**: Allocate/deallocate
   - **Resource Pools**: Acquire/release
   - **Hardware Interfaces**: Setup/teardown

3. **Benefits in Development**:
   - **Safety**: Guaranteed initialization
   - **Clarity**: Clear object lifecycle
   - **Efficiency**: Resource management
   - **Reliability**: Consistent cleanup
   - **Maintainability**: Centralized setup
   - **Exception Safety**: RAII pattern
   - **Resource Safety**: Automatic cleanup

## Implementation Guide

You'll find the starter code in `Tutorials/Module05/Part2/constructors_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module05/Part2/constructors.cpp`.

### Step 1: Basic Constructors
```cpp
class Logger {
private:
    string name;
    ofstream logFile;
    bool enabled;
    
public:
    // Default constructor
    Logger() 
        : name("default"), enabled(false) {
        cout << "Default constructor called" << endl;
    }
    
    // Parameterized constructor
    Logger(const string& fileName, bool isEnabled = true) 
        : name(fileName), enabled(isEnabled) {
        if (enabled) {
            logFile.open(name + ".log", ios::app);
            if (!logFile) {
                throw runtime_error("Failed to open log file");
            }
            log("Log file initialized");
        }
        cout << "Parameterized constructor called" << endl;
    }
    
    // Copy constructor
    Logger(const Logger& other)
        : name(other.name + "_copy"),
          enabled(other.enabled) {
        if (enabled) {
            logFile.open(name + ".log", ios::app);
            if (!logFile) {
                throw runtime_error("Failed to open log file");
            }
            log("Log file copied");
        }
        cout << "Copy constructor called" << endl;
    }
    
    // Destructor
    ~Logger() {
        if (enabled && logFile.is_open()) {
            log("Log file closing");
            logFile.close();
        }
        cout << "Destructor called for " << name << endl;
    }
    
    // Member function
    void log(const string& message) {
        if (enabled && logFile.is_open()) {
            logFile << "[" << getCurrentTime() << "] " 
                   << message << endl;
        }
    }
    
private:
    string getCurrentTime() const {
        time_t now = time(nullptr);
        string time = ctime(&now);
        return time.substr(0, time.length() - 1);
    }
};
```

Key Points:
- Constructor types
- Initialization lists
- Resource management
- Error handling
- Copy semantics
- Cleanup operations
- Exception safety

### Step 2: Resource Management
```cpp
class Buffer {
private:
    size_t size;
    int* data;
    
    // Helper for deep copy
    void copyFrom(const Buffer& other) {
        size = other.size;
        data = new int[size];
        copy(other.data, other.data + size, data);
    }
    
public:
    // Constructor with size
    explicit Buffer(size_t n) : size(n) {
        try {
            data = new int[size]();  // Zero-initialize
        } catch (const bad_alloc& e) {
            throw runtime_error("Memory allocation failed");
        }
    }
    
    // Constructor with data
    Buffer(const int* values, size_t n) : size(n) {
        try {
            data = new int[size];
            copy(values, values + size, data);
        } catch (const bad_alloc& e) {
            throw runtime_error("Memory allocation failed");
        }
    }
    
    // Copy constructor
    Buffer(const Buffer& other) {
        copyFrom(other);
    }
    
    // Move constructor
    Buffer(Buffer&& other) noexcept 
        : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
    }
    
    // Assignment operator
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            copyFrom(other);
        }
        return *this;
    }
    
    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }
    
    // Destructor
    ~Buffer() {
        delete[] data;
    }
    
    // Accessors
    size_t getSize() const { return size; }
    
    int get(size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }
    
    void set(size_t index, int value) {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        data[index] = value;
    }
};
```

Key Points:
- Dynamic memory
- Exception handling
- Move semantics
- Deep copying
- Resource cleanup
- RAII pattern
- Strong guarantee

### Step 3: Constructor Delegation
```cpp
class Configuration {
private:
    string filename;
    map<string, string> settings;
    bool loaded;
    
    // Helper method
    void loadFromFile() {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("Failed to open config file");
        }
        
        string line;
        while (getline(file, line)) {
            size_t pos = line.find('=');
            if (pos != string::npos) {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 1);
                settings[key] = value;
            }
        }
        loaded = true;
    }
    
public:
    // Primary constructor
    Configuration(const string& file, bool loadNow = true)
        : filename(file), loaded(false) {
        if (loadNow) {
            loadFromFile();
        }
    }
    
    // Delegating constructor - default file
    Configuration() : Configuration("config.ini", false) {
        settings["version"] = "1.0";
        settings["name"] = "default";
        loaded = true;
    }
    
    // Delegating constructor - with initial setting
    Configuration(const string& key, const string& value)
        : Configuration() {
        settings[key] = value;
    }
    
    // Copy constructor
    Configuration(const Configuration& other)
        : filename(other.filename + ".backup"),
          settings(other.settings),
          loaded(other.loaded) {}
    
    // Destructor
    ~Configuration() {
        if (loaded) {
            // Save changes if needed
            cout << "Saving configuration..." << endl;
        }
    }
    
    // Accessors
    string get(const string& key, const string& defaultValue = "") const {
        auto it = settings.find(key);
        return (it != settings.end()) ? it->second : defaultValue;
    }
    
    void set(const string& key, const string& value) {
        settings[key] = value;
    }
};
```

Key Points:
- Constructor delegation
- Resource initialization
- Error handling
- File operations
- State management
- Configuration loading
- Backup creation

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module05/Part2/practice_constructors_starter.cpp`
- Complete solution: `Tutorials/Module05/Part2/practice_constructors.cpp`

### Exercise 1: Database Connection
Create a database connection class:
```cpp
class DatabaseConnection {
private:
    string host;
    string username;
    string password;
    bool connected;
    void* connection;  // Database handle
    
public:
    // Constructors
    DatabaseConnection(const string& host, 
                      const string& user, 
                      const string& pass);
    DatabaseConnection(const string& configFile);
    
    // Copy/Move operations
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
    DatabaseConnection(DatabaseConnection&&) noexcept;
    DatabaseConnection& operator=(DatabaseConnection&&) noexcept;
    
    // Destructor
    ~DatabaseConnection();
    
    // Connection operations
    bool connect();
    void disconnect();
    bool isConnected() const;
    bool executeQuery(const string& query);
};
```

Requirements:
1. Handle connection failures
2. Manage connection state
3. Implement move semantics
4. Prevent copying
5. Clean up resources
6. Log operations
7. Support reconnection

### Exercise 2: Image Processor
Implement an image processing class:
```cpp
class Image {
private:
    uint8_t* pixels;
    size_t width;
    size_t height;
    size_t channels;
    
public:
    // Constructors
    Image(size_t w, size_t h, size_t c = 3);
    Image(const string& filename);
    Image(const Image& other);
    Image(Image&& other) noexcept;
    
    // Assignment operators
    Image& operator=(const Image& other);
    Image& operator=(Image&& other) noexcept;
    
    // Destructor
    ~Image();
    
    // Image operations
    bool save(const string& filename) const;
    void clear(uint8_t value = 0);
    void flipHorizontal();
    void flipVertical();
    void resize(size_t newWidth, size_t newHeight);
};
```

Requirements:
1. Manage pixel data
2. Handle file operations
3. Implement deep copy
4. Support move semantics
5. Validate dimensions
6. Handle memory errors
7. Support image formats

### Exercise 3: Thread Pool
Create a thread pool implementation:
```cpp
class ThreadPool {
private:
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex queueMutex;
    condition_variable condition;
    bool stop;
    
public:
    // Constructors
    explicit ThreadPool(size_t threads);
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&) = delete;
    
    // Assignment operators
    ThreadPool& operator=(const ThreadPool&) = delete;
    ThreadPool& operator=(ThreadPool&&) = delete;
    
    // Destructor
    ~ThreadPool();
    
    // Pool operations
    template<class F>
    void enqueue(F&& f);
    
    void waitAll();
    size_t activeThreads() const;
    size_t queuedTasks() const;
};
```

Requirements:
1. Initialize thread pool
2. Manage worker threads
3. Handle task queue
4. Implement shutdown
5. Prevent race conditions
6. Support task types
7. Clean up resources

## Summary

### Key Concepts

1. **Constructor Types**
   ```cpp
   class Example {
       Example();                    // Default
       Example(int x);              // Parameterized
       Example(const Example&);     // Copy
       Example(Example&&) noexcept; // Move
   };
   ```

2. **Resource Management**
   ```cpp
   class Resource {
       Resource() { acquire(); }     // Acquire
       ~Resource() { release(); }    // Release
       void acquire();              // Get resource
       void release();              // Free resource
   };
   ```

3. **Constructor Delegation**
   ```cpp
   class Widget {
       Widget(int x, int y);        // Primary
       Widget() : Widget(0, 0) {}   // Delegating
       Widget(int x) : Widget(x, 0) {} // Delegating
   };
   ```

### Common Pitfalls

1. **Missing Initialization**
   ```cpp
   // Wrong: Uninitialized members
   class Wrong {
       int* ptr;
       Wrong() {}  // ptr not initialized
   };
   
   // Right: Initialize all members
   class Right {
       int* ptr;
       Right() : ptr(nullptr) {}
   };
   ```

2. **Resource Leaks**
   ```cpp
   // Wrong: Resource leak
   class Leak {
       Resource* res;
       ~Leak() {}  // Resource not freed
   };
   
   // Right: Clean up
   class NoLeak {
       Resource* res;
       ~NoLeak() { delete res; }
   };
   ```

3. **Exception Safety**
   ```cpp
   // Wrong: Unsafe construction
   class Unsafe {
       Resource* r1;
       Resource* r2;
       Unsafe() {
           r1 = new Resource();  // Might throw
           r2 = new Resource();  // Leak if throws
       }
   };
   
   // Right: Safe construction
   class Safe {
       unique_ptr<Resource> r1;
       unique_ptr<Resource> r2;
       Safe() : r1(new Resource()),
                r2(new Resource()) {}
   };
   ```

### Best Practices

1. **Constructor Design**
   - Initialize all members
   - Use initialization lists
   - Handle exceptions
   - Validate parameters
   - Document behavior
   - Consider delegation
   - Follow RAII

2. **Resource Management**
   - Use smart pointers
   - Implement Rule of Five
   - Clean up resources
   - Handle self-assignment
   - Prevent leaks
   - Support move semantics
   - Ensure exception safety

3. **Error Handling**
   - Validate parameters
   - Handle allocation failures
   - Maintain invariants
   - Provide strong guarantee
   - Document exceptions
   - Clean up on failure
   - Use RAII pattern

4. **Performance**
   - Minimize copying
   - Use move semantics
   - Optimize initialization
   - Consider inlining
   - Profile constructors
   - Avoid virtual dtors
   - Use noexcept

## Next Steps
1. Complete practice exercises
2. Test with various scenarios
3. Handle edge cases
4. Review error handling
5. Move on to [Part 3: Creating and Using Objects]({{ site.baseurl }}/tutorials/module5/part3-objects)

Remember: Proper constructor and destructor implementation is crucial for reliable object lifecycle management. Always ensure resources are properly allocated and cleaned up, and follow RAII principles for exception safety.
