#pragma once
#include <ostream>
#include <set>

class Span {
    private:
        unsigned int N_;
        std::multiset<int> span_;
    public:
        Span();
        Span(unsigned int N);
        Span(Span const &other);
        Span &operator=(Span const &rhs);
        ~Span();

        const std::multiset<int>& getMultiset() const;
        void addNumber(int number);
        void addNumbers(std::set<int>::const_iterator begin, std::set<int>::const_iterator end);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

std::ostream &operator<<(std::ostream &os, Span const &span);