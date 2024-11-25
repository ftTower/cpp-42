/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:39:46 by tauer             #+#    #+#             */
/*   Updated: 2024/11/25 18:06:54 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

class Span
{
  private:
	std::vector<int> arr;
	unsigned int _max_size;

	Span();

  public:
	Span(unsigned int N);
	~Span();

	void addNumber(int N);

	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end) {
		if (std::distance(begin, end) > static_cast<int>(max_size() - arr.size()))
			throw std::runtime_error("Destination max size < input size !\n");
		arr.insert(arr.begin(), begin, end);
	}
	
	void rotateVec();
	unsigned int max_size() const;

	long shortestSpan() const;
	long biggestSpan() const;
	friend std::ostream &operator<<(std::ostream &out, const Span &arr);
};
