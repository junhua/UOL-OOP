---
layout: default
title: Part 3 - Overriding Methods
nav_order: 3
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part3-overriding/
---

# Part 3: Overriding Methods

## Learning Objectives
- Understand method overriding principles
- Distinguish between overriding and overloading
- Master virtual method usage and mechanics
- Learn pure virtual methods and abstract classes
- Practice polymorphic behavior
- Implement proper override syntax
- Document overridden methods effectively
- Understand final methods and preventing overrides

## Introduction
Method overriding is a key mechanism in inheritance that allows derived classes to provide their own implementations of base class methods. Think of it like customizing a standard recipe:

1. **Why Method Overriding Matters**:
   - **Customization**: Adapt behavior for specific types
   - **Polymorphism**: Enable runtime behavior selection
   - **Flexibility**: Modify functionality without changing interface
   - **Extensibility**: Easy to add new behaviors
   - **Code Organization**: Clear behavior hierarchy

2. **Real-World Parallels**:
   - **Recipe Variations**: Base recipe → Custom versions
   - **Vehicle Controls**: Standard interface → Specific implementations
   - **Communication Methods**: Basic protocol → Specific channels
   - **Work Procedures**: General process → Department-specific steps

3. **Benefits in Development**:
   - **Clear Interface**: Common method signatures
   - **Flexible Implementation**: Customized behavior
   - **Runtime Selection**: Dynamic method choice
   - **Code Reuse**: Share common code
   - **Easy Extension**: Add new variations

## Overriding vs. Overloading

These are two different concepts that are often confused:

### Method Overriding
- Occurs in inheritance relationships
- Same method name, same parameters, same return type
- Provides a new implementation in a derived class
- Runtime polymorphism (decided at runtime)
- Requires virtual keyword in base class
- Uses override keyword in derived class

```cpp
class Base {
public:
    virtual void display() { cout << "Base display" << endl; }
};

class Derived : public Base {
public:
    void display() override { cout << "Derived display" << endl; }
};

// Usage:
Base* obj = new Derived();
obj->display();  // Calls Derived::display() - runtime decision
```

### Method Overloading
- Can occur in the same class
- Same method name, different parameters
- Different implementations for different parameter sets
- Compile-time polymorphism (decided at compile time)
- No virtual keyword needed
- No override keyword used

```cpp
class Calculator {
public:
    // Overloaded methods - same name, different parameters
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

// Usage:
Calculator calc;
calc.add(5, 10);       // Calls first version
calc.add(5.5, 10.5);   // Calls second version
calc.add(5, 10, 15);   // Calls third version
```

### Key Differences

| Aspect | Overriding | Overloading |
|--------|------------|-------------|
| Inheritance | Required | Not required |
| Method signature | Must match exactly | Must differ in parameters |
| Return type | Must match (with covariant exceptions) | Can differ |
| Resolution time | Runtime (dynamic binding) | Compile time (static binding) |
| Performance | Slight overhead (vtable lookup) | No overhead |
| Keywords | virtual, override | None |
| Purpose | Polymorphic behavior | Multiple function versions |

## How Virtual Functions Work

### Virtual Function Tables (vtables)

When a class contains virtual functions, the compiler creates a virtual function table (vtable) for that class:

1. **vtable Creation**:
   - Each class with virtual functions has its own vtable
   - The vtable contains pointers to the actual implementations of virtual functions
   - Derived classes get a copy of the base class vtable, with overridden functions updated

2. **Object Structure**:
   - Each object of a class with virtual functions contains a hidden pointer (vptr)
   - This vptr points to the vtable for that object's class
   - The vptr is automatically initialized by the constructor

3. **Function Call Process**:
   - When a virtual function is called through a pointer/reference:
     1. The program follows the vptr to the object's vtable
     2. It looks up the function pointer at the appropriate index
     3. It calls the function that the pointer points to

