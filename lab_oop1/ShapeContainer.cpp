#include "ShapeContainer.h"
#include <algorithm>
#include <memory>

#define EPS 1e-10

void ShapeContainer::add(const std::shared_ptr<Shape>& shape) {
    shapes.push_back(shape);
}

const std::vector<std::shared_ptr<Shape>>& ShapeContainer::all() const {
    return shapes;
}

bool ShapeContainer::removeAt(size_t index) {
    bool result = false;
    if (index < shapes.size()) {
        shapes.erase(shapes.begin() + index);
        result = true;
    }
    return result;
}

void ShapeContainer::removeByAreaGreaterThan(double threshold) {
    auto it = std::remove_if(shapes.begin(), shapes.end(),
                             [threshold](const std::shared_ptr<Shape>& shape) {
                                 return (shape->area() - threshold) > EPS;
                             });
    shapes.erase(it, shapes.end());
}

void ShapeContainer::sortByArea() {
    std::sort(shapes.begin(), shapes.end(),
              [](const std::shared_ptr<Shape>& a, const std::shared_ptr<Shape>& b) {
                  return (a->area() - b->area()) < -EPS;
              });
}

double ShapeContainer::totalArea() const {
    double result = 0.0;
    for (const auto& shape : shapes) {
        result += shape->area();
    }
    return result;
}
