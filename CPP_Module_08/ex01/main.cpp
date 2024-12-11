/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:39:50 by tauer             #+#    #+#             */
/*   Updated: 2024/12/11 15:55:58 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <sys/wait.h>
#include <climits>

void basicNumbers() {
	std::cout << "============================" << std::endl;
	Span sp = Span(10);

	sp.addNumber(0);
	sp.addNumber(10);
	sp.addNumber(20);
	sp.addNumber(30);
	sp.addNumber(40);
	sp.addNumber(50);
	sp.addNumber(60);
	std::cout << "\033[38;5;5mbasicNumbers\033[0m " << sp;
}

void basicNumbersWithNegativ() {
	std::cout << "============================" << std::endl;
	Span sp = Span(10);

	sp.addNumber(0);
	sp.addNumber(5);
	sp.addNumber(-20);
	sp.addNumber(30);
	sp.addNumber(40);
	sp.addNumber(-50);
	sp.addNumber(60);
	sp.addNumber(-120);
	std::cout << "\033[38;5;5mbasicNumbersWithNegativ\033[0m " << sp;
}

void bigNumbersWithNegativ() {
	std::cout << "============================" << std::endl;
	Span sp = Span(10);

	sp.addNumber(1111110);
	sp.addNumber(16515);
	sp.addNumber(-242340);
	sp.addNumber(3053235);
	sp.addNumber(406346);
	sp.addNumber(-50634231);
	sp.addNumber(605352);
	sp.addNumber(-12021);
	std::cout << "\033[38;5;5mbigNumbersWithNegativ\033[0m " << sp;
}

void maxNumbers() {
	std::cout << "============================" << std::endl;
	Span sp = Span(10);

	sp.addNumber(0);
	sp.addNumber(INT_MAX);
	sp.addNumber(INT_MIN);
	std::cout << "\033[38;5;5mmaxNumbers\033[0m " << sp;
}

void insertRange() {
	std::cout << "============================" << std::endl;
	Span sp(10);
	
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(40);
	vec.push_back(3504);
	vec.push_back(-10);
	vec.push_back(0);

    
	sp.addNumbers(vec.begin(), vec.end());
	
	std::cout << "\033[38;5;5minsertRange\033[0m " << sp;
}

void insertRangeTooMuch() {
	std::cout << "============================" << std::endl;
	Span sp(3);
	
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(40);
	vec.push_back(3504);
	vec.push_back(-10);
	vec.push_back(0);

	try {
		sp.addNumbers(vec.begin(), vec.end());
	} catch (std::exception &e) {
		std::cerr << "Caught an error : " << e.what() << std::endl;
	}
	
	std::cout << "\033[38;5;5minsertRangeTooMuch\033[0m " << sp;
}

void tooMuchNumbers() {
	std::cout << "============================" << std::endl;
	Span sp = Span(5);

	try {
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(10);
	} catch (std::exception &e) {
		std::cerr << "Caught an error : " << e.what() << std::endl;
	}


	std::cout << "\033[38;5;5mtooMuchNumbers\033[0m " << sp;
}

void oneNumbers() {
	std::cout << "============================" << std::endl;
	Span sp = Span(10);

	sp.addNumber(10);

	std::cout << "\033[38;5;5moneNumbers\033[0m " << sp;
}

void noNumbers() {
	std::cout << "============================" << std::endl;
	Span sp = Span(10);
	std::cout << std::endl << "\033[38;5;5mnoNumbers\033[0m "  << sp;
}

int	main(void)
{
	basicNumbers();
	basicNumbersWithNegativ();
	bigNumbersWithNegativ();
	maxNumbers();
	insertRange();
	insertRangeTooMuch();
	tooMuchNumbers();
	oneNumbers();
	noNumbers();
	return (0);
}
