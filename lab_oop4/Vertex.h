#ifndef VERTEX_H
#define VERTEX_H

#include "Point3D.h"
#include "SceneObject.h"

class Vertex : SceneObject
{
    private:
       Point3D *_position;

    public:
        Vertex();
        Vertex(Point3D point);
        Point3D* getPosition();
        void setPosition(Point3D *point);
        void transform(TransformMatrix mat) override;
        ~Vertex() override;
};

#endif // VERTEX_H
