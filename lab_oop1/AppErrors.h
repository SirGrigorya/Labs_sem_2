#pragma once
#include <stdexcept>
#include <string>

class ShapeError : public std::runtime_error {
public:
    explicit ShapeError(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidShapeParameters : public ShapeError {
public:
    explicit InvalidShapeParameters(const std::string& message)
        : ShapeError("Cannot create shape: " + message) {}
};

class ShapeIndexError : public ShapeError {
public:
    explicit ShapeIndexError(const std::string& message)
        : ShapeError("Index error: " + message) {}
};
