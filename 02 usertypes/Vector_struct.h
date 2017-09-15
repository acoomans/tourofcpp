#ifndef USERTYPES_VECTOR_STRUCT_H
#define USERTYPES_VECTOR_STRUCT_H


struct Vector_struct {
    int size;
    double *elem;
};

void vector_struct_init(Vector_struct& v, int size);


#endif // USERTYPES_VECTOR_STRUCT_H
