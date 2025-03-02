#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

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
    double radius;
    
public:
    /**
     * @brief Constructor
     * @param color The color of the circle
     * @param radius The radius of the circle
     */
    Circle(std::string color, double r);
    
    /**
     * @brief Destructor
     */
    ~Circle() override;
    
    /**
     * @brief Get the circle's radius
     * @return The radius as a double
     */
    double getRadius() const;
    
    /**
     * @brief Calculate the area of the circle
     * @return The area as a double (π * radius^2)
     */
    double getArea() const override;
    
    /**
     * @brief Draw the circle
     * 
     * This method displays a simple representation of a circle.
     */
    void draw() const override;
    
    /**
     * @brief Display information about the circle
     * 
     * This method calls the base class displayInfo method
     * and then adds circle-specific information.
     */
    void displayInfo() const override;
};

#endif // CIRCLE_H
