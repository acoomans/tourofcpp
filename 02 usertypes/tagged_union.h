#ifndef USERTYPES_TAGGED_UNION_H
#define USERTYPES_TAGGED_UNION_H
#include <cstring>


enum Type {str, num};

union Value {
    char *s;
    int i;
};

struct TaggedUnion {
    Type t;
    Value v;
};

#endif // USERTYPES_TAGGED_UNION_H
