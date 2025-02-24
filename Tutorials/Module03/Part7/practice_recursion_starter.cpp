#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Exercise 1: Number Operations
// TODO: Implement sumDigits function
// - Handle negative numbers
// - Use recursion to sum digits
// - Return total sum

// TODO: Implement countDigits function
// - Handle negative numbers
// - Use recursion to count digits
// - Return digit count

// TODO: Implement isPrime function
// - Handle special cases (0, 1, negative)
// - Use recursion to check divisibility
// - Return true if prime

// TODO: Implement gcd function
// - Handle negative numbers
// - Use Euclidean algorithm recursively
// - Return GCD

// Exercise 2: Array Operations
// TODO: Implement arraySum function
// - Handle empty array
// - Use recursion to sum elements
// - Return total sum

// TODO: Implement findMax function
// - Handle empty array
// - Use recursion to find maximum
// - Return maximum value

// TODO: Implement isSorted function
// - Handle empty array
// - Use recursion to check order
// - Return true if sorted

// TODO: Implement reverseArray function
// - Handle empty array
// - Use recursion to reverse
// - Modify array in place

// Exercise 3: Tree Operations
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// TODO: Implement treeHeight function
// - Handle null nodes
// - Use recursion to find height
// - Return maximum height

// TODO: Implement countNodes function
// - Handle null nodes
// - Use recursion to count nodes
// - Return total count

// TODO: Implement isBalanced function
// - Handle null nodes
// - Check height difference
// - Return true if balanced

// TODO: Implement printInOrder function
// - Handle null nodes
// - Use recursion for inorder traversal
// - Print node values

int main() {
    try {
        // Test Number Operations
        cout << "=== Number Operations ===" << endl;
        int num = 12345;
        cout << "Number: " << num << endl;
        // TODO: Test number operations
        // - Sum of digits
        // - Count of digits
        // - Prime check
        // - GCD calculation
        
        // Test Array Operations
        cout << "\n=== Array Operations ===" << endl;
        int arr[] = {1, 2, 3, 4, 5};
        int size = sizeof(arr) / sizeof(arr[0]);
        
        cout << "Array: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
        
        // TODO: Test array operations
        // - Array sum
        // - Find maximum
        // - Check if sorted
        // - Reverse array
        
        // Test Tree Operations
        cout << "\n=== Tree Operations ===" << endl;
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        
        // TODO: Test tree operations
        // - Calculate height
        // - Count nodes
        // - Check balance
        // - Print inorder traversal
        
        // Clean up tree
        delete root->left->left;
        delete root->left->right;
        delete root->left;
        delete root->right;
        delete root;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
