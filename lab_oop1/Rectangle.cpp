#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle(const std::string& name, double topLeftX, double topLeftY, double bottomRightX, double bottomRightY)
    : name(name), topLeftX(topLeftX), topLeftY(topLeftY), bottomRightX(bottomRightX), bottomRightY(bottomRightY) {}

std::string Rectangle::getName() const {
    return name;
}

double Rectangle::getArea() const {
    double width = bottomRightX - topLeftX;
    double height = topLeftY - bottomRightY;
    return std::abs(width * height);
}

std::string Rectangle::getInfo() const {
    std::ostringstream oss;
    oss << "Прямоугольник: " << name << ", Верхний Левый: (" << topLeftX << ", " << topLeftY
        << "), Нижний Правый: (" << bottomRightX << ", " << bottomRightY << ")";
    return oss.str();
}
