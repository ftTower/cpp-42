#pragma once

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public Form
{
  public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const &executor) const;

	const std::string getTarget() const;

  private:
	PresidentialPardonForm();
	const std::string _target;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm a);
