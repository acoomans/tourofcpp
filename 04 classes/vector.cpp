#include "vector.h"

Vector operator+(const Vector& v1, const Vector& v2) {
    Vector r(v1.getSize() + v2.getSize());
    for (int i=0; i<v1.getSize(); i++) {
        r[i] = v1[i];
    }
    for (int i=0; i<v2.getSize(); i++) {
        r[i+v1.getSize()] = v2[i];
    }
    return r;
}