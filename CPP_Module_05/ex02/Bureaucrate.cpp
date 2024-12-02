#include "Bureaucrate.hpp"

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this == &src)
		return *this;
	this->grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()), grade(src.getGrade())
{
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int _grade) : name(name), grade(_grade)
{
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
	else if (grade < 1)
		throw (GradeTooHighException());
}
void Bureaucrat::incrementGrade()
{
	if (grade - 1 == 0)
		throw GradeTooHighException();
	else
		grade -= 1;
};

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 == MAX_GRADE)
		throw GradeTooLowException();
	else
		grade += 1;
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