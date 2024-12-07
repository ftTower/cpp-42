/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:43:08 by tauer             #+#    #+#             */
/*   Updated: 2024/12/07 02:26:00 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main() {
    try {
        Array<int> emptyArray;
        std::cout << "Test 1: Size of emptyArray: " << emptyArray.size() << std::endl;

        unsigned int size = 5;
        Array<int> intArray(size);
        std::cout << "Test 2: Size of intArray: " << intArray.size() << std::endl;

        for (unsigned int i = 0; i < size; ++i) {
            intArray[i] = i * 10; 
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        Array<int> copyArray(intArray);
        std::cout << "Test 3: Copying intArray to copyArray..." << std::endl;
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
        }

        copyArray[0] = 1000;
        std::cout << "Modified copyArray[0] = " << copyArray[0] << std::endl;
        std::cout << "Original intArray[0] (should remain unchanged) = " << intArray[0] << std::endl;

        Array<int> assignedArray = intArray;
        std::cout << "Test 4: Assigning intArray to assignedArray..." << std::endl;
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
        }

        std::cout << "Test 5: Accessing out-of-bounds index..." << std::endl;
        std::cout << intArray[size] << std::endl; 
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

// #include <iostream>
// #include "Array.hpp"
// #include <stdlib.h>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }