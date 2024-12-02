#include "AForm.hpp"
#include "Bureaucrate.hpp"

const std::string &Form::getName() const
{
	return (name);
}
bool	Form::getSign(void) const
{
	return (isSigned);
}
int	Form::getGradeToSign(void) const
{
	return (gradeToSign);
}
int	Form::getGradeToExecute(void) const
{
	return (gradeToExecute);
}

Form::Form(const std::string &name, int gradeToSign,
	int gradeToExecute) : name(name), gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooLowException();
	else if (gradeToSign > MAX_GRADE || gradeToExecute > MAX_GRADE)
		throw GradeTooHighException();
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat &bureaucrat__)
{
	if (bureaucrat__.getGrade() > getGradeToSign())
	{
		throw GradeTooLowException();
	}
	isSigned = true;
};

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << ",Sign grade "
            << form.getGradeToSign()
            << ",Execute grade "
            << form.getGradeToExecute()
            << ",Signed "
            << (form.getSign() ? "yes" : "no");
	return (out);
}