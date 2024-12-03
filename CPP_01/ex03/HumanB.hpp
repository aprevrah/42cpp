#pragma once
#include <string>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(const std::string& name);
        void attack();
        void setWeapon(Weapon& weapon);
    private:
        std::string name;
        Weapon*     weapon;
};