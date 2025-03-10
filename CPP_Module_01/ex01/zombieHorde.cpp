#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombieArray;

    if (N <= 0)
        return (NULL);
    zombieArray = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombieArray[i].setName(name);
        zombieArray[i].setPos(i);
    }
    return (zombieArray);
}