```
Memory Layout:

+----------------+        +----------------+
| Media Object   |        | Media vtable   |
|----------------|        |----------------|
| vptr  ---------|------->| ~Media()       |
| title          |        | play()         |
| artist         |        | displayInfo()  |
| duration       |        +----------------+
+----------------+

+----------------+        +----------------+
| Song Object    |        | Song vtable    |
|----------------|        |----------------|
| vptr  ---------|------->| ~Song()        |
| title          |        | play()         |
| artist         |        | displayInfo()  |
| duration       |        +----------------+
| genre          |
+----------------+
```

### Performance Considerations

Virtual functions have a small runtime cost:
- Extra memory for the vtable and vptr
- Indirect function call (pointer dereference)
- Potential cache miss when following the vptr

This overhead is usually negligible in modern systems, but can matter in:
- Performance-critical code with millions of calls
- Embedded systems with limited resources
- Cache-sensitive applications

## The 'override' Keyword

The `override` keyword was introduced in C++11 and provides several important benefits:

### 1. Compile-time Error Detection

Without `override`, if you make a mistake in the signature, the compiler treats it as a new method:

```cpp
class Base {
public:
    virtual void process(int value) const { }
};

class Derived : public Base {
public:
    // MISTAKE: Parameter type different, but compiles without error!
    void process(double value) const { }
    
    // MISTAKE: Missing const, but compiles without error!
    void process(int value) { }
};
```

With `override`, the compiler catches these errors:

```cpp
class Derived : public Base {
public:
    // ERROR: Parameter type doesn't match base class
    void process(double value) const override { }
    
    // ERROR: Missing const qualifier
    void process(int value) override { }
    
    // CORRECT: Signature matches exactly
    void process(int value) const override { }
};
```

### 2. Documentation and Readability

The `override` keyword clearly indicates:
- This method is intentionally overriding a base class method
- The method is part of the polymorphic interface
- Changes to the base class might affect this method

### 3. Maintenance Benefits

When the base class changes:
- Methods marked with `override` will cause compile errors if they no longer match
- This prevents subtle bugs when base class interfaces evolve
- Makes refactoring safer and more predictable

## Implementation Guide

The `Tutorials/Module07/Part3/Learning/` directory contains starter files to help you learn about method overriding:

1. Start with these files:
   - `Media_starter.h` and `Media_starter.cpp`: Base class skeleton
   - `Song_starter.h` and `Song_starter.cpp`: Derived class skeleton
   - `main_starter.cpp`: Test program template

2. Implementation Steps:
   a. Begin with Media base class:
      - Add member variables
      - Define virtual methods
      - Create pure virtual methods
   
   b. Move to Song derived class:
      - Add specific members
      - Override virtual methods
      - Add unique functionality
   
   c. Complete the main program:
      - Create Media pointers
      - Test polymorphic behavior
      - Verify proper cleanup

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -o media_demo main_starter.cpp Media_starter.cpp Song_starter.cpp
   
   # Run and verify output
   ./media_demo
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each override implementation
   - Compare with example code
   - Use debugger to understand virtual calls

5. Reference Implementation:
   The completed versions (Media.h, Media.cpp, etc.) are available
   in the Practice directory's solutions. Use these to:
   - Verify your implementation
   - Study override patterns
   - Understand best practices

### Step 1: Virtual Methods

```cpp
class Media {
protected:
    string title;
    string artist;
    int duration;  // in seconds
    bool isPlaying;
    
public:
    Media(string t, string a, int d)
        : title(t), artist(a), duration(d), isPlaying(false) {
        cout << "Creating media: " << title << endl;
    }
    
    virtual ~Media() {
        cout << "Destroying media: " << title << endl;
    }
    
    // Getters
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    int getDuration() const { return duration; }
    bool getIsPlaying() const { return isPlaying; }
    
    // Virtual method with default implementation
    virtual void play() {
        if (!isPlaying) {
            isPlaying = true;
            cout << "Playing: " << title << endl;
        }
    }
    
    virtual void stop() {
        if (isPlaying) {
            isPlaying = false;
            cout << "Stopped: " << title << endl;
        }
    }
    
    // Pure virtual method - must be overridden
    virtual void displayInfo() const = 0;
    
    // Helper method for formatting duration
    string formatDuration() const {
        int minutes = duration / 60;
        int seconds = duration % 60;
        stringstream ss;
        ss << minutes << ":" << setfill('0') << setw(2) << seconds;
        return ss.str();
    }
};
```

