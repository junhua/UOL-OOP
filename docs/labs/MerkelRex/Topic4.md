---
layout: default
title: "Topic 4: Writing and testing an algorithm"
parent: Labs
nav_order: 4
---

# Topic 4: Writing and testing an algorithm

## Overview

Topic 4 focuses on implementing and testing algorithms for the MerkelRex application. This topic introduces:

- Creating the OrderBook class to manage trading data
- Implementing algorithms to calculate statistics (high/low prices)
- Developing time-based navigation functionality
- Testing algorithms with sample data
- Using maps to efficiently organize data

## Implementation Details

### The OrderBook Class

The OrderBook class is responsible for managing the order book data and providing methods to access and analyze it. It encapsulates the collection of OrderBookEntry objects and provides functionality to filter and analyze the data.

#### Header File (OrderBook.h)

```cpp
#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook {
public:
    // constructors, reading a csv data file
    OrderBook(std::string filename);
    
    // return vector of all known products in the dataset
    std::vector<std::string> getKnownProducts();
    
    // return vector of orders according to the sent filter
    std::vector<OrderBookEntry> getOrders(OrderBookType type, 
                                         std::string product, 
                                         std::string timestamp);
    
    // returns the earliest time in the orderbook
    std::string getEarliestTime();
    
    // returns the next time after the sent time in the orderbook
    // if there is no next timestamp, wraps around to the start
    std::string getNextTime(std::string timestamp);
    
    // calculate the highest price in the sent vector
    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    
    // calculate the lowest price in the sent vector
    static double getLowPrice(std::vector<OrderBookEntry> &orders);
    
private:
    std::vector<OrderBookEntry> orders;
};
```

#### Source File (OrderBook.cpp)

```cpp
#include "OrderBook.h"
#include <map>
#include <algorithm>

OrderBook::OrderBook(std::string filename) {
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> products;
    std::map<std::string, bool> prodMap;
    
    for (OrderBookEntry &e : orders) {
        prodMap[e.product] = true;
    }
    
    for (auto const &e : prodMap) {
        products.push_back(e.first);
    }
    
    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, 
                                               std::string product, 
                                               std::string timestamp) {
    std::vector<OrderBookEntry> orders_sub;
    
    for (OrderBookEntry &e : orders) {
        if (e.orderType == type && 
            e.product == product && 
            e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }
    
    return orders_sub;
}

std::string OrderBook::getEarliestTime() {
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp) {
    std::string next_timestamp = "";
    
    for (OrderBookEntry &e : orders) {
        if (e.timestamp > timestamp) {
            next_timestamp = e.timestamp;
            break;
        }
    }
    
    if (next_timestamp == "") {
        next_timestamp = orders[0].timestamp;
    }
    
    return next_timestamp;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders) {
    double max = orders[0].price;
    
    for (OrderBookEntry &e : orders) {
        if (e.price > max) max = e.price;
    }
    
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders) {
    double min = orders[0].price;
    
    for (OrderBookEntry &e : orders) {
        if (e.price < min) min = e.price;
    }
    
    return min;
}
```

### Updating MerkelMain

The MerkelMain class is updated to use the OrderBook class:

#### Header File (MerkelMain.h)

```cpp
#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain {
public:
    MerkelMain();
    void init();
    
private:
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void processUserOption(int userOption);
    
    std::string currentTime;
    OrderBook orderBook{"20200317.csv"};
};
```

#### Source File (MerkelMain.cpp)

```cpp
#include <iostream>
#include "MerkelMain.h"

MerkelMain::MerkelMain() {}

void MerkelMain::init() {
    currentTime = orderBook.getEarliestTime();
    
    while (true) {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
}

void MerkelMain::printMenu() {
    // ... (unchanged)
    std::cout << "Current time: " << currentTime << std::endl;
}

void MerkelMain::printMarketStats() {
    for (std::string const &p : orderBook.getKnownProducts()) {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
}

void MerkelMain::gotoNextTimeframe() {
    std::cout << "Going to next time frame. " << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}

// ... (other methods)
```

## Algorithm Implementation Details

### Finding Known Products

The `getKnownProducts` method uses a map to efficiently find all unique products in the order book:

