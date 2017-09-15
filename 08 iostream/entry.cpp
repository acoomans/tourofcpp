// Copyright (c) 9/3/17 Arnaud Coomans.

#include "entry.h"

std::ostream& operator<<(std::ostream &os, Entry& e) {
    return os << "{\"" << e.name << "\", " << e.number << "}";
}