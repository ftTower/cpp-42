#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {

    protected :
    
    const std::string name;
    int hitPoints;
    int attackDamage;
    int energyPoints;

    public :
        ClapTrap(const std::string name) : \
            name(name), hitPoints(10), attackDamage(0), energyPoints(10) {
            std::cout << name << " constructor(Claptrap) called" <<std::endl;
        };
        virtual ~ClapTrap() {
            std::cout << name << "destructor called(Claptrap)" <<std::endl;
        };
        
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    setHitPoints(unsigned int amount) {hitPoints = amount;}
        void    setAttackDamage(unsigned int amount) {attackDamage = amount;}
        void    setEnergyPoints(unsigned int amount) {energyPoints = amount;}


        bool    useEnergy();
        bool    useHitPoints(int amount);

};



#endif