#include "Shape.h"

Shape::Shape(std::string c) : color(c) {
    std::cout << "Creating " << color << " shape" << std::endl;
}

Shape::~Shape() {
    std::cout << "Destroying " << color << " shape" << std::endl;
}

std::string Shape::getColor() const {
    return color;
}
