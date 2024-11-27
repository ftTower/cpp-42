/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:45:00 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 01:10:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::~Span()
{
}

Span::Span() : arr(0)
{
}

Span::Span(unsigned int N) : arr(0), _max_size(N)
{
}

unsigned int Span::max_size() const
{
	return (_max_size);
}

void Span::addNumber(int N)
{
	if (arr.size() >= max_size())
		throw std::runtime_error("Cannot add more int in vector !\n");
	arr.push_back(N);
}

void Span::rotateVec()
{
	if (arr.empty())
		return ;
	arr.push_back(arr[0]);
	arr.erase(arr.begin());
}

long	getDist(int n1, int n2)
{
	return (std::abs((long)n1 - (long)n2));
}

long Span::shortestSpan() const
{
	if (arr.empty() || arr.size() < 2)
		throw std::runtime_error("Cannot found shortest with < 1 int !\n");
	long shortSpan = __LONG_MAX__;
	std::vector<int> sortedArr(arr);
	std::sort(sortedArr.begin(), sortedArr.end());
	for (unsigned int i = 0; i < sortedArr.size() - 1; i++)
	{
		long tmp = getDist(sortedArr[i], sortedArr[i + 1]);
		if (tmp < shortSpan)
		{
			shortSpan = tmp;
		}
	}
	return (shortSpan);
}

long Span::biggestSpan() const
{
	if (arr.empty() || arr.size() < 2)
		throw std::runtime_error("Cannot found biggest with < 1 int !\n");
	return (getDist(*std::min_element(arr.begin(), arr.end()),
			*std::max_element(arr.begin(), arr.end())));
}

std::ostream &operator<<(std::ostream &out, const Span &arr)
{
	out << std::endl;
	for (size_t i = 0; i < arr.arr.size(); i++)
	{
		out << "[\033[38;5;1m" << i << "\033[0m:\033[38;5;17m" << arr.arr[i] << "\033[0m] ";
		if (!((i + 1) % 3))
			out << std::endl;	
	}
	try
	{
		out << std::endl << "min distance : " << arr.shortestSpan();
		out << std::endl << "maxx distance : " << arr.biggestSpan() << std::endl << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (out);
}
