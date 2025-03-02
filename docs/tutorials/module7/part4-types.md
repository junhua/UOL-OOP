---
layout: default
title: Part 4 - Types of Inheritance
nav_order: 4
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part4-types/
---

# Part 4: Types of Inheritance

## Learning Objectives
- Understand different inheritance types and their practical applications
- Master access level control in inheritance hierarchies
- Learn when to choose each inheritance type
- Practice proper access control implementation
- Implement complex inheritance hierarchies
- Understand multiple inheritance and its challenges
- Learn about the diamond problem and virtual inheritance
- Document access patterns effectively

## Introduction
C++ provides different types of inheritance that control how base class members are inherited in derived classes. Think of it like security clearance levels in an organization:

1. **Why Inheritance Types Matter**:
   - **Access Control**: Manage member visibility
   - **Interface Design**: Control public API
   - **Implementation Hiding**: Protect internals
   - **Inheritance Control**: Manage derivation
   - **Security**: Enforce encapsulation

2. **Real-World Parallels**:
   - **Security Clearance**: Public → Protected → Private
   - **Building Access**: Public areas → Restricted zones → Private offices
   - **Document Classification**: Public → Confidential → Top Secret
   - **Software Licenses**: Open → Restricted → Proprietary

3. **Benefits in Development**:
   - **Clear Boundaries**: Well-defined access
   - **Controlled Inheritance**: Managed derivation
   - **Implementation Protection**: Hidden details
   - **Interface Control**: Public API management
   - **Design Flexibility**: Different inheritance types

## Types of Inheritance in C++

C++ supports three types of inheritance, each with different access control implications:

### 1. Public Inheritance

```cpp
class Derived : public Base { };
```

- **Access Level Changes**:
  - Public members of Base remain public in Derived
  - Protected members of Base remain protected in Derived
  - Private members of Base are not accessible in Derived

- **Relationship**: Represents "is-a" relationship
- **Usage**: Most common type, used for polymorphism
- **Example**: A Car is a Vehicle

### 2. Protected Inheritance

```cpp
class Derived : protected Base { };
```

- **Access Level Changes**:
  - Public members of Base become protected in Derived
  - Protected members of Base remain protected in Derived
  - Private members of Base are not accessible in Derived

- **Relationship**: Represents "implemented-in-terms-of" relationship
- **Usage**: Rare, used for implementation inheritance
- **Example**: A DatabaseConnection is implemented in terms of a Socket

### 3. Private Inheritance

```cpp
class Derived : private Base { };
```

- **Access Level Changes**:
  - Public members of Base become private in Derived
  - Protected members of Base become private in Derived
  - Private members of Base are not accessible in Derived

- **Relationship**: Represents "implemented-in-terms-of" relationship with no further inheritance
- **Usage**: Alternative to composition when access to protected members is needed
- **Example**: A Stack is implemented in terms of a Vector

## When to Use Each Inheritance Type

### Public Inheritance

Use public inheritance when:
- The derived class truly "is-a" base class
- You want polymorphic behavior
- Clients should be able to use derived objects through base class pointers
- The Liskov Substitution Principle applies

**Real-world example**: GUI frameworks
```cpp
// Base widget class
class Widget {
public:
    virtual void draw() = 0;
    virtual void resize(int w, int h);
    virtual bool contains(int x, int y);
};

// Button IS-A Widget
class Button : public Widget {
public:
    void draw() override;
    void onClick(std::function<void()> handler);
};

// Client code can use any widget polymorphically
void renderUI(Widget* widget) {
    widget->draw();
}
```

### Protected Inheritance

Use protected inheritance when:
- You want to inherit implementation but not interface
- You want derived classes to have access to base class methods
- You don't want clients to use base class methods directly
- You might need further inheritance

**Real-world example**: Framework extension
```cpp
// Framework base class
class FrameworkObject {
public:
    void initialize();
    void cleanup();
protected:
    void logMessage(const std::string& msg);
};

// Your framework extension
class MyFrameworkExtension : protected FrameworkObject {
public:
    void extendedFeature() {
        // Can use protected methods
        logMessage("Using extended feature");
        // Implementation...
    }
};

// Further extension
class SpecificExtension : public MyFrameworkExtension {
public:
    void specificFeature() {
        // Can still use FrameworkObject's protected methods
        logMessage("Using specific feature");
    }
};
```

### Private Inheritance

Use private inheritance when:
- You want to inherit implementation only
- You need access to protected members of the base
- You want to prevent further inheritance
- Composition would work but you need access to protected members

