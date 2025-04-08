#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <string>

class Circle : public Shape {
private:
    double x, y; // Координаты центра
    double radius; // Радиус

public:
    // Конструктор
    Circle(const std::string& name, double x, double y, double radius);

    // Реализация чисто виртуальных методов
    double area() const override;
    std::string get_type() const override;
    void print_parameters(std::ostream& os) const override;

    // Геттеры
    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_radius() const { return radius; }
};

#endif // CIRCLE_H
