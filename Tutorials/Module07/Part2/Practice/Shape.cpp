#include "Shape.h"

// Shape implementation
Shape::Shape(std::string c) : color(c) {
    std::cout << "Creating " << color << " shape" << std::endl;
}

Shape::~Shape() {
    std::cout << "Destroying " << color << " shape" << std::endl;
}

std::string Shape::getColor() const {
    return color;
}

// Circle implementation
Circle::Circle(std::string color, double r) 
    : Shape(color), radius(r) {
    std::cout << "Creating circle with radius " << radius << std::endl;
}

Circle::~Circle() {
    std::cout << "Destroying " << color << " circle" << std::endl;
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

void Circle::draw() const {
    std::cout << "Drawing " << color << " circle with radius " << radius << std::endl;
    
    // ASCII art circle
    int size = static_cast<int>(radius * 2);
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            double distance = std::sqrt(std::pow(i - radius, 2) + 
                                     std::pow(j - radius, 2));
            std::cout << (distance <= radius ? "*" : " ");
        }
        std::cout << std::endl;
    }
}

double Circle::getRadius() const {
    return radius;
}

// Rectangle implementation
Rectangle::Rectangle(std::string color, double w, double h)
    : Shape(color), width(w), height(h) {
    std::cout << "Creating rectangle " << width << "x" << height << std::endl;
}

Rectangle::~Rectangle() {
    std::cout << "Destroying " << color << " rectangle" << std::endl;
}

double Rectangle::getArea() const {
    return width * height;
}

double Rectangle::getPerimeter() const {
    return 2 * (width + height);
}

void Rectangle::draw() const {
    std::cout << "Drawing " << color << " rectangle " 
              << width << "x" << height << std::endl;
    
    // ASCII art rectangle
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setDimensions(double w, double h) {
    width = w;
    height = h;
}

// Square implementation
Square::Square(std::string color, double side)
    : Rectangle(color, side, side) {
    std::cout << "Creating square with side " << side << std::endl;
}

Square::~Square() {
    std::cout << "Destroying " << color << " square" << std::endl;
}

void Square::draw() const {
    std::cout << "Drawing " << color << " square with side " 
              << getWidth() << std::endl;
    
    // ASCII art square (reuse rectangle's ASCII art)
    Rectangle::draw();
}

double Square::getSide() const {
    return getWidth();  // width == height for square
}

void Square::setSide(double side) {
    setDimensions(side, side);
}
