/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:45:00 by tauer             #+#    #+#             */
/*   Updated: 2024/11/25 15:57:35 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::~Span() {}

Span::Span() : arr(0){}

Span::Span(unsigned int N) :  arr(0), _max_size(N) {}

unsigned int Span::max_size() const {
	return (_max_size);
}

void Span::addNumber(int N) {
	if (arr.size() >= max_size())
		throw std::runtime_error("Cannot add more int in vector !");
	arr.push_back(N);
}

void Span::rotateVec() {
	if (arr.empty())
		return ;
	arr.push_back(arr[0]);
	arr.erase(arr.begin());
}

long getDist(int n1, int n2) {
    return abs(n1 - n2);
}

// long	Span::shortestSpan() const {
	

// 	if (!arr || _index() < 2 || arr[0] == arr[1])
// 		throw std::runtime_error("Cannot found shortest with < 1 int !");
	
// 	long	shortSpan = __LONG_MAX__;	
	
// 	std::vector<int> sortedArr(arr, arr + _index());
// 	std::sort(sortedArr.begin(), sortedArr.end());

	
// 	for (unsigned int i = 0; i < sortedArr.size() - 1; i++) {
// 		long tmp = getDist(sortedArr[i], sortedArr[i + 1]);
// 		if (tmp < shortSpan) {
// 			shortSpan = tmp;
// 		}
// 	}
	
// 	std::cout <<"[\033[38;5;196mMin distance\033[0m : " << shortSpan << "]" << std::endl;
// 	return (shortSpan); 
// }

// int	Span::biggestSpan() const {
	
// 	long	BigSpan = 0;

// 	if (!arr || _index() < 2 || arr[0] == arr[1])
// 		throw std::runtime_error("Cannot found biggest with < 1 int !");
	
// 	int minElement = *std::min_element(arr, arr + _index());
// 	int maxElement = *std::max_element(arr, arr + _index());
// 	BigSpan = getDist(minElement, maxElement);

// 	std::cout << "[\033[38;5;196mMax distance\033[0m : " << BigSpan << "]" << std::endl;
// 	return (BigSpan); 
// }

std::ostream &operator<<(std::ostream &out, const Span &arr)
{
	for(size_t i = 0 ; i < arr.arr.size() ; i++)
		out << "[" << i << " " << arr.arr[i] << "] ";
	out << std::endl;
	return (out);
}

