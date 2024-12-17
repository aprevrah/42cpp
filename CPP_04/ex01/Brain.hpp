#pragma once
#include <string>
class Brain {
    protected:
        std::string type;
    public:
        Brain(const std::string& type);
        Brain();
        Brain(const Brain& other);
        virtual ~Brain();
        Brain& operator=(const Brain& rhs);
};