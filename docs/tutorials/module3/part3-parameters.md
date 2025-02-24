---
layout: default
title: Part 3 - Function Parameters and Return Values
nav_order: 3
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part3-parameters/
---

# Part 3: Function Parameters and Return Values

## Learning Objectives
- Master different parameter passing methods
- Understand value vs. reference parameters
- Learn when to use const parameters
- Practice parameter type selection
- Implement error handling with parameters
- Master return value management

## Introduction
Function parameters and return values are essential mechanisms for making functions flexible and reusable. Think of them like:

1. **Parameters as Input Ports**:
   - Like plugs on a device
   - Accept different types of data
   - Configure function behavior
   - Enable function flexibility
   - Allow code reuse

2. **Return Values as Output Ports**:
   - Provide results back to caller
   - Share computed values
   - Indicate success/failure
   - Enable function chaining
   - Support error handling

3. **Real-World Applications**:
   - Calculator functions with number parameters
   - String processing with text parameters
   - Database queries with search parameters
   - Graphics functions with coordinate parameters
   - Network functions with connection parameters

## Implementation Guide

You'll find the starter code in `Tutorials/Module03/Part3/parameters_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module03/Part3/parameters.cpp`.

### Step 1: Value Parameters
Value parameters create a copy of the argument:

```cpp
// Function declarations
void modifyValue(int num);
void modifyArray(int arr[], int size);
void modifyString(string text);

int main() {
    int number = 5;
    modifyValue(number);     // number stays 5
    
    int array[] = {1, 2, 3};
    modifyArray(array, 3);   // array is modified
    
    string text = "Hello";
    modifyString(text);      // text stays "Hello"
    
    return 0;
}

// Function definitions
void modifyValue(int num) {
    num *= 2;  // Only modifies local copy
}

void modifyArray(int arr[], int size) {
    // Arrays are passed by reference by default
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

void modifyString(string text) {
    text += " World";  // Only modifies local copy
}
```

Key Points:
- Value parameters create copies
- Changes don't affect original
- Arrays are special case
- Good for small data types
- Protects original data

### Step 2: Reference Parameters
Reference parameters provide direct access to the original argument:

```cpp
// Function declarations
void modifyByReference(int& num);
void getMinMax(const vector<int>& numbers, int& min, int& max);
void swapValues(int& a, int& b);

int main() {
    int number = 10;
    modifyByReference(number);  // number becomes 20
    
    vector<int> nums = {3, 7, 1, 9, 4};
    int min, max;
    getMinMax(nums, min, max);  // min=1, max=9
    
    int x = 5, y = 10;
    swapValues(x, y);  // x=10, y=5
    
    return 0;
}

// Function definitions
void modifyByReference(int& num) {
    num *= 2;  // Modifies original value
}

void getMinMax(const vector<int>& numbers, int& min, int& max) {
    if (numbers.empty()) {
        min = max = 0;
        return;
    }
    
    min = max = numbers[0];
    for (int num : numbers) {
        if (num < min) min = num;
        if (num > max) max = num;
    }
}

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Key Points:
- References modify original
- More efficient for large objects
- Can return multiple values
- Must be initialized
- Can't be null

### Step 3: Const Parameters
Const parameters prevent modification of arguments:

```cpp
// Function declarations
double calculateAverage(const vector<int>& numbers);
void printDetails(const string& name, const int& age);
bool searchValue(const int arr[], int size, int target);

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Average: " << calculateAverage(nums) << endl;
    
    printDetails("Alice", 25);
    
    int arr[] = {10, 20, 30, 40, 50};
    cout << "Found 30: " << (searchValue(arr, 5, 30) ? "Yes" : "No") << endl;
    
    return 0;
}

// Function definitions
double calculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) return 0.0;
    
    double sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

void printDetails(const string& name, const int& age) {
    cout << "Name: " << name << ", Age: " << age << endl;
}

bool searchValue(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}
```

Key Points:
- Prevents accidental changes
- Compiler enforces protection
- More efficient than copies
- Clear code intent
- Better error prevention

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part3/practice_parameters_starter.cpp`
- Complete solution: `Tutorials/Module03/Part3/practice_parameters.cpp`

### Exercise 1: Student Grade Calculator
Create a grade management system:

