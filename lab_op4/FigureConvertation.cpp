#include "FigureConvertation.h"

Figure2D convertFigure3DToFigure2D(Figure3D &figure)
{
    Figure2D result;

    int size = figure.size();
    for(int i = 0; i < size; i++)
    {
        result.verices.push_back(
            Point2D(figure.verices[i].X, figure.verices[i].Y));
    }

    result.edges = figure.edges;
    return result;
}
