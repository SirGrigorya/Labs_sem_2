#ifndef TRANSFROMMATRIXBUILDER_H
#define TRANSFROMMATRIXBUILDER_H

#include "TransformMatrix.h"

class TransfromMatrixBuilder
{
    private:
        static TransformMatrix createRotationMatrixX(float x);
        static TransformMatrix createRotationMatrixY(float y);
        static TransformMatrix createRotationMatrixZ(float z);
    public:
        static TransformMatrix createMoveMatrix(float x, float y, float z);
        static TransformMatrix createScaleMatrix(float x, float y, float z);
        static TransformMatrix createRotationMatrix(float x, float y, float z);
};

#endif // TRANSFROMMATRIXBUILDER_H
