/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:11:21 by tauer             #+#    #+#             */
/*   Updated: 2024/11/23 18:37:53 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <iostream>

template <typename T>

const T &max(const T &x, const T &y)
{
	return (x >= y ? x : y);
}

template <typename U>

const U &min(const U &x, const U &y)
{
	return (x <= y ? x : y);
}

template <typename V>

void swap(V &x,V &y)
{
	V tmp = x;
	x = y;
	y = tmp;
}