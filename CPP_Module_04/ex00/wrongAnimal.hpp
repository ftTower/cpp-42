#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "animal.hpp"

class wrongAnimal : public Animal
{
  public:
	wrongAnimal();
	virtual ~wrongAnimal();
	void makeSound() const;
};

class wrongCat : public wrongAnimal
{
  public:
	wrongCat();
};

#endif