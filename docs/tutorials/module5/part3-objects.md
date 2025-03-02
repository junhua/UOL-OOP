---
layout: default
title: Part 3 - Creating and Using Objects
nav_order: 3
parent: Module 5 - Classes and Objects
grand_parent: Tutorials
permalink: /tutorials/module5/part3-objects/
---

# Part 3: Creating and Using Objects

## Learning Objectives
- Master object instantiation techniques
- Understand object lifetime management
- Learn object relationship patterns
- Practice object composition strategies
- Implement object interactions
- Handle object-related errors
- Design robust object hierarchies

## Introduction
Objects are instances of classes that represent real-world entities in your program. Think of them like:

1. **Why Objects Matter**:
   - **Data Organization**: Group related data
   - **State Management**: Track conditions
   - **Behavior Encapsulation**: Bundle operations
   - **Interface Definition**: Clear interactions
   - **Instance Control**: Multiple copies
   - **Resource Management**: Controlled lifecycle
   - **Type Safety**: Compile-time checking

2. **Real-World Applications**:
   - **User Management**: Account objects
   - **Game Development**: Entity objects
   - **Financial Systems**: Transaction objects
   - **GUI Applications**: Widget objects
   - **Database Systems**: Record objects
   - **Network Systems**: Connection objects
   - **File Systems**: Stream objects

3. **Benefits in Development**:
   - **Code Organization**: Logical grouping
   - **Data Protection**: Controlled access
   - **Code Reuse**: Multiple instances
   - **Maintenance**: Localized changes
   - **Testing**: Isolated units
   - **Debugging**: State inspection
   - **Documentation**: Clear structure

## Implementation Guide

You'll find the starter code in `Tutorials/Module05/Part3/objects_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module05/Part3/objects.cpp`.

### Step 1: Object Creation and Initialization
```cpp
class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;
    vector<string> transactions;
    
public:
    // Constructor with validation
    BankAccount(const string& number, const string& name, double initial = 0.0) {
        if (number.empty() || name.empty()) {
            throw invalid_argument("Account number and name required");
        }
        if (initial < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
        
        accountNumber = number;
        ownerName = name;
        balance = initial;
        
        // Record initial transaction
        if (initial > 0) {
            addTransaction("Initial deposit: " + to_string(initial));
        }
    }
    
    // Member functions
    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive");
        }
        
        balance += amount;
        addTransaction("Deposit: " + to_string(amount));
    }
    
    bool withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive");
        }
        
        if (amount > balance) {
            return false;
        }
        
        balance -= amount;
        addTransaction("Withdrawal: " + to_string(amount));
        return true;
    }
    
    // Getters
    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }
    
    // Display account details
    void displayAccount() const {
        cout << "Account: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
        
        cout << "\nTransaction History:" << endl;
        for (const auto& transaction : transactions) {
            cout << "- " << transaction << endl;
        }
    }
    
private:
    void addTransaction(const string& description) {
        time_t now = time(nullptr);
        string timestamp = ctime(&now);
        timestamp = timestamp.substr(0, timestamp.length() - 1);  // Remove newline
        
        transactions.push_back(timestamp + " - " + description);
    }
};

int main() {
    try {
        // Create account objects
        BankAccount savings("SAV001", "John Doe", 1000.0);
        BankAccount checking("CHK002", "John Doe");
        
        // Perform transactions
        savings.deposit(500.0);
        if (savings.withdraw(200.0)) {
            checking.deposit(200.0);  // Transfer between accounts
        }
        
        // Display accounts
        cout << "Savings Account:" << endl;
        savings.displayAccount();
        
        cout << "\nChecking Account:" << endl;
        checking.displayAccount();
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
```

Key Points:
- Object instantiation
- Constructor validation
- Member access
- State management
- Transaction tracking
- Error handling
- Object interaction

