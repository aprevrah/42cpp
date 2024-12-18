#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
	std::cout << BLUE << "Test allocation\n" << RESET << std::endl;
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

	std::cout << BLUE << "\nTest deep copy\n" << RESET << std::endl;
	Dog* foo = new Dog();
	Dog* bar = new Dog();
	foo->getBrain()->setIdea(25, "25 is my favorite number...");
	bar->getBrain()->setIdea(25, "25 is a terrible number...");

	std::cout << GREEN << "foo's 25 idea is: " << RESET << foo->getBrain()->getIdea(25) << std::endl;
	std::cout << YELLOW << "bar's 25 idea is: " << RESET << bar->getBrain()->getIdea(25) << std::endl;

	Dog* foofighter = new Dog(*bar);
	foofighter->getBrain()->setIdea(26, "I'll fight anyone who thinks 25 is a good number...");
	std::cout << RED << "foofighters's 25 idea is: " << RESET << foofighter->getBrain()->getIdea(25) << std::endl;
	std::cout << RED << "foofighters's 26 idea is: " << RESET << foofighter->getBrain()->getIdea(26) << std::endl;
	*foo = *foofighter;
	std::cout << "foofighter sent his brain to foo" << std::endl;
	std::cout << GREEN << "foo's 25 idea is: " << RESET << foo->getBrain()->getIdea(25) << std::endl;
	std::cout << GREEN << "foo's 26 idea is: " << RESET << foo->getBrain()->getIdea(26) << std::endl;
	delete foo;
	delete bar;
	delete foofighter;

	//This should no longer work.
	//Animal animal_test();
	return 0;
}