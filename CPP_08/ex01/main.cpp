#include "Span.hpp"
#include <stdexcept>
#include <set>
#include <iostream>
#include <cstdlib>
#include <ctime>

void testSpan() {
    std::cout << "===== Basic Tests =====" << std::endl;

    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Should be 2 (9 and 11)
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;  // Should be 14 (3 and 17)
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n===== Limits Tests =====" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(2147483647);
        sp.addNumber(-2147483648);

        std::cout << sp << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Should be 2 (9 and 11)
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;  // Should be 14 (3 and 17)
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Edge Case: Empty Span =====" << std::endl;
    try {
        Span emptySpan(10);
        std::cout << "Shortest Span: " << emptySpan.shortestSpan() << std::endl; // Should throw
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Edge Case: One Element =====" << std::endl;
    try {
        Span oneElemSpan(10);
        oneElemSpan.addNumber(42);
        std::cout << "Shortest Span: " << oneElemSpan.shortestSpan() << std::endl; // Should throw
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Edge Case: Full Span =====" << std::endl;
    try {
        Span fullSpan(2);
        fullSpan.addNumber(1);
        fullSpan.addNumber(100);
        fullSpan.addNumber(200); // Should throw
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Large Random Test =====" << std::endl;
    try {
        Span bigSpan(10000);
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i) {
            bigSpan.addNumber(std::rand() % 1000000000);
        }
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== addNumbers Tests =====" << std::endl;
    std::set<int> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers.insert(i);
    }

    try {
        Span spAddRange(10);
        spAddRange.addNumbers(numbers.begin(), numbers.end());
        std::cout << spAddRange << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Span spAddFail(9);
        spAddFail.addNumbers(numbers.begin(), numbers.end());
        std::cout << spAddFail << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Copy and Assignment Test =====" << std::endl;
    try {
        Span sp1(5);
        sp1.addNumber(10);
        sp1.addNumber(20);
        sp1.addNumber(30);

        Span sp2 = sp1; // Copy constructor test
        Span sp3(3);
        sp3 = sp1; // Assignment operator test

        sp1.addNumber(1); //These are deep copies
        sp2.addNumber(2);
        sp3.addNumber(3);

        std::cout << "Original: " << sp1 << std::endl;
        std::cout << "Copy Constructor: " << sp2 << std::endl;
        std::cout << "Assignment Operator: " << sp3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    testSpan();
    return 0;
}
