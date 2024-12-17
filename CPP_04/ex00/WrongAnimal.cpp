#include "WrongAnimal.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "The Sound Of Silence" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}