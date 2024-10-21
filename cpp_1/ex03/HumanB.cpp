#include "./weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weaponType(NULL){
    std::cout << "\033[38;5;50m" + name << " is born\033[0m" << std::endl;
}

HumanB::~HumanB() {
    std::cout << "\033[38;5;196m" + name << " killed by Zombiessss...\033[0m" << std::endl; 
}

void HumanB::setType(Weapon *WeaponType) {
    weaponType = WeaponType;
}

void    HumanB::attack() {
    if (!weaponType)
        return std::cout << "\033[38;5;196m" << name << " has no weapon to attack with\033[0m" << std::endl, void();
    std::cout << "\033[38;5;46m" << name << " attacks with their " << weaponType->getType() << "\033[0m" << std::endl;
}