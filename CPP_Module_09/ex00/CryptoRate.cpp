/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CryptoRate.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:26:18 by tauer             #+#    #+#             */
/*   Updated: 2024/11/29 23:08:48 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CryptoRate.hpp"
#include <cmath>     // Pour HUGE_VAL

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

unsigned int CryptoRate::getYear() const {
	if (!getData().empty())
		return atoi(getData().substr(0, 4).c_str());
	return 0;
}

unsigned int CryptoRate::getMonth() const {
	if (!getData().empty())
		return atoi(getData().substr(5, 2).c_str());
	return 0;
}


unsigned int CryptoRate::getDay() const {
	if (!getData().empty())
		return atoi(getData().substr(8, 2).c_str());
	return 0;
}

float CryptoRate::getRate()  const{
    if (getData().size() > 25)
		throw(std::runtime_error("Input tooooo long"));
	else if (!getData().empty()) {
        char *endptr;
        double tmp = std::strtod(getData().substr(11).c_str(), &endptr);
        
        if (endptr == getData().substr(11).c_str()) {
            std::cerr << "Erreur de conversion de chaîne en nombre" << std::endl;
            throw std::runtime_error("Erreur de conversion");
        }
        
        if (tmp == HUGE_VAL || tmp == -HUGE_VAL) {
            std::cout << tmp << " Input too big or too small!" << std::endl;
            throw std::runtime_error("Input too big or too small!");
        }

        if (tmp > std::numeric_limits<float>::max() || tmp < -std::numeric_limits<float>::max()) {
            std::cout << tmp << " Input too big or too small!" << std::endl;
            throw std::runtime_error("Input too big or too small!");
        }

        return static_cast<float>(tmp);
    }
    return 0;
}

std::string CryptoRate::getData() const {
	return (data);
}


