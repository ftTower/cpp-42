/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:37:49 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 03:07:44 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << RED << "ERROR : ./RPN <.. .. + .. - >"
		 << END << std::endl, 1);
	// (void)argv;
	try
	{
		RPN rpn(argv[1]);

		rpn.displayArr();

		// std::cout << rpn.calculateInput() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "ERROR :" << e.what() << END << std::endl;
	}

	return (0);
}