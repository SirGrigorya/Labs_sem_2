#ifndef CONVEXPOLYGON_H
#define CONVEXPOLYGON_H

#include "shape.h"
#include <vector>
#include <utility> // Для std::pair

class ConvexPolygon : public Shape {
private:
    std::vector<std::pair<double, double>> vertices; // Вершины многоугольника

public:
    // Конструктор
    ConvexPolygon(const std::string& name, const std::vector<std::pair<double, double>>& points);

    // Реализация чисто виртуальных методов
    double area() const override;
    std::string get_type() const override;
    void print_parameters(std::ostream& os) const override;

    // Геттер для вершин
    const std::vector<std::pair<double, double>>& get_vertices() const { return vertices; }

    // Проверка, является ли многоугольник выпуклым
    static bool is_convex(const std::vector<std::pair<double, double>>& points);
};

#endif // CONVEXPOLYGON_H
