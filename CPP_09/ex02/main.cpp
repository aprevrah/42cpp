// #include "PmergeMe.hpp"
#include <iostream>
#include <ostream>
#include <cmath>
#include <vector>

unsigned long comparisons = 0;

/**
 * @brief binary search a sorted chunked sequence for the chunk whose last value is smaller than item 
 * 
 * @param a the sequence
 * @param item 
 * @param low low chunk index
 * @param high high chunk index
 * @param chunk_size 
 * @return int the chunk index 
 */
int binarySearch(const std::vector<int> &a, const int item, int low, int high, const size_t chunk_size)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // comparisons++; // count comparison
        // if (item == a[mid * chunk_size + chunk_size - 1])
        //     return mid + 1;
        comparisons++; // count comparison
        if (item >= a[mid * chunk_size + chunk_size - 1])
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return low;
}

size_t jacobsthal(const size_t j_minus_1, const size_t j_minus_2) {
    return j_minus_1 + 2 * j_minus_2;
}

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
    (void) argc;
    (void) argv;
//    std::vector<int> data = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    std::vector<int> data = {11, 2, 17, 0, 67, 16, 8, 5, 6, 15, 99, 10, 3, 304957, 21, 1, 18, 124, 9, 14, 45, 19, 12, 5, 4, 20, 13, 7};
    std::vector<int> sorted(data);
    std::cout << "Comparison target for " << data.size() << " elements to be sorted: " << F(data.size()) << std::endl;


    // Step 1 of the FJ Algorithm:
    // Data are chunked up in sizes that double from iteration to iteration.
    // We glide along the array with a chunk a and a chunk b
    // We compare the last elements of chunks a and b. If last(a) is bigger than
    // last(b), we swap the chunks. For that we need a buffer. 
    size_t chunk_size = 1;
    while (chunk_size < data.size()/2) {
        std::vector<int> buffer(chunk_size); // in case we need to swap 
        for (size_t offs=0; offs + 2 * chunk_size <= sorted.size(); offs+= chunk_size * 2) {
            int last_of_chunk_a = sorted[offs + chunk_size - 1];
            int last_of_chunk_b = sorted[offs + 2 * chunk_size -1];
            comparisons++; // count comparison
            if (last_of_chunk_a > last_of_chunk_b) {
                // swap chunks
                // buffer chunk a
                std::copy(sorted.begin() + offs, sorted.begin() + offs + chunk_size, buffer.begin());
                // overwrite chunk a with chunk b
                std::copy(sorted.begin() + offs + chunk_size, sorted.begin() + offs + 2 * chunk_size, sorted.begin() + offs);
                // overwrite chunk b with buffer
                std::copy(buffer.begin(), buffer.end(), sorted.begin() + offs + chunk_size);
            }
        }
        chunk_size *= 2;
    }

    // Step 2 of the FJ Algorithm

    // Precompute Jacobsthal indices up to total_chunks,
    // already in the correct spelled-out order
    // later we just need to break if we overflow over pend size
    std::vector<size_t> jacob_indices;
    int jt_prev = 0, jt_curr = 1;
    while (jt_curr < (int)data.size()) {
        for (int i = jt_curr; i > jt_prev; --i)
            jacob_indices.push_back((size_t)i-1);
        int jt_new = jt_curr + 2 * jt_prev;
        jt_prev = jt_curr;
        jt_curr = jt_new;
    }

    chunk_size /= 2;    //above last chunk size didnt fit anymore


    while (chunk_size >= 1) {
        //std::vector<int> pend(chunk_size * ((int)((float)(sorted.size() / chunk_size)/ 2. + 0.5) -1)); // in case we need to swap 
        std::vector<int> pend;
        // FJ Step 2- make a sequence b1, a2, a3, a4, a.. in sorted,
        // the b2, b3, ... go to the pend 
        // we begin at 2*chunk_size because b1 and a1 stay where they are
        for (size_t offs=2*chunk_size; offs + chunk_size <= sorted.size(); offs += chunk_size) {
            pend.insert(pend.end(), sorted.begin() + offs, sorted.begin() + offs + chunk_size);
            sorted.erase(sorted.begin() + offs, sorted.begin() + offs + chunk_size);
        }
    
        // FJ Step 3 - binary insert from the pend into sorted
        // --- Jacobsthal-based insertion ---
        size_t total_chunks = pend.size() / chunk_size;
        // std::vector<bool> inserted(total_chunks, false);
 
        // Insert chunks at Jacobsthal indices
        for (size_t idx = 0; idx < jacob_indices.size(); ++idx) {
            size_t i = jacob_indices[idx];
            if (i >= total_chunks)
                continue;
            int last_of_pend_elem = pend[(i + 1) * chunk_size - 1];
            int search_high = std::min(static_cast<int>(2 + i * 2 - 1), static_cast<int>(sorted.size() / chunk_size) - 1);
            int index = binarySearch(sorted, last_of_pend_elem, 0, search_high, chunk_size);
            sorted.insert(sorted.begin() + index * chunk_size, pend.begin() + i * chunk_size, pend.begin() + (i + 1) * chunk_size);
       //     inserted[i] = true;
       }

        // // Insert any remaining chunks in order
        // for (size_t i = 0; i < total_chunks; ++i) {
        //     if (inserted[i])
        //         continue;
        //     int last_of_pend_elem = pend[(i + 1) * chunk_size - 1];
        //     int search_high = std::min(static_cast<int>(2 + i * 2 - 1), static_cast<int>(sorted.size() / chunk_size) - 1);
        //     int index = binarySearch(sorted, last_of_pend_elem, 0, search_high, chunk_size);
        //     sorted.insert(sorted.begin() + index * chunk_size, pend.begin() + i * chunk_size, pend.begin() + (i + 1) * chunk_size);
        //     inserted[i] = true;
        // }
        // 
        chunk_size /= 2;
    }

    for(size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << ", ";
    std::cout << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    return 0;
}

