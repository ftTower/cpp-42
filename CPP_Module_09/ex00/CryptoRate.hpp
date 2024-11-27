/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CryptoRate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:19:18 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 19:22:14 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#define RED "\033[38;5;196m"
#define YELLOW "\033[38;5;220m"
#define END "\033[0m"


class CryptoRate
{
  private:
	std::string &data;
	size_t _pos;

  public:
	CryptoRate(std::string &inputData, size_t pos);
	~CryptoRate();
	
	unsigned int getYear();
	unsigned int getMonth();
	unsigned int getDay();
	float getRate();

	void	setPos(size_t pos);
	size_t 	pos();
		
};

std::ostream& operator<<(std::ostream& os, const CryptoRate& rate);

