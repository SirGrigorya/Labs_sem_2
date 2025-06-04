#include "Scene.h"

using namespace std;

Scene::Scene()
{

}

Scene::Scene(vector<Vertex>* verices, vector<Edge>* edges)
{
     _figure = new Figure(verices, edges);
}

Figure* Scene::getFigure()
{
    return _figure;
}

void Scene::transform(TransformMatrix mat)
{
    _figure->transform(mat);
}

Scene::~Scene()
{
    delete _figure;
}
