/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:19:58 by tauer             #+#    #+#             */
/*   Updated: 2024/11/23 15:50:10 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data::Data() {
	this->name = "Default";
}

Data::Data(const std::string &Name) {
	this->name = Name;
}

Data::~Data() {
	
}

std::string Data::getName() {
	return (this->name);
}

void	Data::setName(std::string Name) {
	this->name = Name;
}