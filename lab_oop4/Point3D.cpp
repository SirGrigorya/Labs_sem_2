#include "Point3D.h"

#include <math.h>

Point3D::Point3D()
{
    X = Y = Z = 0;
}

Point3D ::Point3D(float x, float y, float z) : X(x), Y(y), Z(z)
{

}

bool Point3D::isPoint3DNear(Point3D val1, Point3D val2)
{
    return (sqrt(pow(val1.X - val2.X, 2) + pow(val1.Y - val2.Y, 2)) <= 1.0);
}
