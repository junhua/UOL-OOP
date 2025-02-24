#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TODO: Implement basic recursion examples
// Factorial calculation
// Fibonacci sequence

// TODO: Implement string recursion examples
// String reversal
// Palindrome check

// TODO: Implement array recursion examples
// Array sum
// Check if sorted

// TODO: Implement advanced recursion examples
// Binary search
// Power calculation

// Tree recursion example
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// TODO: Implement tree recursion examples
// Calculate tree height
// Inorder traversal

int main() {
    // Test basic recursion
    cout << "=== Basic Recursion ===" << endl;
    // TODO: Test factorial
    // TODO: Test fibonacci
    
    // Test string recursion
    cout << "\n=== String Recursion ===" << endl;
    string text = "Hello";
    // TODO: Test string reversal
    // TODO: Test palindrome check
    
    // Test array recursion
    cout << "\n=== Array Recursion ===" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    // TODO: Test array sum
    // TODO: Test sorted check
    
    // Test advanced recursion
    cout << "\n=== Advanced Recursion ===" << endl;
    vector<int> sorted = {1, 3, 5, 7, 9, 11, 13};
    // TODO: Test binary search
    // TODO: Test power function
    
    // Test tree recursion
    cout << "\n=== Tree Recursion ===" << endl;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // TODO: Test tree height
    // TODO: Test inorder traversal
    
    // Clean up tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
