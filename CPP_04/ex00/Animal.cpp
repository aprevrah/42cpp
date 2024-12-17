#include "Animal.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

Animal::Animal(const std::string& type) : type(type) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

Animal::Animal() {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;

}

Animal& Animal::operator=(const Animal& rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "The Sound Of Silence" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}