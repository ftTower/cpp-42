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

PmergeMe::PmergeMe(char **argv) {
	for (size_t i = 1; argv[i]; ++i) {
		try {
			_vector.push_back(InputChecker(argv[i]));
			_deque.push_back(InputChecker(argv[i]));
		}	catch (std::exception &e) {
			std::cerr << "[Input " << i <<  "]" << e.what() << std::endl;   
		}
	}
}


PmergeMe::~PmergeMe() {
	
}

void PmergeMe::displayOutput(char **argv) {
	//display input
	std::cout << "\t" << BLUE << "Before : " << END;
	for(size_t i = 1; argv[i]; i++) {
		if (i == 5 + 1) {
			std::cout << "\t...";
			break;
		}
		std::cout << RED << "\t" << atoi(argv[i]) ;
	}
	std::cout << END << "\n\t" << BLUE << "After  : " << END;
	//display output
	for(size_t i = 0; i < _vector.size(); i++) {
		if (i == 5) {
			std::cout << "\t...";
			break;
		}
		std::cout << GREEN << "\t" << _vector[i] ;
	}
	std::cout << END << "\n\n\t" << "[" << PURPLE << _vector.size() << END << WHITE << " Numbers"  << "]\n\n" << END;
	//display time
	std::cout << PURPLE << "\tVector :\t" << END << _vectorTime << " us\n";
	std::cout << PURPLE << "\tDeque  :\t" << END << _dequeTime << " us\n\n";
}

std::vector<size_t> JacobsthalSequence () {
	std::vector<size_t> jList;
	jList.push_back(0);
	jList.push_back(1);
	while(1) {
		size_t n = 2 * jList.back() - 1 + jList.back() - 2;
		if (n < jList.back() - 1)
			break ;
		jList.push_back(n);
	}
	return jList;
}

std::vector<size_t> PmergeMe::getJacobsthalNum() {
	return (JacobsthalSequence());
}


void PmergeMe::sortVector() {
	struct timeval start,end;
	
	gettimeofday(&start, NULL);

	this->Sort(_vector);
	
	gettimeofday(&end, NULL);
	_vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::sortDeque() {
	struct timeval start,end;
	gettimeofday(&start, NULL);
	
	this->Sort(_deque);
	
	gettimeofday(&end, NULL);
	_dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}	

std::ostream &operator<<(std::ostream &out, const PmergeMe &arr) {
	out << "In vector : \n\t";
	for(size_t i = 0; i < arr._vector.size(); i++)
		out << arr._vector[i] << " ";
	out << "\nIn deque : \n\t";
	for(size_t i = 0; i < arr._deque.size(); i++)
		out << arr._deque[i] << " ";
	out << "\n";
	return out;
}
