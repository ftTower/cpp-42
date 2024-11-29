/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:52:43 by tauer             #+#    #+#             */
/*   Updated: 2024/11/29 23:12:07 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>

float	calculateBTC(float value, float input)
{
	if (value == 0.0f)
		return (0.0f);
	return (value / input);
}

int	dateToDays(CryptoRate &date)
{
	return (date.getYear() * 365 + date.getMonth() * 30 + date.getDay());
}

unsigned int	getNearestDate(std::vector<CryptoRate> arr, CryptoRate &input)
{
	int				inputDays;
	unsigned int	nearestIndex;
	int				smallestDiff;
	int				currentDiff;

	if (arr.empty())
		return (-1);
	inputDays = dateToDays(input);
	nearestIndex = 0;
	smallestDiff = std::abs(dateToDays(arr[0]) - inputDays);
	for (unsigned int i = 1; i < arr.size(); ++i)
	{
		currentDiff = std::abs(dateToDays(arr[i]) - inputDays);
		if (currentDiff < smallestDiff)
		{
			smallestDiff = currentDiff;
			nearestIndex = i;
		}
	}
	return (nearestIndex);
}

Btc::~Btc()
{
}

std::ostream &operator<<(std::ostream &out, CryptoRate &cR)
{
	unsigned int	tmp;

	out << cR.getYear() << "-";
	tmp = cR.getMonth();
	if (tmp < 10)
		out << "0";
	out << tmp << "-";
	tmp = cR.getDay();
	if (tmp < 10)
		out << "0";
	out << tmp << " | " << cR.getRate();
	return (out);
}

void	displayDate(CryptoRate &value)
{
	std::cout << YELLOW << "|" << END << WHITE << value.getYear() << "-";
	if (value.getMonth() < 10)
		std::cout << "0";
	std::cout << value.getMonth() << "-";
	if (value.getDay() < 10)
		std::cout << "0";
	std::cout << value.getDay() << END;
}

void	displayWallet(CryptoRate &value, CryptoRate &input)
{
	displayDate(input);
	std::cout << " ";
	displayDate(value);
	std::cout << " " << std:: fixed << std::setprecision(2) << value.getRate();
	std::cout << YELLOW << "|" << END;
	std::cout << " " << BLUE_BG << std::setprecision(10) << calculateBTC(value.getRate(),
		input.getRate()) << " Btc" << END;
	std::cout << std::endl;
}

Btc::Btc(const std::string &inputFile) : arr()
{
	size_t	index;

	std::ifstream dataBase("data.csv");
	if (!dataBase.is_open())
		throw std::runtime_error("Failed to open Data base !");
	std::string line;
	index = 0;
	while (std::getline(dataBase, line))
	{
		try
		{
			arr.push_back(CryptoRate(line, index++));
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "ERROR: l." << index << " data.csv : " << END << e.what() << std::endl;
		}
	}
	if (arr.empty())
		throw std::runtime_error("Empty Data base !");
	std::cout << GREEN << "Database successfully imported !" << END << std::endl;
	index = 0;
	std::ifstream inputF(inputFile.c_str());
	if (!inputF.is_open())
		throw std::runtime_error("Failed to open " + inputFile + " !");
	while (std::getline(inputF, line))
	{
		try
		{
			CryptoRate cur(line, index++);
			displayWallet(arr[getNearestDate(arr, cur)], cur);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "ERROR: l." << index << " " << inputFile << " : " << END << e.what() << std::endl;
		}
	}
}
