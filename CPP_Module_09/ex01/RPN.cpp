/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:45:32 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 16:29:23 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// cd ../ex01 && make re && clear && valgrind ./RPN "          1 1 + 2 *        +   3 -" && make fclean

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
		else if (index < input.size() - 1 && _isOperand(input[index])
			&& _isOperand(input[index + 1]))
			throw(std::runtime_error("Please separate operand with space !"));
		else if (input[index] != ' ')
			arr.push_back(input[index]);
		index++;
	}
}

int	calculation(Element nb1, Element nb2, Element operand)
{
	if (nb1.getType() != TYPE_NUM || nb2.getType() != TYPE_NUM || operand.getType() == TYPE_NUM)
		throw(std::runtime_error("wrong entry for calculation ! must be : <nb> <nb> <operand>"));
	long buf;
	switch (operand.getType())
	{
		case TYPE_DIV:
			buf = nb1.getValue() / nb2.getValue();
			break;
		case TYPE_MULTI:
			buf = nb1.getValue() * nb2.getValue();
			break;
		case TYPE_MINUS:
			buf = nb1.getValue() - nb2.getValue();
			break;
		case TYPE_PLUS:
			buf = nb1.getValue() + nb2.getValue();
			break;
		default:
			throw(std::runtime_error("Unknow operand : '-' '+' '*' '/' "));		
			break;
	}
	if (buf > INT_MAX || buf < INT_MIN)
		throw(std::runtime_error("Cannot do more operation ! int overflow"));
	return (static_cast<int> (buf));		
}

bool RPN::HadOperand() const { 
	for (size_t i = 0; i < arr.size(); i++)
		if (_isOperand(arr[i].getValue()))
			return (true);
	return false;
}

void RPN::RpnCalculationElements()
{
	if (arr.size() < 3)
		throw(std::runtime_error("Cannot do operation with less than 3 elements!"));
	else if (!HadOperand())
		throw(std::runtime_error("Cannot do operation with no operand!"));
	
	size_t i;
	for(i = 0; i < arr.size(); i++) {
		if (arr[i].getType() != TYPE_NUM)
			break ;
	}
	std::cout << arr[i - 2] << " " << arr[i - 1] << " " << arr[i] << std::endl;
	int buf = calculation(arr[i - 2], arr[i - 1], arr[i]);
	arr.erase(arr.begin(), arr.begin() + i);
	arr.insert(arr.begin(), Element(buf));
}

void RPN::displayArr()
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout  << "[" << YELLOW << arr[i]  << END << "] ";
	std::cout << std::endl;
}
