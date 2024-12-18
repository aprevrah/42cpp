#include "Brain.hpp"
#include <iostream>
#include <typeinfo>


Brain::Brain() {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Unga Bunga";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea(unsigned int index) const {
    if (index < NB_OF_IDEAS)
        return ideas[index];
    else
        return "Zoned out...";
        
}

void    Brain::setIdea(unsigned int index, std::string idea) {
    if (index < NB_OF_IDEAS)
        ideas[index] = idea;
}