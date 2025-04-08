#include "circle.h"
#include "app_errors.h"
#include <cmath>

Circle::Circle(const std::string& name, double x, double y, double radius)
    : Shape(name), x(x), y(y), radius(radius) {
    if (radius <= 0) throw InvalidCircle();
}

double Circle::area() const {
    return M_PI * radius * radius;
}

std::string Circle::get_type() const {
    return "Circle";
}

void Circle::print_parameters(std::ostream& os) const {
    os << "Name: " << get_name() << ", Center: (" << x << ", " << y << "), Radius: " << radius;
}
