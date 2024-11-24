/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:43:45 by tauer             #+#    #+#             */
/*   Updated: 2024/11/24 03:20:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> class Array
{
  private:
	T *arr;
	size_t len;

  public:
  
	size_t size() const {
		return (len);
	}
	
	~Array() {
		delete[] arr;
	}
	
	Array() : arr(NULL), len(0) {}

	Array(unsigned int n) : arr(new T[n]), len(n) {
		for(size_t i = 0; i < len; i++) {
			arr[i] = T();
		}
	}

	Array(Array &other) : arr(new T[other.len]), len(other.len){
		for(size_t i = 0; i < len; i++) {
			arr[i] = other.arr[i];
		}
	}

	Array &operator=(const Array &other) {
		if (this != &other) {
			delete[] arr;
			len = other.len;
			arr = new T[other.len];
			for (size_t i = 0; i < len; i++)
				arr[i] = other.arr[i];
		}
		return (*this);
	}

	T& operator[](size_t index) {
		if (index >= size())
			throw std::out_of_range("Index out of range");
		return (arr[index]);
	}

	void setT(T ptr, size_t pos)
	{
		if (!ptr || !this->arr || pos >= size())
			return ;
		this->arr[pos] = ptr;
	}

	T *getT()
	{
		return (this->arr);
	}

	void displayTArr()
	{
		if (!getT())
			return ;
		for (size_t i = 0; i < size(); i++)
			std::cout << "[" << i << ":" << arr[i] << "]" << " ";
		std::cout << std::endl;
	}

};
