#pragma once
#include <string>
#define NB_OF_IDEAS 100

class Brain {
    protected:
        std::string ideas[NB_OF_IDEAS];
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& rhs);
        std::string getIdea(unsigned int index) const;
        void    setIdea(unsigned int index, std::string idea);
};