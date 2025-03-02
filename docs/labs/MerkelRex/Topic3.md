---
layout: default
title: "Topic 3: File I/O, Exception Handling and Algorithms: the CSVReader class"
parent: Labs
nav_order: 3
---

# Topic 3: File I/O, Exception Handling and Algorithms: the CSVReader class

## Overview

Topic 3 introduces file input/output operations, exception handling, and algorithm implementation by creating the CSVReader class. This topic focuses on:

- Implementing a tokenize algorithm to process CSV data
- Reading data from files using file streams
- Handling exceptions to gracefully recover from errors
- Creating a CSVReader class to encapsulate file reading functionality
- Converting string data to appropriate types

## Implementation Details

### The Tokenize Algorithm

The first step is to implement a tokenize algorithm that breaks a string into tokens based on a separator character. This algorithm is essential for processing CSV data.

```cpp
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string csvLine, char sep) {
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    
    // Find the first non-separator character in the input string
    start = csvLine.find_first_not_of(sep, 0);
    
    // Loop through the input string, finding each separator character and extracting the token between it and the previous separator
    do {
        // Find the next occurrence of the separator character
        end = csvLine.find_first_of(sep, start);
        
        // If no separator is found or if start == end, break out of the loop
        if (start == csvLine.length() || start == end) break;
        
        // Extract the substring between the current position and the separator
        if (end >= 0) {
            token = csvLine.substr(start, end - start);
        } else {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        
        // Add the token to the vector of tokens
        tokens.push_back(token);
        
        // Update the starting position for the next iteration
        start = end + 1;
    } while (end > 0);
    
    return tokens;
}
```

### File I/O Operations

The next step is to implement file I/O operations to read data from a CSV file:

```cpp
#include <fstream>

int main() {
    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    
    if (csvFile.is_open()) {
        // Read the file line by line
        while (std::getline(csvFile, line)) {
            std::cout << "Read line: " << line << std::endl;
            
            // Process the line (tokenize, etc.)
            // ...
        }
        csvFile.close();
    } else {
        std::cout << "File is not open" << std::endl;
    }
    
    return 0;
}
```

### Exception Handling

When processing CSV data, we need to handle potential errors, such as invalid numeric values. This is done using try-catch blocks:

```cpp
int main() {
    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::string> tokens;
    
    if (csvFile.is_open()) {
        while (std::getline(csvFile, line)) {
            std::cout << "Read line: " << line << std::endl;
            tokens = tokenize(line, ',');
            
            if (tokens.size() != 5) {
                std::cout << "Bad line " << std::endl;
                continue;
            }
            
            try {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << price << " : " << amount << std::endl;
            } catch (std::exception &e) {
                std::cout << "Bad float! " << tokens[3] << std::endl;
                std::cout << "Bad float! " << tokens[4] << std::endl;
                continue;
            }
        }
        csvFile.close();
    } else {
        std::cout << "File is not open" << std::endl;
    }
    
    return 0;
}
```

### The CSVReader Class

To encapsulate the file reading functionality, we create a CSVReader class:

#### Header File (CSVReader.h)

```cpp
#pragma once
#include "OrderBookEntry.h"
#include <vector>

class CSVReader {
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    
private:
    static std::vector<std::string> tokenize(std::string csvLine, char sep);
    static OrderBookEntry stringToOBE(std::vector<std::string> tokens);
};
```

#### Source File (CSVReader.cpp)

```cpp
#include "CSVReader.h"
#include "OrderBookEntry.h"
#include <fstream>
#include <iostream>

CSVReader::CSVReader() {}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile) {
    std::vector<OrderBookEntry> entries;
    std::ifstream csvStream{csvFile};
    std::string line;
    
    if (csvStream.is_open()) {
        while (std::getline(csvStream, line)) {
            try {
                OrderBookEntry obe = stringToOBE(tokenize(line, ','));
                entries.push_back(obe);
            } catch(std::exception& e) {
                std::cout << "Bad data" << std::endl;
                continue;
            }
        }
    } else {
        std::cout << "Unable to open file: " << csvFile << std::endl;
    }
    
    std::cout << "CSVReader::readCSV read " << entries.size() << " entries." << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenize(std::string csvLine, char sep) {
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    
    start = csvLine.find_first_not_of(sep, 0);
    
    do {
        end = csvLine.find_first_of(sep, start);
        if (start == csvLine.length() || start == end) break;
        
        if (end >= 0) {
            token = csvLine.substr(start, end - start);
        } else {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        
        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);
    
    return tokens;
}

OrderBookEntry CSVReader::stringToOBE(std::vector<std::string> tokens) {
    double price, amount;
    std::string timestamp, product;
    OrderBookType type;
    
    if (tokens.size() != 5) {
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    
    try {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    } catch (const std::exception &e) {
        std::cout << "Bad float! " << tokens[3] << std::endl;
        std::cout << "Bad float! " << tokens[4] << std::endl;
        throw;
    }
    
    return OrderBookEntry(price, amount, tokens[0], tokens[1], OrderBookEntry::stringToOrderType(tokens[2]));
}
```

