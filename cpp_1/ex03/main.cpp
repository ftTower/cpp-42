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
    return (0);
}
