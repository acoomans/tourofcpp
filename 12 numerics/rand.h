#ifndef INC_NUMERICS_RAND_H
#define INC_NUMERICS_RAND_H

#include <random>

class Rand {

public:
    Rand(int a, int b) : dist {a, b}, gen(seed()) {};
    int operator()() { return dist(gen); };

private:
    std::uniform_int_distribution<> dist;

    // crappy default generator
//    std::default_random_engine gen;

    // better (best?) generator
    std::random_device seed;
    std::mt19937 gen;

};


#endif // INC_NUMERICS_RAND_H
