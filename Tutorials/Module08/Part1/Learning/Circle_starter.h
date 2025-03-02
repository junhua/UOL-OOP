#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape_starter.h"

/**
 * @class Circle
 * @brief Circle shape derived from Shape
 * 
 * This class represents a circle with a specific radius.
 * It inherits from the Shape base class and implements
 * all the required virtual methods.
 */
class Circle : public Shape {
private:
    // TODO: Add a private member variable to store the circle's radius
    
public:
    /**
     * @brief Constructor
     * @param color The color of the circle
     * @param radius The radius of the circle
     */
    // TODO: Implement constructor that initializes the base class and radius
    
    /**
     * @brief Destructor
     */
    // TODO: Implement destructor that prints a message
    
    /**
     * @brief Get the circle's radius
     * @return The radius as a double
     */
    // TODO: Implement a getter for the radius
    
    /**
     * @brief Calculate the area of the circle
     * @return The area as a double (π * radius^2)
     */
    // TODO: Override the getArea method from the base class
    
    /**
     * @brief Draw the circle
     * 
     * This method should display a simple representation of a circle.
     */
    // TODO: Override the draw method from the base class
    
    /**
     * @brief Display information about the circle
     * 
     * This method should call the base class displayInfo method
     * and then add circle-specific information.
     */
    // TODO: Override the displayInfo method from the base class
};

#endif // CIRCLE_H
