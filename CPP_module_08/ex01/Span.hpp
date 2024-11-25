/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:39:46 by tauer             #+#    #+#             */
/*   Updated: 2024/11/25 01:30:16 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
class Span {

	private :
		int *arr;
		unsigned int len;
		unsigned int index;
		Span();
		
	public :

	Span(unsigned int N);
	~Span();

	void addNumber(int N) ;
	int	 getNumber(unsigned int pos) const;
	unsigned int _len() const;
	unsigned int _index() const;
	void		_incrIndex() ;

	long	shortestSpan() const;
	int biggestSpan() const ;
	friend std::ostream &operator<<(std::ostream &out, const Span &arr);
};

