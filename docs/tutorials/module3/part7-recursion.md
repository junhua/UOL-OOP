---
layout: default
title: Part 7 - Introduction to Recursion
nav_order: 7
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part7-recursion/
---

# Part 7: Introduction to Recursion

## Learning Objectives
- Master the mechanics and structure of recursive functions in C++
- Analyze the memory implications and stack behavior of recursive calls
- Implement base cases to ensure proper recursion termination
- Compare iterative and recursive solutions for efficiency and readability
- Debug common recursion issues including infinite recursion and stack overflow
- Apply recursion to solve complex problems in data structures and algorithms
- Optimize recursive solutions using techniques like memoization and tail recursion
- Evaluate when recursion is appropriate versus iterative approaches

## Introduction
Recursion is a powerful programming technique where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems. Understanding recursion is crucial for solving complex problems elegantly and efficiently.

1. **Recursion Fundamentals**:
   - A function that calls itself directly or indirectly
   - Requires at least one base case to terminate
   - Each recursive call works on a smaller subproblem
   - Builds a call stack during execution
   - Follows a pattern of "divide and conquer"
   - Combines solutions to subproblems to solve the original problem
   - Often expresses solutions in a way that mirrors mathematical definitions

2. **Real-World Parallels**:
   - **Russian Nesting Dolls**: Each doll contains a smaller version of itself until reaching the smallest doll (base case)
   - **Mirrors Facing Each Other**: Creating infinite reflections, each smaller than the previous (without a base case)
   - **Fractal Patterns**: Natural structures like snowflakes, ferns, and coastlines that repeat patterns at different scales
   - **Family Trees**: Each person has parents, who have parents, continuing back generations until reaching ancestors with no known parents
   - **File Systems**: Directories containing files and subdirectories, which may contain more files and subdirectories
   - **Organizational Hierarchies**: Managers supervising employees who may themselves be managers of other employees

3. **Benefits of Recursive Solutions**:
   - **Elegant Code**: Often produces cleaner, more concise solutions
   - **Natural Problem Solving**: Directly maps to problems with recursive structures
   - **Simplified Logic**: Complex problems reduced to simpler subproblems
   - **Mathematical Clarity**: Closely matches mathematical recurrence relations
   - **Divide and Conquer**: Breaks complex problems into manageable pieces
   - **Readability**: Can be more intuitive for certain algorithms
   - **Reduced Complexity**: Simplifies implementation of complex data structures

4. **Industry Applications**:
   - **Compiler Design**: Parsing expressions and syntax trees
   - **Graphics Programming**: Rendering fractals and recursive geometric patterns
   - **Game Development**: Pathfinding algorithms and game tree evaluation
   - **Web Development**: DOM traversal and manipulation
   - **Database Systems**: Hierarchical data queries and tree-structured data
   - **Artificial Intelligence**: Search algorithms and decision trees
   - **Operating Systems**: File system traversal and process management

## Implementation Guide

The `Tutorials/Module03/Part7/Learning/` directory contains starter files to help you learn about recursion:

1. Start with these files:
   - `basic_recursion_starter.cpp`: Simple recursive functions like factorial and Fibonacci
   - `string_recursion_starter.cpp`: String manipulation using recursion
   - `array_recursion_starter.cpp`: Array operations using recursion
   - `advanced_recursion_starter.cpp`: More complex recursive algorithms
   - `optimization_techniques_starter.cpp`: Improving recursive solutions

2. Implementation Steps:
   a. Begin with basic recursion:
      - Implement factorial and Fibonacci functions
      - Understand base cases and recursive cases
      - Trace the execution stack
   
   b. Move to string recursion:
      - Implement string reversal and palindrome checking
      - Work with string slicing in recursive calls
      - Handle edge cases
   
   c. Explore array recursion:
      - Implement array sum and search functions
      - Use recursion with array indices
      - Compare with iterative approaches
   
   d. Tackle advanced recursion:
      - Implement binary search and merge sort
      - Solve tower of Hanoi and other classic problems
      - Analyze recursive complexity

