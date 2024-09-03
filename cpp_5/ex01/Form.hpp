#ifndef FORM_HPP
# define FORM_HPP

#include "stdbool.h"
#include "Bureaucrate.hpp"

class Bureaucrat;

class Form {
    private:

    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExecute;

    public:
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    ~Form();

    const std::string &getName() const {return (name);}
    bool              getSign() const {return (isSigned);}
    int               getGradeToSign() const {return (gradeToSign);}
    int               getGradeToExecute() const {return (gradeToExecute);}
    void              beSigned(const Bureaucrat &bureaucrat__);

    //----------------------exeception---------

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
};

//----------------------operator---------
std::ostream &operator<<(std::ostream &out, const Form &form);
    
#endif