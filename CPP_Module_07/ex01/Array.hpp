/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:23 by tauer             #+#    #+#             */
/*   Updated: 2024/11/23 19:24:38 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template < typename T>

void iter(T *arr, size_t arr_len, void (*foo)(T &)) {
	if (!arr || !foo)
		return ;
	for (size_t i = 0; i < arr_len; ++i) {
		foo(arr[i]);
	}
}
