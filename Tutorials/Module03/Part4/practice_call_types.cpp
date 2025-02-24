#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

// ===== Exercise 1: Bank Account =====
struct BankAccount {
    string accountHolder;
    double balance;
    vector<string> transactions;
};

// Function declarations
void deposit(BankAccount& account, double amount);
bool withdraw(BankAccount& account, double amount);
void displayBalance(const BankAccount& account);
void addTransaction(BankAccount& account, const string& transaction);
double calculateInterest(const BankAccount& account, double rate);

// ===== Exercise 2: Text Processor =====
// Function declarations
void tokenizeText(const string& text, vector<string>& words);
void sortWords(vector<string>& words);
int countUniqueWords(const vector<string>& words);
void displayStats(const vector<string>& words);
string joinWords(const vector<string>& words, const string& delimiter);

// ===== Exercise 3: Data Analysis =====
struct DataPoint {
    double value;
    string label;
    bool isValid;
};

// Function declarations
void processDataPoint(DataPoint& point);
double calculateAverage(const vector<DataPoint>& data);
void filterInvalidData(vector<DataPoint>& data);
void displayDataSummary(const vector<DataPoint>& data);

int main() {
    // Test Exercise 1: Bank Account
    cout << "===== Bank Account Tests =====" << endl;
    BankAccount account{"John Doe", 1000.0, {}};
    
    deposit(account, 500.0);
    withdraw(account, 200.0);
    displayBalance(account);
    cout << "Interest earned: $" << calculateInterest(account, 0.05) << endl;
    cout << "\nTransaction History:" << endl;
    for (const string& transaction : account.transactions) {
        cout << transaction << endl;
    }
    cout << endl;
    
    // Test Exercise 2: Text Processor
    cout << "===== Text Processor Tests =====" << endl;
    string text = "The quick brown fox jumps over the lazy dog";
    vector<string> words;
    
    tokenizeText(text, words);
    cout << "Original words: " << joinWords(words, " ") << endl;
    
    sortWords(words);
    cout << "Sorted words: " << joinWords(words, " ") << endl;
    
    cout << "Unique word count: " << countUniqueWords(words) << endl;
    displayStats(words);
    cout << endl;
    
    // Test Exercise 3: Data Analysis
    cout << "===== Data Analysis Tests =====" << endl;
    vector<DataPoint> dataPoints = {
        {10.5, "Point 1", true},
        {-1.0, "Point 2", false},
        {15.7, "Point 3", true},
        {8.9, "Point 4", true}
    };
    
    for (DataPoint& point : dataPoints) {
        processDataPoint(point);
    }
    
    filterInvalidData(dataPoints);
    displayDataSummary(dataPoints);
    cout << "Average of valid points: " << calculateAverage(dataPoints) << endl;
    
    return 0;
}

// ===== Exercise 1: Bank Account Implementation =====
void deposit(BankAccount& account, double amount) {
    if (amount > 0) {
        account.balance += amount;
        addTransaction(account, "Deposit: $" + to_string(amount));
    }
}

bool withdraw(BankAccount& account, double amount) {
    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        addTransaction(account, "Withdrawal: $" + to_string(amount));
        return true;
    }
    return false;
}

void displayBalance(const BankAccount& account) {
    cout << "Account Holder: " << account.accountHolder << endl;
    cout << "Current Balance: $" << fixed << setprecision(2) 
         << account.balance << endl;
}

void addTransaction(BankAccount& account, const string& transaction) {
    account.transactions.push_back(transaction);
}

double calculateInterest(const BankAccount& account, double rate) {
    return account.balance * rate;
}

// ===== Exercise 2: Text Processor Implementation =====
void tokenizeText(const string& text, vector<string>& words) {
    string word;
    size_t start = 0, end = 0;
    
    while ((end = text.find(' ', start)) != string::npos) {
        word = text.substr(start, end - start);
        if (!word.empty()) {
            words.push_back(word);
        }
        start = end + 1;
    }
    
    word = text.substr(start);
    if (!word.empty()) {
        words.push_back(word);
    }
}

void sortWords(vector<string>& words) {
    sort(words.begin(), words.end());
}

int countUniqueWords(const vector<string>& words) {
    vector<string> uniqueWords = words;
    sort(uniqueWords.begin(), uniqueWords.end());
    auto last = unique(uniqueWords.begin(), uniqueWords.end());
    return distance(uniqueWords.begin(), last);
}

void displayStats(const vector<string>& words) {
    cout << "Word Statistics:" << endl;
    cout << "Total words: " << words.size() << endl;
    cout << "Average word length: " 
         << accumulate(words.begin(), words.end(), 0.0,
                      [](double sum, const string& word) {
                          return sum + word.length();
                      }) / words.size() << endl;
}

string joinWords(const vector<string>& words, const string& delimiter) {
    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

// ===== Exercise 3: Data Analysis Implementation =====
void processDataPoint(DataPoint& point) {
    // Validate and process data point
    if (point.value < 0) {
        point.isValid = false;
    }
}

double calculateAverage(const vector<DataPoint>& data) {
    if (data.empty()) return 0.0;
    
    double sum = 0.0;
    int count = 0;
    
    for (const DataPoint& point : data) {
        if (point.isValid) {
            sum += point.value;
            count++;
        }
    }
    
    return count > 0 ? sum / count : 0.0;
}

void filterInvalidData(vector<DataPoint>& data) {
    data.erase(
        remove_if(data.begin(), data.end(),
                 [](const DataPoint& point) { return !point.isValid; }),
        data.end()
    );
}

void displayDataSummary(const vector<DataPoint>& data) {
    cout << "Data Summary:" << endl;
    cout << "Total points: " << data.size() << endl;
    cout << "Valid points:" << endl;
    
    for (const DataPoint& point : data) {
        if (point.isValid) {
            cout << point.label << ": " << point.value << endl;
        }
    }
}
