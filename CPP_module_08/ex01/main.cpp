/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:39:50 by tauer             #+#    #+#             */
/*   Updated: 2024/11/25 16:03:41 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <sys/wait.h>

// ./Span shortest distance biggest distance numbers.. 

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cerr << "not enough args !" << std::endl, 1);
	(void)argv;
	
	Span sp = Span(argc - 1);
	
	try {
		for(unsigned int i = 1; argv[i]; i++)
			sp.addNumber(atoi(argv[i]));
		std::cout << sp;
	} catch (std::exception & e) {
		std::cerr << "Caught exeption :" << e.what() << std::endl;
	}
	
	// while(1) {
	// 	std::cout << "\033c" <<  sp;
	// 	sp.rotateVec();		
	// 	sleep(1);
	// }

	return (0);
}
