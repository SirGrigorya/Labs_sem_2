#pragma once

#include "ShapeContainer.h"
#include <memory>
#include <string>

class ShapeFactory {
public:
    static std::shared_ptr<Shape> createCircle();
    static std::shared_ptr<Shape> createRectangle();
    static std::shared_ptr<Shape> createTriangle();
    static std::shared_ptr<Shape> createConvexPolygon();

private:
    static std::string getString(const std::string& prompt);
    static double getDouble(const std::string& prompt);
    static int getInt(const std::string& prompt);
};
