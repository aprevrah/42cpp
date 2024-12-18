#include "Animal.hpp"
#include <string>
#include <iostream>


Animal::Animal(const std::string& type) : type(type) {
    std::cout << "Animal" << " : Constructor called" << std::endl;
}

Animal::Animal() : type("Animal") {
    std::cout << "Animal" << " : Default-Constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal" << " : Copy-Constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal" << " : Deconstructor called" << std::endl;

}

Animal& Animal::operator=(const Animal& rhs) {
    std::cout << "Animal" << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "The Sound Of Silence" << std::endl;
}

std::string Animal::getType() const {
    return type;
}