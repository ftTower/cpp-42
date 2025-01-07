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
		 std::sort(container.begin(), container.end());

		 
	}

	void sortVector();
	void sortDeque();
	
	void displayOutput(char **argv);
	
	friend std::ostream &operator<<(std::ostream &out, const PmergeMe &src);
	
};
