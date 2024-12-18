#include "WrongAnimal.hpp"
#include <string>
#include <iostream>


WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
    std::cout << "WrongAnimal" << " : Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal" << " : Default-Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal" << " : Copy-Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal" << " : Deconstructor called" << std::endl;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "WrongAnimal" << " : Copy assignment operator called" << std::endl;
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