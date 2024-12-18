#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

int main()
{
	unsigned int count = 4;
	Animal* animals[count];
	for (unsigned int i = 0; i < count; i++) {
		if (i < count/2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (unsigned int i = 0; i < count; i++) {
		delete animals[i];
	}
	return 0;
}