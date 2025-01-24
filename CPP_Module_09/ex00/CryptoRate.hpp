/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CryptoRate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:19:18 by tauer             #+#    #+#             */
/*   Updated: 2024/11/29 23:08:26 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>

#define RED "\033[38;5;196m"
#define GREEN "\033[38;5;34m"
#define YELLOW "\033[38;5;220m"
#define PURPLE "\033[38;5;135m"
#define BLUE "\033[38;5;18m"
#define WHITE "\033[38;5;195m"

#define RED_BG "\033[48;5;196m"
#define GREEN_BG "\033[48;5;34m"
#define YELLOW_BG "\033[48;5;220m"
#define PURPLE_BG "\033[48;5;135m"
#define BLUE_BG "\033[48;5;18m"
#define WHITE_BG "\033[48;5;195m"


#define END "\033[0m"


class CryptoRate
{
  private:
	std::string data;
	size_t _pos;

  public:
	CryptoRate(std::string &inputData, size_t pos);
	~CryptoRate();
	
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	float 		 getRate() const;

	std::string  getData() const;
	
};

std::ostream& operator<<(std::ostream& os, const CryptoRate& rate);

