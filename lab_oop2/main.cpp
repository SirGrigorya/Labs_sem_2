#include "vector_tests.h"
#include <iostream>
#include <cassert>

void display_menu() {
    std::cout << "\n=== Vector Test Menu ===\n";
    std::cout << "1. Test Constructors\n";
    std::cout << "2. Test Accessors\n";
    std::cout << "3. Test Arithmetic Operations\n";
    std::cout << "4. Test Iterators\n";
    std::cout << "5. Test Output\n";
    std::cout << "6. Test Exceptions\n";
    std::cout << "7. Run All Tests\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice = 0;

    do {
        display_menu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            clear_input_buffer();
            continue;
        }

        clear_input_buffer();

        if (choice == 1) {
            test_constructors();
        }
        else if (choice == 2) {
            test_accessors();
        }
        else if (choice == 3) {
            test_arithmetic();
        }
        else if (choice == 4) {
            test_iterators();
        }
        else if (choice == 5) {
            test_output();
        }
        else if (choice == 6) {
            test_exceptions();
        }
        else if (choice == 7) {
            run_all_tests();
        }
        else if (choice == 0) {
            std::cout << "Exiting...\n";
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
