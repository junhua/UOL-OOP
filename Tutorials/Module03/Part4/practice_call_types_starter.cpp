#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

// TODO: Implement Bank Account System
struct BankAccount {
    string accountNumber;
    double balance;
    vector<string> transactions;
};

void deposit(BankAccount& account, double amount) {
    // Your code here
}

bool withdraw(BankAccount& account, double amount) {
    // Your code here
    return false;
}

void displayBalance(const BankAccount& account) {
    // Your code here
}

void addTransaction(BankAccount& account, const string& description) {
    // Your code here
}

// TODO: Implement Text Processing System
void processText(const string& input, string& output) {
    // Your code here
}

int countWords(const string& text) {
    // Your code here
    return 0;
}

void convertCase(string& text, char mode) {
    // Your code here
}

void findAndReplace(string& text, const string& find, 
                   const string& replace) {
    // Your code here
}

// TODO: Implement Data Analysis System
struct DataSet {
    vector<double> values;
    double mean;
    double median;
    double standardDev;
};

void calculateStats(DataSet& data) {
    // Your code here
}

void addValue(DataSet& data, double value) {
    // Your code here
}

void removeValue(DataSet& data, int index) {
    // Your code here
}

void displayStats(const DataSet& data) {
    // Your code here
}

void testBankAccount() {
    cout << "Bank Account Test" << endl;
    cout << "=================" << endl;
    
    BankAccount account{"ACC001", 0.0, {}};
    
    deposit(account, 1000.0);
    displayBalance(account);
    
    withdraw(account, 500.0);
    displayBalance(account);
    
    withdraw(account, 700.0);  // Should fail
    displayBalance(account);
    
    cout << "\nTransaction History:" << endl;
    for (const string& transaction : account.transactions) {
        cout << transaction << endl;
    }
}

void testTextProcessing() {
    cout << "\nText Processing Test" << endl;
    cout << "===================" << endl;
    
    string input = "Hello, World!";
    string output;
    
    processText(input, output);
    cout << "Processed: " << output << endl;
    
    cout << "Word count: " << countWords(input) << endl;
    
    string text = "Mixed Case Text";
    convertCase(text, 'U');
    cout << "Uppercase: " << text << endl;
    
    text = "Replace this with that";
    findAndReplace(text, "this", "that");
    cout << "Replaced: " << text << endl;
}

void testDataAnalysis() {
    cout << "\nData Analysis Test" << endl;
    cout << "=================" << endl;
    
    DataSet data;
    addValue(data, 10.5);
    addValue(data, 15.2);
    addValue(data, 12.8);
    addValue(data, 8.7);
    addValue(data, 14.3);
    
    displayStats(data);
    
    removeValue(data, 2);
    cout << "\nAfter removing value:" << endl;
    displayStats(data);
}

int main() {
    cout << "Practice Call Types Demo" << endl;
    cout << "======================" << endl;
    
    testBankAccount();
    testTextProcessing();
    testDataAnalysis();
    
    return 0;
}
