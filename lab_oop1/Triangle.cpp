#include "Triangle.h"
#include "AppErrors.h"
#include "GeometryUtils.h"
#include <sstream>
#include <cmath>

#define EPS 1e-10

Triangle::Triangle(const std::string& name, const Point& a, const Point& b, const Point& c)
    : Shape(name), a(a), b(b), c(c) {

    double ab = GeometryUtils::distance(a, b);
    double bc = GeometryUtils::distance(b, c);
    double ca = GeometryUtils::distance(c, a);

    double s = (ab + bc + ca) / 2.0;
    double area = std::sqrt(s * (s - ab) * (s - bc) * (s - ca));

    if (area < EPS) {
        throw InvalidShapeParameters("Degenerate triangle (zero area).");
    }
}

std::string Triangle::info() const {
    std::ostringstream oss;
    oss << "Triangle \"" << name << "\" | Vertices: ("
        << a.getX() << ", " << a.getY() << "), ("
        << b.getX() << ", " << b.getY() << "), ("
        << c.getX() << ", " << c.getY() << ")";
    return oss.str();
}

double Triangle::area() const {
    double ab = GeometryUtils::distance(a, b);
    double bc = GeometryUtils::distance(b, c);
    double ca = GeometryUtils::distance(c, a);

    double s = (ab + bc + ca) / 2.0;
    return std::sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

std::string Triangle::type() const {
    return "Triangle";
}

std::string Triangle::parameters() const {
    std::ostringstream oss;
    oss << "Vertices: " << a.toString() << ", " << b.toString() << ", " << c.toString();
    return oss.str();
}
