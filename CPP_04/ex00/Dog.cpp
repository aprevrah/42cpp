#include "Dog.hpp"
#include <string>
#include <iostream>


Dog::Dog(const std::string& type) : type(type) {
    std::cout << "Dog" << " : Constructor called" << std::endl;
}

Dog::Dog() : type("Dog") {
    std::cout << "Dog" << " : Default-Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : type(other.type) {
    std::cout << "Dog" << " : Copy-Constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog" << " : Deconstructor called" << std::endl;

}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog" << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Wooof" << std::endl;
}