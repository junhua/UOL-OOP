---
layout: default
title: "Topic 2: Using classes and variables to model data: the OrderBookEntry class"
parent: Labs
nav_order: 2
---

# Topic 2: Using classes and variables to model data: the OrderBookEntry class

## Overview

Topic 2 introduces object-oriented programming concepts by implementing the OrderBookEntry class to model trading data. This topic focuses on:

- Using basic data types (numbers and strings) to represent data
- Creating classes to encapsulate related data and functionality
- Implementing constructors and accessor methods
- Separating class declarations and implementations into header and source files
- Using vectors to store collections of objects

## Implementation Details

### The OrderBookEntry Class

The OrderBookEntry class represents a single entry in the order book, containing information about a trading order:

- **price**: The price of the order (double)
- **amount**: The amount of the order (double)
- **timestamp**: When the order was placed (string)
- **product**: The trading pair (e.g., "ETH/BTC") (string)
- **orderType**: Whether it's a bid or ask (enum class OrderType)

### Code Structure

#### Basic Data Types

The implementation starts by defining the basic data types needed to represent the order book data:

```cpp
#include <string>

int main() {
    // numbers
    double price = 5319.45;
    double amount = 0.0002;
    
    // strings
    std::string timestamp{"2019-01-01 00:00:00.884492"}; // ISO 8601 format with microseconds
    std::string product{"BTC/USDT"};
    
    // enum
    enum class OrderType{Bid, Ask};
    OrderType orderType{OrderType::Bid}; // to make a bid
    
    // ...
}
```

#### Using Vectors for Collections

To store multiple entries, vectors are introduced:

```cpp
#include <vector>

int main() {
    enum class OrderType{Bid, Ask};
    
    std::vector<double> prices;
    std::vector<double> amounts;
    std::vector<std::string> timeframes;
    std::vector<std::string> products;
    std::vector<OrderType> orderTypes;
    
    prices.push_back(5000.01);
    amounts.push_back(1.0);
    timeframes.push_back("2020-01-01 00:00:00");
    products.push_back("ETH/BTC");
    orderTypes.push_back(OrderType::Bid);
    
    std::cout << "Price: " << prices[0] << std::endl;
    
    // ...
}
```

#### Creating the OrderBookEntry Class

The next step is to create a class that encapsulates all the data related to an order book entry:

```cpp
enum class OrderType{Bid, Ask};

class OrderBookEntry{
public:
    double price;
    double amount;
    std::string timeframe;
    std::string product;
    OrderType orderType;
    
    // Constructor 1
    OrderBookEntry() {};
    
    // Constructor 2
    OrderBookEntry(double _price, 
                  double _amount, 
                  std::string _timeframe, 
                  std::string _product, 
                  OrderType _orderType) 
        : price(_price), 
          amount(_amount), 
          timeframe(_timeframe), 
          product(_product), 
          orderType(_orderType) {}
};
```

#### Using the OrderBookEntry Class

With the class defined, we can create and use OrderBookEntry objects:

```cpp
int main() {
    // Using constructor 1
    OrderBookEntry order1;
    order1.price = 5000.01;
    order1.amount = 1.0;
    order1.timeframe = "2020-01-01 00:00:00";
    order1.product = "ETH/BTC";
    order1.orderType = OrderType::Bid;
    
    // Using constructor 2
    OrderBookEntry order2(5030.01, 1.0, "2020-01-02 01:50:10", "ETH/BTC", OrderType::Ask);
    
    std::cout << "Order 1's price: " << order1.price << std::endl;
    std::cout << "Order 2's price: " << order2.price << std::endl;
    
    // ...
}
```

#### Creating a Vector of OrderBookEntry Objects

We can now create a vector to store multiple OrderBookEntry objects:

```cpp
int main() {
    // ...
    
    std::vector<OrderBookEntry> orderBook;
    orderBook.push_back(order1);
    orderBook.push_back(OrderBookEntry(5000.01, 1.0, "2020-01-02 01:50:10", "ETH/BTC", OrderType::Ask));
    
    std::cout << "Price: " << orderBook[0].price << std::endl;
    std::cout << "Price: " << orderBook[1].price << std::endl;
    
    // ...
}
```

#### Iterating Over a Vector

There are multiple ways to iterate over a vector:

```cpp
// Iterate using a for loop with an index variable
for (std::size_t i = 0; i < orderBook.size(); ++i) {
    std::cout << "Price: " << orderBook[i].price << std::endl;
}

// Iterate using a for loop with an index variable (using at() method)
for (std::size_t i = 0; i < orderBook.size(); ++i) {
    std::cout << "Price: " << orderBook.at(i).price << std::endl;
}

// Iterate using a range-based for loop
for (const OrderBookEntry &entry : orderBook) {
    std::cout << "Price: " << entry.price << std::endl;
}
```

### Splitting into Header and Source Files

As the program grows, it's good practice to split the class into a header file (.h) and a source file (.cpp):

#### Header File (OrderBookEntry.h)

```cpp
#pragma once

#include <string>

enum class OrderType { Bid, Ask };

class OrderBookEntry {
public:
    // Constructors
    OrderBookEntry();
    OrderBookEntry(double price, double amount, const std::string& timestamp, const std::string& product, OrderType orderType);
    
    // Accessor functions
    double getPrice() const;
    double getAmount() const;
    std::string getTimestamp() const;
    std::string getProduct() const;
    OrderType getOrderType() const;
    
private:
    double m_price;
    double m_amount;
    std::string m_timestamp;
    std::string m_product;
    OrderType m_orderType;
};
```

#### Source File (OrderBookEntry.cpp)

