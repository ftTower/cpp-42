#include "Bureaucrate.hpp"

void    Bureaucrat::signForm(Form &form) {
        try {
            form.beSigned(*this);
            std::cout << name << " signed " << form.getName() << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << name << " couldn't sign" << form.getName() << " because " << e.what() << std::endl;
        }
}