#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	_name = "Nameless Zombie";
}

Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie() {
	std::cout << _name << ": Bye..." << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string& name) {
	_name = name;
}