Test Cases:
```cpp
// Cannot create Media directly (abstract class)
// Media media("Title", "Artist", 180);  // Error!

// Must use derived class
Media* media = new Song("Title", "Artist", 180, "Pop");
media->play();
media->displayInfo();
media->stop();
delete media;

Expected Output:
Creating media: Title
Creating song: Title from Pop
Playing: Title
♪ Now playing: Title by Artist
Song: Title
Artist: Artist
Genre: Pop
Duration: 3:00
Status: Playing
Stopped: Title
Destroying song: Title
Destroying media: Title
```

### Step 2: Override Implementation

```cpp
class Song : public Media {
private:
    string genre;
    string album;
    
public:
    Song(string title, string artist, int duration, string g, string alb = "")
        : Media(title, artist, duration), genre(g), album(alb) {
        cout << "Creating song: " << title << " from " << genre << endl;
    }
    
    ~Song() override {
        cout << "Destroying song: " << title << endl;
    }
    
    // Getters
    string getGenre() const { return genre; }
    string getAlbum() const { return album; }
    
    // Override with specific behavior
    void play() override {
        Media::play();  // Call base implementation first
        
        if (isPlaying) {
            cout << "♪ Now playing: " << title << " by " << artist << endl;
        }
    }
    
    // Implement pure virtual method
    void displayInfo() const override {
        cout << "Song: " << title << endl;
        cout << "Artist: " << artist << endl;
        
        if (!album.empty()) {
            cout << "Album: " << album << endl;
        }
        
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << formatDuration() << endl;
        cout << "Status: " << (isPlaying ? "Playing" : "Stopped") << endl;
    }
};
```

### Step 3: Complex Polymorphic Behavior

Let's extend our media player with more types and a playlist system:

