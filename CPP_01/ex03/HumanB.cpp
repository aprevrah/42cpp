#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack(void) {
    if (weapon != NULL)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with their BARE FISTS beacause they don't have any weapon" << std::endl;
}
