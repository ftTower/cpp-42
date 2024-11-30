#include "Bureaucrate.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
	{
		if (grade > MAX_GRADE)
			throw GradeTooHighException();
		else if (grade < 1)
			throw GradeTooLowException();
	}

void	Bureaucrat::incrementGrade(void)
{
	if (grade + 1 == MAX_GRADE)
		throw GradeTooHighException();
	else
		grade = +1;
};
void	Bureaucrat::decrementGrade(void)
{
	if (grade - 1 == 0)
		throw GradeTooLowException();
	else
		grade = -1;
};
std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't sign" << form.getName() << " because " << e.what() << std::endl;
	}
};

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't execute " << form.getName() << "because" << e.what() << std::endl;
	}
};