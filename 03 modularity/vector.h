#ifndef MODULARITY_VECTOR_H
#define MODULARITY_VECTOR_H

#include <exception>

namespace space {

    class vector_exception : std::exception {};

    class Vector {

    protected:
        int size;
        int *elements;

    public:
        explicit Vector(int size) : size {size}, elements {new int[size]} {};
        ~Vector() { delete[] elements; };

        int& operator[](int index); // write
        const int& operator[](int index) const; // read

    };

} // space

#endif // MODULARITY_VECTOR_H
