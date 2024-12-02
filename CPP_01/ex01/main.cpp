#include "Zombie.hpp"
#include "zombieHorde.hpp"

int main() {
    int nb_of_zombs = 50;
    Zombie* horde = zombieHorde(nb_of_zombs, "HordeZomb");
    for (int i = 0; i < nb_of_zombs; i++){
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}