#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
    private :
    std::string type;
    
    public:
    Animal(std::string type) : type(type) {}
    ~Animal() {}

    void    makeSound(std::string sound) {
        std::cout << type << " : " << sound << std::endl;
    }
};

class Dog : public Animal {

    private :
    std::string sound;

    public:
    Dog(std::string type) : Animal(type) {
        this->sound = "WOUFARRRRRR WOUF";
    }
    ~Dog() {}

};


#endif