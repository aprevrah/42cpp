#include "Span.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

Span::Span() : N_(2) {}

Span::Span(unsigned int N) : N_(N) {}

Span::Span(Span &other) : N_(other.N_), span_(other.span_) {}

Span &Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        this->N_ = rhs.N_;
        this->span_ = rhs.span_;
    }
    return *this; 
}

Span::~Span() {}

std::multiset<int> Span::getMultiset() {
    return this->span_;
}

void Span::addNumber(int number) {
    if (this->span_.size() < this->N_)
        this->span_.insert(number);
    else
        throw std::runtime_error("Span is full");
}

unsigned int Span::shortestSpan() const {
    if (this->span_.size() < 2)
        throw std::runtime_error("Too little elements");

    std::set<int>::const_iterator it = this->span_.begin();
    std::set<int>::const_iterator nextIt = it;
    ++nextIt;

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();

    while (nextIt != this->span_.end()) {
        unsigned int diff = static_cast<unsigned int>(*nextIt - *it);
        if (diff < minSpan)
            minSpan = diff;
        ++it;
        ++nextIt;
    }

    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (this->span_.size() < 2)
        throw std::runtime_error("Too little elements");

    return static_cast<unsigned int>(*this->span_.rbegin() - *this->span_.begin());
}

std::ostream &operator<<(std::ostream &out, Span &span) {
    std::multiset<int> spanSet = span.getMultiset();
    out << "Span Elements: "; 
    std::copy(spanSet.begin(), spanSet.end(), std::ostream_iterator<int>(out, " "));
    return out;
}