#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>

template <typename T>
class list {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    // Конструкторы и деструктор
    list() : head(nullptr), tail(nullptr), length(0) {}

    list(const list<T>& lst) : head(nullptr), tail(nullptr), length(0) {
        for (Node* temp = lst.head; temp != nullptr; temp = temp->next) {
            add(temp->data);
        }
    }

    list(list<T>&& lst) noexcept : head(lst.head), tail(lst.tail), length(lst.length) {
        lst.head = nullptr;
        lst.tail = nullptr;
        lst.length = 0;
    }

    list(std::initializer_list<T> lst) : head(nullptr), tail(nullptr), length(0) {
        for (const T& elem : lst) {
            add(elem);
        }
    }

    ~list() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Оператор присваивания
    list<T>& operator=(const list<T>& lst) {
        if (this != &lst) {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            length = 0;
            for (Node* temp = lst.head; temp != nullptr; temp = temp->next) {
                add(temp->data);
            }
        }
        return *this;
    }

    // Методы для работы со списком
    int get_length() const {
        return length;
    }

    void add(const T& elem) {
        Node* newNode = new Node(elem);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void add_range(const list<T>& lst) {
        for (Node* temp = lst.head; temp != nullptr; temp = temp->next) {
            add(temp->data);
        }
    }

    void add_range(std::initializer_list<T> lst) {
        for (const T& elem : lst) {
            add(elem);
        }
    }

    void set_elem(int index, const T& elem) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = elem;
    }

    T& get_elem(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void remove_elem(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
            }
            Node* temp = prev->next;
            prev->next = temp->next;
            if (temp == tail) {
                tail = prev;
            }
            delete temp;
        }
        length--;
    }

    list<T> combine(const list<T>& lst) {
        list<T> newList(*this);
        newList.add_range(lst);
        return newList;
    }

    void sort(int (*comp)(const T& r1, const T& r2)) {
        if (length <= 1) return;
        bool swapped;
        do {
            swapped = false;
            Node* prev = nullptr;
            Node* curr = head;
            while (curr->next != nullptr) {
                if (comp(curr->data, curr->next->data) > 0) {
                    T temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = true;
                }
                prev = curr;
                curr = curr->next;
            }
        } while (swapped);
    }

    int get_index(T &elem) const {
        int index = 0;
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->data == elem) {
                return index;
            }
            index++;
        }
        return -1;
    }

    T* to_array() {
        T* arr = new T[length];
        Node* temp = head;
        for (int i = 0; i < length; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }
        return arr;
    }

    T& operator[](int index) {
        return get_elem(index);
    }

    // Класс итератора
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        T& operator*() {
            if (current == nullptr) {
                throw std::out_of_range("Iterator out of range");
            }
            return current->data;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};

#endif // LIST_H
