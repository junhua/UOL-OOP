#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <regex>
using namespace std;

// String tokenization
void tokenizationDemo() {
    cout << "String Tokenization" << endl;
    cout << "==================" << endl;
    
    string text = "The quick brown fox jumps over the lazy dog";
    
    // Using stringstream
    istringstream iss(text);
    string word;
    cout << "Words using stringstream:" << endl;
    while (iss >> word) {
        cout << word << endl;
    }
    
    // Using strtok-like splitting
    string delimiter = " ";
    size_t pos = 0;
    string token;
    string temp = text;
    cout << "\nWords using manual splitting:" << endl;
    while ((pos = temp.find(delimiter)) != string::npos) {
        token = temp.substr(0, pos);
        cout << token << endl;
        temp.erase(0, pos + delimiter.length());
    }
    cout << temp << endl;  // Last word
}

// String transformation
void transformationDemo() {
    cout << "\nString Transformation" << endl;
    cout << "====================" << endl;
    
    string text = "Hello World! 123";
    
    // To upper case
    string upper = text;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << "Upper case: " << upper << endl;
    
    // To lower case
    string lower = text;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "Lower case: " << lower << endl;
    
    // Remove punctuation
    string noPunct = text;
    noPunct.erase(remove_if(noPunct.begin(), noPunct.end(), ::ispunct),
                  noPunct.end());
    cout << "No punctuation: " << noPunct << endl;
    
    // Remove digits
    string noDigits = text;
    noDigits.erase(remove_if(noDigits.begin(), noDigits.end(), ::isdigit),
                   noDigits.end());
    cout << "No digits: " << noDigits << endl;
}

// String pattern matching
void patternMatchingDemo() {
    cout << "\nPattern Matching" << endl;
    cout << "================" << endl;
    
    string text = "Email: john@example.com, Phone: 123-456-7890";
    
    // Using regex for email
    regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    smatch match;
    if (regex_search(text, match, emailPattern)) {
        cout << "Found email: " << match[0] << endl;
    }
    
    // Using regex for phone number
    regex phonePattern(R"(\d{3}-\d{3}-\d{4})");
    if (regex_search(text, match, phonePattern)) {
        cout << "Found phone: " << match[0] << endl;
    }
    
    // Find all matches
    string text2 = "Numbers: 123, 456, 789, abc";
    regex numberPattern(R"(\d+)");
    cout << "All numbers:" << endl;
    auto begin = sregex_iterator(text2.begin(), text2.end(), numberPattern);
    auto end = sregex_iterator();
    for (auto i = begin; i != end; ++i) {
        cout << i->str() << endl;
    }
}

// String formatting
void formattingDemo() {
    cout << "\nString Formatting" << endl;
    cout << "=================" << endl;
    
    // Using stringstream for formatting
    ostringstream oss;
    
    // Format numbers
    double pi = 3.14159265359;
    oss << fixed << setprecision(2) << pi;
    cout << "Formatted pi: " << oss.str() << endl;
    
    // Padding with zeros
    oss.str("");
    oss.clear();
    oss << setw(5) << setfill('0') << 42;
    cout << "Padded number: " << oss.str() << endl;
    
    // Format table
    vector<pair<string, int>> data = {
        {"Apple", 5},
        {"Banana", 3},
        {"Orange", 4}
    };
    
    cout << "\nFormatted table:" << endl;
    cout << setw(10) << left << "Item" 
         << setw(8) << right << "Count" << endl;
    cout << string(18, '-') << endl;
    
    for (const auto& item : data) {
        cout << setw(10) << left << item.first 
             << setw(8) << right << item.second << endl;
    }
}

// String alignment and justification
void alignmentDemo() {
    cout << "\nString Alignment" << endl;
    cout << "================" << endl;
    
    string text = "Hello";
    int width = 20;
    
    // Left alignment
    cout << "Left   : |" << left << setw(width) << text << "|" << endl;
    
    // Right alignment
    cout << "Right  : |" << right << setw(width) << text << "|" << endl;
    
    // Center alignment
    int padding = (width - text.length()) / 2;
    cout << "Center : |" << string(padding, ' ') << text 
         << string(width - text.length() - padding, ' ') << "|" << endl;
    
    // Custom fill character
    cout << "Custom : |" << setfill('*') << setw(width) << text << "|" << endl;
}

int main() {
    cout << "String Operations Demo" << endl;
    cout << "===================\n" << endl;
    
    tokenizationDemo();
    transformationDemo();
    patternMatchingDemo();
    formattingDemo();
    alignmentDemo();
    
    return 0;
}