```cpp
#include "OrderBookEntry.h"

// Constructors
OrderBookEntry::OrderBookEntry() 
    : m_price(0.0), m_amount(0.0), m_timestamp(""), m_product(""), m_orderType(OrderType::Bid) {}

OrderBookEntry::OrderBookEntry(double price, double amount, const std::string& timestamp, const std::string& product, OrderType orderType)
    : m_price(price), m_amount(amount), m_timestamp(timestamp), m_product(product), m_orderType(orderType) {}

// Accessor functions
double OrderBookEntry::getPrice() const { return m_price; }

double OrderBookEntry::getAmount() const { return m_amount; }

std::string OrderBookEntry::getTimestamp() const { return m_timestamp; }

std::string OrderBookEntry::getProduct() const { return m_product; }

OrderType OrderBookEntry::getOrderType() const { return m_orderType; }
```

### The MerkelMain Class

To further organize the code, a MerkelMain class is introduced to manage the application:

#### Header File (MerkelMain.h)

```cpp
#pragma once

#include <vector>
#include "OrderBookEntry.h" 

class MerkelMain
{
public:
    MerkelMain();
    void init();

private:
    void loadOrderBook();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void processUserOption(int userOption);
    std::vector<OrderBookEntry> orderBook;
};
```

#### Source File (MerkelMain.cpp)

```cpp
#include <iostream>
#include <vector>
#include "MerkelMain.h"

MerkelMain::MerkelMain() {}

void MerkelMain::init()
{
    while (true)
    {
        loadOrderBook();
        int input;
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void MerkelMain::loadOrderBook()
{
    orderBook.push_back(OrderBookEntry{ 1000.00, 0.2, "2020/03/17 17:01:01.123412", "BTC/USDT", OrderType::Bid });
    orderBook.push_back(OrderBookEntry{ 2000.00, 0.2, "2020/03/17 17:01:01.123412", "BTC/USDT", OrderType::Bid });
}

// ... (other methods)
```

#### Main File (main.cpp)

```cpp
#include "OrderBookEntry.h"
#include "MerkelMain.h"

int main()
{
    MerkelMain app{};
    app.init();
    return 0;
}
```

## OOP Concepts Demonstrated

Topic 2 introduces several fundamental object-oriented programming concepts:

### Classes and Objects

The OrderBookEntry class demonstrates how to create a class to encapsulate related data and functionality. Objects of this class represent individual entries in the order book.

### Constructors

The OrderBookEntry class has two constructors:
- A default constructor that creates an empty entry
- A parameterized constructor that initializes all data members

```cpp
// Default constructor
OrderBookEntry::OrderBookEntry() 
    : m_price(0.0), m_amount(0.0), m_timestamp(""), m_product(""), m_orderType(OrderType::Bid) {}

// Parameterized constructor
OrderBookEntry::OrderBookEntry(double price, double amount, const std::string& timestamp, const std::string& product, OrderType orderType)
    : m_price(price), m_amount(amount), m_timestamp(timestamp), m_product(product), m_orderType(orderType) {}
```

### Member Initialization Lists

The constructors use member initialization lists to initialize the data members:

```cpp
OrderBookEntry::OrderBookEntry(double price, double amount, const std::string& timestamp, const std::string& product, OrderType orderType)
    : m_price(price), m_amount(amount), m_timestamp(timestamp), m_product(product), m_orderType(orderType) {}
```

This is more efficient than assigning values in the constructor body, especially for non-primitive types like strings.

### Access Modifiers

The OrderBookEntry class demonstrates the use of access modifiers to control access to class members:

```cpp
class OrderBookEntry {
public:
    // Public members can be accessed from outside the class
    
private:
    // Private members can only be accessed from within the class
    double m_price;
    double m_amount;
    std::string m_timestamp;
    std::string m_product;
    OrderType m_orderType;
};
```

### Accessor Methods (Getters)

The OrderBookEntry class provides accessor methods to access the private data members:

```cpp
double getPrice() const;
double getAmount() const;
std::string getTimestamp() const;
std::string getProduct() const;
OrderType getOrderType() const;
```

These methods provide controlled access to the private data members, allowing for data validation and encapsulation.

### Const Correctness

The accessor methods are marked as `const`, indicating that they don't modify the object's state:

```cpp
double getPrice() const { return m_price; }
```

This is an important aspect of C++ programming that helps prevent unintended modifications and enables compiler optimizations.

### Enumerations

The OrderType enum class demonstrates the use of scoped enumerations to represent a fixed set of values:

```cpp
enum class OrderType { Bid, Ask };
```

Using an enum class instead of raw strings or integers provides type safety and makes the code more readable.

### Header and Source File Separation

The implementation demonstrates the separation of class declarations (in header files) and implementations (in source files), which is a common practice in C++ programming:

- **Header File (.h)**: Contains the class declaration, including member variables and function prototypes
- **Source File (.cpp)**: Contains the implementation of the class methods

This separation allows for better code organization and compilation efficiency.

## Key Takeaways

1. **Data Modeling**: Classes provide a way to model real-world entities by encapsulating related data and functionality.

2. **Encapsulation**: Access modifiers and accessor methods help control access to class members, promoting encapsulation.

3. **Code Organization**: Separating class declarations and implementations into header and source files improves code organization.

4. **Object Collections**: Vectors provide a way to store and manipulate collections of objects.

5. **Iteration Techniques**: Different techniques can be used to iterate over collections, each with its own advantages.

## Next Steps

The next topic will build upon this foundation by implementing file I/O and exception handling to read order book data from a CSV file, introducing the CSVReader class.
