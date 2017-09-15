#ifndef INC_CLASSES_ABSTRACT_VECTOR_H
#define INC_CLASSES_ABSTRACT_VECTOR_H

class AbstractVector {
public:
    virtual const int& operator[](int idx) const =0;
    virtual int& operator[](int idx) =0;
};

#endif // INC_CLASSES_ABSTRACT_VECTOR_H
