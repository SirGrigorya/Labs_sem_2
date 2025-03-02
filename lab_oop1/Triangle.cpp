#include "Triangle.h"
#include "Errors.h" // Подключаем файл с ошибками
#include <cmath>
#include <sstream>

double Triangle::calculateSideLength(double x1, double y1, double x2, double y2) const {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

Triangle::Triangle(const std::string& name, double x1, double y1, double x2, double y2, double x3, double y3)
    : name(name), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
    double a = calculateSideLength(x1, y1, x2, y2);
    double b = calculateSideLength(x2, y2, x3, y3);
    double c = calculateSideLength(x1, y1, x3, y3);

    if (a + b <= c || a + c <= b || b + c <= a) {
        throw InvalidTriangleError("Треугольник с такими сторонами не может существовать.");
    }
}

std::string Triangle::getName() const {
    return name;
}

double Triangle::getArea() const {
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

std::string Triangle::getInfo() const {
    std::ostringstream oss;
    oss << "Треугольник: " << name << ", Вершины: (" << x1 << ", " << y1 << "), ("
        << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")";
    return oss.str();
}
