#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    {
        ClapTrap clappy("Clappy");
        clappy.stats();
    }
    {
        std::cout << "--------------------------------------------------------" << std::endl;
        ScavTrap scavy("Scavy");
        scavy.stats();
        scavy.attack("Scavy's Target");
        scavy.takeDamage(5);
        scavy.guardGate();
        scavy.attack("Scavy's Other Target");
        scavy.stats();
        scavy.beRepaired(2);
        scavy.stats();
        scavy.attack("Scavy's Another Other Target");
        for (int i = 0; i < 50; i++) {
            scavy.beRepaired(1);
        }
        scavy.stats();
        scavy.attack("Scavy's Another Other Other Target");
        scavy.stats();
    }
}