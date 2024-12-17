#include "ClapTrap.hpp"

int main() {
    ClapTrap clappy("Clappy");
    clappy.stats();
    clappy.attack("Clappy's Target");
    clappy.takeDamage(8);
    clappy.beRepaired(5);
    clappy.stats();
    clappy.takeDamage(20);
    clappy.beRepaired(20);
    clappy.stats();
}