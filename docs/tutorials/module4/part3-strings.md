---
layout: default
title: Part 3 - Strings
nav_order: 3
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part3-strings/
---

# Part 3: Strings

## Learning Objectives
- Master C-style string operations
- Understand std::string functionality
- Learn string conversion techniques
- Practice string manipulation
- Implement string processing
- Handle string-related errors

## Introduction
C++ provides two main ways to work with strings: C-style strings and the std::string class. Think of them like:

1. **Why String Types Matter**:
   - **C-style Strings**: Legacy compatibility, low-level control
   - **std::string**: Modern features, safety, convenience
   - **Type Choice**: Performance vs. functionality trade-offs
   - **Memory Management**: Manual vs. automatic
   - **Safety Features**: Bounds checking, dynamic sizing

2. **Real-World Applications**:
   - **Text Processing**: Document handling
   - **User Input**: Form validation
   - **File Operations**: Path manipulation
   - **Network Programming**: Protocol parsing
   - **Data Formatting**: Output generation

3. **Benefits in Development**:
   - **Code Clarity**: Expressive string operations
   - **Safety**: Automatic memory management
   - **Flexibility**: Dynamic string handling
   - **Performance**: Optimized implementations
   - **Compatibility**: Multiple string types

## Implementation Guide

You'll find the starter code in `Tutorials/Module04/Part3/strings_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module04/Part3/strings.cpp`.

### Step 1: C-style Strings
```cpp
#include <cstring>

// String declaration
char str1[] = "Hello";
char str2[20] = "World";
const char* str3 = "Constant";

// String length
size_t len = strlen(str1);
cout << "Length: " << len << endl;

// String copy
char dest[20];
strcpy(dest, str1);
cout << "Copy: " << dest << endl;

// String concatenation
strcat(dest, " ");
strcat(dest, str2);
cout << "Combined: " << dest << endl;

// String comparison
if (strcmp(str1, str2) == 0) {
    cout << "Strings are equal" << endl;
}

// Character array manipulation
for (int i = 0; str1[i] != '\0'; i++) {
    str1[i] = toupper(str1[i]);
}
```

Key Points:
- Null termination required
- Fixed buffer size
- Manual memory management
- No bounds checking
- Direct memory access

### Step 2: std::string Class
```cpp
#include <string>

// String creation
string str1 = "Hello";
string str2("World");
string str3(5, '*');  // *****

// String concatenation
string result = str1 + " " + str2;
str1 += " there";

// String length and capacity
cout << "Length: " << str1.length() << endl;
cout << "Capacity: " << str1.capacity() << endl;

// Substring operations
string sub = str1.substr(0, 5);

// Find operations
size_t pos = str1.find("World");
if (pos != string::npos) {
    cout << "Found at: " << pos << endl;
}

// Character access
char first = str1[0];
str1[0] = 'h';  // Modify character

// Insert and erase
str1.insert(5, "!");
str1.erase(5, 1);
```

Key Points:
- Dynamic size management
- Safe operations
- Rich functionality
- Iterator support
- Exception safety

### Step 3: String Conversion
```cpp
// C-string to std::string
const char* cstr = "Hello C++";
string stdstr(cstr);

// std::string to C-string
const char* back_to_cstr = stdstr.c_str();

// Number to string
int num = 42;
string num_str = to_string(num);

// String to number
string value = "123.45";
double number = stod(value);

// Character case conversion
string text = "Hello";
transform(text.begin(), text.end(), text.begin(), ::toupper);
```

Key Points:
- Safe conversion methods
- Type checking
- Error handling
- Format control
- Memory safety

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module04/Part3/practice_strings_starter.cpp`
- Complete solution: `Tutorials/Module04/Part3/practice_strings.cpp`

### Exercise 1: Text Analyzer
Create a text analysis system:
```cpp
class TextAnalyzer {
private:
    string text;
public:
    TextAnalyzer(const string& input);
    int countWords() const;
    int countChar(char target) const;
    string getWord(int position) const;
    void replaceWord(const string& old, const string& newWord);
};
```

Requirements:
1. Count words accurately
2. Handle case sensitivity
3. Support word extraction
4. Implement replacement
5. Handle empty text

### Exercise 2: Password Validator
Implement a password validation system:
```cpp
class PasswordValidator {
public:
    static bool isStrong(const string& password);
    static int getStrengthScore(const string& password);
    static vector<string> getSuggestions(const string& password);
};
```

Requirements:
1. Check minimum length
2. Verify character types
3. Calculate strength score
4. Provide improvement suggestions
5. Handle edge cases

### Exercise 3: URL Parser
Build a URL parsing system:
```cpp
class URLParser {
private:
    string protocol;
    string domain;
    string path;
    string query;
public:
    bool parse(const string& url);
    string getProtocol() const;
    string getDomain() const;
    string getPath() const;
    string getQueryParam(const string& param) const;
};
```

Requirements:
1. Parse URL components
2. Handle query parameters
3. Validate URL format
4. Support various schemes
5. Handle malformed URLs

## Summary

### Key Concepts

1. **C-style Strings**
   ```cpp
   char str[];              // Character array
   strlen(), strcpy()       // String operations
   strcat(), strcmp()      // More operations
   NULL termination        // End marker
   Fixed size buffers      // Size management
   ```

2. **std::string**
   ```cpp
   string str;             // String object
   length(), capacity()    // Size operations
   substr(), find()       // String operations
   operator+, operator+=   // Concatenation
   [], at()               // Access operations
   ```

3. **String Conversion**
   ```cpp
   c_str()                // To C-string
   string(char*)          // From C-string
   to_string()           // To string
   stoi(), stod()        // From string
   ```

### Common Pitfalls

1. **Buffer Overflow**
   ```cpp
   // Wrong: No bounds check
   char str[5];
   strcpy(str, "Too long!");
   
   // Right: Use strncpy
   strncpy(str, "OK", sizeof(str));
   ```

2. **Null Termination**
   ```cpp
   // Wrong: Missing null
   char str[5] = {'H','e','l','l','o'};
   
   // Right: Include null
   char str[6] = {'H','e','l','l','o','\0'};
   ```

3. **String Modification**
   ```cpp
   // Wrong: Modifying string literal
   char* str = "Hello";
   str[0] = 'h';  // Undefined behavior
   
   // Right: Use array
   char str[] = "Hello";
   str[0] = 'h';  // OK
   ```

### Best Practices

1. **String Choice**
   - Use std::string by default
   - Use C-strings for APIs
   - Consider string_view
   - Document string requirements
   - Handle empty strings

2. **Memory Management**
   - Check buffer sizes
   - Use string capacity
   - Avoid fixed buffers
   - Handle allocation
   - Clean up resources

3. **String Operations**
   - Validate inputs
   - Check string lengths
   - Handle edge cases
   - Use safe functions
   - Document assumptions

4. **Error Handling**
   - Check operations
   - Handle exceptions
   - Validate formats
   - Report errors
   - Provide feedback

## Next Steps
1. Complete practice exercises
2. Test with various inputs
3. Handle edge cases
4. Review error handling
5. Move on to [Part 4: Common String Operations]({{ site.baseurl }}/tutorials/module4/part4-string-ops)

Remember: Choose the appropriate string type based on your needs. std::string is generally safer and more convenient, but C-style strings might be needed for compatibility or performance.
