#ifndef CONVEXPOLYGON_H
#define CONVEXPOLYGON_H

#include "shape.h"
#include <vector>
#include <utility>

class ConvexPolygon : public Shape {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    ConvexPolygon(const std::string& name, const std::vector<std::pair<double, double>>& points);

    double area() const override;
    std::string get_type() const override;
    void print_parameters(std::ostream& os) const override;

    const std::vector<std::pair<double, double>>& get_vertices() const { return vertices; }

    static bool is_convex(const std::vector<std::pair<double, double>>& points);
};

#endif // CONVEXPOLYGON_H
