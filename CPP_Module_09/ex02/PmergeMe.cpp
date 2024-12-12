/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:31:23 by tauer             #+#    #+#             */
/*   Updated: 2024/12/12 23:27:09 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int	InputChecker(char *input)
{
	long ret = -1;
	
	if (!input)
		throw(std::runtime_error("NULL INPUT !"));
	
	for(size_t i = 0; input[i]; i++)
		if (!isdigit(input[i]))
			throw(std::runtime_error(std::string("found a non numeric input : ") + input));
	ret = atol(input);
	if (ret > INT_MAX || ret < INT_MIN)
			throw(std::runtime_error(std::string("found a too large input : ") + input));
	return (ret);
}

void	PmergeMe::Sort() {
	
}

PmergeMe::PmergeMe(char **argv) {
	for (size_t i = 1; argv[i]; ++i) {
		try {
			orig.push_back(InputChecker(argv[i]));
		}	catch (std::exception &e) {
			std::cerr << "[Input " << i <<  "]" << e.what() << std::endl;   
		}
	}

	Sort();
}


PmergeMe::~PmergeMe() {
	
}

std::ostream &operator<<(std::ostream &out, const PmergeMe &arr) {
	out << "Original Array : \n";
	for(size_t i = 0; i < arr.orig.size(); i++)
		out << arr.orig[i] << " ";
	out << "\n";
	return out;
}
