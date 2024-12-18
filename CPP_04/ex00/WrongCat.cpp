#include "WrongCat.hpp"
#include <string>
#include <iostream>


WrongCat::WrongCat(const std::string& type) : type(type) {
    std::cout << "WrongCat" << " : Constructor called" << std::endl;
}

WrongCat::WrongCat() : type("WrongCat") {
    std::cout << "WrongCat" << " : Default-Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : type(other.type) {
    std::cout << "WrongCat" << " : Copy-Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat" << " : Deconstructor called" << std::endl;

}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    std::cout << "WrongCat" << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow" << std::endl;
}