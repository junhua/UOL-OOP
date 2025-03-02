#ifndef WIDGET_H
#define WIDGET_H

#include <string>
#include <iostream>

// TODO: Implement the Widget base class
class Widget {
public:
    // TODO: Add public members:
    // - Constructor(id, x, y, width, height)
    // - draw(): Draw the widget
    // - move(newX, newY): Move widget
    // - resize(newWidth, newHeight): Resize widget
    // - getId(): Return widget ID
    
protected:
    // TODO: Add protected members:
    // - id (string)
    // - x, y (int): Position
    // - width, height (int): Size
    // - isVisible (bool)
    // - updatePosition(): Update coordinates
    // - updateSize(): Update dimensions
    
private:
    // TODO: Add private members:
    // - validatePosition(): Check bounds
    // - validateSize(): Check dimensions
    // - notifyUpdate(): Signal changes
};

// TODO: Implement Button with public inheritance
class Button {
    // TODO: Add members:
    // - label (string)
    // - isPressed (bool)
    // - onClick (function pointer)
    // Override draw() with button style
    // Add press() and release() methods
};

// TODO: Implement Container with protected inheritance
class Container {
    // TODO: Add members:
    // - children (vector<Widget*>)
    // - layout (string)
    // Override resize() to handle children
    // Add addChild() and removeChild()
};

// TODO: Implement Implementation with private inheritance
class Implementation {
    // TODO: Add members:
    // - renderMode (string)
    // - bufferSize (int)
    // - useHardware (bool)
    // Selectively expose drawing methods
    // Add optimization methods
};

#endif // WIDGET_H
