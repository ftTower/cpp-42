/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:45:00 by tauer             #+#    #+#             */
/*   Updated: 2024/11/24 23:37:36 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span() {
	delete[] arr;
}

Span::Span() : arr(NULL), len(0), index(0) {}

Span::Span(unsigned int N) :  arr(new int[N]), len(N), index(0) {
	for(unsigned int i = 0; i < len; i++) {
		arr[i] = 0;
	}
}

int	Span::getNumber(unsigned int pos) const {
	if (!arr || pos > _len())
		throw std::runtime_error("Pos not in array !");
	return (arr[pos]);
}

unsigned int Span::_len() const {
	return (len);
}

unsigned int Span::_index() const {
	return (index);
}

void	Span::_incrIndex() {
	index += 1;
}

void Span::addNumber(int N) {
	if (_index() >= _len())
		throw std::runtime_error("Can't insert more numbers..");
	arr[_index()] = N;
	_incrIndex();
}

int	Span::shortestSpan() const {
	
	unsigned int pos1 = 0;
	unsigned int pos2 = 0;
	int	shortSpan = __INT_MAX__;
	int tmp;

	for (unsigned int i = 0; i < _index(); i++) {
		for (unsigned int y = 0; y < _index(); y++) {
			tmp = arr[i] - arr[y];
			if (tmp < 0)
				tmp *= -1;
			if (tmp < shortSpan && i != y) {
				shortSpan = tmp;
				pos1 = i;
				pos2 = y;
				if (!shortSpan)
					break;
			}
		}
	}
	std::cout << "==============================================" << std::endl;
	std::cout << std::right << std::setw(7) << pos1 << " |\t" << arr[pos1] << std::endl;
	std::cout << std::right << std::setw(7) << pos2 << " |\t" << arr[pos2] << std::endl;
	std::cout << "[\033[38;5;196mMin distance\033[0m : " << shortSpan << "]" << std::endl;
	std::cout << "==============================================" << std::endl;
	return (tmp); 
}

std::ostream &operator<<(std::ostream &out, const Span &arr)
{
	out << "[" << arr._index() << "/" << arr._len() << "]" << std::endl;
	out << "==============================================" << std::endl;
	for (unsigned int i = 0; i < arr._len(); i++) {
		if (i >= arr._index() + 5) {
			out << "    ... |\t..." << std::endl;
			break ;
		}
		out << std::right << std::setw(7) << i << " |";
		if (i < arr._index())
			out << "\033[38;5;196m";
		else
			out << "\033[38;5;118m";
		try {
			out << "\t" << arr.getNumber(i) << "\033[0m" << std::endl;
		} catch (const std::exception &e) {
			std::cerr << arr._len() << " " << arr._index() << " " << "Caught exception : " << e.what() << std::endl;
		}
	}
	arr.shortestSpan();
	return (out);
}

