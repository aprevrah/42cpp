#pragma once
#include <string>
class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& rhs);
};