#include "Cat.hpp"
#include <string>
#include <iostream>


Cat::Cat(const std::string& type) : type(type) {
    std::cout << "Cat" << " : Constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
    std::cout  << "Cat" << " : Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout  << "Cat" << " : Copy Constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout  << "Cat" << " : Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    if (this != &rhs) {
        type = rhs.type;
        *brain = *rhs.brain;
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() {
    return brain;
}