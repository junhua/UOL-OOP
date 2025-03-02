# Base Classes and Derived Classes Practice

This practice exercise will help you understand inheritance in C++ by implementing a vehicle management system.

## Files Overview

- `Vehicle_starter.h` - Base class header file
- `Vehicle_starter.cpp` - Base class implementation
- `Car_starter.h` - Derived class header file
- `Car_starter.cpp` - Derived class implementation
- `main_starter.cpp` - Main program demonstrating inheritance

## Tasks

### 1. Implement the Vehicle Base Class

In `Vehicle_starter.h` and `Vehicle_starter.cpp`:

1. Add protected member variables:
   - make (string)
   - model (string)
   - year (int)
   - price (double)

2. Implement constructor and destructor:
   - Initialize all members
   - Print creation/destruction messages

3. Implement getters:
   - getMake()
   - getModel()
   - getYear()
   - getPrice()

4. Implement virtual methods:
   - displayInfo() - Show vehicle details
   - calculateValue() - Calculate current value with depreciation

### 2. Implement the Car Derived Class

In `Car_starter.h` and `Car_starter.cpp`:

1. Add private member variables:
   - numDoors (int)
   - fuelType (string)

2. Implement constructor:
   - Call base class constructor
   - Initialize Car-specific members
   - Print creation message

3. Implement getters:
   - getNumDoors()
   - getFuelType()

4. Override virtual methods:
   - displayInfo() - Add Car-specific details
   - calculateValue() - Apply fuel type adjustments

### 3. Complete the Main Program

In `main_starter.cpp`:

1. Create a vector of Vehicle pointers

2. Add different vehicles:
   - Toyota Camry (Hybrid)
   - Tesla Model 3 (Electric)
   - Honda Civic (Gasoline)

3. Display information for all vehicles

4. Demonstrate polymorphism:
   - Show how same method calls work differently
   - Display current values with adjustments

5. Clean up allocated memory properly

## Testing

1. Compile your program:
   ```bash
   g++ -o vehicle_system main_starter.cpp Vehicle_starter.cpp Car_starter.cpp
   ```

2. Run the program:
   ```bash
   ./vehicle_system
   ```

3. Verify the output:
   - Check constructor/destructor messages
   - Verify inheritance relationship
   - Confirm polymorphic behavior
   - Ensure proper memory cleanup

## Expected Output

```
Vehicle Management System
==================================================

Creating vehicle: 2020 Toyota Camry
Creating car with 4 doors
Vehicle Information:
===================
Make: Toyota
Model: Camry
Year: 2020
Original Price: $25000.00
Current Value: $18125.00
Type: Car
Number of Doors: 4
Fuel Type: Hybrid

[Similar output for other vehicles...]

Cleaning up...
Destroying car: Honda Civic
Destroying vehicle: 2019 Honda Civic
[Similar cleanup messages for other vehicles...]

Program completed successfully
```

## Tips

1. Use initialization lists in constructors
2. Remember to call base class methods when needed
3. Use override keyword for virtual functions
4. Properly manage memory with new/delete
5. Test with different vehicle types

## Common Issues to Watch For

1. Missing virtual destructor
2. Forgetting to call base class methods
3. Memory leaks in vector cleanup
4. Incorrect inheritance syntax
5. Missing override keyword

Good luck with your implementation!
