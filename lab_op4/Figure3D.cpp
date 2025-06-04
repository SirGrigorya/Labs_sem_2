#include "Figure3D.h"
#include "VectorOperations.h"

void clearFigure3D(Figure3D &figure)
{
    figure.verices.clear();
    figure.edges.clear();
}

void setFigureSize(Figure3D &figure, int size)
{
    clearFigure3D(figure);
    figure.verices.resize(size);
    for(int i = 0; i < size; i++)
    {
        vector<int> temp;
        temp.resize(size);
        figure.edges.push_back(temp);
    }
}


int readFigure3D(Figure3D &figure, vector<vector<float>> &data, float normalizeMin, float normalizeMax)
{
    if(!data.size())
        return 1;

    int error = 0;

    unsigned int sizeX = data.size();
    unsigned int sizeY = data[0].size();

    setFigureSize(figure, sizeX * sizeY);

    normalizeVectors(data, normalizeMin, normalizeMax);

    int num = 0;
    for(unsigned int i = 0; i < sizeX; i++)
    {
        if(data[i].size() != sizeY)
        {
            error = 1;
            break;
        }

        for(unsigned int j = 0; j < sizeY; j++)
            figure.verices[num++] = Point3D(i, j, data[i][j]);
    }

    setFigure3DEdges(figure);

    if(error)
        clearFigure3D(figure);

    return error;
}

Figure3D rotateFigure3D(Figure3D &figure, float rotX, float rotY, float rotZ)
{
    int size = figure.size();
    Figure3D result = figure;
    for(int i = 0; i < size; i++)
        result.verices[i] = rotatePoint3D(figure.verices[i], rotX, rotY, rotZ);

    return result;
}
Figure3D setFigure3DScale(Figure3D &figure, float scale)
{
    int size = figure.size();
    Figure3D result = figure;
    for(int i = 0; i < size; i++)
        scalePoint3D(result.verices[i], scale);

    return result;
}

void setFigure3DEdges(Figure3D &figure)
{
    int size = figure.size();
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(isPoints3DNear(figure.verices[i], figure.verices[j], 1.0))
                figure.edges[i][j] = 1;
        }
    }
}
