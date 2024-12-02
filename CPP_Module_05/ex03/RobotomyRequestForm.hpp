#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public Form
{

  public:
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const &executor) const;

  private:
	RobotomyRequestForm();
	const std::string target;
};
