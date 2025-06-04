#include "QtSceneDrawer.h"
#include <QPainter>


QtSceneDrawer::QtSceneDrawer(QPicture* picture) : SceneDrawerBase(), _picture(picture)
{

}

void QtSceneDrawer::drawScene(Scene *scene)
{
    QPainter painter;
    painter.begin(_picture);
    size_t size = scene->getFigure()->getEdges()->size();
    for (size_t i = 0; i < size; i++)
    {
        painter.drawLine(scene->getFigure()->getEdges()->at(i).getBegin()->getPosition()->X * coef,
                         scene->getFigure()->getEdges()->at(i).getBegin()->getPosition()->Y * coef,
                         scene->getFigure()->getEdges()->at(i).getEnd()->getPosition()->X * coef,
                         scene->getFigure()->getEdges()->at(i).getEnd()->getPosition()->Y * coef);
    }
    painter.end();

}

QtSceneDrawer::~QtSceneDrawer()
{
    delete  _picture;
}
