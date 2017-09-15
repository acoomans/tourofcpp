#include "Vector_struct.h"

void vector_struct_init(Vector_struct& v, int size){
    v.size = size;
    v.elem = new double[size];
}