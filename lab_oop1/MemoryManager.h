#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "Shape.h"
#include <vector>
#include <memory>

class MemoryManager {
private:
    std::vector<std::shared_ptr<Shape>> figures; // Контейнер для хранения фигур

public:
    // Добавление фигуры
    void addFigure(std::shared_ptr<Shape> figure);

    // Удаление фигуры по индексу
    void removeFigure(size_t index);

    // Удаление фигур, площадь которых больше заданного значения
    void removeFiguresWithAreaGreaterThan(double area);

    // Получение списка фигур
    std::vector<std::shared_ptr<Shape>> getFigures() const;

    // Очистка памяти (удаление всех фигур)
    void clear();

    // Получение количества фигур
    size_t getFigureCount() const;
};

#endif // MEMORYMANAGER_H
