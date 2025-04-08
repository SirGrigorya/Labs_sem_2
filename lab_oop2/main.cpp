#include "vector.h"
#include <iostream>
#include <cassert>
#include <limits>

void clear_input_buffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void test_constructors() {
    std::cout << "\n=== Testing constructors ===\n";

    m_vector<int> v0;
    assert(v0.get_length() == 0);
    std::cout << "Default constructor: OK\n";

    m_vector<int> v1(3);
    assert(v1.get_length() == 3);
    std::cout << "Size constructor: OK\n";

    m_vector<int> v2 = {1, 2, 3, 4};
    assert(v2.get_length() == 4);
    assert(v2[0] == 1 && v2[3] == 4);
    std::cout << "Initializer list constructor: OK\n";

    m_vector<int> v3(v2);
    assert(v3 == v2);
    std::cout << "Copy constructor: OK\n";

    m_vector<int> v4(std::move(m_vector<int>{5, 6, 7}));
    assert(v4.get_length() == 3);
    assert(v4[0] == 5 && v4[2] == 7);
    std::cout << "Move constructor: OK\n";

    std::cout << "=== Constructors test passed! ===\n";
}

void test_accessors() {
    std::cout << "\n=== Testing accessors ===\n";
    m_vector<int> v = {10, 20, 30};

    v.set_elem(1, 25);
    assert(v.get_elem(1) == 25);
    std::cout << "set_elem/get_elem: OK\n";

    v[2] = 35;
    assert(v[2] == 35);
    std::cout << "operator[]: OK\n";

    assert(v.get_length() == 3);
    std::cout << "get_length: OK\n";

    int* arr = v.to_array();
    assert(arr[0] == 10 && arr[1] == 25 && arr[2] == 35);
    delete[] arr;
    std::cout << "to_array: OK\n";

    const m_vector<int> cv = {1, 2, 3};
    assert(cv[1] == 2);
    assert(cv.get_elem(2) == 3);
    std::cout << "const access: OK\n";

    std::cout << "=== Accessors test passed! ===\n";
}

void test_arithmetic() {
    std::cout << "\n=== Testing arithmetic ===\n";
    m_vector<int> a = {1, 2, 3};
    m_vector<int> b = {4, 5, 6};

    m_vector<int> c = a;
    c += b;
    assert(c[0] == 5 && c[1] == 7 && c[2] == 9);
    std::cout << "operator+=: OK\n";

    c -= b;
    assert(c == a);
    std::cout << "operator-=: OK\n";

    auto d = a + b;
    assert(d[1] == 7);
    std::cout << "operator+: OK\n";

    auto e = d - b;
    assert(e == a);
    std::cout << "operator-: OK\n";

    auto f = a * 3;
    assert(f[2] == 9);
    std::cout << "operator*: OK\n";

    auto g = f / 3;
    assert(g == a);
    std::cout << "operator/: OK\n";

    std::cout << "=== Arithmetic test passed! ===\n";
}

void test_iterators() {
    std::cout << "\n=== Testing iterators ===\n";
    m_vector<int> v = {1, 3, 5, 7};

    int sum = 0;
    for (auto it = v.iterator_begin(); it != v.iterator_end(); ++it) {
        sum += *it;
    }
    assert(sum == 16);
    std::cout << "Non-const iterators: OK\n";

    const m_vector<int> cv = {2, 4, 6};
    sum = 0;
    for (auto it = cv.iterator_begin(); it != cv.iterator_end(); ++it) {
        sum += *it;
    }
    assert(sum == 12);
    std::cout << "Const iterators: OK\n";

    for (auto it = v.iterator_begin(); it != v.iterator_end(); ++it) {
        *it += 1;
    }
    assert(v[0] == 2 && v[3] == 8);
    std::cout << "Iterator modification: OK\n";

    std::cout << "=== Iterators test passed! ===\n";
}

void test_output() {
    std::cout << "\n=== Testing output ===\n";
    m_vector<int> v = {2, 4, 6, 8};
    std::cout << "Vector output: " << v << "\n";

    m_vector<int> empty;
    std::cout << "Empty vector: " << empty << "\n";

    std::cout << "=== Output test passed! ===\n";
}

void test_exceptions() {
    std::cout << "\n=== Testing exceptions ===\n";
    m_vector<int> v = {1, 2, 3};

    try {
        v.set_elem(3, 4);
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: " << e.what() << " - OK\n";
    }

    try {
        m_vector<int> v2(-1);
        assert(false);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: " << e.what() << " - OK\n";
    }

    try {
        m_vector<int> v3 = {1, 2};
        m_vector<int> v4 = {1, 2, 3};
        v3 += v4;
        assert(false);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: " << e.what() << " - OK\n";
    }

    try {
        auto v5 = v / 0;
        assert(false);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: " << e.what() << " - OK\n";
    }

    std::cout << "=== Exceptions test passed! ===\n";
}

void run_all_tests() {
    std::cout << "\nRunning all tests...\n";
    test_constructors();
    test_accessors();
    test_arithmetic();
    test_iterators();
    test_output();
    test_exceptions();
    std::cout << "\nAll tests passed successfully!\n";
}

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
