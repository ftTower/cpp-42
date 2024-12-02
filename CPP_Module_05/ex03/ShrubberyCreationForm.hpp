#pragma once


#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public Form {
    public :
        ShrubberyCreationForm(const ShrubberyCreationForm &target);
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm() {};

        virtual void execute(Bureaucrat const &executor) const;

	    const std::string getTarget() const;
    private :
        const std::string _target;
        ShrubberyCreationForm();
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm a);
