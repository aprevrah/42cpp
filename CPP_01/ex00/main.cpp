#include "Zombie.hpp"

int main() {
    Zombie* foo = newZombie("Foo");
    foo->announce();
    delete foo;
    randomChump("Bar");
    return 0;
}