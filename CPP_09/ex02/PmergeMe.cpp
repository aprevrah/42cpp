#include "PmergeMe.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

// Helper struct for pairs
struct FJPair {
    int high;
    int low;
    FJPair(int a, int b) {
        if (a > b) { high = a; low = b; }
        else { high = b; low = a; }
    }
};

// Binary insert helper
void binaryInsert(std::vector<int>& sorted, int value) {
    auto it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

// The main Ford-Johnson sort function
std::vector<int> fordJohnsonSort(const std::vector<int>& input) {
    // Base case: 0 or 1 element
    if (input.size() <= 1) return input;
    
    // 1. Pair up elements and collect straggler if odd
    std::vector<FJPair> pairs;
    int straggler = 0;
    bool hasStraggler = false;
    size_t i = 0;
    for (; i + 1 < input.size(); i += 2) {
        pairs.push_back(FJPair(input[i], input[i + 1]));
    }
    if (i < input.size()) {
        hasStraggler = true;
        straggler = input[i];
    }

    // 2. Recursively sort the "high" values of each pair
    std::vector<int> highs;
    for (size_t j = 0; j < pairs.size(); ++j) highs.push_back(pairs[j].high);
    std::vector<int> sortedHighs = fordJohnsonSort(highs);

    // 3. Insert the first "low" value at the beginning
    std::vector<int> result;
    result.push_back(pairs[0].low);

    // 4. Insert remaining "low" values using binary insertion
    for (size_t j = 1; j < pairs.size(); ++j) {
        binaryInsert(result, pairs[j].low);
    }

    // 5. Merge sorted highs and lows
    std::vector<int> merged;
    size_t h = 0, l = 0;
    while (h < sortedHighs.size() && l < result.size()) {
        if (sortedHighs[h] < result[l]) {
            merged.push_back(sortedHighs[h++]);
        } else {
            merged.push_back(result[l++]);
        }
    }
    while (h < sortedHighs.size()) merged.push_back(sortedHighs[h++]);
    while (l < result.size()) merged.push_back(result[l++]);

    // 6. Insert straggler if present
    if (hasStraggler) {
        binaryInsert(merged, straggler);
    }
    return merged;
}

// Example usage
void runFordJohnsonDemo() {
    std::vector<int> data = {10, 1, 4, 3, 5, 6, 7, 8, 9, 2};
    std::vector<int> sorted = fordJohnsonSort(data);
    std::cout << "Sorted: ";
    for (size_t i = 0; i < sorted.size(); ++i) {
        std::cout << sorted[i] << (i + 1 < sorted.size() ? ", " : "\n");
    }
}

