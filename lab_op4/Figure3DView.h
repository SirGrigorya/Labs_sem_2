#ifndef FIGURE3DVIEW_H
#define FIGURE3DVIEW_H

#include "Figure3D.h"

struct Figure3DView
{
    Figure3D basic;
    Figure3D modified;

    float rotX;
    float rotY;
    float rotZ;

    float scale;

    Figure3DView(): rotX(0.0), rotY(0.0), rotZ(0.0), scale(1.0) {}
    Figure3DView(Figure3D &figure): basic(figure), rotX(0.0), rotY(0.0), rotZ(0.0), scale(1.0) {}
};

void clearFigure3DView(Figure3DView &view);
void setFigure3DViewFigure(Figure3DView &view, Figure3D &figure);
void transformFigure3DView(Figure3DView &view, float rotX, float rotY, float rotZ, float scale);
Figure3DView loadFigure3DView(vector<vector<string>> &data, float normalizeMin, float normalizeMax);

#endif // FIGURE3DVIEW_H
