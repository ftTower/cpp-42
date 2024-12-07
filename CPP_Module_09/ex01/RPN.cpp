/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:45:32 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 03:49:48 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// cd ../ex01 && make re && clear && valgrind ./RPN "          1 1 + 2 *         +   3 -" && make fclean

RPN::~RPN()
{
}

// (((1 * 2) / 2) * 2) = 2
// 2 2 4 - + == 2 + 2 - 4 = 0;

RPN::RPN(const std::string &input)
{
	size_t	index;

	index = 0;
	while (index < input.size())
	{
		if (index < input.size() - 1 && isdigit(input[index])
			&& isdigit(input[index + 1]))
			throw(std::runtime_error("One digit numbers only !"));
		else if (index < input.size() - 1 && isOperand(input[index])
			&& isOperand(input[index + 1]))
			throw(std::runtime_error("Please separate operand with space !"));
		else if (input[index] != ' ')
			arr.push_back(input[index]);
		
		// while (index < input.size() && input[index] == ' ')
		// 	index++;
		// while (index < input.size() && input[index] != ' ')
		// {
		// 	index++;
		// }
		// std::string buf = input.substr(index - 1, 1);
		// try {
		// 	arr.push_back(Element(buf));
		// } catch (std::exception &e) {
		// 	std::cerr << "ERROR : " << e.what() << std::endl;
		// }
		index++;
	}
}

void RPN::calculate()
{
	while (arr.size() > 1)
	{
	}
}

void RPN::displayArr()
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << "[" << RED << i << END << "] " << arr[i] << std::endl;
}
