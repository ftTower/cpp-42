#include "./weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weaponType(NULL){
}

HumanB::~HumanB() {
    std::cout << "\033[38;5;196m" + name << " killed by Zombiessss...\033[0m" << std::endl; 
}

void HumanB::setType(Weapon *WeaponType) {
    weaponType = WeaponType;
}

void    HumanB::attack() {
    if (!weaponType)
        return ;
    std::cout << "\033[38;5;46m" << name << " attacks with their " << weaponType->getType() << "\033[0m" << std::endl;
}