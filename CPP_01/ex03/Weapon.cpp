#include <string>
#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {}

std::string Weapon::getType() {
    return type;
}

void Weapon::setType(std::string type) {
    type = type;
}
