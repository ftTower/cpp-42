#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {

    public:
        std::string name;
        Weapon *weaponType;
        HumanB(std::string name);
        ~HumanB();
        void    setType(Weapon *weaponTime);
        void    attack();
};

#endif