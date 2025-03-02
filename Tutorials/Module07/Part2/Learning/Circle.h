#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
private:
    double radius;
    
public:
    // Constructor
    Circle(std::string color, double r);
    
    // Destructor
    ~Circle() override;
    
    // Override base class methods
    double getArea() const override;
    void draw() const override;
    
    // Circle-specific getter
    double getRadius() const;
};

#endif // CIRCLE_H
