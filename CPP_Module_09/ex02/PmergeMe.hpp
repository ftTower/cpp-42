/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:30:37 by tauer             #+#    #+#             */
/*   Updated: 2024/12/12 00:57:48 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdlib.h>

template <typename T>

class PmergeMe
{
  private:
	std::vector<int> orig;
  public:
	PmergeMe(char **argv);
	~PmergeMe();

	template <class U>
	friend std::ostream &operator<<(std::ostream &out, const PmergeMe<U> &arr);
	
};
