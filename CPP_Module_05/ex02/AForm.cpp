#include "AForm.hpp"
#include "Bureaucrate.hpp"

const std::string &AForm::getName() const
{
	return (name);
}

bool	AForm::getSign(void) const
{
	return (isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (gradeToExecute);
}

AForm::AForm(const AForm &src) : name(src.getName()), isSigned(src.getSign()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()) {}


AForm::AForm(const std::string &name, int gradeToSign,
	int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooLowException();
	else if (gradeToSign > MAX_GRADE || gradeToExecute > MAX_GRADE)
		throw GradeTooHighException();
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(const AForm &src) {
	if (this == &src)
		return *this;
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat__)
{
	if (bureaucrat__.getGrade() > getGradeToSign())
	{
		throw GradeTooLowException();
	}
	isSigned = true;
};

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << ",Sign grade "
         << form.getGradeToSign() 
         << ",Execute grade " 
         << form.getGradeToExecute()
         << ",Signed " 
         << (form.getSign() ? "yes" : "no");
	return (out);
}