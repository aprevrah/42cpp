#include <iostream>
#include "iter.hpp"

//int
void add_three(int &i) {
    i += 3;
}

void half(double &d) {
    d *= 0.5;
}

void awesome(std::string &s) {
    s = "awesome " + s;
}

template <typename T>
void print(T &t) {
    std::cout << t << std::endl;
}

int main( void ) {
    int int_array[] = {1, 2, 3, 4, 5};
    double double_array[] = {1, 2, 3, 4, 5};
    std::string string_array[] = {"one", "two", "three", "four", "five"};

    iter(int_array, 5, add_three);
    iter(int_array, 5, print);

    iter(double_array, 5, half);
    iter(double_array, 5, print);

    iter(string_array, 5, awesome);
    iter(string_array, 5, print);
    return 0;
}