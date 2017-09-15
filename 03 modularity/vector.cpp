#include "vector.h"

namespace space {
    int& Vector::operator[](int index) {
        if (index > size) {
            throw vector_exception();
        }

        return elements[index];
    }
}

const int& space::Vector::operator[](int index) const {
    if (index > size) {
        throw vector_exception();
    }
    return elements[index];
}

