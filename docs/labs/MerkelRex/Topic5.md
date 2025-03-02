---
layout: default
title: "Topic 5: Object interactions"
parent: Labs
nav_order: 5
---

# Topic 5: Object interactions

## Overview

Topic 5 completes the MerkelRex application by implementing object interactions, specifically the Wallet class and trading functionality. This topic focuses on:

- Creating the Wallet class to manage user currencies
- Implementing trading functionality (matching asks and bids)
- Handling object interactions between different components
- Processing sales and updating the wallet
- Validating user actions based on wallet contents

## Implementation Details

### The Wallet Class

The Wallet class is responsible for managing the user's currencies and providing methods to check if the user has enough funds to make a trade.

#### Header File (Wallet.h)

```cpp
#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet {
public:
    Wallet();
    
    /** insert currency to the wallet */
    void insertCurrency(std::string type, double amount);
    
    /** remove currency from the wallet */
    bool removeCurrency(std::string type, double amount);
    
    /** check if the wallet contains this much currency or more */
    bool containsCurrency(std::string type, double amount);
    
    /** check if the wallet can fulfill this order */
    bool canFulfillOrder(OrderBookEntry order);
    
    /** update the contents of the wallet
     * assumes the order was made by the owner of the wallet
     */
    void processSale(OrderBookEntry &sale);
    
    /** get the currencies and the respective amounts in the wallet */
    std::string toString();
    
private:
    std::map<std::string, double> currencies;
};
```

#### Source File (Wallet.cpp)

```cpp
#include "Wallet.h"
#include "CSVReader.h"
#include <iostream>

Wallet::Wallet() {}

void Wallet::insertCurrency(std::string type, double amount) {
    double balance;
    
    if (amount < 0) {
        // crash the program if user puts negative amount
        throw std::exception{};
    }
    
    if (currencies.count(type) == 0) {
        balance = 0;
    } else {
        balance = currencies[type];
    }
    
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(std::string type, double amount) {
    if (amount < 0 || currencies.count(type) == 0 || currencies[type] < amount) {
        return false;
    }
    
    currencies[type] -= amount;
    return true;
}

bool Wallet::containsCurrency(std::string type, double amount) {
    if (currencies.count(type) == 0) {
        return false;
    }
    
    return currencies[type] >= amount;
}

bool Wallet::canFulfillOrder(OrderBookEntry order) {
    std::vector<std::string> currencies = CSVReader::tokenize(order.product, '/');
    
    // ask: check if you own enough currency1 to buy currency2
    if (order.orderType == OrderBookType::ask) {
        double amount = order.amount;
        std::string currency = currencies[0];
        std::cout << "Wallet::canFulfillOrder: currency = " << currency << ", amount = " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    
    // bid: check if you own enough currency2 to sell currency1
    if (order.orderType == OrderBookType::bid) {
        double amount = order.amount * order.price;
        std::string currency = currencies[1];
        std::cout << "Wallet::canFulfillOrder: currency = " << currency << ", amount = " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    
    return false;
}

void Wallet::processSale(OrderBookEntry &sale) {
    std::vector<std::string> currs = CSVReader::tokenize(sale.product, '/');
    
    if (sale.orderType == OrderBookType::asksale) {
        double outgoingAmount = sale.amount;
        std::string outgoingCurrency = currs[0];
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currs[1];
        
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
    
    if (sale.orderType == OrderBookType::bidsale) {
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currs[0];
        double outgoingAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currs[1];
        
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
}

std::string Wallet::toString() {
    std::string s;
    
    for (const std::pair<std::string, double> &pair : currencies) {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + ": " + std::to_string(amount) + "\n";
    }
    
    return s;
}
```

### Updating OrderBookEntry

The OrderBookEntry class is updated to include a username field and additional order types for sales:

#### Header File (OrderBookEntry.h)

