#include "ConsoleUi.h"
#include "ShapeFactory.h"
#include <iostream>
#include <limits>

ConsoleUi::ConsoleUi() {}

void ConsoleUi::run() {
    bool running = true;

    while (running) {
        printMenu();
        int choice = getChoice();

        if (choice == 0) {
            running = false;
        } else {
            if (choice == 1) addCircle();
            if (choice == 2) addRectangle();
            if (choice == 3) addTriangle();
            if (choice == 4) addPolygon();
            if (choice == 5) listFigures();
            if (choice == 6) listWithAreas();
            if (choice == 7) totalArea();
            if (choice == 8) sortByArea();
            if (choice == 9) removeByIndex();
            if (choice == 10) removeByAreaThreshold();
        }
    }
}

void ConsoleUi::printMenu() {
    std::cout << "\n--- Shape Manager Menu ---\n";
    std::cout << "1. Add Circle\n";
    std::cout << "2. Add Rectangle\n";
    std::cout << "3. Add Triangle\n";
    std::cout << "4. Add Convex Polygon\n";
    std::cout << "5. List all shapes\n";
    std::cout << "6. List shapes with areas\n";
    std::cout << "7. Total area\n";
    std::cout << "8. Sort shapes by area\n";
    std::cout << "9. Remove shape by index\n";
    std::cout << "10. Remove shapes with area greater than threshold\n";
    std::cout << "0. Exit\n";
}

int ConsoleUi::getChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }

    return choice;
}

std::string ConsoleUi::getString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin >> input;
    return input;
}

double ConsoleUi::getDouble(const std::string& prompt) {
    double value;
    std::cout << prompt;
    std::cin >> value;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again: ";
        std::cin >> value;
    }
    return value;
}

int ConsoleUi::getInt(const std::string& prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again: ";
        std::cin >> value;
    }
    return value;
}

void ConsoleUi::addCircle() {
    try {
        container.add(ShapeFactory::createCircle());
        std::cout << "Circle added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::addRectangle() {
    try {
        container.add(ShapeFactory::createRectangle());
        std::cout << "Rectangle added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::addTriangle() {
    try {
        container.add(ShapeFactory::createTriangle());
        std::cout << "Triangle added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::addPolygon() {
    try {
        container.add(ShapeFactory::createConvexPolygon());
        std::cout << "Polygon added successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ConsoleUi::listFigures() {
    const auto& shapes = container.all();
    if (shapes.empty()) {
        std::cout << "No shapes.\n";
    } else {
        for (size_t i = 0; i < shapes.size(); ++i) {
            std::cout << i << ". " << shapes[i]->info() << "\n";
        }
    }
}

void ConsoleUi::listWithAreas() {
    const auto& shapes = container.all();
    if (shapes.empty()) {
        std::cout << "No shapes.\n";
    } else {
        for (size_t i = 0; i < shapes.size(); ++i) {
            std::cout << i << ". " << shapes[i]->type() << ": " << shapes[i]->info()
            << " | Area: " << shapes[i]->area() << "\n";
        }
    }
}

void ConsoleUi::totalArea() {
    std::cout << "Total area: " << container.totalArea() << "\n";
}

void ConsoleUi::sortByArea() {
    container.sortByArea();
    std::cout << "Shapes sorted by area.\n";
}

void ConsoleUi::removeByIndex() {
    int index = getInt("Enter index of shape to remove: ");
    if (container.removeAt(index)) {
        std::cout << "Shape removed.\n";
    } else {
        std::cout << "Invalid index.\n";
    }
}

void ConsoleUi::removeByAreaThreshold() {
    double threshold = getDouble("Enter area threshold: ");
    container.removeByAreaGreaterThan(threshold);
    std::cout << "Shapes with area > threshold removed.\n";
}
