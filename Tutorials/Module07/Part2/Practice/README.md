# "is-a" Relationship Practice Exercises

This directory contains three practice exercises demonstrating proper use of inheritance and "is-a" relationships in C++.

## Exercise 1: Shape Hierarchy

Files:
- `Shape_starter.h`
- `main_starter.cpp`

Task: Implement a shape hierarchy that demonstrates proper inheritance relationships:
1. Shape (base class)
2. Circle (inherits from Shape)
3. Rectangle (inherits from Shape)
4. Square (inherits from Rectangle)

Key Concepts:
- Pure virtual methods
- Method overriding
- LSP compliance
- Proper inheritance chains

## Exercise 2: Vehicle System

Files:
- `Vehicle_starter.h`
- `vehicle_main_starter.cpp`

Task: Create a vehicle classification system with multi-level inheritance:
1. Vehicle (base class)
2. LandVehicle (inherits from Vehicle)
3. Car (inherits from LandVehicle)
4. Motorcycle (inherits from LandVehicle)

Key Concepts:
- Multi-level inheritance
- Specialized behaviors
- Common operations
- Type hierarchies

## Exercise 3: Banking System

Files:
- `Account_starter.h`
- `banking_main_starter.cpp`

Task: Implement a banking system with inheritance-based account types:
1. Account (base class)
2. SavingsAccount (inherits from Account)
3. CheckingAccount (inherits from Account)
4. MoneyMarket (inherits from SavingsAccount)

Key Concepts:
- Financial operations
- Transaction tracking
- Specialized account features
- Complex inheritance relationships

## Building and Testing

1. Complete the starter header files first
2. Implement all required methods
3. Use the starter main files to test
4. Compile with:
   ```bash
   # For Exercise 1
   g++ main_starter.cpp -o shape_test
   
   # For Exercise 2
   g++ vehicle_main_starter.cpp -o vehicle_test
   
   # For Exercise 3
   g++ banking_main_starter.cpp -o banking_test
   ```

## Common Pitfalls to Avoid

1. Forced Relationships
   - Don't create inheritance relationships that don't make logical sense
   - Use the "is-a" test before implementing inheritance

2. LSP Violations
   - Derived classes should be substitutable for their base class
   - Override methods without breaking base class contracts

3. Deep Hierarchies
   - Keep inheritance chains reasonable
   - Consider composition as an alternative

4. Missing Virtual Destructors
   - Always make base class destructors virtual
   - Clean up resources properly

5. Access Level Mistakes
   - Use protected for members needed by derived classes
   - Keep implementation details private
   - Make interface methods public

## Best Practices

1. Use clear naming conventions
2. Document class relationships
3. Test thoroughly with polymorphism
4. Handle errors appropriately
5. Clean up allocated memory
6. Follow LSP principles
7. Keep hierarchies shallow
8. Use override keyword

## Testing Your Implementation

Each exercise includes a main file with test cases. Make sure your implementation:
1. Compiles without warnings
2. Runs without memory leaks
3. Produces expected output
4. Handles edge cases
5. Demonstrates proper inheritance
6. Shows correct polymorphic behavior

## Next Steps

After completing these exercises:
1. Add more derived classes
2. Implement additional features
3. Add error handling
4. Write unit tests
5. Consider real-world applications

Remember: The goal is to understand and properly implement "is-a" relationships. Take time to think about the relationships before coding.
