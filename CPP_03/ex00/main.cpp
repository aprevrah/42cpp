#include "ClapTrap.hpp"

int main() {
    ClapTrap clappy("Clappy");
    clappy.attack("Target");
    clappy.takeDamage(1);
    clappy.takeDamage(20);
    clappy.beRepaired(20);
    for (int i = 0; i < 10; i++) {
        clappy.beRepaired(1);
    }

}