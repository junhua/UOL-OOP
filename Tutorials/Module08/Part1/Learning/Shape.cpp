#include "Shape.h"
#include <iostream>

Shape::Shape(std::string c) : color(c) {
    std::cout << "Creating " << color << " shape" << std::endl;
}

Shape::~Shape() {
    std::cout << "Destroying " << color << " shape" << std::endl;
}

std::string Shape::getColor() const {
    return color;
}

void Shape::displayInfo() const {
    std::cout << "\nShape Information:" << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
}
