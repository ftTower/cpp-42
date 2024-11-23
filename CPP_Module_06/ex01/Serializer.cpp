/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:06:36 by tauer             #+#    #+#             */
/*   Updated: 2024/11/23 16:04:01 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
		return reinterpret_cast<uintptr_t>(ptr);	
}

Data* Serializer::deserialize(uintptr_t raw) {
		return reinterpret_cast<Data *>(raw);	
}