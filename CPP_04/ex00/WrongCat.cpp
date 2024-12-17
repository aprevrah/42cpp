#include "WrongCat.hpp"
#include <string>
#include <iostream>
#include <typeinfo>

WrongCat::WrongCat(const std::string& type) : type(type) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

WrongCat::WrongCat() : type("WrongCat") {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : type(other.type) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << typeid(*this).name() << " : Deconstructor called" << std::endl;

}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow" << std::endl;
}