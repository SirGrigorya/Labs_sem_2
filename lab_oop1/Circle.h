#pragma once
#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
private:
    Point* center;
    double* radius;

public:
    Circle(const std::string& name, const Point& center, double radius);
    ~Circle();

    double area() const override;
    std::string type() const override;
    std::string info() const override;
    std::string parameters() const override;
};
