#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "Creating ClapTrap and ScavTrap instances:" << std::endl;
    
    ClapTrap claptrap("Claptrap");
    ScavTrap scavtrap("Scavtrap");

    std::cout << "\nInitial status and actions:" << std::endl;
    claptrap.attack("target1");
    scavtrap.attack("target2");

    scavtrap.guardGate();
    claptrap.beRepaired(20);
    scavtrap.beRepaired(20);

    return 0;
}