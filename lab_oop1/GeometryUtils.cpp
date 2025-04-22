#include "GeometryUtils.h"
#include <cmath>

#define EPS 1e-10

namespace GeometryUtils {

double crossProduct(const Point& a, const Point& b, const Point& c) {
    double dx1 = b.x - a.x;
    double dy1 = b.y - a.y;
    double dx2 = c.x - b.x;
    double dy2 = c.y - b.y;

    double result = dx1 * dy2 - dy1 * dx2;
    return result;
}

double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;

    double result = std::hypot(dx, dy);
    return result;
}

double shoelaceArea(const std::vector<Point>& points) {
    size_t n = points.size();
    double sum = 0.0;

    for (size_t i = 0; i < n; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % n];
        sum += (p1.x * p2.y - p2.x * p1.y);
    }

    double result = std::abs(sum) / 2.0;
    return result;
}

}
