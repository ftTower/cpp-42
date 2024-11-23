#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;
	void kill() const;
};

class Dog : public Animal
{
  public:
	Dog();
	virtual ~Dog();

	void makeSound(void) const;
};

class Cat : public Animal
{
  public:
	Cat();
	virtual ~Cat();

	void makeSound(void) const;
};

#endif