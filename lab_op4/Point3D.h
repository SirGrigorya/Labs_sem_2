#ifndef POINT3D_H
#define POINT3D_H

#include <string>
#include <vector>

using namespace std;

struct Point3D
{
    float X;
    float Y;
    float Z;

    Point3D() {}
    Point3D(float x, float y, float z) : X(x), Y(y), Z(z) {}
};

Point3D transformPoint3D(Point3D &point, float rotX, float rotY, float rotZ, float scale);
Point3D rotatePoint3D(Point3D &point, float rotX, float rotY, float rotZ);
void rotatePoint3DX(Point3D &point, float ang);
void rotatePoint3DY(Point3D &point, float ang);
void rotatePoint3DZ(Point3D &point, float ang);
void scalePoint3D(Point3D &point, float scale);

bool isPoints3DNear(Point3D &point1, Point3D &point2, float dist = 1.0);
#endif // POINT3D_H