```cpp
class Video : public Media {
private:
    string resolution;
    bool hasSubtitles;
    
public:
    Video(string title, string artist, int duration, 
          string res, bool subs = false)
        : Media(title, artist, duration), 
          resolution(res), hasSubtitles(subs) {
        cout << "Creating video: " << title << endl;
    }
    
    ~Video() override {
        cout << "Destroying video: " << title << endl;
    }
    
    void play() override {
        Media::play();
        if (isPlaying) {
            cout << "▶ Playing video: " << title 
                 << " (" << resolution << ")" << endl;
            
            if (hasSubtitles) {
                cout << "   Subtitles enabled" << endl;
            }
        }
    }
    
    void displayInfo() const override {
        cout << "Video: " << title << endl;
        cout << "Creator: " << artist << endl;
        cout << "Resolution: " << resolution << endl;
        cout << "Subtitles: " << (hasSubtitles ? "Yes" : "No") << endl;
        cout << "Duration: " << formatDuration() << endl;
        cout << "Status: " << (isPlaying ? "Playing" : "Stopped") << endl;
    }
    
    void toggleSubtitles() {
        hasSubtitles = !hasSubtitles;
        cout << "Subtitles " << (hasSubtitles ? "enabled" : "disabled") 
             << " for " << title << endl;
    }
};

class Podcast : public Media {
private:
    string host;
    int episode;
    
public:
    Podcast(string title, string publisher, int duration,
            string host, int episode)
        : Media(title, publisher, duration),
          host(host), episode(episode) {
        cout << "Creating podcast: " << title << " ep." << episode << endl;
    }
    
    ~Podcast() override {
        cout << "Destroying podcast: " << title << endl;
    }
    
    void play() override {
        Media::play();
        if (isPlaying) {
            cout << "🎙 Playing podcast: " << title 
                 << " episode " << episode << endl;
            cout << "   Hosted by: " << host << endl;
        }
    }
    
    void displayInfo() const override {
        cout << "Podcast: " << title << endl;
        cout << "Publisher: " << artist << endl;
        cout << "Host: " << host << endl;
        cout << "Episode: " << episode << endl;
        cout << "Duration: " << formatDuration() << endl;
        cout << "Status: " << (isPlaying ? "Playing" : "Stopped") << endl;
    }
};

// Playlist to demonstrate complex polymorphic behavior
class Playlist {
private:
    string name;
    vector<Media*> items;
    int currentIndex;
    
public:
    Playlist(string n) : name(n), currentIndex(-1) {
        cout << "Creating playlist: " << name << endl;
    }
    
    ~Playlist() {
        // Note: Playlist doesn't own the media items
        cout << "Destroying playlist: " << name << endl;
    }
    
    void addItem(Media* item) {
        items.push_back(item);
        cout << "Added " << item->getTitle() << " to playlist " << name << endl;
    }
    
    void play() {
        if (items.empty()) {
            cout << "Playlist " << name << " is empty" << endl;
            return;
        }
        
        if (currentIndex == -1) {
            currentIndex = 0;
        }
        
        cout << "Playing playlist: " << name << endl;
        cout << "Track " << (currentIndex + 1) << " of " << items.size() << endl;
        
        // Polymorphic call - different behavior based on actual type
        items[currentIndex]->play();
    }
    
    void next() {
        if (items.empty()) return;
        
        // Stop current item if playing
        if (currentIndex >= 0 && currentIndex < items.size()) {
            items[currentIndex]->stop();
        }
        
        // Move to next item
        currentIndex = (currentIndex + 1) % items.size();
        cout << "Moving to track " << (currentIndex + 1) 
             << " of " << items.size() << endl;
        
        // Play next item
        items[currentIndex]->play();
    }
    
    void displayInfo() const {
        cout << "Playlist: " << name << endl;
        cout << "Items: " << items.size() << endl;
        
        for (size_t i = 0; i < items.size(); i++) {
            cout << (i == currentIndex ? "▶ " : "  ")
                 << (i + 1) << ". " << items[i]->getTitle() 
                 << " (" << items[i]->formatDuration() << ")" << endl;
        }
    }
};
```

### Step 4: Final Methods and Preventing Overrides

C++11 introduced the `final` keyword, which can be used to prevent further overriding:

```cpp
class Base {
public:
    virtual void method1() { cout << "Base::method1" << endl; }
    virtual void method2() { cout << "Base::method2" << endl; }
};

class Derived : public Base {
public:
    // This method cannot be overridden in classes derived from Derived
    void method1() override final { cout << "Derived::method1" << endl; }
    
    void method2() override { cout << "Derived::method2" << endl; }
};

class Further : public Derived {
public:
    // Error! Cannot override final method
    // void method1() override { cout << "Further::method1" << endl; }
    
    // OK - method2 is not final
    void method2() override { cout << "Further::method2" << endl; }
};
```

You can also mark an entire class as final to prevent inheritance:

```cpp
class FinalClass final : public Base {
    // This class cannot be used as a base class
};

// Error! Cannot inherit from final class
// class Attempt : public FinalClass { };
```

When to use `final`:
- To enforce design decisions about inheritance
- To prevent accidental overriding
- To enable compiler optimizations (inlining)
- To ensure security-critical methods aren't modified
- When a class or method has reached its final form

## Practice Exercises

The `Tutorials/Module07/Part3/Practice/` directory contains starter files for three exercises:

1. Exercise Structure:
   Each exercise provides:
   - Starter header file (e.g., Media_starter.h)
   - Main program template (e.g., main_starter.cpp)
   - README.md with detailed instructions
   - Solution files for reference

