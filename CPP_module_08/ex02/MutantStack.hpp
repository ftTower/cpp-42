/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 01:15:08 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 01:38:08 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public :
		typedef typename std::deque<T>::iterator iterator;
    	typedef typename std::deque<T>::const_iterator const_iterator;
    	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
		
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return (*this);
		}

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		
		const_iterator begin() const { return this->c.begin();}
		const_iterator end() const { return this->c.end();}

		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}		

		const_reverse_iterator rbegin() const {return this->c.rbegin();}
		const_reverse_iterator rend() const {return this->c.rend();}		
		
		~MutantStack() {};
};