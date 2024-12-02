#pragma once


#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public Form {
    public:
        PresidentialPardonForm(const std::string &target);
        virtual ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const &executor) const ;

    private:
        const std::string target;
};

