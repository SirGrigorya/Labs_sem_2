#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <string>

class Rectangle : public Shape {
private:
    double left, top; // Левый верхний угол
    double right, bottom; // Правый нижний угол

public:
    // Конструктор
    Rectangle(const std::string& name, double left, double top, double right, double bottom);

    // Реализация чисто виртуальных методов
    double area() const override;
    std::string get_type() const override;
    void print_parameters(std::ostream& os) const override;

    // Геттеры
    double get_left() const { return left; }
    double get_top() const { return top; }
    double get_right() const { return right; }
    double get_bottom() const { return bottom; }
};

#endif // RECTANGLE_H
