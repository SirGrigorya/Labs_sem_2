#pragma once

#include <string>
#include <sstream>

class Point {
public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    std::string toString() const {
        std::ostringstream oss;
        oss << "(" << x << ", " << y << ")";
        return oss.str();
    }

private:
    double x;
    double y;
};
