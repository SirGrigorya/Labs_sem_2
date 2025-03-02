#include "Triangle.h"
#include <cmath>
#include <sstream>

Triangle::Triangle(const std::string& name, double x1, double y1, double x2, double y2, double x3, double y3)
    : Shape(name), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

double Triangle::getArea() const {
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
}

double Triangle::getPerimeter() const {
    double side1 = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double side2 = std::sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double side3 = std::sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    return side1 + side2 + side3;
}

std::string Triangle::getInfo() const {
    std::ostringstream oss;
    oss << getName() << ", Вершины: (" << x1 << ", " << y1 << "), ("
        << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")";
    return oss.str();
}
