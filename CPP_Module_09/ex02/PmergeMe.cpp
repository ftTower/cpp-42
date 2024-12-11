/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:31:23 by tauer             #+#    #+#             */
/*   Updated: 2024/12/11 18:36:40 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


template <typename T>
PmergeMe<T>::PmergeMe(T &arr) {
	orig.insert(orig.end(), arr.begin(), arr.end());
}

template <typename T>

PmergeMe<T>::~PmergeMe() {
	
}

template <typename U>
std::ostream &operator<<(std::ostream &out, const PmergeMe<U> &arr) {
	out << "Original Array : \n";
	for(size_t i = 0; i < arr.orig.size(); i++)
		out << arr.orig[i] << " ";
	out << "\n";
	return out;
}
