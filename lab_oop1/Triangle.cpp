#include "Triangle.h"
#include "AppErrors.h"
#include <sstream>
#include <cmath>

#define EPS 1e-10

static double distance(const Point& p1, const Point& p2) {
    return std::hypot(p1.x - p2.x, p1.y - p2.y);
}

Triangle::Triangle(const std::string& name, const Point& a, const Point& b, const Point& c)
    : Shape(name), a(a), b(b), c(c) {

    double* ab = new double(distance(a, b));
    double* bc = new double(distance(b, c));
    double* ca = new double(distance(c, a));

    double* s = new double((*ab + *bc + *ca) / 2.0);
    double* area = new double(std::sqrt(*s * (*s - *ab) * (*s - *bc) * (*s - *ca)));

    bool invalid = (*area < EPS);

    delete ab;
    delete bc;
    delete ca;
    delete s;

    if (invalid) {
        delete area;
        throw InvalidShapeParameters("Degenerate triangle (zero area).");
    }

    delete area;
}

std::string Triangle::info() const {
    std::ostringstream* oss = new std::ostringstream();
    *oss << "Triangle \"" << name << "\" | Vertices: ("
         << a.x << ", " << a.y << "), ("
         << b.x << ", " << b.y << "), ("
         << c.x << ", " << c.y << ")";
    std::string result = oss->str();
    delete oss;
    return result;
}

double Triangle::area() const {
    double* ab = new double(distance(a, b));
    double* bc = new double(distance(b, c));
    double* ca = new double(distance(c, a));

    double* s = new double((*ab + *bc + *ca) / 2.0);
    double* area = new double(std::sqrt(*s * (*s - *ab) * (*s - *bc) * (*s - *ca)));

    double result = *area;

    delete ab;
    delete bc;
    delete ca;
    delete s;
    delete area;

    return result;
}

std::string Triangle::type() const {
    std::string result = "Triangle";
    return result;
}

std::string Triangle::parameters() const {
    std::ostringstream* oss = new std::ostringstream();
    *oss << "Vertices: " << a.toString() << ", " << b.toString() << ", " << c.toString();
    std::string result = oss->str();
    delete oss;
    return result;
}
