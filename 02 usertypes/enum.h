#ifndef USERTYPES_ENUM_H
#define USERTYPES_ENUM_H

#include <iostream>

enum class E {
    red,
    green,
    blue
};

E& operator++(E& e);

std::ostream& operator<<(std::ostream& os, E& e);

#endif // USERTYPES_ENUM_H
