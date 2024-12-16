#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <typeinfo>

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " was constructed." << std::endl;
    hitPoints = 100;
    energyPoints = 50; 
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    *this = other;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " was destructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
    if (this != &rhs) {
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->energyPoints = rhs.energyPoints;
    this->attackDamage = rhs.attackDamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " tries to attack " << target << ", but fails miserably due to lack of energy points!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::stats() {
    std::cout << "+==========================+" << std::endl;
    std::cout << "Class:        " << typeid(*this).name() << std::endl;
    std::cout << "name:         " << name << std::endl;
    std::cout << "hitPoints:    " << hitPoints << std::endl;
    std::cout << "energyPoints: " << energyPoints << std::endl;
    std::cout << "attackDamage: " << attackDamage << std::endl;
    std::cout << "+==========================+" << std::endl;
}