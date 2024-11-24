/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:43:08 by tauer             #+#    #+#             */
/*   Updated: 2024/11/24 02:31:11 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main() {
    try {
        // Test 1: Construction par défaut
        Array<int> emptyArray;
        std::cout << "Test 1: Size of emptyArray: " << emptyArray.size() << std::endl;

        // Test 2: Construction avec une taille donnée
        unsigned int size = 5;
        Array<int> intArray(size);
        std::cout << "Test 2: Size of intArray: " << intArray.size() << std::endl;

        // Initialisation et affichage des valeurs
        for (unsigned int i = 0; i < size; ++i) {
            intArray[i] = i * 10; // Remplir l'array avec des valeurs
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        // Test 3: Construction par copie
        Array<int> copyArray(intArray);
        std::cout << "Test 3: Copying intArray to copyArray..." << std::endl;
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
        }

        // Modification d'une copie et vérification d'indépendance
        copyArray[0] = 1000;
        std::cout << "Modified copyArray[0] = " << copyArray[0] << std::endl;
        std::cout << "Original intArray[0] (should remain unchanged) = " << intArray[0] << std::endl;

        // Test 4: Opérateur d'affectation
        Array<int> assignedArray = intArray;
        std::cout << "Test 4: Assigning intArray to assignedArray..." << std::endl;
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
        }

        // Test 5: Accès hors limites
        std::cout << "Test 5: Accessing out-of-bounds index..." << std::endl;
        std::cout << intArray[size] << std::endl; // Devrait lancer une exception
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}