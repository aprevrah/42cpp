#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ){
	_name = "Nameless Zombie";
}

Zombie::Zombie( std::string name ){
	_name = name;
}

Zombie::~Zombie( void ){
	std::cout << _name << ": Bye..." << std::endl;
}

void Zombie::announce( void ){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name ){
	_name = name;
}