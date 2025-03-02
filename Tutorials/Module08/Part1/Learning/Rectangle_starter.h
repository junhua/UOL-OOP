#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape_starter.h"

/**
 * @class Rectangle
 * @brief Rectangle shape derived from Shape
 * 
 * This class represents a rectangle with width and height.
 * It inherits from the Shape base class and implements
 * all the required virtual methods.
 */
class Rectangle : public Shape {
private:
    // TODO: Add private member variables to store the rectangle's width and height
    
public:
    /**
     * @brief Constructor
     * @param color The color of the rectangle
     * @param width The width of the rectangle
     * @param height The height of the rectangle
     */
    // TODO: Implement constructor that initializes the base class, width, and height
    
    /**
     * @brief Destructor
     */
    // TODO: Implement destructor that prints a message
    
    /**
     * @brief Get the rectangle's width
     * @return The width as a double
     */
    // TODO: Implement a getter for the width
    
    /**
     * @brief Get the rectangle's height
     * @return The height as a double
     */
    // TODO: Implement a getter for the height
    
    /**
     * @brief Calculate the area of the rectangle
     * @return The area as a double (width * height)
     */
    // TODO: Override the getArea method from the base class
    
    /**
     * @brief Draw the rectangle
     * 
     * This method should display a simple representation of a rectangle.
     */
    // TODO: Override the draw method from the base class
    
    /**
     * @brief Display information about the rectangle
     * 
     * This method should call the base class displayInfo method
     * and then add rectangle-specific information.
     */
    // TODO: Override the displayInfo method from the base class
};

#endif // RECTANGLE_H