```cpp
enum class OrderBookType { bid, ask, unknown, asksale, bidsale };

class OrderBookEntry {
public:
    OrderBookEntry(double price, 
                  double amount, 
                  std::string timestamp, 
                  std::string product, 
                  OrderBookType orderType,
                  std::string username = "dataset");
    
    // ... (other methods)
    
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
    std::string username;
};
```

#### Source File (OrderBookEntry.cpp)

```cpp
OrderBookEntry::OrderBookEntry(double _price, 
                             double _amount, 
                             std::string _timestamp, 
                             std::string _product, 
                             OrderBookType _orderType,
                             std::string _username)
    : price(_price), 
      amount(_amount), 
      timestamp(_timestamp), 
      product(_product), 
      orderType(_orderType),
      username(_username) {}
```

### Updating OrderBook

The OrderBook class is updated to include a method for matching asks to bids:

#### Header File (OrderBook.h)

```cpp
class OrderBook {
public:
    // ... (other methods)
    
    /** Match asks to bids and return a vector of sales */
    std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);
    
    /** Insert an order into the order book */
    void insertOrder(OrderBookEntry &order);
    
    // ... (other methods)
};
```

#### Source File (OrderBook.cpp)

```cpp
#include <algorithm>

void OrderBook::insertOrder(OrderBookEntry &order) {
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp) {
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);
    std::vector<OrderBookEntry> sales;
    
    // Sort asks by price (ascending) and bids by price (descending)
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);
    
    // Match asks to bids
    for (OrderBookEntry &ask : asks) {
        for (OrderBookEntry &bid : bids) {
            if (bid.price >= ask.price) {
                OrderBookEntry sale{ask.price, 0, timestamp, product, OrderBookType::sale};
                
                if (bid.username == "simuser") {
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::bidsale;
                }
                
                if (ask.username == "simuser") {
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::asksale;
                }
                
                if (bid.amount == ask.amount) {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;
                }
                
                if (bid.amount > ask.amount) {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount;
                    break;
                }
                
                if (bid.amount < ask.amount) {
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    continue;
                }
            }
        }
    }
    
    return sales;
}
```

### Updating MerkelMain

The MerkelMain class is updated to include a Wallet and handle user interactions with it:

#### Header File (MerkelMain.h)

```cpp
#include "Wallet.h"

class MerkelMain {
public:
    // ... (other methods)
    
private:
    // ... (other methods)
    
    OrderBook orderBook{"20200317.csv"};
    Wallet wallet;
};
```

#### Source File (MerkelMain.cpp)

```cpp
void MerkelMain::init() {
    currentTime = orderBook.getEarliestTime();
    wallet.insertCurrency("BTC", 10);
    
    while (true) {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
}

void MerkelMain::enterAsk() {
    std::cout << "Make an ask - enter the amount: product,price,amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenize(input, ',');
    
    if (tokens.size() != 3) {
        std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask
            );
            obe.username = "simuser";
            
            if (wallet.canFulfillOrder(obe)) {
                std::cout << "Wallet looks good." << std::endl;
                orderBook.insertOrder(obe);
            } else {
                std::cout << "Wallet has insufficient funds." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << " MerkelMain::enterAsk Bad input " << std::endl;
        }
    }
    
    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid() {
    std::cout << "Make a bid - enter the amount: product,price,amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenize(input, ',');
    
    if (tokens.size() != 3) {
        std::cout << "MerkelMain::enterBid: bad input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid
            );
            obe.username = "simuser";
            
            if (wallet.canFulfillOrder(obe)) {
                std::cout << "Wallet looks good." << std::endl;
                orderBook.insertOrder(obe);
            } else {
                std::cout << "Wallet has insufficient funds." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << " MerkelMain::enterBid: bad input " << std::endl;
        }
    }
    
    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::printWallet() {
    std::cout << wallet.toString() << std::endl;
}

void MerkelMain::gotoNextTimeframe() {
    std::cout << "Going to next time frame. " << std::endl;
    
    for (std::string &p : orderBook.getKnownProducts()) {
        std::cout << "matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);
        std::cout << "Sales: " << sales.size() << std::endl;
        
        for (OrderBookEntry &sale : sales) {
            std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;
            
            if (sale.username == "simuser") {
                // update the wallet
                wallet.processSale(sale);
            }
        }
    }
    
    currentTime = orderBook.getNextTime(currentTime);
}
```

