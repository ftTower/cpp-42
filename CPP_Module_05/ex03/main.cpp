#include "Bureaucrate.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	Intern someRandomIntern;
	Form *rrf;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		std::cout << "\033[48;5;23m" << *rrf << "\033[0m" << std::endl;
		
		rrf = someRandomIntern.makeForm("shrubbery request", "Leela");
		rrf = someRandomIntern.makeForm("presidential request", "Phil");
		rrf = someRandomIntern.makeForm("unknow request", "tauer");


	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR : " << e.what() << std::endl;
	}



	(void)rrf;
	return (0);
}