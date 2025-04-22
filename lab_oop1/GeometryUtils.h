#pragma once

#include "Point.h"
#include <vector>

#define EPS 1e-10

namespace GeometryUtils {

double crossProduct(const Point& a, const Point& b, const Point& c);

double distance(const Point& p1, const Point& p2);

double shoelaceArea(const std::vector<Point>& points);
}
