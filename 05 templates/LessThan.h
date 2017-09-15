#ifndef INC_TEMPLATES_LESSTHAN_H
#define INC_TEMPLATES_LESSTHAN_H

template<typename T>
class LessThan {
    const T value;
public:
    LessThan(const T& t) : value {t} {};
    bool operator()(const T& t) const { return t<value; };
};


#endif // INC_TEMPLATES_LESSTHAN_H
