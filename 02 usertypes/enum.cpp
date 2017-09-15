// Copyright (c) 9/2/17 Arnaud Coomans.

#include "enum.h"

E& operator++(E& e) {
    switch (e){
        case E::red:
            e = E::green;
            break;
        case E::green:
            e = E::blue;
            break;
        case E::blue:
            e = E::red;
            break;
    }
    return e;
}

std::ostream& operator<<(std::ostream& os, E& e) {
    switch (e) {
        case E::red:
            os << "R";
            break;
        case E::green:
            os << "G";
            break;
        case E::blue:
            os << "B";
            break;
        default:
            os << "default";
            break;
    }
    return os;
}