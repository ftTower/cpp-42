#include "Bureaucrate.hpp"
#include "Form.hpp"

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

Form::Form(const Form &src) : name(src.getName()), isSigned(src.getSign()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()) {}

Form::Form(const std::string &name, int gradeToSign,
	int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign),
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
}

Form	&Form::operator=(const Form &src) {
	if (this == &src)
		return *this;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << ",Sign grade " 
            << form.getGradeToSign() << ",Execute grade "
            << form.getGradeToExecute()
            << ",Signed " << (form.getSign() ? "yes" : "no");
	return (out);
}