#pragma once

#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(const std::string& name, const Point& topLeft, const Point& bottomRight);

    double area() const override;
    std::string type() const override;
    std::string parameters() const override;
    std::string info() const override;


    const Point& getTopLeft() const { return topLeft; }
    const Point& getBottomRight() const { return bottomRight; }
};
