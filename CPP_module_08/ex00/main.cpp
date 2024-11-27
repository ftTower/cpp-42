/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:11:10 by tauer             #+#    #+#             */
/*   Updated: 2024/11/24 03:41:22 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    try {
        // Initialisation d'un std::vector
        int vec_values[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(vec_values, vec_values + sizeof(vec_values) / sizeof(int));
        easyfind(vec, 3);  // Devrait trouver la valeur
        easyfind(vec, 10); // Devrait lever une exception

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Initialisation d'un std::list
        int lst_values[] = {10, 20, 30, 40};
        std::list<int> lst(lst_values, lst_values + sizeof(lst_values) / sizeof(int));
        easyfind(lst, 20); // Devrait trouver la valeur
        easyfind(lst, 5);  // Devrait lever une exception

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
