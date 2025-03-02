#include <iostream>
#include <vector>
#include <iomanip>
#include "Shape.h"

using namespace std;

/**
 * Shape Hierarchy Solution
 * 
 * This program demonstrates:
 * 1. Proper "is-a" relationships
 * 2. Inheritance chains
 * 3. Method overriding
 * 4. LSP compliance
 * 5. Polymorphic behavior
 */

int main() {
    cout << "Shape Hierarchy Demonstration" << endl;
    cout << string(50, '=') << endl;
    
    // Create a vector of Shape pointers
    vector<Shape*> shapes;
    
    // Add various shapes
    shapes.push_back(new Circle("red", 5));
    shapes.push_back(new Rectangle("blue", 4, 6));
    shapes.push_back(new Square("green", 3));
    
    // Demonstrate polymorphism
    cout << "\nShape Information:" << endl;
    cout << string(50, '=') << endl;
    
    for (const auto& shape : shapes) {
        cout << "\nShape Type: " << typeid(*shape).name() << endl;
        cout << "Color: " << shape->getColor() << endl;
        cout << "Area: " << fixed << setprecision(2) << shape->getArea() << endl;
        cout << "Perimeter: " << shape->getPerimeter() << endl;
        shape->draw();
        cout << string(50, '-') << endl;
    }
    
    // Demonstrate specific shape features
    cout << "\nSpecific Shape Features:" << endl;
    cout << string(50, '=') << endl;
    
    // Circle features
    Circle* circle = new Circle("purple", 2);
    cout << "\nCircle Specific:" << endl;
    cout << "Radius: " << circle->getRadius() << endl;
    cout << "Area: " << circle->getArea() << endl;
    circle->draw();
    
    // Rectangle features
    Rectangle* rectangle = new Rectangle("yellow", 5, 3);
    cout << "\nRectangle Specific:" << endl;
    cout << "Width: " << rectangle->getWidth() << endl;
    cout << "Height: " << rectangle->getHeight() << endl;
    cout << "Area: " << rectangle->getArea() << endl;
    rectangle->draw();
    
    // Square features
    Square* square = new Square("orange", 4);
    cout << "\nSquare Specific:" << endl;
    cout << "Side: " << square->getSide() << endl;
    cout << "Area: " << square->getArea() << endl;
    square->draw();
    
    // Demonstrate LSP
    cout << "\nLSP Demonstration:" << endl;
    cout << string(50, '=') << endl;
    
    // Use Rectangle pointer to Square
    Rectangle* squareAsRect = new Square("pink", 2);
    cout << "\nSquare through Rectangle pointer:" << endl;
    cout << "Width: " << squareAsRect->getWidth() << endl;
    cout << "Height: " << squareAsRect->getHeight() << endl;
    cout << "Area: " << squareAsRect->getArea() << endl;
    squareAsRect->draw();
    
    // Clean up
    cout << "\nCleaning up..." << endl;
    for (auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();
    
    delete circle;
    delete rectangle;
    delete square;
    delete squareAsRect;
    
    cout << "\nProgram completed successfully" << endl;
    
    return 0;
}
