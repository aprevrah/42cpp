#include <iostream>
#include <ostream>
#include <cmath>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"
#include <ctime>

unsigned long comparisons = 0;


/**
 * @brief Upper bound of numbers of comparison allowed for
 * a FJ sort for a sequence of length n
 * 
 * @param n 
 * @return int 
 */
int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main(int argc, char** argv) {
    int show_comparisons = 0;
    int arg_start = 1;
    if (argc > 1 && std::string(argv[1]) == "-c") {
        show_comparisons = 1;
        arg_start = 2;
    }
    if (argc < arg_start + 1) {
        std::cerr << "Usage: " << argv[0] << " [-c] <int1> <int2> ..." << std::endl;
        return 1;
    }
    std::vector<int> data_vec;
    std::deque<int> data_deq;
    for (int i = arg_start; i < argc; ++i) {
        int val = 0;
        char *endptr = 0;
        val = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0') {
            std::cerr << "Invalid integer: " << argv[i] << std::endl;
            return 1;
        }
        if (val <= 0) {
            std::cerr << "Only positive integers are allowed: " << argv[i] << std::endl;
            return 1;
        }
        data_vec.push_back(val);
        data_deq.push_back(val);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < data_vec.size(); ++i)
        std::cout << data_vec[i] << (i + 1 < data_vec.size() ? " " : "\n");

    std::clock_t start_vec = std::clock();
    PmergeMe<std::vector<int> > pm_vec(data_vec);
    std::vector<int> sorted = pm_vec.FJsort();
    std::clock_t end_vec = std::clock();
    double elapsed_vec = 1e6 * (end_vec - start_vec) / (double)CLOCKS_PER_SEC;

    std::cout << "After: ";
    for(size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << (i + 1 < sorted.size() ? " " : "\n");
    std::cout << "Time to process a range of " << data_vec.size() << " elements with std::vector<int> : " << elapsed_vec << " us" << std::endl;
    // if (show_comparisons) {
    //     std::cout << "Comparisons used: " << comparisons << std::endl;
    //     std::cout << "Comparison target for " << data_vec.size() << " elements: " << F((int)data_vec.size()) << std::endl;
    // }

    comparisons = 0;
    std::clock_t start_deq = std::clock();
    PmergeMe<std::deque<int> > pm_deq(data_deq);
    std::deque<int> sorted2 = pm_deq.FJsort();
    std::clock_t end_deq = std::clock();
    double elapsed_deq = 1e6 * (end_deq - start_deq) / (double)CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << data_deq.size() << " elements with std::deque<int> : " << elapsed_deq << " us" << std::endl;
    if (show_comparisons) {
        std::cout << "Comparisons used: " << comparisons << std::endl;
        std::cout << "Comparison target for " << data_deq.size() << " elements: " << F((int)data_deq.size()) << std::endl;
    }
    return 0;
}

