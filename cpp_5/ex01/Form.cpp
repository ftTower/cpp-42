#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooLowException();
        else if (gradeToSign > MAX_GRADE || gradeToExecute > MAX_GRADE) throw GradeTooHighException();
    }

Form::~Form() {}

std::ostream &operator<<(std::ostream &out, const Form &form) {
        out << "Form " << form.getName() << ", Sign grade " << form.getGradeToSign()
            << ", Execute grade " << form.getGradeToExecute()
            << ", Signed " << (form.isSigned() ? "yes" : "no");
        return (out);  
}