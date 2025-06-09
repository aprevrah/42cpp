// #include "PmergeMe.hpp"
#include <iostream>
#include <ostream>
#include <vector>

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;
    std::vector<int> data = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    std::vector<int> sorted(data);

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
        for (size_t i=0; i * chunk_size < pend.size(); i++) {
            int last_of_pend_elem = pend[(i+1)*chunk_size-1];
            // search over sorted from corresponding a element to the left.
            // for every b_i, we definitely need to compare to the
            // first two elements b1, a1, and then one more according
            // to i and one other more because we inserted the previous
            // b_i's (-1 because of 0-index)
            int j;
            for (j = 2+i*2-1; j>=0; j--) {
                int last = sorted[(j+1)*chunk_size-1];
                if (last < last_of_pend_elem) {
                    sorted.insert(sorted.begin()+(j+1)*chunk_size, pend.begin()+i*chunk_size, pend.begin()+(i+1)*chunk_size);
                    break;
                }
            }
            if(j==-1)
                sorted.insert(sorted.begin(), pend.begin()+i*chunk_size, pend.begin()+(i+1)*chunk_size);
        }
        chunk_size /= 2;
    }

    for(size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << ", ";
    std::cout << std::endl;
    return 0;
}

