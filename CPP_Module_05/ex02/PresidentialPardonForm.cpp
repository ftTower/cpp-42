#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm",
	25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("PresidentialPardonForm",
	25, 5), _target(src.getTarget())
{
}


PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string PresidentialPardonForm::getTarget() const {
    return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSign())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm a)
{
	o << "Form " << a.getName() <<
	":\n\ttarget-nam:\t" << a.getTarget() <<
	"\n\tsign-grade:\t" << a.getGradeToSign() <<
	"\n\texec-grade:\t" << a.getGradeToExecute() <<
	"\n\tis signed:\t" << a.getSign() <<
	std::endl;
	return (o);
}