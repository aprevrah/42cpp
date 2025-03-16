#pragma once
#include <algorithm>
#include <iterator>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int i) {
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it == container.end()) {
        throw std::runtime_error("Element not found");
    }
    return it;
}