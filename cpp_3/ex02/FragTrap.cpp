#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << name << " ScavTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (useEnergy()) {

        std::cout << name << " attacks " << target << " causing " << attackDamage
                  << " points of damage !" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << name << " requests a high five!" << std::endl;
}