/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:36:06 by tauer             #+#    #+#             */
/*   Updated: 2024/12/03 00:37:02 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public Form
{
  public:
	RobotomyRequestForm(const RobotomyRequestForm &target);
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const &executor) const;
	
	const std::string getTarget() const;

  private:
	const std::string _target;
	RobotomyRequestForm();
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm a);

