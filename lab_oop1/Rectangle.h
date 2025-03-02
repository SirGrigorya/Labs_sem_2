#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double topLeftX, topLeftY;
    double bottomRightX, bottomRightY;

public:
    Rectangle(const std::string& name, double topLeftX, double topLeftY, double bottomRightX, double bottomRightY);

    // Реализация виртуальных методов
    double getArea() const override;
    double getPerimeter() const override;
    std::string getInfo() const override;
};

#endif // RECTANGLE_H
