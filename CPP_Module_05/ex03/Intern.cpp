/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:15:49 by tauer             #+#    #+#             */
/*   Updated: 2024/12/02 21:56:19 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(const Intern &target) {
	*this = target;
}

Intern::~Intern() {}


static Form *makePresident(const std::string target) {
	return (new PresidentialPardonForm(target));
}

static  Form *makeRobotomy(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static Form *makeShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(const std::string form, const std::string target) {

	Form *(*aformArr[])(const std::string target) = {&makePresident, &makeRobotomy, &makeShrubbery};
	const std::string arr[] = {"presidential request", "robotomy request", "shrubbery request"};
	
	for (size_t i = 0; i < 3; i++) {
		if (form == arr[i])
		{
			std::cout << "Intern " << target << " create " << form << std::endl;
			return (aformArr[i](target));
		}
	}
	throw std::runtime_error("Cannot found a form named " + form);
}
