#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>() {
    for (typename std::stack<T>::container_type::const_iterator it = other.c.begin(); it != other.c.end(); ++it) {
        this->c.push_back(*it);
    }
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &rhs) {
    if (this != &rhs) {
        this->c.clear();
        for (typename std::stack<T>::container_type::const_iterator it = rhs.c.begin(); it != rhs.c.end(); ++it) {
            this->c.push_back(*it);
        }
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return std::stack<T>::c.rend();
}
