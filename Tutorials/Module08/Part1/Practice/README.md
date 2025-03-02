# Polymorphism Practice Exercises

This directory contains practice exercises to help you master polymorphism concepts in C++.

## Exercise 1: Game Character System

Create a polymorphic game character system with the following requirements:

1. Create an abstract `Character` base class with:
   - Protected member variables for name, health, and power
   - Pure virtual methods for `attack()` and `defend()`
   - Virtual method for `displayStats()`
   - Virtual destructor

2. Create at least three derived character classes:
   - `Warrior` (high health, strong attacks)
   - `Mage` (low health, powerful spells)
   - `Rogue` (medium health, stealth abilities)

3. Each derived class should:
   - Override the pure virtual methods
   - Add class-specific attributes and methods
   - Implement proper constructors and destructors

4. Create a main program that:
   - Creates a collection of different character types
   - Processes them polymorphically
   - Demonstrates virtual method calls
   - Shows proper memory management

### Files to Modify:
- `Character_starter.h` and `Character_starter.cpp`
- `Warrior_starter.h` and `Warrior_starter.cpp`
- `Mage_starter.h` and `Mage_starter.cpp`
- `Rogue_starter.h` and `Rogue_starter.cpp`
- `main_starter.cpp`

## Exercise 2: Vehicle Hierarchy

Create a polymorphic vehicle system with the following requirements:

1. Create an abstract `Vehicle` base class with:
   - Protected member variables for make, model, year, and price
   - Pure virtual method for `calculateValue()`
   - Virtual method for `displayInfo()`
   - Virtual destructor

2. Create at least three derived vehicle classes:
   - `Car` (with number of doors, fuel type)
   - `Motorcycle` (with engine size, has sidecar)
   - `Truck` (with cargo capacity, towing capacity)

3. Each derived class should:
   - Override the pure virtual methods
   - Add class-specific attributes and methods
   - Implement proper constructors and destructors

4. Create a main program that:
   - Creates a collection of different vehicle types
   - Processes them polymorphically
   - Demonstrates virtual method calls
   - Shows proper memory management

### Files to Modify:
- `Vehicle_starter.h` and `Vehicle_starter.cpp`
- `Car_starter.h` and `Car_starter.cpp`
- `Motorcycle_starter.h` and `Motorcycle_starter.cpp`
- `Truck_starter.h` and `Truck_starter.cpp`
- `vehicle_main_starter.cpp`

## Exercise 3: Banking System

Create a polymorphic banking system with the following requirements:

1. Create an abstract `Account` base class with:
   - Protected member variables for account number, owner name, and balance
   - Pure virtual methods for `deposit()` and `withdraw()`
   - Virtual method for `displayInfo()`
   - Virtual destructor

2. Create at least three derived account classes:
   - `SavingsAccount` (with interest rate, minimum balance)
   - `CheckingAccount` (with transaction fee, overdraft limit)
   - `CreditAccount` (with credit limit, interest rate)

3. Each derived class should:
   - Override the pure virtual methods with appropriate behavior
   - Add class-specific attributes and methods
   - Implement proper constructors and destructors

4. Create a main program that:
   - Creates a collection of different account types
   - Processes them polymorphically
   - Demonstrates virtual method calls
   - Shows proper memory management

### Files to Modify:
- `Account_starter.h` and `Account_starter.cpp`
- `SavingsAccount_starter.h` and `SavingsAccount_starter.cpp`
- `CheckingAccount_starter.h` and `CheckingAccount_starter.cpp`
- `CreditAccount_starter.h` and `CreditAccount_starter.cpp`
- `banking_main_starter.cpp`

## Building and Testing

For each exercise, compile and run your program using:

```bash
# For Exercise 1:
g++ -o game_characters main_starter.cpp Character_starter.cpp Warrior_starter.cpp Mage_starter.cpp Rogue_starter.cpp
./game_characters

# For Exercise 2:
g++ -o vehicles vehicle_main_starter.cpp Vehicle_starter.cpp Car_starter.cpp Motorcycle_starter.cpp Truck_starter.cpp
./vehicles

# For Exercise 3:
g++ -o banking banking_main_starter.cpp Account_starter.cpp SavingsAccount_starter.cpp CheckingAccount_starter.cpp CreditAccount_starter.cpp
./banking
```

## Tips for Success

1. **Start with the base class**: Implement the abstract base class first to establish the interface.
2. **One class at a time**: Implement one derived class completely before moving to the next.
3. **Test incrementally**: Test each class as you implement it.
4. **Use the override keyword**: Always use the `override` keyword for overridden methods.
5. **Memory management**: Use smart pointers for polymorphic collections.
6. **Follow LSP**: Ensure derived classes can substitute for the base class.
7. **Document your code**: Add comments explaining your implementation decisions.

## Solution Files

Reference solutions are available in the `Solutions` directory. Try to complete the exercises on your own before looking at the solutions.
