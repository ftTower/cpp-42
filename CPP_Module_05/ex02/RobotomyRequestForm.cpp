#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::srand(std::time(0));
};

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    
    std::cout << "Drilling noises.." << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfuly" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << std::endl;
    }
}