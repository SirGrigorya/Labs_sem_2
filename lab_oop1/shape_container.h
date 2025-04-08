#ifndef SHAPE_CONTAINER_H
#define SHAPE_CONTAINER_H

#include <vector>
#include <memory>
#include "shape.h"

class ShapeContainer {
private:
    std::vector<std::unique_ptr<Shape>> shapes; // Коллекция фигур

public:
    void add_shape(std::unique_ptr<Shape> shape);

    const std::vector<std::unique_ptr<Shape>>& get_shapes() const;

    double total_area() const;

    void sort_by_area();

    void remove_shape(size_t index);

    void remove_shapes_above_area(double threshold);

    void clear();
};

#endif // SHAPE_CONTAINER_H
