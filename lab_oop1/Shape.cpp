#include "Shape.h"

// Конструктор
Shape::Shape(const std::string& name) : name(name) {}

// Реализация метода getName()
std::string Shape::getName() const {
    return name;
}