**Real-world example**: Implementation hiding
```cpp
// Third-party timer class
class Timer {
public:
    void start();
    void stop();
protected:
    void onTick();
};

// Your class that needs timer functionality
class DataCollector : private Timer {
public:
    void beginCollection() {
        // Use Timer's public methods
        start();
    }
    
    void endCollection() {
        stop();
    }
    
private:
    // Override protected method
    void onTick() override {
        // Collect data on each tick
        collectDataPoint();
    }
    
    void collectDataPoint() {
        // Implementation...
    }
};

// Client code can't access Timer methods through DataCollector
// DataCollector* collector = new DataCollector();
// collector->start();  // Error: start() is private in DataCollector
```

## Inheritance Type Decision Guide

Use this flowchart to help decide which inheritance type to use:

```
Start
  |
  v
Is Derived truly a kind of Base?
  |
  +--Yes--> Does Derived need to be used
  |          polymorphically through Base?
  |            |
  |            +--Yes--> Use public inheritance
  |            |
  |            +--No---> Consider protected inheritance
  |
  +--No---> Does Derived need access to
             protected members of Base?
               |
               +--Yes--> Is further inheritance needed?
               |           |
               |           +--Yes--> Use protected inheritance
               |           |
               |           +--No---> Use private inheritance
               |
               +--No---> Use composition instead of inheritance
```

## Implementation Guide

The `Tutorials/Module07/Part4/Learning/` directory contains starter files to help you learn about inheritance types:

1. Start with these files:
   - `Base_starter.h` and `Base_starter.cpp`: Base class skeleton
   - `Derived_starter.h` and `Derived_starter.cpp`: Derived classes skeleton
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Base class:
      - Add members with different access levels
      - Create public interface
      - Define protected helpers
      - Hide private implementation
   
   b. Create derived classes:
      - Implement public inheritance
      - Implement protected inheritance
      - Implement private inheritance
   
   c. Complete the main program:
      - Test access levels
      - Verify inheritance behavior
      - Demonstrate restrictions

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o inheritance_demo main_starter.cpp Base_starter.cpp Derived_starter.cpp
   
   # Run and verify output
   ./inheritance_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each access level
   - Compare inheritance types
   - Use debugger to understand access

