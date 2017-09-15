#include <iostream>

#include "Vector_struct.h"
#include "Vector_class.h"
#include "tagged_union.h"
#include "enum.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    /* structure */

    Vector_struct v = Vector_struct();
    std::cout << v.size << std::endl; // -> 0
    vector_struct_init(v, 5);
    std::cout << v.size << std::endl; // -> 5

    /* class */

    Vector_class w = Vector_class(6);
//    Vector_class z = 10; // error if contructor is explicit
    std::cout << w.getSize() << std::endl; // -> 6


    /* tagged union */

    TaggedUnion tu = {
            .t = str,
            .v.s = "hello"
//            .t = num,
//            .v.i = 10
    };

    if (tu.t == str) {
        std::cout << tu.v.s << std::endl;
    } else if (tu.t == num) {
        std::cout << tu.v.i << std::endl;
    } // -> hello

    /* enum */
    E e = E::red;
    std::cout << e << std::endl;

    ++e;
    std::cout << e << std::endl;


    return 0;
}