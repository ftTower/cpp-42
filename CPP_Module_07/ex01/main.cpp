/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:04:28 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 02:22:56 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
// #include "../../CPP_Module_06/ex00/ScalarConverter.hpp"

void ft_plusOne(int &arr) {
	arr += 1;
}

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void	test_char()
{
	char a[] = {'A', 'B', 'C'};

	std::cout << "Original:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	::iter(a, sizeof(a) / sizeof(char), ft_tolower);

	std::cout << "Changed:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	::iter(a, 2, ft_toupper);

	std::cout << "Changed:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;
}

void	test_int()
{
	int arr[] = {10, 5, 6};

	std::cout << "Original:" <<
	"\n\ta[0]: " << arr[0] <<
	"\n\ta[1]: " << arr[1] <<
	"\n\ta[2]: " << arr[2] <<
	std::endl << std::endl;

	::iter(arr, 2, ft_plusOne);

	std::cout << "Changed:" <<
	"\n\ta[0]: " << arr[0] <<
	"\n\ta[1]: " << arr[1] <<
	"\n\ta[2]: " << arr[2] <<
	std::endl << std::endl;

}

int main()
{
	test_char();

	std::cout << "==========================" << std::endl;

	test_int();
}