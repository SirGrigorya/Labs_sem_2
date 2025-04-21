#pragma once
#include <string>

class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& name) : name(name) {}
    virtual ~Shape() = default;

    std::string getName() const { return name; }

    virtual double area() const = 0;

    virtual std::string type() const = 0;

    virtual std::string parameters() const = 0;

    virtual std::string info() const = 0;

    bool operator<(const Shape& other) const {
        return this->area() < other.area();
    }
};
