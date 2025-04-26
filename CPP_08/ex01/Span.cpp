#include "Span.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>
#include <algorithm>

Span::Span() : N_(2) {}

Span::Span(unsigned int N) : N_(N) {}

Span::Span(Span const &other) : N_(other.N_) {
    for (std::multiset<int>::const_iterator it = other.span_.begin(); it != other.span_.end(); ++it) {
        this->span_.insert(*it);
    }
}

Span &Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        this->N_ = rhs.N_;
        this->span_.clear();
        for (std::multiset<int>::const_iterator it = rhs.span_.begin(); it != rhs.span_.end(); ++it) {
            this->span_.insert(*it);
        }
    }
    return *this;
}

Span::~Span() {}

std::multiset<int> const &Span::getMultiset() const {
    return this->span_;
}

void Span::addNumber(int number) {
    if (this->span_.size() < this->N_)
        this->span_.insert(number);
    else
        throw std::runtime_error("Span is full");
}

void Span::addNumbers(std::set<int>::const_iterator begin, std::set<int>::const_iterator end) {
    std::size_t count = static_cast<std::size_t>(std::distance(begin, end));
    if (this->span_.size() + count > this->N_) {
        throw std::runtime_error("Span is full");
    }
    this->span_.insert(begin, end);
}

unsigned int Span::shortestSpan() const {
    if (this->span_.size() < 2)
        throw std::runtime_error("Too little elements");

    std::multiset<int>::const_iterator it = this->span_.begin();
    std::multiset<int>::const_iterator nextIt = it;
    ++nextIt;
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    while (nextIt != this->span_.end()) {
        minSpan = std::min(minSpan, static_cast<unsigned int>(std::max(*nextIt, *it) - std::min(*nextIt, *it)));
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

std::ostream &operator<<(std::ostream &os, Span const &span) {
    os << "{ ";
    for (std::multiset<int>::const_iterator it = span.getMultiset().begin(); 
         it != span.getMultiset().end(); ++it) {
        os << *it << " ";
    }
    os << "}";
    return os;
}