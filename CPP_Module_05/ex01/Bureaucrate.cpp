#include "Bureaucrate.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
	{
		if (grade > MAX_GRADE)
			throw GradeTooHighException();
		else if (grade < 1)
			throw GradeTooLowException();
	}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (grade + 1 == MAX_GRADE)
		throw GradeTooHighException();
	else
		grade = +1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (grade - 1 == 0)
		throw GradeTooLowException();
	else
		grade = -1;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}