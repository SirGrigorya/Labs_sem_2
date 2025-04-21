#include "Circle.h"
#include "AppErrors.h"
#include <cmath>
#include <sstream>

#define EPS 1e-9
#define MIN_RADIUS EPS

Circle::Circle(const std::string& name, const Point& center, double radius)
    : Shape(name), center(new Point(center)), radius(new double(radius)) {

    if (radius <= MIN_RADIUS) {
        throw InvalidShapeParameters("Radius must be positive.");
    }
}

double Circle::area() const {
    double result = M_PI * (*radius) * (*radius);
    return result;
}

std::string Circle::type() const {
    std::string result = "Circle";
    return result;
}

std::string Circle::info() const {
    std::ostringstream* oss = new std::ostringstream();
    *oss << "Circle \"" << name << "\" | Center: (" << center->x << ", " << center->y
         << ") | Radius: " << *radius;
    std::string result = oss->str();
    delete oss;
    return result;
}

std::string Circle::parameters() const {
    std::ostringstream* oss = new std::ostringstream();
    *oss << "Center: " << center->toString() << ", radius: " << *radius;
    std::string result = oss->str();
    delete oss;
    return result;
}

Circle::~Circle() {
    delete center;
    delete radius;
}
