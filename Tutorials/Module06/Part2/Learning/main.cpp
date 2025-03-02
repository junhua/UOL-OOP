#include <iostream>
#include <iomanip>
#include <vector>
#include "AccessControl.h"
using namespace std;

// Helper function to display shape information
void displayShape(const Shape& shape) {
    cout << "Position: (" << shape.getX() << ", " << shape.getY() << ")" << endl;
    cout << "Dimensions: " << shape.getWidth() << " x " << shape.getHeight() << endl;
    cout << "Color: " << shape.getColor() << endl;
    cout << "Area: " << shape.area() << endl;
    cout << "Visible: " << (shape.isVisible() ? "Yes" : "No") << endl;
}

int main() {
    cout << "Access Control Example" << endl;
    cout << "====================" << endl;
    
    // Demonstrate poor access control
    cout << "\nPoor Access Control Example:" << endl;
    cout << "-------------------------" << endl;
    
    ShapePoor poorShape;
    poorShape.x = -100;  // Invalid position, no validation
    poorShape.y = -50;
    poorShape.width = -10;  // Invalid dimension, no validation
    poorShape.height = 0;
    poorShape.color = "invalid_color";  // Invalid color, no validation
    
    cout << "Poor Shape State:" << endl;
    cout << "Position: (" << poorShape.x << ", " << poorShape.y << ")" << endl;
    cout << "Dimensions: " << poorShape.width << " x " << poorShape.height << endl;
    cout << "Color: " << poorShape.color << endl;
    
    // Demonstrate good access control with Rectangle
    cout << "\nGood Access Control Example (Rectangle):" << endl;
    cout << "-----------------------------------" << endl;
    
    Rectangle rect(10, 20, 30, 40, "blue");
    
    cout << "1. Initial state:" << endl;
    displayShape(rect);
    
    // Demonstrate validation
    cout << "\n2. Validation in action:" << endl;
    
    if (!rect.resize(-10, 50)) {
        cout << "Prevented invalid width" << endl;
    }
    
    if (!rect.setColor("purple")) {
        cout << "Prevented invalid color" << endl;
    }
    
    if (rect.resize(60, 70)) {
        cout << "Valid resize successful" << endl;
    }
    
    if (rect.setColor("red")) {
        cout << "Valid color change successful" << endl;
    }
    
    // Show updated state
    cout << "\n3. After valid changes:" << endl;
    displayShape(rect);
    
    // Demonstrate visibility control
    rect.hide();
    cout << "\n4. After hiding:" << endl;
    displayShape(rect);
    
    // Demonstrate Circle with different behavior
    cout << "\nCircle Example:" << endl;
    cout << "-------------" << endl;
    
    Circle circle(100, 100, 50, "green");
    
    cout << "1. Initial state:" << endl;
    displayShape(circle);
    cout << "Radius: " << circle.getRadius() << endl;
    
    // Demonstrate radius changes affecting dimensions
    if (circle.setRadius(75)) {
        cout << "\n2. After radius change:" << endl;
        displayShape(circle);
        cout << "New radius: " << circle.getRadius() << endl;
    }
    
    // Demonstrate inheritance and polymorphism
    cout << "\nPolymorphic Behavior:" << endl;
    cout << "-------------------" << endl;
    
    vector<Shape*> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circle);
    
    for (size_t i = 0; i < shapes.size(); i++) {
        cout << "\nShape " << (i + 1) << ":" << endl;
        displayShape(*shapes[i]);
    }
    
    cout << "\nKey Benefits of Good Access Control:" << endl;
    cout << "1. Data validation enforced" << endl;
    cout << "2. State consistency maintained" << endl;
    cout << "3. Implementation details hidden" << endl;
    cout << "4. Interface clearly defined" << endl;
    cout << "5. Inheritance properly supported" << endl;
    
    return 0;
}
