#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
    protected :
    std::string type;
    
    public:

    Animal() {
        std::cout << "Animal constructor called" << std::endl<< std::endl;
    };
    virtual ~Animal() {
        std::cout << "Animal deconstructor called" << std::endl;
    };

    virtual void    makeSound() const {
        std::cout << "Animal sound" << std::endl;
    }
    std::string getType() const{
        return (type);
    }
    void    kill() const
    {
        delete(this);
    }
};

class Brain {
    public :
    std::string ideas[100];

};

class Dog : public Animal {

    public:
    
    Dog() {
        type = "Dog";
        brain = new(Brain);
        std::cout << "Dog constructor called" << std::endl<< std::endl;
    }
    
    virtual ~Dog() {
        delete(brain);
        std::cout << "Dog deconstructor called" << std::endl;
    }

    void    makeSound() const{
        std::cout << "WOUF WOUF WOUF ARGRRRRRRRR" << std::endl;
    }

    private:
    Brain *brain;
};

class Cat : public Animal {

    public:
    
    Cat() {
        type = "Cat";
        brain = new(Brain);
        std::cout << "Cat constructor called" << std::endl<< std::endl;
    }
    
    virtual ~Cat() {
        delete(brain);
        std::cout << "Cat deconstructor called" << std::endl;
    }

    void    makeSound() const{
        std::cout << "MMrrrRaouuuuw" << std::endl;
    }

    private:
    Brain *brain;
};


#endif