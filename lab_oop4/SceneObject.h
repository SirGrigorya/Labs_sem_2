#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "TransformMatrix\TransformMatrix.h"

class SceneObject
{
    public:
        virtual void transform(TransformMatrix mat) = 0;
        virtual ~SceneObject() {}
};

#endif // SCENEOBJECT_H
