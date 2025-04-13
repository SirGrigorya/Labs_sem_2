#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <string>
#include <vector>
#include <memory>
#include "shape.h"

class ConsoleUI {
public:
    static void show_menu();

    static void show_error(const std::string& message);

    static void show_message(const std::string& message);

    static void list_shapes(const std::vector<std::unique_ptr<Shape>>& shapes);

    static void list_areas(const std::vector<std::unique_ptr<Shape>>& shapes);

    static int input_int(const std::string& prompt);

    static double input_double(const std::string& prompt);

    static std::string input_string(const std::string& prompt);

    static std::unique_ptr<Shape> create_shape(int type);

    static std::unique_ptr<Shape> create_circle();

    static std::unique_ptr<Shape> create_rectangle();

    static std::unique_ptr<Shape> create_triangle();

    static std::unique_ptr<Shape> create_polygon();
};

#endif // CONSOLE_UI_H
