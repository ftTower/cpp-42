#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

# define MAX_GRADE 150

class Form;

class Bureaucrat {
    private :

    const std::string name;
    int grade;
    
    public :

    Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
        if (grade > MAX_GRADE) throw GradeTooHighException();
        else if (grade < 1) throw GradeTooLowException();
    }

    std::string getName() const {return (name);}
    int         getGrade() const {return (grade);}
    void    signForm(Form &form);

    //----------------------arithmetic---------

    void        incrementGrade() {
        if (grade + 1 == MAX_GRADE) throw GradeTooHighException();
        else grade =+1;
    };
    void decrementGrade() {
        if (grade - 1 == 0) throw GradeTooLowException();
        else grade =-1;
    };

    //----------------------exeception---------
    class GradeTooHighException : public std::exception {
        public :
            const char *what() const throw() {
                return ("Grade is too high");
            }
    };
    class GradeTooLowException : public std::exception {    
        public :
            const char *what() const throw() {
              return ("Grade is too low");
           }
    };
    //----------------------operator---------
    friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &B) {
        return out << B.name << ", bureaucrat grade " << B.grade << std::endl; 
    }
};

#endif