#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>
#include <cmath>

class Triangle : public Shape {
private:
    std::string name;
    double x1, y1;
    double x2, y2;
    double x3, y3;

    // Вспомогательная функция для вычисления длины стороны
    double calculateSideLength(double x1, double y1, double x2, double y2) const;

public:
    // Конструктор с проверкой корректности треугольника
    Triangle(const std::string& name, double x1, double y1, double x2, double y2, double x3, double y3);

    // Реализация виртуальных методов из Shape
    std::string getName() const override;
    double getArea() const override;
    double getPerimeter() const ; // Добавлен метод getPerimeter()
    std::string getInfo() const override;
};

#endif // TRIANGLE_H
