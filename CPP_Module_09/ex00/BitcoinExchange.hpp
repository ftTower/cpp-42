/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:33:40 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 19:21:43 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CryptoRate.hpp"

class Btc
{
  private:
	std::vector<CryptoRate> arr;
	Btc();

  public:
	Btc(const std::string &inputFile);
	~Btc();
};

