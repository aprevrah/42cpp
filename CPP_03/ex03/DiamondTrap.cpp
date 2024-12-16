#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <typeinfo>


DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default_diamond_name") {
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)  : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    std::cout << "DiamondTrap " << name << " was constructed." << std::endl;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
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

void DiamondTrap::stats() {
    std::cout << "+==========================+" << std::endl;
    std::cout << "Class:                " << typeid(*this).name() << std::endl;
    std::cout << "DiamondTrap::name:    " << name << std::endl;
    std::cout << "ClapTrap::name:       " << ClapTrap::name << std::endl;
    std::cout << "hitPoints:            " << hitPoints << std::endl;
    std::cout << "energyPoints:         " << energyPoints << std::endl;
    std::cout << "attackDamage:         " << attackDamage << std::endl;
    std::cout << "+==========================+" << std::endl;
}