#include <iostream>
#include <vector>
#include "easyfind.hpp"


int main() {
    std::vector<int> vec;
    for (int i = 0; i < 30; ++i) {
        vec.push_back(i);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 50);
        std::cout << "Element found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::string str = "Hello, world!";
        std::string::iterator it = easyfind(str, 'e');
        std::cout << "Element found: " << *it << " at: " << std::distance(str.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}