## Object Interactions

The MerkelRex application demonstrates several types of object interactions:

### Wallet and OrderBookEntry Interaction

The Wallet class interacts with OrderBookEntry objects to check if the user has enough funds to make a trade and to process sales:

```cpp
bool Wallet::canFulfillOrder(OrderBookEntry order) {
    // ...
}

void Wallet::processSale(OrderBookEntry &sale) {
    // ...
}
```

### OrderBook and OrderBookEntry Interaction

The OrderBook class contains a vector of OrderBookEntry objects and provides methods to access and manipulate them:

```cpp
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, 
                                               std::string product, 
                                               std::string timestamp) {
    // ...
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp) {
    // ...
}
```

### MerkelMain, OrderBook, and Wallet Interaction

The MerkelMain class orchestrates the interactions between the OrderBook and Wallet classes:

```cpp
void MerkelMain::enterAsk() {
    // ...
    if (wallet.canFulfillOrder(obe)) {
        orderBook.insertOrder(obe);
    }
    // ...
}

void MerkelMain::gotoNextTimeframe() {
    // ...
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);
    // ...
    if (sale.username == "simuser") {
        wallet.processSale(sale);
    }
    // ...
}
```

## OOP Concepts Demonstrated

Topic 5 introduces several important object-oriented programming concepts:

### Object Composition

The application demonstrates object composition through the relationships between classes:

- MerkelMain has-a OrderBook and a Wallet
- OrderBook has-a vector of OrderBookEntry objects
- Wallet has-a map of currencies

### State Management

The Wallet class demonstrates state management by maintaining the state of the user's currencies:

```cpp
private:
    std::map<std::string, double> currencies;
```

The state is modified through methods like insertCurrency, removeCurrency, and processSale.

### Method Overloading

The OrderBookEntry constructor is overloaded to provide a default value for the username parameter:

```cpp
OrderBookEntry(double price, 
              double amount, 
              std::string timestamp, 
              std::string product, 
              OrderBookType orderType,
              std::string username = "dataset");
```

### Complex Algorithms

The matchAsksToBids method in the OrderBook class demonstrates a complex algorithm for matching asks to bids:

```cpp
std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp) {
    // ...
}
```

This algorithm sorts asks and bids by price, then matches them based on price and amount.

### Error Handling

The application demonstrates error handling through validation checks and try-catch blocks:

```cpp
try {
    OrderBookEntry obe = CSVReader::stringsToOBE(
        tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask
    );
    // ...
} catch (const std::exception& e) {
    std::cout << " MerkelMain::enterAsk Bad input " << std::endl;
}
```

## Key Takeaways

1. **Object Interactions**: Objects interact with each other to achieve complex functionality through a simple command sequence.

2. **State Management**: Classes maintain state through member variables and provide methods to modify and access that state.

3. **Validation**: Validating user actions based on the current state is essential for maintaining data integrity.

4. **Complex Algorithms**: Complex algorithms can be encapsulated in methods to provide high-level functionality.

5. **Error Handling**: Proper error handling is essential for gracefully recovering from errors and providing feedback to the user.

## Conclusion

The MerkelRex application demonstrates how object-oriented programming can be used to model a real-world trading system. By breaking down the system into classes with specific responsibilities and defining how they interact, we've created a modular and maintainable application.

The application allows users to:
- View market statistics
- Make asks and bids
- View their wallet
- Navigate through time to see how the market evolves

The object interactions between the MerkelMain, OrderBook, and Wallet classes enable this functionality while maintaining data integrity and providing a clean user interface.
