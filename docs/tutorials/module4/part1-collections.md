---
layout: default
title: Part 1 - Vector, Set and Map
nav_order: 1
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part1-collections/
---

# Part 1: Vector, Set and Map

## Learning Objectives
- Master STL container concepts and usage
- Understand container selection criteria
- Learn container operations and iterators
- Practice container manipulation
- Implement efficient container operations
- Handle container-specific errors

## Introduction
STL containers are fundamental building blocks in C++ that provide different ways to store and organize data. Think of them like:

1. **Why Containers Matter**:
   - **Organization**: Store and manage collections of data
   - **Efficiency**: Optimized implementations for different needs
   - **Type Safety**: Compile-time type checking
   - **Standardization**: Consistent interface across containers
   - **Reusability**: Standard algorithms work with all containers

2. **Real-World Applications**:
   - **Vector**: Dynamic arrays, growing collections
   - **Set**: Unique elements, sorted data
   - **Map**: Key-value associations, dictionaries
   - **Container Selection**: Performance trade-offs
   - **Iterator Usage**: Uniform access patterns

3. **Benefits in Development**:
   - **Code Organization**: Clear data structure choice
   - **Performance**: Right container for the job
   - **Maintainability**: Standard interfaces
   - **Flexibility**: Easy container switching
   - **Safety**: Built-in bounds checking

## Implementation Guide

You'll find the starter code in `Tutorials/Module04/Part1/collections_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module04/Part1/collections.cpp`.

### Step 1: Vector Operations
```cpp
#include <vector>

// Create and initialize vector
vector<int> numbers = {1, 2, 3, 4, 5};

// Add elements
numbers.push_back(6);
numbers.push_back(7);

// Access elements
cout << "First: " << numbers[0] << endl;
cout << "Last: " << numbers.back() << endl;

// Iterate using index
for (size_t i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
}

// Range-based loop
for (int num : numbers) {
    cout << num << " ";
}

// Vector operations
cout << "Size: " << numbers.size() << endl;
numbers.pop_back();  // Remove last
```

Key Points:
- Dynamic size management
- Continuous memory storage
- Fast random access
- Efficient end operations
- Iterator support

### Step 2: Set Operations
```cpp
#include <set>

// Create and initialize set
set<string> fruits = {"apple", "banana", "orange"};

// Insert elements
fruits.insert("grape");  // New element
fruits.insert("apple");  // Duplicate ignored

// Check existence
if (fruits.find("banana") != fruits.end()) {
    cout << "Found banana" << endl;
}

// Iterate through set
for (const string& fruit : fruits) {
    cout << fruit << " ";
}

// Set operations
cout << "Size: " << fruits.size() << endl;
fruits.erase("apple");
```

Key Points:
- Unique elements
- Automatic sorting
- Fast search operations
- No duplicates
- Iterator stability

### Step 3: Map Operations
```cpp
#include <map>

// Create and initialize map
map<string, int> scores = {
    {"Alice", 95},
    {"Bob", 87}
};

// Add/update elements
scores["Charlie"] = 92;
scores["Alice"] = 97;  // Updates Alice's score

// Access elements
cout << "Alice's score: " << scores["Alice"] << endl;

// Check key existence
if (scores.find("Bob") != scores.end()) {
    cout << "Bob's score: " << scores["Bob"] << endl;
}

// Iterate through map
for (const auto& pair : scores) {
    cout << pair.first << ": " << pair.second << endl;
}
```

Key Points:
- Key-value pairs
- Unique keys
- Automatic key sorting
- Fast key lookup
- Iterator support

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module04/Part1/practice_collections_starter.cpp`
- Complete solution: `Tutorials/Module04/Part1/practice_collections.cpp`

### Exercise 1: Grade Tracker
Implement a grade tracking system using vector:
```cpp
class GradeTracker {
    vector<double> grades;
public:
    void addGrade(double grade);
    double getAverage() const;
    double getHighest() const;
    double getLowest() const;
    void displayGrades() const;
};
```

Requirements:
1. Validate grade input (0-100)
2. Calculate accurate statistics
3. Handle empty grade list
4. Format output clearly
5. Support grade updates

### Exercise 2: Word Counter
Create a unique word counter using set:
```cpp
class WordCounter {
    set<string> uniqueWords;
public:
    void addWord(const string& word);
    size_t getUniqueWordCount() const;
    bool containsWord(const string& word) const;
    void displayWords() const;
};
```

Requirements:
1. Case-insensitive comparison
2. Handle punctuation
3. Support word lookup
4. Clear word display
5. Efficient storage

### Exercise 3: Phone Directory
Build a phone directory using map:
```cpp
class PhoneDirectory {
    map<string, string> directory;
public:
    void addContact(const string& name, const string& phone);
    bool removeContact(const string& name);
    string getPhoneNumber(const string& name) const;
    void displayContacts() const;
};
```

Requirements:
1. Validate phone numbers
2. Handle name collisions
3. Support contact updates
4. Format display neatly
5. Efficient lookup

## Summary

### Key Concepts

1. **Vector**
   ```cpp
   vector<T>              // Dynamic array
   push_back(), pop_back() // End operations
   [], at()               // Element access
   size(), empty()        // Capacity
   begin(), end()         // Iterators
   ```

2. **Set**
   ```cpp
   set<T>                // Unique sorted elements
   insert(), erase()     // Modification
   find(), count()       // Searching
   size(), empty()       // Capacity
   begin(), end()        // Iterators
   ```

3. **Map**
   ```cpp
   map<K,V>              // Key-value pairs
   [], at()              // Element access
   insert(), erase()     // Modification
   find(), count()       // Searching
   begin(), end()        // Iterators
   ```

### Common Pitfalls

1. **Vector Issues**
   ```cpp
   // Wrong: No bounds checking
   vec[i] = value;  
   
   // Right: Safe access
   vec.at(i) = value;
   ```

2. **Set Problems**
   ```cpp
   // Wrong: Direct modification
   *set.find(value) = newValue;
   
   // Right: Remove and insert
   set.erase(value);
   set.insert(newValue);
   ```

3. **Map Mistakes**
   ```cpp
   // Wrong: Unnecessary lookups
   if (map.find(key) != map.end())
       map[key] = value;
   
   // Right: Single operation
   map[key] = value;
   ```

### Best Practices

1. **Container Selection**
   - Use vector for sequential data
   - Use set for unique elements
   - Use map for key-value pairs
   - Consider performance needs
   - Match container to usage

2. **Memory Management**
   - Reserve vector capacity
   - Clear unused elements
   - Use shrink_to_fit()
   - Monitor container size
   - Handle reallocation

3. **Iterator Usage**
   - Use range-based for
   - Check iterator validity
   - Use const iterators
   - Handle end conditions
   - Maintain iterator safety

4. **Error Handling**
   - Check bounds
   - Validate input
   - Handle duplicates
   - Check container empty
   - Use at() for safety

## Next Steps
1. Complete practice exercises
2. Test with various data types
3. Handle edge cases
4. Review error handling
5. Move on to [Part 2: Arrays]({{ site.baseurl }}/tutorials/module4/part2-arrays)

Remember: Container choice affects program performance and maintainability. Choose containers based on your specific needs and usage patterns.
