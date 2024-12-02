#include "Bureaucrate.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int _grade) : name(name), grade(_grade)
{
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
	else if (grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this == &src)
		return *this;
	this->grade = src.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
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