QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Edge.cpp \
    Facade/Facade.cpp \
    Facade/FacadeOperationResult.cp \
    Figure.cpp \
    FileReader/BaseFileReader.cpp \
    FileReader/ExceptionFileReader.cpp \
    FileReader/FileReader.cpp \
    MainWindow.cpp \
    Normalization/NormalizationManager.cpp \
    Normalization/NormalizationParameters.cpp \
    Point3D.cpp \
    Scene.cpp \
    SceneDrawer/BaseSceneDrawer.cpp \
    SceneDrawer/QtSceneDrawer.cpp \
    StringsManager.cpp \
    TransformMatrix/TransformMatrix.cpp \
    TransformMatrix/TransformMatrixBuilder.cpp \
    Vertex.cpp \
    main.cpp

HEADERS += \
    Edge.h \
    Facade/Facade.h \
    Facade/FacadeOperationResult.h \
    Figure.h \
    FileReader/BaseFileReader.h \
    FileReader/ExceptionFileReader.h \
    FileReader/FileReader.h \
    MainWindow.h \
    Normalization/NormalizationManager.h \
    Normalization/NormalizationParameters.h \
    Point3D.h \
    Scene.h \
    SceneDrawer/BaseSceneDrawer.h \
    SceneDrawer/QtSceneDrawer.h \
    SceneObject.h \
    StringsManager.h \
    TransformMatrix/TransformMatrix.h \
    TransformMatrix/TransformMatrixBuilder.h \
    Vertex.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
