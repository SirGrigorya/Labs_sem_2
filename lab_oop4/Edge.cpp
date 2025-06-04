#include "Edge.h"

Edge::Edge(Vertex& begin, Vertex& end)
{
    _begin = &begin;
    _end = &end;
}

Vertex* Edge::getBegin()
{
    return _begin;
}

Vertex* Edge::getEnd()
{
    return _end;
}
