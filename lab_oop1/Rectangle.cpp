#include "Rectangle.h"
#include "AppErrors.h"
#include <sstream>

#define EPS 1e-10

Rectangle::Rectangle(const std::string& name, const Point& topLeft, const Point& bottomRight)
    : Shape(name), topLeft(topLeft), bottomRight(bottomRight) {

    double width = bottomRight.x - topLeft.x;
    double height = topLeft.y - bottomRight.y;

    if (width <= EPS || height <= EPS) {
        throw InvalidShapeParameters("Rectangle must have positive width and height.");
    }
}

double Rectangle::area() const {
    double width = bottomRight.x - topLeft.x;
    double height = topLeft.y - bottomRight.y;
    return width * height;
}

std::string Rectangle::type() const {
    return "Rectangle";
}

std::string Rectangle::info() const {
    std::ostringstream oss;
    oss << "Rectangle \"" << name << "\" | Top-left: ("
        << topLeft.x << ", " << topLeft.y << ") | Bottom-right: ("
        << bottomRight.x << ", " << bottomRight.y << ")";
    return oss.str();
}

std::string Rectangle::parameters() const {
    std::ostringstream oss;
    oss << "Top-left corner: " << topLeft.toString()
        << ", bottom-right corner: " << bottomRight.toString();
    return oss.str();
}
