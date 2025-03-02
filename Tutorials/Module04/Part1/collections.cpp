#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// Vector examples
void vectorDemo() {
    cout << "Vector Demo" << endl;
    cout << "===========" << endl;
    
    // Create and initialize vector
    vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Add elements
    numbers.push_back(6);
    numbers.push_back(7);
    
    // Access elements
    cout << "First element: " << numbers[0] << endl;
    cout << "Last element: " << numbers.back() << endl;
    
    // Iterate using index
    cout << "Using index: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Iterate using range-based for
    cout << "Using range-based for: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Iterate using iterator
    cout << "Using iterator: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Vector operations
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    
    // Remove last element
    numbers.pop_back();
    cout << "After pop_back(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

// Set examples
void setDemo() {
    cout << "\nSet Demo" << endl;
    cout << "========" << endl;
    
    // Create and initialize set
    set<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Print set (automatically sorted, no duplicates)
    cout << "Set contents: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Insert elements
    numbers.insert(7);
    numbers.insert(3);  // Duplicate, won't be added
    
    cout << "After insertions: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Find element
    auto it = numbers.find(5);
    if (it != numbers.end()) {
        cout << "Found: " << *it << endl;
    }
    
    // Remove element
    numbers.erase(5);
    cout << "After removing 5: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

// Map examples
void mapDemo() {
    cout << "\nMap Demo" << endl;
    cout << "========" << endl;
    
    // Create and initialize map
    map<string, int> scores = {
        {"Alice", 95},
        {"Bob", 87},
        {"Charlie", 92}
    };
    
    // Add/update elements
    scores["David"] = 88;
    scores["Alice"] = 97;  // Updates Alice's score
    
    // Access elements
    cout << "Alice's score: " << scores["Alice"] << endl;
    
    // Check if key exists
    if (scores.count("Bob") > 0) {
        cout << "Bob's score: " << scores["Bob"] << endl;
    }
    
    // Iterate through map
    cout << "All scores:" << endl;
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Remove element
    scores.erase("Charlie");
    
    // Print size
    cout << "Number of scores: " << scores.size() << endl;
}

// Advanced operations
void advancedDemo() {
    cout << "\nAdvanced Operations Demo" << endl;
    cout << "======================" << endl;
    
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Sort vector
    sort(numbers.begin(), numbers.end());
    cout << "Sorted: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Find minimum and maximum
    auto minmax = minmax_element(numbers.begin(), numbers.end());
    cout << "Min: " << *minmax.first << endl;
    cout << "Max: " << *minmax.second << endl;
    
    // Count occurrences
    int count = std::count(numbers.begin(), numbers.end(), 5);
    cout << "Number of 5s: " << count << endl;
    
    // Remove duplicates
    auto newEnd = unique(numbers.begin(), numbers.end());
    numbers.erase(newEnd, numbers.end());
    cout << "After removing duplicates: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    cout << "STL Collections Demo" << endl;
    cout << "==================\n" << endl;
    
    vectorDemo();
    setDemo();
    mapDemo();
    advancedDemo();
    
    return 0;
}
