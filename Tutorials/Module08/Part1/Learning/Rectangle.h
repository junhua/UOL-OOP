#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

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
    double width;
    double height;
    
public:
    /**
     * @brief Constructor
     * @param color The color of the rectangle
     * @param width The width of the rectangle
     * @param height The height of the rectangle
     */
    Rectangle(std::string color, double w, double h);
    
    /**
     * @brief Destructor
     */
    ~Rectangle() override;
    
    /**
     * @brief Get the rectangle's width
     * @return The width as a double
     */
    double getWidth() const;
    
    /**
     * @brief Get the rectangle's height
     * @return The height as a double
     */
    double getHeight() const;
    
    /**
     * @brief Calculate the area of the rectangle
     * @return The area as a double (width * height)
     */
    double getArea() const override;
    
    /**
     * @brief Draw the rectangle
     * 
     * This method displays a simple representation of a rectangle.
     */
    void draw() const override;
    
    /**
     * @brief Display information about the rectangle
     * 
     * This method calls the base class displayInfo method
     * and then adds rectangle-specific information.
     */
    void displayInfo() const override;
};

#endif // RECTANGLE_H