### Step 2: Object Relationships
```cpp
class Product {
private:
    string id;
    string name;
    double price;
    
public:
    Product(const string& i, const string& n, double p)
        : id(i), name(n), price(p) {
        if (price < 0) {
            throw invalid_argument("Price cannot be negative");
        }
    }
    
    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
};

class ShoppingCart {
private:
    vector<pair<Product, int>> items;  // Product and quantity
    
public:
    void addItem(const Product& product, int quantity = 1) {
        if (quantity <= 0) {
            throw invalid_argument("Quantity must be positive");
        }
        
        // Check if product already exists
        for (auto& item : items) {
            if (item.first.getId() == product.getId()) {
                item.second += quantity;
                return;
            }
        }
        
        items.emplace_back(product, quantity);
    }
    
    void removeItem(const string& productId, int quantity = 1) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->first.getId() == productId) {
                it->second -= quantity;
                if (it->second <= 0) {
                    items.erase(it);
                }
                return;
            }
        }
    }
    
    double getTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.first.getPrice() * item.second;
        }
        return total;
    }
    
    void displayCart() const {
        cout << "Shopping Cart Contents:" << endl;
        cout << "----------------------" << endl;
        
        for (const auto& item : items) {
            cout << item.first.getName() 
                 << " (ID: " << item.first.getId() << ")"
                 << " x " << item.second
                 << " @ $" << fixed << setprecision(2) 
                 << item.first.getPrice()
                 << " = $" << item.first.getPrice() * item.second 
                 << endl;
        }
        
        cout << "----------------------" << endl;
        cout << "Total: $" << getTotal() << endl;
    }
};

class Order {
private:
    string orderId;
    ShoppingCart cart;
    string status;
    time_t orderTime;
    
public:
    Order(const string& id, const ShoppingCart& c)
        : orderId(id), cart(c), status("Pending"), orderTime(time(nullptr)) {}
    
    void process() {
        // Process order logic here
        status = "Processed";
    }
    
    void displayOrder() const {
        cout << "Order ID: " << orderId << endl;
        cout << "Status: " << status << endl;
        cout << "Order Time: " << ctime(&orderTime);
        cart.displayCart();
    }
};
```

Key Points:
- Object composition
- Object relationships
- Collection management
- State tracking
- Data validation
- Error handling
- Object interaction

### Step 3: Object Lifecycle Management
```cpp
class ResourceManager {
private:
    string name;
    vector<unique_ptr<Resource>> resources;
    mutex resourceMutex;
    
public:
    ResourceManager(const string& n) : name(n) {}
    
    // Add resource with ownership transfer
    void addResource(unique_ptr<Resource> resource) {
        if (!resource) {
            throw invalid_argument("Cannot add null resource");
        }
        
        lock_guard<mutex> lock(resourceMutex);
        resources.push_back(move(resource));
    }
    
    // Access resource safely
    Resource* getResource(size_t index) {
        lock_guard<mutex> lock(resourceMutex);
        if (index >= resources.size()) {
            throw out_of_range("Resource index out of range");
        }
        return resources[index].get();
    }
    
    // Remove resource
    unique_ptr<Resource> removeResource(size_t index) {
        lock_guard<mutex> lock(resourceMutex);
        if (index >= resources.size()) {
            throw out_of_range("Resource index out of range");
        }
        
        unique_ptr<Resource> resource = move(resources[index]);
        resources.erase(resources.begin() + index);
        return resource;
    }
    
    // Resource status
    size_t resourceCount() const {
        lock_guard<mutex> lock(resourceMutex);
        return resources.size();
    }
    
    void displayResources() const {
        lock_guard<mutex> lock(resourceMutex);
        cout << "Resource Manager: " << name << endl;
        cout << "Resource Count: " << resources.size() << endl;
        
        for (size_t i = 0; i < resources.size(); ++i) {
            cout << "Resource " << i << ": " 
                 << resources[i]->getDescription() << endl;
        }
    }
};
```

Key Points:
- Smart pointers
- Resource ownership
- Thread safety
- Error handling
- State management
- Safe access
- Cleanup handling

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module05/Part3/practice_objects_starter.cpp`
- Complete solution: `Tutorials/Module05/Part3/practice_objects.cpp`

### Exercise 1: Document Management System
Create a document management system:
```cpp
class Document {
private:
    string id;
    string title;
    string content;
    vector<string> tags;
    time_t lastModified;
    
public:
    Document(const string& id, const string& title);
    void setContent(const string& content);
    void addTag(const string& tag);
    bool removeTag(const string& tag);
    bool containsText(const string& text) const;
    void display() const;
};

class DocumentManager {
private:
    map<string, unique_ptr<Document>> documents;
    vector<string> searchIndex;
    
public:
    void addDocument(unique_ptr<Document> doc);
    Document* getDocument(const string& id);
    vector<Document*> findByTag(const string& tag);
    vector<Document*> search(const string& text);
    void removeDocument(const string& id);
};
```

Requirements:
1. Manage document lifecycle
2. Implement search functionality
3. Handle document metadata
4. Support tagging system
5. Maintain search index
6. Handle concurrent access
7. Implement error handling

### Exercise 2: Event System
Implement an event management system:
```cpp
class Event {
private:
    string id;
    string name;
    time_t startTime;
    time_t endTime;
    vector<string> attendees;
    
public:
    Event(const string& id, const string& name);
    void setTimes(time_t start, time_t end);
    bool addAttendee(const string& person);
    bool removeAttendee(const string& person);
    bool hasConflict(const Event& other) const;
    void display() const;
};