2. Development Process:
   a. Start with the header file:
      - Read all TODO comments
      - Plan your overrides
      - Define virtual methods
   
   b. Create implementation files:
      - Follow the header file structure
      - Implement all overrides
      - Add proper constructors/destructors
   
   c. Complete the main program:
      - Follow the structured outline in the file
      - Implement each section step by step
      - Test thoroughly after each section

3. Building and Testing:
   ```bash
   # For each exercise:
   g++ -o exercise1 main_starter.cpp Media_starter.cpp Song_starter.cpp
   ./exercise1
   ```

4. Learning Path:
   - Complete exercises in order
   - Each builds on previous concepts
   - Use debugger to understand virtual calls
   - Compare with solutions
   - Test thoroughly

### Exercise 1: Media Player
Create a media player system:

```cpp
// TODO: Implement these classes
class Media;      // Abstract base class
class Song;       // Music files
class Video;      // Video files
class Podcast;    // Audio podcasts
```

### Exercise 2: Game Characters
Implement a game character system:

```cpp
// TODO: Implement these classes
class Character;    // Base character class
class Warrior;      // Combat specialist
class Mage;         // Magic user
class Rogue;        // Stealth specialist
```

### Exercise 3: Drawing System
Create a graphics drawing system:

```cpp
// TODO: Implement these classes
class Drawable;     // Base drawing class
class Rectangle;    // Rectangle shape
class Circle;       // Circle shape
class Triangle;     // Triangle shape
```

## Summary

### Key Concepts

1. **Overriding vs. Overloading**
   - Overriding: Same signature, derived class, runtime polymorphism
   - Overloading: Different parameters, same class, compile-time resolution
   - Different purposes and mechanisms

2. **Virtual Methods**
   - Enable polymorphism
   - Allow runtime selection
   - Support default implementation
   - Require proper declaration
   - Need virtual destructor
   - Use vtables for implementation

3. **Override Keyword Benefits**
   - Compile-time error detection
   - Documentation and readability
   - Maintenance and refactoring safety
   - Prevents subtle bugs

4. **Final Keyword Uses**
   - Prevent further overriding
   - Enforce design decisions
   - Enable compiler optimizations
   - Ensure security-critical methods

5. **Common Patterns**
   - Base class interface
   - Derived class specifics
   - Pure virtual methods
   - Default implementations
   - Template method pattern

### Common Pitfalls

1. **Signature Mismatches**
   ```cpp
   // Wrong! Different parameter type
   class Derived : public Base {
       void method(int x) override { }  // Base uses double
   };
   ```

2. **Missing Override**
   ```cpp
   // Wrong! No override keyword
   class Derived : public Base {
       void method() { }  // Should be marked override
   };
   ```

3. **Const Correctness**
   ```cpp
   // Wrong! Const mismatch
   class Derived : public Base {
       void method() override { }  // Base method is const
   };
   ```

4. **Forgetting Base Class Call**
   ```cpp
   // Wrong! Base functionality lost
   class Derived : public Base {
       void process() override {
           // Forgot to call Base::process()
           // Additional derived functionality
       }
   };
   ```

5. **Slicing Problem**
   ```cpp
   // Wrong! Object slicing
   void processMedia(Media media) {  // Passed by value
       media.play();  // Always calls Media::play()
   }
   
   // Correct
   void processMedia(Media& media) {  // Passed by reference
       media.play();  // Calls appropriate override
   }
   ```

### Best Practices
1. Always use override keyword
2. Match signatures exactly
3. Consider const correctness
4. Document overridden behavior
5. Test polymorphic usage
6. Call base when needed
7. Keep overrides focused
8. Follow LSP principles
9. Use final when appropriate
10. Pass polymorphic objects by reference/pointer

## Next Steps
1. Complete all practice exercises
2. Test with various scenarios
3. Review virtual methods
4. Study polymorphic behavior
5. Move on to [Part 4: Types of Inheritance]({{ site.baseurl }}/tutorials/module7/part4-types)

Remember: Method overriding is key to polymorphic behavior. Take time to understand virtual methods and proper override implementation.
