#include <iostream>
#include <windows.h>
#include "shape_container.h"
#include "console_ui.h"

using namespace std;

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    cout << "Program started!" << endl;

    ShapeContainer shapeContainer;

    while (true) {
        try {
            ConsoleUI::show_menu();
            int choice = ConsoleUI::input_int("Enter your choice: ");

            if (choice == 1) {
                cout << "Adding a shape." << endl;
                ConsoleUI::show_message("1. Circle\n2. Rectangle\n3. Triangle\n4. Polygon");
                int type = ConsoleUI::input_int("Select type: ");
                shapeContainer.add_shape(ConsoleUI::create_shape(type));
                ConsoleUI::show_message("Shape added.");
            } else if (choice == 2) {
                cout << "Listing all shapes." << endl;
                ConsoleUI::list_shapes(shapeContainer.get_shapes());
            } else if (choice == 3) {
                cout << "Listing areas." << endl;
                ConsoleUI::list_areas(shapeContainer.get_shapes());
            } else if (choice == 4) {
                cout << "Calculating total area." << endl;
                double total = shapeContainer.total_area();
                ConsoleUI::show_message("Total area: " + to_string(total));
            } else if (choice == 5) {
                cout << "Sorting shapes by area." << endl;
                shapeContainer.sort_by_area();
                ConsoleUI::show_message("Shapes sorted by area.");
            } else if (choice == 6) {
                cout << "Deleting a shape by number." << endl;
                size_t num = ConsoleUI::input_int("Enter the shape number to delete: ");
                shapeContainer.remove_shape(num - 1); // Индексация с 0
                ConsoleUI::show_message("Shape deleted.");
            } else if (choice == 7) {
                cout << "Deleting shapes by area threshold." << endl;
                double threshold = ConsoleUI::input_double("Enter the area threshold: ");
                shapeContainer.remove_shapes_above_area(threshold);
                ConsoleUI::show_message("Shapes removed.");
            } else if (choice == 8) {
                cout << "Exiting." << endl;
                return 0;
            } else {
                cout << "Invalid choice." << endl;
                ConsoleUI::show_error("Invalid choice. Please try again.");
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            ConsoleUI::show_error(e.what());
        }
    }
}
