#include "Figure.h"

using namespace std;

Figure::Figure()
{

}

Figure::Figure(vector<Vertex> *verices, vector<Edge> *edges) : _verices(verices), _edges(edges)
{

}

vector<Vertex>* Figure::getVerices()
{
    return _verices;
}

vector<Edge>* Figure::getEdges()
{
    return _edges;
}

void Figure::setVerices(vector<Vertex> *verices)
{
    _verices = verices;
}

void Figure::transform(TransformMatrix mat)
{
    size_t size = _verices->size();
    for (size_t i = 0; i < size; i++)
    {
        _verices->at(i).transform(mat);
    }
}

Figure::~Figure()
{
    delete _verices;
    delete _edges;
}
