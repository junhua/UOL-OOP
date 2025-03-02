# Abstract Classes Practice Exercises

This directory contains practice exercises for working with abstract classes and pure virtual functions in C++.

## Exercise 1: Media Player System

Create a media player system with the following classes:
- `MediaItem` (abstract base class)
- `Song` (derived from MediaItem)
- `Video` (derived from MediaItem)
- `Podcast` (derived from MediaItem)

### Requirements:
1. The `MediaItem` class should have:
   - Protected members for title, artist, and duration
   - Pure virtual methods for `play()` and `displayInfo()`
   - Virtual methods for `pause()` and `stop()`
   - A non-virtual method for `getDuration()`

2. Each derived class should:
   - Override the pure virtual methods
   - Add class-specific attributes and methods
   - Implement proper constructors and destructors

3. In your main program:
   - Create a playlist of MediaItem pointers
   - Add different media types to the playlist
   - Demonstrate polymorphism by playing items in the playlist

## Exercise 2: Banking System

Create a banking system with the following classes:
- `Account` (abstract base class)
- `SavingsAccount` (derived from Account)
- `CheckingAccount` (derived from Account)
- `CreditAccount` (derived from Account)

### Requirements:
1. The `Account` class should have:
   - Protected members for accountNumber, customerName, and balance
   - Pure virtual methods for `calculateInterest()` and `displayInfo()`
   - Virtual methods for `deposit()` and `withdraw()`
   - A non-virtual method for `getBalance()`

2. Each derived class should:
   - Override the pure virtual methods with appropriate implementations
   - Add class-specific attributes (interestRate, overdraftLimit, creditLimit, etc.)
   - Implement proper constructors and destructors

3. In your main program:
   - Create an array of Account pointers
   - Add various account types to the array
   - Process transactions and calculate interest for all accounts

## Exercise 3: Game Character System

Create a game character system with the following classes:
- `Character` (abstract base class)
- `Warrior` (derived from Character)
- `Mage` (derived from Character)
- `Archer` (derived from Character)

### Requirements:
1. The `Character` class should have:
   - Protected members for name, health, and level
   - Pure virtual methods for `attack()` and `specialAbility()`
   - Virtual methods for `takeDamage()` and `heal()`
   - A non-virtual method for `getHealth()`

2. Each derived class should:
   - Override the pure virtual methods with class-specific implementations
   - Add class-specific attributes and methods
   - Implement proper constructors and destructors

3. In your main program:
   - Create a party of Character pointers
   - Add different character types to the party
   - Simulate a battle where characters attack and use special abilities

## Submission

Complete the starter files provided for each exercise:
- `MediaItem_starter.h/cpp`, `Song_starter.h/cpp`, etc.
- `Account_starter.h/cpp`, `SavingsAccount_starter.h/cpp`, etc.
- `Character_starter.h/cpp`, `Warrior_starter.h/cpp`, etc.

Test your implementation using the provided `main_starter.cpp` files.
