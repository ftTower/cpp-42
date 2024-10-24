#include "animal.hpp"

//?Animal

Animal::Animal()
{
	this->type = "default";
	std::cout << "Animal constructor called" << std::endl;
};

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
};

void Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::kill(void) const
{
	delete (this);
}

//?Dog

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "WOUF WOUF WOUF ARGRRRRRRRR" << std::endl;
}

//?Cat

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "MMrrrRaouuuuw" << std::endl;
}
