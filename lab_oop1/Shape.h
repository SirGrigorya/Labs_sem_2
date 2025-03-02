#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual ~Shape() = default;

    // Виртуальные методы
    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;
    virtual std::string getInfo() const = 0;
};

#endif // SHAPE_H
