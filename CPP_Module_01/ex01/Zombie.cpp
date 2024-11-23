#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}
Zombie::Zombie() : name() {}

Zombie::~Zombie() {
    std::cout << name << " has been destroyed" << std::endl;
}

void    Zombie::announce(void) {
    std::cout << name << "/" << pos << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void    randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}

void Zombie::setName(std::string& name) { this->name = name; }
void Zombie::setPos(int& pos) { this->pos = pos; }