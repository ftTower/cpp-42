#include "Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc <= 1)
        return (1);
    
    //!normal case 
    Zombie *zombieArray = zombieHorde(atoi(argv[1]), "Boris");
    for (int i = 0; i < atoi(argv[1]); i++)
        zombieArray[i].announce();
    delete [] zombieArray;

    //!test with empty size
    zombieArray = zombieHorde(0, "Boris");
    delete [] zombieArray;

    //!test with negative size
    zombieArray = zombieHorde(-1, "Boris");
    delete [] zombieArray;
    return (0);
}