#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget()) {
    std::srand(std::time(0));
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
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