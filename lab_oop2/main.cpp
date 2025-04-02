#include "vector.h"
#include <iostream>
#include <cassert>

void test_constructors() {
    std::cout << "=== Testing constructors ===\n";

    // Конструктор по умолчанию
    m_vector<int> v0;
    assert(v0.get_length() == 0);

    // Конструктор с размером
    m_vector<int> v1(3);
    assert(v1.get_length() == 3);

    // Конструктор с initializer_list
    m_vector<int> v2 = {1, 2, 3, 4};
    assert(v2.get_length() == 4);
    assert(v2[0] == 1 && v2[3] == 4);

    // Конструктор копирования
    m_vector<int> v3(v2);
    assert(v3 == v2);

    // Конструктор перемещения
    m_vector<int> v4(std::move(m_vector<int>{5, 6, 7}));
    assert(v4.get_length() == 3);
    assert(v4[0] == 5 && v4[2] == 7);

    std::cout << "Constructors test passed!\n\n";
}

void test_accessors() {
    std::cout << "=== Testing accessors ===\n";
    m_vector<int> v = {10, 20, 30};

    // set_elem/get_elem
    v.set_elem(1, 25);
    assert(v.get_elem(1) == 25);

    // operator[]
    v[2] = 35;
    assert(v[2] == 35);

    // get_length
    assert(v.get_length() == 3);

    // to_array
    int* arr = v.to_array();
    assert(arr[0] == 10 && arr[1] == 25 && arr[2] == 35);
    delete[] arr;

    // Проверка константного доступа
    const m_vector<int> cv = {1, 2, 3};
    assert(cv[1] == 2);
    assert(cv.get_elem(2) == 3);

    std::cout << "Accessors test passed!\n\n";
}

void test_arithmetic() {
    std::cout << "=== Testing arithmetic ===\n";
    m_vector<int> a = {1, 2, 3};
    m_vector<int> b = {4, 5, 6};

    // +=
    m_vector<int> c = a;
    c += b;
    assert(c[0] == 5 && c[1] == 7 && c[2] == 9);

    // -=
    c -= b;
    assert(c == a);

    // +
    auto d = a + b;
    assert(d[1] == 7);

    // -
    auto e = d - b;
    assert(e == a);

    // * с числом
    auto f = a * 3;
    assert(f[2] == 9);

    // / с числом
    auto g = f / 3;
    assert(g == a);

    std::cout << "Arithmetic test passed!\n\n";
}

void test_iterators() {
    std::cout << "=== Testing iterators ===\n";
    m_vector<int> v = {1, 3, 5, 7};

    // Проверка неконстантных итераторов
    int sum = 0;
    for (auto it = v.iterator_begin(); it != v.iterator_end(); ++it) {
        sum += *it;
    }
    assert(sum == 16);

    // Проверка константных итераторов
    const m_vector<int> cv = {2, 4, 6};
    sum = 0;
    for (auto it = cv.iterator_begin(); it != cv.iterator_end(); ++it) {
        sum += *it;
    }
    assert(sum == 12);

    // Модификация через итератор
    for (auto it = v.iterator_begin(); it != v.iterator_end(); ++it) {
        *it += 1;
    }
    assert(v[0] == 2 && v[3] == 8);

    std::cout << "Iterators test passed!\n\n";
}

void test_output() {
    std::cout << "=== Testing output ===\n";
    m_vector<int> v = {2, 4, 6, 8};
    std::cout << "Vector output: " << v << "\n";

    // Проверка вывода пустого вектора
    m_vector<int> empty;
    std::cout << "Empty vector: " << empty << "\n";

    std::cout << "Output test passed!\n\n";
}

void test_exceptions() {
    std::cout << "=== Testing exceptions ===\n";
    m_vector<int> v = {1, 2, 3};

    try {
        v.set_elem(3, 4);  // Выход за границы
        assert(false);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range (set_elem): " << e.what() << "\n";
    }

    try {
        m_vector<int> v2(-1);  // Отрицательный размер
        assert(false);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument (constructor): " << e.what() << "\n";
    }

    try {
        m_vector<int> v3 = {1, 2};
        m_vector<int> v4 = {1, 2, 3};
        v3 += v4;  // Разные размеры
        assert(false);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument (operator+=): " << e.what() << "\n";
    }

    try {
        auto v5 = v / 0;  // Деление на ноль
        assert(false);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument (division): " << e.what() << "\n";
    }

    std::cout << "Exceptions test passed!\n\n";
}

int main() {
    test_constructors();
    test_accessors();
    test_arithmetic();
    test_iterators();
    test_output();
    test_exceptions();

    std::cout << "All vector tests passed successfully!\n";
    return 0;
}
