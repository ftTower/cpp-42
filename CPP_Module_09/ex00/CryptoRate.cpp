/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CryptoRate.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:26:18 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 19:26:59 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CryptoRate.hpp"

// class CryptoRate {
		
// 	private :
// 		std::string &data;
		
// 	public :
// 		CryptoRate(std::string &inputData);
// 		~CryptoRate();
// 		unsigned int getYear();
// 		unsigned int getMonth();
// 		unsigned int getDay();
// 		float getrate();
// };

CryptoRate::~CryptoRate() {
	
};

CryptoRate::CryptoRate(std::string &inputData, size_t pos) : data(inputData), _pos(pos) {
		data.erase(remove_if(data.begin(), data.end(), isspace), data.end());
		// std::cout << data << std::endl;
		if (data[4] != '-' || data[7] != '-')
			throw(std::runtime_error(YELLOW + data + END + " Date format invalid"));
		if (data[10] != '|' && data[10] != ',')
			throw(std::runtime_error(YELLOW + data + END + " Separator format invalid"));
};

unsigned int CryptoRate::getYear() {
	return atoi(data.substr(0, 4).c_str());
}

unsigned int CryptoRate::getMonth() {
	return atoi(data.substr(5, 9).c_str());
}


unsigned int CryptoRate::getDay() {
	return atoi(data.substr(9, 11).c_str());
}

float CryptoRate::getRate() {
	return atof(data.substr(9, data.size()).c_str());
}

