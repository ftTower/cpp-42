#ifndef FRAGTRAPE_HPP
# define FRAGTRAPE_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    
    public:
    FragTrap(const std::string &name);        
    ~FragTrap();
    
    virtual void    attack(const std::string &target);
    void    highFivesGuys();

};

#endif
