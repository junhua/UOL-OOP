---
layout: default
title: Part 4 - Common String Operations
nav_order: 4
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part4-string-ops/
---

# Part 4: Common String Operations

## Learning Objectives
- Master string manipulation techniques
- Understand string transformation
- Learn string searching methods
- Practice string formatting
- Implement string utilities
- Handle string operation errors

## Introduction
String operations are essential for text processing and data manipulation. Think of them like:

1. **Why String Operations Matter**:
   - **Text Processing**: Content manipulation
   - **Data Validation**: Input verification
   - **Format Conversion**: Data transformation
   - **Search Operations**: Pattern matching
   - **Output Formatting**: Display presentation

2. **Real-World Applications**:
   - **Form Processing**: Input cleaning
   - **Data Parsing**: CSV, JSON handling
   - **Template Systems**: Content generation
   - **Command Processing**: Argument parsing
   - **Text Analysis**: Content statistics

3. **Benefits in Development**:
   - **Code Reusability**: Common operations
   - **Standardization**: Consistent handling
   - **Efficiency**: Optimized methods
   - **Reliability**: Tested operations
   - **Maintainability**: Clear intent

## Implementation Guide

You'll find the starter code in `Tutorials/Module04/Part4/string_ops_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module04/Part4/string_ops.cpp`.

### Step 1: Case Conversion
```cpp
#include <algorithm>

// Convert to uppercase
string upper = text;
transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

// Convert to lowercase
string lower = text;
transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

// Convert first character
string capitalized = text;
if (!capitalized.empty()) {
    capitalized[0] = toupper(capitalized[0]);
}

// Title case
string title = text;
bool newWord = true;
for (char& c : title) {
    if (isspace(c)) {
        newWord = true;
    } else if (newWord) {
        c = toupper(c);
        newWord = false;
    } else {
        c = tolower(c);
    }
}
```

Key Points:
- In-place transformation
- Character-by-character processing
- Case sensitivity handling
- Boundary conditions
- Unicode considerations

### Step 2: String Trimming
```cpp
// Trim left
string leftTrimmed = text;
leftTrimmed.erase(0, leftTrimmed.find_first_not_of(" \t\n\r"));

// Trim right
string rightTrimmed = text;
size_t lastNonSpace = rightTrimmed.find_last_not_of(" \t\n\r");
if (lastNonSpace != string::npos) {
    rightTrimmed.erase(lastNonSpace + 1);
}

// Trim both ends
string trimmed = text;
trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
lastNonSpace = trimmed.find_last_not_of(" \t\n\r");
if (lastNonSpace != string::npos) {
    trimmed.erase(lastNonSpace + 1);
}
```

Key Points:
- Whitespace handling
- Position finding
- String modification
- Empty string handling
- Efficiency considerations

### Step 3: String Splitting and Joining
```cpp
// Split string into words
vector<string> split(const string& text, char delimiter = ' ') {
    vector<string> tokens;
    size_t start = 0;
    size_t end = text.find(delimiter);
    
    while (end != string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
        end = text.find(delimiter, start);
    }
    tokens.push_back(text.substr(start));
    
    return tokens;
}

// Join strings with delimiter
string join(const vector<string>& tokens, const string& delimiter) {
    string result;
    for (size_t i = 0; i < tokens.size(); i++) {
        if (i > 0) result += delimiter;
        result += tokens[i];
    }
    return result;
}
```

Key Points:
- Token extraction
- Delimiter handling
- Empty token handling
- Memory efficiency
- String building

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module04/Part4/practice_string_ops_starter.cpp`
- Complete solution: `Tutorials/Module04/Part4/practice_string_ops.cpp`

### Exercise 1: CSV Parser
Create a CSV file parser:
```cpp
class CSVParser {
private:
    char delimiter;
    vector<string> headers;
    vector<vector<string>> data;
public:
    bool parse(const string& input);
    vector<string> splitLine(const string& line);
    string getField(size_t row, size_t col) const;
    string getField(size_t row, const string& header) const;
};
```

Requirements:
1. Handle quoted fields
2. Support custom delimiters
3. Process header row
4. Handle empty fields
5. Validate CSV format

### Exercise 2: Template Engine
Build a simple template engine:
```cpp
class TemplateEngine {
private:
    map<string, string> variables;
public:
    void setVariable(const string& name, const string& value);
    string process(const string& templateStr);
    bool hasVariable(const string& name) const;
    string getVariable(const string& name) const;
};
```

Requirements:
1. Replace variables
2. Handle missing variables
3. Support nested variables
4. Escape special characters
5. Handle template errors

### Exercise 3: Command Line Parser
Implement a command line argument parser:
```cpp
class CommandLineParser {
private:
    map<string, string> options;
    vector<string> arguments;
public:
    bool parse(const vector<string>& args);
    bool hasOption(const string& name) const;
    string getOption(const string& name, const string& defaultValue = "") const;
    const vector<string>& getArguments() const;
};
```

Requirements:
1. Parse options formats
2. Handle flags
3. Support default values
4. Process arguments
5. Validate input

## Summary

### Key Concepts

1. **Case Conversion**
   ```cpp
   transform()            // STL algorithm
   toupper(), tolower()  // Character conversion
   isspace(), isalpha()  // Character testing
   Case sensitivity      // Comparison modes
   ```

2. **String Trimming**
   ```cpp
   find_first_not_of()  // Left trim
   find_last_not_of()   // Right trim
   erase()             // Remove characters
   Whitespace handling // Multiple types
   ```

3. **Split and Join**
   ```cpp
   find()              // Find delimiter
   substr()           // Extract substring
   push_back()        // Add to vector
   String building    // Efficient joining
   ```

### Common Pitfalls

1. **Case Conversion Issues**
   ```cpp
   // Wrong: Direct modification
   text[i] = toupper(text[i]);
   
   // Right: Use transform
   transform(text.begin(), text.end(), text.begin(), ::toupper);
   ```

2. **Trimming Problems**
   ```cpp
   // Wrong: Only spaces
   text.erase(0, text.find_first_not_of(" "));
   
   // Right: All whitespace
   text.erase(0, text.find_first_not_of(" \t\n\r"));
   ```

3. **Split/Join Errors**
   ```cpp
   // Wrong: No empty token handling
   if (token.empty()) continue;
   
   // Right: Keep empty tokens
   tokens.push_back(token);
   ```

### Best Practices

1. **String Operations**
   - Use standard algorithms
   - Handle edge cases
   - Consider efficiency
   - Document assumptions
   - Test thoroughly

2. **Memory Management**
   - Avoid unnecessary copies
   - Pre-allocate when possible
   - Clear unused memory
   - Monitor string growth
   - Use appropriate methods

3. **Error Handling**
   - Validate input
   - Check boundaries
   - Handle special cases
   - Report errors
   - Maintain consistency

4. **Performance**
   - Choose efficient methods
   - Minimize allocations
   - Use appropriate containers
   - Profile operations
   - Optimize hot paths

## Next Steps
1. Complete practice exercises
2. Test with various inputs
3. Handle edge cases
4. Review error handling
5. Move on to [Module 5: Classes and Objects]({{ site.baseurl }}/tutorials/module5)

Remember: String operations are fundamental to many programming tasks. Choose the right operations for your needs and always consider performance and safety implications.
