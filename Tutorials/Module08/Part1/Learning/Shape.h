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
    std::string color;
    
public:
    /**
     * @brief Constructor
     * @param color The color of the shape
     */
    Shape(std::string c);
    
    /**
     * @brief Virtual destructor
     * 
     * Virtual destructor is essential for proper cleanup of derived objects
     * when deleted through a base class pointer.
     */
    virtual ~Shape();
    
    /**
     * @brief Get the shape's color
     * @return The color as a string
     */
    std::string getColor() const;
    
    /**
     * @brief Calculate the area of the shape
     * @return The area as a double
     * 
     * This is a pure virtual method that must be implemented by all derived classes.
     */
    virtual double getArea() const = 0;
    
    /**
     * @brief Draw the shape
     * 
     * This is a pure virtual method that must be implemented by all derived classes.
     * Each shape will provide its own drawing implementation.
     */
    virtual void draw() const = 0;
    
    /**
     * @brief Display information about the shape
     * 
     * This method displays common information about the shape.
     * It can be overridden by derived classes to add more specific information.
     */
    virtual void displayInfo() const;
};

#endif // SHAPE_H
