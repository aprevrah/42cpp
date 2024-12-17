#pragma once
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		static const unsigned int hitPoints_default = 100;
		static const unsigned int energyPoints_default = 100;
		static const unsigned int attackDamage_default = 30;
		FragTrap();
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		~FragTrap();
		FragTrap& operator=(const FragTrap &rhs);

		void attack(const std::string& target);
		void highFivesGuys(void);
};