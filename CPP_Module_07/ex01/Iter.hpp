/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:23 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 16:04:06 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template < typename T>

void iter(T *arr, long long arr_len, void (*foo)(T &)) {
	if (!arr || !foo || arr_len < 0)
		return ;
	for (size_t i = 0; i < (size_t)arr_len; ++i) {
		foo(arr[i]);
	}
}
