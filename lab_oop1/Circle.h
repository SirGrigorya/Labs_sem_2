#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>

class Circle : public Shape {
private:
    std::string name;
    double centerX, centerY;
    double radius;

public:
    Circle(const std::string& name, double centerX, double centerY, double radius);

    std::string getName() const override;
    double getArea() const override;
    std::string getInfo() const override;
};

#endif // CIRCLE_H
