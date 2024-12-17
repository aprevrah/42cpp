#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
        scavy.guardGate();
    }
    {
        std::cout << "--------------------------------------------------------" << std::endl;
        FragTrap fragy("Fragy");
        fragy.stats();
        fragy.attack("Fragy's Target");
        fragy.highFivesGuys();
    }
}