#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

// Basic string operations
void basicStringDemo() {
    cout << "Basic String Operations" << endl;
    cout << "====================" << endl;
    
    // String creation
    string str1 = "Hello";
    string str2("World");
    string str3(5, '*');  // Creates "*****"
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    
    // String concatenation
    string result = str1 + " " + str2;
    cout << "\nConcatenation: " << result << endl;
    
    // String length
    cout << "Length: " << result.length() << endl;
    cout << "Size: " << result.size() << endl;
    
    // Accessing characters
    cout << "First char: " << result[0] << endl;
    cout << "Last char: " << result.back() << endl;
    
    // Modifying characters
    result[0] = 'h';
    cout << "After modification: " << result << endl;
}

// String comparison and searching
void stringSearchDemo() {
    cout << "\nString Searching" << endl;
    cout << "===============" << endl;
    
    string text = "Hello World! Welcome to C++";
    
    // Find substring
    size_t pos = text.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    }
    
    // Find character
    pos = text.find('!');
    if (pos != string::npos) {
        cout << "'!' found at position: " << pos << endl;
    }
    
    // Find last occurrence
    pos = text.rfind('o');
    if (pos != string::npos) {
        cout << "Last 'o' found at position: " << pos << endl;
    }
    
    // Find first of
    pos = text.find_first_of("aeiou");
    if (pos != string::npos) {
        cout << "First vowel at position: " << pos << endl;
    }
    
    // Find last of
    pos = text.find_last_of("aeiou");
    if (pos != string::npos) {
        cout << "Last vowel at position: " << pos << endl;
    }
}

// String modification
void stringModificationDemo() {
    cout << "\nString Modification" << endl;
    cout << "==================" << endl;
    
    string text = "Hello World";
    
    // Substring
    string sub = text.substr(0, 5);  // "Hello"
    cout << "Substring: " << sub << endl;
    
    // Insert
    text.insert(5, " Beautiful");
    cout << "After insert: " << text << endl;
    
    // Erase
    text.erase(5, 10);  // Remove " Beautiful"
    cout << "After erase: " << text << endl;
    
    // Replace
    text.replace(0, 5, "Hi");
    cout << "After replace: " << text << endl;
    
    // Clear
    text.clear();
    cout << "After clear: " << text << endl;
    cout << "Is empty? " << (text.empty() ? "Yes" : "No") << endl;
}

// String conversion
void stringConversionDemo() {
    cout << "\nString Conversion" << endl;
    cout << "=================" << endl;
    
    // Number to string
    int num = 42;
    string str = to_string(num);
    cout << "Number to string: " << str << endl;
    
    double pi = 3.14159;
    str = to_string(pi);
    cout << "Double to string: " << str << endl;
    
    // String to number
    string numStr = "123";
    int value = stoi(numStr);
    cout << "String to int: " << value << endl;
    
    string doubleStr = "3.14159";
    double dValue = stod(doubleStr);
    cout << "String to double: " << dValue << endl;
    
    // Character case conversion
    string text = "Hello World";
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    cout << "To upper: " << text << endl;
    
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    cout << "To lower: " << text << endl;
}

// String stream operations
void stringStreamDemo() {
    cout << "\nString Stream Operations" << endl;
    cout << "======================" << endl;
    
    // String formatting
    ostringstream oss;
    oss << "Integer: " << 42 << endl;
    oss << "Double: " << fixed << 3.14159 << endl;
    oss << "Boolean: " << boolalpha << true << endl;
    
    string result = oss.str();
    cout << "Formatted string:\n" << result;
    
    // String parsing
    string input = "John 25 180.5";
    istringstream iss(input);
    
    string name;
    int age;
    double height;
    
    iss >> name >> age >> height;
    
    cout << "Parsed data:" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
}

int main() {
    cout << "String Operations Demo" << endl;
    cout << "===================\n" << endl;
    
    basicStringDemo();
    stringSearchDemo();
    stringModificationDemo();
    stringConversionDemo();
    stringStreamDemo();
    
    return 0;
}
