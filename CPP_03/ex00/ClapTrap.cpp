#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
		return;
	}
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << name << " tries to attack " << target << ", but failes miserably because they have no energy points" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " took " << amount << " point";
	if (amount != 1)
		std::cout << "s";
	std::cout << " of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repaied " << amount << " hit point";
	if (amount != 1)
		std::cout << "s";
	std::cout << std::endl;
}
