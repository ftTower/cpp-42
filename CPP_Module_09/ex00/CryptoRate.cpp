/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CryptoRate.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:26:18 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 17:52:37 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

CryptoRate::CryptoRate(std::string &inputData) : data(inputData) {
		remove_if(data.begin(), data.end(), isspace);
		// std::cout << data << std::endl;
};