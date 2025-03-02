#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(std::string color, double w, double h)
    : Shape(color), width(w), height(h) {
    std::cout << "Creating rectangle with dimensions " << width << "x" << height << std::endl;
}

Rectangle::~Rectangle() {
    std::cout << "Destroying rectangle with dimensions " << width << "x" << height << std::endl;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::draw() const {
    std::cout << "Drawing " << getColor() << " rectangle with dimensions " << width << "x" << height << std::endl;
    
    // Simple ASCII art rectangle
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void Rectangle::displayInfo() const {
    Shape::displayInfo();
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
}
