---
layout: default
title: Part 4 - "has-a" Relationship vs "is-a" Relationship
nav_order: 4
parent: Module 8 - Core OOP Concepts - Polymorphism
grand_parent: Tutorials
permalink: /tutorials/module8/part4-has-a-vs-is-a/
---

# Part 4: "has-a" Relationship vs "is-a" Relationship

## Learning Objectives
- Understand the difference between "has-a" and "is-a" relationships
- Master when to use composition vs inheritance
- Learn how to implement both relationship types effectively
- Practice designing class hierarchies with appropriate relationships
- Understand the benefits and drawbacks of each approach
- Implement proper memory management with both approaches
- Recognize and avoid common design pitfalls

## Introduction
In object-oriented programming, two fundamental relationships exist between classes: the "is-a" relationship (inheritance) and the "has-a" relationship (composition/aggregation). Understanding when to use each is crucial for good software design.

1. **Why These Relationships Matter**:
   - **Design Clarity**: Express class relationships accurately
   - **Code Organization**: Structure code in a logical, maintainable way
   - **Flexibility**: Choose the right relationship for future changes
   - **Reusability**: Maximize code reuse without tight coupling
   - **Maintainability**: Make code easier to understand and modify

2. **Real-World Parallels**:
   - **"is-a"**: Dog is an Animal, Car is a Vehicle
   - **"has-a"**: Car has an Engine, Library has Books
   - **Biological Classification**: Species inheritance vs organ composition
   - **Organizational Structure**: Department contains employees vs manager is an employee

3. **Benefits in Development**:
   - **Clear Modeling**: Represent real-world relationships accurately
   - **Appropriate Coupling**: Choose the right level of dependency
   - **Design Flexibility**: Select the best approach for each situation
   - **Better Maintenance**: Make future changes easier
   - **Proper Abstraction**: Create the right boundaries between classes

## Understanding "is-a" vs "has-a" Relationships

### "is-a" Relationship (Inheritance)

The "is-a" relationship is implemented through inheritance. It represents a specialization relationship where one class is a specialized type of another.

```cpp
// "is-a" relationship example
class Animal {
public:
    virtual void makeSound() const {
        cout << "Some generic animal sound" << endl;
    }
    
    virtual void move() const {
        cout << "Animal moves" << endl;
    }
};

class Dog : public Animal {  // Dog IS-A Animal
public:
    void makeSound() const override {
        cout << "Woof!" << endl;
    }
    
    void move() const override {
        cout << "Dog runs on four legs" << endl;
    }
};
```

Key characteristics:
- Derived class inherits interface and implementation from base class
- Derived class can be used wherever base class is expected (substitutability)
- Represents specialization or refinement
- Creates a strong coupling between classes
- Changes to base class affect all derived classes

### "has-a" Relationship (Composition/Aggregation)

The "has-a" relationship is implemented through composition or aggregation. It represents a containment relationship where one class contains instances of another class as members.

```cpp
// "has-a" relationship example
class Engine {
public:
    void start() {
        cout << "Engine started" << endl;
    }
    
    void stop() {
        cout << "Engine stopped" << endl;
    }
};

class Car {  // Car HAS-A Engine
private:
    Engine engine;  // Composition
    
public:
    void start() {
        cout << "Car starting..." << endl;
        engine.start();
    }
    
    void stop() {
        cout << "Car stopping..." << endl;
        engine.stop();
    }
};
```

Key characteristics:
- Container class has member variables of the contained class
- Container class delegates to contained class for functionality
- Represents ownership or containment
- Creates a looser coupling between classes
- Changes to contained class have minimal impact on container class

### Composition vs Aggregation

Both composition and aggregation are forms of the "has-a" relationship, but they differ in the strength of the relationship:

