#include "Point3D.h"
#include "Trigonometry.h"
#include <tgmath.h>

Point3D transformPoint3D(Point3D &point, float rotX, float rotY, float rotZ, float scale)
{
    Point3D result;
    result = rotatePoint3D(point, rotX, rotY, rotZ);
    scalePoint3D(result, scale);
    return result;
}

Point3D rotatePoint3D(Point3D &point, float rotX, float rotY, float rotZ)
{
    Point3D result = point;
    rotatePoint3DX(result, rotX);
    rotatePoint3DY(result, rotY);
    rotatePoint3DZ(result, rotZ);
    return result;
}

void rotatePoint3DX(Point3D &point, float ang)
{
    Point3D old = point;
    float rad = fromAngToRad(ang);

    point.X = old.X;
    point.Y = old.Y * cos(rad) + old.Z * sin(rad);
    point.Z = -old.Y * sin(rad) + old.Z * cos(rad);
}

void rotatePoint3DY(Point3D &point, float ang)
{
    Point3D old = point;
    float rad = fromAngToRad(ang);

    point.X = old.X * cos(rad) + old.Z * sin(rad);
    point.Y = old.Y;
    point.Z = -old.X * sin(rad) + old.Z * cos(rad);
}

void rotatePoint3DZ(Point3D &point, float ang)
{
    Point3D old = point;
    float rad = fromAngToRad(ang);

    point.X = old.X * cos(rad) - old.Y * sin(rad);
    point.Y = -old.X * sin(rad) + old.Y * cos(rad);
    point.Z = old.Z;
}

void scalePoint3D(Point3D &point, float scale)
{
    point.X *= scale;
    point.Y *= scale;
    point.Z *= scale;
}

bool isPoints3DNear(Point3D &point1, Point3D &point2, float dist)
{
    return (sqrt(pow(point1.X - point2.X, 2) + pow(point1.Y - point2.Y, 2)) <= dist);
}

