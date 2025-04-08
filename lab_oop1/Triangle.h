#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <string>

class Triangle : public Shape {
private:
    double x1, y1; // Первая вершина
    double x2, y2; // Вторая вершина
    double x3, y3; // Третья вершина

public:
    // Конструктор
    Triangle(const std::string& name, double x1, double y1, double x2, double y2, double x3, double y3);

    // Реализация чисто виртуальных методов
    double area() const override;
    std::string get_type() const override;
    void print_parameters(std::ostream& os) const override;

    // Геттеры
    double get_x1() const { return x1; }
    double get_y1() const { return y1; }
    double get_x2() const { return x2; }
    double get_y2() const { return y2; }
    double get_x3() const { return x3; }
    double get_y3() const { return y3; }
};

#endif // TRIANGLE_H
