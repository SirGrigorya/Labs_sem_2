#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "shape.h" // Базовый класс Shape
#include "circle.h" // Класс Circle
#include "rectangle.h" // Класс Rectangle
#include "triangle.h" // Класс Triangle
#include "convexpolygon.h" // Класс ConvexPolygon

class ConsoleUI {
public:
    // Отображение главного меню
    static void show_menu();

    // Отображение сообщения об ошибке
    static void show_error(const std::string& message);

    // Отображение сообщения
    static void show_message(const std::string& message);

    // Вывод списка всех фигур
    static void list_shapes(const std::vector<std::unique_ptr<Shape>>& shapes);

    // Вывод списка площадей всех фигур
    static void list_areas(const std::vector<std::unique_ptr<Shape>>& shapes);

    // Ввод целого числа с проверкой
    static int input_int(const std::string& prompt);

    // Ввод числа с плавающей точкой с проверкой
    static double input_double(const std::string& prompt);

    // Ввод строки
    static std::string input_string(const std::string& prompt);

    // Создание фигуры в зависимости от выбора пользователя
    static std::unique_ptr<Shape> create_shape(int type);

    // Создание круга
    static std::unique_ptr<Shape> create_circle();

    // Создание прямоугольника
    static std::unique_ptr<Shape> create_rectangle();

    // Создание треугольника
    static std::unique_ptr<Shape> create_triangle();

    // Создание выпуклого многоугольника
    static std::unique_ptr<Shape> create_polygon();
};

#endif // CONSOLE_UI_H
