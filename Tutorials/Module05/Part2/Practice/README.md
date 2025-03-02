# Module 5 - Part 2: Practice Exercises

This directory contains three practice exercises focusing on constructors, destructors, and resource management in C++.

## Exercise 1: Database Connection

Files:
- `DatabaseConnection_starter.h`
- `DatabaseConnection_starter.cpp`
- `database_main_starter.cpp`

This exercise simulates a database connection manager, focusing on:
- Resource acquisition and release
- Move semantics for connection handling
- Error handling and state management
- Transaction support

Key concepts to implement:
1. Constructor for establishing connections
2. Destructor for proper cleanup
3. Move operations for connection transfer
4. Connection state management
5. Query execution and logging
6. Transaction handling

## Exercise 2: Image Processing

Files:
- `Image_starter.h`
- `Image_starter.cpp`
- `image_main_starter.cpp`

This exercise implements an image processing class, focusing on:
- Dynamic memory management
- Copy and move semantics
- Resource cleanup
- Image manipulation operations

Key concepts to implement:
1. Pixel data management
2. Copy and move operations
3. Image transformations
4. Memory cleanup
5. Error handling
6. File I/O operations

## Exercise 3: Thread Pool

Files:
- `ThreadPool_starter.h`
- `ThreadPool_starter.cpp`
- `threadpool_main_starter.cpp`

This exercise creates a thread pool implementation, focusing on:
- Thread lifecycle management
- Task queue handling
- Synchronization
- Resource cleanup

Key concepts to implement:
1. Thread creation and management
2. Task queue operations
3. Thread synchronization
4. Pool control operations
5. Error handling
6. Resource cleanup

## Getting Started

1. Each exercise has three files:
   - Header file (`.h`) defining the class interface
   - Implementation file (`.cpp`) with function stubs
   - Main file for testing

2. Start by reading the header files to understand:
   - Class structure
   - Available methods
   - TODO comments

3. Implement the functions in the cpp files:
   - Follow the TODO comments
   - Consider edge cases
   - Handle errors appropriately

4. Use the main files to:
   - Test your implementation
   - Verify functionality
   - Check error handling

## Testing Your Implementation

Each exercise includes a comprehensive test suite:

1. **Database Connection**:
   ```bash
   g++ -std=c++17 DatabaseConnection_starter.cpp database_main_starter.cpp -o db_test
   ./db_test
   ```

2. **Image Processing**:
   ```bash
   g++ -std=c++17 Image_starter.cpp image_main_starter.cpp -o image_test
   ./image_test
   ```

3. **Thread Pool**:
   ```bash
   g++ -std=c++17 ThreadPool_starter.cpp threadpool_main_starter.cpp -o thread_test -pthread
   ./thread_test
   ```

## Tips

1. **Resource Management**:
   - Always clean up resources in destructors
   - Use RAII principles
   - Handle allocation failures

2. **Error Handling**:
   - Check for invalid parameters
   - Handle resource allocation failures
   - Use exceptions appropriately

3. **Testing**:
   - Run all test cases
   - Check edge cases
   - Verify resource cleanup

4. **Documentation**:
   - Read the comments carefully
   - Document your implementation
   - Explain complex logic

## Common Pitfalls

1. **Memory Leaks**:
   - Forgetting to delete resources
   - Not handling allocation failures
   - Incorrect copy/move operations

2. **Thread Safety**:
   - Missing synchronization
   - Deadlocks
   - Race conditions

3. **Error Handling**:
   - Not checking return values
   - Ignoring edge cases
   - Improper exception handling

## Additional Challenges

Once you complete the basic implementation, try these extensions:

1. **Database Connection**:
   - Add connection pooling
   - Implement retry logic
   - Add connection string parsing

2. **Image Processing**:
   - Add more transformations
   - Implement filters
   - Add format conversion

3. **Thread Pool**:
   - Add priority queue
   - Implement thread scaling
   - Add task cancellation

## Learning Outcomes

After completing these exercises, you should understand:
- Constructor and destructor behavior
- Resource management principles
- Move semantics
- Error handling
- Thread safety
- RAII pattern
