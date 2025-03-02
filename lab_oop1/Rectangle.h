#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

class Rectangle : public Shape {
private:
    std::string name;
    double topLeftX, topLeftY;
    double bottomRightX, bottomRightY;

public:
    Rectangle(const std::string& name, double topLeftX, double topLeftY, double bottomRightX, double bottomRightY);

    std::string getName() const override;
    double getArea() const override;
    std::string getInfo() const override;
};

#endif // RECTANGLE_H
