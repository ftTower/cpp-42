#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << name << " ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (useEnergy()) {

        std::cout << name << " attacks " << target << " causing " << attackDamage
                  << " points of damage !" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << name << " is now in Gate Keeper mode" << std::endl;
}