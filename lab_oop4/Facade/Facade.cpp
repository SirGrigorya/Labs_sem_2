#include "Facade/Facade.h"
#include "FileReader/ExceptionFileReader.h"
#include "TransformMatrix/TransformMatrixBuilder.h"

using namespace std;

Facade::~Facade()
{
    delete _scene;
    delete _sceneDrawer;
    delete _fileReader;
    _scene = nullptr;
    _sceneDrawer = nullptr;
    _fileReader = nullptr;
}

Facade::Facade(BaseFileReader* fileReader, SceneDrawerBase* _sceneDrawer) :
    _fileReader(fileReader), _sceneDrawer(_sceneDrawer)
{
    _scene = nullptr;
}

FacadeOperationResult Facade::loadScene(NormalizationParameters params)
{
    FacadeOperationResult result;
    try
    {
        Scene* temp = _fileReader->readScene(_filePath, params);
        if (_scene != nullptr)
        {
            delete _scene;
            _scene = nullptr;
        }
        _scene = temp;
    }
    catch(ExceptionFileReader &ex)
    {
        result.set(ex.what());
    }
    catch(...)
    {
        result.set("Unknown error occured!");
    }
    return result;
}

FacadeOperationResult Facade::drawScene()
{
    FacadeOperationResult result;
    _sceneDrawer->drawScene(_scene);
    return result;
}

FacadeOperationResult Facade::moveScene(float x, float y, float z)
{
    FacadeOperationResult result;
    TransformMatrix mat = TransfromMatrixBuilder::createMoveMatrix(x, y, z);
    _scene->transform(mat);
    return result;
}

FacadeOperationResult Facade::scaleScene(float x, float y, float z)
{
    FacadeOperationResult result;
    TransformMatrix mat = TransfromMatrixBuilder::createScaleMatrix(x, y, z);
    _scene->transform(mat);
    return result;
}

FacadeOperationResult Facade::rotateScene(float x, float y, float z)
{
    FacadeOperationResult result;
    TransformMatrix mat = TransfromMatrixBuilder::createRotationMatrix(x, y, z);
    _scene->transform(mat);
    return result;
}

void Facade::setFilePath(string path)
{
    _filePath = path;
}

string Facade::getFilePath()
{
    return _filePath;
}
