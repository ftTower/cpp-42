/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:52:43 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 21:46:41 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>

Btc::~Btc() {
	
}

std::ostream &operator<<(std::ostream &out, CryptoRate &cR) {
	
	out << cR.getYear() << "-";
	
	unsigned int tmp = cR.getMonth();
	if (tmp < 10)
		out << "0";
	out << tmp << "-";

	tmp = cR.getDay();
	if (tmp < 10)
		out << "0";
	out << tmp << " | " << 	cR.getRate();
	return (out);	
}


Btc::Btc(const std::string &inputFile) : arr() {

	std::ifstream dataBase("data.csv");
	if (!dataBase.is_open())
		throw std::runtime_error("Failed to open Data base !");
	std::string line;
	size_t index = 0;
	while (std::getline(dataBase, line)) {
		try {
			arr.push_back(CryptoRate(line, index++));			
		} catch (std::exception &e){
			std::cerr << RED << "ERROR: l." << index << " data.csv : " << END  << e.what() << std::endl;
		}
	}
	if (arr.empty())
		throw std::runtime_error("Empty Data base !");
		
	std::cout << GREEN << "Database successfully imported !" << END << std::endl;
	
	index = 0;
	std::ifstream inputF(inputFile.c_str());
	if (!inputF.is_open())
		throw std::runtime_error("Failed to open " + inputFile + " !");
	while (std::getline(inputF, line)) {
		try {
			CryptoRate cur(line, index++);
			
			std::cout << cur << std::endl;
		} catch (std::exception &e){
			std::cerr << RED << "ERROR: l." << index << " " << inputFile << " : " << END  << e.what() << std::endl;
		}

	}
		
}

