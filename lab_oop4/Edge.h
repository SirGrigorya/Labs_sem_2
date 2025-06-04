#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge
{
    private:
        Vertex* _begin;
        Vertex* _end;

    public:
        Edge(Vertex& begin, Vertex& end);
        Vertex* getBegin();
        Vertex* getEnd();
};

#endif // EDGE_H
