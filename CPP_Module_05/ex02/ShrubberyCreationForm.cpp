#include "ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::string filename = target + "_shrubbery";

    std::ofstream outFile(filename.c_str());
    if (outFile) {
        outFile << "ASCII Art of Trees" << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error creating file." << std::endl;
    }
}