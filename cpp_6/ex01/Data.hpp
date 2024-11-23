/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:19:07 by tauer             #+#    #+#             */
/*   Updated: 2024/11/23 15:24:43 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

class Data {
	private :
		std::string name;
	public 	:
		Data();
		Data(const std::string &name);
		~Data();
		std::string getName();
		void  setName(std::string Name);
};