#include "ClapTrap.hpp"

bool ClapTrap::useEnergy() {
    if (hitPoints > 0 && energyPoints > 0) {
        --energyPoints;
        return true;
    }
    std::cout << name << " energy or hitPoints too low" << std::endl;
    return false;
}

bool ClapTrap::useHitPoints(int amount) {
    if (hitPoints > 0 || (hitPoints == 0 && amount > 0)) {
        hitPoints += amount;
        return true;
    }
    std::cout << name << " hitPoints too low" << std::endl;
    return false;
}

void ClapTrap::attack(const std::string &target) {
    if (useEnergy()) {
        std::cout << name << " attacks " << target << " causing " << attackDamage
                  << " pts damage" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0 && useHitPoints(-amount)) {
        std::cout << name << " takes " << amount << " damage, " << hitPoints << " hitPoints left" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (useEnergy() && useHitPoints(amount) ) {
        std::cout << name << " heals himself " << amount << ", " << hitPoints << " hitPoints left" << std::endl;
    }
}
