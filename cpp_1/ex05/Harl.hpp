#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
// #include <>

class Harl {

    private:
    void    debug(void) {
        std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    }
    void    info(void)  {
        std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    }
    void    warning(void) {
        std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    }
    void    error(void) {
        std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
    }
    void    unknow(void) {
        std::cout << "UNKNOW: Unknow level" << std::endl;
    }
    
    int getLevelInfo(std::string level){
        if (level == "DEBUG") {return (0);}
        else if (level == "INFO") {return (1);}
        else if (level == "WARNING") {return (2);}
        else if (level == "ERROR") {return (3);}
        else {return (4);}
    }
    
    public:

    void complain(std::string level) {
        void (Harl::*funcs[])(void) = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error,
            &Harl::unknow,
        };
        (this->*funcs[getLevelInfo(level)])();
    };
};

#endif