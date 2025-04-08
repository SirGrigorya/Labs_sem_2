#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
protected:
    std::string name; // Поле Name, вынесенное в базовый класс

public:
    // Конструктор, принимающий имя
    explicit Shape(const std::string& name) : name(name) {}

    // Виртуальный деструктор
    virtual ~Shape() = default;

    // Чисто виртуальные функции
    virtual double area() const = 0;
    virtual std::string get_type() const = 0;
    virtual void print_parameters(std::ostream& os) const = 0;

    // Метод для получения имени
    std::string get_name() const {
        return name;
    }

    // Метод для изменения имени
    void set_name(const std::string& new_name) {
        name = new_name;
    }
};

#endif
