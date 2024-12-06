/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:45:32 by tauer             #+#    #+#             */
/*   Updated: 2024/12/06 20:43:07 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
		while (index < input.size() && input[index] == ' ')
			index++;
		while (index < input.size() && input[index] != ' ')
		{
			if (index < input.size() - 1 && isdigit(input[index])
					&& isdigit(input[index + 1]))
				throw(std::runtime_error("One digit numbers only !"));
			index++;
		}
		std::string buf = input.substr(index - 1, 1);
		arr.push_back(buf);
		index++;
	}
}

bool	isOperand(char c) {
	return (c == '/' || c == '*' || c == '-' || c == '+');
}

void RPN::calculate()
{
	while(arr.size() > 1){
				
		
		
	}
}

void RPN::displayArr()
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << i << " " << arr[i] << std::endl;
}
