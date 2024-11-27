/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:33:40 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 17:44:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define RED "\033[38;5;196m"
#define END "\033[0m"



class CryptoRate {
		
	private :
		std::string &data;
		
	public :
		CryptoRate(std::string &inputData);
		~CryptoRate();
		unsigned int getYear();
		unsigned int getMonth();
		unsigned int getDay();
		float getrate();
};

class Btc {

	private :
		std::vector<CryptoRate> arr;
		Btc();
		
	public :
		Btc(const std::string &inputFile);
		~Btc();
		
};