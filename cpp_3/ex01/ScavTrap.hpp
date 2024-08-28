#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    
    public:
    ScavTrap(const std::string &name);        
    ~ScavTrap();
    
    virtual void    attack(const std::string &target);
    void    guardGate();

};

#endif