### Converting String to OrderType

To convert a string to an OrderType, we add a static method to the OrderBookEntry class:

#### Header File (OrderBookEntry.h)

```cpp
enum class OrderBookType { bid, ask, unknown };

class OrderBookEntry {
public:
    // ...
    static OrderBookType stringToOrderType(std::string type);
    // ...
};
```

#### Source File (OrderBookEntry.cpp)

```cpp
OrderBookType OrderBookEntry::stringToOrderType(std::string type) {
    if (type == "bid") {
        return OrderBookType::bid;
    } else if (type == "ask") {
        return OrderBookType::ask;
    } else {
        return OrderBookType::unknown;
    }
}
```

### Updating MerkelMain

Finally, we update the MerkelMain class to use the CSVReader:

```cpp
#include "CSVReader.h"

void MerkelMain::loadOrderBook() {
    orders = CSVReader::readCSV("20200317.csv");
}

void MerkelMain::printMarketStats() {
    std::cout << "OrderBook contains : " << orders.size() << "entries" << std::endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    
    for (OrderBookEntry & order : orders) {
        if (order.orderType == OrderBookType::bid) {
            bids++;
        }
        if (order.orderType == OrderBookType::ask) {
            asks++;
        }
    }
    
    std::cout << "OrderBook asks size : " << asks << std::endl;
    std::cout << "OrderBook bids size : " << bids << std::endl;
}
```

## OOP Concepts Demonstrated

Topic 3 introduces several important object-oriented programming concepts:

### Static Methods

The CSVReader class demonstrates the use of static methods, which belong to the class rather than to instances of the class:

```cpp
static std::vector<OrderBookEntry> readCSV(std::string csvFile);
static std::vector<std::string> tokenize(std::string csvLine, char sep);
static OrderBookEntry stringToOBE(std::vector<std::string> tokens);
```

Static methods can be called without creating an instance of the class, which is useful for utility functions that don't depend on instance state.

### Exception Handling

The implementation demonstrates the use of try-catch blocks to handle exceptions:

```cpp
try {
    price = std::stod(tokens[3]);
    amount = std::stod(tokens[4]);
} catch (const std::exception &e) {
    std::cout << "Bad float! " << tokens[3] << std::endl;
    std::cout << "Bad float! " << tokens[4] << std::endl;
    throw;
}
```

This allows the program to gracefully recover from errors, such as invalid numeric values in the CSV file.

### File I/O

The implementation demonstrates how to read data from files using file streams:

```cpp
std::ifstream csvStream{csvFile};
std::string line;

if (csvStream.is_open()) {
    while (std::getline(csvStream, line)) {
        // Process the line
    }
}
```

This is essential for reading data from external sources, such as CSV files.

### Algorithm Implementation

The tokenize function demonstrates the implementation of a string processing algorithm:

```cpp
std::vector<std::string> CSVReader::tokenize(std::string csvLine, char sep) {
    // Implementation
}
```

This algorithm breaks a string into tokens based on a separator character, which is essential for processing CSV data.

### Type Conversion

The stringToOBE function demonstrates how to convert string data to appropriate types:

```cpp
OrderBookEntry CSVReader::stringToOBE(std::vector<std::string> tokens) {
    double price, amount;
    // ...
    price = std::stod(tokens[3]);
    amount = std::stod(tokens[4]);
    // ...
}
```

This is important for processing data from external sources, where all data is initially in string format.

### Single Responsibility Principle

The CSVReader class demonstrates the Single Responsibility Principle, as it has a single responsibility: reading and parsing CSV data. This makes the code more maintainable and easier to understand.

## Key Takeaways

1. **File I/O**: File streams provide a way to read data from external sources, such as CSV files.

2. **Exception Handling**: Try-catch blocks allow the program to gracefully recover from errors, such as invalid data.

3. **Algorithm Implementation**: Implementing algorithms, such as the tokenize function, is essential for processing data.

4. **Static Methods**: Static methods belong to the class rather than to instances of the class, which is useful for utility functions.

5. **Type Conversion**: Converting string data to appropriate types is important for processing data from external sources.

## Next Steps

The next topic will build upon this foundation by implementing algorithms to calculate statistics and navigate through time in the order book, introducing the OrderBook class.
