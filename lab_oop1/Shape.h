#pragma once
#include <string>

class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& name) : name(name) {}
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual std::string type() const = 0;
    virtual std::string info() const = 0;
    virtual std::string parameters() const = 0;

    std::string getName() const { return name; }
};
