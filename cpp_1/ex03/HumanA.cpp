#include "./weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weaponType(weapon) {
    std::cout << "\033[38;5;50m" + name << " is born\033[0m" << std::endl; 
}

HumanA::~HumanA() {
    std::cout << "\033[38;5;196m" + name << " killed by Zombiessss...\033[0m" << std::endl; 
}

void    HumanA::attack() {
    std::cout << "\033[38;5;46m" << name << " attack with " << weaponType.getType() << "\033[0m" << std::endl;
}