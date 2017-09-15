#include <iostream>

#include <array>
#include <bitset>
#include <chrono>
#include <functional> // bind
#include <iostream>
#include <memory> // unique_ptr, shared_ptr
#include <tuple>
#include <type_traits>
#include <utility> // pair

class F;
std::ostream& operator<<(std::ostream &os, F& f);


class S {
public:
    std::string s;
    S(std::string s): s {s} {};
};

class A {
public:
    std::unique_ptr<S> s;
    std::shared_ptr<S> s2;
    std::weak_ptr<S> s3;
    A() : s {nullptr} {};
    ~A() {};
};

class B {
public:
    std::unique_ptr<S> s;
    std::shared_ptr<S> s2;
    std::weak_ptr<S> s3;
    B() : s {nullptr} {};
    ~B() {};
};

void f(std::string s1, std::string s2, std::string s3) {
    std::cout << s1 << ", " << s2 << ", " << s3 << std::endl;
}

class F {
public:
    void f() {
        std::cout << "hello " << *this << std::endl;
    }
};

std::ostream& operator<<(std::ostream &os, F& f) {
    return os << "F";
}

class M {
public:
    std::function<std::string(void)> m;
    std::string IAm() {
        return "I am ";
    }
    void print() {
        std::cout << this->m() << std::endl;
    }
};


int main() {

    /* smart pointers */

    std::unique_ptr<S> s {new S("hello")};
    A a;
//    a.s = s; // won't work, need move
    a.s = std::move(s);
    std::cout << a.s->s << std::endl;
    B b;
    b.s = std::move(a.s);
    if (a.s) {
        std::cout << a.s->s << std::endl;
    } else {
        std::cout << "a has no pointer" << std::endl;
    }
    if (b.s) {
        std::cout << b.s->s << std::endl;
    } else {
        std::cout << "b has no pointer" << std::endl;
    }

    std::shared_ptr<S> s2 {new S("bye")};
    A a2;
    a2.s2 = s2; // copy ok here
    B b2;
    b2.s2 = a2.s2; // copy ok here
    if (a2.s2) {
        std::cout << a2.s2->s << std::endl;
    } else {
        std::cout << "a2 has no pointer" << std::endl;
    }
    if (b2.s2) {
        std::cout << b2.s2->s << std::endl;
    } else {
        std::cout << "b2 has no pointer" << std::endl;
    }
    if (a2.s2 == b2.s2) {
        std::cout << "a2 and b2 have same pointer" << std::endl;
    }


    /* array */

    int arr1[3] = {1,2,3};
    for (auto x : arr1) {
        std::cout << x << std::endl; // -> 1, 2, 3
    }
    // no size for array

    std::array<int,3> arr2 = {4,5,6};
    for (auto x : arr2) {
        std::cout << x << std::endl; // -> 4, 5, 6
    }
    std::cout << "c++ array has size: " + std::to_string(arr2.size()) << std::endl; // -> size: 3
    std::array<int,3> arr3 = arr2; // can be copied right away
    for (auto x : arr2) {
        std::cout << x << std::endl; // -> 4, 5, 6
    }
    for (auto x : arr3) {
        std::cout << x << std::endl; // -> 4, 5, 6
    }


    /* bitset */

    std::bitset<3> bs {"101"};
    std::cout << bs << std::endl; // -> 101

    std::bitset<3> bs2 {5};
    std::cout << bs2 << std::endl; // -> 101
    bs2 = bs2 << 1;
    std::cout << bs2 << std::endl; // -> 010


    /* pair */

    std::pair<std::string, int> p {"hey", 123};
    std::cout << p.first << ", " << p.second << std::endl; // -> hey, 123


    /* tuple */

    std::tuple<int, int, int> t {1, 2, 3};
    std::cout << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << std::endl; // -> 1, 2, 3


    /* time */

    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << "tick tock" << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() << std::endl;


    /* bind */

    auto g = std::bind(f, "hello", std::placeholders::_1, "bye");
    g("yo"); // -> hello, yo, bye


    /* mem_fn */

    auto fun = std::mem_fn(&F::f);
    F f;
    fun(f);  // -> hello F

    /* function */

    M m;
//    m.m = [*this](){ std::cout << this->IAm(); return "lambda M"; }; // can't capture this :(
    m.m = [](){ return "I am M"; };  // -> I am M
    m.print();


    // TODO iterator traits


    /* type predicate */

    bool is_a = std::is_arithmetic<int>();
    std::cout << is_a << std::endl; // -> 1



    return 0;
}