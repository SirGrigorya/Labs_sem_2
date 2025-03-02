#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(const std::string& name, double topLeftX, double topLeftY, double bottomRightX, double bottomRightY)
    : Shape(name), topLeftX(topLeftX), topLeftY(topLeftY), bottomRightX(bottomRightX), bottomRightY(bottomRightY) {}

double Rectangle::getArea() const {
    double width = bottomRightX - topLeftX;
    double height = topLeftY - bottomRightY;
    return std::abs(width * height);
}

double Rectangle::getPerimeter() const {
    double width = bottomRightX - topLeftX;
    double height = topLeftY - bottomRightY;
    return 2 * (width + height);
}

std::string Rectangle::getInfo() const {
    std::ostringstream oss;
    oss << getName() << ", Верхний Левый: (" << topLeftX << ", " << topLeftY
        << "), Нижний Правый: (" << bottomRightX << ", " << bottomRightY << ")";
    return oss.str();
}
