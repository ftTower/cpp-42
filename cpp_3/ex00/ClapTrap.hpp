#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {

    private :
    
    const std::string name;
    int hitPoints;
    const int attackDamage;
    int energyPoints;

    public :
        ClapTrap(const std::string name) : \
            name(name), hitPoints(10), attackDamage(0), energyPoints(10) {
            std::cout << name << " constructor called" <<std::endl;
        };
        ~ClapTrap() {std::cout << "destructor called" <<std::endl;};
        
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        bool    useEnergy();
        bool    useHitPoints(int amount);
};

#endif