#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " was constructed." << std::endl;
    hitPoints = 100;
    energyPoints = 100; 
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) {
    *this = other;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " was destructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
    if (this != &rhs) {
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Hey High Five Guys!" << std::endl;
}

/* void FragTrap::attack(const std::string& target) {
    if (hitPoints == 0) {
        std::cout << "FragTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "FragTrap " << name << " tries to attack " << target << ", but fails miserably due to lack of energy points!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}*/