#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " was constructed." << std::endl;
    hitPoints = 10;
    energyPoints = 10; 
    attackDamage = 0;
}

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap " << name << " was destructed." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " was destructed." << std::endl;
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

void ScavTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " is already dead!" << std::endl;
        return;
    }
    if (amount > hitPoints) {
        amount = hitPoints;
    }
    hitPoints -= amount;
    std::cout << "ScavTrap " << name << " took " << amount << " point" 
              << (amount != 1 ? "s" : "") << " of damage! Remaining hit points: " << hitPoints << "." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " is dead and cannot be repaired!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " tries to repair itself but lacks the energy to do so!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ScavTrap " << name << " repaired itself, restoring " << amount << " hit point" 
              << (amount != 1 ? "s" : "") << "! New hit points: " << hitPoints << "." << std::endl;
}