#ifndef M_VECTOR_CONST_ITERATOR_H
#define M_VECTOR_CONST_ITERATOR_H

template <typename T>
class m_vector_const_iterator {
private:
    const T* ptr;

public:
    explicit m_vector_const_iterator(const T* pointer) : ptr(pointer) {}

    m_vector_const_iterator& operator++() {
        ++ptr;
        return *this;
    }

    m_vector_const_iterator operator++(int) {
        m_vector_const_iterator temp = *this;
        ++ptr;
        return temp;
    }

    const T& operator*() const { return *ptr; }

    const T* operator->() const { return ptr; }

    bool operator==(const m_vector_const_iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const m_vector_const_iterator& other) const { return ptr != other.ptr; }
};

#endif // M_VECTOR_CONST_ITERATOR_H
