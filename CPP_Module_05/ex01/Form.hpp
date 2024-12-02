#ifndef FORM_HPP
# define FORM_HPP

#include "stdbool.h"
#include "Bureaucrate.hpp"

class Bureaucrat;

class Form {
    private:
    Form();
    const std::string name;
    bool              isSigned;
    const int         gradeToSign;
    const int         gradeToExecute;

    public:
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    ~Form();

    const std::string &getName() const;
    bool              getSign() const;
    int               getGradeToSign() const;
    int               getGradeToExecute() const;
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