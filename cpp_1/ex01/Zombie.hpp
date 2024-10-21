#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

    private:
        std::string name;
        int pos;
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();
       void setName(std::string &name);
       void setPos(int &pos);
        
    void    announce(void);

};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif