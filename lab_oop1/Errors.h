#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>
#include <string>

// Базовый класс для пользовательских ошибок
class ShapeError : public std::invalid_argument {
public:
    explicit ShapeError(const std::string& message)
        : std::invalid_argument(message) {}
};

// Ошибка для некорректного треугольника
class InvalidTriangleError : public ShapeError {
public:
    explicit InvalidTriangleError(const std::string& message)
        : ShapeError(message) {}
};

// Ошибка для некорректного круга (например, отрицательный радиус)
class InvalidCircleError : public ShapeError {
public:
    explicit InvalidCircleError(const std::string& message)
        : ShapeError(message) {}
};

// Ошибка для некорректного прямоугольника (например, неправильные координаты)
class InvalidRectangleError : public ShapeError {
public:
    explicit InvalidRectangleError(const std::string& message)
        : ShapeError(message) {}
};

// Ошибка для некорректного многоугольника
class InvalidPolygonError : public ShapeError {
public:
    explicit InvalidPolygonError(const std::string& message)
        : ShapeError(message) {}
};

#endif // ERRORS_H
