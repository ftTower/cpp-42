/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:52:43 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 19:30:35 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::~Btc() {
	
}

std::ostream &operator<<(std::ostream &out, CryptoRate &cR) {
	out << cR.getYear() << "-" << cR.getMonth() << "-" << cR.getDay() << " | " << cR.getRate() << std::endl;
	return (out);	
}

Btc::Btc(const std::string &inputFile) {
	
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
	std::cout << "Filled " << arr.size() << " lines of " << "data.csv" << std::endl;
	index = 0;
	std::ifstream inputF(inputFile.c_str());
	if (!inputF.is_open())
		throw std::runtime_error("Failed to open " + inputFile + " !");
	while (std::getline(inputF, line)) {
		try {
			CryptoRate cur(line, index++);
			
			std::cout << cur;
		} catch (std::exception &e){
			std::cerr << RED << "ERROR: l." << index << " data.csv : " << END  << e.what() << std::endl;
		}

	}
		
}

