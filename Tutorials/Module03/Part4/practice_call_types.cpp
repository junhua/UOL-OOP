#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

// Bank Account System
struct BankAccount {
    string accountNumber;
    double balance;
    vector<string> transactions;
};

void deposit(BankAccount& account, double amount) {
    if (amount <= 0) {
        cout << "Error: Invalid deposit amount" << endl;
        return;
    }
    
    account.balance += amount;
    account.transactions.push_back(
        "Deposit: $" + to_string(amount)
    );
}

bool withdraw(BankAccount& account, double amount) {
    if (amount <= 0) {
        cout << "Error: Invalid withdrawal amount" << endl;
        return false;
    }
    
    if (amount > account.balance) {
        cout << "Error: Insufficient funds" << endl;
        return false;
    }
    
    account.balance -= amount;
    account.transactions.push_back(
        "Withdrawal: $" + to_string(amount)
    );
    return true;
}

void displayBalance(const BankAccount& account) {
    cout << "Account: " << account.accountNumber << endl;
    cout << "Balance: $" << fixed << setprecision(2) 
         << account.balance << endl;
}

void addTransaction(BankAccount& account, const string& description) {
    account.transactions.push_back(description);
}

// Text Processing System
void processText(const string& input, string& output) {
    output = input;
    // Convert to uppercase
    transform(output.begin(), output.end(), 
             output.begin(), ::toupper);
}

int countWords(const string& text) {
    int count = 0;
    bool inWord = false;
    
    for (char c : text) {
        if (isspace(c)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    
    return count;
}

void convertCase(string& text, char mode) {
    if (mode == 'U' || mode == 'u') {
        transform(text.begin(), text.end(), 
                 text.begin(), ::toupper);
    } else if (mode == 'L' || mode == 'l') {
        transform(text.begin(), text.end(), 
                 text.begin(), ::tolower);
    }
}

void findAndReplace(string& text, const string& find, 
                   const string& replace) {
    size_t pos = 0;
    while ((pos = text.find(find, pos)) != string::npos) {
        text.replace(pos, find.length(), replace);
        pos += replace.length();
    }
}

// Data Analysis System
struct DataSet {
    vector<double> values;
    double mean;
    double median;
    double standardDev;
};

void calculateStats(DataSet& data) {
    if (data.values.empty()) {
        data.mean = data.median = data.standardDev = 0;
        return;
    }
    
    // Calculate mean
    double sum = 0;
    for (double value : data.values) {
        sum += value;
    }
    data.mean = sum / data.values.size();
    
    // Calculate median
    vector<double> sorted = data.values;
    sort(sorted.begin(), sorted.end());
    size_t size = sorted.size();
    if (size % 2 == 0) {
        data.median = (sorted[size/2 - 1] + sorted[size/2]) / 2;
    } else {
        data.median = sorted[size/2];
    }
    
    // Calculate standard deviation
    double sumSquares = 0;
    for (double value : data.values) {
        double diff = value - data.mean;
        sumSquares += diff * diff;
    }
    data.standardDev = sqrt(sumSquares / data.values.size());
}

void addValue(DataSet& data, double value) {
    data.values.push_back(value);
    calculateStats(data);
}

void removeValue(DataSet& data, int index) {
    if (index >= 0 && index < data.values.size()) {
        data.values.erase(data.values.begin() + index);
        calculateStats(data);
    }
}

void displayStats(const DataSet& data) {
    cout << "\nData Analysis:" << endl;
    cout << "-------------" << endl;
    cout << "Number of values: " << data.values.size() << endl;
    cout << "Values: ";
    for (double value : data.values) {
        cout << value << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Mean: " << data.mean << endl;
    cout << "Median: " << data.median << endl;
    cout << "Standard Deviation: " << data.standardDev << endl;
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
