/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:10:17 by tauer             #+#    #+#             */
/*   Updated: 2024/12/05 21:27:26 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void) {
	srand(time(NULL));

	std::cout << "new ";
	int n = rand() % 3;
	if (!n)
		return (std::cout << "A\n",new(A));
	else if (n == 1)
		return (std::cout << "B\n",new(B));
	else if (n == 2)
		return (std::cout << "C\n",new(C));
	return (NULL);		
}

void	identify(Base *ptr) {
	std::cout << "is a : ";
	if (!ptr)
		return (std::cout << "NULL ptr\n", (void)NULL);
	if (dynamic_cast<A *>(ptr))
		std::cout << "A ptr\n";
	else if (dynamic_cast<B *>(ptr))
		std::cout << "B ptr\n";
	else if (dynamic_cast<C *>(ptr))
		std::cout << "C ptr\n";	
}

void	identify(Base &ref) {
	std::cout << "is a : ";
	try {
		A &a = dynamic_cast<A &>(ref);
		(void)a;
		std::cout << "A ref\n";
	}
	catch(const std::exception &e) {}
	try {
		B &b = dynamic_cast<B &>(ref);
		(void)b;
		std::cout << "B ref\n";
	}
	catch(const std::exception &e) {}
	try {
		C &c = dynamic_cast<C &>(ref);
		(void)c;
		std::cout << "C ref\n";
	}
	catch(const std::exception &e) {}
	std::cout << std::endl;
}

int	main(void) {
	Base *ptr = generate();
	if (!ptr)
		return (1);
	// ptr = NULL;
	identify(ptr);
	identify(*ptr);
	delete(ptr);
	return (0);
}