```cpp
struct Student {
    string name;
    vector<double> grades;
};

void addGrade(Student& student, double grade);
double calculateAverage(const Student& student);
char getLetterGrade(double average);
void printStudentReport(const Student& student);
```

Requirements:
1. Validate grades (0-100)
2. Calculate accurate average
3. Convert to letter grades
4. Format output clearly
5. Handle empty grade lists

### Exercise 2: Array Operations
Implement array manipulation functions:

```cpp
void fillArray(int arr[], int size);
void modifyArray(int arr[], int size, int multiplier);
int findMax(const int arr[], int size);
void printArray(const int arr[], int size);
```

Requirements:
1. Fill array sequentially
2. Modify all elements
3. Find maximum safely
4. Format output neatly
5. Handle empty arrays

### Exercise 3: String Manipulator
Create string processing functions:

```cpp
void appendText(string& text, const string& suffix);
string wrapInTags(const string& text, const string& tag);
int countOccurrences(const string& text, char target);
void convertCase(string& text, char mode);
```

Requirements:
1. Append text efficiently
2. Create HTML tags
3. Count characters accurately
4. Handle case conversion
5. Process empty strings

## Summary

### Key Concepts

1. **Value Parameters**
   - Creates copy of argument
   - Changes don't affect original
   - Good for small data types

   ```cpp
   void modifyValue(int x) {
       x = x * 2;  // Only changes local copy
   }

   int num = 10;
   modifyValue(num);  // num still equals 10
   ```

2. **Reference Parameters**
   - Direct access to original data
   - Changes affect original value
   - More efficient for large objects

   ```cpp
   void modifyReference(string& text) {
       text += " modified";  // Changes original
   }

   string msg = "Hello";
   modifyReference(msg);  // msg is now "Hello modified"
   ```

3. **Const Parameters**
   - Prevents modification of arguments
   - Compiler enforces protection
   - Best for large read-only data

   ```cpp
   void printData(const vector<int>& data) {
       // data.push_back(42);  // Error: can't modify
       for (int value : data) {
           cout << value << " ";
       }
   }
   ```

4. **Multiple Return Values**
   - Use reference parameters
   - Pass by reference for output
   - Document output parameters

   ```cpp
   void getMinMax(const vector<int>& data, 
                 int& min, int& max) {
       if (data.empty()) return;
       min = max = data[0];
       for (int value : data) {
           min = std::min(min, value);
           max = std::max(max, value);
       }
   }
   ```

### Common Pitfalls

1. **Value vs. Reference Confusion**

   ```cpp
   // Wrong: Trying to modify through value
   void increment(int x) {
       x++;  // Doesn't affect original
   }

   // Right: Using reference
   void increment(int& x) {
       x++;  // Modifies original
   }
   ```

2. **Missing Const**

   ```cpp
   // Wrong: Could accidentally modify input
   void printArray(vector<int>& nums) {
       nums[0] = 0;  // Accidental modification
   }

   // Right: Protect with const
   void printArray(const vector<int>& nums) {
       // nums[0] = 0;  // Compiler error
   }
   ```

3. **Array Decay**

   ```cpp
   // Wrong: Size lost in parameter
   void process(int arr[]) {
       int size = sizeof(arr);  // Wrong!
   }

   // Right: Pass size explicitly
   void process(int arr[], int size) {
       // Use size parameter
   }
   ```

### Best Practices

1. **Parameter Selection**
   - Use value for small types
   - Use const reference for large types
   - Use non-const reference to modify
   - Pass arrays with size
   - Use const when possible

2. **Return Values**
   - Return by value for small types
   - Return by const reference for large types
   - Use references for multiple returns
   - Return status for error handling
   - Document return values

3. **Error Handling**
   - Validate all inputs
   - Handle edge cases
   - Return error status
   - Use references for errors
   - Document error conditions

4. **Documentation**
   - Document parameters
   - Specify return values
   - Note modifications
   - List requirements
   - Explain errors

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Review error handling
5. Move on to [Part 4: Call Types]({{ site.baseurl }}/tutorials/module3/part4-call-types)

Remember: Proper parameter and return value management is crucial for creating reliable and maintainable functions. Always consider the most appropriate parameter types and validate all inputs thoroughly.
