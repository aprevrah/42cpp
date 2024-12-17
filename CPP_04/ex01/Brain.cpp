#include "Brain.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

Brain::Brain(const std::string& type) : type(type) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

Brain::Brain() : type("Brain") {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

Brain::Brain(const Brain& other) : type(other.type) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;

}

Brain& Brain::operator=(const Brain& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        //this->type = rhs.type;
    }
    return *this;
}