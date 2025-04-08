#include "circle.h"
#include "app_errors.h"
#include <cmath>

// Конструктор вызывает конструктор базового класса Shape для инициализации name
Circle::Circle(const std::string& name, double x, double y, double radius)
    : Shape(name), x(x), y(y), radius(radius) {
    if (radius <= 0) throw InvalidCircle(); // Проверка корректности радиуса
}

// Реализация метода area()
double Circle::area() const {
    return M_PI * radius * radius;
}

// Реализация метода get_type()
std::string Circle::get_type() const {
    return "Circle";
}

// Реализация метода print_parameters()
void Circle::print_parameters(std::ostream& os) const {
    os << "Name: " << get_name() << ", Center: (" << x << ", " << y << "), Radius: " << radius;
}
