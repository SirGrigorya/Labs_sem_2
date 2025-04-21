#include "ConsoleUi.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ConvexPolygon.h"
#include "AppErrors.h"

#include <iostream>
#include <limits>
#include <cmath>
#include <memory>

#define EPS 1e-10
#define MIN_VERTICES 3
#define EXIT_CODE 0
#define INVALID_OPTION -1

ConsoleUi::ConsoleUi() {}

void ConsoleUi::run() {
    bool running = true;
    while (running) {
        printMenu();
        int choice = getChoice();

        if (choice == 1) {
            addCircle();
        } else if (choice == 2) {
            addRectangle();
        } else if (choice == 3) {
            addTriangle();
        } else if (choice == 4) {
            addPolygon();
        } else if (choice == 5) {
            listFigures();
        } else if (choice == 6) {
            listWithAreas();
        } else if (choice == 7) {
            totalArea();
        } else if (choice == 8) {
            sortByArea();
        } else if (choice == 9) {
            removeByIndex();
        } else if (choice == 10) {
            removeByAreaThreshold();
        } else if (choice == EXIT_CODE) {
            running = false;
        } else {
            std::cout << "\nInvalid input. Try again.\n";
        }
    }
}

void ConsoleUi::printMenu() {
    std::cout << "\n=== Menu ===\n"
              << "1. Add circle\n"
              << "2. Add rectangle\n"
              << "3. Add triangle\n"
              << "4. Add convex polygon\n"
              << "5. List shapes\n"
              << "6. List shapes with areas\n"
              << "7. Total area\n"
              << "8. Sort by area\n"
              << "9. Remove shape by index\n"
              << "10. Remove shapes with area greater than threshold\n"
              << "0. Exit\n"
              << "Choose an option: ";
}

int ConsoleUi::getChoice() {
    int* choice = new int;
    std::cin >> *choice;

    int result = *choice;
    delete choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        result = INVALID_OPTION;
    }

    return result;
}

std::string ConsoleUi::getString(const std::string& prompt) {
    std::cout << prompt;
    std::string* input = new std::string;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, *input);

    std::string result = *input;
    delete input;

    return result;
}

double ConsoleUi::getDouble(const std::string& prompt) {
    double* value = new double;
    bool valid = false;

    while (!valid) {
        std::cout << prompt;
        std::cin >> *value;
        valid = !std::cin.fail();
        if (!valid) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
        }
    }

    double result = *value;
    delete value;

    return result;
}

int ConsoleUi::getInt(const std::string& prompt) {
    int* value = new int;
    bool valid = false;

    while (!valid) {
        std::cout << prompt;
        std::cin >> *value;
        valid = !std::cin.fail();
        if (!valid) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
        }
    }

    int result = *value;
    delete value;

    return result;
}

void ConsoleUi::addCircle() {
    try {
        std::string name = getString("Enter circle name: ");
        double x = getDouble("Enter center X: ");
        double y = getDouble("Enter center Y: ");
        double radius = getDouble("Enter radius: ");

        container.add(std::make_shared<Circle>(name, Point(x, y), radius));
        std::cout << "Circle added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::addRectangle() {
    try {
        std::string name = getString("Enter rectangle name: ");
        double x1 = getDouble("Enter top-left X: ");
        double y1 = getDouble("Enter top-left Y: ");
        double x2 = getDouble("Enter bottom-right X: ");
        double y2 = getDouble("Enter bottom-right Y: ");

        container.add(std::make_shared<Rectangle>(name, Point(x1, y1), Point(x2, y2)));
        std::cout << "Rectangle added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::addTriangle() {
    try {
        std::string name = getString("Enter triangle name: ");
        double x1 = getDouble("Enter vertex A X: ");
        double y1 = getDouble("Enter vertex A Y: ");
        double x2 = getDouble("Enter vertex B X: ");
        double y2 = getDouble("Enter vertex B Y: ");
        double x3 = getDouble("Enter vertex C X: ");
        double y3 = getDouble("Enter vertex C Y: ");

        container.add(std::make_shared<Triangle>(name, Point(x1, y1), Point(x2, y2), Point(x3, y3)));
        std::cout << "Triangle added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::addPolygon() {
    try {
        std::string name = getString("Enter polygon name: ");
        int n = getInt("Enter number of vertices (minimum 3): ");
        if (n < MIN_VERTICES) {
            throw InvalidShapeParameters("Polygon must have at least 3 vertices");
        }

        std::vector<Point>* points = new std::vector<Point>;
        for (int i = 0; i < n; ++i) {
            double x = getDouble("Enter vertex " + std::to_string(i + 1) + " X: ");
            double y = getDouble("Enter vertex " + std::to_string(i + 1) + " Y: ");
            points->emplace_back(x, y);
        }

        container.add(std::make_shared<ConvexPolygon>(name, *points));
        delete points;

        std::cout << "Polygon added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::listFigures() {
    const auto& shapes = container.all();
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << i + 1 << ". " << shapes[i]->info() << "\n";
    }
}

void ConsoleUi::listWithAreas() {
    const auto& shapes = container.all();
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << i + 1 << ". " << shapes[i]->info()
        << ", area: " << shapes[i]->area() << "\n";
    }
}

void ConsoleUi::totalArea() {
    double area = container.totalArea();
    std::cout << "Total area: " << area << "\n";
}

void ConsoleUi::sortByArea() {
    container.sortByArea();
    std::cout << "Shapes sorted by area.\n";
}

void ConsoleUi::removeByIndex() {
    int index = getInt("Enter shape index to remove: ") - 1;
    bool success = container.removeAt(index);
    if (success) {
        std::cout << "Shape removed.\n";
    } else {
        std::cerr << "Invalid index.\n";
    }
}

void ConsoleUi::removeByAreaThreshold() {
    double threshold = getDouble("Remove shapes with area greater than: ");
    container.removeByAreaGreaterThan(threshold);
    std::cout << "Removal complete.\n";
}
