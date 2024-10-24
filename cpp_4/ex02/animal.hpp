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
	virtual void makeSound() const = 0;
	std::string getType() const;
	void kill() const;
};

class Brain
{
    public:
    Brain();
    Brain(Brain const &copy);
    ~Brain();
    private:
	std::string ideas[100];
};

class Dog : public Animal
{
  public:
	Dog();
    Dog(const Dog &copy);
	virtual ~Dog();
	void makeSound() const;
    Dog &operator=(const Dog &copy);

  private:
	Brain *brain;
};

class Cat : public Animal
{
  public:
	Cat();
	virtual ~Cat();
    Cat(const Cat &copy);
	void makeSound() const;
    Cat &operator=(const Cat &copy);

  private:
	Brain *brain;
};

#endif