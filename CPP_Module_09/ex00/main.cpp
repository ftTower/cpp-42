/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:33:57 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 17:19:31 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./BitcoinExchange.hpp"

// Assuming Btc is a function declared in BitcoinExchange.hpp
// void Btc(const char* path);

int		main(int argc, char **argv) {
	if (argc != 2) {
		return (std::cerr << RED << "ERROR : "  << END << argv[0] << " <path>" << std::endl, 1);
	}
	try {
		Btc btc(argv[1]);	
		
	}catch (std::exception &e) {
		std::cerr << RED << "ERROR : "<< END << e.what() << std::endl;
	}
	return (0);
}