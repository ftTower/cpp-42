#include "Bureaucrate.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bob("Bob", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Alice", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat keke("Keke", 70);
		std::cout << keke << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat coco("Coco", MAX_GRADE - 2);
		coco.decrementGrade();
		std::cout << coco << std::endl;
		coco.decrementGrade();
		coco.decrementGrade();
		std::cout << coco << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat cece("Cece", 0 + 2);
		cece.incrementGrade();
		std::cout << cece << std::endl;
		cece.incrementGrade();
		cece.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat toto("Toto", 50);

		Bureaucrat liso("Liso", 70);

		toto = liso;

		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat toto("Toto", 50);

		Bureaucrat liso(toto);

		std::cout << liso << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}