/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:01:54 by tauer             #+#    #+#             */
/*   Updated: 2024/12/11 15:43:15 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

class ValueNotFoundException : public std::exception {
		public:
			virtual const char *what () const throw() {
					return ("Value not found in container");
			};
};

template <typename T>
typename T::iterator easyfind(T &arr, int value) {
	typename T::iterator it = std::find(arr.begin(), arr.end(), value);
	if (it == arr.end())
		throw ValueNotFoundException();
	std::cout << "Value " << value << " found in arr" << std::endl;
	return (it);
};