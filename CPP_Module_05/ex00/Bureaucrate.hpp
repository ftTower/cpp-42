#pragma once

# include <iostream>
# include <stdexcept>

# define MAX_GRADE 150

class Bureaucrat
{
  private:
	Bureaucrat();
	const std::string name;
	int grade;

  public:
	Bureaucrat(std::string name, int grade);

	const std::string& getName() const;
	 int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	Bureaucrat&operator=(const Bureaucrat &src);

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Grade is too high!");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Grade is too low!");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);
