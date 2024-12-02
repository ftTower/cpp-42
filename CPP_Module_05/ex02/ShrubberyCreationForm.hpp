#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public :
        ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {};
        ~ShrubberyCreationForm() {};
        virtual void execute(Bureaucrat const &executor) const;
    private :
        const std::string target;
        ShrubberyCreationForm();
};

#endif