class Calendar {
private:
    string owner;
    vector<unique_ptr<Event>> events;
    
public:
    void addEvent(unique_ptr<Event> event);
    vector<Event*> getEventsForDay(const time_t& date);
    bool hasConflicts(const Event& newEvent) const;
    void removeEvent(const string& id);
    void displaySchedule(time_t start, time_t end) const;
};
```

Requirements:
1. Handle event scheduling
2. Detect time conflicts
3. Manage attendees
4. Support date ranges
5. Implement notifications
6. Handle timezone issues
7. Support recurring events

### Exercise 3: Inventory System
Create an inventory management system:
```cpp
class Product {
private:
    string sku;
    string name;
    double price;
    int quantity;
    string location;
    
public:
    Product(const string& sku, const string& name);
    void updatePrice(double newPrice);
    bool adjustQuantity(int delta);
    void relocate(const string& newLocation);
    void display() const;
};

class Inventory {
private:
    map<string, unique_ptr<Product>> products;
    vector<string> lowStockAlerts;
    
public:
    void addProduct(unique_ptr<Product> product);
    bool processOrder(const string& sku, int quantity);
    void receiveShipment(const string& sku, int quantity);
    vector<Product*> getLowStockItems(int threshold) const;
    void generateReport() const;
};
```

Requirements:
1. Track inventory levels
2. Process orders
3. Handle shipments
4. Monitor stock levels
5. Generate reports
6. Support multiple locations
7. Implement alerts

## Summary

### Key Concepts

1. **Object Creation**
   ```cpp
   // Stack objects
   MyClass obj1;              // Default
   MyClass obj2(param);       // Parameterized
   
   // Heap objects
   auto ptr = make_unique<MyClass>();  // Smart pointer
   MyClass* raw = new MyClass();       // Raw pointer
   ```

2. **Object Relationships**
   ```cpp
   class Container {
       Component member;      // Composition
       Component* pointer;    // Association
       unique_ptr<Component> owned;  // Ownership
   };
   ```

3. **Object Lifecycle**
   ```cpp
   {
       auto obj = make_unique<Resource>();  // Create
       obj->use();                          // Use
   }  // Automatic cleanup
   ```

### Common Pitfalls

1. **Resource Management**
   ```cpp
   // Wrong: Raw pointer ownership
   class Wrong {
       Resource* ptr = new Resource();  // Who deletes?
   };
   
   // Right: Clear ownership
   class Right {
       unique_ptr<Resource> ptr;  // Automatic cleanup
   };
   ```

2. **Object Access**
   ```cpp
   // Wrong: Direct member access
   obj.private_member = value;
   
   // Right: Use interface
   obj.setValue(value);
   ```

3. **Error Handling**
   ```cpp
   // Wrong: Ignore errors
   void process() {
       obj.riskyOperation();  // Might throw
   }
   
   // Right: Handle errors
   void process() {
       try {
           obj.riskyOperation();
       } catch (const exception& e) {
           // Handle error
       }
   }
   ```

### Best Practices

1. **Object Creation**
   - Use smart pointers
   - Validate constructor parameters
   - Initialize all members
   - Handle construction errors
   - Follow RAII
   - Document requirements
   - Use factory methods

2. **Object Usage**
   - Validate input
   - Handle errors
   - Check state
   - Document behavior
   - Use const correctly
   - Follow interfaces
   - Maintain invariants

3. **Object Relationships**
   - Define clear ownership
   - Use appropriate containers
   - Handle dependencies
   - Manage lifecycles
   - Document relationships
   - Consider coupling
   - Support testing

4. **Error Handling**
   - Validate parameters
   - Check preconditions
   - Handle exceptions
   - Maintain state
   - Clean up resources
   - Document errors
   - Provide feedback

## Next Steps
1. Complete practice exercises
2. Test with various scenarios
3. Handle edge cases
4. Review error handling
5. Move on to [Module 6: Core OOP Concepts - Encapsulation]({{ site.baseurl }}/tutorials/module6)

Remember: Objects are the building blocks of object-oriented programs. Design them carefully with clear responsibilities and well-defined interfaces, and always ensure proper resource management and error handling.
