#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

// Basic array operations
void basicArrayDemo() {
    cout << "Basic Array Operations" << endl;
    cout << "====================" << endl;
    
    // Array declaration and initialization
    int numbers[5] = {1, 2, 3, 4, 5};
    
    // Access elements
    cout << "First element: " << numbers[0] << endl;
    cout << "Last element: " << numbers[4] << endl;
    
    // Modify elements
    numbers[2] = 10;
    
    // Print array
    cout << "Array contents: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Array size
    cout << "Array size: " << sizeof(numbers) / sizeof(numbers[0]) << endl;
}

// Array bounds checking
void boundsCheckingDemo() {
    cout << "\nArray Bounds Checking" << endl;
    cout << "===================" << endl;
    
    // Using std::array for automatic bounds checking
    array<int, 5> numbers = {1, 2, 3, 4, 5};
    
    // Safe access using at()
    try {
        cout << "Element at index 2: " << numbers.at(2) << endl;
        cout << "Element at index 5: " << numbers.at(5) << endl;  // Will throw
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Array size
    cout << "Array size: " << numbers.size() << endl;
}

// Multi-dimensional arrays
void multiDimensionalDemo() {
    cout << "\nMulti-dimensional Arrays" << endl;
    cout << "======================" << endl;
    
    // 2D array declaration and initialization
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Print matrix
    cout << "Matrix contents:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    
    // Access and modify elements
    matrix[1][1] = 0;
    
    // Print modified matrix
    cout << "\nModified matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Array operations
void arrayOperationsDemo() {
    cout << "\nArray Operations" << endl;
    cout << "================" << endl;
    
    int numbers[] = {5, 2, 8, 1, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Find minimum and maximum
    int min = numbers[0];
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
    }
    
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    
    // Calculate sum and average
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    double average = static_cast<double>(sum) / size;
    
    cout << "Sum: " << sum << endl;
    cout << "Average: " << fixed << setprecision(2) << average << endl;
    
    // Reverse array
    for (int i = 0; i < size / 2; i++) {
        int temp = numbers[i];
        numbers[i] = numbers[size - 1 - i];
        numbers[size - 1 - i] = temp;
    }
    
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

// Array searching and sorting
void searchSortDemo() {
    cout << "\nArray Searching and Sorting" << endl;
    cout << "=========================" << endl;
    
    int numbers[] = {5, 2, 8, 1, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Linear search
    int target = 8;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            cout << "Found " << target << " at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << target << " not found" << endl;
    
    // Bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Array Operations Demo" << endl;
    cout << "==================\n" << endl;
    
    basicArrayDemo();
    boundsCheckingDemo();
    multiDimensionalDemo();
    arrayOperationsDemo();
    searchSortDemo();
    
    return 0;
}
