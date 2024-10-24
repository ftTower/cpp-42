#include "animal.hpp"

//?Animal

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl << std::endl;
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

//? cat

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new (Brain);
	std::cout << "Cat constructor called" << std::endl << std::endl;
}

Cat::Cat(Cat const &copy) : Animal() { 
	*this = copy;
}

Cat::~Cat()
{
	delete (brain);
	std::cout << "Cat deconstructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "MMrrrRaouuuuw" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	if (this == &copy)
		return *this;
	this->type = copy.type;
	this->brain = new Brain();
	*this->brain = *copy.brain;
	return (*this);
}

//?Dog

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new (Brain);
	std::cout << "Dog constructor called" << std::endl << std::endl;
}

Dog::Dog(Dog const &copy) : Animal() { 
	*this = copy;
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog deconstructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "WOUF WOUF WOUF ARGRRRRRRRR" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	if (this == &copy)
		return *this;
	this->type = copy.type;
	this->brain = new Brain();
	*this->brain = *copy.brain;
	return (*this);
}

//?Brain

Brain::Brain(void) {
	std::cout << "new brain" << std::endl;
}

Brain::Brain(Brain const &copy) {
	*this = copy;
}

Brain::~Brain(void) {
	std::cout << "liquified brain" << std::endl;
}