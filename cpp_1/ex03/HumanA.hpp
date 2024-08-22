#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {

    public:
        std::string name;
        Weapon &weaponType;
        HumanA(std::string name, Weapon &weaponType);
        ~HumanA();
        void    attack();
};

#endif