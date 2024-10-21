#include "Zombie.hpp"

int main(void)
{
    //!normal case STACK
    randomChump("boris");
    //!empty name STACK
    randomChump("");

    //!normal case HEAP
    Zombie *heapZombie = newZombie("klein");
    heapZombie->announce();
    delete heapZombie;

    //!empty name HEAP
    Zombie *heapZombie = newZombie("");
    heapZombie->announce();
    delete heapZombie;

    return (0);
}