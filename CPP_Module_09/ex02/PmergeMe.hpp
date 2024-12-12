/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:30:37 by tauer             #+#    #+#             */
/*   Updated: 2024/12/12 23:34:08 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <deque>
#include <climits>

#include <stdlib.h>
#include <stdbool.h>
class PmergeMe
{
  private:
	std::deque<int> orig;
	std::deque<int> final;
  public:
	PmergeMe(char **argv);
	~PmergeMe();

	void Sort();

	friend std::ostream &operator<<(std::ostream &out, const PmergeMe &src);
	
};
