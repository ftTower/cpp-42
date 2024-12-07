/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:38:12 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 16:27:48 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <climits>
#include "Element.hpp"

#define RED "\033[38;5;196m"
#define GREEN "\033[38;5;34m"
#define YELLOW "\033[38;5;220m"
#define PURPLE "\033[38;5;135m"
#define BLUE "\033[38;5;18m"
#define WHITE "\033[38;5;195m"
#define END "\033[0m"


class RPN {

	private :
		RPN();
		std::vector <Element> arr;

	public :
		RPN(const std::string &input);
		// RPN(const std::vector  <std::string> arr);
		~RPN();

		bool	HadOperand() const;

		void	displayArr();
		void	calculate();
		void 	RpnCalculationElements();
};

