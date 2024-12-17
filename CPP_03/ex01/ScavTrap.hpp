#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		ScavTrap();
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &rhs);

		void attack(const std::string& target);
		void guardGate();
};