1. **Composition** (strong "has-a"):
   - Container owns the contained object
   - Contained object cannot exist independently
   - When container is destroyed, contained object is also destroyed
   - Example: Car has an Engine (engine doesn't exist without the car)

   ```cpp
   class Car {
   private:
       Engine engine;  // Composition - Engine is created/destroyed with Car
   };
   ```

2. **Aggregation** (weak "has-a"):
   - Container uses the contained object
   - Contained object can exist independently
   - When container is destroyed, contained object may continue to exist
   - Example: Library has Books (books can exist without the library)

   ```cpp
   class Library {
   private:
       vector<Book*> books;  // Aggregation - Books exist independently
   
   public:
       void addBook(Book* book) {
           books.push_back(book);
       }
   };
   ```

## When to Use Each Relationship

### Use "is-a" (Inheritance) When:

1. **Specialization**: Derived class is truly a specialized version of base class
2. **Substitutability**: Derived class can be used wherever base class is expected
3. **Interface Sharing**: Derived class needs to inherit interface from base class
4. **Polymorphic Behavior**: You need runtime polymorphism
5. **LSP Compliance**: Liskov Substitution Principle is satisfied

Examples:
- `Rectangle` is a `Shape`
- `SavingsAccount` is an `Account`
- `Manager` is an `Employee`

### Use "has-a" (Composition/Aggregation) When:

1. **Containment**: One class logically contains instances of another
2. **Implementation Reuse**: You want to reuse implementation without inheriting interface
3. **Dynamic Behavior**: You need to change behavior at runtime
4. **Loose Coupling**: You want to minimize dependencies between classes
5. **LSP Violation**: Liskov Substitution Principle would be violated by inheritance

Examples:
- `Car` has an `Engine`
- `Library` has `Books`
- `Department` has `Employees`

### Decision Guide

Use this flowchart to help decide which relationship to use:

```
Start
  |
  v
Is Class A a specialized type of Class B?
  |
  +--Yes--> Does Class A satisfy the Liskov
  |          Substitution Principle for Class B?
  |            |
  |            +--Yes--> Use inheritance (is-a)
  |            |
  |            +--No---> Use composition (has-a)
  |
  +--No---> Does Class A need to contain or use Class B?
               |
               +--Yes--> Is the relationship one of ownership?
               |           |
               |           +--Yes--> Use composition (strong has-a)
               |           |
               |           +--No---> Use aggregation (weak has-a)
               |
               +--No---> Consider if a relationship is needed at all
```

## Implementation Guide

The `Tutorials/Module08/Part4/Learning/` directory contains starter files to help you learn about "is-a" vs "has-a" relationships:

1. Start with these files:
   - `Document_starter.h` and `Document_starter.cpp`: Base class with "has-a" relationships
   - `TextDocument_starter.h` and `TextDocument_starter.cpp`: Derived class with "is-a" relationship
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Document class:
      - Add member variables
      - Implement "has-a" relationship with Author (composition)
      - Implement "has-a" relationship with Formatter (aggregation)
      - Implement methods for document operations
   
   b. Implement Author class:
      - Add member variables
      - Implement methods for author information
   
   c. Implement Formatter class:
      - Add member variables
      - Implement methods for formatting
   
   d. Move to TextDocument class:
      - Implement "is-a" relationship with Document
      - Add specific members
      - Override methods as needed
      - Add TextDocument-specific functionality
   
   e. Complete the main program:
      - Create Document and TextDocument objects
      - Demonstrate both relationship types
      - Show benefits of each approach

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o document_demo main_starter.cpp Document_starter.cpp TextDocument_starter.cpp
   
   # Run and verify output
   ./document_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each relationship type
   - Compare the approaches
   - Use debugger to understand relationship behavior

5. Reference Implementation:
   The completed versions (Document.h, Document.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study relationship patterns
   - Understand best practices

### Step 1: Implementing "has-a" Relationships

```cpp
// Author class for composition relationship
class Author {
private:
    string name;
    string email;
    
public:
    Author(string name, string email)
        : name(name), email(email) {
        cout << "Creating author: " << name << endl;
    }
    
    ~Author() {
        cout << "Destroying author: " << name << endl;
    }
    
    string getName() const { return name; }
    string getEmail() const { return email; }
    
    void displayInfo() const {
        cout << "Author: " << name << " (" << email << ")" << endl;
    }
};

// Formatter class for aggregation relationship
class Formatter {
private:
    string name;
    bool boldSupport;
    bool italicSupport;
    
public:
    Formatter(string name, bool bold = true, bool italic = true)
        : name(name), boldSupport(bold), italicSupport(italic) {
        cout << "Creating formatter: " << name << endl;
    }
    
    ~Formatter() {
        cout << "Destroying formatter: " << name << endl;
    }
    
    string getName() const { return name; }
    
    string formatText(const string& text, bool bold, bool italic) const {
        string result = text;
        
        if (bold && boldSupport) {
            result = "**" + result + "**";
        }
        
        if (italic && italicSupport) {
            result = "_" + result + "_";
        }
        
        return result;
    }
    
    void displayInfo() const {
        cout << "Formatter: " << name << endl;
        cout << "Supports bold: " << (boldSupport ? "Yes" : "No") << endl;
        cout << "Supports italic: " << (italicSupport ? "Yes" : "No") << endl;
    }
};

// Document class with "has-a" relationships
class Document {
private:
    string title;
    string content;
    string creationDate;
    Author author;  // Composition - strong "has-a" relationship
    Formatter* formatter;  // Aggregation - weak "has-a" relationship
    
public:
    Document(string title, string content, string date,
             string authorName, string authorEmail)
        : title(title), content(content), creationDate(date),
          author(authorName, authorEmail), formatter(nullptr) {
        cout << "Creating document: " << title << endl;
    }
    
    virtual ~Document() {
        cout << "Destroying document: " << title << endl;
        // Note: We don't delete formatter because it's an aggregation
    }
    
    // Getters
    string getTitle() const { return title; }
    string getContent() const { return content; }
    string getCreationDate() const { return creationDate; }
    
    // Author methods (delegation to composed object)
    string getAuthorName() const { return author.getName(); }
    string getAuthorEmail() const { return author.getEmail(); }
    void displayAuthorInfo() const { author.displayInfo(); }
    
    // Formatter methods (delegation to aggregated object)
    void setFormatter(Formatter* fmt) { formatter = fmt; }
    Formatter* getFormatter() const { return formatter; }
    
    // Document operations
    virtual void display() const {
        cout << "Document: " << title << endl;
        cout << "Created on: " << creationDate << endl;
        author.displayInfo();
        
        if (formatter) {
            cout << "Formatted with: " << formatter->getName() << endl;
        } else {
            cout << "No formatter set" << endl;
        }
        
        cout << "Content:" << endl;
        cout << content << endl;
    }
    
    virtual string getFormattedContent(bool bold = false, bool italic = false) const {
        if (formatter) {
            return formatter->formatText(content, bold, italic);
        }
        return content;
    }
    
    virtual void appendContent(const string& newContent) {
        content += newContent;
    }
};
```

Test Cases:
```cpp
// Create a formatter
Formatter* markdownFormatter = new Formatter("Markdown");

// Create a document with composition (Author) and aggregation (Formatter)
Document doc("Meeting Notes", "Discussed project timeline.", "2024-02-25",
             "John Doe", "john@example.com");

// Set the formatter (aggregation)
doc.setFormatter(markdownFormatter);

// Display document
doc.display();

// Get formatted content
cout << "Formatted content: " << doc.getFormattedContent(true, false) << endl;

// Clean up
delete markdownFormatter;

Expected Output:
Creating author: John Doe
Creating document: Meeting Notes
Creating formatter: Markdown
Document: Meeting Notes
Created on: 2024-02-25
Author: John Doe (john@example.com)
Formatted with: Markdown
Content:
Discussed project timeline.
Formatted content: **Discussed project timeline.**
Destroying formatter: Markdown
Destroying document: Meeting Notes
Destroying author: John Doe
```

### Step 2: Implementing "is-a" Relationship

```cpp
// TextDocument class with "is-a" relationship to Document
class TextDocument : public Document {  // TextDocument IS-A Document
private:
    string textFormat;  // e.g., "plain", "markdown", "html"
    int wordCount;
    
public:
    TextDocument(string title, string content, string date,
                 string authorName, string authorEmail,
                 string format = "plain")
        : Document(title, content, date, authorName, authorEmail),
          textFormat(format) {
        cout << "Creating text document with format: " << format << endl;
        updateWordCount();
    }
    
    ~TextDocument() override {
        cout << "Destroying text document: " << getTitle() << endl;
    }
    
    // Getters and setters
    string getTextFormat() const { return textFormat; }
    int getWordCount() const { return wordCount; }
    
    void setTextFormat(const string& format) {
        textFormat = format;
        cout << "Changed format to: " << format << endl;
    }
    
    // Override base class methods
    void display() const override {
        Document::display();  // Call base class method
        cout << "Format: " << textFormat << endl;
        cout << "Word count: " << wordCount << endl;
    }
    
    void appendContent(const string& newContent) override {
        Document::appendContent(newContent);  // Call base class method
        updateWordCount();
    }
    
    // TextDocument-specific methods
    void updateWordCount() {
        string content = getContent();
        wordCount = 0;
        bool inWord = false;
        
        for (char c : content) {
            if (isspace(c)) {
                inWord = false;
            } else if (!inWord) {
                inWord = true;
                wordCount++;
            }
        }
    }
    
    string spellCheck() const {
        // Simplified spell check simulation
        return "Spell check completed for '" + getTitle() + "'. No errors found.";
    }
    
    string generateWordFrequency() const {
        return "Word frequency analysis for '" + getTitle() + "' completed.";
    }
};
```

Test Cases:
```cpp
// Create a formatter
Formatter* htmlFormatter = new Formatter("HTML");

// Create a TextDocument (demonstrates "is-a" relationship)
TextDocument textDoc("Project Proposal", "This is a project proposal document.", 
                     "2024-02-25", "Jane Smith", "jane@example.com", "markdown");

// Set the formatter
textDoc.setFormatter(htmlFormatter);

// Display document (polymorphic behavior)
textDoc.display();

// Use TextDocument-specific methods
cout << textDoc.spellCheck() << endl;
cout << "Word count: " << textDoc.getWordCount() << endl;

// Append content and see word count update
textDoc.appendContent(" It contains important information.");
cout << "After append - Word count: " << textDoc.getWordCount() << endl;

// Clean up
delete htmlFormatter;

Expected Output:
Creating author: Jane Smith
Creating document: Project Proposal
Creating text document with format: markdown
Creating formatter: HTML
Document: Project Proposal
Created on: 2024-02-25
Author: Jane Smith (jane@example.com)
Formatted with: HTML
Content:
This is a project proposal document.
Format: markdown
Word count: 6
Spell check completed for 'Project Proposal'. No errors found.
Word count: 6
After append - Word count: 10
Destroying formatter: HTML
Destroying text document: Project Proposal
Destroying document: Project Proposal
Destroying author: Jane Smith
```

### Step 3: Comparing the Relationships

```cpp
// main.cpp
int main() {
    cout << "=== Demonstrating 'has-a' Relationships ===" << endl;
    
    // Create formatters (will be aggregated)
    Formatter* markdownFormatter = new Formatter("Markdown");
    Formatter* htmlFormatter = new Formatter("HTML", true, true);
    
    // Create a Document with composition and aggregation
    Document doc("Meeting Notes", "Discussed project timeline.", "2024-02-25",
                 "John Doe", "john@example.com");
    
    // Demonstrate aggregation - formatter exists independently
    cout << "\nSetting formatter (aggregation):" << endl;
    doc.setFormatter(markdownFormatter);
    
    // Display document with formatter
    cout << "\nDisplaying document:" << endl;
    doc.display();
    
    // Show formatted content
    cout << "\nFormatted content examples:" << endl;
    cout << "Bold: " << doc.getFormattedContent(true, false) << endl;
    cout << "Italic: " << doc.getFormattedContent(false, true) << endl;
    cout << "Bold and Italic: " << doc.getFormattedContent(true, true) << endl;
    
    // Change formatter - demonstrates flexibility of aggregation
    cout << "\nChanging formatter:" << endl;
    doc.setFormatter(htmlFormatter);
    cout << "New formatted content: " << doc.getFormattedContent(true, true) << endl;
    
    cout << "\n=== Demonstrating 'is-a' Relationship ===" << endl;
    
    // Create a TextDocument - demonstrates inheritance
    TextDocument textDoc("Project Proposal", "This is a project proposal document.", 
                         "2024-02-25", "Jane Smith", "jane@example.com", "markdown");
    
    // Set formatter for TextDocument
    textDoc.setFormatter(htmlFormatter);
    
    // Display TextDocument - demonstrates polymorphism
    cout << "\nDisplaying TextDocument (polymorphism):" << endl;
    textDoc.display();
    
    // Use TextDocument-specific methods
    cout << "\nTextDocument-specific functionality:" << endl;
    cout << textDoc.spellCheck() << endl;
    cout << textDoc.generateWordFrequency() << endl;
    
    // Demonstrate polymorphic behavior
    cout << "\nDemonstrating polymorphism:" << endl;
    Document* docPtr = &textDoc;  // Base pointer to derived object
    docPtr->display();  // Calls TextDocument::display()
    
    // Append content and show word count update
    cout << "\nAppending content:" << endl;
    textDoc.appendContent(" It contains important information.");
    cout << "After append - Word count: " << textDoc.getWordCount() << endl;
    
    // Clean up
    cout << "\n=== Cleaning Up ===" << endl;
    delete markdownFormatter;
    delete htmlFormatter;
    
    return 0;
}
```

Expected Output:
```
=== Demonstrating 'has-a' Relationships ===
Creating author: John Doe
Creating document: Meeting Notes
Creating formatter: Markdown
Creating formatter: HTML

Setting formatter (aggregation):

Displaying document:
Document: Meeting Notes
Created on: 2024-02-25
Author: John Doe (john@example.com)
Formatted with: Markdown
Content:
Discussed project timeline.

Formatted content examples:
Bold: **Discussed project timeline.**
Italic: _Discussed project timeline._
Bold and Italic: _**Discussed project timeline.**_

Changing formatter:
New formatted content: _**Discussed project timeline.**_

=== Demonstrating 'is-a' Relationship ===
Creating author: Jane Smith
Creating document: Project Proposal
Creating text document with format: markdown

Displaying TextDocument (polymorphism):
Document: Project Proposal
Created on: 2024-02-25
Author: Jane Smith (jane@example.com)
Formatted with: HTML
Content:
This is a project proposal document.
Format: markdown
Word count: 6

TextDocument-specific functionality:
Spell check completed for 'Project Proposal'. No errors found.
Word frequency analysis for 'Project Proposal' completed.

Demonstrating polymorphism:
Document: Project Proposal
Created on: 2024-02-25
Author: Jane Smith (jane@example.com)
Formatted with: HTML
Content:
This is a project proposal document.
Format: markdown
Word count: 6

Appending content:
After append - Word count: 10

=== Cleaning Up ===
Destroying formatter: Markdown
Destroying formatter: HTML
Destroying text document: Project Proposal
Destroying document: Project Proposal
Destroying author: Jane Smith
Destroying document: Meeting Notes
Destroying author: John Doe
```

### Step 4: Benefits and Drawbacks

#### Benefits of "is-a" (Inheritance):

1. **Interface Inheritance**: Derived classes automatically inherit the interface
2. **Polymorphic Behavior**: Runtime polymorphism through base class pointers
3. **Code Reuse**: Derived classes inherit implementation from base class
4. **Type Relationship**: Clear expression of specialization relationship
5. **LSP Compliance**: When properly designed, supports substitutability

```cpp
// Benefits of "is-a" relationship
void processDocument(Document& doc) {
    // Works with any Document or derived class
    doc.display();
}

Document* doc1 = new Document(...);
Document* doc2 = new TextDocument(...);

processDocument(*doc1);  // Works with Document
processDocument(*doc2);  // Works with TextDocument (polymorphism)
```

#### Drawbacks of "is-a" (Inheritance):

1. **Tight Coupling**: Changes to base class affect all derived classes
2. **Fragile Base Class Problem**: Base class changes can break derived classes
3. **Inflexibility**: Inheritance hierarchy is fixed at compile time
4. **Complexity**: Deep hierarchies can be hard to understand and maintain
5. **LSP Violations**: Improper inheritance can lead to unexpected behavior

```cpp
// Drawbacks of "is-a" relationship
class Base {
public:
    void method() {
        // If this implementation changes, all derived classes are affected
        step1();
        step2();
    }
    
    virtual void step1() { /* ... */ }
    virtual void step2() { /* ... */ }
};
```

#### Benefits of "has-a" (Composition/Aggregation):

1. **Loose Coupling**: Container and contained classes are less dependent
2. **Flexibility**: Relationships can be changed at runtime
3. **Encapsulation**: Implementation details can be hidden
4. **Simplicity**: Easier to understand than complex inheritance hierarchies
5. **Testability**: Components can be tested in isolation

```cpp
// Benefits of "has-a" relationship
class TextProcessor {
private:
    SpellChecker* spellChecker;  // Can be changed at runtime
    
public:
    void setSpellChecker(SpellChecker* checker) {
        spellChecker = checker;
    }
    
    void processText(const string& text) {
        // Delegate to contained object
        spellChecker->check(text);
    }
};
```

#### Drawbacks of "has-a" (Composition/Aggregation):

1. **Delegation Overhead**: Must manually delegate to contained objects
2. **Interface Duplication**: May need to recreate interface of contained objects
3. **Memory Management**: Need to manage lifetime of contained objects
4. **Complexity**: Many contained objects can lead to complex relationships
5. **Performance**: Slight overhead from delegation

```cpp
// Drawbacks of "has-a" relationship
class Car {
private:
    Engine engine;
    Transmission transmission;
    Suspension suspension;
    // Many more components...
    
public:
    // Need to delegate to each component
    void start() { engine.start(); }
    void shift() { transmission.shift(); }
    void adjust() { suspension.adjust(); }
    // Many more delegations...
};
```

## Practice Exercises

The `Tutorials/Module08/Part4/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., Book_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your class relationships
      - Decide between "is-a" and "has-a"
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement all required methods
      - Add proper constructors/destructors
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -o exercise1 main_starter.cpp Book_starter.cpp Library_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand relationship behavior
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Library System

Create a library system with the following classes:
- `Book` (base class)
- `Library` (container class with "has-a" relationship to Book)
- `FictionBook` (derived from Book with "is-a" relationship)
- `NonFictionBook` (derived from Book with "is-a" relationship)

### Exercise 2: Vehicle System

Create a vehicle system with the following classes:
- `Vehicle` (base class)
- `Engine` (component class with "has-a" relationship to Vehicle)
- `Car` (derived from Vehicle with "is-a" relationship)
- `Motorcycle` (derived from Vehicle with "is-a" relationship)

### Exercise 3: Computer System

Create a computer system with the following classes:
- `Computer` (base class)
- `CPU` and `Memory` (component classes with "has-a" relationship to Computer)
- `Laptop` (derived from Computer with "is-a" relationship)
- `Desktop` (derived from Computer with "is-a" relationship)

## Summary

### Key Concepts

1. **"is-a" Relationship**
   - Implemented through inheritance
   - Represents specialization
   - Derived class inherits interface and implementation
   - Enables polymorphic behavior
   - Creates tight coupling

2. **"has-a" Relationship**
   - Implemented through composition or aggregation
   - Represents containment or usage
   - Container class delegates to contained class
   - Provides flexibility at runtime
   - Creates loose coupling

3. **Composition vs Aggregation**
   - Composition: Strong ownership (contained object lifetime tied to container)
   - Aggregation: Weak ownership (contained object can exist independently)
   - Both are forms of "has-a" relationship
   - Choose based on ownership semantics

4. **Relationship Selection**
   - Use "is-a" for true specialization that satisfies LSP
   - Use "has-a" for containment or implementation reuse
   - Consider future changes and flexibility needs
   - Prefer composition over inheritance when in doubt

5. **Design Principles**
   - Single Responsibility Principle
   - Open/Closed Principle
   - Liskov Substitution Principle
   - Interface Segregation Principle
   - Dependency Inversion Principle

### Common Pitfalls

1. **Overusing Inheritance**
   ```cpp
   // Wrong! Inheritance for implementation reuse only
   class Stack : public Vector { };  // Stack is not truly a Vector
   
   // Better: Use composition
   class Stack {
   private:
       Vector elements;  // Stack has-a Vector
   };
   ```

2. **LSP Violations**
   ```cpp
   // Wrong! Violates LSP
   class Rectangle {
       virtual void setWidth(int w) { width = w; }
       virtual void setHeight(int h) { height = h; }
   };
   
   class Square : public Rectangle {
       void setWidth(int w) override {
           width = height = w;  // Changes behavior unexpectedly
       }
   };
   
   // Better: Use composition
   class Square {
   private:
       Rectangle rectangle;  // Square has-a Rectangle
   };
   ```

3. **Deep Inheritance Hierarchies**
   ```cpp
   // Wrong! Too deep, hard to understand
   class A : public B : public C : public D : public E { };
   
   // Better: Flatter hierarchy with composition
   class A : public B {
   private:
       C c;  // Composition
       D d;  // Composition
   };
   ```

4. **Tight Coupling**
   ```cpp
   // Wrong! Tight coupling through inheritance
   class Derived : public Base {
       void method() {
           // Depends on Base implementation details
           internalBaseMethod();
       }
   };
   
   // Better: Loose coupling through composition
   class Client {
   private:
       Service* service;  // Can be changed at runtime
   };
   ```

5. **Memory Management Issues**
   ```cpp
   // Wrong! Unclear ownership
   class Container {
   private:
       Resource* resource;  // Who owns this?
   };
   
   // Better: Clear ownership
   class Container {
   private:
       unique_ptr<Resource> resource;  // Container owns Resource
   };
   ```

### Best Practices
1. Prefer composition over inheritance when in doubt
2. Use inheritance only for true "is-a" relationships
3. Ensure LSP compliance for inheritance
4. Keep inheritance hierarchies shallow
5. Use composition for implementation reuse
6. Use aggregation for loose relationships
7. Be clear about ownership semantics
8. Consider future changes and flexibility
9. Document relationships clearly
10. Test both relationship types thoroughly

## Next Steps
1. Complete all practice exercises
2. Test with various scenarios
3. Review relationship mechanics
4. Study design patterns that use both relationships
5. Apply these concepts to your own projects

Remember: Choosing the right relationship type is crucial for good software design. Take time to analyze your class relationships and select the most appropriate approach for each situation.
