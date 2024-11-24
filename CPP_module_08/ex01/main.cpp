/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:39:50 by tauer             #+#    #+#             */
/*   Updated: 2024/11/24 23:35:41 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span sp = Span(100);
	try {
		sp.addNumber(6);
		sp.addNumber(11);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		
	} catch (std::exception & e) {
		std::cerr << "Caught exeption :" << e.what() << std::endl;
	}
	
	std::cout << sp;
	return (0);
}