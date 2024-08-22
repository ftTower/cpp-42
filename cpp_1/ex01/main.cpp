#include "Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc <= 1)
        return (1);
    Zombie *zombieArray = zombieHorde(atoi(argv[1]), "boris");
    for (int i = 0; i < atoi(argv[1]); i++)
        zombieArray[i].announce();
    delete [] zombieArray;
    return (0);
}