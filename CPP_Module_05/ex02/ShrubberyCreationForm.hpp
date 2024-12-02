#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
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

#endif