3. Build and Test:
   ```bash
   # Compile your implementation
   g++ -std=c++17 -o recursion basic_recursion_starter.cpp
   
   # Run and verify output
   ./recursion
   ```

4. Learning Progression:
   - Follow TODO comments in each file
   - Test each function as you implement it
   - Compare with example code in documentation
   - Trace recursive calls on paper to understand execution
   
5. Reference Implementation:
   The completed versions are available in the same directory with "_solution" suffix.
   Use these to:
   - Verify your implementation
   - Study recursion patterns
   - Understand memory implications

### Step 1: Basic Recursion

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>
using namespace std;

/**
 * Calculates factorial of a number using recursion
 * 
 * @param n Number to calculate factorial for
 * @return Factorial of n (n!)
 * @throws invalid_argument if n is negative
 */
unsigned long long factorial(int n) {
    // Input validation
    if (n < 0) {
        throw invalid_argument("Factorial not defined for negative numbers");
    }
    
    // Base case
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}

/**
 * Calculates factorial using tail recursion
 * 
 * @param n Number to calculate factorial for
 * @param result Accumulated result (default: 1)
 * @return Factorial of n (n!)
 * @throws invalid_argument if n is negative
 */
unsigned long long factorialTail(int n, unsigned long long result = 1) {
    // Input validation
    if (n < 0) {
        throw invalid_argument("Factorial not defined for negative numbers");
    }
    
    // Base case
    if (n <= 1) {
        return result;
    }
    
    // Recursive case (tail recursion)
    return factorialTail(n - 1, n * result);
}

/**
 * Calculates factorial using iteration
 * 
 * @param n Number to calculate factorial for
 * @return Factorial of n (n!)
 * @throws invalid_argument if n is negative
 */
