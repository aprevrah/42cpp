#include "Cat.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

Cat::Cat(const std::string& type) : type(type) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

Cat::Cat() : type("Cat") {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : type(other.type) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;

}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}