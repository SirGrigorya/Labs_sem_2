#ifndef FIGURE_H
#define FIGURE_H

#include "SceneObject.h"
#include "Vertex.h"
#include "Edge.h"
#include <vector>

class Figure : public SceneObject
{
    private:
        std::vector<Vertex>* _verices;
        std::vector<Edge>* _edges;

    public:
        Figure();
        Figure(std::vector<Vertex> *verices, std::vector<Edge> *edges);
        std::vector<Vertex>* getVerices();
        std::vector<Edge>* getEdges();
        void setVerices(std::vector<Vertex> *vertices);
        void transform(TransformMatrix mat) override;
        ~Figure() override;
};

#endif // FIGURE_H
