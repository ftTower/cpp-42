/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:08:19 by tauer             #+#    #+#             */
/*   Updated: 2024/12/08 17:16:50 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Element.hpp"
#include <cctype>

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

bool Element::isOperand() const
{
	return (getType() == TYPE_DIV || getType() == TYPE_MULTI  || getType() == TYPE_MINUS || getType() == TYPE_PLUS);
}


int Element::getValue() const
{
	// if (getType() == TYPE_NUM)
	// 	return (this->value - '0');
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
		c -= '0';
		break ;
	}
	this->value = static_cast<int>(c);
}

Element::Element(int c) : value(c), type(TYPE_NUM) {}


Element::~Element()
{
}

std::ostream &operator<<(std::ostream &out, const Element &E) {
	if (E.isOperand()) {
		out << " " <<static_cast<char>(E.getValue()) << " ";
	}
	else
		out << std::setw(3) << E.getValue() << " ";
	return (out);
}