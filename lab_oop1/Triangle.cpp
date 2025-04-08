#include "triangle.h"
#include "app_errors.h"
#include <cmath>

// Конструктор вызывает конструктор базового класса Shape для инициализации name
Triangle::Triangle(const std::string& name,
                   double x1, double y1,
                   double x2, double y2,
                   double x3, double y3)
    : Shape(name), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
    double area_val = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if(area_val == 0) throw InvalidTriangle(); // Проверка на вырожденность треугольника
}

// Реализация метода area()
double Triangle::area() const {
    return 0.5 * std::abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}

// Реализация метода get_type()
std::string Triangle::get_type() const {
    return "Triangle";
}

// Реализация метода print_parameters()
void Triangle::print_parameters(std::ostream& os) const {
    os << "Name: " << get_name() << ", Points: (" << x1 << ", " << y1 << "), ("
       << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")";
}