unsigned long long factorialIterative(int n) {
    // Input validation
    if (n < 0) {
        throw invalid_argument("Factorial not defined for negative numbers");
    }
    
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

/**
 * Calculates Fibonacci number using recursion
 * 
 * @param n Position in Fibonacci sequence (0-based)
 * @return Fibonacci number at position n
 * @throws invalid_argument if n is negative
 */
int fibonacci(int n) {
    // Input validation
    if (n < 0) {
        throw invalid_argument("Fibonacci not defined for negative indices");
    }
    
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Calculates Fibonacci number using memoization
 * 
 * @param n Position in Fibonacci sequence (0-based)
 * @param memo Memoization cache
 * @return Fibonacci number at position n
 */
int fibonacciMemo(int n, vector<int>& memo) {
    // Input validation
    if (n < 0) {
        throw invalid_argument("Fibonacci not defined for negative indices");
    }
    
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Check if already calculated
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Calculate and store result
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

/**
 * Wrapper function for memoized Fibonacci
 * 
 * @param n Position in Fibonacci sequence (0-based)
 * @return Fibonacci number at position n
 */
int fibonacciMemoized(int n) {
    if (n < 0) {
        throw invalid_argument("Fibonacci not defined for negative indices");
    }
    
    vector<int> memo(n + 1, -1);
    return fibonacciMemo(n, memo);
}

/**
 * Calculates Fibonacci number using iteration
 * 
 * @param n Position in Fibonacci sequence (0-based)
 * @return Fibonacci number at position n
 */
int fibonacciIterative(int n) {
    // Input validation
    if (n < 0) {
        throw invalid_argument("Fibonacci not defined for negative indices");
    }
    
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    return curr;
}

/**
 * Measures execution time of a function
 * 
 * @param func Function to measure
 * @param args Arguments to pass to the function
 * @return Pair of result and execution time in milliseconds
 */
template<typename Func, typename... Args>
pair<decltype(declval<Func>()(declval<Args>()...)), double> 
measureTime(Func func, Args... args) {
    auto start = chrono::high_resolution_clock::now();
    auto result = func(args...);
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = end - start;
    return {result, duration.count()};
}

/**
 * Demonstrates recursive function call stack
 * 
 * @param n Current level of recursion
 * @param maxDepth Maximum recursion depth
 */
void demonstrateCallStack(int n, int maxDepth) {
    // Print indentation based on recursion depth
    string indent(n * 2, ' ');
    
    cout << indent << "Enter function call " << n << endl;
    
    // Base case
    if (n >= maxDepth) {
        cout << indent << "Reached max depth, returning" << endl;
        return;
    }
    
    // Recursive case
    cout << indent << "Calling function " << n + 1 << endl;
    demonstrateCallStack(n + 1, maxDepth);
    
    cout << indent << "Returned to function call " << n << endl;
}

int main() {
    try {
        cout << "=== Basic Recursion Examples ===" << endl;
        
        // Factorial examples
        int n = 5;
        cout << "Factorial of " << n << ":" << endl;
        
        auto [factResult, factTime] = measureTime(factorial, n);
        cout << "  Recursive: " << factResult << " (Time: " << factTime << " ms)" << endl;
        
        auto [factTailResult, factTailTime] = measureTime(factorialTail, n);
        cout << "  Tail recursive: " << factTailResult << " (Time: " << factTailTime << " ms)" << endl;
        
        auto [factIterResult, factIterTime] = measureTime(factorialIterative, n);
        cout << "  Iterative: " << factIterResult << " (Time: " << factIterTime << " ms)" << endl;
        
        // Fibonacci examples
        int m = 10;
        cout << "\nFibonacci number at position " << m << ":" << endl;
        
        auto [fibResult, fibTime] = measureTime(fibonacci, m);
        cout << "  Recursive: " << fibResult << " (Time: " << fibTime << " ms)" << endl;
        
        auto [fibMemoResult, fibMemoTime] = measureTime(fibonacciMemoized, m);
        cout << "  Memoized: " << fibMemoResult << " (Time: " << fibMemoTime << " ms)" << endl;
        
        auto [fibIterResult, fibIterTime] = measureTime(fibonacciIterative, m);
        cout << "  Iterative: " << fibIterResult << " (Time: " << fibIterTime << " ms)" << endl;
        
        // Demonstrate larger Fibonacci calculation
        int large = 30;
        cout << "\nLarger Fibonacci calculation (n=" << large << "):" << endl;
        
        // Skip pure recursion for large values as it's too slow
        cout << "  Pure recursion: (skipped - would take too long)" << endl;
        
        auto [largeMemoResult, largeMemoTime] = measureTime(fibonacciMemoized, large);
        cout << "  Memoized: " << largeMemoResult << " (Time: " << largeMemoTime << " ms)" << endl;
        
        auto [largeIterResult, largeIterTime] = measureTime(fibonacciIterative, large);
        cout << "  Iterative: " << largeIterResult << " (Time: " << largeIterTime << " ms)" << endl;
        
        // Demonstrate call stack
        cout << "\n=== Function Call Stack Demonstration ===" << endl;
        demonstrateCallStack(1, 4);
        
        // Test error handling
        cout << "\n=== Error Handling ===" << endl;
        try {
            cout << "Attempting factorial of -1: ";
            factorial(-1);
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
```

Recursion Call Stack Visualization:
```
Function Call Stack for factorial(4):
┌─────────────────────────┐
│ factorial(4)            │
│ return 4*factorial(3)   │◄─┐
└─────────────────────────┘  │
                             │ Call
                             │
┌─────────────────────────┐  │
│ factorial(3)            │◄─┘
│ return 3*factorial(2)   │◄─┐
└─────────────────────────┘  │
                             │ Call
                             │
┌─────────────────────────┐  │
│ factorial(2)            │◄─┘
│ return 2*factorial(1)   │◄─┐
└─────────────────────────┘  │
                             │ Call
                             │
┌─────────────────────────┐  │
│ factorial(1)            │◄─┘
│ return 1                │
└─────────────────────────┘
         │
         │ Return 1
         ▼
┌─────────────────────────┐
│ factorial(2)            │
│ return 2*1 = 2          │
└─────────────────────────┘
         │
         │ Return 2
         ▼
┌─────────────────────────┐
│ factorial(3)            │
│ return 3*2 = 6          │
└─────────────────────────┘
         │
         │ Return 6
         ▼
┌─────────────────────────┐
│ factorial(4)            │
│ return 4*6 = 24         │
└─────────────────────────┘
         │
         │ Return 24
         ▼
       Result: 24
```

Recursion vs. Iteration Comparison:
```
Fibonacci Calculation Methods:
┌───────────────┬────────────────┬────────────────┐
│ Method        │ Time Complexity│ Space Complexity│
├───────────────┼────────────────┼────────────────┤
│ Pure Recursion│ O(2^n)         │ O(n)           │
│ Memoization   │ O(n)           │ O(n)           │
│ Iteration     │ O(n)           │ O(1)           │
└───────────────┴────────────────┴────────────────┘
```

Key Points:
- Every recursive function requires at least one base case to terminate
- Each recursive call should work on a smaller subproblem
- The call stack builds up during recursion and can lead to stack overflow for deep recursion
- Memoization can dramatically improve performance for recursive functions with overlapping subproblems
- Tail recursion can be optimized by some compilers to avoid stack overflow
- Iterative solutions often have better performance but may be less intuitive
- Always include proper error handling in recursive functions

### Step 2: Recursive String Operations

```cpp
#include <iostream>
#include <string>
#include <cctype>
#include <chrono>
using namespace std;

/**
 * Reverses a string using recursion
 * 
 * @param str String to reverse
 * @return Reversed string
 */
string reverseString(const string& str) {
    // Base case
    if (str.length() <= 1) {
        return str;
    }
    
    // Recursive case: first character moves to the end
    return reverseString(str.substr(1)) + str[0];
}

/**
 * Reverses a string using recursion with indices
 * More efficient than the substring version
 * 
 * @param str String to reverse
 * @param start Start index
 * @param end End index
 * @return Reversed string
 */
string reverseStringEfficient(const string& str, int start, int end) {
    // Input validation
    if (start < 0 || end >= str.length() || start > end) {
        return "";
    }
    
    // Base case
    if (start >= end) {
        return string(1, str[start]);
    }
    
    // Recursive case: swap first and last characters
    return str[end] + reverseStringEfficient(str, start, end - 1);
}

/**
 * Wrapper function for efficient string reversal
 * 
 * @param str String to reverse
 * @return Reversed string
 */
string reverseStringWrapper(const string& str) {
    if (str.empty()) {
        return "";
    }
    return reverseStringEfficient(str, 0, str.length() - 1);
}

/**
 * Reverses a string iteratively
 * 
 * @param str String to reverse
 * @return Reversed string
 */
string reverseStringIterative(const string& str) {
    string result = str;
    int left = 0;
    int right = result.length() - 1;
    
    while (left < right) {
        swap(result[left], result[right]);
        left++;
        right--;
    }
    
    return result;
}

/**
 * Checks if a string is a palindrome using recursion
 * 
 * @param str String to check
 * @return true if palindrome, false otherwise
 */
bool isPalindrome(const string& str) {
    // Base case: empty string or single character
    if (str.length() <= 1) {
        return true;
    }
    
    // Check if first and last characters match
    if (str[0] != str[str.length() - 1]) {
        return false;
    }
    
    // Recursive case: check substring without first and last characters
    return isPalindrome(str.substr(1, str.length() - 2));
}

/**
 * Checks if a string is a palindrome using recursion with indices
 * More efficient than the substring version
 * 
 * @param str String to check
 * @param start Start index
 * @param end End index
 * @return true if palindrome, false otherwise
 */
bool isPalindromeEfficient(const string& str, int start, int end) {
    // Base case: empty string or single character
    if (start >= end) {
        return true;
    }
    
    // Check if characters at current positions match
    if (str[start] != str[end]) {
        return false;
    }
    
    // Recursive case: check substring
    return isPalindromeEfficient(str, start + 1, end - 1);
}

/**
 * Wrapper function for efficient palindrome checking
 * 
 * @param str String to check
 * @return true if palindrome, false otherwise
 */
bool isPalindromeWrapper(const string& str) {
    if (str.empty()) {
        return true;
    }
    return isPalindromeEfficient(str, 0, str.length() - 1);
}

/**
 * Checks if a string is a palindrome, ignoring case and non-alphanumeric characters
 * 
 * @param str String to check
 * @param start Start index
 * @param end End index
 * @return true if palindrome, false otherwise
 */
bool isPalindromeIgnoreNonAlphanumeric(const string& str, int start, int end) {
    // Skip non-alphanumeric characters from start
    while (start < end && !isalnum(str[start])) {
        start++;
    }
    
    // Skip non-alphanumeric characters from end
    while (start < end && !isalnum(str[end])) {
        end--;
    }
    
    // Base case: empty string or single character
    if (start >= end) {
        return true;
    }
    
    // Check if characters at current positions match (case insensitive)
    if (tolower(str[start]) != tolower(str[end])) {
        return false;
    }
    
    // Recursive case: check substring
    return isPalindromeIgnoreNonAlphanumeric(str, start + 1, end - 1);
}

/**
 * Wrapper function for advanced palindrome checking
 * 
 * @param str String to check
 * @return true if palindrome, false otherwise
 */
bool isPalindromeAdvanced(const string& str) {
    if (str.empty()) {
        return true;
    }
    return isPalindromeIgnoreNonAlphanumeric(str, 0, str.length() - 1);
}

/**
 * Counts vowels in a string using recursion
 * 
 * @param str String to check
 * @param index Current index
 * @return Number of vowels
 */
int countVowels(const string& str, int index = 0) {
    // Base case: end of string
    if (index >= str.length()) {
        return 0;
    }
    
    // Check if current character is a vowel
    char c = tolower(str[index]);
    int isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
    
    // Recursive case: count vowels in rest of string
    return isVowel + countVowels(str, index + 1);
}

/**
 * Measures execution time of a function
 * 
 * @param func Function to measure
 * @param args Arguments to pass to the function
 * @return Pair of result and execution time in milliseconds
 */
template<typename Func, typename... Args>
pair<decltype(declval<Func>()(declval<Args>()...)), double> 
measureTime(Func func, Args... args) {
    auto start = chrono::high_resolution_clock::now();
    auto result = func(args...);
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = end - start;
    return {result, duration.count()};
}

int main() {
    cout << "=== String Recursion Examples ===" << endl;
    
    // String reversal examples
    string text = "Hello, World!";
    cout << "Original string: \"" << text << "\"" << endl;
    
    auto [reversed1, time1] = measureTime(reverseString, text);
    cout << "Reversed (substring): \"" << reversed1 << "\" (Time: " << time1 << " ms)" << endl;
    
    auto [reversed2, time2] = measureTime(reverseStringWrapper, text);
    cout << "Reversed (efficient): \"" << reversed2 << "\" (Time: " << time2 << " ms)" << endl;
    
    auto [reversed3, time3] = measureTime(reverseStringIterative, text);
    cout << "Reversed (iterative): \"" << reversed3 << "\" (Time: " << time3 << " ms)" << endl;
    
    // Palindrome examples
    cout << "\n=== Palindrome Examples ===" << endl;
    vector<string> testStrings = {
        "radar",
        "hello",
        "A man, a plan, a canal: Panama",
        "Madam, I'm Adam",
        ""
    };
    
    for (const auto& str : testStrings) {
        cout << "String: \"" << str << "\"" << endl;
        
        auto [isPal1, palTime1] = measureTime(isPalindrome, str);
        cout << "  Basic palindrome check: " << (isPal1 ? "Yes" : "No") 
             << " (Time: " << palTime1 << " ms)" << endl;
        
        auto [isPal2, palTime2] = measureTime(isPalindromeWrapper, str);
        cout << "  Efficient palindrome check: " << (isPal2 ? "Yes" : "No") 
             << " (Time: " << palTime2 << " ms)" << endl;
        
        auto [isPal3, palTime3] = measureTime(isPalindromeAdvanced, str);
        cout << "  Advanced palindrome check: " << (isPal3 ? "Yes" : "No") 
             << " (Time: " << palTime3 << " ms)" << endl;
    }
    
    // Vowel counting example
    cout << "\n=== Vowel Counting Example ===" << endl;
    string sentence = "The quick brown fox jumps over the lazy dog";
    cout << "Sentence: \"" << sentence << "\"" << endl;
    cout << "Vowel count: " << countVowels(sentence) << endl;
    
    return 0;
}
```

String Recursion Visualization:
```
Recursive String Reversal Process:
reverseString("Hello")
┌─────────────────────────────────────────┐
│ str = "Hello"                           │
│ str.length() > 1, so recursive case     │
│ return reverseString("ello") + "H"      │
└─────────────────────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────┐
│ str = "ello"                            │
│ str.length() > 1, so recursive case     │
│ return reverseString("llo") + "e"       │
└─────────────────────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────┐
│ str = "llo"                             │
│ str.length() > 1, so recursive case     │
│ return reverseString("lo") + "l"        │
└─────────────────────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────┐
│ str = "lo"                              │
│ str.length() > 1, so recursive case     │
│ return reverseString("o") + "l"         │
└─────────────────────────────────────────┘
                    │

### Step 2: Recursive String Operations

```cpp
#include <iostream>
#include <string>
using namespace std;

// Reverse string using recursion
string reverseString(const string& str) {
    // Base case
    if (str.length() <= 1) return str;
    
    // Recursive case
    return reverseString(str.substr(1)) + str[0];
}

// Check palindrome using recursion
bool isPalindrome(const string& str) {
    // Base cases
    if (str.length() <= 1) return true;
    
    // Recursive case
    if (str[0] != str[str.length()-1]) return false;
    return isPalindrome(str.substr(1, str.length()-2));
}

int main() {
    string text = "Hello";
    cout << "Original: " << text << endl;
    cout << "Reversed: " << reverseString(text) << endl;
    
    string palindrome = "radar";
    cout << "Is " << palindrome << " palindrome? " 
         << (isPalindrome(palindrome) ? "Yes" : "No") << endl;
    
    return 0;
}
```

### Step 3: Advanced Recursion

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Binary search using recursion
int binarySearch(const vector<int>& arr, int target, int left, int right) {
    // Base case: not found
    if (left > right) return -1;
    
    // Calculate middle point
    int mid = left + (right - left) / 2;
    
    // Base case: found
    if (arr[mid] == target) return mid;
    
    // Recursive cases
    if (arr[mid] > target) {
        return binarySearch(arr, target, left, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, right);
    }
}

// Power calculation using recursion
double power(double base, int exponent) {
    // Base cases
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    if (exponent < 0) return 1.0 / power(base, -exponent);
    
    // Recursive case: use divide and conquer
    double half = power(base, exponent / 2);
    if (exponent % 2 == 0) {
        return half * half;
    } else {
        return base * half * half;
    }
}

int main() {
    // Test binary search
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    int index = binarySearch(arr, target, 0, arr.size() - 1);
    cout << target << " found at index: " << index << endl;
    
    // Test power function
    double base = 2.0;
    int exp = 3;
    cout << base << " raised to " << exp << " = " 
         << power(base, exp) << endl;
    
    return 0;
}
```

## Practice Exercises

You'll find the starter code and solutions in:
- Starter template: `Tutorials/Module03/Part7/practice_recursion_starter.cpp`
- Complete solution: `Tutorials/Module03/Part7/practice_recursion.cpp`

### Exercise 1: Number Operations

```cpp
// TODO: Implement these recursive functions
int sumDigits(int n);              // Sum of digits
int countDigits(int n);            // Count digits
bool isPrime(int n, int divisor);  // Check prime
int gcd(int a, int b);            // Greatest common divisor
```

Requirements:
1. Use recursion
2. Handle negative numbers
3. Include base cases
4. Validate inputs
5. Handle edge cases

### Exercise 2: Array Operations

```cpp
// TODO: Implement these recursive functions
int arraySum(const int arr[], int size);     // Sum elements
int findMax(const int arr[], int size);      // Find maximum
bool isSorted(const int arr[], int size);    // Check if sorted
void reverseArray(int arr[], int start, int end);  // Reverse array
```

Requirements:
1. Use recursion
2. Handle empty arrays
3. Process array portions
4. Maintain original data
5. Optimize operations

### Exercise 3: Tree Operations

```cpp
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

// TODO: Implement these recursive functions
int treeHeight(TreeNode* root);              // Calculate height
int countNodes(TreeNode* root);              // Count nodes
bool isBalanced(TreeNode* root);             // Check if balanced
void printInOrder(TreeNode* root);           // In-order traversal
```

Requirements:
1. Use recursion
2. Handle null nodes
3. Process both subtrees
4. Calculate depths
5. Maintain tree structure

## Summary

### Key Concepts

1. **Recursion Basics**
   ```cpp
   // Basic structure
   returnType recursive(parameters) {
       // Base case
       if (baseCondition) return baseValue;
       
       // Recursive case
       return recursive(smaller problem);
   }
   ```

2. **Base Cases**
   ```cpp
   int factorial(int n) {
       if (n <= 1) return 1;  // Base case
       return n * factorial(n - 1);  // Recursive
   }
   ```

3. **Multiple Recursion**
   ```cpp
   int fibonacci(int n) {
       if (n <= 0) return 0;  // Base case 1
       if (n == 1) return 1;  // Base case 2
       return fibonacci(n-1) + fibonacci(n-2);  // Multiple
   }
   ```

### Common Pitfalls

1. **Missing Base Case**
   ```cpp
   // Wrong: Infinite recursion
   void infinite(int n) {
       cout << n;
       infinite(n - 1);  // No base case!
   }
   
   // Right: With base case
   void finite(int n) {
       if (n < 0) return;  // Base case
       cout << n;
       finite(n - 1);
   }
   ```

2. **Stack Overflow**
   ```cpp
   // Wrong: Too many recursive calls
   int deepRecursion(int n) {
       return deepRecursion(n-1) + 1;  // Stack overflow!
   }
   
   // Right: Limit depth
   int safeRecursion(int n, int depth = 0) {
       if (depth > 1000) throw overflow_error("Too deep");
       if (n <= 0) return 0;
       return safeRecursion(n-1, depth+1) + 1;
   }
   ```

3. **Inefficient Recursion**
   ```cpp
   // Wrong: Redundant calculations
   int badFib(int n) {
       if (n <= 1) return n;
       return badFib(n-1) + badFib(n-2);  // Recalculates
   }
   
   // Right: Use helper with memoization
   int goodFib(int n, vector<int>& memo) {
       if (n <= 1) return n;
       if (memo[n] != -1) return memo[n];
       memo[n] = goodFib(n-1, memo) + goodFib(n-2, memo);
       return memo[n];
   }
   ```

### Best Practices

1. **Always Have Base Case**
   ```cpp
   int sum(int n) {
       if (n <= 0) return 0;  // Clear base case
       return n + sum(n - 1);
   }
   ```

2. **Progress Toward Base Case**
   ```cpp
   void countdown(int n) {
       if (n <= 0) return;
       cout << n << " ";
       countdown(n - 1);  // Gets closer to base
   }
   ```

3. **Consider Stack Space**
   ```cpp
   // Use tail recursion when possible
   int factorial_tail(int n, int result = 1) {
       if (n <= 1) return result;
       return factorial_tail(n - 1, n * result);
   }
   ```

## Next Steps
1. Complete practice exercises
2. Test with various inputs
3. Handle edge cases
4. Review error handling
5. Study more advanced recursion topics

Remember: Recursion is a powerful tool but should be used judiciously. Always ensure your recursive functions have proper base cases and make progress toward them.
