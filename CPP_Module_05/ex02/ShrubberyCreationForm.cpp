#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm",
	145, 137), _target(src.getTarget()){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm",
	145, 137), _target(target){};

const std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSign())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = this->getTarget() + "_shrubbery";

	std::ofstream outFile(filename.c_str());
	if (outFile)
	{
		outFile << "ASCII Art of Trees" << std::endl;
		outFile.close();
	}
	else
	{
		std::cerr << "Error creating file." << std::endl;
	}
}