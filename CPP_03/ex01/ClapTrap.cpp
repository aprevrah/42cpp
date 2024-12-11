#include "ClapTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " was constructed." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " was destructed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " tries to attack " << target << ", but fails miserably due to lack of energy points!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    if (amount > hitPoints) {
        amount = hitPoints;
    }
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " took " << amount << " point" 
              << (amount != 1 ? "s" : "") << " of damage! Remaining hit points: " << hitPoints << "." << std::endl;
}

// Repair Function
void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is dead and cannot be repaired!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " tries to repair itself but lacks the energy to do so!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repaired itself, restoring " << amount << " hit point" 
              << (amount != 1 ? "s" : "") << "! New hit points: " << hitPoints << "." << std::endl;
}