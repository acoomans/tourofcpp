#include <iostream>
#include <string>

#include "vector.h"
#include "LessThan.h"
#include "variadic.h"

int main() {

    /* templates */

    Vector<int> v = { 0, 10, 20 };

    std::cout << v[0] << std::endl; // -> 0
    std::cout << v[1] << std::endl; // -> 10
    std::cout << v[2] << std::endl; // -> 20

    /* functor */

    LessThan<int> lt(10);
    std::cout << lt(4) << std::endl; // -> 1

    /* lambda */

    int a = 1;
    std::cout << [&](int i){return ++a;}(a) << std::endl; // -> 2
    std::cout << [=](int i){return a+1;}(a) << std::endl; // -> 3
    std::cout << a << std::endl; // -> 2

    Vector<int> w = {11, 22, 33};
    w.foreach([&](int b){ std::cout << b << std::endl; }); // -> 11, 22, 33

    /* variadic templates */

    variadic<int, std::string, std::string>(91, "hello", "bye");

    /* aliases */

    //TODO

    return 0;
}