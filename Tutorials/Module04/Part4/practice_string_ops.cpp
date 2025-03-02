#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <regex>
using namespace std;

// Template Engine
class TemplateEngine {
public:
    // Set template content
    void setTemplate(const string& content) {
        templateContent = content;
    }
    
    // Add variable
    void setVariable(const string& name, const string& value) {
        variables[name] = value;
    }
    
    // Render template
    string render() const {
        string result = templateContent;
        
        // Replace all variables
        for (const auto& var : variables) {
            string placeholder = "{{" + var.first + "}}";
            size_t pos = result.find(placeholder);
            while (pos != string::npos) {
                result.replace(pos, placeholder.length(), var.second);
                pos = result.find(placeholder);
            }
        }
        
        return result;
    }

private:
    string templateContent;
    map<string, string> variables;
};

// Markdown Parser
class MarkdownParser {
public:
    // Parse headers
    string parseHeaders(const string& text) {
        string result;
        istringstream iss(text);
        string line;
        
        while (getline(iss, line)) {
            if (line.empty()) {
                result += "\n";
                continue;
            }
            
            // Check for headers
            if (line[0] == '#') {
                size_t level = 1;
                while (level < line.length() && line[level] == '#') {
                    level++;
                }
                if (level < line.length() && line[level] == ' ') {
                    string header = line.substr(level + 1);
                    result += "<h" + to_string(level) + ">" + 
                             header + "</h" + to_string(level) + ">\n";
                    continue;
                }
            }
            
            result += line + "\n";
        }
        
        return result;
    }
    
    // Parse emphasis
    string parseEmphasis(const string& text) {
        string result = text;
        
        // Bold
        regex boldPattern(R"(\*\*(.*?)\*\*)");
        result = regex_replace(result, boldPattern, "<strong>$1</strong>");
        
        // Italic
        regex italicPattern(R"(\*(.*?)\*)");
        result = regex_replace(result, italicPattern, "<em>$1</em>");
        
        return result;
    }
    
    // Parse links
    string parseLinks(const string& text) {
        string result = text;
        regex linkPattern(R"(\[(.*?)\]\((.*?)\))");
        result = regex_replace(result, linkPattern, "<a href=\"$2\">$1</a>");
        return result;
    }
    
    // Parse all
    string parse(const string& markdown) {
        string result = markdown;
        result = parseHeaders(result);
        result = parseEmphasis(result);
        result = parseLinks(result);
        return result;
    }
};

// Log Parser
class LogParser {
public:
    struct LogEntry {
        string timestamp;
        string level;
        string message;
    };
    
    // Parse single log line
    LogEntry parseLine(const string& line) {
        LogEntry entry;
        regex pattern(R"(\[(.*?)\]\s*\[(.*?)\]\s*(.*))");
        smatch matches;
        
        if (regex_match(line, matches, pattern)) {
            entry.timestamp = matches[1];
            entry.level = matches[2];
            entry.message = matches[3];
        }
        
        return entry;
    }
    
    // Parse multiple lines
    vector<LogEntry> parseLog(const string& log) {
        vector<LogEntry> entries;
        istringstream iss(log);
        string line;
        
        while (getline(iss, line)) {
            if (!line.empty()) {
                entries.push_back(parseLine(line));
            }
        }
        
        return entries;
    }
    
    // Filter by log level
    vector<LogEntry> filterByLevel(const vector<LogEntry>& entries, 
                                 const string& level) {
        vector<LogEntry> filtered;
        copy_if(entries.begin(), entries.end(), back_inserter(filtered),
                [&level](const LogEntry& entry) {
                    return entry.level == level;
                });
        return filtered;
    }
    
    // Format log entry
    string formatEntry(const LogEntry& entry) {
        ostringstream oss;
        oss << setw(20) << left << entry.timestamp
            << setw(10) << left << entry.level
            << entry.message;
        return oss.str();
    }
};

void testTemplateEngine() {
    cout << "Template Engine Test" << endl;
    cout << "===================" << endl;
    
    TemplateEngine engine;
    engine.setTemplate("Hello {{name}}! Welcome to {{place}}.");
    engine.setVariable("name", "Alice");
    engine.setVariable("place", "Wonderland");
    
    cout << "Template result: " << engine.render() << endl;
}

void testMarkdownParser() {
    cout << "\nMarkdown Parser Test" << endl;
    cout << "===================" << endl;
    
    MarkdownParser parser;
    string markdown = "# Main Title\n"
                     "## Subtitle\n"
                     "This is **bold** and *italic* text.\n"
                     "Here's a [link](http://example.com).\n";
    
    cout << "Original Markdown:" << endl;
    cout << markdown << endl;
    
    cout << "\nParsed HTML:" << endl;
    cout << parser.parse(markdown) << endl;
}

void testLogParser() {
    cout << "\nLog Parser Test" << endl;
    cout << "===============" << endl;
    
    LogParser parser;
    string log = "[2024-02-24 10:30:15] [INFO] Application started\n"
                 "[2024-02-24 10:30:16] [DEBUG] Loading configuration\n"
                 "[2024-02-24 10:30:17] [ERROR] Failed to connect to database\n"
                 "[2024-02-24 10:30:18] [INFO] Retrying connection\n";
    
    cout << "Original log:" << endl;
    cout << log << endl;
    
    auto entries = parser.parseLog(log);
    cout << "\nParsed entries:" << endl;
    for (const auto& entry : entries) {
        cout << parser.formatEntry(entry) << endl;
    }
    
    cout << "\nFiltered by ERROR:" << endl;
    auto errors = parser.filterByLevel(entries, "ERROR");
    for (const auto& error : errors) {
        cout << parser.formatEntry(error) << endl;
    }
}

int main() {
    cout << "String Operations Practice Demo" << endl;
    cout << "===========================\n" << endl;
    
    testTemplateEngine();
    testMarkdownParser();
    testLogParser();
    
    return 0;
}
