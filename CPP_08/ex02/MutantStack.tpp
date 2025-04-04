#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {};

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &rhs) {
    if (*this != rhs) {
        this->c = rhs.c;
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

// template <typename T>
// typedef typename std::stack<T>::container_type::iterator iterator;

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}

// template <typename T>
// typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
//     return std::stack<T>::c.rbegin();
// }

// template <typename T>
// typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
//     return std::stack<T>::c.rend();
// }

   
// template <typename T>
//friend std::ostream &operator<<(std::ostream &os, MutantStack const &span);
