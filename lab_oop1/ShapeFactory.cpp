#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ConvexPolygon.h"
#include "AppErrors.h"

#include <iostream>
#include <limits>
#include <vector>

#define MIN_VERTICES 3

std::shared_ptr<Shape> ShapeFactory::createCircle() {
    std::string name = getString("Enter circle name: ");
    double x = getDouble("Enter center X: ");
    double y = getDouble("Enter center Y: ");
    double radius = getDouble("Enter radius: ");
    return std::make_shared<Circle>(name, Point(x, y), radius);
}

std::shared_ptr<Shape> ShapeFactory::createRectangle() {
    std::string name = getString("Enter rectangle name: ");
    double x1 = getDouble("Enter top-left X: ");
    double y1 = getDouble("Enter top-left Y: ");
    double x2 = getDouble("Enter bottom-right X: ");
    double y2 = getDouble("Enter bottom-right Y: ");
    return std::make_shared<Rectangle>(name, Point(x1, y1), Point(x2, y2));
}

std::shared_ptr<Shape> ShapeFactory::createTriangle() {
    std::string name = getString("Enter triangle name: ");
    double x1 = getDouble("Enter vertex A X: ");
    double y1 = getDouble("Enter vertex A Y: ");
    double x2 = getDouble("Enter vertex B X: ");
    double y2 = getDouble("Enter vertex B Y: ");
    double x3 = getDouble("Enter vertex C X: ");
    double y3 = getDouble("Enter vertex C Y: ");
    return std::make_shared<Triangle>(name, Point(x1, y1), Point(x2, y2), Point(x3, y3));
}

std::shared_ptr<Shape> ShapeFactory::createConvexPolygon() {
    std::string name = getString("Enter polygon name: ");
    int n = getInt("Enter number of vertices (minimum 3): ");
    if (n < MIN_VERTICES) {
        throw InvalidShapeParameters("Polygon must have at least 3 vertices");
    }

    std::vector<Point> points;
    for (int i = 0; i < n; ++i) {
        double x = getDouble("Enter vertex " + std::to_string(i + 1) + " X: ");
        double y = getDouble("Enter vertex " + std::to_string(i + 1) + " Y: ");
        points.emplace_back(x, y);
    }

    return std::make_shared<ConvexPolygon>(name, points);
}

std::string ShapeFactory::getString(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    return input;
}

double ShapeFactory::getDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail()) break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
    }
    return value;
}

int ShapeFactory::getInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail()) break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
    }
    return value;
}
