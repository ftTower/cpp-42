/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:45:32 by tauer             #+#    #+#             */
/*   Updated: 2024/12/08 17:49:04 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN()
{
}


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
			arr.push_back(Element(input[index]));
		index++;
	}
	if (arr.empty())
		throw(std::runtime_error("No number or operator in input !"));
	for (int i = arr.size() - 1 ; i >= 0; i--) {
		if (arr[i].isOperand())
			op.push(arr[i]);
		else
			nbs.push(arr[i]);
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
			if (nb2.getValue() == 0)
				throw(std::runtime_error("Division by zero error!"));
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

void RPN::CalculArr() {
    std::stack<int> stack;

    for (size_t i = 0; i < arr.size(); ++i) {
        Element elem = arr[i];
        if (elem.getType() == TYPE_NUM) {
            stack.push(elem.getValue());
        } else {
            if (stack.size() < 2)
                throw std::runtime_error("Invalid RPN expression: not enough numbers for operation!");

            int b = stack.top(); stack.pop(); 
            int a = stack.top(); stack.pop(); 

            int result = calculation(Element(a), Element(b), elem);
            stack.push(result); 
        }
    }

    if (stack.size() != 1){
        throw std::runtime_error("Invalid RPN expression: too many numbers or operators!");
	}
	
	displayArr();
    std::cout << "Result: " << stack.top() << std::endl;
}

void RPN::displayArr()
{
	size_t i;
	for(i = 0; i < arr.size(); i++) {
		if (arr[i].getType() != TYPE_NUM)
			break ;
	}
	
	for (size_t y = 0; y < arr.size(); y++) {
		if (arr[y].getType() != TYPE_NUM)
			std::cout << YELLOW_BG;
		else
			std::cout << BLUE_BG;
		std::cout  << arr[y] << END;
	}
	std::cout << std::endl;
}
