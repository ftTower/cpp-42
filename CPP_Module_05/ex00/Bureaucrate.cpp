/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:40:29 by tauer             #+#    #+#             */
/*   Updated: 2024/12/02 22:08:37 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

const std::string& Bureaucrat::getName() const
{
	return (name);
}

 int Bureaucrat::getGrade() const
{
	return (grade);
}

Bureaucrat::Bureaucrat(std::string name, int _grade) : name(name), grade(_grade)
{
	if (grade > MAX_GRADE)
		throw GradeTooLowException();
	else if (grade < 1)
		throw (GradeTooHighException());
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 == 0)
		throw GradeTooHighException();
	else
		grade -= 1;
};

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 == MAX_GRADE)
		throw GradeTooLowException();
	else
		grade += 1;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B)
{
		return (out << B.getName() << ", bureaucrat grade " << B.getGrade() << std::endl);
}