#pragma once
#include <string>

class Zombie {
	public:
		Zombie();
		Zombie( const std::string& name );
		~Zombie();

		void announce();
		void setName( std::string& name );
	private:
	std::string _name;
};

Zombie*	newZombie( const std::string& name );
void	randomChump( const std::string& name );