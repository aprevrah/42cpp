#pragma once
#include <string>

class Zombie {
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void announce( void );
		void setName( std::string );
	private:
	std::string _name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );