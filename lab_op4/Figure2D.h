#ifndef FIGURE2D_H
#define FIGURE2D_H

#include <vector>
#include "Point2D.h"

using std::vector;

struct Figure2D
{
    vector<Point2D> verices;
    vector<vector<int>> edges;

    int count()
    {
        return verices.size();
    }
};

#endif // FIGURE2D_H
