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
- Understand recursion concepts
- Master recursive function structure
- Learn base case importance
- Practice recursive solutions
- Implement recursive algorithms
- Avoid infinite recursion

## Introduction
Recursion is a programming concept where a function calls itself to solve a problem. Think of recursion like:

1. **Real-World Analogies**:
   - Russian nesting dolls
   - Mirrors facing each other
   - Fractal patterns in nature
   - Family tree branches
   - Directory structures

2. **Benefits of Recursion**:
   - Elegant solutions
   - Natural problem solving
   - Simpler code structure
   - Mathematical clarity
   - Divide and conquer approach

3. **Common Applications**:
   - Tree traversal
   - Directory scanning
   - Mathematical calculations
   - Sorting algorithms
   - Graph algorithms

## Implementation Guide

You'll find the starter code in `Tutorials/Module03/Part7/recursion_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module03/Part7/recursion.cpp`.

### Step 1: Basic Recursion

```cpp
#include <iostream>
using namespace std;

// Factorial calculation using recursion
int factorial(int n) {
    // Base case
    if (n <= 1) return 1;
    
    // Recursive case
    return n * factorial(n - 1);
}

// Fibonacci sequence using recursion
int fibonacci(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Test factorial
    cout << "Factorial of 5: " << factorial(5) << endl;
    
    // Test Fibonacci
    cout << "6th Fibonacci number: " << fibonacci(6) << endl;
    
    return 0;
}
```

Key Points:
- Base case required
- Recursive case calls itself
- Problem gets smaller
- Stack builds up
- Eventually reaches base

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
