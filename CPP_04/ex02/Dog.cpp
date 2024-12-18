#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>


Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "Dog" << " : Default-Constructor called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type), brain(new Brain()) {
    std::cout << "Dog" << " : Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog" << " : Copy-Constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog" << " : Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << "Dog" << " : Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        type = rhs.type;
        *brain = *rhs.brain;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() {
    return brain;
}