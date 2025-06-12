#include <vector>
#include <deque>
#include <algorithm>
#include <cstddef>
#include <cmath>

extern unsigned long comparisons; // Make sure this is defined in one .cpp file

template<typename T>
class PmergeMe {
public:
    PmergeMe(const T& data) : data_(data) {}
    T FJsort() const;

private:
    T data_;
    int binarySearch(const T &a, const int item, int low, int high, const size_t chunk_size) const;
};

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
template<typename T>
int PmergeMe<T>::binarySearch(const T &a, const int item, int low, int high, const size_t chunk_size) const
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

template<typename T>
T PmergeMe<T>::FJsort() const
{
    T sorted(data_);
    // Step 1 of the FJ Algorithm:
    // Data are chunked up in sizes that double from iteration to iteration.
    // We glide along the array with a chunk a and a chunk b
    // We compare the last elements of chunks a and b. If last(a) is bigger than
    // last(b), we swap the chunks. For that we need a buffer. 
    size_t chunk_size = 1;
    while (sorted.size() < 4 ? chunk_size <= sorted.size()/2 : chunk_size < sorted.size()/2) {
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

    // Precompute Jacobsthal indices up to data size,
    // already in the correct spelled-out order
    // later we just need to break if we overflow over pend size
    std::vector<size_t> jacob_indices;
    std::vector<size_t> jacob_search_n;
    int jt_prev = 1, jt_curr = 1;
    bool is_jt_below_data_size = true;
    size_t search_i = 1;
    while (is_jt_below_data_size) {
        for (int i = jt_curr; i > jt_prev; --i) {  // for the FJ algorithm we iterate to lower-indexed chunks
            jacob_indices.push_back((size_t)i-2);
            jacob_search_n.push_back(std::pow(2, search_i)-1);
        }
        if (jt_curr >= (int)data_.size()) 
            is_jt_below_data_size = false;
        int jt_new = jt_curr + 2 * jt_prev;
        jt_prev = jt_curr;
        jt_curr = jt_new;
        ++search_i;
    }

    chunk_size /= 2;    //above last chunk size didnt fit anymore

    while (chunk_size >= 1) {
        //std::vector<int> pend(chunk_size * ((int)((float)(sorted.size() / chunk_size)/ 2. + 0.5) -1)); // in case we need to swap 
        T pend;
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
 
        // Insert chunks at Jacobsthal indices
        for (size_t idx = 0; idx < jacob_indices.size(); ++idx) {
            size_t i = jacob_indices[idx];
            if (i >= total_chunks)
                continue;
            int last_of_pend_elem = pend[(i + 1) * chunk_size - 1];
          //  int search_high = std::min(static_cast<int>(2 + i * 2 -1), static_cast<int>(sorted.size() / chunk_size) - 1);
          int search_high = std::min(static_cast<int>(jacob_search_n[idx] - 1), static_cast<int>(sorted.size() / chunk_size) - 1);
            int index = this->binarySearch(sorted, last_of_pend_elem, 0, search_high, chunk_size);
            sorted.insert(sorted.begin() + index * chunk_size, pend.begin() + i * chunk_size, pend.begin() + (i + 1) * chunk_size);
        }
        chunk_size /= 2;
    }
    return sorted;
}