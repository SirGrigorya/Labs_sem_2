#include "Figure3DView.h"
#include "VectorOperations.h"

void clearFigure3DView(Figure3DView &view)
{
    clearFigure3D(view.basic);
    clearFigure3D(view.modified);
    view.rotX = 0.0;
    view.rotY = 0.0;
    view.rotZ = 0.0;
    view.scale = 1.0;
}

void setFigure3DViewFigure(Figure3DView &view, Figure3D &figure)
{
    clearFigure3DView(view);
    view.basic = figure;
}

void transformFigure3DView(Figure3DView &view, float rotX, float rotY, float rotZ, float scale)
{
    view.modified = rotateFigure3D(view.basic, rotX, rotY, rotZ);
    view.rotX = rotX;
    view.rotY = rotY;
    view.rotZ = rotZ;

    view.modified = setFigure3DScale(view.modified, scale);
    view.scale = scale;
}

Figure3DView loadFigure3DView(vector<vector<string>> &data, float normalizeMin, float normalizeMax)
{
    vector<vector<float>> poses = convertVectorsFromStringToDouble(data);
    Figure3D figure;
    readFigure3D(figure, poses, normalizeMin, normalizeMax);
    return Figure3DView(figure);
}

