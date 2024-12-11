/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:30:37 by tauer             #+#    #+#             */
/*   Updated: 2024/12/11 18:43:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

template <typename T>

class PmergeMe
{
  private:
	std::vector<int> orig;
  public:
	PmergeMe(T &arr);
	~PmergeMe();

	template <class U>
	friend std::ostream &operator<<(std::ostream &out, const PmergeMe<U> &arr);
	
};