```cpp
std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> products;
    std::map<std::string, bool> prodMap;
    
    // Add each product to the map (duplicates are automatically handled)
    for (OrderBookEntry &e : orders) {
        prodMap[e.product] = true;
    }
    
    // Extract the unique product names from the map
    for (auto const &e : prodMap) {
        products.push_back(e.first);
    }
    
    return products;
}
```

This algorithm has a time complexity of O(n log n), where n is the number of orders, due to the map operations.

### Filtering Orders

The `getOrders` method filters the orders based on type, product, and timestamp:

```cpp
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, 
                                               std::string product, 
                                               std::string timestamp) {
    std::vector<OrderBookEntry> orders_sub;
    
    // Iterate through all orders and filter based on criteria
    for (OrderBookEntry &e : orders) {
        if (e.orderType == type && 
            e.product == product && 
            e.timestamp == timestamp) {
            orders_sub.push_back(e);
        }
    }
    
    return orders_sub;
}
```

This algorithm has a time complexity of O(n), where n is the number of orders.

### Time Navigation

The `getNextTime` method finds the next timestamp after a given timestamp:

```cpp
std::string OrderBook::getNextTime(std::string timestamp) {
    std::string next_timestamp = "";
    
    // Find the first timestamp that is greater than the given timestamp
    for (OrderBookEntry &e : orders) {
        if (e.timestamp > timestamp) {
            next_timestamp = e.timestamp;
            break;
        }
    }
    
    // If no next timestamp is found, wrap around to the start
    if (next_timestamp == "") {
        next_timestamp = orders[0].timestamp;
    }
    
    return next_timestamp;
}
```

This algorithm has a time complexity of O(n), where n is the number of orders.

### Finding High and Low Prices

The `getHighPrice` and `getLowPrice` methods calculate the highest and lowest prices in a vector of orders:

```cpp
double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders) {
    double max = orders[0].price;
    
    // Find the maximum price
    for (OrderBookEntry &e : orders) {
        if (e.price > max) max = e.price;
    }
    
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders) {
    double min = orders[0].price;
    
    // Find the minimum price
    for (OrderBookEntry &e : orders) {
        if (e.price < min) min = e.price;
    }
    
    return min;
}
```

Both algorithms have a time complexity of O(n), where n is the number of orders.

## OOP Concepts Demonstrated

Topic 4 introduces several important object-oriented programming concepts:

### Class Composition

The OrderBook class demonstrates class composition by containing a vector of OrderBookEntry objects:

```cpp
private:
    std::vector<OrderBookEntry> orders;
```

This is an example of a "has-a" relationship, where an OrderBook has OrderBookEntry objects.

### Static Methods

The OrderBook class includes static methods for calculating statistics:

```cpp
static double getHighPrice(std::vector<OrderBookEntry> &orders);
static double getLowPrice(std::vector<OrderBookEntry> &orders);
```

These methods don't depend on the state of the OrderBook instance and can be called without creating an instance of the class.

### Encapsulation

The OrderBook class encapsulates the order book data and provides methods to access and manipulate it:

```cpp
private:
    std::vector<OrderBookEntry> orders;
```

The orders vector is private, and access to it is controlled through public methods.

### Algorithm Design

The implementation demonstrates algorithm design for various operations:

- Finding unique products using a map
- Filtering orders based on criteria
- Navigating through time
- Calculating statistics (high/low prices)

### Data Structures

The implementation uses various data structures:

- Vectors for storing collections of objects
- Maps for efficiently finding unique values
- Strings for representing timestamps and products

## Key Takeaways

1. **Algorithm Design**: Designing efficient algorithms is essential for processing and analyzing data.

2. **Data Structures**: Choosing appropriate data structures (vectors, maps) can significantly impact algorithm efficiency.

3. **Class Composition**: Classes can contain other classes, forming "has-a" relationships.

4. **Static Methods**: Static methods belong to the class rather than to instances of the class, which is useful for utility functions.

5. **Encapsulation**: Encapsulating data and providing controlled access to it is a fundamental principle of object-oriented programming.

## Next Steps

The next topic will build upon this foundation by implementing object interactions, specifically the Wallet class and trading functionality, to complete the MerkelRex application.
