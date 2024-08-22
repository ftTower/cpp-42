#include "./weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weaponType(weapon) {
    // Constructor implementation
}

HumanA::~HumanA() {
    std::cout << "\033[38;5;196m" + name << " killed by Zombiessss...\033[0m" << std::endl; 
}

void    HumanA::attack() {
    std::cout << "\033[38;5;46m" << name << " attacks with their " << weaponType.getType() << std::endl;
}