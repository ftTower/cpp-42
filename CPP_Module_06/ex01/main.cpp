/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:12:10 by tauer             #+#    #+#             */
/*   Updated: 2024/11/23 16:05:15 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	std::string buf(argv[1]);
	Data *data = new Data(buf);

	uintptr_t tmp = Serializer::serialize(data);

	std::cout << "\033[38;5;96m[" << data->getName() \
	<< "]\033[0m \nlocated      : " << (uintptr_t)data \
	<< " \nserialised   : " << tmp << std::endl;

	delete (data);
	data = Serializer::deserialize(tmp);
	std::cout << "deserialized : " << (uintptr_t)data << std::endl;
	return (0);
}