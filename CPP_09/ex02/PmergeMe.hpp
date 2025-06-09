#include <vector>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const std::vector<int>& data);
    void add(int value);
    void sort();
    std::vector<int> getSorted() const;

private:
    std::vector<int> _data;
    void fordJohnsonSort(std::vector<int>& data);
    void mergeInsertion(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result);
};

void runFordJohnsonDemo();