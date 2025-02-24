#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Exercise 1: Number Operations
int sumDigits(int n) {
    // Base case
    if (n == 0) return 0;
    
    // Handle negative numbers
    if (n < 0) n = -n;
    
    // Recursive case
    return (n % 10) + sumDigits(n / 10);
}

int countDigits(int n) {
    // Base case
    if (n == 0) return 0;
    
    // Handle negative numbers
    if (n < 0) n = -n;
    
    // Recursive case
    return 1 + countDigits(n / 10);
}

bool isPrime(int n, int divisor = 2) {
    // Handle special cases
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    
    // Base case
    if (divisor > sqrt(n)) return true;
    
    // Recursive case
    if (n % divisor == 0) return false;
    return isPrime(n, divisor + 1);
}

int gcd(int a, int b) {
    // Handle negative numbers
    a = abs(a);
    b = abs(b);
    
    // Base case
    if (b == 0) return a;
    
    // Recursive case
    return gcd(b, a % b);
}

// Exercise 2: Array Operations
int arraySum(const int arr[], int size) {
    // Base case
    if (size <= 0) return 0;
    
    // Recursive case
    return arr[size-1] + arraySum(arr, size-1);
}

int findMax(const int arr[], int size) {
    // Base cases
    if (size <= 0) throw runtime_error("Empty array");
    if (size == 1) return arr[0];
    
    // Recursive case
    int subMax = findMax(arr, size-1);
    return max(arr[size-1], subMax);
}

bool isSorted(const int arr[], int size) {
    // Base cases
    if (size <= 1) return true;
    
    // Recursive case
    if (arr[size-2] > arr[size-1]) return false;
    return isSorted(arr, size-1);
}

void reverseArray(int arr[], int start, int end) {
    // Base case
    if (start >= end) return;
    
    // Recursive case
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1);
}

// Exercise 3: Tree Operations
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

int countNodes(TreeNode* root) {
    // Base case
    if (root == nullptr) return 0;
    
    // Recursive case
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isBalanced(TreeNode* root) {
    // Base case
    if (root == nullptr) return true;
    
    // Get heights
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    
    // Check balance
    if (abs(leftHeight - rightHeight) > 1) return false;
    
    // Recursive case
    return isBalanced(root->left) && isBalanced(root->right);
}

void printInOrder(TreeNode* root) {
    // Base case
    if (root == nullptr) return;
    
    // Recursive case
    printInOrder(root->left);
    cout << root->value << " ";
    printInOrder(root->right);
}

int main() {
    try {
        // Test Number Operations
        cout << "=== Number Operations ===" << endl;
        int num = 12345;
        cout << "Number: " << num << endl;
        cout << "Sum of digits: " << sumDigits(num) << endl;
        cout << "Count of digits: " << countDigits(num) << endl;
        cout << "Is 17 prime? " << (isPrime(17) ? "Yes" : "No") << endl;
        cout << "GCD of 48 and 18: " << gcd(48, 18) << endl;
        
        // Test Array Operations
        cout << "\n=== Array Operations ===" << endl;
        int arr[] = {1, 2, 3, 4, 5};
        int size = sizeof(arr) / sizeof(arr[0]);
        
        cout << "Array: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
        
        cout << "Sum: " << arraySum(arr, size) << endl;
        cout << "Max: " << findMax(arr, size) << endl;
        cout << "Is sorted? " << (isSorted(arr, size) ? "Yes" : "No") << endl;
        
        reverseArray(arr, 0, size-1);
        cout << "Reversed: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
        
        // Test Tree Operations
        cout << "\n=== Tree Operations ===" << endl;
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        
        cout << "Tree height: " << treeHeight(root) << endl;
        cout << "Node count: " << countNodes(root) << endl;
        cout << "Is balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;
        cout << "Inorder traversal: ";
        printInOrder(root);
        cout << endl;
        
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
