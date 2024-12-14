#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    {
    ClapTrap clappy("Clappy");
    clappy.attack("Target");
    clappy.takeDamage(1);
    clappy.takeDamage(20);
    clappy.beRepaired(20);
    for (int i = 0; i < 2; i++) {
        clappy.beRepaired(1);
    }
    }
    {
        std::cout << "--------------------------------------------------------" << std::endl;
        ScavTrap scavy("Scavy");
        scavy.attack("scavy's-target");
        scavy.guardGate();
    }
}