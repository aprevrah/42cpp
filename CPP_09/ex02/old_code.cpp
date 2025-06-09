// class MyPair {
//     public:
//         bool isLeaf; 
//         int high;
//         int low;
//         MyPair* highPair;
//         MyPair* lowPair;
//         MyPair(int x, int y);
//         MyPair(MyPair* x, MyPair* y);
//         bool operator>(const MyPair& other) const;
//         bool operator<(const MyPair& other) const;

// };

// MyPair::MyPair(int x, int y) {
//     comparisons++;
//     if (x > y) {
//         high = x;
//         low = y;
//     }
//     else
//     {
//         high = y;
//         low = x;
//     }
//     isLeaf = true;
// }

// MyPair::MyPair(MyPair* x, MyPair* y) {
//     comparisons++;
//     if (x > y) {
//         highPair = x;
//         lowPair = y;
//     }
//     else
//     {
//         highPair = y;
//         lowPair = x;
//     }
//     isLeaf = false;
// }

// bool MyPair::operator>(const MyPair& other) const {
//     if (isLeaf && other.isLeaf) {
//         return high > other.high;
//     } else if (!isLeaf && !other.isLeaf) {
//         return highPair->high > other.highPair->high;
//     }
//     // Define leaf < internal node
//     return isLeaf < other.isLeaf;
// }

// bool MyPair::operator<(const MyPair& other) const {
//     if (isLeaf && other.isLeaf) {
//         return high < other.high;
//     } else if (!isLeaf && !other.isLeaf) {
//         return highPair->high < other.highPair->high;
//     }
//     // Define leaf < internal node
//     return isLeaf > other.isLeaf;
// }

// std::ostream& operator<<(std::ostream& os, const MyPair& pair) {
//     if (pair.isLeaf) {
//         os << "[" << pair.low << ", " << pair.high << "]";
//     } else {
//         os << "{" << *pair.lowPair << ", " << *pair.highPair << "}";
//     }
//     return os;
// }

// void bin_search(const std::vector<int>& data, int value) {
//     int left = 0;
//     int right = data.size() - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         std::cout << left << " " << mid << " " << right << std::endl;
//         if (data[mid] == value) {
//             std::cout << "Found value " << value << " at index " << mid << std::endl;
//             return;
//         }
//         if (data[mid] < value) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//     std::cout << "Value " << value << " not found." << std::endl;
// }

// void bin_insert(std::vector<int>& data, int value) {
//     int left = 0;
//     int right = data.size();
//     while (left < right) {
//         int mid = left + (right - left) / 2;
//         std::cout << left << " " << mid << " " << right << std::endl;
//         if (data[mid] < value) {
//             left = mid + 1;
//         } else {
//             right = mid;
//         }
//     }
//     data.insert(data.begin() + left, value);
//     std::cout << "Value inserted at index " << left << std::endl;
// }

// std::vector<MyPair> makePairs(const std::vector<int>& data, bool& hasStraggler, int& straggler) {
//     std::vector<MyPair> pairs;
//     size_t i = 0;
//     for (; i + 1 < data.size(); i += 2) {
//         MyPair pair(data[i], data[i + 1]);
//         pairs.push_back(pair);
//     }
//     // Handle the straggler (last element if odd size)
//     if (i < data.size()) {
//         hasStraggler = true;
//         straggler = data[i];
//     } else {
//         hasStraggler = false;
//     }
//     return pairs;
// }

// std::vector<MyPair> makePairsOfPairs(const std::vector<MyPair>& data, bool& hasStraggler, const MyPair*& straggler) {
//     std::vector<MyPair> pairs;
//     size_t i = 0;
//     for (; i + 1 < data.size(); i += 2) {
//         MyPair pair(const_cast<MyPair*>(&data[i]), const_cast<MyPair*>(&data[i + 1]));
//         pairs.push_back(pair);
//     }
//     // Handle the straggler (last element if odd size)
//     if (i < data.size()) {
//         hasStraggler = true;
//         straggler = &data[i];
//     } else {
//         hasStraggler = false;
//         straggler = nullptr;
//     }
//     return pairs;
// }

