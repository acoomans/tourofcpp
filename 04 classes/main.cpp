#include <iostream>

#include "vector.h"


int main() {

    Vector v = { 0, 10, 20 };

    std::cout << v[0] << std::endl; // -> 0
    std::cout << v[1] << std::endl; // -> 10
    std::cout << v[2] << std::endl; // -> 20

    Vector v2 = v;
    Vector v3 = Vector(v);
    v[0] = 100;
    v2[0] = 200;
    v3[0] = 300;
    std::cout << v[0] << std::endl;  // -> 100
    std::cout << v2[0] << std::endl; // -> 200
    std::cout << v3[0] << std::endl; // -> 300

    Vector a1 = { 1, 2 };
    Vector a2 = { 3, 4 };
    Vector a3 = { 5, 6 };
    Vector a = a1 + a2 + a3;
    for (int i=0; i<a.getSize(); i++) {
        std::cout << a[i] << std::endl;  // -> 1, 2, 3, 4, 5, 6
    }

    Vector b1 = {15};
    Vector b2 = std::move(b1);
//    std::cout << b1[0] << std::endl;  // empty
    std::cout << b2[0] << std::endl;  // -> 15

    Vector c1 = {25};
    Vector& c2 = c1;
    c1[0] = 30;
    std::cout << c1[0] << std::endl; // -> 30
    std::cout << c2[0] << std::endl; // -> 30

    Vector c3 = {45};
    c2 = c3; // no re-assignment
    c3[0] = 50;
    std::cout << c3[0] << std::endl; // -> 50
    std::cout << c2[0] << std::endl; // -> 45


    return 0;
}