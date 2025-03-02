#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
using namespace std;

// TODO: Implement Text Processor
class TextProcessor {
public:
    // TODO: Implement word counting
    int countWords(const string& text) {
        // Your code here
        return 0;
    }
    
    // TODO: Implement sentence counting
    int countSentences(const string& text) {
        // Your code here
        return 0;
    }
    
    // TODO: Implement text formatting
    string formatText(string text) {
        // Your code here
        return text;
    }
    
    // TODO: Implement word frequency analysis
    map<string, int> getWordFrequency(const string& text) {
        map<string, int> frequency;
        // Your code here
        return frequency;
    }
};

// TODO: Implement URL Parser
class URLParser {
public:
    // TODO: Implement URL parsing
    void parseURL(const string& url) {
        // Your code here
    }
    
    // Getters
    string getProtocol() const { return protocol; }
    string getHost() const { return host; }
    string getPath() const { return path; }
    string getQuery() const { return query; }
    
    // TODO: Implement query parameter parsing
    map<string, string> getQueryParams() const {
        map<string, string> params;
        // Your code here
        return params;
    }

private:
    string protocol;
    string host;
    string path;
    string query;
};

// TODO: Implement CSV Parser
class CSVParser {
public:
    // TODO: Implement CSV line parsing
    vector<string> parseLine(const string& line) {
        vector<string> fields;
        // Your code here
        return fields;
    }
    
    // TODO: Implement CSV content parsing
    vector<vector<string>> parseContent(const string& content) {
        vector<vector<string>> rows;
        // Your code here
        return rows;
    }
    
    // TODO: Implement CSV row formatting
    string formatRow(const vector<string>& row) {
        // Your code here
        return "";
    }
};

void testTextProcessor() {
    cout << "Text Processor Test" << endl;
    cout << "==================" << endl;
    
    TextProcessor proc;
    string text = "hello world! this is a test. how are you? i am fine.";
    
    cout << "Original text: " << text << endl;
    cout << "Word count: " << proc.countWords(text) << endl;
    cout << "Sentence count: " << proc.countSentences(text) << endl;
    cout << "Formatted text: " << proc.formatText(text) << endl;
    
    cout << "\nWord frequency:" << endl;
    auto frequency = proc.getWordFrequency(text);
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void testURLParser() {
    cout << "\nURL Parser Test" << endl;
    cout << "==============" << endl;
    
    URLParser parser;
    string url = "https://www.example.com/path/to/page?name=value&x=123";
    
    parser.parseURL(url);
    
    cout << "URL: " << url << endl;
    cout << "Protocol: " << parser.getProtocol() << endl;
    cout << "Host: " << parser.getHost() << endl;
    cout << "Path: " << parser.getPath() << endl;
    cout << "Query: " << parser.getQuery() << endl;
    
    cout << "\nQuery parameters:" << endl;
    auto params = parser.getQueryParams();
    for (const auto& param : params) {
        cout << param.first << " = " << param.second << endl;
    }
}

void testCSVParser() {
    cout << "\nCSV Parser Test" << endl;
    cout << "==============" << endl;
    
    CSVParser parser;
    string csv = "Name,Age,City\n"
                 "John,25,\"New York, NY\"\n"
                 "Alice,30,London\n"
                 "Bob,35,\"Paris, France\"";
    
    cout << "Original CSV:" << endl << csv << endl;
    
    cout << "\nParsed data:" << endl;
    auto rows = parser.parseContent(csv);
    for (const auto& row : rows) {
        cout << parser.formatRow(row) << endl;
    }
}

int main() {
    cout << "String Practice Demo" << endl;
    cout << "==================\n" << endl;
    
    testTextProcessor();
    testURLParser();
    testCSVParser();
    
    return 0;
}
