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
		std::cout << RED_BG << "STARTING SORT" << END << std::endl;
		// std::sort(container.begin(), container.end());
		
		
		//? rest value and bool for unpair rest
		std::pair<int, bool> unpairRest;
		unpairRest.first = 0;
		unpairRest.second = false;
		
		
		//!make pairs
		std::vector<std::pair<int, int> > pairsList;
		if (container.size() % 2 != 0) {
			unpairRest.first = container.back();
			unpairRest.second = true;
		}
		for(size_t i = 0; i < container.size(); i += 2) {
			if (i + 1 < container.size()) {
				pairsList.push_back(std::make_pair(container[i], container[i + 1]));
				if (pairsList.back().second < pairsList.back().first)
					std::swap(pairsList.back().second, pairsList.back().first);
			}
		}
		
		//*print pairs
		for(size_t i = 0; i < pairsList.size(); i++) {
			std::cout << GREEN_BG << pairsList[i].first << "  " << pairsList[i].second << END << " ";
		}
		std::cout << std::endl;
		if (unpairRest.second)
			std::cout << YELLOW_BG << unpairRest.first << END << std::endl;
		

		

		 (void)unpairRest;
	}

	void sortVector();
	void sortDeque();
	
	void displayOutput(char **argv);
	
	friend std::ostream &operator<<(std::ostream &out, const PmergeMe &src);
	
};
