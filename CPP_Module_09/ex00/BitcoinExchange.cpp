/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:52:43 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 17:49:37 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::~Btc() {
	
}

Btc::Btc(const std::string &inputFile) {
	
	std::ifstream inputF(inputFile.c_str());
	if (!inputF.is_open())
		throw std::runtime_error("failed to open InputFile !");
	std::string line;
	while (std::getline(inputF, line)) {
		arr.push_back(CryptoRate(line));
	}
	std::cout << "filled " << arr.size() << " lines of " << inputFile << std::endl;
}
