#include "shape_container.h"
#include <algorithm>

void ShapeContainer::add_shape(std::unique_ptr<Shape> shape) {
    shapes.push_back(std::move(shape));
}

const std::vector<std::unique_ptr<Shape>>& ShapeContainer::get_shapes() const {
    return shapes;
}

double ShapeContainer::total_area() const {
    double total = 0.0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

void ShapeContainer::sort_by_area() {
    std::sort(shapes.begin(), shapes.end(), [](const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) {
        return a->area() < b->area();
    });
}

void ShapeContainer::remove_shape(size_t index) {
    if (index >= shapes.size()) {
        throw std::out_of_range("Invalid shape index.");
    }
    shapes.erase(shapes.begin() + index);
}

void ShapeContainer::remove_shapes_above_area(double threshold) {
    shapes.erase(std::remove_if(shapes.begin(), shapes.end(), [threshold](const std::unique_ptr<Shape>& shape) {
                     return shape->area() > threshold;
                 }), shapes.end());
}

void ShapeContainer::clear() {
    shapes.clear();
}
