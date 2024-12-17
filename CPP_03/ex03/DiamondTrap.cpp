#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>



DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default_diamond_name") {
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)  : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    std::cout << "DiamondTrap " << name << " was constructed." << std::endl;
    this->hitPoints = FragTrap::hitPoints_default;
    this->energyPoints = ScavTrap::energyPoints_default;
    this->attackDamage = FragTrap::attackDamage_default;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    *this = other;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " was destructed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->hitPoints = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
    }
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap::name : " << name << std::endl;
    std::cout << "ClapTrap::name: " << ClapTrap::name << std::endl;
}
