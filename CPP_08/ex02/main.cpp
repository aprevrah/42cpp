#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding random numbers

void testMutantStack() {
    std::cout << "===== Basic Tests =====" << std::endl;
    std::stack<int> stack;
    MutantStack<int> mutantStack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.pop();
    mutantStack.push(1);
    mutantStack.push(2);
    mutantStack.push(3);
    mutantStack.push(4);
    mutantStack.pop();

    std::cout << "S Top: " << stack.top() << std::endl;
    std::cout << "MS Top: " << mutantStack.top() << std::endl;
    std::cout << "S Size: " << stack.size() << std::endl;
    std::cout << "MS Size: " << mutantStack.size() << std::endl;
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    std::cout << "===== Random Test =====" << std::endl;
    try {
        MutantStack<int> randMStack;
        std::stack<int> randStack;
        std::srand(std::time(0)); // Seed for random values
        for (int i = 0; i < 10; ++i) {
            randMStack.push(std::rand() % 1000000000);
            randStack.push(randMStack.top());
        }
        std::cout << "Top: MS: " << randMStack.top() << " S: " << randStack.top() << std::endl;
        std::cout << "Size: " << randMStack.size() << std::endl;
        for (MutantStack<int>::iterator it = randMStack.begin(); it != randMStack.end(); ++it) {
            std::cout << " " << *it << "=" << randStack.top();
            if (*it != randStack.top()) {
                std::cerr << "Error: MutantStack and Stack are not the same" << std::endl;
            }
            randStack.pop();
        }
        std::cout << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    testMutantStack();
    return 0;
}
