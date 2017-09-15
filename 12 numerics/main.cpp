#include <iostream>

#include "rand.h"

int main() {

    /* random */

    Rand r {1, 10};
    int i = r();
    std::cout << i << std::endl; // -> some random number

    return 0;
}