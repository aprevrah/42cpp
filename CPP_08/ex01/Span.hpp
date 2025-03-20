#pragma once
#include <algorithm>
#include <iterator>
#include <exception>
#include <set>

class Span {
    private:
        unsigned int N_;
        std::multiset<int> span_;
    public:
        Span();
        Span(unsigned int N);
        Span(Span &other);
        Span &operator=(Span const &rhs);
        ~Span();

        std::multiset<int> getMultiset();
        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

std::ostream &operator<<(std::ostream &out, Span &span);