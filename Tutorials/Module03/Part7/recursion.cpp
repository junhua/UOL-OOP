#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Basic recursion examples
int factorial(int n) {
    // Base case
    if (n <= 1) return 1;
    
    // Recursive case
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// String recursion examples
string reverseString(const string& str) {
    // Base case
    if (str.length() <= 1) return str;
    
    // Recursive case
    return reverseString(str.substr(1)) + str[0];
}

bool isPalindrome(const string& str) {
    // Base cases
    if (str.length() <= 1) return true;
    
    // Recursive case
    if (str[0] != str[str.length()-1]) return false;
    return isPalindrome(str.substr(1, str.length()-2));
}

// Array recursion examples
int sumArray(const int arr[], int size) {
    // Base case
    if (size <= 0) return 0;
    
    // Recursive case
    return arr[size-1] + sumArray(arr, size-1);
}

bool isSorted(const int arr[], int size) {
    // Base cases
    if (size <= 1) return true;
    
    // Recursive case
    if (arr[size-2] > arr[size-1]) return false;
    return isSorted(arr, size-1);
}

// Advanced recursion examples
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

// Tree recursion example
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int treeHeight(TreeNode* root) {
    // Base case
    if (root == nullptr) return 0;
    
    // Recursive case
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

void inorderTraversal(TreeNode* root) {
    // Base case
    if (root == nullptr) return;
    
    // Recursive case
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main() {
    // Test basic recursion
    cout << "=== Basic Recursion ===" << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Fibonacci(6): " << fibonacci(6) << endl;
    
    // Test string recursion
    cout << "\n=== String Recursion ===" << endl;
    string text = "Hello";
    cout << "Original: " << text << endl;
    cout << "Reversed: " << reverseString(text) << endl;
    
    string palindrome = "radar";
    cout << "Is " << palindrome << " palindrome? " 
         << (isPalindrome(palindrome) ? "Yes" : "No") << endl;
    
    // Test array recursion
    cout << "\n=== Array Recursion ===" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Array sum: " << sumArray(arr, 5) << endl;
    cout << "Is array sorted? " << (isSorted(arr, 5) ? "Yes" : "No") << endl;
    
    // Test advanced recursion
    cout << "\n=== Advanced Recursion ===" << endl;
    vector<int> sorted = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    cout << target << " found at index: " 
         << binarySearch(sorted, target, 0, sorted.size()-1) << endl;
    
    cout << "2^3 = " << power(2, 3) << endl;
    
    // Test tree recursion
    cout << "\n=== Tree Recursion ===" << endl;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Tree height: " << treeHeight(root) << endl;
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;
    
    // Clean up tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
