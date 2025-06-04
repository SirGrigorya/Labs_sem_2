#include "TransformMatrix.h"

using namespace std;

TransformMatrix::TransformMatrix()
{
    _matrix.resize(4);
    for (int i = 0; i < 4; i++)
    {
        _matrix[i].resize(4);
    }
}

TransformMatrix::TransformMatrix(vector<vector<float>> matrix): _matrix(matrix)
{

}

Point3D TransformMatrix::tranformPoint(Point3D point)
{
    Point3D result;
    result.X = point.X * _matrix[0][0] + point.Y * _matrix[0][1] + point.Z * _matrix[0][2] + _matrix[0][3];
    result.Y = point.X * _matrix[1][0] + point.Y * _matrix[1][1] + point.Z * _matrix[1][2] + _matrix[1][3];
    result.Z = point.X * _matrix[2][0] + point.Y * _matrix[2][1] + point.Z * _matrix[2][2] + _matrix[2][3];
    return result;
}

TransformMatrix TransformMatrix::multiply(TransformMatrix left, TransformMatrix right)
{
    TransformMatrix result;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           result._matrix[i][j] = left._matrix[i][0] * right._matrix[0][j] + left._matrix[i][1] * right._matrix[1][j] +
                           left._matrix[i][2] * right._matrix[2][j] + left._matrix[i][3] * right._matrix[3][j];
        }
    }
    return result;
}

