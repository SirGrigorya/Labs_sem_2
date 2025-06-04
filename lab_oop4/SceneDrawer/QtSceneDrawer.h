#ifndef QTSCENEDRAWER_H
#define QTSCENEDRAWER_H

#include "SceneDrawer/BaseSceneDrawer.h"
#include <QPicture>


class QtSceneDrawer : public SceneDrawerBase
{
    private:
        QPicture* _picture;
        const int coef = 15;
    public:
        QtSceneDrawer(QPicture* picture);
        void drawScene(Scene *scene);
        ~QtSceneDrawer();
};

#endif // QTSCENEDRAWER_H
