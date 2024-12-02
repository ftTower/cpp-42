#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form("RobotomyRequestForm", 72, 45), _target(src.getTarget()) {
    std::srand(std::time(0));
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
    std::srand(std::time(0));
};

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::getTarget() const {
    return (_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getSign())
        throw FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    
    std::cout << "Drilling noises.." << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfuly" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << this->getTarget() << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm a)
{
	o << "Form " << a.getName() <<
	":\n\ttarget-nam:\t" << a.getTarget() <<
	"\n\tsign-grade:\t" << a.getGradeToSign() <<
	"\n\texec-grade:\t" << a.getGradeToExecute() <<
	"\n\tis signed:\t" << a.getSign() <<
	std::endl;
	return (o);
}