#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
	private:

	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};