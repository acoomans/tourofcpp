#include "vector.h"

template<typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) {
    Vector<T> r(v1.getSize() + v2.getSize());
    for (int i=0; i<v1.getSize(); i++) {
        r[i] = v1[i];
    }
    for (int i=0; i<v2.getSize(); i++) {
        r[i+v1.getSize()] = v2[i];
    }
    return r;
}