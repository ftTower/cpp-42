#pragma once


#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public Form {
    public :
        ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), target(target) {};
        ~ShrubberyCreationForm() {};
        virtual void execute(Bureaucrat const &executor) const;
    private :
        const std::string target;
};

