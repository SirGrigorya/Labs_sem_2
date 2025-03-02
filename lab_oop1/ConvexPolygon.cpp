#include "ConvexPolygon.h"
#include <cmath>
#include <sstream>

ConvexPolygon::ConvexPolygon(const std::string& name, const std::vector<std::pair<double, double>>& vertices)
    : Shape(name), vertices(vertices) {
    if (vertices.size() < 3) {
        throw std::invalid_argument("Многоугольник должен иметь как минимум 3 вершины.");
    }
}

double ConvexPolygon::getArea() const {
    double area = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        size_t j = (i + 1) % n; // Следующая вершина (с учетом замыкания на первую)
        area += vertices[i].first * vertices[j].second; // x_i * y_{i+1}
        area -= vertices[j].first * vertices[i].second; // x_{i+1} * y_i
    }
    return std::abs(area) / 2.0; // Берем модуль и делим на 2
}

double ConvexPolygon::getPerimeter() const {
    double perimeter = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        size_t j = (i + 1) % n; // Следующая вершина (с учетом замыкания на первую)
        double dx = vertices[j].first - vertices[i].first;
        double dy = vertices[j].second - vertices[i].second;
        perimeter += std::sqrt(dx * dx + dy * dy); // Длина стороны
    }
    return perimeter;
}

std::string ConvexPolygon::getInfo() const {
    std::ostringstream oss;
    oss << getName() << ", Вершины: ";
    for (const auto& vertex : vertices) {
        oss << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    return oss.str();
}
