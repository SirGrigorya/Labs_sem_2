#ifndef CONVEXPOLYGON_H
#define CONVEXPOLYGON_H

#include "Shape.h"
#include <vector>
#include <utility> // для std::pair

class ConvexPolygon : public Shape {
private:
    std::string name;
    std::vector<std::pair<double, double>> vertices;

public:
    ConvexPolygon(const std::string& name, const std::vector<std::pair<double, double>>& vertices);

    std::string getName() const override;
    double getArea() const override;
    std::string getInfo() const override;
};

#endif // CONVEXPOLYGON_H
