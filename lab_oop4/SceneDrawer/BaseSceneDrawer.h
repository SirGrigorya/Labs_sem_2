#ifndef BASESCENEDRAWER_H
#define BASESCENEDRAWER_H
#include "Scene.h"

class SceneDrawerBase
{
    public:
        virtual void drawScene(Scene *scene) = 0;
        virtual ~SceneDrawerBase() {}
};

#endif // BASESCENEDRAWER_H
