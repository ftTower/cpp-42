/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:30:54 by tauer             #+#    #+#             */
/*   Updated: 2024/12/12 23:16:08 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ./PmergeMe `shuf -i 1-100000 -n 10 | tr "\n" " "`

int	main(int argc, char **argv) {

	if (argc < 2)
		return (1);

	PmergeMe pm(argv);
	
	// pm.sortDeque();
	pm.sortVector();

	pm.displayOutput(argv);

	// std::cout << pm << std::endl;
	return (0);
}