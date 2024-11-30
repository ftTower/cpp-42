/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:40:29 by tauer             #+#    #+#             */
/*   Updated: 2024/11/30 18:53:23 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

std::string Bureaucrat::getName()
{
	return (name);
}

int Bureaucrat::getGrade()
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
