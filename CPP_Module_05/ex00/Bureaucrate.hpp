#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

# include <iostream>
# include <stdexcept>

# define MAX_GRADE 150

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat(std::string name, int grade);

	std::string getName();
	int getGrade();

	void incrementGrade();
	void decrementGrade();

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

	friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &B)
	{
		return (out << B.name << ", bureaucrat grade " << B.grade << std::endl);
	}
};

#endif