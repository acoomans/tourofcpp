#ifndef INC_IOSTREAM_ENTRY_H
#define INC_IOSTREAM_ENTRY_H

#include <iostream>
#include <string>

class Entry {
public:
    std::string name;
    int number;

    Entry(std::string name, int number) : name {name}, number {number} {};
};

std::ostream& operator<<(std::ostream &os, Entry& e);

// TODO: operator>>


#endif // INC_IOSTREAM_ENTRY_H
