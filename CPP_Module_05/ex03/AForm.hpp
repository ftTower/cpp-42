#pragma once


#include <iostream>
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
    Form(const Form &src);
    virtual ~Form();
    Form &operator=(const Form &src);

    const std::string &getName() const;
    bool              getSign() const ;
    int               getGradeToSign() const;
    int               getGradeToExecute() const;
    void              beSigned(const Bureaucrat &bureaucrat__);
    virtual void      execute(Bureaucrat const &executor) const = 0;
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
    class FormNotSignedException : public std::exception {
        public:
            const char *what() const throw() {
                return ("Form not signed");
            }
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);
