#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
using namespace std;

// Text Processor
class TextProcessor {
public:
    // Count words in text
    int countWords(const string& text) {
        istringstream iss(text);
        int count = 0;
        string word;
        
        while (iss >> word) {
            count++;
        }
        
        return count;
    }
    
    // Count sentences
    int countSentences(const string& text) {
        int count = 0;
        for (char c : text) {
            if (c == '.' || c == '!' || c == '?') {
                count++;
            }
        }
        return count;
    }
    
    // Format text (capitalize first letter of each sentence)
    string formatText(string text) {
        bool newSentence = true;
        
        for (size_t i = 0; i < text.length(); i++) {
            if (newSentence && isalpha(text[i])) {
                text[i] = toupper(text[i]);
                newSentence = false;
            } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
                newSentence = true;
            }
        }
        
        return text;
    }
    
    // Get word frequency
    map<string, int> getWordFrequency(const string& text) {
        map<string, int> frequency;
        istringstream iss(text);
        string word;
        
        while (iss >> word) {
            // Convert to lowercase for case-insensitive counting
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            // Remove punctuation
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            frequency[word]++;
        }
        
        return frequency;
    }
};

// URL Parser
class URLParser {
public:
    // Parse URL into components
    void parseURL(const string& url) {
        // Find protocol
        size_t protocolEnd = url.find("://");
        if (protocolEnd != string::npos) {
            protocol = url.substr(0, protocolEnd);
            protocolEnd += 3;  // Skip "://"
        } else {
            protocolEnd = 0;
            protocol = "";
        }
        
        // Find path and query
        size_t pathStart = url.find('/', protocolEnd);
        if (pathStart == string::npos) {
            host = url.substr(protocolEnd);
            path = "/";
            query = "";
            return;
        }
        
        host = url.substr(protocolEnd, pathStart - protocolEnd);
        
        // Find query
        size_t queryStart = url.find('?', pathStart);
        if (queryStart == string::npos) {
            path = url.substr(pathStart);
            query = "";
        } else {
            path = url.substr(pathStart, queryStart - pathStart);
            query = url.substr(queryStart + 1);
        }
    }
    
    // Get components
    string getProtocol() const { return protocol; }
    string getHost() const { return host; }
    string getPath() const { return path; }
    string getQuery() const { return query; }
    
    // Parse query parameters
    map<string, string> getQueryParams() const {
        map<string, string> params;
        istringstream iss(query);
        string param;
        
        while (getline(iss, param, '&')) {
            size_t pos = param.find('=');
            if (pos != string::npos) {
                string key = param.substr(0, pos);
                string value = param.substr(pos + 1);
                params[key] = value;
            }
        }
        
        return params;
    }

private:
    string protocol;
    string host;
    string path;
    string query;
};

// CSV Parser
class CSVParser {
public:
    // Parse CSV line
    vector<string> parseLine(const string& line) {
        vector<string> fields;
        string field;
        bool inQuotes = false;
        ostringstream oss;
        
        for (char c : line) {
            if (c == '"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                fields.push_back(oss.str());
                oss.str("");
                oss.clear();
            } else {
                oss << c;
            }
        }
        
        // Add last field
        fields.push_back(oss.str());
        
        return fields;
    }
    
    // Parse CSV content
    vector<vector<string>> parseContent(const string& content) {
        vector<vector<string>> rows;
        istringstream iss(content);
        string line;
        
        while (getline(iss, line)) {
            if (!line.empty()) {
                rows.push_back(parseLine(line));
            }
        }
        
        return rows;
    }
    
    // Format CSV row
    string formatRow(const vector<string>& row) {
        ostringstream oss;
        for (size_t i = 0; i < row.size(); i++) {
            if (i > 0) oss << ",";
            
            // Quote fields containing commas or quotes
            if (row[i].find(',') != string::npos || 
                row[i].find('"') != string::npos) {
                oss << '"' << row[i] << '"';
            } else {
                oss << row[i];
            }
        }
        return oss.str();
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
