#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class ConvexPolygon : public Shape {
private:
    std::vector<Point> vertices;
    std::vector<Point> points;

public:
    ConvexPolygon(const std::string& name, const std::vector<Point>& points);

    double area() const override;
    std::string type() const override;
    std::string parameters() const override;
    std::string info() const override;


    const std::vector<Point>& getVertices() const { return vertices; }
};
