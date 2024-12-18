#include "Animal.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

Animal::Animal(const std::string& type) : type(type) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

Animal::Animal() : type("Animal") {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;

}

Animal& Animal::operator=(const Animal& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

std::string Animal::getType() const {
    return type;
}