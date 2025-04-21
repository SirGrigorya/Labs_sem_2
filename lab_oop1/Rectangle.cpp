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
    double* width = new double(bottomRight.x - topLeft.x);
    double* height = new double(topLeft.y - bottomRight.y);
    double result = (*width) * (*height);
    delete width;
    delete height;
    return result;
}

std::string Rectangle::type() const {
    std::string result = "Rectangle";
    return result;
}

std::string Rectangle::info() const {
    std::ostringstream* oss = new std::ostringstream;
    *oss << "Rectangle \"" << name << "\" | Top-left: ("
         << topLeft.x << ", " << topLeft.y << ") | Bottom-right: ("
         << bottomRight.x << ", " << bottomRight.y << ")";
    std::string result = oss->str();
    delete oss;
    return result;
}

std::string Rectangle::parameters() const {
    std::ostringstream* oss = new std::ostringstream;
    *oss << "Top-left corner: " << topLeft.toString()
         << ", bottom-right corner: " << bottomRight.toString();
    std::string result = oss->str();
    delete oss;
    return result;
}
