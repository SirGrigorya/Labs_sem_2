#include "Circle.h"
#include <cmath>
#include <sstream>

Circle::Circle(const std::string& name, double centerX, double centerY, double radius)
    : Shape(name), centerX(centerX), centerY(centerY), radius(radius) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

std::string Circle::getInfo() const {
    std::ostringstream oss;
    oss << getName() << ", Центр: (" << centerX << ", " << centerY << "), Радиус: " << radius;
    return oss.str();
}