// std::vector<MyPair> FJ(const std::vector<MyPair>& data) {
//     // Base case: if 1 or 0 pairs, return as is
//     if (data.size() <= 1) {
//         return data;
//     }
//     // Pair up pairs recursively
//     bool hasStraggler;
//     const MyPair* straggler;
//     std::vector<MyPair> pairs = makePairsOfPairs(data, hasStraggler, straggler);
//     // Recursive call
//     std::vector<MyPair> sorted = FJ(pairs);
//     // Insert straggler if present
//     if (hasStraggler && straggler) {
//         // Insert straggler into sorted at correct position (by high value)
//         size_t insertPos = 0;
//         while (insertPos < sorted.size() && *straggler > sorted[insertPos]) {
//             ++insertPos;
//         }
//         sorted.insert(sorted.begin() + insertPos, *straggler);
//     }
//     return sorted;
// } 

/*
merge_sort() {
    std::vector<MyPair> pairs;
    size_t i = 0;
    for (; i + 1 < data.size(); i += 2) {
        MyPair pair(data[i], data[i + 1]);
        pairs.push_back(pair);
    }
}*/

// unsigned int comparisons = 0;

/**
 * @brief Base class for elements that can be sorted
 */
class Element {
    private:
        std::vector<int> higher;
    	std::vector<int> lower;
    public:
        Element(std::vector<int>& a, std::vector<int>& b) : higher(a), lower(b) {
            if (a < b) {
                lower = a;
                higher = b;
            }
        }
        Element(int a, int b)  {
            lower = std::vector<int>(1);
            higher = std::vector<int>(1);
            if (a < b) {
                lower[0] = a;
                higher[0] = b;
            } else {
                lower[0] = b;
                higher[0] = a;
            }
        }
        bool operator<(const Element& other) const;
};

bool Element::operator<(const Element& other) const {
    // We can safely assume that the Element vectors are internally
    // sorted in a such a way that the last element of each vector
    // is its highest number, so let's just compare the last elements. 
    return this->higher.back() < other.higher.back();
}

// // Helper to pair up elements of any type T into Element<T>
// template<typename T>
// void makeElementPairs(const std::vector<T>& input, std::vector<Element<T>>& output) {
//     if (input.size() < 2) return;
//     for (size_t i = 0; i + 1 < input.size(); i += 2) {
//         output.push_back(Element<T>(input[i], input[i + 1]));
//     }
// }

// // Recursive function to pair up elements until only one or zero remain
// // Each level in result is a vector of Element<T> for that level
// // Example: result[0] = pairs of input, result[1] = pairs of pairs, etc.
// template<typename T>
// void recursiveElementPairing(const std::vector<T>& input, std::vector<Element<T>>& result) {
//     std::vector<Element<T>> pairs;
//     makeElementPairs(input, pairs);
//     if (!pairs.empty()) {
//         // Recurse on the new pairs
//         recursiveElementPairing(pairs, result);
//     }
// }


 // std::vector<Element<int>> pairingLevels;
    // recursiveElementPairing(arr, pairingLevels);

    // std::vector<MyPair> pairs = makePairs(data, hasStraggler, straggler);

    // for(size_t i = 0; i < pairs.size(); i++)
    //     std::cout << pairs[i] << ", ";
    // std::cout << std::endl;
    // std::vector<MyPair> sorted = FJ(pairs);

    for(size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << ", ";

    /*
    bin_search(data, 344);
    
    bin_insert(data, 344);
    //data.insert(data.begin() + 12, 344);
    for(size_t i = 0; i < data.size(); i++)
        std::cout << data[i] << ", ";
    bin_search(data, 344);
    */