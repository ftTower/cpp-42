#ifndef FORM_HPP
# define FORM_HPP

#include "stdbool.h"
#include "Bureaucrate.hpp"

class Form {
    private:

    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExecute;

    public:
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    ~Form() {};

    const std::string &Form::getName() const {return (name);}
    bool              Form::isSigned() const {return (isSigned);}
    int               Form::getGradeToSign() const {return (gradeToSign);}
    int               Form::getGradeToExecute() const {return (gradeToExecute);}
    

    class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw() {
                return ("Form grade too high");
            }
    };
    
    class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw() {
                return ("Form grade too Low");
            }
    };
    
    void    beSigned(const Bureaucrat &bureaucrat) {
        if (bureaucrat.getGrade() > gradeToSign) {throw GradeTooLowException();}
            isSigned = true;
    };

};

std::ostream &operator<<(std::ostream &out, Bureaucrat &Bureaucrat);
    
#endif