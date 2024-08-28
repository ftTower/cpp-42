#include "ClapTrap.hpp"
#include <iostream>

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

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    // Create two ClapTrap instances with Star Wars names
    ClapTrap vader("Darth Vader");
    ClapTrap luke("Luke Skywalker");

    // Display initial status
    std::cout << "\nInitial status:\n";
    vader.attack("Luke Skywalker");
    luke.takeDamage(1);

    // Darth Vader attacks Luke Skywalker several times
    std::cout << "\nDarth Vader attacks Luke Skywalker repeatedly:\n";
    for (int i = 0; i < 5; ++i) {
        vader.attack("Luke Skywalker");
        luke.takeDamage(1);
    }

    // Luke Skywalker repairs himself
    std::cout << "\nLuke Skywalker uses the Force to heal:\n";
    luke.beRepaired(5);

    // Darth Vader runs out of energy
    std::cout << "\nDarth Vader tries to attack but runs out of energy:\n";
    for (int i = 0; i < 10; ++i) {
        vader.attack("Luke Skywalker");
    }

    // Luke Skywalker takes more damage until he "dies"
    std::cout << "\nLuke Skywalker takes damage until he has no hit points left:\n";
    for (int i = 0; i < 10; ++i) {
        luke.takeDamage(1);
    }

    // Luke Skywalker tries to repair himself with no hit points or energy left
    std::cout << "\nLuke Skywalker tries to heal himself with no hit points or energy left:\n";
    luke.beRepaired(5);

    // End of tests
    std::cout << "\nEnd of tests\n";
    return 0;
}

