#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		static const unsigned int hitPoints_default = 100;
		static const unsigned int energyPoints_default = 50;
		static const unsigned int attackDamage_default = 20;
		ScavTrap();
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &rhs);

		void attack(const std::string& target);
		void guardGate();
};