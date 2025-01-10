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
#include <vector>
#include <climits>
#include <ctime>
#include <sys/time.h>

#include <stdlib.h>
#include <stdbool.h>

#define RED "\033[38;5;196m"
#define RED_BG "\033[48;5;196m"

#define GREEN "\033[38;5;34m"
#define GREEN_BG "\033[48;5;34m"

#define YELLOW "\033[38;5;220m"
#define YELLOW_BG "\033[48;5;220m"

#define PURPLE "\033[38;5;135m"

#define BLUE "\033[38;5;18m"
#define BLUE_BG "\033[48;5;18m"

#define WHITE "\033[38;5;195m"
#define WHITE_BG "\033[48;5;195m"

#define END "\033[0m"

class PmergeMe
{
  private:
	std::vector<int> _vector;
	std::deque<int> _deque;

	double _vectorTime;
	double _dequeTime;
	
  public:
	PmergeMe(char **argv);
	~PmergeMe();

	template <typename Container>
	void Sort(Container &container) {
		if (container.size() <= 1)
			return ;
		std::vector <int> left, right;
		
		for (size_t i = 0; i + 1 < container.size(); i+= 2) {
			if (container[i] <= container[i + 1]) {
				left.push_back(container[i]);
				right.push_back(container[i + 1]);
			} else {
				left.push_back(container[i + 1]);
				right.push_back(container[i]);
			}
		}
		
		if (container.size() % 2 != 0)
			left.push_back(container.back());
			
		Sort(right);
		const std::vector<size_t> &jList = getJacobsthalNum();
		size_t i = 0;
		
		while(left.size()) {
			size_t toInsert;
			if (i + 2 >= jList.size())
				toInsert = jList[jList.size() - 1];
			else
				toInsert = jList[i + 2];
			i++;
			if (toInsert >= left.size())
				toInsert = left.size() - 1;
			std::vector<int>::iterator pos = std::lower_bound(right.begin(), right.end(), left[toInsert]);
			right.insert(pos, left[toInsert]);
			left.erase(left.begin() + toInsert);
		}
		container.assign(right.begin(), right.end());
	}

	void sortVector();
	void sortDeque();
	
	void displayOutput(char **argv);
	
	friend std::ostream &operator<<(std::ostream &out, const PmergeMe &src);
	
};
