#include "Bureaucrate.hpp"

void    Bureaucrat::signForm(AForm &form) {
        try {
            form.beSigned(*this);
            std::cout << name << " signed " << form.getName() << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << name << " couldn't sign" << form.getName() << " because " << e.what() << std::endl;
        }
};

void    Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn't execute " << form.getName() << "because" << e.what() << std::endl;
    }
};