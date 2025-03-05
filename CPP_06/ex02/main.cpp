#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base *generate(void) {
    int random = rand() % 3;
    if (random == 0) {
        std::cout << "Generated A" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "Generated B" << std::endl;
        return new B();
    } else {
        std::cout << "Generated C" << std::endl;
        return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception &e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception &e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception &e) {}

    std::cout << "Unknown" << std::endl;
}

int main() {
    std::srand(std::clock());
    Base *base = generate();
    Base &ref = *base;
    identify(base);
    identify(ref);
    delete base;
    return 0;
}