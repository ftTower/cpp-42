#include "./weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    //!test with HumanA
    std::cout << "====================HumanA====================" << std::endl;
    Weapon Weapon1 = Weapon("his stinky socks");
    HumanA firstHuman("Rick", Weapon1);
    firstHuman.attack();
    Weapon1.setType("his knownledge");
    firstHuman.attack();

    //!test with HumanB
    std::cout << "====================HumanB====================" << std::endl;
    Weapon Weapon2 = Weapon("his cat");
    Weapon Weapon3 = Weapon("his dogs");
    HumanB secondHuman("Bob");
    secondHuman.setType(&Weapon2);
    secondHuman.attack();
    Weapon2.setType("his bob");
    secondHuman.attack();

    //!test B with null weapon
    secondHuman.setType(NULL);
    secondHuman.attack();

    
    return (0);
}
