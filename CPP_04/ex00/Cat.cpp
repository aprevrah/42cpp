#include "Cat.hpp"
#include <string>
#include <iostream>


Cat::Cat(const std::string& type) : type(type) {
    std::cout << "Cat" << " : Constructor called" << std::endl;
}

Cat::Cat() : type("Cat") {
    std::cout << "Cat" << " : Default-Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : type(other.type) {
    std::cout << "Cat" << " : Copy-Constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat" << " : Deconstructor called" << std::endl;

}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout << "Cat" << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}