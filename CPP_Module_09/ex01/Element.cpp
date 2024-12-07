/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:08:19 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 15:24:46 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Element.hpp"

// class Element {
// public :
// Element(std::string &input);
// ~Element();
//
// int getValue() const;
// int getType() const;
// private :
// int		value;
// t_type type;
// };

bool	_isOperand(char c)
{
	return (c == '/' || c == '*' || c == '-' || c == '+');
}

int Element::getValue() const
{
	if (getType() == TYPE_NUM)
		return (this->value - '0');
	return (this->value);
}

t_type Element::getType() const
{
	return (this->type);
}

Element::Element(char c)
{
	if (!isdigit(c) && !_isOperand(c))
		throw(std::runtime_error("Please Enter numbers between 0 & 9 or operand {'+', '-', '*', '/'} !"));
	switch (c)
	{
	case '-':
		this->type = TYPE_MINUS;
		break ;
	case '+':
		this->type = TYPE_PLUS;
		break ;
	case '/':
		this->type = TYPE_DIV;
		break ;
	case '*':
		this->type = TYPE_MULTI;
		break ;
	default:
		this->type = TYPE_NUM;
		break ;
	}
	this->value = static_cast<int>(c);
}

Element::~Element()
{
}

std::ostream &operator<<(std::ostream &out, const Element &E)
{
	switch (E.getType())
	{
	case TYPE_DIV:
		out << "/ ";
		break ;
	case TYPE_MULTI:
		out << "* ";
		break ;
	case TYPE_PLUS:
		out << "+ ";
		break ;
	case TYPE_MINUS:
		out << "- ";
		break ;
	default:
		out << E.getValue();
		break ;
	}
	return (out);
}