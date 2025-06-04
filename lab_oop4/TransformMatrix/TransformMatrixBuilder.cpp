#include "TransformMatrixBuilder.h"
#include <math.h>

using namespace std;

TransformMatrix TransfromMatrixBuilder::createMoveMatrix(float x, float y, float z)
{
    vector<vector<float>> matrix = {{ 1, 0, 0, x},
                                 { 0, 1, 0, y},
                                 { 0, 0, 1, z},
                                 { 0, 0, 0, 1}};
    return TransformMatrix(matrix);
}

TransformMatrix TransfromMatrixBuilder::createScaleMatrix(float x, float y, float z)
{
    vector<vector<float>> matrix = {{ x, 0, 0, 0},
                                 { 0, y, 0, 0},
                                 { 0, 0, z, 0},
                                 { 0, 0, 0, 1}};
    return TransformMatrix(matrix);
}


TransformMatrix TransfromMatrixBuilder::createRotationMatrixX(float x)
{
    float radX = (M_PI / 180.0) * x;
    vector<vector<float>> matrix = {{1, 0, 0, 0},
                                 {0, cos(radX), -sin(radX), 0},
                                 {0, sin(radX), cos(radX), 0},
                                 {0, 0, 0, 1} };
    return TransformMatrix(matrix);
}

TransformMatrix TransfromMatrixBuilder::createRotationMatrixY(float y)
{
    float radY = (M_PI / 180) * y;
    vector<vector<float>> matrix = {{cos(radY), 0, sin(radY), 0},
                                {0, 1, 0, 0},
                                {-sin(radY), 0, cos(radY), 0},
                                {0, 0, 0, 1} };
    return TransformMatrix(matrix);
}

TransformMatrix TransfromMatrixBuilder::createRotationMatrixZ(float z)
{
    float radZ = (M_PI / 180) * z;
    vector<vector<float>> matrix = {{cos(radZ), -sin(radZ), 0, 0},
                                {sin(radZ), cos(radZ), 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 1} };
    return TransformMatrix(matrix);
}

TransformMatrix TransfromMatrixBuilder::createRotationMatrix(float x, float y, float z)
{
    TransformMatrix matrixX =  createRotationMatrixX(x);
    TransformMatrix matrixY =  createRotationMatrixY(y);
    TransformMatrix matrixZ = createRotationMatrixZ(z);
    return TransformMatrix::multiply(matrixX, matrixY);
}
