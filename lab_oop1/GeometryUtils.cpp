#include "GeometryUtils.h"
#include <cmath>

#define EPS 1e-10

namespace GeometryUtils {

double crossProduct(const Point& a, const Point& b, const Point& c) {
    double dx1 = b.getX() - a.getX();
    double dy1 = b.getY() - a.getY();
    double dx2 = c.getX() - b.getX();
    double dy2 = c.getY() - b.getY();

    double result = dx1 * dy2 - dy1 * dx2;
    return result;
}

double distance(const Point& p1, const Point& p2) {
    double dx = p1.getX() - p2.getX();
    double dy = p1.getY() - p2.getY();

    double result = std::hypot(dx, dy);
    return result;
}

double shoelaceArea(const std::vector<Point>& points) {
    size_t n = points.size();
    double sum = 0.0;

    for (size_t i = 0; i < n; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % n];
        sum += (p1.getX() * p2.getY() - p2.getX() * p1.getY());
    }

    double result = std::abs(sum) / 2.0;
    return result;
}

}
