#include "./weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    Weapon Weapon1 = Weapon("mamooths");

    HumanA firstHuman("Rick", Weapon1);

    firstHuman.attack();
    Weapon1.setType("ninjas");
    firstHuman.attack();

    Weapon Weapon2 = Weapon("mamooths");

    HumanB secondHuman("Bob");
    secondHuman.setType(&Weapon2);
    secondHuman.attack();
    Weapon2.setType("ninjas");
    secondHuman.attack();
    return (0);
}
