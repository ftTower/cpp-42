#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

# include <iostream>
# include <ostream>
# include <stdexcept>
# include <string>

# define MAX_GRADE 150

class	Form;

class Bureaucrat
{
  private:
	Bureaucrat();
	const std::string name;
	int grade;

  public:
	Bureaucrat(std::string name, int grade);

	std::string getName() const;
	int getGrade() const;
	void signForm(Form &form);

	//----------------------arithmetic---------

	void incrementGrade();
	void decrementGrade();

	//----------------------exeception---------
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Grade is too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Grade is too low");
		}
	};

	//----------------------operator---------

	friend std::ostream &operator<<(std::ostream &out, const Bureaucrat &B)
	{
		return (out << B.name << ", bureaucrat grade " << B.grade << std::endl);
	}
};

#endif