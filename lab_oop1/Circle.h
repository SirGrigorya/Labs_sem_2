#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double centerX, centerY;
    double radius;

public:
    Circle(const std::string& name, double centerX, double centerY, double radius);

    // Реализация виртуальных методов
    double getArea() const override;
    double getPerimeter() const override;
    std::string getInfo() const override;
};

#endif // CIRCLE_H