5. Reference Implementation:
   The completed versions (Base.h, Base.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study access patterns
   - Understand inheritance types

### Step 1: Public Inheritance

```cpp
class Base {
public:
    Base(const std::string& name) : name(name) {
        std::cout << "Creating Base: " << name << std::endl;
    }
    
    virtual ~Base() {
        std::cout << "Destroying Base: " << name << std::endl;
    }
    
    void publicMethod() {
        std::cout << name << ": Public method called" << std::endl;
    }
    
    std::string getName() const { return name; }
    
protected:
    void protectedMethod() {
        std::cout << name << ": Protected method called" << std::endl;
    }
    
    std::string getNameProtected() const { return name + " (protected)"; }
    
private:
    std::string name;
    
    void privateMethod() {
        std::cout << name << ": Private method called" << std::endl;
    }
};

class PublicDerived : public Base {
public:
    PublicDerived() : Base("PublicDerived") {
        std::cout << "Public inheritance example" << std::endl;
    }
    
    void testAccess() {
        std::cout << "Testing access in PublicDerived:" << std::endl;
        publicMethod();      // OK: public is public
        protectedMethod();   // OK: protected is protected
        // privateMethod();  // Error: private not accessible
        
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Protected name: " << getNameProtected() << std::endl;
    }
};
```

Test Cases:
```cpp
PublicDerived derived;
derived.publicMethod();     // OK: public access
// derived.protectedMethod(); // Error: protected access
// derived.privateMethod();   // Error: private access

// Polymorphic usage
Base* base = &derived;
base->publicMethod();       // OK: polymorphic call

Expected Output:
Creating Base: PublicDerived
Public inheritance example
PublicDerived: Public method called
PublicDerived: Public method called
```

### Step 2: Protected Inheritance

```cpp
class ProtectedDerived : protected Base {
public:
    ProtectedDerived() : Base("ProtectedDerived") {
        std::cout << "Protected inheritance example" << std::endl;
    }
    
    void testAccess() {
        std::cout << "Testing access in ProtectedDerived:" << std::endl;
        publicMethod();      // OK: public became protected
        protectedMethod();   // OK: protected remains
        // privateMethod();  // Error: private not accessible
        
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Protected name: " << getNameProtected() << std::endl;
    }
    
    // Expose base functionality selectively
    void exposeName() {
        std::cout << "Exposed name: " << getName() << std::endl;
    }
};

class Further : public ProtectedDerived {
public:
    Further() {
        std::cout << "Further inheritance example" << std::endl;
    }
    
    void testInheritance() {
        std::cout << "Testing inheritance in Further:" << std::endl;
        publicMethod();      // OK: inherited as protected
        protectedMethod();   // OK: still protected
        // privateMethod();  // Error: not accessible
        
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Protected name: " << getNameProtected() << std::endl;
    }
};
```

Test Cases:
```cpp
ProtectedDerived protectedDerived;
// protectedDerived.publicMethod();  // Error: public became protected
protectedDerived.exposeName();      // OK: exposed method
protectedDerived.testAccess();      // OK: member function

// Cannot use polymorphically
// Base* base = &protectedDerived;  // Error: cannot convert

Further further;
further.testInheritance();          // OK: can access inherited protected

Expected Output:
Creating Base: ProtectedDerived
Protected inheritance example
Exposed name: ProtectedDerived
Testing access in ProtectedDerived:
ProtectedDerived: Public method called
ProtectedDerived: Protected method called
Name: ProtectedDerived
Protected name: ProtectedDerived (protected)
Creating Base: ProtectedDerived
Protected inheritance example
Further inheritance example
Testing inheritance in Further:
ProtectedDerived: Public method called
ProtectedDerived: Protected method called
Name: ProtectedDerived
Protected name: ProtectedDerived (protected)
```

### Step 3: Private Inheritance

```cpp
class PrivateDerived : private Base {
public:
    PrivateDerived() : Base("PrivateDerived") {
        std::cout << "Private inheritance example" << std::endl;
    }
    
    void testAccess() {
        std::cout << "Testing access in PrivateDerived:" << std::endl;
        publicMethod();      // OK: became private
        protectedMethod();   // OK: became private
        // privateMethod();  // Error: not accessible
        
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Protected name: " << getNameProtected() << std::endl;
    }
    
    // Selectively expose functionality
    void exposedMethod() {
        std::cout << "Exposed functionality:" << std::endl;
        publicMethod();  // OK: private access
    }
};

// Error: Cannot inherit from private inheritance
// class FurtherPrivate : public PrivateDerived {
//     void test() {
//         // publicMethod();  // Error: not accessible
//         // protectedMethod();  // Error: not accessible
//     }
// };
```

Test Cases:
```cpp
PrivateDerived privateDerived;
// privateDerived.publicMethod();  // Error: public became private
privateDerived.exposedMethod();   // OK: exposed method
privateDerived.testAccess();      // OK: member function

// Cannot use polymorphically
// Base* base = &privateDerived;  // Error: cannot convert

Expected Output:
Creating Base: PrivateDerived
Private inheritance example
Exposed functionality:
PrivateDerived: Public method called
Testing access in PrivateDerived:
PrivateDerived: Public method called
PrivateDerived: Protected method called
Name: PrivateDerived
Protected name: PrivateDerived (protected)
```

## Multiple Inheritance

C++ supports multiple inheritance, allowing a class to inherit from more than one base class:

```cpp
class Base1 {
public:
    void method1() { std::cout << "Base1::method1" << std::endl; }
};

class Base2 {
public:
    void method2() { std::cout << "Base2::method2" << std::endl; }
};

class Derived : public Base1, public Base2 {
public:
    void method3() {
        method1();  // From Base1
        method2();  // From Base2
        std::cout << "Derived::method3" << std::endl;
    }
};
```

### The Diamond Problem

The diamond problem occurs when a class inherits from two classes that both inherit from a common base:

```
    A
   / \
  B   C
   \ /
    D
```

```cpp
class A {
public:
    int value;
    void method() { std::cout << "A::method" << std::endl; }
};

class B : public A {
public:
    void methodB() { std::cout << "B::methodB" << std::endl; }
};

class C : public A {
public:
    void methodC() { std::cout << "C::methodC" << std::endl; }
};

// Without virtual inheritance, D would have two copies of A
class D : public B, public C {
public:
    void methodD() {
        // Ambiguous: which 'value' to use?
        // value = 10;  // Error: ambiguous
        
        // Ambiguous: which 'method' to call?
        // method();  // Error: ambiguous
        
        // Need to specify:
        B::value = 10;
        C::value = 20;
        B::method();
        C::method();
    }
};
```

### Virtual Inheritance

Virtual inheritance solves the diamond problem by ensuring only one copy of the common base:

```cpp
class A {
public:
    int value;
    void method() { std::cout << "A::method" << std::endl; }
};

class B : virtual public A {  // Virtual inheritance
public:
    void methodB() { std::cout << "B::methodB" << std::endl; }
};

class C : virtual public A {  // Virtual inheritance
public:
    void methodC() { std::cout << "C::methodC" << std::endl; }
};

// With virtual inheritance, D has only one copy of A
class D : public B, public C {
public:
    void methodD() {
        // No ambiguity now
        value = 10;  // OK: only one copy of A::value
        method();    // OK: only one copy of A::method
        
        methodB();   // From B
        methodC();   // From C
    }
};
```

### When to Use Multiple Inheritance

Multiple inheritance should be used carefully:

- **Interface Inheritance**: Inheriting from multiple pure abstract classes (interfaces) is generally safe
- **Mixin Classes**: Small, focused classes that add specific functionality
- **Implementation Reuse**: When you need functionality from multiple base classes

**Real-world example**: GUI with serialization
```cpp
// Interface for drawable objects
class Drawable {
public:
    virtual ~Drawable() {}
    virtual void draw() = 0;
};

// Interface for serializable objects
class Serializable {
public:
    virtual ~Serializable() {}
    virtual void serialize(std::ostream& out) = 0;
    virtual void deserialize(std::istream& in) = 0;
};

// A button that can be drawn and serialized
class Button : public Drawable, public Serializable {
private:
    std::string label;
    int x, y, width, height;
    
public:
    Button(const std::string& l, int x, int y, int w, int h)
        : label(l), x(x), y(y), width(w), height(h) {}
    
    void draw() override {
        std::cout << "Drawing button '" << label << "' at (" 
                  << x << "," << y << ")" << std::endl;
    }
    
    void serialize(std::ostream& out) override {
        out << label << " " << x << " " << y << " " 
            << width << " " << height;
    }
    
    void deserialize(std::istream& in) override {
        in >> label >> x >> y >> width >> height;
    }
};
```

## Practice Exercises

The `Tutorials/Module07/Part4/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., Base_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan access levels
      - Define inheritance types
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement access patterns
      - Add proper inheritance
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -o exercise1 main_starter.cpp Base_starter.cpp Derived_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand access
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Library System
Create a library management system:

```cpp
// TODO: Implement these classes
class LibraryItem;     // Base class with public interface
class Book;            // Public inheritance (is-a relationship)
class Reference;       // Protected inheritance (implementation)
class Internal;        // Private inheritance (implementation detail)
```

### Exercise 2: GUI Framework
Implement a GUI component system:

```cpp
// TODO: Implement these classes
class Widget;          // Base widget class
class Button;          // Public widget (is-a relationship)
class Container;       // Protected widget (implementation)
class Implementation;  // Private widget (implementation detail)
```

### Exercise 3: Network Protocol
Create a network protocol system:

```cpp
// TODO: Implement these classes
class Protocol;        // Base protocol
class TCP;             // Public protocol (is-a relationship)
class Internal;        // Protected protocol (implementation)
class Hardware;        // Private protocol (implementation detail)
```

## Real-World Example: Database Abstraction Layer

Here's a more complex example showing different inheritance types in a database abstraction layer:

```cpp
// Base connection interface
class DBConnection {
public:
    virtual ~DBConnection() {}
    
    virtual bool connect(const std::string& connectionString) = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() const = 0;
    
    virtual bool executeQuery(const std::string& query) = 0;
    virtual ResultSet* getResults() = 0;
    
protected:
    // Utility methods for derived classes
    void logError(const std::string& message);
    void logQuery(const std::string& query);
    
    // Connection state
    bool connected = false;
};

// Low-level socket implementation (not part of public API)
class Socket {
public:
    bool open(const std::string& host, int port);
    void close();
    bool send(const char* data, size_t length);
    bool receive(char* buffer, size_t maxLength, size_t& bytesRead);
    
protected:
    // Protected methods for derived classes
    bool waitForData(int timeoutMs);
    bool isOpen() const;
};

// MySQL implementation - public inheritance for "is-a" relationship
class MySQLConnection : public DBConnection {
public:
    bool connect(const std::string& connectionString) override;
    void disconnect() override;
    bool isConnected() const override;
    
    bool executeQuery(const std::string& query) override;
    ResultSet* getResults() override;
    
    // MySQL-specific methods
    bool setOption(MySQLOption option, const std::string& value);
};

// PostgreSQL implementation using sockets - protected inheritance
class PostgreSQLConnection : public DBConnection, protected Socket {
public:
    bool connect(const std::string& connectionString) override;
    void disconnect() override;
    bool isConnected() const override;
    
    bool executeQuery(const std::string& query) override;
    ResultSet* getResults() override;
    
protected:
    // Uses Socket's protected methods
    bool waitForQueryResults() {
        return waitForData(5000);  // Socket's protected method
    }
};

// In-memory database for testing - private inheritance
class InMemoryDatabase : private std::map<std::string, std::vector<std::string>> {
public:
    bool addTable(const std::string& tableName);
    bool addRow(const std::string& tableName, const std::vector<std::string>& row);
    std::vector<std::vector<std::string>> query(const std::string& tableName);
    
private:
    // Uses map's methods privately
    bool tableExists(const std::string& tableName) {
        return find(tableName) != end();  // map's methods
    }
};

// Connection pool using multiple inheritance
class ConnectionPool : public std::vector<DBConnection*>, private std::mutex {
public:
    DBConnection* getConnection() {
        // Uses mutex to ensure thread safety
        std::lock_guard<std::mutex> lock(*this);  // private inheritance
        
        // Uses vector methods through public inheritance
        for (auto conn : *this) {
            if (!conn->isConnected()) {
                return conn;
            }
        }
        
        return nullptr;
    }
    
    void releaseConnection(DBConnection* conn) {
        std::lock_guard<std::mutex> lock(*this);
        // Implementation...
    }
};
```

## Summary

### Key Concepts

1. **Public Inheritance**
   - Preserves access levels
   - Models "is-a" relationship
   - Maintains interface
   - Supports polymorphism
   - Most common type

2. **Protected Inheritance**
   - Public becomes protected
   - Implementation inheritance
   - Restricts external access
   - Allows further inheritance
   - Used for implementation details that derived classes need

3. **Private Inheritance**
   - All becomes private
   - Implementation detail
   - Prevents inheritance
   - Composition alternative
   - Used when you need access to protected members

4. **Multiple Inheritance**
   - Inherits from multiple base classes
   - Can lead to diamond problem
   - Solved with virtual inheritance
   - Useful for interfaces and mixins
   - Requires careful design

### Common Pitfalls

1. **Wrong Inheritance Type**
   ```cpp
   // Wrong! Should be public for "is-a"
   class Dog : private Animal { };
   
   // Correct
   class Dog : public Animal { };
   ```

2. **Access Confusion**
   ```cpp
   // Wrong! Can't access protected
   ProtectedDerived d;
   d.publicMethod();  // Error: public became protected
   
   // Correct
   ProtectedDerived d;
   d.exposeName();    // Use exposed methods
   ```

3. **Inheritance Chain**
   ```cpp
   // Wrong! Can't inherit from private
   class Further : public PrivateDerived { };
   
   // Correct
   class Further : public PublicDerived { };
   ```

4. **Diamond Problem**
   ```cpp
   // Wrong! Ambiguous inheritance
   class D : public B, public C { };  // B and C both inherit from A
   
   // Correct
   class B : virtual public A { };
   class C : virtual public A { };
   class D : public B, public C { };
   ```

5. **Overusing Inheritance**
   ```cpp
   // Wrong! Inheritance for code reuse only
   class StringUtils { /* utility methods */ };
   class TextProcessor : public StringUtils { };
   
   // Correct
   class TextProcessor {
       StringUtils utils;  // Composition
   };
   ```

### Best Practices
1. Use public inheritance for "is-a" relationships
2. Use private inheritance for implementation details
3. Use protected inheritance sparingly
4. Document inheritance decisions
5. Test access patterns thoroughly
6. Consider composition as an alternative
7. Use multiple inheritance carefully
8. Use virtual inheritance for diamond patterns
9. Keep inheritance hierarchies shallow
10. Follow LSP principles with public inheritance

## Next Steps
1. Complete all practice exercises
2. Test with various scenarios
3. Review inheritance types
4. Study access patterns
5. Consider taking [Module 8: Core OOP Concepts - Polymorphism]({{ site.baseurl }}/tutorials/module8)

Remember: Inheritance types control member access and derivation capabilities. Choose the appropriate type based on your design needs.
