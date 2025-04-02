#ifndef APP_ERRORS_H
#define APP_ERRORS_H

#include <stdexcept>
#include <string>

// Базовый класс для пользовательских исключений
class ShapeError : public std::runtime_error {
public:
    explicit ShapeError(const std::string& message)
        : std::runtime_error(message) {}
};

// Исключение для некорректного круга
class InvalidCircle : public ShapeError {
public:
    InvalidCircle()
        : ShapeError("Invalid circle parameters: radius must be positive.") {}
};

// Исключение для некорректного прямоугольника
class InvalidRectangle : public ShapeError {
public:
    InvalidRectangle()
        : ShapeError("Invalid rectangle parameters: left must be less than right, and top must be greater than bottom.") {}
};

// Исключение для некорректного треугольника
class InvalidTriangle : public ShapeError {
public:
    InvalidTriangle()
        : ShapeError("Invalid triangle parameters: points must not be collinear.") {}
};

// Исключение для некорректного многоугольника
class InvalidPolygon : public ShapeError {
public:
    InvalidPolygon()
        : ShapeError("Invalid polygon parameters: must have at least 3 vertices and be convex.") {}
};

#endif // APP_ERRORS_H
