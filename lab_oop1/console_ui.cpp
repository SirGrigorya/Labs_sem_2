#include "console_ui.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "convexpolygon.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void ConsoleUI::show_menu() {
    cout << "\nMenu:\n"
         << "1. Add a shape\n"
         << "2. List all shapes\n"
         << "3. List areas\n"
         << "4. Total area\n"
         << "5. Sort by area\n"
         << "6. Delete by number\n"
         << "7. Delete by area threshold\n"
         << "8. Exit\n"
         << "Enter choice: ";
}

void ConsoleUI::show_error(const string& message) {
    cerr << "Error: " << message << endl;
}

void ConsoleUI::show_message(const string& message) {
    cout << message << endl;
}

void ConsoleUI::list_shapes(const vector<unique_ptr<Shape>>& shapes) {
    if(shapes.empty()) {
        show_message("No shapes.");
        return;
    }
    for(size_t i = 0; i < shapes.size(); ++i) {
        cout << i+1 << ". " << shapes[i]->get_type() << " - ";
        shapes[i]->print_parameters(cout);
        cout << "\n";
    }
}

void ConsoleUI::list_areas(const vector<unique_ptr<Shape>>& shapes) {
    if(shapes.empty()) {
        show_message("No shapes.");
        return;
    }
    for(size_t i = 0; i < shapes.size(); ++i) {
        cout << i+1 << ". " << shapes[i]->get_type()
        << " - Area: " << shapes[i]->area() << "\n";
    }
}

int ConsoleUI::input_int(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
            return value;
        } else {
            std::cin.clear(); // Reset error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
            std::cerr << "Error: Please enter an integer." << std::endl;
        }
    }
}

double ConsoleUI::input_double(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
            return value;
        } else {
            std::cin.clear(); // Reset error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
            std::cerr << "Error: Please enter a number." << std::endl;
        }
    }
}

string ConsoleUI::input_string(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin >> ws, value);
    return value;
}

unique_ptr<Shape> ConsoleUI::create_shape(int type) {
    if (type == 1) {
        return create_circle();
    } else if (type == 2) {
        return create_rectangle();
    } else if (type == 3) {
        return create_triangle();
    } else if (type == 4) {
        return create_polygon();
    } else {
        throw invalid_argument("Invalid shape type");
    }
}

unique_ptr<Shape> ConsoleUI::create_circle() {
    string name = input_string("Enter name: ");
    double x = input_double("Enter center x: ");
    double y = input_double("Enter center y: ");
    double r = input_double("Enter radius: ");
    return make_unique<Circle>(name, x, y, r);
}

unique_ptr<Shape> ConsoleUI::create_rectangle() {
    string name = input_string("Enter name: ");
    double l = input_double("Enter left x: ");
    double t = input_double("Enter top y: ");
    double r = input_double("Enter right x: ");
    double b = input_double("Enter bottom y: ");
    return make_unique<Rectangle>(name, l, t, r, b);
}

unique_ptr<Shape> ConsoleUI::create_triangle() {
    string name = input_string("Enter name: ");
    double x1 = input_double("Enter x1: ");
    double y1 = input_double("Enter y1: ");
    double x2 = input_double("Enter x2: ");
    double y2 = input_double("Enter y2: ");
    double x3 = input_double("Enter x3: ");
    double y3 = input_double("Enter y3: ");
    return make_unique<Triangle>(name, x1, y1, x2, y2, x3, y3);
}

unique_ptr<Shape> ConsoleUI::create_polygon() {
    string name = input_string("Enter name: ");
    int n = input_int("Enter number of vertices: ");
    vector<pair<double, double>> points;
    for(int i = 0; i < n; ++i) {
        double x = input_double("Enter x" + to_string(i+1) + ": ");
        double y = input_double("Enter y" + to_string(i+1) + ": ");
        points.emplace_back(x, y);
    }
    return make_unique<ConvexPolygon>(name, points);
}
