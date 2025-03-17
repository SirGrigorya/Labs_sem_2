#include "list.h"

int main() {
    // Создание списка
    list<int> lst = {3, 1, 4, 1, 5, 9};
    std::cout << "Initial list: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Добавление элементов
    lst.add(2);
    lst.add_range({6, 5, 3});
    std::cout << "After adding elements: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Сортировка списка
    lst.sort([](const int& a, const int& b) { return a - b; });
    std::cout << "After sorting: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Удаление элемента
    lst.remove_elem(2);
    std::cout << "After removing element at index 2: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Получение элемента по индексу
    std::cout << "Element at index 3: " << lst.get_elem(3) << std::endl;

    // Преобразование списка в массив
    int* arr = lst.to_array();
    std::cout << "List as array: ";
    for (int i = 0; i < lst.get_length(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;

    return 0;
}
