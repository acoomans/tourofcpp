#ifndef INC_CLASSES_VECTOR_H
#define INC_CLASSES_VECTOR_H

#include <algorithm>
#include <initializer_list>
#include <iostream>

#include "abstract_vector.h"

class Vector : AbstractVector {

protected:
    int size;
    int *elements;

public:
    Vector() : Vector(20) {};
    explicit Vector(int size) :
            size {size},
            elements {new int[size]} {};
    Vector(std::initializer_list<int> list) :
            size {static_cast<int>(list.size())},
            elements {new int[size]}
    { std::copy(list.begin(), list.end(), elements); };

    // copy constructor
    Vector(const Vector& v) : size {v.size}, elements {new int[v.size]} {
        std::cout << "copy ctor" << std::endl;
        for (int i=0; i<v.size; i++) {
            elements[i] = v.elements[i];
        }
    }

    // copy assignment
    Vector& operator=(const Vector& v) {
        std::cout << "copy assgnmt" << std::endl;
        auto *new_elements = new int[v.size];
        for (int i=0; i<v.size; i++) {
            new_elements[i] = v.elements[i];
        }
        delete [] elements;
        elements = new_elements;
        return *this;
    }

    // move constructor
    Vector(Vector&& v) noexcept : size {v.size}, elements {v.elements} {
        std::cout << "move ctor" << std::endl;
        v.size = 0;
        v.elements = nullptr;
    }

    // move assignment
    Vector& operator=(Vector&& v) noexcept {
        std::cout << "move assgnmt" << std::endl;
        v.size = 0;
        v.elements = nullptr;
        return *this;
    }

    // subscripting
    const int& operator[](int idx) const override { return elements[idx]; };
    int& operator[](int idx) override { return elements[idx]; };

    int getSize() const {
        return size;
    }
};

Vector operator+(const Vector& v1, const Vector& v2);

#endif // INC_CLASSES_VECTOR_H
