#include "Rectangle.h"
#include "AppErrors.h"
#include <sstream>

#define EPS 1e-10

Rectangle::Rectangle(const std::string& name, const Point& topLeft, const Point& bottomRight)
    : Shape(name), topLeft(topLeft), bottomRight(bottomRight) {

    double width = bottomRight.getX() - topLeft.getX();
    double height = topLeft.getY() - bottomRight.getY();

    if (width <= EPS || height <= EPS) {
        throw InvalidShapeParameters("Rectangle must have positive width and height.");
    }
}

double Rectangle::area() const {
    double width = bottomRight.getX() - topLeft.getX();
    double height = topLeft.getY() - bottomRight.getY();
    return width * height;
}

std::string Rectangle::type() const {
    return "Rectangle";
}

std::string Rectangle::info() const {
    std::ostringstream oss;
    oss << "Rectangle \"" << name << "\" | Top-left: ("
        << topLeft.getX() << ", " << topLeft.getY() << ") | Bottom-right: ("
        << bottomRight.getX() << ", " << bottomRight.getY() << ")";
    return oss.str();
}

std::string Rectangle::parameters() const {
    std::ostringstream oss;
    oss << "Top-left corner: " << topLeft.toString()
        << ", bottom-right corner: " << bottomRight.toString();
    return oss.str();
}
