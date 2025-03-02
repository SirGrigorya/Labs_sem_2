#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
private:
    double x1, y1;
    double x2, y2;
    double x3, y3;

public:
    Triangle(const std::string& name, double x1, double y1, double x2, double y2, double x3, double y3);

    // Реализация виртуальных методов
    double getArea() const override;
    double getPerimeter() const override;
    std::string getInfo() const override;
};

#endif // TRIANGLE_H
