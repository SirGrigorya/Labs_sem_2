#include "Circle.h"
#include "Errors.h"
#include <cmath>
#include <sstream>

Circle::Circle(const std::string& name, double centerX, double centerY, double radius)
    : name(name), centerX(centerX), centerY(centerY) {
    if (radius < 0) {
        throw InvalidCircleError("Радиус круга не может быть отрицательным.");
    }
    this->radius = radius;
}

std::string Circle::getName() const {
    return name;
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

std::string Circle::getInfo() const {
    std::ostringstream oss;
    oss << "Circle: " << name << ", Центр: (" << centerX << ", " << centerY << "), Радиус: " << radius;
    return oss.str();
}
