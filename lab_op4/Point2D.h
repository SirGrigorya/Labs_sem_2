#ifndef POINT2D_H
#define POINT2D_H

#include <vector>

struct Point2D
{
    float X;
    float Y;

    Point2D() {}
    Point2D(float x, float y): X(x), Y(y) {}
};

#endif // POINT2D_H
