/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CryptoRate.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:26:18 by tauer             #+#    #+#             */
/*   Updated: 2024/11/28 17:34:29 by tauer            ###   ########.fr       */
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
		if (getData()[4] != '-' || getData()[7] != '-')
			throw(std::runtime_error(YELLOW + data + END + " Date format invalid"));
		else if (data[10] != '|' && data[10] != ',')
			throw(std::runtime_error(YELLOW + data + END + " Separator format invalid"));
		else if (getMonth() < 1 || getMonth() > 12)
			throw(std::runtime_error(YELLOW + data + END + " Month format invalid"));
		else if (getDay() < 1 || getDay() > 31)
			throw(std::runtime_error(YELLOW + data + END + " Day format invalid"));
};

unsigned int CryptoRate::getYear() {
	if (!getData().empty())
		return atoi(getData().substr(0, 4).c_str());
	return 0;
}

unsigned int CryptoRate::getMonth() {
	if (!getData().empty())
		return atoi(getData().substr(5, 2).c_str());
	return 0;
}


unsigned int CryptoRate::getDay() {
	if (!getData().empty())
		return atoi(getData().substr(8, 2).c_str());
	return 0;
}

float CryptoRate::getRate() {
	if (!getData().empty())
		return std::atof(getData().substr(11, 2).c_str());
	return 0;
}

std::string CryptoRate::getData() {
	return (data);
}
