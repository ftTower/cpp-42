
#include "wrongAnimal.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const Animal* i = new Animal();

    delete j;
    delete i;

    Animal *tab[100];
    for(size_t i = 0; i < 100; i++)
    {
        if (!(i % 2))
            tab[i] = new Dog();
        else
            tab[i] = new Cat();
    }

    for(size_t i = 0; i < 100; i++)
    {
        tab[i]->makeSound();
        delete tab[i];
    }
    

    return (0);
}