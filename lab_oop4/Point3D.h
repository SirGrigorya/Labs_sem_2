#ifndef POINT3D_H
#define POINT3D_H

class Point3D
{
    public:
        float X;
        float Y;
        float Z;
        Point3D();
        Point3D(float x, float y, float z);
        static bool isPoint3DNear(Point3D val1, Point3D val2);
};

#endif // POINT3D_H
