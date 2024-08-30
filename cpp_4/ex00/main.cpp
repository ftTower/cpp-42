
#include "wrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* coco = new Dog();
    const Animal* i = new Cat();

    std::cout << coco->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(), coco->makeSound(), meta->makeSound();

    i->kill();
    const wrongAnimal* vache2 = new wrongCat();

    i = vache2;
    i->makeSound();//, coco->makeSound(), meta->makeSound();
    i->kill(), coco->kill(), meta->kill();
    return 0;
}
