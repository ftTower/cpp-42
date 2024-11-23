
#include "wrongAnimal.hpp"

void    Animal_half()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    Animal *tab[50];
    for(size_t i = 0; i < 50; i++)
    {
        if (!(i % 2))
            tab[i] = new Dog();
        else
            tab[i] = new Cat();
    }

    for(size_t i = 0; i < 50; i++)
    {
        tab[i]->makeSound();
        delete tab[i];
    }
}

void    copy_profonde()
{
    Dog Basic;
    {
        Dog tmp = Basic;
    }
    Cat Basic2;
    {
        Cat tmp = Basic2;
    }
}

int main()
{

    // Animal test;

    Animal_half();

    // copy_profonde();
    
    return (0);
}