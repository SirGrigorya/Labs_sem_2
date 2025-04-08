#ifndef M_VECTOR_ITERATOR_H
#define M_VECTOR_ITERATOR_H

template <typename T>
class m_vector_iterator {
private:
    T* ptr;

public:
    explicit m_vector_iterator(T* pointer) : ptr(pointer) {}

    m_vector_iterator& operator++() {
        ++ptr;
        return *this;
    }

    m_vector_iterator operator++(int) {
        m_vector_iterator temp = *this;
        ++ptr;
        return temp;
    }

    T& operator*() { return *ptr; }
    const T& operator*() const { return *ptr; }

    T* operator->() { return ptr; }
    const T* operator->() const { return ptr; }

    bool operator==(const m_vector_iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const m_vector_iterator& other) const { return ptr != other.ptr; }
};

#endif // M_VECTOR_ITERATOR_H
