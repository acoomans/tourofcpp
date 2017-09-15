#include <iostream>

#include "vector.h"


int main() {

    /* namespace */

    using namespace space;

//    space::Vector v {10};
    Vector v {10};
    v[0] = 0;
    v[1] = 10;
    v[2] = 20;
    std::cout << v[0] << std::endl;
    std::cout << v[1] << std::endl;
    std::cout << v[2] << std::endl;

    int a = v[1];


    /* exceptions */

    try {
        Vector w {20};
        int a = w[100];
        std::cout << a << std::endl;
    } catch (vector_exception) {
        std::cout << "exception thrown" << std::endl;
    }

    return 0;
}