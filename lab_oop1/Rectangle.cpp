#include "rectangle.h"
#include "app_errors.h"

// Конструктор вызывает конструктор базового класса Shape для инициализации name
Rectangle::Rectangle(const std::string& name, double l, double t, double r, double b)
    : Shape(name), left(l), top(t), right(r), bottom(b) {
    if(left >= right || top <= bottom)
        throw InvalidRectangle(); // Проверка корректности координат
}

// Реализация метода area()
double Rectangle::area() const {
    return (right - left) * (top - bottom);
}

// Реализация метода get_type()
std::string Rectangle::get_type() const {
    return "Rectangle";
}

// Реализация метода print_parameters()
void Rectangle::print_parameters(std::ostream& os) const {
    os << "Name: " << get_name() << ", Left-Top: (" << left << ", " << top
       << "), Right-Bottom: (" << right << ", " << bottom << ")";
}
