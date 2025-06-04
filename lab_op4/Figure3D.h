#ifndef FIGURE_H
#define FIGURE_H

#include <vector>
#include <string>
#include "Point3D.h"


using namespace std;
struct Figure3D
{
    vector<Point3D> verices;
    vector<vector<int>> edges;

    int size()
    {
        return verices.size();
    }
};

void clearFigure3D(Figure3D &figure);
void setFigureSize(Figure3D &figure, int size);
int readFigure3D(Figure3D &figure, vector<vector<float>> &data, float normalizeMin, float normalizeMax);

Figure3D rotateFigure3D(Figure3D &figure, float rotX, float rotY, float rotZ);
Figure3D setFigure3DScale(Figure3D &figure, float scale);

void setFigure3DEdges(Figure3D &figure);

#endif // FIGURE_H
