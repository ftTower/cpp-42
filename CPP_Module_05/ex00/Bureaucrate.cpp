/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:40:29 by tauer             #+#    #+#             */
/*   Updated: 2024/11/30 02:49:04 by tauer            ###   ########.fr       */
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
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
}

void Bureaucrat::incrementGrade()
{
	if (grade + 1 == MAX_GRADE)
		throw GradeTooHighException();
	else
		grade = +1;
};

void Bureaucrat::decrementGrade(void)
{
	if (grade - 1 == 0)
		throw GradeTooLowException();
	else
		grade = -1;
};
