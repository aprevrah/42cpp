#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
	private:
		
	public:
		ScavTrap(const std::string& name);
		~ScavTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};