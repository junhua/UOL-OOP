#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <cmath>

/**
 * @class Shape
 * @brief Abstract base class for all shapes
 * 
 * This class defines the common interface for all shapes in our system.
 * It provides pure virtual methods that all derived classes must implement,
 * as well as common functionality shared by all shapes.
 */
class Shape {
protected:
    // TODO: Add a protected member variable to store the shape's color
    
public:
    /**
     * @brief Constructor
     * @param color The color of the shape
     */
    // TODO: Implement constructor that initializes the color and prints a message
    
    /**
     * @brief Virtual destructor
     * 
     * Virtual destructor is essential for proper cleanup of derived objects
     * when deleted through a base class pointer.
     */
    // TODO: Implement virtual destructor that prints a message
    
    /**
     * @brief Get the shape's color
     * @return The color as a string
     */
    // TODO: Implement a getter for the color
    
    /**
     * @brief Calculate the area of the shape
     * @return The area as a double
     * 
     * This is a pure virtual method that must be implemented by all derived classes.
     */
    // TODO: Declare a pure virtual method to calculate the area
    
    /**
     * @brief Draw the shape
     * 
     * This is a pure virtual method that must be implemented by all derived classes.
     * Each shape will provide its own drawing implementation.
     */
    // TODO: Declare a pure virtual method to draw the shape
    
    /**
     * @brief Display information about the shape
     * 
     * This method displays common information about the shape.
     * It can be overridden by derived classes to add more specific information.
     */
    // TODO: Implement a virtual method to display shape information
};

#endif // SHAPE_H
