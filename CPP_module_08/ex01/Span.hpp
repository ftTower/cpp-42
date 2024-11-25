/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:39:46 by tauer             #+#    #+#             */
/*   Updated: 2024/11/25 15:56:10 by tauer            ###   ########.fr       */
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
	void rotateVec();
	unsigned int max_size() const;

	// long shortestSpan() const;
	// int biggestSpan() const;
	friend std::ostream &operator<<(std::ostream &out, const Span &arr);
};
