#include "Zombie.hpp"

int main(void)
{
    randomChump("boris");

    Zombie *heapZombie = newZombie("klein");
    heapZombie->announce();

    delete heapZombie;
    return (0);
}