#include "ConvexPolygon.h"
#include "AppErrors.h"
#include <sstream>
#include <cmath>
#include <memory>

#define EPS 1e-10
#define MIN_POLY_VERTICES 3
#define ZERO_AREA EPS

static bool isConvex(const std::vector<Point>& pts) {
    bool result = true;
    size_t n = pts.size();

    if (n < MIN_POLY_VERTICES) {
        result = false;
    } else {
        bool sign = false;
        for (size_t i = 0; i < n && result; ++i) {
            const Point& a = pts[i];
            const Point& b = pts[(i + 1) % n];
            const Point& c = pts[(i + 2) % n];

            double dx1 = b.x - a.x;
            double dy1 = b.y - a.y;
            double dx2 = c.x - b.x;
            double dy2 = c.y - b.y;

            double cross = dx1 * dy2 - dy1 * dx2;

            if (i == 0) {
                sign = cross > EPS;
            } else if ((cross > EPS) != sign) {
                result = false;
            }
        }
    }

    return result;
}

static double shoelaceArea(const std::vector<Point>& pts) {
    size_t n = pts.size();
    double* sum = new double;
    *sum = 0.0;

    for (size_t i = 0; i < n; ++i) {
        const Point& p1 = pts[i];
        const Point& p2 = pts[(i + 1) % n];
        *sum += (p1.x * p2.y - p2.x * p1.y);
    }

    double area = std::abs(*sum) / 2.0;
    delete sum;
    return area;
}

ConvexPolygon::ConvexPolygon(const std::string& name, const std::vector<Point>& points)
    : Shape(name), vertices(points) {

    bool valid = true;

    if (points.size() < MIN_POLY_VERTICES) {
        valid = false;
        throw InvalidShapeParameters("Polygon must have at least 3 vertices.");
    }

    if (!isConvex(points)) {
        valid = false;
        throw InvalidShapeParameters("Polygon is not convex.");
    }

    if (shoelaceArea(points) <= ZERO_AREA) {
        valid = false;
        throw InvalidShapeParameters("Polygon area is zero.");
    }

    // `valid` unused further — retained for logical clarity if expanded.
}

double ConvexPolygon::area() const {
    double result = shoelaceArea(vertices);
    return result;
}

std::string ConvexPolygon::type() const {
    std::string result = "Convex Polygon";
    return result;
}

std::string ConvexPolygon::info() const {
    std::ostringstream* oss = new std::ostringstream;
    *oss << "Convex Polygon \"" << name << "\" | Vertices:";
    for (const auto& p : vertices) {
        *oss << " (" << p.x << ", " << p.y << ")";
    }

    std::string result = oss->str();
    delete oss;
    return result;
}

std::string ConvexPolygon::parameters() const {
    std::ostringstream* oss = new std::ostringstream;
    *oss << "Vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        *oss << vertices[i].toString();
        if (i != vertices.size() - 1) *oss << ", ";
    }

    std::string result = oss->str();
    delete oss;
    return result;
}
