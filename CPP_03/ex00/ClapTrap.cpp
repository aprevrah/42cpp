#include "ClapTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " was constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), 
    hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " was destructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->name = rhs.name;
        this->hitPoints = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

// member functions

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