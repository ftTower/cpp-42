/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:05:37 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 15:24:28 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


typedef enum e_type {
	TYPE_NUM,
	TYPE_PLUS,
	TYPE_MINUS,
	TYPE_DIV,
	TYPE_MULTI,
}	t_type;

class Element {
	public :
		Element(char c);
		~Element();

		int getValue() const;
		t_type getType() const;
		bool	isOperand() const;
	private :
		int	   value;
		t_type type;
};

bool	_isOperand(char c);

std::ostream &operator<<(std::ostream &out, const Element &E);
