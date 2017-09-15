#include <iostream>

#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <condition_variable>
#include <future>

std::mutex m;
std::mutex m1;
std::mutex m2;

std::mutex mm;
std::condition_variable cv;

void wait(int sec) {

    /* sleep */

    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

template <typename T>
void p(T& t) {

    /* lock */

    std::unique_lock<std::mutex> lck {m};
    std::cout << t << std::endl;
}

template <typename T, typename TT>
void p2(T& t, TT& tt) {

    /* multiple locks */

    std::unique_lock<std::mutex> lck1 {m1, std::defer_lock};
    std::unique_lock<std::mutex> lck2 {m2, std::defer_lock};

    std::lock(lck1, lck2);

    std::cout << t << tt << std::endl;

    lck1.unlock();
    lck2.unlock();
}

void a() {
    p("a");
}

class B {
public:
    void operator()() {
        p("b");
    }
};


void c(int c) {
    p2(c, c);
}

class D {
public:
    void operator()(int d) {
        p("--");

        wait(3);
        p2(d, d);
    }
};


void e(std::promise<int>& pi) {
    if (true) {
        pi.set_value(6);
    } else {
        auto e = std::make_exception_ptr(std::exception());
        pi.set_exception(e);
    }
}

void f(std::future<int>& fi) {
    try {
        int i = fi.get();
        p(i);
    } catch (std::exception) {
        p("exception");
    }
}

int h() {
    return 2;
}


int z() {
    return 1000;
}

int main() {

    /* thread */

    std::thread t1 {a};
    std::thread t2 {B()};

    t1.join();
    t2.join();

    // -> ab or ba

    /* arguments */

    int ci = 1;
    int di = 2;

    std::thread t3 {c, ci};
    std::thread t4 {D(), di};

    t3.join();
    t4.join();

    // -> 11 22 or 22 11


    /* promise-future */

    std::promise<int> pp;
    std::future<int> fi {pp.get_future()};
    std::thread t5 {e, std::ref(pp)};
    std::thread t6 {f, std::ref(fi)};

    t5.join();
    t6.join();
    // -> 6 or exception


    /* packaged task */

    std::packaged_task<int()> pt {h};
    std::future<int> fii {pt.get_future()};
    std::thread t7 {std::move(pt)};
    std::cout << fii.get() << std::endl; // -> 2

    t7.join();


    /* async */

    auto j = std::async(z);
    std::cout << j.get() << std::endl; // -> 1000


    return 0;
}