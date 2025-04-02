#ifndef SHAPE_CONTAINER_H
#define SHAPE_CONTAINER_H

#include <vector>
#include <memory>
#include "shape.h"

class ShapeContainer {
private:
    std::vector<std::unique_ptr<Shape>> shapes; // Коллекция фигур

public:
    // Добавление фигуры в контейнер
    void add_shape(std::unique_ptr<Shape> shape);

    // Получение списка фигур (константная версия)
    const std::vector<std::unique_ptr<Shape>>& get_shapes() const;

    // Вычисление суммарной площади всех фигур
    double total_area() const;

    // Сортировка фигур по площади (по возрастанию)
    void sort_by_area();

    // Удаление фигуры по индексу
    void remove_shape(size_t index);

    // Удаление фигур с площадью больше заданного порога
    void remove_shapes_above_area(double threshold);

    // Очистка контейнера
    void clear();
};

#endif // SHAPE_CONTAINER_H
