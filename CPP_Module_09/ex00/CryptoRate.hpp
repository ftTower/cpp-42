/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CryptoRate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:19:18 by tauer             #+#    #+#             */
/*   Updated: 2024/11/29 01:10:45 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define RED "\033[38;5;196m"
#define GREEN "\033[38;5;34m"
#define YELLOW "\033[38;5;220m"
#define END "\033[0m"


class CryptoRate
{
  private:
	std::string data;
	size_t _pos;

  public:
	CryptoRate(std::string &inputData, size_t pos);
	~CryptoRate();
	
	unsigned int getYear();
	unsigned int getMonth();
	unsigned int getDay();
	float 		 getRate();

	std::string  getData();
	
};

std::ostream& operator<<(std::ostream& os, const CryptoRate& rate);

