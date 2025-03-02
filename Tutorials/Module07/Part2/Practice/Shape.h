#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <cmath>

class Shape {
protected:
    std::string color;
    
public:
    // Constructor and destructor
    Shape(std::string c);
    virtual ~Shape();
    
    // Pure virtual methods
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
    
    // Getter
    std::string getColor() const;
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(std::string color, double r);
    ~Circle() override;
    
    double getArea() const override;
    double getPerimeter() const override;
    void draw() const override;
    
    double getRadius() const;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(std::string color, double w, double h);
    ~Rectangle() override;
    
    double getArea() const override;
    double getPerimeter() const override;
    void draw() const override;
    
    double getWidth() const;
    double getHeight() const;
    
    // Protected setter for use by Square
protected:
    void setDimensions(double w, double h);
};

class Square : public Rectangle {
public:
    Square(std::string color, double side);
    ~Square() override;
    
    // No need to override area/perimeter as they work the same
    void draw() const override;
    
    double getSide() const;
    void setSide(double side);
};

#endif // SHAPE_H
