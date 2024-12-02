#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP_HPP

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm(const RobotomyRequestForm &target);
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const &executor) const;
	
	const std::string getTarget() const;

  private:
	const std::string _target;
	RobotomyRequestForm();
};

#endif