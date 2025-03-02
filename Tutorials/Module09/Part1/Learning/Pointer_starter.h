#ifndef POINTER_H
#define POINTER_H

#include <iostream>

/**
 * @brief Class demonstrating basic pointer operations
 * 
 * This class provides methods to demonstrate fundamental pointer concepts
 * including declaration, initialization, dereferencing, and address-of operations.
 */
class PointerDemo {
public:
    /**
     * @brief Demonstrate basic pointer declaration and initialization
     * 
     * Shows how to declare pointers, initialize them with addresses,
     * and use the dereferencing operator.
     */
    void demonstrateBasicPointers();
    
    /**
     * @brief Demonstrate pointer assignment and comparison
     * 
     * Shows how to assign one pointer to another and compare pointers.
     */
    void demonstratePointerAssignment();
    
    /**
     * @brief Demonstrate null pointers and their safe usage
     * 
     * Shows how to initialize and check for null pointers.
     */
    void demonstrateNullPointers();
    
    /**
     * @brief Demonstrate void pointers and type casting
     * 
     * Shows how to use void pointers and cast them to specific types.
     */
    void demonstrateVoidPointers();
    
    /**
     * @brief Demonstrate the relationship between pointers and arrays
     * 
     * Shows how arrays decay to pointers and how to access array elements
     * using pointer notation.
     */
    void demonstratePointersAndArrays();
};

#endif // POINTER_H
