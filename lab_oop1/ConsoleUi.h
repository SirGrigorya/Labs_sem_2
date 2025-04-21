#pragma once

#include "ShapeContainer.h"
#include <string>

class ConsoleUi {
public:
    ConsoleUi();
    void run();

private:
    ShapeContainer container;

    void printMenu();
    int getChoice();

    std::string getString(const std::string& prompt);
    double getDouble(const std::string& prompt);
    int getInt(const std::string& prompt);

    void addCircle();
    void addRectangle();
    void addTriangle();
    void addPolygon();

    void listFigures();
    void listWithAreas();
    void totalArea();
    void sortByArea();
    void removeByIndex();
    void removeByAreaThreshold();
};
