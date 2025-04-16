#include "convexpolygon.h"
#include <cmath>
#include "app_errors.h"

bool ConvexPolygon::is_convex(const std::vector<std::pair<double, double>>& points) {
    bool result = true;
    int n = points.size();
    if(n < 3) {
        result = false;
    } else {
        int sign = 0;
        for(int i = 0; i < n; ++i) {
            const auto& p1 = points[i];
            const auto& p2 = points[(i+1)%n];
            const auto& p3 = points[(i+2)%n];

            double cross = (p2.first - p1.first) * (p3.second - p2.second)
                           - (p2.second - p1.second) * (p3.first - p2.first);

            if(cross == 0) continue;
            if(sign == 0) {
                sign = cross > 0 ? 1 : -1;
            } else if((cross > 0 && sign == -1) || (cross < 0 && sign == 1)) {
                result = false;
                break;
            }
        }
    }
    return result;
}

ConvexPolygon::ConvexPolygon(const std::string& name,
                             const std::vector<std::pair<double, double>>& points)
    : Shape(name), vertices(points) {
    if(points.size() < 3 || !is_convex(points)) {
        throw InvalidPolygon();
    }
}

double ConvexPolygon::area() const {
    double a = 0.0;
    int n = vertices.size();
    for(int i = 0; i < n; ++i) {
        const auto& p1 = vertices[i];
        const auto& p2 = vertices[(i+1)%n];
        a += (p1.first * p2.second - p2.first * p1.second);
    }
    return std::abs(a) / 2.0;
}

std::string ConvexPolygon::get_type() const {
    std::string type = "ConvexPolygon";
    return type;
}

void ConvexPolygon::print_parameters(std::ostream& os) const {
    os << "Name: " << get_name() << ", Vertices: ";
    for(size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if(i < vertices.size() - 1) os << ", ";
    }
}
