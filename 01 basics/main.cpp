#include <iostream>

using namespace std;

double sq(double x) {
    return x*x;
}

void print_square(double x) {
    cout << "the square of " << x << " is " << sq(x) << "\n";
}

int main() {
    std::cout << "Hello, World!\n";

    string s {"Hello "};
    string t {65}; // this converts ascii code
    string u = {" again!"};
    cout << s + t + u << std::endl; // -> Hello A again!

    print_square(1.2); // -> the square of 1.2 is 1.44

    string v ("bye ");
    string w = "bye\n";
    // string x = 65; // does not work
    cout << v + w; // -> bye bye

    /* Narrowing conversions */

    float f1 = 7.2;
    int i1 = 7.2; // warning: conversion loss
    // int i2 {7.2}; // error: cannot narrow
    // int i3 = {7.2}; // error: cannot narrow
    int i4 = (7.2); // warning: conversion loss
    auto f2 = f1;

    cout << f1 << endl; // -> 7.2
    cout << i1 << endl; // -> 7
    // cout << i2 << endl;
    // cout << i3 << endl;
    cout << i4 << endl; // -> 7
    cout << f2 << endl; // -> 7.2


    int arr[] = {0, 1, 2, 3};
    for (auto a : arr) {
        cout << a << std::endl; // -> 0, 1, 2, 3
    }

    return 0;
}