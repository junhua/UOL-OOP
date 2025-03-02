#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

class Shape {
protected:
    std::string color;
    
public:
    // Constructor
    Shape(std::string c);
    
    // Virtual destructor
    virtual ~Shape();
    
    // Pure virtual methods
    virtual double getArea() const = 0;
    virtual void draw() const = 0;
    
    // Getter
    std::string getColor() const;
};

#endif // SHAPE_H
