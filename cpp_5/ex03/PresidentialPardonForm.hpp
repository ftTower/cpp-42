#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(const std::string &target);
        virtual ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const &executor) const ;

    private:
        const std::string &target;
};

#endif