#include "Circle.h"
#include "AppErrors.h"
#include <cmath>
#include <sstream>

#define EPS 1e-10
#define MIN_RADIUS EPS

Circle::Circle(const std::string& name, const Point& center, double radius)
    : Shape(name), center(center), radius(radius) {

    if (radius <= MIN_RADIUS) {
        throw InvalidShapeParameters("Radius must be positive.");
    }
}

double Circle::area() const {
    return M_PI * radius * radius;
}

std::string Circle::type() const {
    return "Circle";
}

std::string Circle::info() const {
    std::ostringstream oss;
    oss << "Circle \"" << name << "\" | Center: ("
        << center.getX() << ", " << center.getY() << ") | Radius: " << radius;
    return oss.str();
}

std::string Circle::parameters() const {
    std::ostringstream oss;
    oss << "Center: " << center.toString() << ", radius: " << radius;
    return oss.str();
}

Circle::~Circle() = default;
