#include "Dog.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

Dog::Dog(const std::string& type) : type(type) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

Dog::Dog() : type("Dog") {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : type(other.type) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;

}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Wooof" << std::endl;
}