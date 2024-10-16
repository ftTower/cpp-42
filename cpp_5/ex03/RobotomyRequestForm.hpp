#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
    public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    virtual void execute(Bureaucrat const &executor) const;

    private :
    const std::string target;
};

#endif