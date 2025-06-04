#ifndef FACADE_H
#define FACADE_H

#include "FileReader/BaseFileReader.h"
#include "SceneDrawer/BaseSceneDrawer.h"
#include "Facade/FacadeOperationResult.h"

class Facade
{
    private:
        BaseFileReader* _fileReader;
        Scene* _scene;
        SceneDrawerBase *_sceneDrawer;
        std::string _filePath;

    public:
        Facade(BaseFileReader* fileReader, SceneDrawerBase* sceneDrawer);
        FacadeOperationResult loadScene(NormalizationParameters params);
        FacadeOperationResult drawScene();
        FacadeOperationResult moveScene(float x, float y, float z);
        FacadeOperationResult scaleScene(float x, float y, float z);
        FacadeOperationResult rotateScene(float x, float y, float z);
        void setFilePath(std::string path);
        std::string getFilePath();
        ~Facade();
};

#endif // FACADE_H
