#ifndef SCENE_H
#define SCENE_H

#include "Figure.h"

class Scene
{
    private:
        Figure *_figure;

    public:
        Scene();
        Scene(std::vector<Vertex> *verices, std::vector<Edge> *edges);
        Figure* getFigure();
        void setFigure(Figure figure);
        void transform(TransformMatrix mat);
        ~Scene();
};

#endif // SCENE_H
