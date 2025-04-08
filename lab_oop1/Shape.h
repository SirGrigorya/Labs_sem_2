#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
protected:
    std::string name;

public:
    explicit Shape(const std::string& name) : name(name) {}

    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual std::string get_type() const = 0;
    virtual void print_parameters(std::ostream& os) const = 0;

    std::string get_name() const {
        return name;
    }

    void set_name(const std::string& new_name) {
        name = new_name;
    }
};

#endif
