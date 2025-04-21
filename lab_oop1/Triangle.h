#pragma once

#include "Shape.h"
#include "Point.h"

class Triangle : public Shape {
private:
    Point a, b, c;

public:
    Triangle(const std::string& name, const Point& a, const Point& b, const Point& c);

    double area() const override;
    std::string type() const override;
    std::string parameters() const override;
    std::string info() const override;


    const Point& getA() const { return a; }
    const Point& getB() const { return b; }
    const Point& getC() const { return c; }
};
