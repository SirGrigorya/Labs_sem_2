#include "Container.h"
#include <algorithm> // Подключаем заголовочный файл

// Добавление фигуры
void MemoryManager::addFigure(std::shared_ptr<Shape> figure) {
    figures.push_back(figure);
}

// Удаление фигуры по индексу
void MemoryManager::removeFigure(size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

// Удаление фигур, площадь которых больше заданного значения
void MemoryManager::removeFiguresWithAreaGreaterThan(double area) {
    figures.erase(
        std::remove_if(figures.begin(), figures.end(),
                       [area](const std::shared_ptr<Shape>& figure) {
                           return figure->getArea() > area;
                       }),
        figures.end()
        );
}

// Получение списка фигур
std::vector<std::shared_ptr<Shape>> MemoryManager::getFigures() const {
    return figures;
}

// Очистка памяти (удаление всех фигур)
void MemoryManager::clear() {
    figures.clear();
}

// Получение количества фигур
size_t MemoryManager::getFigureCount() const {
    return figures.size();
}
