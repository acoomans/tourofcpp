#ifndef INC_CLASSES_VECTOR_H
#define INC_CLASSES_VECTOR_H

#include <algorithm>
#include <initializer_list>
#include <iostream>

template <typename T>
class Vector {

protected:
    int size;
    T *elements;

public:
    Vector() : Vector(20) {};

    explicit Vector(int size) {
        size = size;
        elements = new T[size];
    }

    Vector(std::initializer_list<T> list) {
        size = static_cast<T>(list.size());
        elements = new T[size];
        std::copy(list.begin(), list.end(), elements);
    }

    Vector(const Vector<T>& v) : size {v.size}, elements {new T[v.size]} {
        size = v.size;
        elements = new T[v.size];
        std::cout << "copy ctor" << std::endl;
        for (int i=0; i<v.size; i++) {
            elements[i] = v.elements[i];
        }
    }

    Vector<T>& operator=(const Vector& v) {
        std::cout << "copy assgnmt" << std::endl;
        auto *new_elements = new T[v.size];
        for (int i=0; i<v.size; i++) {
            new_elements[i] = v.elements[i];
        }
        delete [] elements;
        elements = new_elements;
        return *this;
    }

    Vector(Vector<T>&& v) noexcept{
        size = v.size;
        elements = v.elements;
        std::cout << "move ctor" << std::endl;
        v.size = 0;
        v.elements = nullptr;
    }

    Vector<T>& operator=(Vector<T>&& v) noexcept {
        std::cout << "move assgnmt" << std::endl;
        v.size = 0;
        v.elements = nullptr;
        return *this;
    }

    const T& operator[](int idx) const { return elements[idx]; };

    T& operator[](int idx) { return elements[idx]; };

    int getSize() const {
        return size;
    }

    void foreach(std::function<void(T& t)> callback) {
        for (int i=0; i<size; i++) {
            callback(elements[i]);
        }
    };

};

template<typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2);

#endif // INC_CLASSES_VECTOR_H
