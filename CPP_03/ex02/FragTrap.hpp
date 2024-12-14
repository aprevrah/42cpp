#pragma once
#include <string>
#include "ClapTrap.hpp"

class FragTrap : ClapTrap {
	private:
		FragTrap();
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		~FragTrap();
		FragTrap& operator=(const FragTrap &rhs);

		void attack(const std::string& target);
		void highFivesGuys(void);
};