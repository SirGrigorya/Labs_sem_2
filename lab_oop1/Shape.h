#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
protected:
    std::string name; // Поле для хранения имени фигуры

public:
    Shape(const std::string& name); // Конструктор
    virtual ~Shape() = default;

    // Виртуальные методы
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string getInfo() const = 0;

    // Метод для получения имени фигуры
    std::string getName() const;
};

#endif // SHAPE_H
