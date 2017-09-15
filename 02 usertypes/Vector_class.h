#ifndef USERTYPES_VECTOR_CLASS_H
#define USERTYPES_VECTOR_CLASS_H


class Vector_class {
public:
    explicit Vector_class(int size): elem {new double[size]}, size {size} {};

    double& operator[](int idx) { return elem[idx]; };

    int getSize() { return size; };

private:
    int size;
    double *elem;
};


#endif // USERTYPES_VECTOR_CLASS_H
