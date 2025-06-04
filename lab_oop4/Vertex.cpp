#include "Vertex.h"

Vertex::Vertex()
{

}

Vertex::Vertex(Point3D point)
{
    _position = new Point3D(point);
}

Point3D* Vertex::getPosition()
{
    return _position;
}

void Vertex::setPosition(Point3D *point)
{
    _position = point;
}

void Vertex::transform(TransformMatrix mat)
{
    Point3D result;
    result = mat.tranformPoint(*_position);
    _position->X = result.X;
    _position->Y = result.Y;
    _position->Z = result.Z;
}

Vertex::~Vertex()
{
    delete _position;
}
