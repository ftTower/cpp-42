/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:45:32 by tauer             #+#    #+#             */
/*   Updated: 2024/11/30 02:11:10 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isOperand(int op) {
	switch (op)
	{
		case '+':
		case '-':
		case '/':
		case '*':
		return (true);
	default:
		return (false);
	}
}

RPN::~RPN() {}

RPN::RPN(const std::string &input) {
	for (size_t i = 0; i < input.size(); i++) {
		if (isspace(input[i]))
			continue;
		else if (isdigit(input[i]))
			arr.push_back(input[i] - '0');
		else if (isOperand(input[i]))
			arr.push_back(input[i]);
		else
			throw std::runtime_error("wrong operator in input !");
	}
	std::cout << std::endl;
}

void RPN::displayArr() const {
	if (arr.empty())
		throw std::runtime_error("Empty array !");
	
	std::cout << "Inputed : |";
	for(size_t i = 0; i < arr.size(); i++) {
		if (arr[i] >= 0 && arr[i] <= 9)
			std::cout << arr[i] << "|";
		else
			std::cout << (char)arr[i] << "|";
	}
	std::cout << std::endl;
}

int	calculateNumbers(int nb1, int nb2, char op) {
	switch (op) {
		case '+' :
			return (nb1 + nb2);
		case '-' :
			return (nb1 - nb2);
		case '*' :
			return (nb1 * nb2);
		case '/' :
			return (nb1 / nb2);
		default :
			throw std::runtime_error("wrong operator in input !");
	}
	return (0);
}

int RPN::calculateInput() {
    while (arr.size() > 1) {
        size_t i = 0;
        // Parcourir la pile pour trouver un opérateur
        while (i < arr.size() && !isOperand(arr[i])) {
            i++;
        }

        if (i >= arr.size()) {
            throw std::runtime_error("No operator found or insufficient operands!");
        }

        // On a trouvé un opérateur, effectuer le calcul
        int op = arr[i];
        if (i < 2) {
            throw std::runtime_error("Insufficient operands for calculation!");
        }

        int n1 = arr[i - 2];
        int n2 = arr[i - 1];

        // Remplacer dans la pile
        arr.erase(arr.begin() + i - 2, arr.begin() + i + 1); // Supprimer n1, n2 et op
        arr.insert(arr.begin() + i - 2, calculateNumbers(n1, n2, op)); // Ajouter le résultat
    }

    if (arr.size() == 1) {
        return arr.back();
    }

    throw std::runtime_error("Calculation failed!");
}
