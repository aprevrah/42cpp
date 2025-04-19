#pragma once

template <typename T, typename U>
void iter(T* arr, size_t len, void (*func)(U&)) {
    for (size_t i = 0; i < len; ++i) {
        func(arr[i]);
    }
}