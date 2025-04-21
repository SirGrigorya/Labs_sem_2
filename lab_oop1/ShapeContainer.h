#pragma once

#include <vector>
#include <memory>
#include "Shape.h"

class ShapeContainer {
private:
    std::vector<std::shared_ptr<Shape>> shapes;

public:
    void add(const std::shared_ptr<Shape>& shape);
    const std::vector<std::shared_ptr<Shape>>& all() const;

    bool removeAt(size_t index);
    void removeByAreaGreaterThan(double threshold);
    void sortByArea();

    double totalArea() const;
};
