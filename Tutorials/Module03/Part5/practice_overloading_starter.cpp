#include <iostream>
#include <string>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

// Exercise 1: Calculator Functions
// TODO: Implement calculate for double parameters
// TODO: Implement calculate for int parameters
// TODO: Implement calculate for complex parameters

// Exercise 2: Shape Area Calculator
const double PI = 3.14159265359;

// TODO: Implement calculateArea for circle (radius)
// TODO: Implement calculateArea for rectangle (length, width)
// TODO: Implement calculateArea for triangle/parallelogram (base, height, shape)

// Exercise 3: String Formatter
// TODO: Implement basic format function (removes leading/trailing spaces)
// TODO: Implement format with uppercase option
// TODO: Implement format with width and fill character
// TODO: Implement format with prefix and suffix

int main() {
    try {
        // Test Calculator Functions
        cout << "=== Calculator Functions ===" << endl;
        // TODO: Test different calculator functions
        // - Test integer calculations
        // - Test double calculations
        // - Test complex number calculations
        // - Test error cases (division by zero)

        // Test Shape Area Calculator
        cout << "\n=== Shape Area Calculator ===" << endl;
        // TODO: Test different shape calculations
        // - Calculate circle area
        // - Calculate rectangle area
        // - Calculate triangle area
        // - Calculate parallelogram area
        // - Test error cases (negative dimensions)

        // Test String Formatter
        cout << "\n=== String Formatter ===" << endl;
        string text = "  Hello, World!  ";
        // TODO: Test different string formatting options
        // - Test basic formatting
        // - Test uppercase conversion
        // - Test width and fill
        // - Test prefix and suffix
        // - Test empty string cases

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
