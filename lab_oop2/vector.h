#ifndef M_VECTOR_H
#define M_VECTOR_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

template <typename T>
class m_vector {
private:
    std::vector<T> data;

public:
    // Конструкторы
    m_vector(int length = 0) : data(length) {
        if (length < 0) {
            throw std::invalid_argument("Vector length cannot be negative");
        }
    }

    m_vector(const m_vector<T>& vect) : data(vect.data) {}

    m_vector(m_vector<T>&& vect) noexcept : data(std::move(vect.data)) {}

    m_vector(std::initializer_list<T> lst) : data(lst) {}

    // Деструктор
    ~m_vector() = default;

    // Операторы присваивания
    m_vector<T>& operator=(const m_vector<T>& lst) {
        if (this != &lst) {
            data = lst.data;
        }
        return *this;
    }

    m_vector<T>& operator=(m_vector<T>&& lst) noexcept {
        data = std::move(lst.data);
        return *this;
    }

    // Доступ к элементам
    void set_elem(int index, const T& elem) {
        if (index < 0 || index >= get_length()) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = elem;
    }

    T& get_elem(int index) {
        if (index < 0 || index >= get_length()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& get_elem(int index) const {
        if (index < 0 || index >= get_length()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& operator[](int index) { return get_elem(index); }
    const T& operator[](int index) const { return get_elem(index); }

    // Преобразование в массив
    T* to_array() const {
        T* arr = new T[data.size()];
        std::copy(data.begin(), data.end(), arr);
        return arr;
    }

    // Размер вектора
    int get_length() const { return static_cast<int>(data.size()); }

    // Операторы сравнения
    bool operator==(const m_vector<T>& other) const {
        return data == other.data;
    }

    bool operator!=(const m_vector<T>& other) const {
        return !(*this == other);
    }

    // Арифметические операции
    m_vector<T>& operator+=(const m_vector<T>& vect) {
        if (get_length() != vect.get_length()) {
            throw std::invalid_argument("Vectors must be of same length");
        }
        for (int i = 0; i < get_length(); ++i) {
            data[i] += vect.data[i];
        }
        return *this;
    }

    m_vector<T>& operator-=(const m_vector<T>& vect) {
        if (get_length() != vect.get_length()) {
            throw std::invalid_argument("Vectors must be of same length");
        }
        for (int i = 0; i < get_length(); ++i) {
            data[i] -= vect.data[i];
        }
        return *this;
    }

    m_vector<T>& operator*=(const T& val) {
        for (auto& elem : data) {
            elem *= val;
        }
        return *this;
    }

    m_vector<T>& operator/=(const T& val) {
        if (val == 0) {
            throw std::invalid_argument("Division by zero");
        }
        for (auto& elem : data) {
            elem /= val;
        }
        return *this;
    }

    // Дружественные операторы
    friend m_vector<T> operator+(const m_vector<T>& v1, const m_vector<T>& v2) {
        m_vector<T> result(v1);
        result += v2;
        return result;
    }

    friend m_vector<T> operator-(const m_vector<T>& v1, const m_vector<T>& v2) {
        m_vector<T> result(v1);
        result -= v2;
        return result;
    }

    friend m_vector<T> operator*(const m_vector<T>& v1, const T& val) {
        m_vector<T> result(v1);
        result *= val;
        return result;
    }

    friend m_vector<T> operator/(const m_vector<T>& v1, const T& val) {
        m_vector<T> result(v1);
        result /= val;
        return result;
    }

    // Вывод в поток
    friend std::ostream& operator<<(std::ostream& os, const m_vector<T>& lst) {
        os << "[";
        for (size_t i = 0; i < lst.data.size(); ++i) {
            if (i != 0) os << ", ";
            os << lst.data[i];
        }
        os << "]";
        return os;
    }

    // Класс итератора
    class Iterator {
    private:
        typename std::vector<T>::iterator it;

    public:
        Iterator(typename std::vector<T>::iterator iterator) : it(iterator) {}

        Iterator& operator++() {
            ++it;
            return *this;
        }

        T& operator*() { return *it; }
        const T& operator*() const { return *it; }

        bool operator==(const Iterator& other) const { return it == other.it; }
        bool operator!=(const Iterator& other) const { return it != other.it; }
    };

    Iterator iterator_begin() { return Iterator(data.begin()); }
    Iterator iterator_end() { return Iterator(data.end()); }

    // Константные итераторы
    class ConstIterator {
    private:
        typename std::vector<T>::const_iterator it;

    public:
        ConstIterator(typename std::vector<T>::const_iterator iterator) : it(iterator) {}

        ConstIterator& operator++() {
            ++it;
            return *this;
        }

        const T& operator*() const { return *it; }

        bool operator==(const ConstIterator& other) const { return it == other.it; }
        bool operator!=(const ConstIterator& other) const { return it != other.it; }
    };

    ConstIterator iterator_begin() const { return ConstIterator(data.begin()); }
    ConstIterator iterator_end() const { return ConstIterator(data.end()); }
};

#endif // M_VECTOR_H
