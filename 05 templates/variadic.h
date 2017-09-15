#ifndef INC_TEMPLATES_VARIADIC_H
#define INC_TEMPLATES_VARIADIC_H

#include "iostream"

void variadic();

template<typename T, typename ...Tail>
void variadic(T head, Tail... tail) {
    std::cout << head << std::endl;
    variadic(tail ...);
};

#endif // INC_TEMPLATES_VARIADIC_H
