#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H

#include <vector>
#include <Point3D.h>

class TransformMatrix
{
    private:
        std::vector<std::vector<float>> _matrix;
    public:
        TransformMatrix();
        TransformMatrix(std::vector<std::vector<float>> matrix);
        Point3D tranformPoint(Point3D point);
        static TransformMatrix multiply(TransformMatrix left, TransformMatrix right);
};

#endif // TRANSFORMMATRIX_H
