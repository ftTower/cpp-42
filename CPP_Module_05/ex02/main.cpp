#include "Bureaucrate.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "sys/wait.h"

int	main(void)
{
	try
	{
		Bureaucrat highRank("HighRank", 1); //  :D
		Bureaucrat midRank("MidRank", 50);  //  :|
		Bureaucrat lowRank("LowRank", 150); // :(

		ShrubberyCreationForm shrubForm("home");
		RobotomyRequestForm roboForm("office");
		PresidentialPardonForm presForm("criminal");

		highRank.signForm(shrubForm); // :D
		midRank.signForm(roboForm);   // :D
		lowRank.signForm(presForm);   // :(

		std::cout << "================" << std::endl;

		highRank.executeForm(shrubForm);
		midRank.executeForm(shrubForm);
		lowRank.executeForm(shrubForm);
		std::cout << "================" << std::endl;

		highRank.executeForm(roboForm);
		midRank.executeForm(roboForm);
		lowRank.executeForm(roboForm);
		std::cout << "================" << std::endl;
        highRank.signForm(presForm);
		highRank.executeForm(presForm);
		midRank.executeForm(presForm);
		lowRank.executeForm(presForm);

		std::cout << "================" << std::endl;

		RobotomyRequestForm unSignedRoboForm("unSignedOffice");
		try
		{
			highRank.executeForm(unSignedRoboForm); //  :(
		}
		catch (const AForm::FormNotSignedException &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << "================" << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			std::cout << "Attempt " << i + 1 << ": ";
            sleep(1);
			highRank.executeForm(roboForm);
		}
		std::cout << "================" << std::endl;

		highRank.executeForm(presForm); //:D
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}