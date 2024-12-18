#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>
#include <typeinfo>

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << typeid(*this).name() << " : Default-Constructor called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type), brain(new Brain()) {
    std::cout << typeid(*this).name() << " : Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << typeid(*this).name() << " : Copy-Constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << typeid(*this).name() << " : Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout << typeid(*this).name() << " : Copy assignment operator called" << std::endl;
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