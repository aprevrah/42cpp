#include "Zombie.hpp"

void randomChump(const std::string& name){
	Zombie zomb(name);
	zomb.announce();
}